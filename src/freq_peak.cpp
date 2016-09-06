#include <Rcpp.h>


//' 
//' @rdname freq_peak
//' 
//' @title freq_peak
//' @description Find peaks in frequency data.
//' 
//' @param myMat a matrix of frequencies [0-1].
//' @param pos a numeric vector describing the position of variants in myMat.
//' @param winsize sliding window size.
//' 
//' @details
//' More to come.
//' 
//' @return 
//' A list
//' 
//' @examples
//' freqs <- matrix(runif(n=9), ncol=3, nrow=3)
//' pos <- 1:3
//' myPeaks <- freq_peak(freqs, pos)
//' 
//' data(vcfR_example)
//' ad <- extract.gt(vcf, element = "AD")
//' ad1 <- masplit(ad, record = 1)
//' ad2 <- masplit(ad, record = 2)
//' freqs <- ad1/(ad1+ad2)
//' myPeaks <- freq_peak(freqs, getPOS(vcf))
//' 
//' 
//' @export
// [[Rcpp::export]]
Rcpp::List freq_peak(Rcpp::NumericMatrix myMat,
                     Rcpp::NumericVector pos,
                     int winsize = 10000
                     ){
  int i = 0;
  
  // NA matrix to return in case of unexpected results.
  Rcpp::NumericMatrix naMat( 1, 1 );
  naMat(0,0) = NA_REAL;
  
  // Create a matrix of windows.
// Rcpp::Rcout << "pos.size() is: " << pos.size() << ".\n"; 
  int max_pos = pos[ pos.size() - 1 ] / winsize + 1;
// Rcpp::Rcout << "max_pos is: " << max_pos << ".\n"; 
  Rcpp::NumericMatrix wins( max_pos, 6);
  Rcpp::StringVector rownames( max_pos );
  for(i=0; i<max_pos; i++){
    wins(i,0) = i * winsize + 1;
    wins(i,1) = i * winsize + winsize;
    rownames(i) = "win" + std::to_string(i+1);
  }
//  Rcpp::Rcout << "wins initialized!\n";
  Rcpp::StringVector colnames(6);
  colnames(0) = "START";
  colnames(1) = "END";
  colnames(2) = "START_row";
  colnames(3) = "END_row";
  colnames(4) = "START_pos";
  colnames(5) = "END_pos";
  wins.attr("dimnames") = Rcpp::List::create(rownames, colnames);

  // Initialize a freq matrix.
  Rcpp::NumericMatrix freqs( max_pos, myMat.ncol() );
//  Rcpp::Rcout << "Trying dimnames.\n";
  Rcpp::StringVector myColNames = Rcpp::colnames(myMat);
//  Rcpp::Rcout << "myColNames.size(): " << myColNames.size() << "\n";

  Rcpp::rownames(freqs) = rownames;
  if( myColNames.size() > 0 ){
    Rcpp::colnames(freqs) = myColNames;
  }
  
//  Rcpp::Rcout << "Finished dimnames.\n";
  
  // Find windows in pos.
  int win_num = 0;
  i = 0;

  // First row.
//  Rcpp::Rcout << "First row.\n";
  while( pos(i) < wins(win_num,0) ){
      win_num++;
  }
  wins(win_num,2) = i + 1;
  wins(win_num,4) = pos(0);
  
  // Remaining rows.
//  Rcpp::Rcout << "Windowing.\n";
  for(i=1; i<myMat.nrow(); i++){
    
    if( pos(i) > wins(win_num,1) ){
      // Increment window.
//      Rcpp::Rcout << "  New window, pos(i): " << pos(i) << " wins(win_num,0): " << wins(win_num,0) << " wins(win_num,1): " << wins(win_num,1) << "\n";
      wins(win_num,3) = i;
      wins(win_num,5) = pos(i-1);
      
      while( pos(i) > wins(win_num,1) ){
//        win_num++;
        win_num = win_num + 1;
//        Rcpp::Rcout << "    Incrementing win_num: " << win_num << "\n";
      }
//      Rcpp::Rcout << "    win_num: " << win_num << "\n";
      wins(win_num,2) = i + 1;
      wins(win_num,4) = pos(i);
    }
  }
  
  // Last row.
  wins(win_num,3) = i;
  wins(win_num,5) = pos(i-1);

  // Windowize and process.

  
  // Create the return List.
  Rcpp::List myList = Rcpp::List::create(
    Rcpp::Named("wins") = wins,
    Rcpp::Named("peaks") = freqs
  );
  
  return(myList);
}



