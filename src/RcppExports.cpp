// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// vcf_stats_gz
Rcpp::NumericVector vcf_stats_gz(std::string x, int nrows, int skip);
RcppExport SEXP _vcfR_vcf_stats_gz(SEXP xSEXP, SEXP nrowsSEXP, SEXP skipSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type nrows(nrowsSEXP);
    Rcpp::traits::input_parameter< int >::type skip(skipSEXP);
    rcpp_result_gen = Rcpp::wrap(vcf_stats_gz(x, nrows, skip));
    return rcpp_result_gen;
END_RCPP
}
// read_meta_gz
Rcpp::StringVector read_meta_gz(std::string x, Rcpp::NumericVector stats, int verbose);
RcppExport SEXP _vcfR_read_meta_gz(SEXP xSEXP, SEXP statsSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type stats(statsSEXP);
    Rcpp::traits::input_parameter< int >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(read_meta_gz(x, stats, verbose));
    return rcpp_result_gen;
END_RCPP
}
// read_body_gz
Rcpp::CharacterMatrix read_body_gz(std::string x, Rcpp::NumericVector stats, long int nrows, long int skip, Rcpp::IntegerVector cols, int convertNA, int verbose);
RcppExport SEXP _vcfR_read_body_gz(SEXP xSEXP, SEXP statsSEXP, SEXP nrowsSEXP, SEXP skipSEXP, SEXP colsSEXP, SEXP convertNASEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type stats(statsSEXP);
    Rcpp::traits::input_parameter< long int >::type nrows(nrowsSEXP);
    Rcpp::traits::input_parameter< long int >::type skip(skipSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type cols(colsSEXP);
    Rcpp::traits::input_parameter< int >::type convertNA(convertNASEXP);
    Rcpp::traits::input_parameter< int >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(read_body_gz(x, stats, nrows, skip, cols, convertNA, verbose));
    return rcpp_result_gen;
END_RCPP
}
// timesTwo
int timesTwo(int x);
RcppExport SEXP _vcfR_timesTwo(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(timesTwo(x));
    return rcpp_result_gen;
END_RCPP
}
// write_vcf_body
void write_vcf_body(Rcpp::CharacterMatrix fix, Rcpp::CharacterMatrix gt, std::string filename, int mask);
RcppExport SEXP _vcfR_write_vcf_body(SEXP fixSEXP, SEXP gtSEXP, SEXP filenameSEXP, SEXP maskSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterMatrix >::type fix(fixSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterMatrix >::type gt(gtSEXP);
    Rcpp::traits::input_parameter< std::string >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< int >::type mask(maskSEXP);
    write_vcf_body(fix, gt, filename, mask);
    return R_NilValue;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_vcfR_vcf_stats_gz", (DL_FUNC) &_vcfR_vcf_stats_gz, 3},
    {"_vcfR_read_meta_gz", (DL_FUNC) &_vcfR_read_meta_gz, 3},
    {"_vcfR_read_body_gz", (DL_FUNC) &_vcfR_read_body_gz, 7},
    {"_vcfR_timesTwo", (DL_FUNC) &_vcfR_timesTwo, 1},
    {"_vcfR_write_vcf_body", (DL_FUNC) &_vcfR_write_vcf_body, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_vcfR(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
