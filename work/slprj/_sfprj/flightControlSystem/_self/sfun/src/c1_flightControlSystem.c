/* Include files */

#include "flightControlSystem_sfun.h"
#include "c1_flightControlSystem.h"
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c1_emlrtMCI = { 14, /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c1_b_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnegative",               /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnegative.m"/* pName */
};

static emlrtMCInfo c1_c_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c1_d_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c1_e_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c1_f_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c1_g_emlrtMCI = { 28,/* lineNo */
  19,                                  /* colNo */
  "sub2ind",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtMCInfo c1_h_emlrtMCI = { 18,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtMCInfo c1_i_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnan.m"/* pName */
};

static emlrtMCInfo c1_j_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c1_k_emlrtMCI = { 57,/* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtMCInfo c1_l_emlrtMCI = { 58,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c1_m_emlrtMCI = { 64,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c1_n_emlrtMCI = { 1499,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtMCInfo c1_o_emlrtMCI = { 21,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtMCInfo c1_p_emlrtMCI = { 288,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtMCInfo c1_q_emlrtMCI = { 46,/* lineNo */
  23,                                  /* colNo */
  "sumprod",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtMCInfo c1_r_emlrtMCI = { 81,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtMCInfo c1_s_emlrtMCI = { 296,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtMCInfo c1_t_emlrtMCI = { 392,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtMCInfo c1_u_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatepositive",                  /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatepositive.m"/* pName */
};

static emlrtMCInfo c1_v_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validatenonempty",                  /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonempty.m"/* pName */
};

static emlrtMCInfo c1_w_emlrtMCI = { 18,/* lineNo */
  23,                                  /* colNo */
  "validatencols",                     /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatencols.m"/* pName */
};

static emlrtMCInfo c1_x_emlrtMCI = { 72,/* lineNo */
  1,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtMCInfo c1_y_emlrtMCI = { 47,/* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtMCInfo c1_ab_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validateinteger",                   /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validateinteger.m"/* pName */
};

static emlrtMCInfo c1_bb_emlrtMCI = { 454,/* lineNo */
  5,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pName */
};

static emlrtMCInfo c1_cb_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validateodd",                       /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validateodd.m"/* pName */
};

static emlrtMCInfo c1_db_emlrtMCI = { 474,/* lineNo */
  1,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pName */
};

static emlrtMCInfo c1_eb_emlrtMCI = { 642,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtMCInfo c1_fb_emlrtMCI = { 56,/* lineNo */
  27,                                  /* colNo */
  "parseSortrowsOptions",              /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\parseSortrowsOptions.m"/* pName */
};

static emlrtRSInfo c1_emlrtRSI = { 4,  /* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2725"          /* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 5,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2725"          /* pathName */
};

static emlrtRSInfo c1_c_emlrtRSI = { 6,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2725"          /* pathName */
};

static emlrtRSInfo c1_d_emlrtRSI = { 7,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2725"          /* pathName */
};

static emlrtRSInfo c1_e_emlrtRSI = { 8,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2725"          /* pathName */
};

static emlrtRSInfo c1_f_emlrtRSI = { 9,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2725"          /* pathName */
};

static emlrtRSInfo c1_g_emlrtRSI = { 10,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2725"          /* pathName */
};

static emlrtRSInfo c1_h_emlrtRSI = { 70,/* lineNo */
  "imbinarize",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imbinarize.m"/* pathName */
};

static emlrtRSInfo c1_i_emlrtRSI = { 102,/* lineNo */
  "imbinarize",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imbinarize.m"/* pathName */
};

static emlrtRSInfo c1_j_emlrtRSI = { 41,/* lineNo */
  "im2uint8",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\im2uint8.m"/* pathName */
};

static emlrtRSInfo c1_k_emlrtRSI = { 197,/* lineNo */
  "im2uint8",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\im2uint8.m"/* pathName */
};

static emlrtRSInfo c1_l_emlrtRSI = { 19,/* lineNo */
  "grayto8",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\grayto8.m"/* pathName */
};

static emlrtRSInfo c1_m_emlrtRSI = { 133,/* lineNo */
  "imhist",                            /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c1_n_emlrtRSI = { 207,/* lineNo */
  "imhist",                            /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c1_o_emlrtRSI = { 170,/* lineNo */
  "imhist",                            /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c1_p_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "D:\\Matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c1_q_emlrtRSI = { 37,/* lineNo */
  "otsuthresh",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\otsuthresh.m"/* pathName */
};

static emlrtRSInfo c1_r_emlrtRSI = { 85,/* lineNo */
  "otsuthresh",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\otsuthresh.m"/* pathName */
};

static emlrtRSInfo c1_s_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c1_t_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c1_u_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c1_v_emlrtRSI = { 119,/* lineNo */
  "edge",                              /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_w_emlrtRSI = { 135,/* lineNo */
  "edge",                              /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_x_emlrtRSI = { 141,/* lineNo */
  "edge",                              /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_y_emlrtRSI = { 745,/* lineNo */
  "edge",                              /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_ab_emlrtRSI = { 746,/* lineNo */
  "edge",                              /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_bb_emlrtRSI = { 751,/* lineNo */
  "edge",                              /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_cb_emlrtRSI = { 752,/* lineNo */
  "edge",                              /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_db_emlrtRSI = { 109,/* lineNo */
  "imfilter",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_eb_emlrtRSI = { 121,/* lineNo */
  "imfilter",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_fb_emlrtRSI = { 877,/* lineNo */
  "imfilter",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_gb_emlrtRSI = { 950,/* lineNo */
  "imfilter",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_hb_emlrtRSI = { 1021,/* lineNo */
  "imfilter",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_ib_emlrtRSI = { 1049,/* lineNo */
  "imfilter",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_jb_emlrtRSI = { 1061,/* lineNo */
  "imfilter",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_kb_emlrtRSI = { 761,/* lineNo */
  "edge",                              /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_lb_emlrtRSI = { 456,/* lineNo */
  "imhist",                            /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c1_mb_emlrtRSI = { 801,/* lineNo */
  "edge",                              /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_nb_emlrtRSI = { 807,/* lineNo */
  "edge",                              /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_ob_emlrtRSI = { 911,/* lineNo */
  "edge",                              /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_pb_emlrtRSI = { 80,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c1_qb_emlrtRSI = { 77,/* lineNo */
  "bwmorph",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwmorph.m"/* pathName */
};

static emlrtRSInfo c1_rb_emlrtRSI = { 33,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_sb_emlrtRSI = { 322,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_tb_emlrtRSI = { 325,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_ub_emlrtRSI = { 145,/* lineNo */
  "bwlookup",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwlookup.m"/* pathName */
};

static emlrtRSInfo c1_vb_emlrtRSI = { 205,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_wb_emlrtRSI = { 163,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_xb_emlrtRSI = { 164,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_yb_emlrtRSI = { 33,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_ac_emlrtRSI = { 43,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_bc_emlrtRSI = { 51,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_cc_emlrtRSI = { 69,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_dc_emlrtRSI = { 24,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_ec_emlrtRSI = { 28,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_fc_emlrtRSI = { 31,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_gc_emlrtRSI = { 32,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_hc_emlrtRSI = { 78,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_ic_emlrtRSI = { 139,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_jc_emlrtRSI = { 179,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_kc_emlrtRSI = { 184,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_lc_emlrtRSI = { 43,/* lineNo */
  "graythresh",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\graythresh.m"/* pathName */
};

static emlrtRSInfo c1_mc_emlrtRSI = { 45,/* lineNo */
  "graythresh",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\graythresh.m"/* pathName */
};

static emlrtRSInfo c1_nc_emlrtRSI = { 48,/* lineNo */
  "graythresh",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\graythresh.m"/* pathName */
};

static emlrtRSInfo c1_oc_emlrtRSI = { 35,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_pc_emlrtRSI = { 138,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_qc_emlrtRSI = { 255,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_rc_emlrtRSI = { 254,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_sc_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_tc_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c1_uc_emlrtRSI = { 16,/* lineNo */
  "sub2ind",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c1_vc_emlrtRSI = { 28,/* lineNo */
  "colon",                             /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c1_wc_emlrtRSI = { 125,/* lineNo */
  "colon",                             /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c1_xc_emlrtRSI = { 328,/* lineNo */
  "colon",                             /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c1_yc_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c1_ad_emlrtRSI = { 150,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_bd_emlrtRSI = { 29,/* lineNo */
  "chcenters",                         /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c1_cd_emlrtRSI = { 34,/* lineNo */
  "chcenters",                         /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c1_dd_emlrtRSI = { 35,/* lineNo */
  "chcenters",                         /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c1_ed_emlrtRSI = { 36,/* lineNo */
  "chcenters",                         /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c1_fd_emlrtRSI = { 48,/* lineNo */
  "chcenters",                         /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c1_gd_emlrtRSI = { 53,/* lineNo */
  "chcenters",                         /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c1_hd_emlrtRSI = { 55,/* lineNo */
  "chcenters",                         /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c1_id_emlrtRSI = { 62,/* lineNo */
  "medfilt2",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\medfilt2.m"/* pathName */
};

static emlrtRSInfo c1_jd_emlrtRSI = { 155,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRSInfo c1_kd_emlrtRSI = { 179,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRSInfo c1_ld_emlrtRSI = { 66,/* lineNo */
  "imhmax",                            /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\imhmax.m"/* pathName */
};

static emlrtRSInfo c1_md_emlrtRSI = { 10,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c1_nd_emlrtRSI = { 14,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c1_od_emlrtRSI = { 14,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imregionalmax.m"/* pathName */
};

static emlrtRSInfo c1_pd_emlrtRSI = { 35,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imregionalmax.m"/* pathName */
};

static emlrtRSInfo c1_qd_emlrtRSI = { 37,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imregionalmax.m"/* pathName */
};

static emlrtRSInfo c1_rd_emlrtRSI = { 41,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_sd_emlrtRSI = { 107,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_td_emlrtRSI = { 109,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_ud_emlrtRSI = { 314,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_vd_emlrtRSI = { 316,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_wd_emlrtRSI = { 378,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_xd_emlrtRSI = { 26,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_yd_emlrtRSI = { 101,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_ae_emlrtRSI = { 100,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_be_emlrtRSI = { 93,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_ce_emlrtRSI = { 85,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_de_emlrtRSI = { 84,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_ee_emlrtRSI = { 83,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_fe_emlrtRSI = { 71,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_ge_emlrtRSI = { 58,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_he_emlrtRSI = { 39,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_ie_emlrtRSI = { 51,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_je_emlrtRSI = { 114,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_ke_emlrtRSI = { 149,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_le_emlrtRSI = { 150,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_me_emlrtRSI = { 153,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_ne_emlrtRSI = { 20,/* lineNo */
  "sum",                               /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo c1_oe_emlrtRSI = { 99,/* lineNo */
  "sumprod",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo c1_pe_emlrtRSI = { 86,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c1_qe_emlrtRSI = { 107,/* lineNo */
  "blockedSummation",                  /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blockedSummation.m"/* pathName */
};

static emlrtRSInfo c1_re_emlrtRSI = { 22,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c1_se_emlrtRSI = { 42,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c1_te_emlrtRSI = { 57,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c1_ue_emlrtRSI = { 178,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c1_ve_emlrtRSI = { 189,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c1_we_emlrtRSI = { 210,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c1_xe_emlrtRSI = { 14,/* lineNo */
  "cumsum",                            /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\cumsum.m"/* pathName */
};

static emlrtRSInfo c1_ye_emlrtRSI = { 16,/* lineNo */
  "cumop",                             /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c1_af_emlrtRSI = { 32,/* lineNo */
  "useConstantDim",                    /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\useConstantDim.m"/* pathName */
};

static emlrtRSInfo c1_bf_emlrtRSI = { 100,/* lineNo */
  "cumop",                             /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c1_cf_emlrtRSI = { 125,/* lineNo */
  "cumop",                             /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c1_df_emlrtRSI = { 290,/* lineNo */
  "cumop",                             /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c1_ef_emlrtRSI = { 38,/* lineNo */
  "repmat",                            /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c1_ff_emlrtRSI = { 149,/* lineNo */
  "repmat",                            /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c1_gf_emlrtRSI = { 1511,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_hf_emlrtRSI = { 1696,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_if_emlrtRSI = { 2068,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_jf_emlrtRSI = { 485,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_kf_emlrtRSI = { 1381,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_lf_emlrtRSI = { 1372,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_mf_emlrtRSI = { 1367,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_nf_emlrtRSI = { 1364,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_of_emlrtRSI = { 1001,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_pf_emlrtRSI = { 999,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_qf_emlrtRSI = { 19,/* lineNo */
  "ind2sub",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pathName */
};

static emlrtRSInfo c1_rf_emlrtRSI = { 39,/* lineNo */
  "cat",                               /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c1_sf_emlrtRSI = { 113,/* lineNo */
  "cat",                               /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c1_tf_emlrtRSI = { 1350,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_uf_emlrtRSI = { 22,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_vf_emlrtRSI = { 26,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_wf_emlrtRSI = { 273,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_xf_emlrtRSI = { 274,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_yf_emlrtRSI = { 16,/* lineNo */
  "round",                             /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\round.m"/* pathName */
};

static emlrtRSInfo c1_ag_emlrtRSI = { 33,/* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo c1_bg_emlrtRSI = { 37,/* lineNo */
  "sort",                              /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

static emlrtRSInfo c1_cg_emlrtRSI = { 72,/* lineNo */
  "sort",                              /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c1_dg_emlrtRSI = { 104,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_eg_emlrtRSI = { 105,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_fg_emlrtRSI = { 301,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_gg_emlrtRSI = { 309,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_hg_emlrtRSI = { 310,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_ig_emlrtRSI = { 318,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_jg_emlrtRSI = { 326,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_kg_emlrtRSI = { 333,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_lg_emlrtRSI = { 381,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_mg_emlrtRSI = { 409,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_ng_emlrtRSI = { 416,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_og_emlrtRSI = { 576,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_pg_emlrtRSI = { 578,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_qg_emlrtRSI = { 606,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_rg_emlrtRSI = { 488,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_sg_emlrtRSI = { 495,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_tg_emlrtRSI = { 496,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_ug_emlrtRSI = { 503,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_vg_emlrtRSI = { 550,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_wg_emlrtRSI = { 519,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_xg_emlrtRSI = { 347,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_yg_emlrtRSI = { 356,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_ah_emlrtRSI = { 39,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_bh_emlrtRSI = { 144,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_ch_emlrtRSI = { 382,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_dh_emlrtRSI = { 402,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_eh_emlrtRSI = { 6,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_fh_emlrtRSI = { 14,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_gh_emlrtRSI = { 16,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_hh_emlrtRSI = { 32,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_ih_emlrtRSI = { 35,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_jh_emlrtRSI = { 44,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_kh_emlrtRSI = { 72,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_lh_emlrtRSI = { 73,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_mh_emlrtRSI = { 13,/* lineNo */
  "all",                               /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\all.m"/* pathName */
};

static emlrtRSInfo c1_nh_emlrtRSI = { 143,/* lineNo */
  "allOrAny",                          /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pathName */
};

static emlrtRSInfo c1_oh_emlrtRSI = { 9,/* lineNo */
  "angle",                             /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\angle.m"/* pathName */
};

static emlrtRSInfo c1_ph_emlrtRSI = { 74,/* lineNo */
  "applyScalarFunction",               /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo c1_qh_emlrtRSI = { 10,/* lineNo */
  "exp",                               /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m"/* pathName */
};

static emlrtRSInfo c1_rh_emlrtRSI = { 60,/* lineNo */
  "hough",                             /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\hough.m"/* pathName */
};

static emlrtRSInfo c1_sh_emlrtRSI = { 290,/* lineNo */
  "hough",                             /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\hough.m"/* pathName */
};

static emlrtRSInfo c1_th_emlrtRSI = { 297,/* lineNo */
  "hough",                             /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\hough.m"/* pathName */
};

static emlrtRSInfo c1_uh_emlrtRSI = { 150,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_vh_emlrtRSI = { 149,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_wh_emlrtRSI = { 111,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_xh_emlrtRSI = { 61,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_yh_emlrtRSI = { 274,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_ai_emlrtRSI = { 317,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_bi_emlrtRSI = { 321,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_ci_emlrtRSI = { 324,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_di_emlrtRSI = { 427,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_ei_emlrtRSI = { 439,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_fi_emlrtRSI = { 474,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_gi_emlrtRSI = { 463,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_hi_emlrtRSI = { 74,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_ii_emlrtRSI = { 91,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_ji_emlrtRSI = { 127,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_ki_emlrtRSI = { 137,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_li_emlrtRSI = { 145,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_mi_emlrtRSI = { 159,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_ni_emlrtRSI = { 638,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_oi_emlrtRSI = { 531,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_pi_emlrtRSI = { 501,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_qi_emlrtRSI = { 420,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_ri_emlrtRSI = { 24,/* lineNo */
  "sortrows",                          /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pathName */
};

static emlrtRSInfo c1_si_emlrtRSI = { 27,/* lineNo */
  "sortrows",                          /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pathName */
};

static emlrtRSInfo c1_ti_emlrtRSI = { 28,/* lineNo */
  "sortrows",                          /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pathName */
};

static emlrtRSInfo c1_ui_emlrtRSI = { 86,/* lineNo */
  "sortIdx",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_vi_emlrtRSI = { 113,/* lineNo */
  "mergesort",                         /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\mergesort.m"/* pathName */
};

static emlrtRSInfo c1_wi_emlrtRSI = { 39,/* lineNo */
  "sortrows",                          /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pathName */
};

static emlrtRSInfo c1_xi_emlrtRSI = { 42,/* lineNo */
  "sortrows",                          /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pathName */
};

static emlrtRSInfo c1_yi_emlrtRSI = { 543,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_aj_emlrtRSI = { 587,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_bj_emlrtRSI = { 590,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_cj_emlrtRSI = { 608,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRTEInfo c1_emlrtRTEI = { 776,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c1_b_emlrtRTEI = { 777,/* lineNo */
  37,                                  /* colNo */
  "edge",                              /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c1_c_emlrtRTEI = { 76,/* lineNo */
  9,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c1_d_emlrtRTEI = { 777,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c1_e_emlrtRTEI = { 773,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c1_f_emlrtRTEI = { 774,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c1_g_emlrtRTEI = { 8,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_h_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_i_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_j_emlrtRTEI = { 128,/* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtRTEInfo c1_k_emlrtRTEI = { 43,/* lineNo */
  6,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_l_emlrtRTEI = { 43,/* lineNo */
  15,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_m_emlrtRTEI = { 51,/* lineNo */
  21,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_n_emlrtRTEI = { 369,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_o_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_p_emlrtRTEI = { 51,/* lineNo */
  5,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_q_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_r_emlrtRTEI = { 53,/* lineNo */
  5,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_s_emlrtRTEI = { 72,/* lineNo */
  30,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_t_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_u_emlrtRTEI = { 14,/* lineNo */
  62,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_v_emlrtRTEI = { 14,/* lineNo */
  82,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_w_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c1_x_emlrtRTEI = { 14,/* lineNo */
  18,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_y_emlrtRTEI = { 30,/* lineNo */
  21,                                  /* colNo */
  "applyScalarFunction",               /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pName */
};

static emlrtRTEInfo c1_ab_emlrtRTEI = { 69,/* lineNo */
  21,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_bb_emlrtRTEI = { 57,/* lineNo */
  9,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_cb_emlrtRTEI = { 58,/* lineNo */
  9,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_db_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_eb_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_fb_emlrtRTEI = { 32,/* lineNo */
  35,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_gb_emlrtRTEI = { 32,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_hb_emlrtRTEI = { 32,/* lineNo */
  1,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_ib_emlrtRTEI = { 320,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c1_jb_emlrtRTEI = { 78,/* lineNo */
  23,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_kb_emlrtRTEI = { 79,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_lb_emlrtRTEI = { 80,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_mb_emlrtRTEI = { 81,/* lineNo */
  33,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_nb_emlrtRTEI = { 93,/* lineNo */
  25,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_ob_emlrtRTEI = { 94,/* lineNo */
  25,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_pb_emlrtRTEI = { 96,/* lineNo */
  24,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_qb_emlrtRTEI = { 97,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_rb_emlrtRTEI = { 100,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_sb_emlrtRTEI = { 123,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_tb_emlrtRTEI = { 124,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_ub_emlrtRTEI = { 125,/* lineNo */
  28,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_vb_emlrtRTEI = { 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_wb_emlrtRTEI = { 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_xb_emlrtRTEI = { 253,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_yb_emlrtRTEI = { 254,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_ac_emlrtRTEI = { 33,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c1_bc_emlrtRTEI = { 35,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c1_cc_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_dc_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_ec_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_fc_emlrtRTEI = { 42,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_gc_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_hc_emlrtRTEI = { 26,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c1_ic_emlrtRTEI = { 53,/* lineNo */
  44,                                  /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_jc_emlrtRTEI = { 53,/* lineNo */
  64,                                  /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_kc_emlrtRTEI = { 53,/* lineNo */
  18,                                  /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_lc_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_mc_emlrtRTEI = { 55,/* lineNo */
  33,                                  /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_nc_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo c1_oc_emlrtRTEI = { 55,/* lineNo */
  10,                                  /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_pc_emlrtRTEI = { 56,/* lineNo */
  19,                                  /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_qc_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_rc_emlrtRTEI = { 41,/* lineNo */
  1,                                   /* colNo */
  "repmat",                            /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c1_sc_emlrtRTEI = { 1511,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_tc_emlrtRTEI = { 1968,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_uc_emlrtRTEI = { 1972,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_vc_emlrtRTEI = { 1991,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_wc_emlrtRTEI = { 1995,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_xc_emlrtRTEI = { 2012,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_yc_emlrtRTEI = { 2063,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ad_emlrtRTEI = { 2068,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_bd_emlrtRTEI = { 477,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_cd_emlrtRTEI = { 478,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_dd_emlrtRTEI = { 17,/* lineNo */
  25,                                  /* colNo */
  "cumop",                             /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pName */
};

static emlrtRTEInfo c1_ed_emlrtRTEI = { 485,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_fd_emlrtRTEI = { 488,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_gd_emlrtRTEI = { 48,/* lineNo */
  27,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_hd_emlrtRTEI = { 49,/* lineNo */
  25,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_id_emlrtRTEI = { 50,/* lineNo */
  28,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_jd_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_kd_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_ld_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_md_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_nd_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_od_emlrtRTEI = { 53,/* lineNo */
  35,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_pd_emlrtRTEI = { 69,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_qd_emlrtRTEI = { 83,/* lineNo */
  32,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_rd_emlrtRTEI = { 84,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_sd_emlrtRTEI = { 84,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_td_emlrtRTEI = { 100,/* lineNo */
  23,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_ud_emlrtRTEI = { 101,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_vd_emlrtRTEI = { 101,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_wd_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_xd_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_yd_emlrtRTEI = { 47,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_ae_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_be_emlrtRTEI = { 26,/* lineNo */
  20,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_ce_emlrtRTEI = { 26,/* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_de_emlrtRTEI = { 26,/* lineNo */
  54,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_ee_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "useConstantDim",                    /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\useConstantDim.m"/* pName */
};

static emlrtRTEInfo c1_fe_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c1_ge_emlrtRTEI = { 102,/* lineNo */
  25,                                  /* colNo */
  "repmat",                            /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c1_he_emlrtRTEI = { 157,/* lineNo */
  25,                                  /* colNo */
  "repmat",                            /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c1_ie_emlrtRTEI = { 1359,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_je_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "round",                             /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\round.m"/* pName */
};

static emlrtRTEInfo c1_ke_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c1_le_emlrtRTEI = { 561,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_me_emlrtRTEI = { 471,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_ne_emlrtRTEI = { 509,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_oe_emlrtRTEI = { 191,/* lineNo */
  5,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pName */
};

static emlrtRTEInfo c1_pe_emlrtRTEI = { 187,/* lineNo */
  5,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pName */
};

static emlrtRTEInfo c1_qe_emlrtRTEI = { 74,/* lineNo */
  15,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_re_emlrtRTEI = { 102,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_se_emlrtRTEI = { 105,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_te_emlrtRTEI = { 108,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_ue_emlrtRTEI = { 111,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_ve_emlrtRTEI = { 531,/* lineNo */
  12,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_we_emlrtRTEI = { 531,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_xe_emlrtRTEI = { 492,/* lineNo */
  5,                                   /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_ye_emlrtRTEI = { 547,/* lineNo */
  29,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_af_emlrtRTEI = { 560,/* lineNo */
  31,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_bf_emlrtRTEI = { 142,/* lineNo */
  9,                                   /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_cf_emlrtRTEI = { 143,/* lineNo */
  9,                                   /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_df_emlrtRTEI = { 150,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_ef_emlrtRTEI = { 150,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_ff_emlrtRTEI = { 151,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_gf_emlrtRTEI = { 151,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_hf_emlrtRTEI = { 152,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_if_emlrtRTEI = { 153,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_jf_emlrtRTEI = { 11,/* lineNo */
  40,                                  /* colNo */
  "validatepositive",                  /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatepositive.m"/* pName */
};

static emlrtRTEInfo c1_kf_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sortrows",                          /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pName */
};

static emlrtRTEInfo c1_lf_emlrtRTEI = { 63,/* lineNo */
  9,                                   /* colNo */
  "repmat",                            /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c1_mf_emlrtRTEI = { 998,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_nf_emlrtRTEI = { 1003,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_of_emlrtRTEI = { 999,/* lineNo */
  41,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_pf_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_qf_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_rf_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_sf_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_tf_emlrtRTEI = { 121,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c1_uf_emlrtRTEI = { 128,/* lineNo */
  30,                                  /* colNo */
  "cat",                               /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c1_vf_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c1_wf_emlrtRTEI = { 1001,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_xf_emlrtRTEI = { 1349,/* lineNo */
  57,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_yf_emlrtRTEI = { 1349,/* lineNo */
  47,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ag_emlrtRTEI = { 1350,/* lineNo */
  33,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_bg_emlrtRTEI = { 1351,/* lineNo */
  27,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_cg_emlrtRTEI = { 1371,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_dg_emlrtRTEI = { 1381,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_eg_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_fg_emlrtRTEI = { 296,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_gg_emlrtRTEI = { 298,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_hg_emlrtRTEI = { 27,/* lineNo */
  30,                                  /* colNo */
  "sortrows",                          /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pName */
};

static emlrtRTEInfo c1_ig_emlrtRTEI = { 27,/* lineNo */
  1,                                   /* colNo */
  "sortrows",                          /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pName */
};

static emlrtRTEInfo c1_jg_emlrtRTEI = { 148,/* lineNo */
  24,                                  /* colNo */
  "mergesort",                         /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\mergesort.m"/* pName */
};

static emlrtRTEInfo c1_kg_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "mergesort",                         /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\mergesort.m"/* pName */
};

static emlrtRTEInfo c1_lg_emlrtRTEI = { 37,/* lineNo */
  23,                                  /* colNo */
  "sortrows",                          /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pName */
};

static emlrtRTEInfo c1_mg_emlrtRTEI = { 7,/* lineNo */
  2,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725"          /* pName */
};

static emlrtRTEInfo c1_ng_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725"          /* pName */
};

static emlrtRTEInfo c1_og_emlrtRTEI = { 1,/* lineNo */
  43,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_pg_emlrtRTEI = { 31,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_qg_emlrtRTEI = { 14,/* lineNo */
  76,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_rg_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_sg_emlrtRTEI = { 80,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_tg_emlrtRTEI = { 81,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_ug_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_vg_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_wg_emlrtRTEI = { 96,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_xg_emlrtRTEI = { 97,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_yg_emlrtRTEI = { 123,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_ah_emlrtRTEI = { 124,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_bh_emlrtRTEI = { 125,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_ch_emlrtRTEI = { 78,/* lineNo */
  17,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_dh_emlrtRTEI = { 1,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_eh_emlrtRTEI = { 32,/* lineNo */
  8,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c1_fh_emlrtRTEI = { 16,/* lineNo */
  14,                                  /* colNo */
  "sub2ind",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c1_gh_emlrtRTEI = { 36,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_hh_emlrtRTEI = { 1,/* lineNo */
  30,                                  /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_ih_emlrtRTEI = { 53,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_jh_emlrtRTEI = { 53,/* lineNo */
  58,                                  /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_kh_emlrtRTEI = { 35,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_lh_emlrtRTEI = { 109,/* lineNo */
  2,                                   /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_mh_emlrtRTEI = { 1947,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_nh_emlrtRTEI = { 402,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_oh_emlrtRTEI = { 415,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ph_emlrtRTEI = { 416,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_qh_emlrtRTEI = { 1,/* lineNo */
  15,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_rh_emlrtRTEI = { 53,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_sh_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_th_emlrtRTEI = { 51,/* lineNo */
  57,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_uh_emlrtRTEI = { 51,/* lineNo */
  64,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_vh_emlrtRTEI = { 114,/* lineNo */
  55,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_wh_emlrtRTEI = { 137,/* lineNo */
  5,                                   /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_xh_emlrtRTEI = { 127,/* lineNo */
  22,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_yh_emlrtRTEI = { 547,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c1_ai_emlrtRTEI = { 999,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_bi_emlrtRTEI = { 998,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ci_emlrtRTEI = { 1001,/* lineNo */
  34,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_di_emlrtRTEI = { 116,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c1_ei_emlrtRTEI = { 298,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_fi_emlrtRTEI = { 37,/* lineNo */
  1,                                   /* colNo */
  "sortrows",                          /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pName */
};

static emlrtBCInfo c1_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  26,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_emlrtDCI = { 20, /* lineNo */
  26,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  57,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_b_emlrtDCI = { 20,/* lineNo */
  57,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  34,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_c_emlrtDCI = { 23,/* lineNo */
  34,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  34,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_d_emlrtDCI = { 21,/* lineNo */
  34,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  19,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_e_emlrtDCI = { 19,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  52,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_f_emlrtDCI = { 19,/* lineNo */
  52,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  27,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_g_emlrtDCI = { 25,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2725",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_h_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1055,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_i_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1056,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_j_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1057,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_k_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1058,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  144,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  145,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  801,                                 /* lineNo */
  70,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  806,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_p_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  156,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_q_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  156,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  72,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  92,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_x_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  14,                                  /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c1_gi_emlrtRTEI = { 77,/* lineNo */
  9,                                   /* colNo */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtBCInfo c1_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  110,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_kb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_lb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_mb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  132,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_nb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  132,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ob_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  110,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  133,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  133,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_rb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_sb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_tb_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  151,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ub_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_vb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  151,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_wb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_yb_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  151,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_ac_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  151,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_cc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_dc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ec_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  107,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ic_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  84,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_jc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  107,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_kc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_lc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_mc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_nc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c1_emlrtECI = { -1, /* nDims */
  42,                                  /* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c1_hi_emlrtRTEI = { 46,/* lineNo */
  15,                                  /* colNo */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtBCInfo c1_oc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_rc_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  53,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_sc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_tc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_uc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_vc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  2124,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_wc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  2126,                                /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  2127,                                /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_yc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  2127,                                /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ad_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  68,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_cd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_dd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ed_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c1_ii_emlrtRTEI = { 102,/* lineNo */
  9,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtBCInfo c1_fd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  233,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  234,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_id_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_h_emlrtDCI = { 69,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_jd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_kd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ld_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_md_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_nd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_od_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_rd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_sd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_td_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ud_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_vd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  66,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_wd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_yd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ae_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_be_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ce_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_de_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ee_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  62,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ge_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  76,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_he_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ie_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_je_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ke_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_le_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_me_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  183,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_i_emlrtDCI = { 83,/* lineNo */
  38,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c1_j_emlrtDCI = { 83,/* lineNo */
  38,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c1_ne_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_oe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  171,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_re_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_se_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_te_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ue_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ve_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_we_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ye_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_af_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_k_emlrtDCI = { 48,/* lineNo */
  33,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c1_cf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_df_emlrtBCI = { 1,/* iFirst */
  399,                                 /* iLast */
  301,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "hough",                             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\hough.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_ef_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  348,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "hough",                             /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\hough.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_ff_emlrtBCI = { 1,/* iFirst */
  5,                                   /* iLast */
  122,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "houghpeaks",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_gf_emlrtBCI = { 1,/* iFirst */
  399,                                 /* iLast */
  119,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "houghpeaks",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  142,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_if_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  143,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_jf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  150,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_kf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  150,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_lf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_mf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_nf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  248,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_of_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  591,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  592,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qf_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  531,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_rf_emlrtBCI = { 1,/* iFirst */
  180,                                 /* iLast */
  398,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_sf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_tf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_uf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_vf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_wf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  578,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  578,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_yf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  578,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ag_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  578,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  122,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_cg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  123,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_dg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  591,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_eg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  592,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  593,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  593,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  594,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ig_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  594,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_jg_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  503,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_kg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  429,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_lg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  562,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_mg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ng_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_og_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  565,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  567,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  142,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_rg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  143,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_sg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_tg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ug_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_vg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  554,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_wg_emlrtBCI = { 1,/* iFirst */
  180,                                 /* iLast */
  152,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xg_emlrtBCI = { 1,/* iFirst */
  399,                                 /* iLast */
  153,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_l_emlrtDCI = { 547,/* lineNo */
  35,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c1_m_emlrtDCI = { 560,/* lineNo */
  37,                                  /* colNo */
  "houghlines",                        /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c1_n_emlrtDCI = { 41,/* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c1_o_emlrtDCI = { 41,/* lineNo */
  1,                                   /* colNo */
  "repmat",                            /* fName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m",/* pName */
  4                                    /* checkKind */
};

static emlrtECInfo c1_b_emlrtECI = { 1,/* nDims */
  1381,                                /* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtBCInfo c1_yg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1373,                                /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ah_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1352,                                /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1349,                                /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ch_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1003,                                /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_dh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1381,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_eh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1001,                                /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1385,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gh_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  1352,                                /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1352,                                /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ih_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1352,                                /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_jh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1352,                                /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_kh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  998,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_lh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1349,                                /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_mh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  999,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_nh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1371,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_oh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1371,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ph_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1350,                                /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1351,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_rh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1001,                                /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo c1_dj_emlrtRSI = { 56,/* lineNo */
  "chcenters",                         /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c1_ej_emlrtRSI = { 40,/* lineNo */
  "chcenters",                         /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c1_fj_emlrtRSI = { 11,/* lineNo */
  "chcenters",                         /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c1_gj_emlrtRSI = { 10,/* lineNo */
  "chcenters",                         /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c1_hj_emlrtRSI = { 58,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_ij_emlrtRSI = { 57,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_jj_emlrtRSI = { 53,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_kj_emlrtRSI = { 52,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_lj_emlrtRSI = { 10,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_mj_emlrtRSI = { 9,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_nj_emlrtRSI = { 8,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_oj_emlrtRSI = { 125,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_pj_emlrtRSI = { 41,/* lineNo */
  "repmat",                            /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c1_qj_emlrtRSI = { 97,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_rj_emlrtRSI = { 35,/* lineNo */
  "sub2ind",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c1_sj_emlrtRSI = { 33,/* lineNo */
  "sub2ind",                           /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c1_tj_emlrtRSI = { 124,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_uj_emlrtRSI = { 123,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_vj_emlrtRSI = { 1371,/* lineNo */
  "regionprops",                       /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_wj_emlrtRSI = { 81,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_xj_emlrtRSI = { 80,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_yj_emlrtRSI = { 79,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_ak_emlrtRSI = { 94,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_bk_emlrtRSI = { 93,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_ck_emlrtRSI = { 96,/* lineNo */
  "chaccum",                           /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c1_dk_emlrtRSI = { 102,/* lineNo */
  "repmat",                            /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c1_ek_emlrtRSI = { 151,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_fk_emlrtRSI = { 150,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_gk_emlrtRSI = { 105,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_hk_emlrtRSI = { 102,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_ik_emlrtRSI = { 153,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_jk_emlrtRSI = { 152,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_kk_emlrtRSI = { 111,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_lk_emlrtRSI = { 108,/* lineNo */
  "houghlines",                        /* fcnName */
  "D:\\Matlab\\toolbox\\images\\images\\eml\\houghlines.m"/* pathName */
};

static emlrtRSInfo c1_mk_emlrtRSI = { 63,/* lineNo */
  "repmat",                            /* fcnName */
  "D:\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static char_T c1_cv[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F', 'i',
  'n', 'i', 't', 'e' };

static int32_T c1_iv[320] = { 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
  11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
  31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
  51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
  71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
  91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,
  108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 120, 120, 120,
  120, 120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
  18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
  38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
  58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
  78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97,
  98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
  114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129,
  130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145,
  146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160 };

static real_T c1_dv[13] = { 0.0020299751839417137, 0.0102182810143517,
  0.058116735860084034, 0.19634433732941292, 0.37823877042972087,
  0.35505190018248872, 0.0, -0.35505190018248872, -0.37823877042972087,
  -0.19634433732941292, -0.058116735860084034, -0.0102182810143517,
  -0.0020299751839417137 };

static real_T c1_dv1[12] = { 0.0020299751839417137, 0.0102182810143517,
  0.058116735860084034, 0.19634433732941292, 0.37823877042972087,
  0.35505190018248872, -0.35505190018248872, -0.37823877042972087,
  -0.19634433732941292, -0.058116735860084034, -0.0102182810143517,
  -0.0020299751839417137 };

static boolean_T c1_bv[13] = { true, true, true, true, true, true, false, true,
  true, true, true, true, true };

static int32_T c1_iv1[324] = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
  35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
  55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
  75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94,
  95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
  112, 113, 114, 115, 116, 117, 118, 119, 120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
  19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
  39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
  59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78,
  79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98,
  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114,
  115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130,
  131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
  147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 160 };

static creal_T c1_dc = { 0.0,          /* re */
  0.0                                  /* im */
};

static char_T c1_cv1[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'P', 'o',
  's', 'i', 't', 'i', 'v', 'e' };

static char_T c1_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
  't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F', 'a',
  'i', 'l', 'e', 'd' };

static char_T c1_cv3[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N', 'o',
  'n', 'N', 'a', 'N' };

static char_T c1_cv4[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a',
  'x', 's', 'i', 'z', 'e' };

static char_T c1_cv5[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
  'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

static char_T c1_cv6[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
  'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n', 'p',
  'u', 't' };

static char_T c1_cv7[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
  'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
  'F', 'i', 'n', 'i', 't', 'e' };

static char_T c1_cv8[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
  'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
  'I', 'n', 't', 'e', 'g', 'e', 'r' };

static char_T c1_cv9[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I', 'n',
  't', 'e', 'g', 'e', 'r' };

/* Function Declarations */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st);
static void c1_imbinarize(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_I[19200], boolean_T c1_BW[19200]);
static real_T c1_otsuthresh(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_counts[256]);
static void c1_edge(SFc1_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200],
                    boolean_T c1_varargout_1[19200]);
static void c1_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_c_varargin_1[19200], real32_T c1_b[19200]);
static void c1_warning(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp);
static void c1_bwmorph(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_bwin[19200], boolean_T c1_bw[19200]);
static void c1_b_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_c_varargin_1[19200], real32_T c1_b[19200]);
static void c1_c_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_c_varargin_1[19200], real32_T c1_b[19200]);
static void c1_d_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_c_varargin_1[19200], real32_T c1_b[19200]);
static void c1_imfindcircles(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200],
  c1_coder_array_real_T_2D *c1_centers, c1_coder_array_real_T_2D *c1_r_estimated,
  c1_coder_array_real_T_2D *c1_metric);
static void c1_chaccum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200], creal_T
  c1_c_accumMatrix[19200], real32_T c1_b_gradientImg[19200]);
static real_T c1_graythresh(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real32_T c1_I[19200]);
static void c1_eml_find(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_b_x[19200], c1_coder_array_int32_T *c1_i,
  c1_coder_array_int32_T *c1_j);
static void c1_indexShapeCheck(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, int32_T c1_matrixSize, int32_T
  c1_indexSize[2]);
static void c1_sub2ind(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_coder_array_real_T *c1_c_varargin_1,
  c1_coder_array_real_T *c1_b_varargin_2, c1_coder_array_int32_T *c1_idx);
static boolean_T c1_allinrange(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_real_T *c1_b_x, int32_T c1_hi);
static void c1_check_forloop_overflow_error
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp);
static void c1_chcenters(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, creal_T c1_c_varargin_1[19200],
  c1_coder_array_real_T_2D *c1_centers, c1_coder_array_real_T_2D *c1_metric);
static void c1_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_c_a[19200]);
static void c1_regionprops(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200], real_T
  c1_b_varargin_2[19200], c1_coder_array_sOA5t73y81YtFHGIDxk *c1_outstats);
static void c1_bwconncomp(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200],
  c1_s_7KvKuzB0WpLeFthPVHAilE *c1_CC);
static real_T c1_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T *c1_b_x,
  int32_T c1_vlen);
static real_T c1_sumColumnB4(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_int32_T *c1_b_x, int32_T c1_vstart);
static real_T c1_b_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T *c1_b_x,
  int32_T c1_vlen, int32_T c1_vstart);
static void c1_useConstantDim(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T
  *c1_b_varargin_2, int32_T c1_varargin_3, c1_coder_array_int32_T
  *c1_varargout_1);
static void c1_repmat(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, c1_cell_wrap_46 c1_c_a[1], real_T
                      c1_b_varargin_2, c1_coder_array_cell_wrap_46_2D *c1_b);
static void c1_assertValidSizeArg(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_c_varargin_1);
static void c1_ComputeWeightedCentroid(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_I[19200],
  c1_coder_array_s_R6Og1x0kmqQXSF9Pw *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  c1_statsAlreadyComputed, c1_coder_array_s_R6Og1x0kmqQXSF9Pw *c1_b_stats,
  c1_sHtk0WM4OMtyqkehwQYcq2 *c1_b_statsAlreadyComputed);
static real_T c1_sum(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, c1_coder_array_real_T *c1_b_x);
static real_T c1_c_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T *c1_b_x,
  int32_T c1_vlen);
static real_T c1_b_sumColumnB4(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_real_T *c1_b_x, int32_T c1_vstart);
static real_T c1_d_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T *c1_b_x,
  int32_T c1_vlen, int32_T c1_vstart);
static void c1_round(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, c1_coder_array_real_T *c1_b_x,
                     c1_coder_array_real_T *c1_b_y);
static void c1_sort(SFc1_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c1_sp, c1_coder_array_real_T_2D *c1_b_x,
                    c1_coder_array_real_T_2D *c1_c_x, c1_coder_array_int32_T_2D *
                    c1_idx);
static void c1_merge_pow2_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_idx,
  c1_coder_array_real_T_2D *c1_b_x, int32_T c1_offset, c1_coder_array_int32_T_2D
  *c1_b_idx, c1_coder_array_real_T_2D *c1_c_x);
static void c1_merge_block(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_idx,
  c1_coder_array_real_T_2D *c1_b_x, int32_T c1_offset, int32_T c1_n, int32_T
  c1_preSortLevel, c1_coder_array_int32_T *c1_iwork, c1_coder_array_real_T
  *c1_xwork, c1_coder_array_int32_T_2D *c1_b_idx, c1_coder_array_real_T_2D
  *c1_c_x, c1_coder_array_int32_T *c1_b_iwork, c1_coder_array_real_T *c1_b_xwork);
static void c1_merge(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_idx,
                     c1_coder_array_real_T_2D *c1_b_x, int32_T c1_offset,
                     int32_T c1_np, int32_T c1_nq, c1_coder_array_int32_T
                     *c1_iwork, c1_coder_array_real_T *c1_xwork,
                     c1_coder_array_int32_T_2D *c1_b_idx,
                     c1_coder_array_real_T_2D *c1_c_x, c1_coder_array_int32_T
                     *c1_b_iwork, c1_coder_array_real_T *c1_b_xwork);
static boolean_T c1_all(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_coder_array_boolean_T *c1_b_x);
static void c1_hough(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200],
                     real_T c1_h[71820]);
static void c1_houghpeaks(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_c_varargin_1[71820], real_T c1_varargin_4,
  real_T c1_peaks_data[], int32_T c1_peaks_size[2]);
static void c1_b_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_c_a[71820]);
static void c1_c_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_c_a[2]);
static void c1_diff(SFc1_flightControlSystemInstanceStruct *chartInstance,
                    real_T c1_b_x[180], real_T c1_b_y[179]);
static void c1_b_diff(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      real_T c1_b_x[179], real_T c1_b_y[178]);
static real_T c1_e_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_b_x[178]);
static void c1_houghlines(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200], real_T
  c1_varargin_4_data[], int32_T c1_varargin_4_size[2],
  c1_coder_array_s52BVvgcaqgLKaYLjO1 *c1_lines);
static void c1_d_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_a_data[], int32_T
  c1_a_size[2]);
static void c1_sortrows(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_b_y, real_T
  c1_c_varargin_1[2], c1_coder_array_int32_T_2D *c1_c_y);
static boolean_T c1_sortLE(SFc1_flightControlSystemInstanceStruct *chartInstance,
  c1_coder_array_int32_T_2D *c1_v, int32_T c1_dir[2], int32_T c1_idx1, int32_T
  c1_idx2);
static void c1_b_repmat(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, int32_T c1_b_varargin_2,
  c1_coder_array_s52BVvgcaqgLKaYLjO1 *c1_b);
static real_T c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_slStringInitializeDynamicBuffers
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_chart_data_browse_helper(SFc1_flightControlSystemInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig);
static const mxArray *c1_feval(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, const mxArray *c1_input0, const
  mxArray *c1_input1);
static void c1_b_feval(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, const mxArray *c1_input0, const mxArray *c1_input1);
static void c1_b_ComputeWeightedCentroid(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, real_T c1_I[19200],
  c1_coder_array_s_R6Og1x0kmqQXSF9Pw *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  *c1_statsAlreadyComputed);
static void c1_b_sort(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, c1_coder_array_real_T_2D *c1_b_x,
                      c1_coder_array_int32_T_2D *c1_idx);
static void c1_b_merge_pow2_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_idx,
  c1_coder_array_real_T_2D *c1_b_x, int32_T c1_offset);
static void c1_b_merge_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_idx,
  c1_coder_array_real_T_2D *c1_b_x, int32_T c1_offset, int32_T c1_n, int32_T
  c1_preSortLevel, c1_coder_array_int32_T *c1_iwork, c1_coder_array_real_T
  *c1_xwork);
static void c1_b_merge(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_idx,
  c1_coder_array_real_T_2D *c1_b_x, int32_T c1_offset, int32_T c1_np, int32_T
  c1_nq, c1_coder_array_int32_T *c1_iwork, c1_coder_array_real_T *c1_xwork);
static void c1_b_sortrows(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_b_y, real_T
  c1_c_varargin_1[2]);
static real_T c1_binary_expand_op(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, emlrtRSInfo c1_in1,
  c1_coder_array_real_T *c1_in2, c1_coder_array_real_T *c1_in3);
static void c1_array_real_T_2D_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T_2D
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0, int32_T
  c1_size1);
static void c1_array_creal_T_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_creal_T *c1_coderArray,
  const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0);
static void c1_array_boolean_T_2D_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_boolean_T_2D
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0, int32_T
  c1_size1);
static void c1_array_int32_T_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T *c1_coderArray,
  const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0);
static void c1_array_real_T_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T *c1_coderArray,
  const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0);
static void c1_array_boolean_T_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_boolean_T
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0);
static void c1_array_real32_T_2D_SetSize(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, c1_coder_array_real32_T_2D
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0, int32_T
  c1_size1);
static void c1_array_creal_T_2D_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_creal_T_2D
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0, int32_T
  c1_size1);
static void c1_array_sOA5t73y81YtFHGIDxk0fKF_S
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_coder_array_sOA5t73y81YtFHGIDxk *c1_coderArray, const emlrtRTEInfo
   *c1_srcLocation, int32_T c1_size0);
static void c1_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_coder_array_s_R6Og1x0kmqQXSF9Pw *c1_coderArray, const emlrtRTEInfo
   *c1_srcLocation, int32_T c1_size0);
static void c1_array_real_T_Destructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_real_T *c1_coderArray);
static void c1_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s_R6Og1x0kmqQXSF9Pwa49FD *c1_pStruct);
static void c1_array_real_T_2D_Destructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_real_T_2D *c1_coderArray);
static void c1_c_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s_R6Og1x0kmqQXSF9Pwa49FD *c1_pStruct);
static void c1_array_boolean_T_0x0_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_boolean_T_0x0 *c1_pArray);
static void c1_array_real_T_Constructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_real_T *c1_coderArray);
static void c1_array_real_T_2D_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_real_T_2D *c1_coderArray);
static void c1_array_real_T_1x0_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_real_T_1x0 *c1_pArray);
static void c1_array_cell_wrap_46_2D_SetSize
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_coder_array_cell_wrap_46_2D *c1_coderArray, const emlrtRTEInfo
   *c1_srcLocation, int32_T c1_size0, int32_T c1_size1);
static void c1_array_cell_wrap_46_Destructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance, c1_cell_wrap_46
   *c1_pStruct);
static void c1_array_cell_wrap_46_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance, c1_cell_wrap_46
   *c1_pStruct);
static void c1_array_int32_T_2D_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T_2D
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0, int32_T
  c1_size1);
static void c1_array_real32_T_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real32_T
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0);
static void c1_array_s52BVvgcaqgLKaYLjO15CeF_2
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_coder_array_s52BVvgcaqgLKaYLjO1 *c1_coderArray, const emlrtRTEInfo
   *c1_srcLocation, int32_T c1_size0, int32_T c1_size1);
static void c1_b_array_s52BVvgcaqgLKaYLjO15CeF_2
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_s52BVvgcaqgLKaYLjO1 *c1_coderArray);
static void c1_c_array_s52BVvgcaqgLKaYLjO15CeF_2
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_s52BVvgcaqgLKaYLjO1 *c1_coderArray);
static void c1_array_boolean_T_2D_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_boolean_T_2D *c1_coderArray);
static void c1_array_int32_T_Constructor(SFc1_flightControlSystemInstanceStruct *
  chartInstance, c1_coder_array_int32_T *c1_coderArray);
static void c1_array_creal_T_Constructor(SFc1_flightControlSystemInstanceStruct *
  chartInstance, c1_coder_array_creal_T *c1_coderArray);
static void c1_array_boolean_T_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_boolean_T *c1_coderArray);
static void c1_array_boolean_T_2D_Destructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_boolean_T_2D *c1_coderArray);
static void c1_array_int32_T_Destructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_int32_T *c1_coderArray);
static void c1_array_creal_T_Destructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_creal_T *c1_coderArray);
static void c1_array_boolean_T_Destructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_boolean_T *c1_coderArray);
static void c1_array_real32_T_2D_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_real32_T_2D *c1_coderArray);
static void c1_array_creal_T_2D_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_creal_T_2D *c1_coderArray);
static void c1_array_real32_T_2D_Destructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_real32_T_2D *c1_coderArray);
static void c1_array_creal_T_2D_Destructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_creal_T_2D *c1_coderArray);
static void c1_array_sOA5t73y81YtFHGIDxk0fKF_C
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_sOA5t73y81YtFHGIDxk *c1_coderArray);
static void c1_array_int32_T_2D_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_int32_T_2D *c1_coderArray);
static void c1_array_sOA5t73y81YtFHGIDxk0fKF_D
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_sOA5t73y81YtFHGIDxk *c1_coderArray);
static void c1_array_int32_T_2D_Destructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_int32_T_2D *c1_coderArray);
static void c1_d_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_s_R6Og1x0kmqQXSF9Pwa49FD *c1_dst, const
   c1_s_R6Og1x0kmqQXSF9Pwa49FD *c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_array_real_T_1x2s_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[2], const real_T c1_src[2]);
static void c1_array_real_T_1x4s_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[4], const real_T c1_src[4]);
static void c1_array_boolean_T_0x0_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_boolean_T_0x0 *c1_dst,
  const c1_coder_array_boolean_T_0x0 *c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_array_boolean_T_0x0_SetSize
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, int32_T c1_size[2], const emlrtRTEInfo *c1_srcLocation, int32_T
   c1_size0, int32_T c1_size1);
static void c1_array_real_T_8x2s_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[16], const real_T c1_src[16]);
static void c1_array_real_T_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T *c1_dst, const
  c1_coder_array_real_T *c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_array_real_T_2D_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T_2D *c1_dst,
  const c1_coder_array_real_T_2D *c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_array_real_T_1x0_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T_1x0 *c1_dst,
  const c1_coder_array_real_T_1x0 *c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_array_real_T_1x0_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, int32_T c1_size[2], const
  emlrtRTEInfo *c1_srcLocation, int32_T c1_size0, int32_T c1_size1);
static void c1_array_s_7KvKuzB0WpLeFthPVHAilE_
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s_7KvKuzB0WpLeFthPVHAilE *c1_pStruct);
static void c1_array_cell_wrap_46_2D_Construct
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_cell_wrap_46_2D *c1_coderArray);
static void c1_e_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_s_R6Og1x0kmqQXSF9Pw *c1_coderArray);
static void c1_b_array_s_7KvKuzB0WpLeFthPVHAilE_
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s_7KvKuzB0WpLeFthPVHAilE *c1_pStruct);
static void c1_array_cell_wrap_46_2D_Destructo
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_cell_wrap_46_2D *c1_coderArray);
static void c1_f_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_s_R6Og1x0kmqQXSF9Pw *c1_coderArray);
static void c1_array_cell_wrap_46_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_cell_wrap_46 *c1_dst, const
  c1_cell_wrap_46 *c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_array_cell_wrap_46_1s_Construct
  (SFc1_flightControlSystemInstanceStruct *chartInstance, c1_cell_wrap_46
   c1_pMatrix[1]);
static void c1_array_cell_wrap_46_1s_Destructo
  (SFc1_flightControlSystemInstanceStruct *chartInstance, c1_cell_wrap_46
   c1_pMatrix[1]);
static void c1_array_real32_T_Constructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_real32_T *c1_coderArray);
static void c1_array_real32_T_Destructor(SFc1_flightControlSystemInstanceStruct *
  chartInstance, c1_coder_array_real32_T *c1_coderArray);
static void c1_array_cell_wrap_46_2s_Construct
  (SFc1_flightControlSystemInstanceStruct *chartInstance, c1_cell_wrap_46
   c1_pMatrix[2]);
static void c1_array_cell_wrap_46_2s_Destructo
  (SFc1_flightControlSystemInstanceStruct *chartInstance, c1_cell_wrap_46
   c1_pMatrix[2]);
static int32_T c1_div_nzp_s32(SFc1_flightControlSystemInstanceStruct
  *chartInstance, int32_T c1_numerator, int32_T c1_denominator, int32_T
  c1_EMLOvCount_src_loc, uint32_T c1_ssid_src_loc, int32_T c1_offset_src_loc,
  int32_T c1_length_src_loc);
static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c1_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_doneDoubleBufferReInit = false;
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  static const int32_T c1_b_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c1_c_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c1_postfixPredicateTree[3] = { 0, 1, -2 };

  static const int32_T c1_b_condTxtEndIdx[2] = { 1027, 1037 };

  static const int32_T c1_b_condTxtStartIdx[2] = { 1018, 1031 };

  static const int32_T c1_c_condTxtEndIdx[2] = { 1079, 1090 };

  static const int32_T c1_c_condTxtStartIdx[2] = { 1070, 1083 };

  static const int32_T c1_condTxtEndIdx[2] = { 521, 554 };

  static const int32_T c1_condTxtStartIdx[2] = { 494, 527 };

  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  setDataBrowseFcn(chartInstance->S, (void *)&c1_chart_data_browse_helper);
  chartInstance->c1_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c1_RuntimeVar,
    &chartInstance->c1_IsDebuggerActive,
    &chartInstance->c1_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c1_mlFcnLineNumber, &chartInstance->c1_IsHeatMapPresent, 0);
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c1_JITStateAnimation[0],
                        &chartInstance->c1_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    39U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 8U, 0U,
                  0U, 0U, 1U, 0U, 6U, 3U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "c1_flightControlSystem", 0, -1, 1178);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 408, 429, 962,
                    1014, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 490, 555, 947,
                    948, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 568, 630, 696,
                    769, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 3U, 820, 832, -1,
                    909, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 4U, 971, 983, -1,
                    1010, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 5U, 1015, 1037,
                    1063, 1116, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 6U, 1063, 1090, -1,
                    1116, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 7U, 1120, 1143, -1,
                    1167, false);
  covrtEmlForInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 468, 481, 948);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 493, 555, 2U,
                      0U, &c1_condTxtStartIdx[0], &c1_condTxtEndIdx[0], 3U,
                      &c1_postfixPredicateTree[0], false);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 1018, 1037,
                      2U, 2U, &c1_b_condTxtStartIdx[0], &c1_b_condTxtEndIdx[0],
                      3U, &c1_b_postfixPredicateTree[0], false);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 1070, 1090,
                      2U, 4U, &c1_c_condTxtStartIdx[0], &c1_c_condTxtEndIdx[0],
                      3U, &c1_c_postfixPredicateTree[0], false);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 411,
    429, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 494,
    521, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 527,
    554, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 3U, 571,
    630, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 4U, 823,
    832, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 5U, 974,
    983, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 6U, 1018,
    1027, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 7U, 1031,
    1037, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 8U, 1070,
    1079, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 9U, 1083,
    1090, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 10U, 1123,
    1143, -1, 0U);
}

static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c1_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  c1_coder_array_real_T_2D c1_a__1;
  c1_coder_array_real_T_2D c1_a__2;
  c1_coder_array_real_T_2D c1_centers;
  c1_coder_array_s52BVvgcaqgLKaYLjO1 c1_lines;
  emlrtStack c1_b_st;
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c1_P_data[10];
  real_T c1_angle;
  real_T c1_b_ang;
  real_T c1_b_angelina;
  real_T c1_b_angle_;
  real_T c1_b_data;
  real_T c1_b_data1;
  real_T c1_b_n;
  real_T c1_b_number;
  real_T c1_b_x;
  real_T c1_b_y;
  real_T c1_c_x;
  real_T c1_c_y;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d_n;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_ex;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_maxval;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_r;
  real_T c1_sig;
  int32_T c1_P_size[2];
  int32_T c1_ang;
  int32_T c1_b_k;
  int32_T c1_b_varargin_2;
  int32_T c1_c_n;
  int32_T c1_c_varargin_1;
  int32_T c1_c_varargin_2;
  int32_T c1_d_varargin_1;
  int32_T c1_d_varargin_2;
  int32_T c1_e_varargin_1;
  int32_T c1_e_varargin_2;
  int32_T c1_exitg2;
  int32_T c1_f_varargin_1;
  int32_T c1_first;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_idx;
  int32_T c1_k;
  int32_T c1_n;
  boolean_T c1_BW[19200];
  boolean_T c1_BW3[19200];
  boolean_T c1_BW4[19200];
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_exitg1;
  boolean_T c1_guard1;
  boolean_T c1_p;
  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 2U,
                    *chartInstance->c1_angle_);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, *chartInstance->c1_data);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (*chartInstance->c1_u)
                      [c1_i]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_b_data = *chartInstance->c1_data;
  c1_b_angle_ = *chartInstance->c1_angle_;
  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  c1_b_angelina = c1_b_angle_;
  c1_b_data1 = c1_b_data;
  c1_b_st.site = &c1_emlrtRSI;
  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    chartInstance->c1_b_dv[c1_i1] = (*chartInstance->c1_u)[c1_i1];
  }

  c1_imbinarize(chartInstance, &c1_b_st, chartInstance->c1_b_dv, c1_BW3);
  c1_b_st.site = &c1_b_emlrtRSI;
  c1_edge(chartInstance, &c1_b_st, c1_BW3, c1_BW);
  c1_b_st.site = &c1_c_emlrtRSI;
  c1_bwmorph(chartInstance, c1_BW, c1_BW4);
  c1_array_real_T_2D_Constructor(chartInstance, &c1_centers);
  c1_array_real_T_2D_Constructor(chartInstance, &c1_a__1);
  c1_array_real_T_2D_Constructor(chartInstance, &c1_a__2);
  c1_b_st.site = &c1_d_emlrtRSI;
  c1_imfindcircles(chartInstance, &c1_b_st, c1_BW3, &c1_centers, &c1_a__1,
                   &c1_a__2);
  c1_array_real_T_2D_Destructor(chartInstance, &c1_a__2);
  c1_array_real_T_2D_Destructor(chartInstance, &c1_a__1);
  c1_b_st.site = &c1_e_emlrtRSI;
  c1_hough(chartInstance, &c1_b_st, c1_BW4, chartInstance->c1_H);
  for (c1_i2 = 0; c1_i2 < 71820; c1_i2++) {
    chartInstance->c1_varargin_1[c1_i2] = chartInstance->c1_H[c1_i2];
  }

  c1_b_x = chartInstance->c1_varargin_1[0];
  c1_c_x = c1_b_x;
  c1_b = muDoubleScalarIsNaN(c1_c_x);
  c1_p = !c1_b;
  if (c1_p) {
    c1_idx = 1;
  } else {
    c1_idx = 0;
    c1_k = 2;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k < 71821)) {
      c1_d_x = chartInstance->c1_varargin_1[c1_k - 1];
      c1_f_x = c1_d_x;
      c1_b_b = muDoubleScalarIsNaN(c1_f_x);
      c1_b_p = !c1_b_b;
      if (c1_b_p) {
        c1_idx = c1_k;
        c1_exitg1 = true;
      } else {
        c1_k++;
      }
    }
  }

  if (c1_idx == 0) {
    c1_maxval = chartInstance->c1_varargin_1[0];
  } else {
    c1_first = c1_idx - 1;
    c1_ex = chartInstance->c1_varargin_1[c1_first];
    c1_i3 = c1_first;
    for (c1_b_k = c1_i3 + 2; c1_b_k < 71821; c1_b_k++) {
      if (c1_ex < chartInstance->c1_varargin_1[c1_b_k - 1]) {
        c1_ex = chartInstance->c1_varargin_1[c1_b_k - 1];
      }
    }

    c1_maxval = c1_ex;
  }

  c1_e_x = 0.3 * c1_maxval;
  c1_g_x = c1_e_x;
  c1_b_y = c1_g_x;
  c1_b_y = muDoubleScalarCeil(c1_b_y);
  c1_b_st.site = &c1_f_emlrtRSI;
  c1_houghpeaks(chartInstance, &c1_b_st, chartInstance->c1_H, c1_b_y, c1_P_data,
                c1_P_size);
  c1_b_array_s52BVvgcaqgLKaYLjO15CeF_2(chartInstance, &c1_lines);
  c1_b_st.site = &c1_g_emlrtRSI;
  c1_houghlines(chartInstance, &c1_b_st, c1_BW, c1_P_data, c1_P_size, &c1_lines);
  c1_angle = 0.0;
  c1_r = 0.0;
  c1_b_number = 0.0;
  if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
        4U, 0U, 0U, (real_T)c1_lines.size[1], 4.0, -1, 0U, (real_T)
        c1_lines.size[1] == 4.0))) {
    c1_b_number = 1.0;
    c1_sig = 0.0;
    c1_ang = 0;
    c1_guard1 = false;
    do {
      c1_exitg2 = 0;
      if (c1_ang < 4) {
        c1_b_ang = 1.0 + (real_T)c1_ang;
        covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 0, 1);
        c1_i4 = c1_lines.size[1];
        if (c1_b_ang != (real_T)(int32_T)muDoubleScalarFloor(c1_b_ang)) {
          emlrtIntegerCheckR2012b(c1_b_ang, &c1_e_emlrtDCI, &c1_st);
        }

        c1_i5 = (int32_T)c1_b_ang;
        if ((c1_i5 < 1) || (c1_i5 > c1_i4)) {
          emlrtDynamicBoundsCheckR2012b(c1_i5, 1, c1_i4, &c1_e_emlrtBCI, &c1_st);
        }

        c1_d = c1_lines.vector.data[c1_i5 - 1].theta;
        if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 0,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c1_covrtInstance, 4U, 0U, 1U, c1_d,
                              c1_b_angle_ + 5.0, -1, 4U, c1_d > c1_b_angle_ +
                              5.0))) {
          c1_guard1 = true;
          c1_exitg2 = 1;
        } else {
          c1_i8 = c1_lines.size[1];
          if (c1_b_ang != (real_T)(int32_T)muDoubleScalarFloor(c1_b_ang)) {
            emlrtIntegerCheckR2012b(c1_b_ang, &c1_f_emlrtDCI, &c1_st);
          }

          c1_i10 = (int32_T)c1_b_ang;
          if ((c1_i10 < 1) || (c1_i10 > c1_i8)) {
            emlrtDynamicBoundsCheckR2012b(c1_i10, 1, c1_i8, &c1_f_emlrtBCI,
              &c1_st);
          }

          c1_d1 = c1_lines.vector.data[c1_i10 - 1].theta;
          if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 1,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c1_covrtInstance, 4U, 0U, 2U,
                                c1_d1, c1_b_angle_ - 5.0, -1, 2U, c1_d1 <
                                c1_b_angle_ - 5.0))) {
            c1_guard1 = true;
            c1_exitg2 = 1;
          } else {
            covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 0, false);
            covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 1, false);
            c1_ang++;
            _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
            c1_guard1 = false;
          }
        }
      } else {
        covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 0, 0);
        c1_exitg2 = 1;
      }
    } while (c1_exitg2 == 0);

    if (c1_guard1) {
      covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 0, true);
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 1, true);
      c1_i6 = c1_lines.size[1];
      if (c1_b_ang != (real_T)(int32_T)muDoubleScalarFloor(c1_b_ang)) {
        emlrtIntegerCheckR2012b(c1_b_ang, &c1_emlrtDCI, &c1_st);
      }

      c1_i7 = (int32_T)c1_b_ang;
      if ((c1_i7 < 1) || (c1_i7 > c1_i6)) {
        emlrtDynamicBoundsCheckR2012b(c1_i7, 1, c1_i6, &c1_emlrtBCI, &c1_st);
      }

      c1_i9 = c1_i7 - 1;
      c1_h_x = c1_lines.vector.data[c1_i9].point1[0] - 90.0;
      c1_i_x = c1_h_x;
      c1_j_x = c1_i_x;
      c1_d2 = muDoubleScalarAbs(c1_j_x);
      c1_i11 = c1_lines.size[1];
      if (c1_b_ang != (real_T)(int32_T)muDoubleScalarFloor(c1_b_ang)) {
        emlrtIntegerCheckR2012b(c1_b_ang, &c1_b_emlrtDCI, &c1_st);
      }

      c1_i12 = (int32_T)c1_b_ang;
      if ((c1_i12 < 1) || (c1_i12 > c1_i11)) {
        emlrtDynamicBoundsCheckR2012b(c1_i12, 1, c1_i11, &c1_b_emlrtBCI, &c1_st);
      }

      c1_i13 = c1_i12 - 1;
      c1_k_x = c1_lines.vector.data[c1_i13].point2[0] - 90.0;
      c1_l_x = c1_k_x;
      c1_m_x = c1_l_x;
      c1_d3 = muDoubleScalarAbs(c1_m_x);
      if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 2,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 3U, c1_d2,
                          c1_d3, -1, 4U, c1_d2 > c1_d3))) {
        c1_i15 = c1_lines.size[1];
        if (c1_b_ang != (real_T)(int32_T)muDoubleScalarFloor(c1_b_ang)) {
          emlrtIntegerCheckR2012b(c1_b_ang, &c1_d_emlrtDCI, &c1_st);
        }

        c1_i17 = (int32_T)c1_b_ang;
        if ((c1_i17 < 1) || (c1_i17 > c1_i15)) {
          emlrtDynamicBoundsCheckR2012b(c1_i17, 1, c1_i15, &c1_d_emlrtBCI,
            &c1_st);
        }

        c1_i19 = c1_i17 - 1;
        c1_o_x = c1_lines.vector.data[c1_i19].point1[0] - 90.0;
        c1_sig = c1_o_x;
        c1_sig = muDoubleScalarSign(c1_sig);
      } else {
        c1_i14 = c1_lines.size[1];
        if (c1_b_ang != (real_T)(int32_T)muDoubleScalarFloor(c1_b_ang)) {
          emlrtIntegerCheckR2012b(c1_b_ang, &c1_c_emlrtDCI, &c1_st);
        }

        c1_i16 = (int32_T)c1_b_ang;
        if ((c1_i16 < 1) || (c1_i16 > c1_i14)) {
          emlrtDynamicBoundsCheckR2012b(c1_i16, 1, c1_i14, &c1_c_emlrtBCI,
            &c1_st);
        }

        c1_i18 = c1_i16 - 1;
        c1_n_x = c1_lines.vector.data[c1_i18].point2[0] - 90.0;
        c1_sig = c1_n_x;
        c1_sig = muDoubleScalarSign(c1_sig);
      }

      c1_i20 = c1_lines.size[1];
      if (c1_b_ang != (real_T)(int32_T)muDoubleScalarFloor(c1_b_ang)) {
        emlrtIntegerCheckR2012b(c1_b_ang, &c1_g_emlrtDCI, &c1_st);
      }

      c1_i21 = (int32_T)c1_b_ang;
      if ((c1_i21 < 1) || (c1_i21 > c1_i20)) {
        emlrtDynamicBoundsCheckR2012b(c1_i21, 1, c1_i20, &c1_g_emlrtBCI, &c1_st);
      }

      c1_angle = c1_lines.vector.data[c1_i21 - 1].theta;
      if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 3,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 4U, c1_b_data,
                          0.0, -1, 0U, c1_b_data == 0.0))) {
        c1_b_data1 = 1.0;
        c1_b_angelina = c1_angle;
      }
    }

    c1_r = c1_sig;
  } else if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 4,
              covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance, 4U, 0U,
    5U, c1_b_data, 1.0, -1, 0U, c1_b_data == 1.0))) {
    c1_b_data1 = 0.0;
  }

  c1_c_array_s52BVvgcaqgLKaYLjO15CeF_2(chartInstance, &c1_lines);
  if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 2,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c1_covrtInstance, 4U, 0U, 6U, c1_angle,
                        0.0, -1, 2U, c1_angle < 0.0)) && covrtEmlCondEval
      (chartInstance->c1_covrtInstance, 4U, 0, 3, covrtRelationalopUpdateFcn
       (chartInstance->c1_covrtInstance, 4U, 0U, 7U, c1_r, 1.0, -1, 0U, c1_r ==
        1.0))) {
    covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 1, true);
    covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 5, true);
    c1_angle += 180.0;
  } else {
    covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 1, false);
    covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 5, false);
    if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 4,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 8U, c1_angle,
                          0.0, -1, 4U, c1_angle > 0.0)) && covrtEmlCondEval
        (chartInstance->c1_covrtInstance, 4U, 0, 5, covrtRelationalopUpdateFcn
         (chartInstance->c1_covrtInstance, 4U, 0U, 9U, c1_r, -1.0, -1, 0U, c1_r ==
          -1.0))) {
      covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 2, true);
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 6, true);
      c1_angle -= 180.0;
    } else {
      covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 2, false);
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 6, false);
    }
  }

  c1_c_varargin_1 = c1_centers.size[0];
  c1_b_varargin_2 = c1_centers.size[1];
  c1_d_varargin_1 = c1_c_varargin_1;
  c1_c_varargin_2 = c1_b_varargin_2;
  if ((c1_d_varargin_1 == 0) || (c1_c_varargin_2 == 0)) {
    c1_n = 0;
  } else if (c1_d_varargin_1 > c1_c_varargin_2) {
    c1_n = c1_d_varargin_1;
  } else {
    c1_n = c1_c_varargin_2;
  }

  c1_b_n = (real_T)c1_n;
  c1_e_varargin_1 = c1_centers.size[0];
  c1_d_varargin_2 = c1_centers.size[1];
  c1_array_real_T_2D_Destructor(chartInstance, &c1_centers);
  c1_f_varargin_1 = c1_e_varargin_1;
  c1_e_varargin_2 = c1_d_varargin_2;
  if ((c1_f_varargin_1 == 0) || (c1_e_varargin_2 == 0)) {
    c1_c_n = 0;
  } else if (c1_f_varargin_1 > c1_e_varargin_2) {
    c1_c_n = c1_f_varargin_1;
  } else {
    c1_c_n = c1_e_varargin_2;
  }

  c1_d_n = (real_T)c1_c_n;
  if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 7,
                     covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
        4U, 0U, 10U, c1_b_n, 2.0, -1, 0U, c1_d_n == 2.0))) {
    c1_b_number = 2.0;
  }

  c1_c_y = c1_angle;
  *chartInstance->c1_y = c1_c_y;
  *chartInstance->c1_number = c1_b_number;
  *chartInstance->c1_data1 = c1_b_data1;
  *chartInstance->c1_angelina = c1_b_angelina;
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 3U, *chartInstance->c1_y);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 4U,
                    *chartInstance->c1_number);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 5U,
                    *chartInstance->c1_data1);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 6U,
                    *chartInstance->c1_angelina);
}

static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_st;
  c1_st = NULL;
  c1_st = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createcellmatrix(4, 1), false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", chartInstance->c1_angelina, 0, 0U, 0,
    0U, 0), false);
  sf_mex_setcell(c1_b_y, 0, c1_c_y);
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", chartInstance->c1_data1, 0, 0U, 0,
    0U, 0), false);
  sf_mex_setcell(c1_b_y, 1, c1_d_y);
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", chartInstance->c1_number, 0, 0U, 0,
    0U, 0), false);
  sf_mex_setcell(c1_b_y, 2, c1_e_y);
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", chartInstance->c1_y, 0, 0U, 0, 0U, 0),
                false);
  sf_mex_setcell(c1_b_y, 3, c1_f_y);
  sf_mex_assign(&c1_st, c1_b_y, false);
  return c1_st;
}

static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_b_u;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_b_u = sf_mex_dup(c1_st);
  *chartInstance->c1_angelina = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_b_u, 0)), "angelina");
  *chartInstance->c1_data1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_b_u, 1)), "data1");
  *chartInstance->c1_number = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_b_u, 2)), "number");
  *chartInstance->c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_b_u, 3)), "y");
  sf_mex_destroy(&c1_b_u);
  sf_mex_destroy(&c1_st);
}

static void c1_imbinarize(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_I[19200], boolean_T c1_BW[19200])
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  real_T c1_b_y[256];
  real_T c1_localBins1[256];
  real_T c1_localBins2[256];
  real_T c1_localBins3[256];
  real_T c1_T;
  real_T c1_b_out;
  real_T c1_d_i;
  real_T c1_t;
  int32_T c1_b_c;
  int32_T c1_b_i;
  int32_T c1_c;
  int32_T c1_c_a;
  int32_T c1_c_c;
  int32_T c1_c_i;
  int32_T c1_d_a;
  int32_T c1_d_c;
  int32_T c1_e_a;
  int32_T c1_e_c;
  int32_T c1_f_a;
  int32_T c1_f_c;
  int32_T c1_g_a;
  int32_T c1_g_c;
  int32_T c1_h_a;
  int32_T c1_h_c;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i_a;
  int32_T c1_i_c;
  int32_T c1_idx;
  int32_T c1_idx1;
  int32_T c1_idx2;
  int32_T c1_idx3;
  int32_T c1_idx4;
  int32_T c1_j_a;
  int32_T c1_j_c;
  int32_T c1_k_a;
  int32_T c1_l_a;
  uint8_T c1_b_u[19200];
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_h_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_b_st.site = &c1_i_emlrtRSI;
  c1_c_st.site = &c1_j_emlrtRSI;
  c1_d_st.site = &c1_k_emlrtRSI;
  grayto8_real64(&c1_I[0], &c1_b_u[0], 19200.0);
  c1_b_st.site = &c1_i_emlrtRSI;
  c1_c_st.site = &c1_m_emlrtRSI;
  c1_d_st.site = &c1_o_emlrtRSI;
  c1_b_out = 1.0;
  getnumcores(&c1_b_out);
  c1_d_st.site = &c1_n_emlrtRSI;
  for (c1_i = 0; c1_i < 256; c1_i++) {
    c1_b_y[c1_i] = 0.0;
  }

  for (c1_i1 = 0; c1_i1 < 256; c1_i1++) {
    c1_localBins1[c1_i1] = 0.0;
  }

  for (c1_i2 = 0; c1_i2 < 256; c1_i2++) {
    c1_localBins2[c1_i2] = 0.0;
  }

  for (c1_i3 = 0; c1_i3 < 256; c1_i3++) {
    c1_localBins3[c1_i3] = 0.0;
  }

  for (c1_b_i = 4; c1_b_i <= 19200; c1_b_i += 4) {
    c1_i4 = c1_b_i - 3;
    if ((c1_i4 < 1) || (c1_i4 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c1_i4, 1, 19200, &c1_h_emlrtBCI, &c1_d_st);
    }

    c1_idx1 = c1_b_u[c1_i4 - 1];
    c1_i5 = c1_b_i - 2;
    if ((c1_i5 < 1) || (c1_i5 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c1_i5, 1, 19200, &c1_i_emlrtBCI, &c1_d_st);
    }

    c1_idx2 = c1_b_u[c1_i5 - 1];
    c1_i7 = c1_b_i - 1;
    if ((c1_i7 < 1) || (c1_i7 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c1_i7, 1, 19200, &c1_j_emlrtBCI, &c1_d_st);
    }

    c1_idx3 = c1_b_u[c1_i7 - 1];
    if ((c1_b_i < 1) || (c1_b_i > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c1_b_i, 1, 19200, &c1_k_emlrtBCI, &c1_d_st);
    }

    c1_idx4 = c1_b_u[c1_b_i - 1];
    c1_e_a = c1_idx1 + 1;
    c1_c_c = c1_e_a - 1;
    c1_f_a = c1_idx1 + 1;
    c1_d_c = c1_f_a - 1;
    c1_localBins1[c1_c_c] = c1_localBins1[c1_d_c] + 1.0;
    c1_g_a = c1_idx2 + 1;
    c1_e_c = c1_g_a - 1;
    c1_h_a = c1_idx2 + 1;
    c1_f_c = c1_h_a - 1;
    c1_localBins2[c1_e_c] = c1_localBins2[c1_f_c] + 1.0;
    c1_i_a = c1_idx3 + 1;
    c1_g_c = c1_i_a - 1;
    c1_j_a = c1_idx3 + 1;
    c1_h_c = c1_j_a - 1;
    c1_localBins3[c1_g_c] = c1_localBins3[c1_h_c] + 1.0;
    c1_k_a = c1_idx4 + 1;
    c1_i_c = c1_k_a - 1;
    c1_l_a = c1_idx4 + 1;
    c1_j_c = c1_l_a - 1;
    c1_b_y[c1_i_c] = c1_b_y[c1_j_c] + 1.0;
  }

  while (c1_b_i - 3 <= 19200) {
    c1_idx = c1_b_u[c1_b_i - 4];
    c1_c_a = c1_idx + 1;
    c1_c = c1_c_a - 1;
    c1_d_a = c1_idx + 1;
    c1_b_c = c1_d_a - 1;
    c1_b_y[c1_c] = c1_b_y[c1_b_c] + 1.0;
    c1_b_i++;
  }

  for (c1_c_i = 0; c1_c_i < 256; c1_c_i++) {
    c1_d_i = (real_T)c1_c_i + 1.0;
    c1_b_y[(int32_T)c1_d_i - 1] = ((c1_b_y[(int32_T)c1_d_i - 1] + c1_localBins1
      [(int32_T)c1_d_i - 1]) + c1_localBins2[(int32_T)c1_d_i - 1]) +
      c1_localBins3[(int32_T)c1_d_i - 1];
  }

  c1_b_st.site = &c1_i_emlrtRSI;
  c1_t = c1_otsuthresh(chartInstance, &c1_b_st, c1_b_y);
  c1_T = c1_t;
  for (c1_i6 = 0; c1_i6 < 19200; c1_i6++) {
    c1_BW[c1_i6] = (c1_I[c1_i6] > c1_T);
  }
}

static real_T c1_otsuthresh(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_counts[256])
{
  static char_T c1_b_cv[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'o', 't', 's',
    'u', 't', 'h', 'r', 'e', 's', 'h', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c1_b_cv1[6] = { 'C', 'O', 'U', 'N', 'T', 'S' };

  emlrtStack c1_b_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  real_T c1_mu[256];
  real_T c1_omega[256];
  real_T c1_b_k;
  real_T c1_b_p;
  real_T c1_b_x;
  real_T c1_c;
  real_T c1_c_a;
  real_T c1_c_x;
  real_T c1_d_a;
  real_T c1_d_k;
  real_T c1_d_x;
  real_T c1_e_a;
  real_T c1_e_x;
  real_T c1_f_a;
  real_T c1_g_a;
  real_T c1_idx;
  real_T c1_maxval;
  real_T c1_mu_t;
  real_T c1_num_elems;
  real_T c1_num_maxval;
  real_T c1_sigma_b_squared;
  real_T c1_t;
  int32_T c1_c_k;
  int32_T c1_e_k;
  int32_T c1_f_k;
  int32_T c1_k;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b_b;
  boolean_T c1_c_b;
  boolean_T c1_d_b;
  boolean_T c1_exitg1;
  boolean_T c1_isfinite_maxval;
  boolean_T c1_p;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_st.site = &c1_q_emlrtRSI;
  c1_b_st.site = &c1_s_emlrtRSI;
  c1_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 256)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_b_x = c1_counts[(int32_T)c1_b_k - 1];
    c1_c_x = c1_b_x;
    c1_b_b = muDoubleScalarIsInf(c1_c_x);
    c1_b1 = !c1_b_b;
    c1_c_b = c1_b1;
    if (c1_c_b) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 32),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1, 0U, 2, 1, 6),
                  false);
    sf_mex_call(&c1_b_st, &c1_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_b_st, NULL, "message", 1U, 2U, 14, c1_c_y, 14, c1_d_y)));
  }

  c1_b_st.site = &c1_s_emlrtRSI;
  c1_num_elems = 0.0;
  for (c1_c_k = 0; c1_c_k < 256; c1_c_k++) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_num_elems += c1_counts[(int32_T)c1_d_k - 1];
  }

  c1_omega[0] = c1_counts[0] / c1_num_elems;
  c1_mu[0] = c1_omega[0];
  for (c1_e_k = 0; c1_e_k < 255; c1_e_k++) {
    c1_d_k = (real_T)c1_e_k + 2.0;
    c1_b_p = c1_counts[(int32_T)c1_d_k - 1] / c1_num_elems;
    c1_omega[(int32_T)c1_d_k - 1] = c1_omega[(int32_T)(c1_d_k - 1.0) - 1] +
      c1_b_p;
    c1_mu[(int32_T)c1_d_k - 1] = c1_mu[(int32_T)(c1_d_k - 1.0) - 1] + c1_b_p *
      c1_d_k;
  }

  c1_mu_t = c1_mu[255];
  c1_maxval = rtMinusInf;
  c1_idx = 0.0;
  c1_num_maxval = 0.0;
  for (c1_f_k = 0; c1_f_k < 255; c1_f_k++) {
    c1_d_k = (real_T)c1_f_k + 1.0;
    c1_st.site = &c1_r_emlrtRSI;
    c1_c_a = c1_mu_t * c1_omega[(int32_T)c1_d_k - 1] - c1_mu[(int32_T)c1_d_k - 1];
    c1_b_st.site = &c1_t_emlrtRSI;
    c1_d_a = c1_c_a;
    c1_e_a = c1_d_a;
    c1_f_a = c1_e_a;
    c1_g_a = c1_f_a;
    c1_c = c1_g_a * c1_g_a;
    c1_sigma_b_squared = c1_c / (c1_omega[(int32_T)c1_d_k - 1] * (1.0 -
      c1_omega[(int32_T)c1_d_k - 1]));
    if (c1_sigma_b_squared > c1_maxval) {
      c1_maxval = c1_sigma_b_squared;
      c1_idx = c1_d_k;
      c1_num_maxval = 1.0;
    } else if (c1_sigma_b_squared == c1_maxval) {
      c1_idx += c1_d_k;
      c1_num_maxval++;
    }
  }

  c1_d_x = c1_maxval;
  c1_e_x = c1_d_x;
  c1_d_b = muDoubleScalarIsInf(c1_e_x);
  c1_b2 = !c1_d_b;
  c1_isfinite_maxval = c1_b2;
  if (c1_isfinite_maxval) {
    c1_idx /= c1_num_maxval;
    c1_t = (c1_idx - 1.0) / 255.0;
  } else {
    c1_t = 0.0;
  }

  return c1_t;
}

static void c1_edge(SFc1_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200],
                    boolean_T c1_varargout_1[19200])
{
  static real_T c1_b_kernel[13] = { 3.4813359214923059E-5,
    0.00054457256285105158, 0.0051667606200595222, 0.029732654490475543,
    0.10377716120747747, 0.21969625200024598, 0.28209557151935094,
    0.21969625200024598, 0.10377716120747747, 0.029732654490475543,
    0.0051667606200595222, 0.00054457256285105158, 3.4813359214923059E-5 };

  static real_T c1_kernel[13] = { 3.4813359214923059E-5, 0.00054457256285105158,
    0.0051667606200595222, 0.029732654490475543, 0.10377716120747747,
    0.21969625200024598, 0.28209557151935094, 0.21969625200024598,
    0.10377716120747747, 0.029732654490475543, 0.0051667606200595222,
    0.00054457256285105158, 3.4813359214923059E-5 };

  static int32_T c1_idxA[344] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
    53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
    72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,
    108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
    59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
    78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
    97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112,
    113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
    128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142,
    143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157,
    158, 159, 160, 160, 160, 160, 160, 160, 160 };

  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  real_T c1_counts[64];
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  real_T c1_b_data[1];
  real_T c1_highThresh_data[1];
  real_T c1_lowThresh_data[1];
  real_T c1_b_idx;
  real_T c1_b_j;
  real_T c1_b_lowThresh;
  real_T c1_b_out;
  real_T c1_b_sum;
  real_T c1_d_i;
  real_T c1_d_j;
  real_T c1_f_j;
  real_T c1_g_i;
  real_T c1_highThresh;
  real_T c1_highThreshTemp;
  real_T c1_j_i;
  real_T c1_l_i;
  real_T c1_lowThresh;
  int32_T c1_highThresh_size[1];
  int32_T c1_lowThresh_size[1];
  int32_T c1_b_c;
  int32_T c1_b_i;
  int32_T c1_c;
  int32_T c1_c_i;
  int32_T c1_c_j;
  int32_T c1_e_i;
  int32_T c1_e_j;
  int32_T c1_f_i;
  int32_T c1_h_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i_i;
  int32_T c1_idx;
  int32_T c1_j;
  int32_T c1_k_i;
  int32_T c1_loop_ub;
  real32_T c1_magGrad[19200];
  real32_T c1_b;
  real32_T c1_b_b;
  real32_T c1_b_r;
  real32_T c1_b_varargin_2;
  real32_T c1_b_x;
  real32_T c1_b_x1;
  real32_T c1_b_x2;
  real32_T c1_b_y;
  real32_T c1_c_a;
  real32_T c1_c_b;
  real32_T c1_c_x;
  real32_T c1_c_y;
  real32_T c1_d_a;
  real32_T c1_d_b;
  real32_T c1_d_idx;
  real32_T c1_d_varargin_1;
  real32_T c1_d_x;
  real32_T c1_d_y;
  real32_T c1_e_a;
  real32_T c1_e_x;
  real32_T c1_e_y;
  real32_T c1_f_a;
  real32_T c1_f_x;
  real32_T c1_f_y;
  real32_T c1_g_a;
  real32_T c1_g_b;
  real32_T c1_g_x;
  real32_T c1_g_y;
  real32_T c1_h_a;
  real32_T c1_h_x;
  real32_T c1_h_y;
  real32_T c1_i_a;
  real32_T c1_i_x;
  real32_T c1_i_y;
  real32_T c1_j_x;
  real32_T c1_j_y;
  real32_T c1_k_x;
  real32_T c1_k_y;
  real32_T c1_l_x;
  real32_T c1_l_y;
  real32_T c1_magmax;
  real32_T c1_r;
  real32_T c1_x1;
  real32_T c1_x2;
  int8_T c1_c_idx;
  boolean_T c1_E[19200];
  boolean_T c1_conn[13];
  boolean_T c1_b_modeFlag;
  boolean_T c1_b_tooBig;
  boolean_T c1_c_modeFlag;
  boolean_T c1_c_tooBig;
  boolean_T c1_d_modeFlag;
  boolean_T c1_e_b;
  boolean_T c1_e_modeFlag;
  boolean_T c1_f_b;
  boolean_T c1_f_modeFlag;
  boolean_T c1_g_modeFlag;
  boolean_T c1_h_modeFlag;
  boolean_T c1_i_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_nanFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    chartInstance->c1_a[c1_i] = (real32_T)c1_c_varargin_1[c1_i];
  }

  c1_st.site = &c1_v_emlrtRSI;
  c1_b_st.site = &c1_y_emlrtRSI;
  c1_c_st.site = &c1_db_emlrtRSI;
  c1_d_st.site = &c1_fb_emlrtRSI;
  for (c1_j = 0; c1_j < 160; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    for (c1_b_i = 0; c1_b_i < 132; c1_b_i++) {
      c1_d_i = (real_T)c1_b_i + 1.0;
      if ((c1_iv[(int32_T)c1_d_i - 1] < 1) || (c1_iv[(int32_T)c1_d_i - 1] > 120))
      {
        emlrtDynamicBoundsCheckR2012b(c1_iv[(int32_T)c1_d_i - 1], 1, 120,
          &c1_p_emlrtBCI, &c1_d_st);
      }

      c1_i1 = c1_iv[(int32_T)c1_b_j + 159];
      if ((c1_i1 < 1) || (c1_i1 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c1_i1, 1, 160, &c1_q_emlrtBCI, &c1_d_st);
      }

      chartInstance->c1_aTmp[((int32_T)c1_d_i + 132 * ((int32_T)c1_b_j - 1)) - 1]
        = chartInstance->c1_a[(c1_iv[(int32_T)c1_d_i - 1] + 120 * (c1_i1 - 1)) -
        1];
    }
  }

  c1_c_st.site = &c1_eb_emlrtRSI;
  c1_d_st.site = &c1_gb_emlrtRSI;
  c1_tooBig = true;
  for (c1_c_i = 0; c1_c_i < 2; c1_c_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_padSizeT[c1_i3] = 132.0 + 28.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_outSizeT[c1_i5] = 120.0 + 40.0 * (real_T)c1_i5;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_connDimsT[c1_i7] = 13.0 + -12.0 * (real_T)c1_i7;
    }

    ippfilter_real32(&chartInstance->c1_aTmp[0], &chartInstance->c1_bTmp[0],
                     &c1_outSizeT[0], 2.0, &c1_padSizeT[0], &c1_kernel[0],
                     &c1_connDimsT[0], true);
  } else {
    for (c1_i2 = 0; c1_i2 < 13; c1_i2++) {
      c1_conn[c1_i2] = true;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_padSizeT[c1_i4] = 132.0 + 28.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_outSizeT[c1_i6] = 120.0 + 40.0 * (real_T)c1_i6;
    }

    for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
      c1_connDimsT[c1_i8] = 13.0 + -12.0 * (real_T)c1_i8;
    }

    for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
      c1_startT[c1_i9] = 6.0 + -6.0 * (real_T)c1_i9;
    }

    imfilter_real32(&chartInstance->c1_aTmp[0], &chartInstance->c1_bTmp[0], 2.0,
                    &c1_outSizeT[0], 2.0, &c1_padSizeT[0], &c1_kernel[0], 13.0,
                    &c1_conn[0], 2.0, &c1_connDimsT[0], &c1_startT[0], 2.0, true,
                    true);
  }

  c1_b_st.site = &c1_ab_emlrtRSI;
  c1_c_st.site = &c1_db_emlrtRSI;
  c1_d_st.site = &c1_fb_emlrtRSI;
  for (c1_c_j = 0; c1_c_j < 172; c1_c_j++) {
    c1_d_j = (real_T)c1_c_j + 1.0;
    for (c1_e_i = 0; c1_e_i < 120; c1_e_i++) {
      c1_g_i = (real_T)c1_e_i + 1.0;
      if ((c1_idxA[(int32_T)c1_g_i - 1] < 1) || (c1_idxA[(int32_T)c1_g_i - 1] >
           120)) {
        emlrtDynamicBoundsCheckR2012b(c1_idxA[(int32_T)c1_g_i - 1], 1, 120,
          &c1_p_emlrtBCI, &c1_d_st);
      }

      c1_i10 = c1_idxA[(int32_T)c1_d_j + 171];
      if ((c1_i10 < 1) || (c1_i10 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c1_i10, 1, 160, &c1_q_emlrtBCI, &c1_d_st);
      }

      chartInstance->c1_b_aTmp[((int32_T)c1_g_i + 120 * ((int32_T)c1_d_j - 1)) -
        1] = chartInstance->c1_bTmp[(c1_idxA[(int32_T)c1_g_i - 1] + 120 *
        (c1_i10 - 1)) - 1];
    }
  }

  c1_c_st.site = &c1_eb_emlrtRSI;
  c1_d_st.site = &c1_gb_emlrtRSI;
  c1_b_tooBig = true;
  for (c1_f_i = 0; c1_f_i < 2; c1_f_i++) {
    c1_b_tooBig = false;
  }

  if (!c1_b_tooBig) {
    c1_d_modeFlag = true;
  } else {
    c1_d_modeFlag = false;
  }

  if (c1_d_modeFlag) {
    c1_e_modeFlag = true;
  } else {
    c1_e_modeFlag = false;
  }

  c1_f_modeFlag = c1_e_modeFlag;
  if (c1_f_modeFlag) {
    for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
      c1_padSizeT[c1_i12] = 120.0 + 52.0 * (real_T)c1_i12;
    }

    for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
      c1_outSizeT[c1_i14] = 120.0 + 40.0 * (real_T)c1_i14;
    }

    for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
      c1_connDimsT[c1_i16] = 1.0 + 12.0 * (real_T)c1_i16;
    }

    ippfilter_real32(&chartInstance->c1_b_aTmp[0], &chartInstance->c1_bTmp[0],
                     &c1_outSizeT[0], 2.0, &c1_padSizeT[0], &c1_dv[0],
                     &c1_connDimsT[0], true);
  } else {
    for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
      c1_padSizeT[c1_i11] = 120.0 + 52.0 * (real_T)c1_i11;
    }

    for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
      c1_outSizeT[c1_i13] = 120.0 + 40.0 * (real_T)c1_i13;
    }

    for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
      c1_connDimsT[c1_i15] = 1.0 + 12.0 * (real_T)c1_i15;
    }

    for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
      c1_startT[c1_i17] = 6.0 * (real_T)c1_i17;
    }

    imfilter_real32(&chartInstance->c1_b_aTmp[0], &chartInstance->c1_bTmp[0],
                    2.0, &c1_outSizeT[0], 2.0, &c1_padSizeT[0], &c1_dv1[0], 12.0,
                    &c1_bv[0], 2.0, &c1_connDimsT[0], &c1_startT[0], 2.0, true,
                    true);
  }

  c1_b_st.site = &c1_bb_emlrtRSI;
  c1_c_st.site = &c1_db_emlrtRSI;
  c1_d_st.site = &c1_fb_emlrtRSI;
  for (c1_e_j = 0; c1_e_j < 172; c1_e_j++) {
    c1_f_j = (real_T)c1_e_j + 1.0;
    for (c1_h_i = 0; c1_h_i < 120; c1_h_i++) {
      c1_j_i = (real_T)c1_h_i + 1.0;
      if ((c1_idxA[(int32_T)c1_j_i - 1] < 1) || (c1_idxA[(int32_T)c1_j_i - 1] >
           120)) {
        emlrtDynamicBoundsCheckR2012b(c1_idxA[(int32_T)c1_j_i - 1], 1, 120,
          &c1_p_emlrtBCI, &c1_d_st);
      }

      c1_i18 = c1_idxA[(int32_T)c1_f_j + 171];
      if ((c1_i18 < 1) || (c1_i18 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c1_i18, 1, 160, &c1_q_emlrtBCI, &c1_d_st);
      }

      chartInstance->c1_b_aTmp[((int32_T)c1_j_i + 120 * ((int32_T)c1_f_j - 1)) -
        1] = chartInstance->c1_a[(c1_idxA[(int32_T)c1_j_i - 1] + 120 * (c1_i18 -
        1)) - 1];
    }
  }

  c1_c_st.site = &c1_eb_emlrtRSI;
  c1_d_st.site = &c1_gb_emlrtRSI;
  c1_c_tooBig = true;
  for (c1_i_i = 0; c1_i_i < 2; c1_i_i++) {
    c1_c_tooBig = false;
  }

  if (!c1_c_tooBig) {
    c1_g_modeFlag = true;
  } else {
    c1_g_modeFlag = false;
  }

  if (c1_g_modeFlag) {
    c1_h_modeFlag = true;
  } else {
    c1_h_modeFlag = false;
  }

  c1_i_modeFlag = c1_h_modeFlag;
  if (c1_i_modeFlag) {
    for (c1_i20 = 0; c1_i20 < 2; c1_i20++) {
      c1_padSizeT[c1_i20] = 120.0 + 52.0 * (real_T)c1_i20;
    }

    for (c1_i22 = 0; c1_i22 < 2; c1_i22++) {
      c1_outSizeT[c1_i22] = 120.0 + 40.0 * (real_T)c1_i22;
    }

    for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
      c1_connDimsT[c1_i24] = 1.0 + 12.0 * (real_T)c1_i24;
    }

    ippfilter_real32(&chartInstance->c1_b_aTmp[0], &chartInstance->c1_a[0],
                     &c1_outSizeT[0], 2.0, &c1_padSizeT[0], &c1_b_kernel[0],
                     &c1_connDimsT[0], true);
  } else {
    for (c1_i19 = 0; c1_i19 < 13; c1_i19++) {
      c1_conn[c1_i19] = true;
    }

    for (c1_i21 = 0; c1_i21 < 2; c1_i21++) {
      c1_padSizeT[c1_i21] = 120.0 + 52.0 * (real_T)c1_i21;
    }

    for (c1_i23 = 0; c1_i23 < 2; c1_i23++) {
      c1_outSizeT[c1_i23] = 120.0 + 40.0 * (real_T)c1_i23;
    }

    for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
      c1_connDimsT[c1_i25] = 1.0 + 12.0 * (real_T)c1_i25;
    }

    for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
      c1_startT[c1_i26] = 6.0 * (real_T)c1_i26;
    }

    imfilter_real32(&chartInstance->c1_b_aTmp[0], &chartInstance->c1_a[0], 2.0,
                    &c1_outSizeT[0], 2.0, &c1_padSizeT[0], &c1_kernel[0], 13.0,
                    &c1_conn[0], 2.0, &c1_connDimsT[0], &c1_startT[0], 2.0, true,
                    true);
  }

  for (c1_i27 = 0; c1_i27 < 19200; c1_i27++) {
    chartInstance->c1_b_a[c1_i27] = chartInstance->c1_a[c1_i27];
  }

  c1_b_st.site = &c1_cb_emlrtRSI;
  c1_imfilter(chartInstance, &c1_b_st, chartInstance->c1_b_a,
              chartInstance->c1_a);
  c1_b_x = chartInstance->c1_bTmp[0];
  c1_b_y = chartInstance->c1_a[0];
  c1_c_a = c1_b_x;
  c1_b = c1_b_y;
  c1_c_x = c1_c_a;
  c1_c_y = c1_b;
  c1_x1 = c1_c_x;
  c1_x2 = c1_c_y;
  c1_d_a = c1_x1;
  c1_b_b = c1_x2;
  c1_r = muSingleScalarHypot(c1_d_a, c1_b_b);
  c1_magGrad[0] = c1_r;
  c1_magmax = c1_magGrad[0];
  for (c1_idx = 0; c1_idx < 19199; c1_idx++) {
    c1_b_idx = (real_T)c1_idx + 2.0;
    c1_d_x = chartInstance->c1_bTmp[(int32_T)c1_b_idx - 1];
    c1_f_y = chartInstance->c1_a[(int32_T)c1_b_idx - 1];
    c1_e_a = c1_d_x;
    c1_c_b = c1_f_y;
    c1_e_x = c1_e_a;
    c1_g_y = c1_c_b;
    c1_b_x1 = c1_e_x;
    c1_b_x2 = c1_g_y;
    c1_f_a = c1_b_x1;
    c1_d_b = c1_b_x2;
    c1_b_r = muSingleScalarHypot(c1_f_a, c1_d_b);
    c1_magGrad[(int32_T)c1_b_idx - 1] = c1_b_r;
    c1_d_varargin_1 = c1_magGrad[(int32_T)c1_b_idx - 1];
    c1_b_varargin_2 = c1_magmax;
    c1_g_x = c1_d_varargin_1;
    c1_h_y = c1_b_varargin_2;
    c1_h_x = c1_g_x;
    c1_i_y = c1_h_y;
    c1_i_x = c1_h_x;
    c1_j_y = c1_i_y;
    c1_g_a = c1_i_x;
    c1_g_b = c1_j_y;
    c1_k_x = c1_g_a;
    c1_k_y = c1_g_b;
    c1_l_x = c1_k_x;
    c1_l_y = c1_k_y;
    c1_magmax = muSingleScalarMax(c1_l_x, c1_l_y);
  }

  if (c1_magmax > 0.0F) {
    c1_d_y = c1_magmax;
    c1_e_y = c1_d_y;
    for (c1_i28 = 0; c1_i28 < 19200; c1_i28++) {
      c1_magGrad[c1_i28] /= c1_e_y;
    }
  }

  c1_st.site = &c1_w_emlrtRSI;
  c1_b_st.site = &c1_kb_emlrtRSI;
  c1_c_st.site = &c1_m_emlrtRSI;
  c1_d_st.site = &c1_o_emlrtRSI;
  c1_b_out = 1.0;
  getnumcores(&c1_b_out);
  for (c1_i29 = 0; c1_i29 < 64; c1_i29++) {
    c1_counts[c1_i29] = 0.0;
  }

  c1_nanFlag = false;
  for (c1_k_i = 0; c1_k_i < 19200; c1_k_i++) {
    c1_l_i = (real_T)c1_k_i + 1.0;
    c1_f_x = c1_magGrad[(int32_T)c1_l_i - 1];
    c1_e_b = muSingleScalarIsNaN(c1_f_x);
    if (c1_e_b) {
      c1_nanFlag = true;
      c1_d_idx = 0.0F;
    } else {
      c1_d_idx = c1_magGrad[(int32_T)c1_l_i - 1] * 63.0F + 0.5F;
    }

    if (c1_d_idx > 63.0F) {
      c1_counts[63]++;
    } else {
      c1_j_x = c1_magGrad[(int32_T)c1_l_i - 1];
      c1_f_b = muSingleScalarIsInf(c1_j_x);
      if (c1_f_b) {
        c1_counts[63]++;
      } else {
        c1_h_a = c1_d_idx;
        c1_c = (int32_T)c1_h_a;
        c1_i_a = c1_d_idx;
        c1_b_c = (int32_T)c1_i_a;
        c1_counts[c1_c] = c1_counts[c1_b_c] + 1.0;
      }
    }
  }

  if (c1_nanFlag) {
    c1_d_st.site = &c1_lb_emlrtRSI;
    c1_warning(chartInstance, &c1_d_st);
  }

  c1_b_sum = 0.0;
  c1_c_idx = 1;
  while ((!(c1_b_sum > 13440.0)) && ((real_T)c1_c_idx <= 64.0)) {
    c1_b_sum += c1_counts[c1_c_idx - 1];
    c1_i31 = c1_c_idx + 1;
    if (c1_i31 > 127) {
      c1_i31 = 127;
    } else if (c1_i31 < -128) {
      c1_i31 = -128;
    }

    c1_c_idx = (int8_T)c1_i31;
  }

  c1_i30 = c1_c_idx - 1;
  if (c1_i30 > 127) {
    c1_i30 = 127;
  } else if (c1_i30 < -128) {
    c1_i30 = -128;
  }

  c1_highThreshTemp = (real_T)(int8_T)c1_i30 / 64.0;
  if (((real_T)c1_c_idx > 64.0) && (!(c1_b_sum > 13440.0))) {
    c1_highThresh_size[0] = 0;
    c1_lowThresh_size[0] = 0;
  } else {
    c1_highThresh_size[0] = 1;
    c1_highThresh_data[0] = c1_highThreshTemp;
    c1_loop_ub = c1_highThresh_size[0] - 1;
    for (c1_i32 = 0; c1_i32 <= c1_loop_ub; c1_i32++) {
      c1_b_data[c1_i32] = c1_highThresh_data[c1_i32];
    }

    c1_b_data[0] *= 0.4;
    c1_lowThresh_size[0] = 1;
    c1_lowThresh_data[0] = c1_b_data[0];
  }

  c1_st.site = &c1_x_emlrtRSI;
  c1_i33 = 1;
  if ((c1_i33 < 1) || (c1_i33 > c1_lowThresh_size[0])) {
    emlrtDynamicBoundsCheckR2012b(c1_i33, 1, c1_lowThresh_size[0],
      &c1_n_emlrtBCI, &c1_st);
  }

  c1_b_st.site = &c1_mb_emlrtRSI;
  c1_lowThresh = c1_lowThresh_data[0];
  c1_c_st.site = &c1_ob_emlrtRSI;
  c1_b_lowThresh = c1_lowThresh;
  for (c1_i34 = 0; c1_i34 < 19200; c1_i34++) {
    c1_E[c1_i34] = false;
  }

  for (c1_i35 = 0; c1_i35 < 2; c1_i35++) {
    c1_connDimsT[c1_i35] = 120.0 + 40.0 * (real_T)c1_i35;
  }

  cannythresholding_real32_tbb(&chartInstance->c1_bTmp[0], &chartInstance->c1_a
    [0], &c1_magGrad[0], &c1_connDimsT[0], c1_b_lowThresh, &c1_E[0]);
  c1_i36 = 1;
  if ((c1_i36 < 1) || (c1_i36 > c1_highThresh_size[0])) {
    emlrtDynamicBoundsCheckR2012b(c1_i36, 1, c1_highThresh_size[0],
      &c1_o_emlrtBCI, &c1_st);
  }

  c1_highThresh = c1_highThresh_data[0];
  for (c1_i37 = 0; c1_i37 < 19200; c1_i37++) {
    c1_varargout_1[c1_i37] = ((real_T)c1_magGrad[c1_i37] > c1_highThresh);
  }

  c1_b_st.site = &c1_nb_emlrtRSI;
  c1_c_st.site = &c1_pb_emlrtRSI;
  for (c1_i38 = 0; c1_i38 < 2; c1_i38++) {
    c1_connDimsT[c1_i38] = 120.0 + 40.0 * (real_T)c1_i38;
  }

  ippreconstruct_uint8((uint8_T *)&c1_varargout_1[0], (uint8_T *)&c1_E[0],
                       &c1_connDimsT[0], 2.0);
  c1_i39 = 1;
  if ((c1_i39 < 1) || (c1_i39 > c1_lowThresh_size[0])) {
    emlrtDynamicBoundsCheckR2012b(c1_i39, 1, c1_lowThresh_size[0],
      &c1_l_emlrtBCI, (emlrtConstCTX)c1_sp);
  }

  c1_i40 = 1;
  if ((c1_i40 < 1) || (c1_i40 > c1_highThresh_size[0])) {
    emlrtDynamicBoundsCheckR2012b(c1_i40, 1, c1_highThresh_size[0],
      &c1_m_emlrtBCI, (emlrtConstCTX)c1_sp);
  }
}

static void c1_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_c_varargin_1[19200], real32_T c1_b[19200])
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  real_T c1_b_j;
  real_T c1_c_i;
  int32_T c1_b_i;
  int32_T c1_d_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_j;
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_db_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_b_st.site = &c1_fb_emlrtRSI;
  for (c1_j = 0; c1_j < 160; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 132; c1_i++) {
      c1_c_i = (real_T)c1_i + 1.0;
      if ((c1_iv[(int32_T)c1_c_i - 1] < 1) || (c1_iv[(int32_T)c1_c_i - 1] > 120))
      {
        emlrtDynamicBoundsCheckR2012b(c1_iv[(int32_T)c1_c_i - 1], 1, 120,
          &c1_p_emlrtBCI, &c1_b_st);
      }

      c1_d_i = c1_iv[(int32_T)c1_b_j + 159];
      if ((c1_d_i < 1) || (c1_d_i > 160)) {
        emlrtDynamicBoundsCheckR2012b(c1_d_i, 1, 160, &c1_q_emlrtBCI, &c1_b_st);
      }

      chartInstance->c1_c_aTmp[((int32_T)c1_c_i + 132 * ((int32_T)c1_b_j - 1)) -
        1] = c1_c_varargin_1[(c1_iv[(int32_T)c1_c_i - 1] + 120 * (c1_d_i - 1)) -
        1];
    }
  }

  c1_st.site = &c1_eb_emlrtRSI;
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 132.0 + 28.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 13.0 + -12.0 * (real_T)c1_i6;
    }

    ippfilter_real32(&chartInstance->c1_c_aTmp[0], &c1_b[0], &c1_outSizeT[0],
                     2.0, &c1_padSizeT[0], &c1_dv[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
      c1_padSizeT[c1_i1] = 132.0 + 28.0 * (real_T)c1_i1;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_outSizeT[c1_i3] = 120.0 + 40.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_connDimsT[c1_i5] = 13.0 + -12.0 * (real_T)c1_i5;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_startT[c1_i7] = 6.0 + -6.0 * (real_T)c1_i7;
    }

    imfilter_real32(&chartInstance->c1_c_aTmp[0], &c1_b[0], 2.0, &c1_outSizeT[0],
                    2.0, &c1_padSizeT[0], &c1_dv1[0], 12.0, &c1_bv[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_warning(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp)
{
  static char_T c1_msgID[27] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'h', 'i', 's', 't', 'c', ':', 'i', 'n', 'p', 'u', 't', 'H', 'a', 's', 'N',
    'a', 'N', 's' };

  static char_T c1_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c1_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_msgID, 10, 0U, 1, 0U, 2, 1, 27),
                false);
  c1_st.site = &c1_p_emlrtRSI;
  c1_b_feval(chartInstance, &c1_st, c1_b_y, c1_feval(chartInstance, &c1_st,
              c1_c_y, c1_d_y));
}

static void c1_bwmorph(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_bwin[19200], boolean_T c1_bw[19200])
{
  static boolean_T c1_b_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, false, true, false, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, false, false, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, false, true, true, true, false, false, true, true, false, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, false, false, true, false, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, false, true, true, true, false,
    false, true, true, false, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, false, true, true, true, true, true, true, true, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, false, false,
    true, false, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, false, true, true, true, false, false, true, true,
    false, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, false, true, false, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    false, true, true, true, false, false, true, true, false, true, true, true };

  static boolean_T c1_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, true, true, false, false, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, false,
    false, true, true, false, false, true, true, false, false, true, true, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, false, false, false, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, true, true, true, true, true,
    true, true, false, false, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, false, false, false, true, false, false, true, true, false, false,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, false, false, false, true, false, false, true, true, true, true,
    true, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true };

  real_T c1_sizeIn[2];
  real_T c1_b_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_k;
  boolean_T c1_image_iter1[19200];
  boolean_T c1_last_aout[19200];
  boolean_T c1_b_p;
  boolean_T c1_c_p;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  boolean_T c1_x1;
  boolean_T c1_x2;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_bw[c1_i] = c1_bwin[c1_i];
  }

  do {
    for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
      c1_last_aout[c1_i1] = c1_bw[c1_i1];
    }

    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_sizeIn[c1_i2] = 120.0 + 40.0 * (real_T)c1_i2;
    }

    bwlookup_tbb_boolean(&c1_bw[0], &c1_sizeIn[0], 2.0, &c1_lut[0], 512.0,
                         &c1_image_iter1[0]);
    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_sizeIn[c1_i3] = 120.0 + 40.0 * (real_T)c1_i3;
    }

    bwlookup_tbb_boolean(&c1_image_iter1[0], &c1_sizeIn[0], 2.0, &c1_b_lut[0],
                         512.0, &c1_bw[0]);
    c1_p = false;
    c1_b_p = true;
    c1_k = 0;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k < 19200)) {
      c1_b_k = (real_T)c1_k + 1.0;
      c1_x1 = c1_last_aout[(int32_T)c1_b_k - 1];
      c1_x2 = c1_bw[(int32_T)c1_b_k - 1];
      c1_c_p = ((int32_T)c1_x1 == (int32_T)c1_x2);
      if (!c1_c_p) {
        c1_b_p = false;
        c1_exitg1 = true;
      } else {
        c1_k++;
      }
    }

    if (c1_b_p) {
      c1_p = true;
    }
  } while (!c1_p);
}

static void c1_b_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_c_varargin_1[19200], real32_T c1_b[19200])
{
  static real_T c1_kernel[25] = { 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822,
    0.028084023356349175, 0.054700208300935887, 0.068312293270780214,
    0.054700208300935887, 0.028084023356349175, 0.0350727008055935,
    0.068312293270780214, 0.085311730190125085, 0.068312293270780214,
    0.0350727008055935, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.0350727008055935,
    0.028084023356349175, 0.014418818362460822 };

  static real_T c1_nonZeroKernel[25] = { 0.014418818362460822,
    0.028084023356349175, 0.0350727008055935, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.0350727008055935, 0.068312293270780214, 0.085311730190125085,
    0.068312293270780214, 0.0350727008055935, 0.028084023356349175,
    0.054700208300935887, 0.068312293270780214, 0.054700208300935887,
    0.028084023356349175, 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822 };

  static int32_T c1_idxA[328] = { 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,
    89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
    46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
    65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
    84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101,
    102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
    117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131,
    132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
    147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 160,
    160 };

  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  real_T c1_b_j;
  real_T c1_c_i;
  int32_T c1_b_i;
  int32_T c1_d_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_j;
  boolean_T c1_conn[25];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_db_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_b_st.site = &c1_fb_emlrtRSI;
  for (c1_j = 0; c1_j < 164; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 124; c1_i++) {
      c1_c_i = (real_T)c1_i + 1.0;
      if ((c1_idxA[(int32_T)c1_c_i - 1] < 1) || (c1_idxA[(int32_T)c1_c_i - 1] >
           120)) {
        emlrtDynamicBoundsCheckR2012b(c1_idxA[(int32_T)c1_c_i - 1], 1, 120,
          &c1_p_emlrtBCI, &c1_b_st);
      }

      c1_d_i = c1_idxA[(int32_T)c1_b_j + 163];
      if ((c1_d_i < 1) || (c1_d_i > 160)) {
        emlrtDynamicBoundsCheckR2012b(c1_d_i, 1, 160, &c1_q_emlrtBCI, &c1_b_st);
      }

      chartInstance->c1_d_aTmp[((int32_T)c1_c_i + 124 * ((int32_T)c1_b_j - 1)) -
        1] = c1_c_varargin_1[(c1_idxA[(int32_T)c1_c_i - 1] + 120 * (c1_d_i - 1))
        - 1];
    }
  }

  c1_st.site = &c1_eb_emlrtRSI;
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 124.0 + 40.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 5.0;
    }

    ippfilter_real32(&chartInstance->c1_d_aTmp[0], &c1_b[0], &c1_outSizeT[0],
                     2.0, &c1_padSizeT[0], &c1_kernel[0], &c1_connDimsT[0],
                     false);
  } else {
    for (c1_i1 = 0; c1_i1 < 25; c1_i1++) {
      c1_conn[c1_i1] = true;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_padSizeT[c1_i3] = 124.0 + 40.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_outSizeT[c1_i5] = 120.0 + 40.0 * (real_T)c1_i5;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_connDimsT[c1_i7] = 5.0;
    }

    for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
      c1_startT[c1_i8] = 2.0;
    }

    imfilter_real32(&chartInstance->c1_d_aTmp[0], &c1_b[0], 2.0, &c1_outSizeT[0],
                    2.0, &c1_padSizeT[0], &c1_nonZeroKernel[0], 25.0, &c1_conn[0],
                    2.0, &c1_connDimsT[0], &c1_startT[0], 2.0, true, false);
  }
}

static void c1_c_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_c_varargin_1[19200], real32_T c1_b[19200])
{
  static real_T c1_kernel[9] = { -1.0, -2.0, -1.0, -0.0, -0.0, -0.0, 1.0, 2.0,
    1.0 };

  static real_T c1_nonZeroKernel[6] = { -1.0, -2.0, -1.0, 1.0, 2.0, 1.0 };

  static boolean_T c1_conn[9] = { true, true, true, false, false, false, true,
    true, true };

  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  real_T c1_b_j;
  real_T c1_c_i;
  int32_T c1_b_i;
  int32_T c1_d_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_j;
  real32_T c1_e_aTmp[19764];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_db_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_b_st.site = &c1_fb_emlrtRSI;
  for (c1_j = 0; c1_j < 162; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 122; c1_i++) {
      c1_c_i = (real_T)c1_i + 1.0;
      if ((c1_iv1[(int32_T)c1_c_i - 1] < 1) || (c1_iv1[(int32_T)c1_c_i - 1] >
           120)) {
        emlrtDynamicBoundsCheckR2012b(c1_iv1[(int32_T)c1_c_i - 1], 1, 120,
          &c1_p_emlrtBCI, &c1_b_st);
      }

      c1_d_i = c1_iv1[(int32_T)c1_b_j + 161];
      if ((c1_d_i < 1) || (c1_d_i > 160)) {
        emlrtDynamicBoundsCheckR2012b(c1_d_i, 1, 160, &c1_q_emlrtBCI, &c1_b_st);
      }

      c1_e_aTmp[((int32_T)c1_c_i + 122 * ((int32_T)c1_b_j - 1)) - 1] =
        c1_c_varargin_1[(c1_iv1[(int32_T)c1_c_i - 1] + 120 * (c1_d_i - 1)) - 1];
    }
  }

  c1_st.site = &c1_eb_emlrtRSI;
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 122.0 + 40.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 3.0;
    }

    ippfilter_real32(&c1_e_aTmp[0], &c1_b[0], &c1_outSizeT[0], 2.0,
                     &c1_padSizeT[0], &c1_kernel[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
      c1_padSizeT[c1_i1] = 122.0 + 40.0 * (real_T)c1_i1;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_outSizeT[c1_i3] = 120.0 + 40.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_connDimsT[c1_i5] = 3.0;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_startT[c1_i7] = 1.0;
    }

    imfilter_real32(&c1_e_aTmp[0], &c1_b[0], 2.0, &c1_outSizeT[0], 2.0,
                    &c1_padSizeT[0], &c1_nonZeroKernel[0], 6.0, &c1_conn[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_d_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_c_varargin_1[19200], real32_T c1_b[19200])
{
  static real_T c1_kernel[9] = { -1.0, -0.0, 1.0, -2.0, -0.0, 2.0, -1.0, -0.0,
    1.0 };

  static real_T c1_nonZeroKernel[6] = { -1.0, 1.0, -2.0, 2.0, -1.0, 1.0 };

  static boolean_T c1_conn[9] = { true, false, true, true, false, true, true,
    false, true };

  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  real_T c1_b_j;
  real_T c1_c_i;
  int32_T c1_b_i;
  int32_T c1_d_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_j;
  real32_T c1_e_aTmp[19764];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_db_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_b_st.site = &c1_fb_emlrtRSI;
  for (c1_j = 0; c1_j < 162; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 122; c1_i++) {
      c1_c_i = (real_T)c1_i + 1.0;
      if ((c1_iv1[(int32_T)c1_c_i - 1] < 1) || (c1_iv1[(int32_T)c1_c_i - 1] >
           120)) {
        emlrtDynamicBoundsCheckR2012b(c1_iv1[(int32_T)c1_c_i - 1], 1, 120,
          &c1_p_emlrtBCI, &c1_b_st);
      }

      c1_d_i = c1_iv1[(int32_T)c1_b_j + 161];
      if ((c1_d_i < 1) || (c1_d_i > 160)) {
        emlrtDynamicBoundsCheckR2012b(c1_d_i, 1, 160, &c1_q_emlrtBCI, &c1_b_st);
      }

      c1_e_aTmp[((int32_T)c1_c_i + 122 * ((int32_T)c1_b_j - 1)) - 1] =
        c1_c_varargin_1[(c1_iv1[(int32_T)c1_c_i - 1] + 120 * (c1_d_i - 1)) - 1];
    }
  }

  c1_st.site = &c1_eb_emlrtRSI;
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 122.0 + 40.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 3.0;
    }

    ippfilter_real32(&c1_e_aTmp[0], &c1_b[0], &c1_outSizeT[0], 2.0,
                     &c1_padSizeT[0], &c1_kernel[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
      c1_padSizeT[c1_i1] = 122.0 + 40.0 * (real_T)c1_i1;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_outSizeT[c1_i3] = 120.0 + 40.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_connDimsT[c1_i5] = 3.0;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_startT[c1_i7] = 1.0;
    }

    imfilter_real32(&c1_e_aTmp[0], &c1_b[0], 2.0, &c1_outSizeT[0], 2.0,
                    &c1_padSizeT[0], &c1_nonZeroKernel[0], 6.0, &c1_conn[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_imfindcircles(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200],
  c1_coder_array_real_T_2D *c1_centers, c1_coder_array_real_T_2D *c1_r_estimated,
  c1_coder_array_real_T_2D *c1_metric)
{
  static char_T c1_b_cv3[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  static char_T c1_b_cv6[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'i', 'n', 'c', 'o', 'r', 'r', 'e',
    'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  static char_T c1_b_cv8[38] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'f', 'i', 'n', 'd', 'c', 'i', 'r', 'c', 'l', 'e', 's', ':', 'o', 'u', 't',
    'O', 'f', 'B', 'o', 'u', 'n', 'd', 'C', 'e', 'n', 't', 'e', 'r', 's' };

  static char_T c1_b_cv[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h', 'r',
    'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c1_b_cv2[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'r', 'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p',
    'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  static char_T c1_b_cv4[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'r', 'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'i', 'n', 'c',
    'o', 'r', 'r', 'e', 'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  static char_T c1_b_cv1[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c1_b_cv5[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c1_b_cv7[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  c1_coder_array_boolean_T c1_c_centers;
  c1_coder_array_boolean_T c1_d_centers;
  c1_coder_array_boolean_T_2D c1_e_x;
  c1_coder_array_creal_T c1_b_x;
  c1_coder_array_creal_T c1_f_x;
  c1_coder_array_int32_T c1_ii;
  c1_coder_array_real_T c1_b_varargin_2;
  c1_coder_array_real_T c1_e_centers;
  c1_coder_array_real_T c1_f_centers;
  c1_coder_array_real_T c1_idx2Keep;
  c1_coder_array_real_T_2D c1_b_centers;
  c1_coder_array_real_T_2D c1_b_metric;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_st;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_i_y = NULL;
  const mxArray *c1_j_y = NULL;
  const mxArray *c1_k_y = NULL;
  const mxArray *c1_l_y = NULL;
  const mxArray *c1_m_y = NULL;
  const mxArray *c1_n_y = NULL;
  const mxArray *c1_o_y = NULL;
  const mxArray *c1_p_y = NULL;
  creal_T c1_d_x;
  real_T c1_c_dv[2];
  real_T c1_b_k;
  real_T c1_b_u;
  real_T c1_d;
  real_T c1_e_k;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_q_y;
  real_T c1_r_y;
  int32_T c1_b_iv[2];
  int32_T c1_b_ii;
  int32_T c1_b_loop_ub;
  int32_T c1_b_nx;
  int32_T c1_c_b;
  int32_T c1_c_ii;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_c_metric;
  int32_T c1_c_nx;
  int32_T c1_d_b;
  int32_T c1_d_k;
  int32_T c1_d_loop_ub;
  int32_T c1_d_nx;
  int32_T c1_e_b;
  int32_T c1_e_loop_ub;
  int32_T c1_f_b;
  int32_T c1_f_k;
  int32_T c1_f_loop_ub;
  int32_T c1_g_b;
  int32_T c1_g_centers;
  int32_T c1_g_k;
  int32_T c1_g_loop_ub;
  int32_T c1_h_b;
  int32_T c1_h_k;
  int32_T c1_h_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i_k;
  int32_T c1_i_loop_ub;
  int32_T c1_idx;
  int32_T c1_j_loop_ub;
  int32_T c1_k;
  int32_T c1_k_loop_ub;
  int32_T c1_l_loop_ub;
  int32_T c1_loop_ub;
  int32_T c1_m_loop_ub;
  int32_T c1_n_loop_ub;
  int32_T c1_nx;
  int32_T c1_o_loop_ub;
  int32_T c1_p_loop_ub;
  int32_T c1_q_loop_ub;
  int32_T c1_r_loop_ub;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b10;
  boolean_T c1_b11;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  boolean_T c1_b6;
  boolean_T c1_b7;
  boolean_T c1_b8;
  boolean_T c1_b9;
  boolean_T c1_b_b;
  boolean_T c1_b_overflow;
  boolean_T c1_b_p;
  boolean_T c1_b_y;
  boolean_T c1_c_overflow;
  boolean_T c1_c_x;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_st.site = &c1_nj_emlrtRSI;
  c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_centers, &c1_g_emlrtRTEI,
    0, 0);
  c1_st.site = &c1_mj_emlrtRSI;
  c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_r_estimated,
    &c1_h_emlrtRTEI, 0, 0);
  c1_st.site = &c1_lj_emlrtRSI;
  c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_metric, &c1_i_emlrtRTEI,
    0, 0);
  c1_st.site = &c1_yb_emlrtRSI;
  c1_chaccum(chartInstance, &c1_st, c1_c_varargin_1,
             chartInstance->c1_accumMatrix, chartInstance->c1_gradientImg);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    chartInstance->c1_x[c1_i] = chartInstance->c1_accumMatrix[c1_i];
  }

  c1_array_creal_T_Constructor(chartInstance, &c1_b_x);
  c1_array_creal_T_SetSize(chartInstance, c1_sp, &c1_b_x, &c1_j_emlrtRTEI, 19200);
  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    c1_b_x.vector.data[c1_i1] = chartInstance->c1_x[c1_i1];
  }

  c1_b_y = false;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 19200)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_c_x = ((c1_b_x.vector.data[(int32_T)c1_b_k - 1].re == c1_dc.re) &&
              (c1_b_x.vector.data[(int32_T)c1_b_k - 1].im == c1_dc.im));
    if (c1_c_x) {
      c1_b = true;
    } else {
      c1_d_x = c1_b_x.vector.data[(int32_T)c1_b_k - 1];
      c1_b1 = muDoubleScalarIsNaN(c1_d_x.re);
      c1_b2 = muDoubleScalarIsNaN(c1_d_x.im);
      c1_b_b = (c1_b1 || c1_b2);
      if (c1_b_b) {
        c1_b = true;
      } else {
        c1_b = false;
      }
    }

    if (!c1_b) {
      c1_b_y = true;
      c1_exitg1 = true;
    } else {
      c1_k++;
    }
  }

  c1_array_creal_T_Destructor(chartInstance, &c1_b_x);
  c1_array_real_T_Constructor(chartInstance, &c1_idx2Keep);
  c1_array_real_T_2D_Constructor(chartInstance, &c1_b_centers);
  c1_array_real_T_2D_Constructor(chartInstance, &c1_b_metric);
  c1_array_boolean_T_2D_Constructor(chartInstance, &c1_e_x);
  c1_array_int32_T_Constructor(chartInstance, &c1_ii);
  c1_array_real_T_Constructor(chartInstance, &c1_b_varargin_2);
  c1_array_creal_T_Constructor(chartInstance, &c1_f_x);
  c1_array_boolean_T_Constructor(chartInstance, &c1_c_centers);
  c1_array_boolean_T_Constructor(chartInstance, &c1_d_centers);
  c1_array_real_T_Constructor(chartInstance, &c1_e_centers);
  c1_array_real_T_Constructor(chartInstance, &c1_f_centers);
  if (!c1_b_y) {
  } else {
    c1_st.site = &c1_ac_emlrtRSI;
    for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
      chartInstance->c1_b_accumMatrix[c1_i2] = chartInstance->
        c1_accumMatrix[c1_i2];
    }

    c1_chcenters(chartInstance, &c1_st, chartInstance->c1_b_accumMatrix,
                 &c1_b_centers, &c1_b_metric);
    c1_st.site = &c1_ac_emlrtRSI;
    c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_centers,
      &c1_k_emlrtRTEI, c1_b_centers.size[0], c1_b_centers.size[1]);
    c1_loop_ub = c1_b_centers.size[0] * c1_b_centers.size[1] - 1;
    for (c1_i3 = 0; c1_i3 <= c1_loop_ub; c1_i3++) {
      c1_centers->vector.data[c1_i3] = c1_b_centers.vector.data[c1_i3];
    }

    c1_st.site = &c1_ac_emlrtRSI;
    c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_metric, &c1_l_emlrtRTEI,
      c1_b_metric.size[0], c1_b_metric.size[1]);
    c1_b_loop_ub = c1_b_metric.size[0] * c1_b_metric.size[1] - 1;
    for (c1_i4 = 0; c1_i4 <= c1_b_loop_ub; c1_i4++) {
      c1_metric->vector.data[c1_i4] = c1_b_metric.vector.data[c1_i4];
    }

    c1_b3 = (c1_b_centers.size[0] == 0);
    c1_b4 = (c1_b_centers.size[1] == 0);
    if (c1_b3 || c1_b4) {
    } else {
      c1_st.site = &c1_bc_emlrtRSI;
      c1_b_st.site = &c1_bc_emlrtRSI;
      c1_array_boolean_T_2D_SetSize(chartInstance, &c1_b_st, &c1_e_x,
        &c1_m_emlrtRTEI, c1_b_metric.size[0], c1_b_metric.size[1]);
      c1_c_loop_ub = c1_b_metric.size[0] * c1_b_metric.size[1] - 1;
      for (c1_i5 = 0; c1_i5 <= c1_c_loop_ub; c1_i5++) {
        c1_e_x.vector.data[c1_i5] = (c1_b_metric.vector.data[c1_i5] >=
          0.15000000000000002);
      }

      c1_b_st.site = &c1_ah_emlrtRSI;
      c1_nx = c1_e_x.size[0] * c1_e_x.size[1];
      c1_c_st.site = &c1_bh_emlrtRSI;
      c1_c_k = c1_nx;
      c1_b_nx = c1_nx;
      c1_idx = 0;
      c1_array_int32_T_SetSize(chartInstance, &c1_c_st, &c1_ii, &c1_n_emlrtRTEI,
        c1_c_k);
      c1_d_st.site = &c1_ch_emlrtRSI;
      c1_c_b = c1_b_nx;
      c1_d_b = c1_c_b;
      if (c1_d_b < 1) {
        c1_overflow = false;
      } else {
        c1_overflow = (c1_d_b > 2147483646);
      }

      if (c1_overflow) {
        c1_e_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
      }

      c1_b_ii = 1;
      c1_exitg1 = false;
      while ((!c1_exitg1) && (c1_b_ii - 1 <= c1_b_nx - 1)) {
        c1_c_ii = c1_b_ii;
        if (c1_e_x.vector.data[c1_c_ii - 1]) {
          c1_idx++;
          c1_ii.vector.data[c1_idx - 1] = c1_c_ii;
          if (c1_idx >= c1_c_k) {
            c1_exitg1 = true;
          } else {
            c1_b_ii++;
          }
        } else {
          c1_b_ii++;
        }
      }

      if (c1_idx > c1_c_k) {
        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv2, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c1_d_y = NULL;
        sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv2, 10, 0U, 1, 0U, 2, 1,
          30), false);
        sf_mex_call(&c1_c_st, &c1_t_emlrtMCI, "error", 0U, 2U, 14, c1_c_y, 14,
                    sf_mex_call(&c1_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c1_c_st, NULL, "message", 1U, 1U, 14, c1_d_y)));
      }

      if (c1_c_k == 1) {
        if (c1_idx == 0) {
          c1_array_int32_T_SetSize(chartInstance, &c1_c_st, &c1_ii,
            &c1_o_emlrtRTEI, 0);
        }
      } else {
        c1_b5 = (c1_idx < 1);
        if (c1_b5) {
          c1_i6 = 0;
        } else {
          c1_i6 = c1_idx;
        }

        c1_b_iv[0] = 1;
        c1_b_iv[1] = c1_i6;
        c1_d_st.site = &c1_dh_emlrtRSI;
        c1_indexShapeCheck(chartInstance, &c1_d_st, c1_ii.size[0], c1_b_iv);
        c1_array_int32_T_SetSize(chartInstance, &c1_c_st, &c1_ii,
          &c1_o_emlrtRTEI, c1_i6);
      }

      c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_idx2Keep,
        &c1_p_emlrtRTEI, c1_ii.size[0]);
      c1_d_loop_ub = c1_ii.size[0] - 1;
      for (c1_i7 = 0; c1_i7 <= c1_d_loop_ub; c1_i7++) {
        c1_idx2Keep.vector.data[c1_i7] = (real_T)c1_ii.vector.data[c1_i7];
      }

      c1_g_centers = c1_b_centers.size[0];
      c1_st.site = &c1_kj_emlrtRSI;
      c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_centers,
        &c1_q_emlrtRTEI, c1_idx2Keep.size[0], c1_b_centers.size[1]);
      c1_e_loop_ub = c1_b_centers.size[1] - 1;
      for (c1_i8 = 0; c1_i8 <= c1_e_loop_ub; c1_i8++) {
        c1_f_loop_ub = c1_idx2Keep.size[0] - 1;
        for (c1_i9 = 0; c1_i9 <= c1_f_loop_ub; c1_i9++) {
          c1_i10 = (int32_T)c1_idx2Keep.vector.data[c1_i9];
          if ((c1_i10 < 1) || (c1_i10 > c1_g_centers)) {
            emlrtDynamicBoundsCheckR2012b(c1_i10, 1, c1_g_centers,
              &c1_v_emlrtBCI, (emlrtConstCTX)c1_sp);
          }

          c1_centers->vector.data[c1_i9 + c1_centers->size[0] * c1_i8] =
            c1_b_centers.vector.data[(c1_i10 + c1_b_centers.size[0] * c1_i8) - 1];
        }
      }

      c1_c_metric = c1_b_metric.size[0];
      c1_st.site = &c1_jj_emlrtRSI;
      c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_metric,
        &c1_r_emlrtRTEI, c1_idx2Keep.size[0], c1_b_metric.size[1]);
      c1_g_loop_ub = c1_b_metric.size[1] - 1;
      for (c1_i11 = 0; c1_i11 <= c1_g_loop_ub; c1_i11++) {
        c1_h_loop_ub = c1_idx2Keep.size[0] - 1;
        for (c1_i12 = 0; c1_i12 <= c1_h_loop_ub; c1_i12++) {
          c1_i13 = (int32_T)c1_idx2Keep.vector.data[c1_i12];
          if ((c1_i13 < 1) || (c1_i13 > c1_c_metric)) {
            emlrtDynamicBoundsCheckR2012b(c1_i13, 1, c1_c_metric, &c1_w_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_metric->vector.data[c1_i12 + c1_metric->size[0] * c1_i11] =
            c1_b_metric.vector.data[(c1_i13 + c1_b_metric.size[0] * c1_i11) - 1];
        }
      }

      c1_b6 = (c1_centers->size[0] == 0);
      c1_b7 = (c1_centers->size[1] == 0);
      if (c1_b6 || c1_b7) {
        c1_st.site = &c1_ij_emlrtRSI;
        c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_centers,
          &c1_bb_emlrtRTEI, 0, 0);
        c1_st.site = &c1_hj_emlrtRSI;
        c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_metric,
          &c1_cb_emlrtRTEI, 0, 0);
      } else {
        c1_st.site = &c1_cc_emlrtRSI;
        c1_b_st.site = &c1_eh_emlrtRSI;
        c1_c_st.site = &c1_hh_emlrtRSI;
        c1_d_st.site = &c1_jh_emlrtRSI;
        c1_e_st.site = &c1_s_emlrtRSI;
        c1_p = true;
        c1_d = (real_T)(c1_centers->size[0] * c1_centers->size[1]);
        c1_i14 = (int32_T)c1_d - 1;
        c1_d_k = 0;
        c1_exitg1 = false;
        while ((!c1_exitg1) && (c1_d_k <= c1_i14)) {
          c1_e_k = (real_T)c1_d_k + 1.0;
          c1_g_x = c1_centers->vector.data[(int32_T)c1_e_k - 1];
          c1_b_p = !(c1_g_x <= 0.0);
          if (c1_b_p) {
            c1_d_k++;
          } else {
            c1_p = false;
            c1_exitg1 = true;
          }
        }

        if (c1_p) {
          c1_b8 = true;
        } else {
          c1_b8 = false;
        }

        if (!c1_b8) {
          c1_e_y = NULL;
          sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1,
            37), false);
          c1_f_y = NULL;
          sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv1, 10, 0U, 1, 0U, 2, 1,
            48), false);
          c1_g_y = NULL;
          sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1, 0U, 2,
            1, 24), false);
          sf_mex_call(&c1_e_st, &c1_u_emlrtMCI, "error", 0U, 2U, 14, c1_e_y, 14,
                      sf_mex_call(&c1_e_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c1_e_st, NULL, "message", 1U, 2U, 14, c1_f_y, 14,
                        c1_g_y)));
        }

        c1_e_st.site = &c1_s_emlrtRSI;
        c1_b9 = (c1_centers->size[0] == 0);
        c1_b10 = (c1_centers->size[1] == 0);
        if ((!!c1_b9) || (!!c1_b10)) {
          c1_h_y = NULL;
          sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_b_cv2, 10, 0U, 1, 0U, 2,
            1, 37), false);
          c1_i_y = NULL;
          sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_b_cv3, 10, 0U, 1, 0U, 2,
            1, 48), false);
          c1_k_y = NULL;
          sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_b_cv5, 10, 0U, 1, 0U, 2,
            1, 24), false);
          sf_mex_call(&c1_e_st, &c1_v_emlrtMCI, "error", 0U, 2U, 14, c1_h_y, 14,
                      sf_mex_call(&c1_e_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c1_e_st, NULL, "message", 1U, 2U, 14, c1_i_y, 14,
                        c1_k_y)));
        }

        c1_e_st.site = &c1_s_emlrtRSI;
        if (!((real_T)c1_centers->size[1] == 2.0)) {
          c1_j_y = NULL;
          sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_b_cv4, 10, 0U, 1, 0U, 2,
            1, 37), false);
          c1_l_y = NULL;
          sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_b_cv6, 10, 0U, 1, 0U, 2,
            1, 48), false);
          c1_m_y = NULL;
          sf_mex_assign(&c1_m_y, sf_mex_create("y", c1_b_cv7, 10, 0U, 1, 0U, 2,
            1, 24), false);
          c1_b_u = 2.0;
          c1_n_y = NULL;
          sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0, 0U, 0),
                        false);
          sf_mex_call(&c1_e_st, &c1_w_emlrtMCI, "error", 0U, 2U, 14, c1_j_y, 14,
                      sf_mex_call(&c1_e_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c1_e_st, NULL, "message", 1U, 3U, 14, c1_l_y, 14,
                        c1_m_y, 14, c1_n_y)));
        }

        c1_c_st.site = &c1_ih_emlrtRSI;
        c1_i15 = c1_centers->size[1];
        c1_i16 = 1;
        if ((c1_i16 < 1) || (c1_i16 > c1_i15)) {
          emlrtDynamicBoundsCheckR2012b(c1_i16, 1, c1_i15, &c1_t_emlrtBCI,
            &c1_c_st);
        }

        c1_array_boolean_T_SetSize(chartInstance, &c1_c_st, &c1_c_centers,
          &c1_s_emlrtRTEI, c1_centers->size[0]);
        c1_i_loop_ub = c1_centers->size[0] - 1;
        for (c1_i17 = 0; c1_i17 <= c1_i_loop_ub; c1_i17++) {
          c1_c_centers.vector.data[c1_i17] = (c1_centers->vector.data[c1_i17] <=
            160.0);
        }

        c1_d_st.site = &c1_kh_emlrtRSI;
        if (c1_all(chartInstance, &c1_d_st, &c1_c_centers)) {
          c1_i18 = c1_centers->size[1];
          c1_i19 = 2;
          if ((c1_i19 < 1) || (c1_i19 > c1_i18)) {
            emlrtDynamicBoundsCheckR2012b(c1_i19, 1, c1_i18, &c1_u_emlrtBCI,
              &c1_c_st);
          }

          c1_array_boolean_T_SetSize(chartInstance, &c1_c_st, &c1_d_centers,
            &c1_t_emlrtRTEI, c1_centers->size[0]);
          c1_j_loop_ub = c1_centers->size[0] - 1;
          for (c1_i22 = 0; c1_i22 <= c1_j_loop_ub; c1_i22++) {
            c1_d_centers.vector.data[c1_i22] = (c1_centers->vector.data[c1_i22 +
              c1_centers->size[0]] <= 120.0);
          }

          c1_d_st.site = &c1_lh_emlrtRSI;
          if (c1_all(chartInstance, &c1_d_st, &c1_d_centers)) {
            c1_b11 = true;
          } else {
            c1_b11 = false;
          }
        } else {
          c1_b11 = false;
        }

        if (!c1_b11) {
          c1_o_y = NULL;
          sf_mex_assign(&c1_o_y, sf_mex_create("y", c1_b_cv8, 10, 0U, 1, 0U, 2,
            1, 38), false);
          c1_p_y = NULL;
          sf_mex_assign(&c1_p_y, sf_mex_create("y", c1_b_cv8, 10, 0U, 1, 0U, 2,
            1, 38), false);
          sf_mex_call(&c1_c_st, &c1_x_emlrtMCI, "error", 0U, 2U, 14, c1_o_y, 14,
                      sf_mex_call(&c1_c_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c1_c_st, NULL, "message", 1U, 1U, 14, c1_p_y)));
        }

        c1_i20 = c1_centers->size[1];
        c1_i21 = 2;
        if ((c1_i21 < 1) || (c1_i21 > c1_i20)) {
          emlrtDynamicBoundsCheckR2012b(c1_i21, 1, c1_i20, &c1_r_emlrtBCI,
            &c1_st);
        }

        c1_i23 = c1_centers->size[1];
        c1_i24 = 1;
        if ((c1_i24 < 1) || (c1_i24 > c1_i23)) {
          emlrtDynamicBoundsCheckR2012b(c1_i24, 1, c1_i23, &c1_s_emlrtBCI,
            &c1_st);
        }

        c1_b_st.site = &c1_fh_emlrtRSI;
        c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_e_centers,
          &c1_u_emlrtRTEI, c1_centers->size[0]);
        c1_k_loop_ub = c1_centers->size[0] - 1;
        for (c1_i25 = 0; c1_i25 <= c1_k_loop_ub; c1_i25++) {
          c1_e_centers.vector.data[c1_i25] = c1_centers->vector.data[c1_i25 +
            c1_centers->size[0]];
        }

        c1_c_st.site = &c1_fh_emlrtRSI;
        c1_round(chartInstance, &c1_c_st, &c1_e_centers, &c1_idx2Keep);
        c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_f_centers,
          &c1_v_emlrtRTEI, c1_centers->size[0]);
        c1_l_loop_ub = c1_centers->size[0] - 1;
        for (c1_i26 = 0; c1_i26 <= c1_l_loop_ub; c1_i26++) {
          c1_f_centers.vector.data[c1_i26] = c1_centers->vector.data[c1_i26];
        }

        c1_c_st.site = &c1_fh_emlrtRSI;
        c1_round(chartInstance, &c1_c_st, &c1_f_centers, &c1_b_varargin_2);
        c1_c_st.site = &c1_uc_emlrtRSI;
        c1_sub2ind(chartInstance, &c1_c_st, &c1_idx2Keep, &c1_b_varargin_2,
                   &c1_ii);
        c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_idx2Keep,
          &c1_w_emlrtRTEI, c1_ii.size[0]);
        c1_m_loop_ub = c1_ii.size[0] - 1;
        for (c1_i27 = 0; c1_i27 <= c1_m_loop_ub; c1_i27++) {
          c1_idx2Keep.vector.data[c1_i27] = (real_T)c1_ii.vector.data[c1_i27];
        }

        c1_b_st.site = &c1_fh_emlrtRSI;
        c1_array_creal_T_SetSize(chartInstance, &c1_b_st, &c1_f_x,
          &c1_x_emlrtRTEI, c1_idx2Keep.size[0]);
        c1_n_loop_ub = c1_idx2Keep.size[0] - 1;
        for (c1_i28 = 0; c1_i28 <= c1_n_loop_ub; c1_i28++) {
          c1_i29 = (int32_T)c1_idx2Keep.vector.data[c1_i28];
          if ((c1_i29 < 1) || (c1_i29 > 19200)) {
            emlrtDynamicBoundsCheckR2012b(c1_i29, 1, 19200, &c1_x_emlrtBCI,
              &c1_b_st);
          }

          c1_f_x.vector.data[c1_i28].re = chartInstance->c1_accumMatrix[c1_i29 -
            1].re;
          c1_i30 = (int32_T)c1_idx2Keep.vector.data[c1_i28];
          if ((c1_i30 < 1) || (c1_i30 > 19200)) {
            emlrtDynamicBoundsCheckR2012b(c1_i30, 1, 19200, &c1_x_emlrtBCI,
              &c1_b_st);
          }

          c1_f_x.vector.data[c1_i28].im = chartInstance->c1_accumMatrix[c1_i30 -
            1].im;
        }

        c1_c_st.site = &c1_oh_emlrtRSI;
        c1_c_nx = c1_f_x.size[0];
        c1_c_dv[0] = (real_T)c1_f_x.size[0];
        c1_array_real_T_SetSize(chartInstance, &c1_c_st, &c1_idx2Keep,
          &c1_y_emlrtRTEI, (int32_T)c1_c_dv[0]);
        c1_d_st.site = &c1_ph_emlrtRSI;
        c1_e_b = c1_c_nx;
        c1_f_b = c1_e_b;
        if (c1_f_b < 1) {
          c1_b_overflow = false;
        } else {
          c1_b_overflow = (c1_f_b > 2147483646);
        }

        if (c1_b_overflow) {
          c1_e_st.site = &c1_yc_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
        }

        for (c1_f_k = 0; c1_f_k < c1_c_nx; c1_f_k++) {
          c1_g_k = c1_f_k;
          c1_d_x = c1_f_x.vector.data[c1_g_k];
          c1_q_y = c1_d_x.im;
          c1_h_x = c1_d_x.re;
          c1_r_y = muDoubleScalarAtan2(c1_q_y, c1_h_x);
          c1_idx2Keep.vector.data[c1_g_k] = c1_r_y;
        }

        c1_o_loop_ub = c1_idx2Keep.size[0] - 1;
        for (c1_i31 = 0; c1_i31 <= c1_o_loop_ub; c1_i31++) {
          c1_idx2Keep.vector.data[c1_i31] = (c1_idx2Keep.vector.data[c1_i31] +
            3.1415926535897931) / 6.2831853071795862;
        }

        c1_p_loop_ub = c1_idx2Keep.size[0] - 1;
        for (c1_i32 = 0; c1_i32 <= c1_p_loop_ub; c1_i32++) {
          c1_idx2Keep.vector.data[c1_i32] *= 0.98082925301172619;
        }

        c1_b_st.site = &c1_gh_emlrtRSI;
        c1_q_loop_ub = c1_idx2Keep.size[0] - 1;
        for (c1_i33 = 0; c1_i33 <= c1_q_loop_ub; c1_i33++) {
          c1_idx2Keep.vector.data[c1_i33] += 2.70805020110221;
        }

        c1_c_st.site = &c1_qh_emlrtRSI;
        c1_d_nx = c1_idx2Keep.size[0];
        c1_d_st.site = &c1_ag_emlrtRSI;
        c1_g_b = c1_d_nx;
        c1_h_b = c1_g_b;
        if (c1_h_b < 1) {
          c1_c_overflow = false;
        } else {
          c1_c_overflow = (c1_h_b > 2147483646);
        }

        if (c1_c_overflow) {
          c1_e_st.site = &c1_yc_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
        }

        for (c1_h_k = 0; c1_h_k < c1_d_nx; c1_h_k++) {
          c1_i_k = c1_h_k;
          c1_i_x = c1_idx2Keep.vector.data[c1_i_k];
          c1_j_x = c1_i_x;
          c1_j_x = muDoubleScalarExp(c1_j_x);
          c1_idx2Keep.vector.data[c1_i_k] = c1_j_x;
        }

        c1_st.site = &c1_cc_emlrtRSI;
        c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_r_estimated,
          &c1_ab_emlrtRTEI, c1_idx2Keep.size[0], 1);
        c1_r_loop_ub = c1_idx2Keep.size[0] - 1;
        for (c1_i34 = 0; c1_i34 <= c1_r_loop_ub; c1_i34++) {
          c1_r_estimated->vector.data[c1_i34] = c1_idx2Keep.vector.data[c1_i34];
        }
      }
    }
  }

  c1_array_real_T_Destructor(chartInstance, &c1_f_centers);
  c1_array_real_T_Destructor(chartInstance, &c1_e_centers);
  c1_array_boolean_T_Destructor(chartInstance, &c1_d_centers);
  c1_array_boolean_T_Destructor(chartInstance, &c1_c_centers);
  c1_array_creal_T_Destructor(chartInstance, &c1_f_x);
  c1_array_real_T_Destructor(chartInstance, &c1_b_varargin_2);
  c1_array_int32_T_Destructor(chartInstance, &c1_ii);
  c1_array_boolean_T_2D_Destructor(chartInstance, &c1_e_x);
  c1_array_real_T_2D_Destructor(chartInstance, &c1_b_metric);
  c1_array_real_T_2D_Destructor(chartInstance, &c1_b_centers);
  c1_array_real_T_Destructor(chartInstance, &c1_idx2Keep);
}

static void c1_chaccum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200], creal_T
  c1_c_accumMatrix[19200], real32_T c1_b_gradientImg[19200])
{
  static real_T c1_b_dv1[51] = { 94.247779607693786, 97.389372261283583,
    100.53096491487338, 103.67255756846318, 106.81415022205297,
    109.95574287564276, 113.09733552923255, 116.23892818282235,
    119.38052083641213, 122.52211349000193, 125.66370614359172,
    128.80529879718151, 131.94689145077132, 135.0884841043611,
    138.23007675795088, 141.37166941154069, 144.51326206513048,
    147.65485471872029, 150.79644737231007, 153.93804002589985,
    157.07963267948966, 160.22122533307945, 163.36281798666926,
    166.50441064025904, 169.64600329384882, 172.78759594743863,
    175.92918860102841, 179.0707812546182, 182.212373908208, 185.35396656179779,
    188.49555921538757, 191.63715186897738, 194.77874452256717,
    197.92033717615698, 201.06192982974676, 204.20352248333654,
    207.34511513692635, 210.48670779051614, 213.62830044410595,
    216.76989309769573, 219.91148575128551, 223.05307840487532,
    226.1946710584651, 229.33626371205489, 232.4778563656447, 235.61944901923448,
    238.76104167282426, 241.90263432641407, 245.04422698000386,
    248.18581963359367, 251.32741228718345 };

  static real_T c1_c_dv[51] = { -3.1415926535897931, -2.9315412788435564,
    -2.728159340387176, -2.5310363110537715, -2.3397984387514361,
    -2.1541044810986776, -1.9736420410725424, -1.7981244048255176,
    -1.6272878012878906, -1.4608890177945735, -1.29870331763481,
    -1.1405226147782175, -0.98615386858142706, -0.83541766740840728,
    -0.68814697509878542, -0.54418601832017632, -0.40338929622074904,
    -0.26562069659688525, -0.13075270511755654, 0.0013343039096884723,
    0.13075270511755654, 0.25760819651818112, 0.38200031816041236,
    0.50402292138177929, 0.6237645941970773, 0.7413090476535813,
    0.85673546737355633, 0.97011883398172927, 1.081530215665059,
    1.1910370357236069, 1.2987033176348097, 1.4045899098616212,
    1.5087546923810473, 1.6112527666881897, 1.7121366308374268,
    1.8114563409127786, 1.9092596601708323, 2.0055921969685695,
    2.1004975324731667, 2.1940173390488713, 2.2861914901259226,
    2.3770581622765556, 2.4666539301520602, 2.5550138548718566,
    2.6421715663990852, 2.728159340387176, 2.8130081699367118,
    2.8967478326619469, 2.9794069534300291, 3.0610130631038119,
    3.1415926535897931 };

  c1_coder_array_boolean_T_2D c1_inside;
  c1_coder_array_creal_T c1_wkeep;
  c1_coder_array_creal_T_2D c1_w;
  c1_coder_array_int32_T c1_ii;
  c1_coder_array_int32_T c1_jj;
  c1_coder_array_int32_T c1_r;
  c1_coder_array_int32_T c1_xckeep;
  c1_coder_array_int32_T c1_yckeep;
  c1_coder_array_real32_T_2D c1_xc;
  c1_coder_array_real32_T_2D c1_yc;
  c1_coder_array_real_T c1_Ex;
  c1_coder_array_real_T c1_Ex_chunk;
  c1_coder_array_real_T c1_Ey;
  c1_coder_array_real_T c1_Ey_chunk;
  c1_coder_array_real_T c1_b_varargin_2;
  c1_coder_array_real_T c1_idxE;
  c1_coder_array_real_T c1_idxE_chunk;
  c1_coder_array_real_T c1_ndx;
  c1_coder_array_real_T_2D c1_r1;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_st;
  creal_T c1_Opca[51];
  creal_T c1_b_dc;
  creal_T c1_h_x;
  real_T c1_a1;
  real_T c1_ab_x;
  real_T c1_ai;
  real_T c1_apnd;
  real_T c1_ar;
  real_T c1_b1;
  real_T c1_b_d;
  real_T c1_b_idx1;
  real_T c1_b_idx2;
  real_T c1_b_k;
  real_T c1_b_r;
  real_T c1_b_s;
  real_T c1_bb_x;
  real_T c1_bi;
  real_T c1_bim;
  real_T c1_br;
  real_T c1_brm;
  real_T c1_c;
  real_T c1_c_d;
  real_T c1_c_i;
  real_T c1_c_idx;
  real_T c1_c_varargin_2;
  real_T c1_cdiff;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_d_b;
  real_T c1_db_x;
  real_T c1_dim1;
  real_T c1_e_a;
  real_T c1_e_varargin_1;
  real_T c1_e_y;
  real_T c1_eb_x;
  real_T c1_edgeThresh;
  real_T c1_f_a;
  real_T c1_f_y;
  real_T c1_fb_x;
  real_T c1_g_a;
  real_T c1_g_b;
  real_T c1_g_y;
  real_T c1_h_a;
  real_T c1_h_b;
  real_T c1_h_y;
  real_T c1_i_a;
  real_T c1_i_x;
  real_T c1_i_y;
  real_T c1_j_a;
  real_T c1_j_x;
  real_T c1_j_y;
  real_T c1_k_a;
  real_T c1_k_b;
  real_T c1_k_x;
  real_T c1_k_y;
  real_T c1_kd;
  real_T c1_l_b;
  real_T c1_l_x;
  real_T c1_l_y;
  real_T c1_lenE;
  real_T c1_m_a;
  real_T c1_m_b;
  real_T c1_m_x;
  real_T c1_m_y;
  real_T c1_minval;
  real_T c1_n_x;
  real_T c1_ndbl;
  real_T c1_ni;
  real_T c1_nr;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_sgnbi;
  real_T c1_sgnbr;
  real_T c1_sizeChunk;
  real_T c1_t_x;
  real_T c1_thresh;
  real_T c1_u_x;
  real_T c1_v_x;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_y_x;
  int32_T c1_rows_to_keep_size[1];
  int32_T c1_b_i;
  int32_T c1_b_idx;
  int32_T c1_b_loop_ub;
  int32_T c1_c_idx1;
  int32_T c1_c_idx2;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_d_idx;
  int32_T c1_d_k;
  int32_T c1_d_loop_ub;
  int32_T c1_e_idx;
  int32_T c1_e_k;
  int32_T c1_e_loop_ub;
  int32_T c1_f_k;
  int32_T c1_f_loop_ub;
  int32_T c1_first;
  int32_T c1_g_k;
  int32_T c1_g_loop_ub;
  int32_T c1_h_k;
  int32_T c1_h_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i100;
  int32_T c1_i101;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i5;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i6;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i7;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i8;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i9;
  int32_T c1_i90;
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  int32_T c1_i97;
  int32_T c1_i98;
  int32_T c1_i99;
  int32_T c1_i_k;
  int32_T c1_idx;
  int32_T c1_idx1;
  int32_T c1_idx2;
  int32_T c1_idxEdge;
  int32_T c1_idxkeep;
  int32_T c1_j_k;
  int32_T c1_k;
  int32_T c1_l_a;
  int32_T c1_loop_ub;
  int32_T c1_n;
  int32_T c1_n_b;
  int32_T c1_nm1;
  int32_T c1_nm1d2;
  int32_T c1_o_b;
  int32_T c1_q_b;
  int32_T c1_r_b;
  int32_T c1_r_y;
  int32_T c1_s_b;
  int32_T c1_szxc;
  real32_T c1_Gmax;
  real32_T c1_b_b;
  real32_T c1_b_y;
  real32_T c1_b_z;
  real32_T c1_c_a;
  real32_T c1_c_x;
  real32_T c1_c_y;
  real32_T c1_c_z;
  real32_T c1_cb_x;
  real32_T c1_d_a;
  real32_T c1_d_x;
  real32_T c1_d_y;
  real32_T c1_e_x;
  real32_T c1_ex;
  real32_T c1_f_x;
  real32_T c1_g_x;
  real32_T c1_gb_x;
  real32_T c1_hb_x;
  real32_T c1_ib_x;
  real32_T c1_jb_x;
  real32_T c1_kb_x;
  real32_T c1_lb_x;
  real32_T c1_mb_x;
  real32_T c1_n_y;
  real32_T c1_o_y;
  real32_T c1_p_b;
  real32_T c1_p_y;
  real32_T c1_q_y;
  real32_T c1_s_y;
  real32_T c1_t;
  real32_T c1_t_b;
  real32_T c1_t_y;
  real32_T c1_u_y;
  real32_T c1_v_y;
  real32_T c1_x1;
  real32_T c1_x2;
  real32_T c1_z;
  boolean_T c1_b_x[19200];
  boolean_T c1_rows_to_keep_data[19200];
  boolean_T c1_x_data[19200];
  boolean_T c1_b;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  boolean_T c1_b_b1;
  boolean_T c1_b_overflow;
  boolean_T c1_b_p;
  boolean_T c1_c_b;
  boolean_T c1_d_varargin_1;
  boolean_T c1_e_b;
  boolean_T c1_exitg1;
  boolean_T c1_f_b;
  boolean_T c1_flat;
  boolean_T c1_guard1;
  boolean_T c1_guard2;
  boolean_T c1_i_b;
  boolean_T c1_j_b;
  boolean_T c1_overflow;
  boolean_T c1_p;
  boolean_T c1_u_b;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_d_varargin_1 = c1_c_varargin_1[0];
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_b_x[c1_i] = ((int32_T)c1_c_varargin_1[c1_i] == (int32_T)c1_d_varargin_1);
  }

  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    c1_x_data[c1_i1] = c1_b_x[c1_i1];
  }

  c1_flat = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 19200)) {
    c1_b_k = (real_T)c1_k + 1.0;
    if (!c1_x_data[(int32_T)c1_b_k - 1]) {
      c1_flat = false;
      c1_exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (c1_flat) {
    for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
      c1_c_accumMatrix[c1_i2].re = 0.0;
      c1_c_accumMatrix[c1_i2].im = 0.0;
    }

    for (c1_i4 = 0; c1_i4 < 19200; c1_i4++) {
      c1_b_gradientImg[c1_i4] = 0.0F;
    }
  } else {
    c1_st.site = &c1_dc_emlrtRSI;
    for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
      chartInstance->c1_s[c1_i3] = (real32_T)c1_c_varargin_1[c1_i3];
    }

    c1_b_st.site = &c1_vb_emlrtRSI;
    c1_b_imfilter(chartInstance, &c1_b_st, chartInstance->c1_s,
                  chartInstance->c1_A);
    c1_st.site = &c1_ec_emlrtRSI;
    c1_b_st.site = &c1_wb_emlrtRSI;
    c1_c_imfilter(chartInstance, &c1_b_st, chartInstance->c1_A,
                  chartInstance->c1_Gx);
    c1_b_st.site = &c1_xb_emlrtRSI;
    c1_d_imfilter(chartInstance, &c1_b_st, chartInstance->c1_A,
                  chartInstance->c1_Gy);
    for (c1_c_k = 0; c1_c_k < 19200; c1_c_k++) {
      c1_d_k = c1_c_k;
      c1_c_x = chartInstance->c1_Gx[c1_d_k];
      c1_b_y = chartInstance->c1_Gy[c1_d_k];
      c1_x1 = c1_c_x;
      c1_x2 = c1_b_y;
      c1_c_a = c1_x1;
      c1_b_b = c1_x2;
      c1_z = muSingleScalarHypot(c1_c_a, c1_b_b);
      c1_b_gradientImg[c1_d_k] = c1_z;
    }

    c1_st.site = &c1_fc_emlrtRSI;
    for (c1_i5 = 0; c1_i5 < 19200; c1_i5++) {
      chartInstance->c1_s[c1_i5] = c1_b_gradientImg[c1_i5];
    }

    c1_d_x = chartInstance->c1_s[0];
    c1_e_x = c1_d_x;
    c1_b = muSingleScalarIsNaN(c1_e_x);
    c1_p = !c1_b;
    if (c1_p) {
      c1_idx = 1;
    } else {
      c1_idx = 0;
      c1_e_k = 2;
      c1_exitg1 = false;
      while ((!c1_exitg1) && (c1_e_k < 19201)) {
        c1_f_x = chartInstance->c1_s[c1_e_k - 1];
        c1_g_x = c1_f_x;
        c1_c_b = muSingleScalarIsNaN(c1_g_x);
        c1_b_p = !c1_c_b;
        if (c1_b_p) {
          c1_idx = c1_e_k;
          c1_exitg1 = true;
        } else {
          c1_e_k++;
        }
      }
    }

    if (c1_idx == 0) {
      c1_Gmax = chartInstance->c1_s[0];
    } else {
      c1_first = c1_idx - 1;
      c1_ex = chartInstance->c1_s[c1_first];
      c1_i6 = c1_first;
      for (c1_f_k = c1_i6 + 2; c1_f_k < 19201; c1_f_k++) {
        if (c1_ex < chartInstance->c1_s[c1_f_k - 1]) {
          c1_ex = chartInstance->c1_s[c1_f_k - 1];
        }
      }

      c1_Gmax = c1_ex;
    }

    c1_c_y = c1_Gmax;
    c1_d_y = c1_c_y;
    for (c1_i7 = 0; c1_i7 < 19200; c1_i7++) {
      chartInstance->c1_s[c1_i7] = c1_b_gradientImg[c1_i7] / c1_d_y;
    }

    c1_b_st.site = &c1_jc_emlrtRSI;
    c1_edgeThresh = c1_graythresh(chartInstance, &c1_b_st, chartInstance->c1_s);
    c1_d_a = c1_Gmax;
    c1_d_b = c1_edgeThresh;
    c1_t = c1_d_a * (real32_T)c1_d_b;
    c1_b_st.site = &c1_kc_emlrtRSI;
    for (c1_i8 = 0; c1_i8 < 19200; c1_i8++) {
      c1_b_x[c1_i8] = (c1_b_gradientImg[c1_i8] > c1_t);
    }

    c1_array_int32_T_Constructor(chartInstance, &c1_ii);
    c1_array_int32_T_Constructor(chartInstance, &c1_jj);
    c1_c_st.site = &c1_oc_emlrtRSI;
    c1_eml_find(chartInstance, &c1_c_st, c1_b_x, &c1_ii, &c1_jj);
    c1_array_real_T_Constructor(chartInstance, &c1_Ey);
    c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_Ey, &c1_db_emlrtRTEI,
      c1_ii.size[0]);
    c1_loop_ub = c1_ii.size[0] - 1;
    for (c1_i9 = 0; c1_i9 <= c1_loop_ub; c1_i9++) {
      c1_Ey.vector.data[c1_i9] = (real_T)c1_ii.vector.data[c1_i9];
    }

    c1_array_int32_T_Destructor(chartInstance, &c1_ii);
    c1_array_real_T_Constructor(chartInstance, &c1_Ex);
    c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_Ex, &c1_eb_emlrtRTEI,
      c1_jj.size[0]);
    c1_b_loop_ub = c1_jj.size[0] - 1;
    for (c1_i10 = 0; c1_i10 <= c1_b_loop_ub; c1_i10++) {
      c1_Ex.vector.data[c1_i10] = (real_T)c1_jj.vector.data[c1_i10];
    }

    c1_array_int32_T_Destructor(chartInstance, &c1_jj);
    c1_array_real_T_Constructor(chartInstance, &c1_ndx);
    c1_st.site = &c1_gc_emlrtRSI;
    c1_b_st.site = &c1_gc_emlrtRSI;
    c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_ndx, &c1_fb_emlrtRTEI,
      c1_Ey.size[0]);
    c1_c_loop_ub = c1_Ey.size[0] - 1;
    for (c1_i11 = 0; c1_i11 <= c1_c_loop_ub; c1_i11++) {
      c1_ndx.vector.data[c1_i11] = c1_Ey.vector.data[c1_i11];
    }

    c1_array_real_T_Constructor(chartInstance, &c1_b_varargin_2);
    c1_b_st.site = &c1_gc_emlrtRSI;
    c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_b_varargin_2,
      &c1_gb_emlrtRTEI, c1_Ex.size[0]);
    c1_d_loop_ub = c1_Ex.size[0] - 1;
    for (c1_i12 = 0; c1_i12 <= c1_d_loop_ub; c1_i12++) {
      c1_b_varargin_2.vector.data[c1_i12] = c1_Ex.vector.data[c1_i12];
    }

    c1_array_int32_T_Constructor(chartInstance, &c1_r);
    c1_b_st.site = &c1_uc_emlrtRSI;
    c1_sub2ind(chartInstance, &c1_b_st, &c1_ndx, &c1_b_varargin_2, &c1_r);
    c1_array_real_T_Destructor(chartInstance, &c1_b_varargin_2);
    c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_ndx, &c1_w_emlrtRTEI,
      c1_r.size[0]);
    c1_e_loop_ub = c1_r.size[0] - 1;
    for (c1_i13 = 0; c1_i13 <= c1_e_loop_ub; c1_i13++) {
      c1_ndx.vector.data[c1_i13] = (real_T)c1_r.vector.data[c1_i13];
    }

    c1_array_int32_T_Destructor(chartInstance, &c1_r);
    c1_array_real_T_Constructor(chartInstance, &c1_idxE);
    c1_st.site = &c1_gc_emlrtRSI;
    c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_idxE, &c1_hb_emlrtRTEI,
      c1_ndx.size[0]);
    c1_f_loop_ub = c1_ndx.size[0] - 1;
    for (c1_i14 = 0; c1_i14 <= c1_f_loop_ub; c1_i14++) {
      c1_idxE.vector.data[c1_i14] = c1_ndx.vector.data[c1_i14];
    }

    c1_array_real_T_Destructor(chartInstance, &c1_ndx);
    for (c1_i15 = 0; c1_i15 < 51; c1_i15++) {
      c1_Opca[c1_i15].re = -0.0;
      c1_Opca[c1_i15].im = c1_c_dv[c1_i15];
    }

    for (c1_g_k = 0; c1_g_k < 51; c1_g_k++) {
      c1_h_k = c1_g_k;
      c1_h_x = c1_Opca[c1_h_k];
      if (c1_h_x.re == 0.0) {
        c1_d = c1_h_x.im;
        c1_d2 = c1_h_x.im;
        c1_h_x.re = muDoubleScalarCos(c1_d);
        c1_h_x.im = muDoubleScalarSin(c1_d2);
      } else if (c1_h_x.im == 0.0) {
        c1_d1 = c1_h_x.re;
        c1_h_x.re = muDoubleScalarExp(c1_d1);
        c1_h_x.im = 0.0;
      } else {
        c1_i_x = c1_h_x.im;
        c1_e_b = muDoubleScalarIsInf(c1_i_x);
        c1_guard1 = false;
        if (c1_e_b) {
          c1_j_x = c1_h_x.re;
          c1_f_b = muDoubleScalarIsInf(c1_j_x);
          if (c1_f_b && (c1_h_x.re < 0.0)) {
            c1_h_x = c1_dc;
          } else {
            c1_guard1 = true;
          }
        } else {
          c1_guard1 = true;
        }

        if (c1_guard1) {
          c1_b_r = muDoubleScalarExp(c1_h_x.re / 2.0);
          c1_d3 = c1_h_x.im;
          c1_d4 = c1_h_x.im;
          c1_h_x.re = c1_b_r * (c1_b_r * muDoubleScalarCos(c1_d3));
          c1_h_x.im = c1_b_r * (c1_b_r * muDoubleScalarSin(c1_d4));
        }
      }

      c1_Opca[c1_h_k] = c1_h_x;
    }

    for (c1_i16 = 0; c1_i16 < 51; c1_i16++) {
      c1_ar = c1_Opca[c1_i16].re;
      c1_ai = c1_Opca[c1_i16].im;
      c1_br = c1_b_dv1[c1_i16];
      c1_bi = 0.0;
      if (c1_bi == 0.0) {
        if (c1_ai == 0.0) {
          c1_b_dc.re = c1_ar / c1_br;
          c1_b_dc.im = 0.0;
        } else if (c1_ar == 0.0) {
          c1_b_dc.re = 0.0;
          c1_b_dc.im = c1_ai / c1_br;
        } else {
          c1_b_dc.re = c1_ar / c1_br;
          c1_b_dc.im = c1_ai / c1_br;
        }
      } else if (c1_br == 0.0) {
        if (c1_ar == 0.0) {
          c1_b_dc.re = c1_ai / c1_bi;
          c1_b_dc.im = 0.0;
        } else if (c1_ai == 0.0) {
          c1_b_dc.re = 0.0;
          c1_b_dc.im = -(c1_ar / c1_bi);
        } else {
          c1_b_dc.re = c1_ai / c1_bi;
          c1_b_dc.im = -(c1_ar / c1_bi);
        }
      } else {
        c1_brm = muDoubleScalarAbs(c1_br);
        c1_bim = muDoubleScalarAbs(c1_bi);
        if (c1_brm > c1_bim) {
          c1_b_s = c1_bi / c1_br;
          c1_b_d = c1_br + c1_b_s * c1_bi;
          c1_nr = c1_ar + c1_b_s * c1_ai;
          c1_ni = c1_ai - c1_b_s * c1_ar;
          c1_b_dc.re = c1_nr / c1_b_d;
          c1_b_dc.im = c1_ni / c1_b_d;
        } else if (c1_bim == c1_brm) {
          if (c1_br > 0.0) {
            c1_sgnbr = 0.5;
          } else {
            c1_sgnbr = -0.5;
          }

          if (c1_bi > 0.0) {
            c1_sgnbi = 0.5;
          } else {
            c1_sgnbi = -0.5;
          }

          c1_nr = c1_ar * c1_sgnbr + c1_ai * c1_sgnbi;
          c1_ni = c1_ai * c1_sgnbr - c1_ar * c1_sgnbi;
          c1_b_dc.re = c1_nr / c1_brm;
          c1_b_dc.im = c1_ni / c1_brm;
        } else {
          c1_b_s = c1_br / c1_bi;
          c1_b_d = c1_bi + c1_b_s * c1_br;
          c1_nr = c1_b_s * c1_ar + c1_ai;
          c1_ni = c1_b_s * c1_ai - c1_ar;
          c1_b_dc.re = c1_nr / c1_b_d;
          c1_b_dc.im = c1_ni / c1_b_d;
        }
      }

      c1_Opca[c1_i16] = c1_b_dc;
    }

    c1_lenE = (real_T)c1_Ex.size[0];
    for (c1_i17 = 0; c1_i17 < 19200; c1_i17++) {
      c1_c_accumMatrix[c1_i17].re = 0.0;
      c1_c_accumMatrix[c1_i17].im = 0.0;
    }

    c1_i18 = (int32_T)((c1_lenE + 19606.0) / 19607.0);
    emlrtForLoopVectorCheckR2021a(1.0, 19607.0, c1_lenE, mxDOUBLE_CLASS, c1_i18,
      &c1_gi_emlrtRTEI, (emlrtConstCTX)c1_sp);
    c1_array_real_T_Constructor(chartInstance, &c1_Ex_chunk);
    c1_array_real_T_Constructor(chartInstance, &c1_Ey_chunk);
    c1_array_real_T_Constructor(chartInstance, &c1_idxE_chunk);
    c1_array_real32_T_2D_Constructor(chartInstance, &c1_xc);
    c1_array_real32_T_2D_Constructor(chartInstance, &c1_yc);
    c1_array_creal_T_2D_Constructor(chartInstance, &c1_w);
    c1_array_boolean_T_2D_Constructor(chartInstance, &c1_inside);
    c1_array_int32_T_Constructor(chartInstance, &c1_xckeep);
    c1_array_int32_T_Constructor(chartInstance, &c1_yckeep);
    c1_array_creal_T_Constructor(chartInstance, &c1_wkeep);
    c1_array_real_T_2D_Constructor(chartInstance, &c1_r1);
    for (c1_b_i = 0; c1_b_i < c1_i18; c1_b_i++) {
      c1_c_i = (real_T)c1_b_i * 19607.0 + 1.0;
      c1_e_varargin_1 = (c1_c_i + 19607.0) - 1.0;
      c1_c_varargin_2 = c1_lenE;
      c1_k_x = c1_e_varargin_1;
      c1_e_y = c1_c_varargin_2;
      c1_l_x = c1_k_x;
      c1_f_y = c1_e_y;
      c1_m_x = c1_l_x;
      c1_g_y = c1_f_y;
      c1_e_a = c1_m_x;
      c1_g_b = c1_g_y;
      c1_n_x = c1_e_a;
      c1_h_y = c1_g_b;
      c1_o_x = c1_n_x;
      c1_i_y = c1_h_y;
      c1_minval = muDoubleScalarMin(c1_o_x, c1_i_y);
      c1_st.site = &c1_hc_emlrtRSI;
      c1_f_a = c1_c_i;
      c1_c_d = c1_minval;
      c1_b_st.site = &c1_vc_emlrtRSI;
      c1_g_a = c1_f_a;
      c1_h_b = c1_c_d;
      if (c1_h_b < c1_g_a) {
        c1_array_real_T_2D_SetSize(chartInstance, &c1_b_st, &c1_r1,
          &c1_jb_emlrtRTEI, 1, 0);
      } else {
        c1_p_x = c1_g_a;
        c1_i_b = muDoubleScalarIsInf(c1_p_x);
        c1_guard1 = false;
        c1_guard2 = false;
        if (c1_i_b) {
          c1_guard2 = true;
        } else {
          c1_q_x = c1_h_b;
          c1_j_b = muDoubleScalarIsInf(c1_q_x);
          if (c1_j_b) {
            c1_guard2 = true;
          } else {
            c1_guard1 = true;
          }
        }

        if (c1_guard2) {
          if (c1_g_a == c1_h_b) {
            c1_array_real_T_2D_SetSize(chartInstance, &c1_b_st, &c1_r1,
              &c1_jb_emlrtRTEI, 1, 1);
            c1_r1.vector.data[0] = rtNaN;
          } else {
            c1_guard1 = true;
          }
        }

        if (c1_guard1) {
          c1_r_x = c1_g_a;
          c1_s_x = c1_r_x;
          c1_j_y = c1_s_x;
          c1_j_y = muDoubleScalarFloor(c1_j_y);
          if (c1_j_y == c1_g_a) {
            c1_array_real_T_2D_SetSize(chartInstance, &c1_b_st, &c1_r1,
              &c1_jb_emlrtRTEI, 1, (int32_T)(c1_h_b - c1_g_a) + 1);
            c1_g_loop_ub = (int32_T)(c1_h_b - c1_g_a);
            for (c1_i21 = 0; c1_i21 <= c1_g_loop_ub; c1_i21++) {
              c1_r1.vector.data[c1_i21] = c1_g_a + (real_T)c1_i21;
            }
          } else {
            c1_c_st.site = &c1_wc_emlrtRSI;
            c1_h_a = c1_g_a;
            c1_k_b = c1_h_b;
            c1_i_a = c1_h_a;
            c1_l_b = c1_k_b;
            c1_a1 = c1_i_a;
            c1_t_x = (c1_l_b - c1_i_a) + 0.5;
            c1_u_x = c1_t_x;
            c1_ndbl = c1_u_x;
            c1_ndbl = muDoubleScalarFloor(c1_ndbl);
            c1_apnd = c1_i_a + c1_ndbl;
            c1_cdiff = c1_apnd - c1_l_b;
            c1_j_a = c1_i_a;
            c1_m_b = c1_l_b;
            c1_v_x = c1_j_a;
            c1_w_x = c1_v_x;
            c1_x_x = c1_w_x;
            c1_k_y = muDoubleScalarAbs(c1_x_x);
            c1_y_x = c1_m_b;
            c1_ab_x = c1_y_x;
            c1_bb_x = c1_ab_x;
            c1_l_y = muDoubleScalarAbs(c1_bb_x);
            c1_c = muDoubleScalarMax(c1_k_y, c1_l_y);
            c1_thresh = 4.4408920985006262E-16 * c1_c;
            c1_db_x = c1_cdiff;
            c1_eb_x = c1_db_x;
            c1_fb_x = c1_eb_x;
            c1_m_y = muDoubleScalarAbs(c1_fb_x);
            if (c1_m_y < c1_thresh) {
              c1_ndbl++;
              c1_b1 = c1_l_b;
            } else if (c1_cdiff > 0.0) {
              c1_b1 = c1_i_a + (c1_ndbl - 1.0);
            } else {
              c1_ndbl++;
              c1_b1 = c1_apnd;
            }

            if (c1_ndbl >= 0.0) {
              c1_n = (int32_T)muDoubleScalarFloor(c1_ndbl);
            } else {
              c1_n = 0;
            }

            c1_array_real_T_2D_SetSize(chartInstance, &c1_c_st, &c1_r1,
              &c1_ib_emlrtRTEI, 1, c1_n);
            if (c1_n > 0) {
              c1_r1.vector.data[0] = c1_a1;
              if (c1_n > 1) {
                c1_r1.vector.data[c1_n - 1] = c1_b1;
                c1_nm1 = c1_n - 1;
                c1_l_a = c1_nm1;
                c1_nm1d2 = (uint16_T)((uint32_T)(uint16_T)c1_l_a >> 1);
                c1_i50 = c1_nm1d2 - 2;
                c1_d_st.site = &c1_xc_emlrtRSI;
                c1_q_b = c1_i50 + 1;
                c1_r_b = c1_q_b;
                if (c1_r_b < 1) {
                  c1_b_overflow = false;
                } else {
                  c1_b_overflow = (c1_r_b > 2147483646);
                }

                if (c1_b_overflow) {
                  c1_e_st.site = &c1_yc_emlrtRSI;
                  c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
                }

                for (c1_i_k = 0; c1_i_k <= c1_i50; c1_i_k++) {
                  c1_j_k = c1_i_k + 1;
                  c1_kd = (real_T)c1_j_k;
                  c1_r1.vector.data[c1_j_k] = c1_a1 + c1_kd;
                  c1_r1.vector.data[(c1_n - c1_j_k) - 1] = c1_b1 - c1_kd;
                }

                c1_s_b = c1_nm1d2;
                c1_r_y = c1_s_b << 1;
                if (c1_r_y == c1_nm1) {
                  c1_r1.vector.data[c1_nm1d2] = (c1_a1 + c1_b1) / 2.0;
                } else {
                  c1_kd = (real_T)c1_nm1d2;
                  c1_r1.vector.data[c1_nm1d2] = c1_a1 + c1_kd;
                  c1_r1.vector.data[c1_nm1d2 + 1] = c1_b1 - c1_kd;
                }
              }
            }
          }
        }
      }

      c1_sizeChunk = (real_T)c1_r1.size[1];
      c1_st.site = &c1_yj_emlrtRSI;
      c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_Ex_chunk,
        &c1_kb_emlrtRTEI, (int32_T)c1_sizeChunk);
      c1_st.site = &c1_xj_emlrtRSI;
      c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_Ey_chunk,
        &c1_lb_emlrtRTEI, (int32_T)c1_sizeChunk);
      c1_st.site = &c1_wj_emlrtRSI;
      c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_idxE_chunk,
        &c1_mb_emlrtRTEI, (int32_T)c1_sizeChunk);
      c1_idxEdge = (int32_T)c1_c_i;
      c1_i19 = (int32_T)c1_sizeChunk - 1;
      for (c1_b_idx = 0; c1_b_idx <= c1_i19; c1_b_idx++) {
        c1_c_idx = (real_T)c1_b_idx + 1.0;
        c1_i20 = c1_Ex.size[0];
        if ((c1_idxEdge < 1) || (c1_idxEdge > c1_i20)) {
          emlrtDynamicBoundsCheckR2012b(c1_idxEdge, 1, c1_i20, &c1_y_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_i22 = c1_Ex_chunk.size[0];
        c1_i23 = (int32_T)c1_c_idx;
        if ((c1_i23 < 1) || (c1_i23 > c1_i22)) {
          emlrtDynamicBoundsCheckR2012b(c1_i23, 1, c1_i22, &c1_ab_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_Ex_chunk.vector.data[c1_i23 - 1] = c1_Ex.vector.data[c1_idxEdge - 1];
        c1_i24 = c1_Ey.size[0];
        if ((c1_idxEdge < 1) || (c1_idxEdge > c1_i24)) {
          emlrtDynamicBoundsCheckR2012b(c1_idxEdge, 1, c1_i24, &c1_bb_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_i26 = c1_Ey_chunk.size[0];
        c1_i27 = (int32_T)c1_c_idx;
        if ((c1_i27 < 1) || (c1_i27 > c1_i26)) {
          emlrtDynamicBoundsCheckR2012b(c1_i27, 1, c1_i26, &c1_cb_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_Ey_chunk.vector.data[c1_i27 - 1] = c1_Ey.vector.data[c1_idxEdge - 1];
        c1_i29 = c1_idxE.size[0];
        if ((c1_idxEdge < 1) || (c1_idxEdge > c1_i29)) {
          emlrtDynamicBoundsCheckR2012b(c1_idxEdge, 1, c1_i29, &c1_db_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_i31 = c1_idxE_chunk.size[0];
        c1_i33 = (int32_T)c1_c_idx;
        if ((c1_i33 < 1) || (c1_i33 > c1_i31)) {
          emlrtDynamicBoundsCheckR2012b(c1_i33, 1, c1_i31, &c1_eb_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_idxE_chunk.vector.data[c1_i33 - 1] = c1_idxE.vector.data[c1_idxEdge -
          1];
        c1_idxEdge++;
      }

      c1_dim1 = (real_T)c1_idxE_chunk.size[0];
      c1_st.site = &c1_bk_emlrtRSI;
      c1_array_real32_T_2D_SetSize(chartInstance, &c1_st, &c1_xc,
        &c1_nb_emlrtRTEI, (int32_T)c1_dim1, 51);
      c1_st.site = &c1_ak_emlrtRSI;
      c1_array_real32_T_2D_SetSize(chartInstance, &c1_st, &c1_yc,
        &c1_ob_emlrtRTEI, (int32_T)c1_dim1, 51);
      c1_st.site = &c1_ck_emlrtRSI;
      c1_array_creal_T_2D_SetSize(chartInstance, &c1_st, &c1_w, &c1_pb_emlrtRTEI,
        (int32_T)c1_dim1, 51);
      c1_st.site = &c1_qj_emlrtRSI;
      c1_array_boolean_T_2D_SetSize(chartInstance, &c1_st, &c1_inside,
        &c1_qb_emlrtRTEI, (int32_T)c1_dim1, 51);
      c1_rows_to_keep_size[0] = (int32_T)c1_dim1;
      c1_h_loop_ub = (int32_T)c1_dim1 - 1;
      for (c1_i25 = 0; c1_i25 <= c1_h_loop_ub; c1_i25++) {
        c1_rows_to_keep_data[c1_i25] = false;
      }

      for (c1_idx2 = 0; c1_idx2 < 51; c1_idx2++) {
        c1_b_idx2 = (real_T)c1_idx2 + 1.0;
        c1_i28 = (int32_T)c1_dim1 - 1;
        for (c1_idx1 = 0; c1_idx1 <= c1_i28; c1_idx1++) {
          c1_b_idx1 = (real_T)c1_idx1 + 1.0;
          c1_i30 = c1_idxE_chunk.size[0];
          c1_i32 = (int32_T)c1_b_idx1;
          if ((c1_i32 < 1) || (c1_i32 > c1_i30)) {
            emlrtDynamicBoundsCheckR2012b(c1_i32, 1, c1_i30, &c1_fb_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_cb_x = chartInstance->c1_Gx[(int32_T)
            c1_idxE_chunk.vector.data[c1_i32 - 1] - 1];
          c1_i34 = c1_idxE_chunk.size[0];
          c1_i36 = (int32_T)c1_b_idx1;
          if ((c1_i36 < 1) || (c1_i36 > c1_i34)) {
            emlrtDynamicBoundsCheckR2012b(c1_i36, 1, c1_i34, &c1_gb_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_n_y = c1_b_gradientImg[(int32_T)c1_idxE_chunk.vector.data[c1_i36 -
            1] - 1];
          c1_gb_x = c1_cb_x;
          c1_o_y = c1_n_y;
          c1_b_z = c1_gb_x / c1_o_y;
          c1_k_a = -(15.0 + 0.5 * (real_T)((int32_T)c1_b_idx2 - 1));
          c1_p_b = c1_b_z;
          c1_p_y = (real32_T)c1_k_a * c1_p_b;
          c1_i41 = c1_Ex_chunk.size[0];
          c1_i42 = (int32_T)c1_b_idx1;
          if ((c1_i42 < 1) || (c1_i42 > c1_i41)) {
            emlrtDynamicBoundsCheckR2012b(c1_i42, 1, c1_i41, &c1_hb_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_hb_x = (real32_T)c1_Ex_chunk.vector.data[c1_i42 - 1] + c1_p_y;
          c1_ib_x = c1_hb_x;
          c1_q_y = c1_ib_x;
          c1_q_y = muSingleScalarRound(c1_q_y);
          c1_i49 = c1_xc.size[0];
          c1_i51 = (int32_T)c1_b_idx1;
          if ((c1_i51 < 1) || (c1_i51 > c1_i49)) {
            emlrtDynamicBoundsCheckR2012b(c1_i51, 1, c1_i49, &c1_kb_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_xc.vector.data[(c1_i51 + c1_xc.size[0] * ((int32_T)c1_b_idx2 - 1))
            - 1] = c1_q_y;
          c1_i56 = c1_idxE_chunk.size[0];
          c1_i57 = (int32_T)c1_b_idx1;
          if ((c1_i57 < 1) || (c1_i57 > c1_i56)) {
            emlrtDynamicBoundsCheckR2012b(c1_i57, 1, c1_i56, &c1_lb_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_jb_x = chartInstance->c1_Gy[(int32_T)
            c1_idxE_chunk.vector.data[c1_i57 - 1] - 1];
          c1_i60 = c1_idxE_chunk.size[0];
          c1_i62 = (int32_T)c1_b_idx1;
          if ((c1_i62 < 1) || (c1_i62 > c1_i60)) {
            emlrtDynamicBoundsCheckR2012b(c1_i62, 1, c1_i60, &c1_ob_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_s_y = c1_b_gradientImg[(int32_T)c1_idxE_chunk.vector.data[c1_i62 -
            1] - 1];
          c1_kb_x = c1_jb_x;
          c1_t_y = c1_s_y;
          c1_c_z = c1_kb_x / c1_t_y;
          c1_m_a = -(15.0 + 0.5 * (real_T)((int32_T)c1_b_idx2 - 1));
          c1_t_b = c1_c_z;
          c1_u_y = (real32_T)c1_m_a * c1_t_b;
          c1_i71 = c1_Ey_chunk.size[0];
          c1_i72 = (int32_T)c1_b_idx1;
          if ((c1_i72 < 1) || (c1_i72 > c1_i71)) {
            emlrtDynamicBoundsCheckR2012b(c1_i72, 1, c1_i71, &c1_dc_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_lb_x = (real32_T)c1_Ey_chunk.vector.data[c1_i72 - 1] + c1_u_y;
          c1_mb_x = c1_lb_x;
          c1_v_y = c1_mb_x;
          c1_v_y = muSingleScalarRound(c1_v_y);
          c1_i76 = c1_yc.size[0];
          c1_i78 = (int32_T)c1_b_idx1;
          if ((c1_i78 < 1) || (c1_i78 > c1_i76)) {
            emlrtDynamicBoundsCheckR2012b(c1_i78, 1, c1_i76, &c1_ec_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_yc.vector.data[(c1_i78 + c1_yc.size[0] * ((int32_T)c1_b_idx2 - 1))
            - 1] = c1_v_y;
          c1_i80 = c1_w.size[0];
          c1_i81 = (int32_T)c1_b_idx1;
          if ((c1_i81 < 1) || (c1_i81 > c1_i80)) {
            emlrtDynamicBoundsCheckR2012b(c1_i81, 1, c1_i80, &c1_fc_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_w.vector.data[(c1_i81 + c1_w.size[0] * ((int32_T)c1_b_idx2 - 1)) -
            1].re = c1_Opca[(int32_T)c1_b_idx2 - 1].re;
          c1_i84 = c1_w.size[0];
          c1_i85 = (int32_T)c1_b_idx1;
          if ((c1_i85 < 1) || (c1_i85 > c1_i84)) {
            emlrtDynamicBoundsCheckR2012b(c1_i85, 1, c1_i84, &c1_fc_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_w.vector.data[(c1_i85 + c1_w.size[0] * ((int32_T)c1_b_idx2 - 1)) -
            1].im = c1_Opca[(int32_T)c1_b_idx2 - 1].im;
          c1_i87 = c1_xc.size[0];
          c1_i89 = (int32_T)c1_b_idx1;
          if ((c1_i89 < 1) || (c1_i89 > c1_i87)) {
            emlrtDynamicBoundsCheckR2012b(c1_i89, 1, c1_i87, &c1_gc_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_u_b = (c1_xc.vector.data[(c1_i89 + c1_xc.size[0] * ((int32_T)
                      c1_b_idx2 - 1)) - 1] >= 1.0F);
          c1_i91 = c1_xc.size[0];
          c1_i92 = (int32_T)c1_b_idx1;
          if ((c1_i92 < 1) || (c1_i92 > c1_i91)) {
            emlrtDynamicBoundsCheckR2012b(c1_i92, 1, c1_i91, &c1_hc_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_b_b1 = (c1_xc.vector.data[(c1_i92 + c1_xc.size[0] * ((int32_T)
            c1_b_idx2 - 1)) - 1] <= 160.0F);
          c1_b2 = (c1_u_b && c1_b_b1);
          c1_i93 = c1_yc.size[0];
          c1_i94 = (int32_T)c1_b_idx1;
          if ((c1_i94 < 1) || (c1_i94 > c1_i93)) {
            emlrtDynamicBoundsCheckR2012b(c1_i94, 1, c1_i93, &c1_ic_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_b3 = (c1_yc.vector.data[(c1_i94 + c1_yc.size[0] * ((int32_T)
                     c1_b_idx2 - 1)) - 1] >= 1.0F);
          c1_b4 = (c1_b2 && c1_b3);
          c1_i95 = c1_yc.size[0];
          c1_i96 = (int32_T)c1_b_idx1;
          if ((c1_i96 < 1) || (c1_i96 > c1_i95)) {
            emlrtDynamicBoundsCheckR2012b(c1_i96, 1, c1_i95, &c1_jc_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_b5 = (c1_yc.vector.data[(c1_i96 + c1_yc.size[0] * ((int32_T)
                     c1_b_idx2 - 1)) - 1] <= 120.0F);
          c1_i97 = c1_inside.size[0];
          c1_i98 = (int32_T)c1_b_idx1;
          if ((c1_i98 < 1) || (c1_i98 > c1_i97)) {
            emlrtDynamicBoundsCheckR2012b(c1_i98, 1, c1_i97, &c1_kc_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_inside.vector.data[(c1_i98 + c1_inside.size[0] * ((int32_T)
            c1_b_idx2 - 1)) - 1] = (c1_b4 && c1_b5);
          c1_i99 = c1_inside.size[0];
          c1_i100 = (int32_T)c1_b_idx1;
          if ((c1_i100 < 1) || (c1_i100 > c1_i99)) {
            emlrtDynamicBoundsCheckR2012b(c1_i100, 1, c1_i99, &c1_lc_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          if (c1_inside.vector.data[(c1_i100 + c1_inside.size[0] * ((int32_T)
                c1_b_idx2 - 1)) - 1]) {
            c1_i101 = (int32_T)c1_b_idx1;
            if ((c1_i101 < 1) || (c1_i101 > c1_rows_to_keep_size[0])) {
              emlrtDynamicBoundsCheckR2012b(c1_i101, 1, c1_rows_to_keep_size[0],
                &c1_mc_emlrtBCI, (emlrtConstCTX)c1_sp);
            }

            c1_rows_to_keep_data[c1_i101 - 1] = true;
          }
        }
      }

      c1_dim1 = (real_T)c1_idxE_chunk.size[0];
      c1_st.site = &c1_uj_emlrtRSI;
      c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_xckeep,
        &c1_sb_emlrtRTEI, c1_xc.size[0] * 51);
      c1_st.site = &c1_tj_emlrtRSI;
      c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_yckeep,
        &c1_tb_emlrtRTEI, c1_yc.size[0] * 51);
      c1_st.site = &c1_oj_emlrtRSI;
      c1_array_creal_T_SetSize(chartInstance, &c1_st, &c1_wkeep,
        &c1_ub_emlrtRTEI, c1_w.size[0] * 51);
      c1_idxkeep = 0;
      for (c1_c_idx2 = 0; c1_c_idx2 < 51; c1_c_idx2++) {
        c1_b_idx2 = (real_T)c1_c_idx2 + 1.0;
        c1_i35 = (int32_T)c1_dim1 - 1;
        for (c1_c_idx1 = 0; c1_c_idx1 <= c1_i35; c1_c_idx1++) {
          c1_b_idx1 = (real_T)c1_c_idx1 + 1.0;
          c1_i38 = (int32_T)c1_b_idx1;
          if ((c1_i38 < 1) || (c1_i38 > c1_rows_to_keep_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c1_i38, 1, c1_rows_to_keep_size[0],
              &c1_ib_emlrtBCI, (emlrtConstCTX)c1_sp);
          }

          if (c1_rows_to_keep_data[c1_i38 - 1]) {
            c1_i39 = c1_inside.size[0];
            c1_i40 = (int32_T)c1_b_idx1;
            if ((c1_i40 < 1) || (c1_i40 > c1_i39)) {
              emlrtDynamicBoundsCheckR2012b(c1_i40, 1, c1_i39, &c1_jb_emlrtBCI,
                (emlrtConstCTX)c1_sp);
            }

            if (c1_inside.vector.data[(c1_i40 + c1_inside.size[0] * ((int32_T)
                  c1_b_idx2 - 1)) - 1]) {
              c1_idxkeep++;
              c1_i45 = c1_xc.size[0];
              c1_i46 = (int32_T)c1_b_idx1;
              if ((c1_i46 < 1) || (c1_i46 > c1_i45)) {
                emlrtDynamicBoundsCheckR2012b(c1_i46, 1, c1_i45, &c1_mb_emlrtBCI,
                  (emlrtConstCTX)c1_sp);
              }

              c1_i48 = c1_xckeep.size[0];
              if ((c1_idxkeep < 1) || (c1_idxkeep > c1_i48)) {
                emlrtDynamicBoundsCheckR2012b(c1_idxkeep, 1, c1_i48,
                  &c1_nb_emlrtBCI, (emlrtConstCTX)c1_sp);
              }

              c1_xckeep.vector.data[c1_idxkeep - 1] = (int32_T)
                c1_xc.vector.data[(c1_i46 + c1_xc.size[0] * ((int32_T)c1_b_idx2
                - 1)) - 1];
              c1_i53 = c1_yc.size[0];
              c1_i55 = (int32_T)c1_b_idx1;
              if ((c1_i55 < 1) || (c1_i55 > c1_i53)) {
                emlrtDynamicBoundsCheckR2012b(c1_i55, 1, c1_i53, &c1_pb_emlrtBCI,
                  (emlrtConstCTX)c1_sp);
              }

              c1_i59 = c1_yckeep.size[0];
              if ((c1_idxkeep < 1) || (c1_idxkeep > c1_i59)) {
                emlrtDynamicBoundsCheckR2012b(c1_idxkeep, 1, c1_i59,
                  &c1_qb_emlrtBCI, (emlrtConstCTX)c1_sp);
              }

              c1_yckeep.vector.data[c1_idxkeep - 1] = (int32_T)
                c1_yc.vector.data[(c1_i55 + c1_yc.size[0] * ((int32_T)c1_b_idx2
                - 1)) - 1];
              c1_i63 = c1_wkeep.size[0];
              if ((c1_idxkeep < 1) || (c1_idxkeep > c1_i63)) {
                emlrtDynamicBoundsCheckR2012b(c1_idxkeep, 1, c1_i63,
                  &c1_sb_emlrtBCI, (emlrtConstCTX)c1_sp);
              }

              c1_i65 = c1_w.size[0];
              c1_i66 = (int32_T)c1_b_idx1;
              if ((c1_i66 < 1) || (c1_i66 > c1_i65)) {
                emlrtDynamicBoundsCheckR2012b(c1_i66, 1, c1_i65, &c1_rb_emlrtBCI,
                  (emlrtConstCTX)c1_sp);
              }

              c1_wkeep.vector.data[c1_idxkeep - 1].re = c1_w.vector.data[(c1_i66
                + c1_w.size[0] * ((int32_T)c1_b_idx2 - 1)) - 1].re;
              c1_i69 = c1_w.size[0];
              c1_i70 = (int32_T)c1_b_idx1;
              if ((c1_i70 < 1) || (c1_i70 > c1_i69)) {
                emlrtDynamicBoundsCheckR2012b(c1_i70, 1, c1_i69, &c1_rb_emlrtBCI,
                  (emlrtConstCTX)c1_sp);
              }

              c1_i74 = c1_wkeep.size[0];
              if ((c1_idxkeep < 1) || (c1_idxkeep > c1_i74)) {
                emlrtDynamicBoundsCheckR2012b(c1_idxkeep, 1, c1_i74,
                  &c1_sb_emlrtBCI, (emlrtConstCTX)c1_sp);
              }

              c1_wkeep.vector.data[c1_idxkeep - 1].im = c1_w.vector.data[(c1_i70
                + c1_w.size[0] * ((int32_T)c1_b_idx2 - 1)) - 1].im;
            }
          }
        }
      }

      c1_st.site = &c1_ic_emlrtRSI;
      c1_szxc = c1_idxkeep;
      for (c1_i37 = 0; c1_i37 < 19200; c1_i37++) {
        chartInstance->c1_out[c1_i37].re = 0.0;
        chartInstance->c1_out[c1_i37].im = 0.0;
      }

      c1_b_st.site = &c1_ad_emlrtRSI;
      c1_n_b = c1_szxc;
      c1_o_b = c1_n_b;
      if (c1_o_b < 1) {
        c1_overflow = false;
      } else {
        c1_overflow = (c1_o_b > 2147483646);
      }

      if (c1_overflow) {
        c1_c_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
      }

      for (c1_d_idx = 0; c1_d_idx < c1_szxc; c1_d_idx++) {
        c1_e_idx = c1_d_idx + 1;
        c1_i44 = c1_yckeep.size[0];
        if ((c1_e_idx < 1) || (c1_e_idx > c1_i44)) {
          emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1, c1_i44, &c1_ac_emlrtBCI,
            &c1_st);
        }

        c1_i47 = c1_yckeep.vector.data[c1_e_idx - 1];
        if ((c1_i47 < 1) || (c1_i47 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c1_i47, 1, 120, &c1_yb_emlrtBCI, &c1_st);
        }

        c1_i52 = c1_xckeep.size[0];
        if ((c1_e_idx < 1) || (c1_e_idx > c1_i52)) {
          emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1, c1_i52, &c1_cc_emlrtBCI,
            &c1_st);
        }

        c1_i54 = c1_xckeep.vector.data[c1_e_idx - 1];
        if ((c1_i54 < 1) || (c1_i54 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c1_i54, 1, 160, &c1_bc_emlrtBCI, &c1_st);
        }

        c1_i58 = c1_yckeep.size[0];
        if ((c1_e_idx < 1) || (c1_e_idx > c1_i58)) {
          emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1, c1_i58, &c1_ub_emlrtBCI,
            &c1_st);
        }

        c1_i61 = c1_yckeep.vector.data[c1_e_idx - 1];
        if ((c1_i61 < 1) || (c1_i61 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c1_i61, 1, 120, &c1_tb_emlrtBCI, &c1_st);
        }

        c1_i64 = c1_xckeep.size[0];
        if ((c1_e_idx < 1) || (c1_e_idx > c1_i64)) {
          emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1, c1_i64, &c1_wb_emlrtBCI,
            &c1_st);
        }

        c1_i67 = c1_xckeep.vector.data[c1_e_idx - 1];
        if ((c1_i67 < 1) || (c1_i67 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c1_i67, 1, 160, &c1_vb_emlrtBCI, &c1_st);
        }

        c1_i68 = c1_wkeep.size[0];
        if ((c1_e_idx < 1) || (c1_e_idx > c1_i68)) {
          emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1, c1_i68, &c1_xb_emlrtBCI,
            &c1_st);
        }

        chartInstance->c1_out[(c1_i47 + 120 * (c1_i54 - 1)) - 1].re =
          chartInstance->c1_out[(c1_i61 + 120 * (c1_i67 - 1)) - 1].re +
          c1_wkeep.vector.data[c1_e_idx - 1].re;
        c1_i73 = c1_yckeep.size[0];
        if ((c1_e_idx < 1) || (c1_e_idx > c1_i73)) {
          emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1, c1_i73, &c1_ub_emlrtBCI,
            &c1_st);
        }

        c1_i75 = c1_yckeep.vector.data[c1_e_idx - 1];
        if ((c1_i75 < 1) || (c1_i75 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c1_i75, 1, 120, &c1_tb_emlrtBCI, &c1_st);
        }

        c1_i77 = c1_xckeep.size[0];
        if ((c1_e_idx < 1) || (c1_e_idx > c1_i77)) {
          emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1, c1_i77, &c1_wb_emlrtBCI,
            &c1_st);
        }

        c1_i79 = c1_xckeep.vector.data[c1_e_idx - 1];
        if ((c1_i79 < 1) || (c1_i79 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c1_i79, 1, 160, &c1_vb_emlrtBCI, &c1_st);
        }

        c1_i82 = c1_wkeep.size[0];
        if ((c1_e_idx < 1) || (c1_e_idx > c1_i82)) {
          emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1, c1_i82, &c1_xb_emlrtBCI,
            &c1_st);
        }

        c1_i83 = c1_yckeep.size[0];
        if ((c1_e_idx < 1) || (c1_e_idx > c1_i83)) {
          emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1, c1_i83, &c1_ac_emlrtBCI,
            &c1_st);
        }

        c1_i86 = c1_yckeep.vector.data[c1_e_idx - 1];
        if ((c1_i86 < 1) || (c1_i86 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c1_i86, 1, 120, &c1_yb_emlrtBCI, &c1_st);
        }

        c1_i88 = c1_xckeep.size[0];
        if ((c1_e_idx < 1) || (c1_e_idx > c1_i88)) {
          emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1, c1_i88, &c1_cc_emlrtBCI,
            &c1_st);
        }

        c1_i90 = c1_xckeep.vector.data[c1_e_idx - 1];
        if ((c1_i90 < 1) || (c1_i90 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c1_i90, 1, 160, &c1_bc_emlrtBCI, &c1_st);
        }

        chartInstance->c1_out[(c1_i86 + 120 * (c1_i90 - 1)) - 1].im =
          chartInstance->c1_out[(c1_i75 + 120 * (c1_i79 - 1)) - 1].im +
          c1_wkeep.vector.data[c1_e_idx - 1].im;
      }

      for (c1_i43 = 0; c1_i43 < 19200; c1_i43++) {
        c1_c_accumMatrix[c1_i43].re += chartInstance->c1_out[c1_i43].re;
        c1_c_accumMatrix[c1_i43].im += chartInstance->c1_out[c1_i43].im;
      }
    }

    c1_array_real_T_Destructor(chartInstance, &c1_Ex);
    c1_array_real_T_Destructor(chartInstance, &c1_Ey);
    c1_array_real_T_2D_Destructor(chartInstance, &c1_r1);
    c1_array_creal_T_Destructor(chartInstance, &c1_wkeep);
    c1_array_int32_T_Destructor(chartInstance, &c1_yckeep);
    c1_array_int32_T_Destructor(chartInstance, &c1_xckeep);
    c1_array_boolean_T_2D_Destructor(chartInstance, &c1_inside);
    c1_array_creal_T_2D_Destructor(chartInstance, &c1_w);
    c1_array_real32_T_2D_Destructor(chartInstance, &c1_yc);
    c1_array_real32_T_2D_Destructor(chartInstance, &c1_xc);
    c1_array_real_T_Destructor(chartInstance, &c1_idxE_chunk);
    c1_array_real_T_Destructor(chartInstance, &c1_Ey_chunk);
    c1_array_real_T_Destructor(chartInstance, &c1_Ex_chunk);
    c1_array_real_T_Destructor(chartInstance, &c1_idxE);
  }
}

static real_T c1_graythresh(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real32_T c1_I[19200])
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  real_T c1_counts[256];
  real_T c1_localBins1[256];
  real_T c1_localBins2[256];
  real_T c1_localBins3[256];
  real_T c1_b_out;
  real_T c1_d_i;
  int32_T c1_b_c;
  int32_T c1_b_i;
  int32_T c1_c;
  int32_T c1_c_a;
  int32_T c1_c_c;
  int32_T c1_c_i;
  int32_T c1_d_a;
  int32_T c1_d_c;
  int32_T c1_e_a;
  int32_T c1_e_c;
  int32_T c1_f_a;
  int32_T c1_f_c;
  int32_T c1_g_a;
  int32_T c1_g_c;
  int32_T c1_h_a;
  int32_T c1_h_c;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i_a;
  int32_T c1_i_c;
  int32_T c1_idx;
  int32_T c1_idx1;
  int32_T c1_idx2;
  int32_T c1_idx3;
  int32_T c1_idx4;
  int32_T c1_j_a;
  int32_T c1_j_c;
  int32_T c1_k_a;
  int32_T c1_l_a;
  uint8_T c1_b_I[19200];
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_lc_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    chartInstance->c1_img[c1_i] = c1_I[c1_i];
  }

  c1_b_st.site = &c1_j_emlrtRSI;
  c1_c_st.site = &c1_k_emlrtRSI;
  grayto8_real32(&chartInstance->c1_img[0], &c1_b_I[0], 19200.0);
  c1_st.site = &c1_mc_emlrtRSI;
  c1_b_st.site = &c1_m_emlrtRSI;
  c1_c_st.site = &c1_o_emlrtRSI;
  c1_b_out = 1.0;
  getnumcores(&c1_b_out);
  c1_c_st.site = &c1_n_emlrtRSI;
  for (c1_i1 = 0; c1_i1 < 256; c1_i1++) {
    c1_counts[c1_i1] = 0.0;
  }

  for (c1_i2 = 0; c1_i2 < 256; c1_i2++) {
    c1_localBins1[c1_i2] = 0.0;
  }

  for (c1_i3 = 0; c1_i3 < 256; c1_i3++) {
    c1_localBins2[c1_i3] = 0.0;
  }

  for (c1_i4 = 0; c1_i4 < 256; c1_i4++) {
    c1_localBins3[c1_i4] = 0.0;
  }

  for (c1_b_i = 4; c1_b_i <= 19200; c1_b_i += 4) {
    c1_i5 = c1_b_i - 3;
    if ((c1_i5 < 1) || (c1_i5 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c1_i5, 1, 19200, &c1_h_emlrtBCI, &c1_c_st);
    }

    c1_idx1 = c1_b_I[c1_i5 - 1];
    c1_i6 = c1_b_i - 2;
    if ((c1_i6 < 1) || (c1_i6 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c1_i6, 1, 19200, &c1_i_emlrtBCI, &c1_c_st);
    }

    c1_idx2 = c1_b_I[c1_i6 - 1];
    c1_i7 = c1_b_i - 1;
    if ((c1_i7 < 1) || (c1_i7 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c1_i7, 1, 19200, &c1_j_emlrtBCI, &c1_c_st);
    }

    c1_idx3 = c1_b_I[c1_i7 - 1];
    if ((c1_b_i < 1) || (c1_b_i > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c1_b_i, 1, 19200, &c1_k_emlrtBCI, &c1_c_st);
    }

    c1_idx4 = c1_b_I[c1_b_i - 1];
    c1_e_a = c1_idx1 + 1;
    c1_c_c = c1_e_a - 1;
    c1_f_a = c1_idx1 + 1;
    c1_d_c = c1_f_a - 1;
    c1_localBins1[c1_c_c] = c1_localBins1[c1_d_c] + 1.0;
    c1_g_a = c1_idx2 + 1;
    c1_e_c = c1_g_a - 1;
    c1_h_a = c1_idx2 + 1;
    c1_f_c = c1_h_a - 1;
    c1_localBins2[c1_e_c] = c1_localBins2[c1_f_c] + 1.0;
    c1_i_a = c1_idx3 + 1;
    c1_g_c = c1_i_a - 1;
    c1_j_a = c1_idx3 + 1;
    c1_h_c = c1_j_a - 1;
    c1_localBins3[c1_g_c] = c1_localBins3[c1_h_c] + 1.0;
    c1_k_a = c1_idx4 + 1;
    c1_i_c = c1_k_a - 1;
    c1_l_a = c1_idx4 + 1;
    c1_j_c = c1_l_a - 1;
    c1_counts[c1_i_c] = c1_counts[c1_j_c] + 1.0;
  }

  while (c1_b_i - 3 <= 19200) {
    c1_idx = c1_b_I[c1_b_i - 4];
    c1_c_a = c1_idx + 1;
    c1_c = c1_c_a - 1;
    c1_d_a = c1_idx + 1;
    c1_b_c = c1_d_a - 1;
    c1_counts[c1_c] = c1_counts[c1_b_c] + 1.0;
    c1_b_i++;
  }

  for (c1_c_i = 0; c1_c_i < 256; c1_c_i++) {
    c1_d_i = (real_T)c1_c_i + 1.0;
    c1_counts[(int32_T)c1_d_i - 1] = ((c1_counts[(int32_T)c1_d_i - 1] +
      c1_localBins1[(int32_T)c1_d_i - 1]) + c1_localBins2[(int32_T)c1_d_i - 1])
      + c1_localBins3[(int32_T)c1_d_i - 1];
  }

  c1_st.site = &c1_nc_emlrtRSI;
  return c1_otsuthresh(chartInstance, &c1_st, c1_counts);
}

static void c1_eml_find(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_b_x[19200], c1_coder_array_int32_T *c1_i,
  c1_coder_array_int32_T *c1_j)
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_b_iv[2];
  int32_T c1_b_iv1[2];
  int32_T c1_iv2[2];
  int32_T c1_b_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_idx;
  int32_T c1_ii;
  int32_T c1_jj;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_exitg1;
  boolean_T c1_guard1;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_pc_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_idx = 0;
  c1_array_int32_T_SetSize(chartInstance, &c1_st, c1_i, &c1_vb_emlrtRTEI, 19200);
  c1_array_int32_T_SetSize(chartInstance, &c1_st, c1_j, &c1_wb_emlrtRTEI, 19200);
  c1_ii = 1;
  c1_jj = 1;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_jj <= 160)) {
    c1_guard1 = false;
    if (c1_b_x[(c1_ii + 120 * (c1_jj - 1)) - 1]) {
      c1_idx++;
      c1_i->vector.data[c1_idx - 1] = c1_ii;
      c1_j->vector.data[c1_idx - 1] = c1_jj;
      if (c1_idx >= 19200) {
        c1_exitg1 = true;
      } else {
        c1_guard1 = true;
      }
    } else {
      c1_guard1 = true;
    }

    if (c1_guard1) {
      c1_ii++;
      if (c1_ii > 120) {
        c1_ii = 1;
        c1_jj++;
      }
    }
  }

  c1_b = (c1_idx < 1);
  if (c1_b) {
    c1_b_i = 0;
  } else {
    c1_b_i = c1_idx;
  }

  c1_b_iv[0] = 1;
  c1_b_iv[1] = c1_b_i;
  c1_b_st.site = &c1_sc_emlrtRSI;
  c1_indexShapeCheck(chartInstance, &c1_b_st, 19200, c1_b_iv);
  c1_array_int32_T_SetSize(chartInstance, &c1_st, c1_i, &c1_xb_emlrtRTEI, c1_b_i);
  c1_b1 = (c1_idx < 1);
  if (c1_b1) {
    c1_i1 = 0;
  } else {
    c1_i1 = c1_idx;
  }

  c1_b_iv1[0] = 1;
  c1_b_iv1[1] = c1_i1;
  c1_b_st.site = &c1_rc_emlrtRSI;
  c1_indexShapeCheck(chartInstance, &c1_b_st, 19200, c1_b_iv1);
  c1_array_int32_T_SetSize(chartInstance, &c1_st, c1_j, &c1_yb_emlrtRTEI, c1_i1);
  c1_b2 = (c1_idx < 1);
  if (c1_b2) {
    c1_i2 = 0;
  } else {
    c1_i2 = c1_idx;
  }

  c1_iv2[0] = 1;
  c1_iv2[1] = c1_i2;
  c1_b_st.site = &c1_qc_emlrtRSI;
  c1_indexShapeCheck(chartInstance, &c1_b_st, 19200, c1_iv2);
}

static void c1_indexShapeCheck(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, int32_T c1_matrixSize, int32_T
  c1_indexSize[2])
{
  static char_T c1_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  int32_T c1_size1;
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_b_c;
  boolean_T c1_c;
  boolean_T c1_nonSingletonDimFound;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_size1 = c1_matrixSize;
  if (c1_size1 != 1) {
    c1_b = false;
  } else {
    c1_b = true;
  }

  if (c1_b) {
    c1_nonSingletonDimFound = false;
    if (c1_indexSize[1] != 1) {
      c1_nonSingletonDimFound = true;
    }

    c1_b_b = c1_nonSingletonDimFound;
    if (c1_b_b) {
      c1_c = true;
    } else {
      c1_c = false;
    }
  } else {
    c1_c = false;
  }

  c1_st.site = &c1_tc_emlrtRSI;
  c1_b_c = c1_c;
  if (c1_b_c) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c1_st, &c1_f_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_c_y)));
  }
}

static void c1_sub2ind(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_coder_array_real_T *c1_c_varargin_1,
  c1_coder_array_real_T *c1_b_varargin_2, c1_coder_array_int32_T *c1_idx)
{
  static char_T c1_b_cv1[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', '2', 'i', 'n', 'd', ':', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't',
    'V', 'e', 'c', 't', 'o', 'r', 'S', 'i', 'z', 'e' };

  static char_T c1_b_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
    '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  c1_coder_array_int32_T c1_b;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  real_T c1_c_varargin_2[2];
  real_T c1_d_varargin_1[2];
  real_T c1_b_k;
  real_T c1_x1;
  real_T c1_x2;
  int32_T c1_b_loop_ub;
  int32_T c1_c_loop_ub;
  int32_T c1_d_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_k;
  int32_T c1_loop_ub;
  boolean_T c1_b_p;
  boolean_T c1_c_p;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  if (!c1_allinrange(chartInstance, c1_c_varargin_1, 120)) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c1_sp, &c1_g_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 1U, 14, c1_c_y)));
  }

  c1_d_varargin_1[0] = (real_T)c1_c_varargin_1->size[0];
  c1_d_varargin_1[1] = 1.0;
  c1_c_varargin_2[0] = (real_T)c1_b_varargin_2->size[0];
  c1_c_varargin_2[1] = 1.0;
  c1_p = false;
  c1_b_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 2)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_x1 = c1_d_varargin_1[(int32_T)c1_b_k - 1];
    c1_x2 = c1_c_varargin_2[(int32_T)c1_b_k - 1];
    c1_c_p = (c1_x1 == c1_x2);
    if (!c1_c_p) {
      c1_b_p = false;
      c1_exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (c1_b_p) {
    c1_p = true;
  }

  if (!c1_p) {
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    sf_mex_call(c1_sp, &c1_h_emlrtMCI, "error", 0U, 2U, 14, c1_d_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 1U, 14, c1_f_y)));
  }

  if (!c1_allinrange(chartInstance, c1_b_varargin_2, 160)) {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c1_sp, &c1_g_emlrtMCI, "error", 0U, 2U, 14, c1_e_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 1U, 14, c1_g_y)));
  }

  c1_st.site = &c1_sj_emlrtRSI;
  c1_array_int32_T_SetSize(chartInstance, &c1_st, c1_idx, &c1_ac_emlrtRTEI,
    c1_c_varargin_1->size[0]);
  c1_loop_ub = c1_c_varargin_1->size[0] - 1;
  for (c1_i = 0; c1_i <= c1_loop_ub; c1_i++) {
    c1_idx->vector.data[c1_i] = (int32_T)c1_c_varargin_1->vector.data[c1_i];
  }

  c1_array_int32_T_Constructor(chartInstance, &c1_b);
  c1_st.site = &c1_rj_emlrtRSI;
  c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_b, &c1_bc_emlrtRTEI,
    c1_b_varargin_2->size[0]);
  c1_b_loop_ub = c1_b_varargin_2->size[0] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_b_loop_ub; c1_i1++) {
    c1_b.vector.data[c1_i1] = (int32_T)c1_b_varargin_2->vector.data[c1_i1] - 1;
  }

  c1_c_loop_ub = c1_b.size[0] - 1;
  for (c1_i2 = 0; c1_i2 <= c1_c_loop_ub; c1_i2++) {
    c1_b.vector.data[c1_i2] *= 120;
  }

  c1_d_loop_ub = c1_idx->size[0] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_d_loop_ub; c1_i3++) {
    c1_idx->vector.data[c1_i3] += c1_b.vector.data[c1_i3];
  }

  c1_array_int32_T_Destructor(chartInstance, &c1_b);
}

static boolean_T c1_allinrange(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_real_T *c1_b_x, int32_T c1_hi)
{
  real_T c1_b_k;
  real_T c1_d;
  int32_T c1_exitg1;
  int32_T c1_i;
  int32_T c1_k;
  boolean_T c1_b;
  boolean_T c1_p;
  (void)chartInstance;
  c1_d = (real_T)c1_b_x->size[0];
  c1_i = (int32_T)c1_d - 1;
  c1_k = 0;
  do {
    c1_exitg1 = 0;
    if (c1_k <= c1_i) {
      c1_b_k = (real_T)c1_k + 1.0;
      if ((c1_b_x->vector.data[(int32_T)c1_b_k - 1] >= 1.0) &&
          (c1_b_x->vector.data[(int32_T)c1_b_k - 1] <= (real_T)c1_hi)) {
        c1_b = true;
      } else {
        c1_b = false;
      }

      if (!c1_b) {
        c1_p = false;
        c1_exitg1 = 1;
      } else {
        c1_k++;
      }
    } else {
      c1_p = true;
      c1_exitg1 = 1;
    }
  } while (c1_exitg1 == 0);

  return c1_p;
}

static void c1_check_forloop_overflow_error
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp)
{
  static char_T c1_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c1_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  (void)chartInstance;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                false);
  sf_mex_call(c1_sp, &c1_e_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
              sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
    (c1_sp, NULL, "message", 1U, 2U, 14, c1_c_y, 14, c1_d_y)));
}

static void c1_chcenters(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, creal_T c1_c_varargin_1[19200],
  c1_coder_array_real_T_2D *c1_centers, c1_coder_array_real_T_2D *c1_metric)
{
  static int32_T c1_offsets[25] = { -250, -249, -248, -247, -246, -126, -125,
    -124, -123, -122, -2, -1, 0, 1, 2, 122, 123, 124, 125, 126, 246, 247, 248,
    249, 250 };

  static char_T c1_b_cv[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'g', 'i', 'o', 'n', 'a', 'l', 'm', 'a', 'x', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c1_b_cv3[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', 's', 'd', 'e', 'l', 'd', 'i', 'm', 'm', 'i', 's', 'm', 'a', 't', 'c',
    'h' };

  static char_T c1_b_cv2[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    'l', 'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c1_b_cv1[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'I', ',' };

  c1_coder_array_int32_T c1_r;
  c1_coder_array_int32_T_2D c1_iidx;
  c1_coder_array_real_T c1_b_centers;
  c1_coder_array_real_T c1_b_varargin_2;
  c1_coder_array_real_T c1_c_centers;
  c1_coder_array_real_T c1_ndx;
  c1_coder_array_real_T_2D c1_e_centers;
  c1_coder_array_real_T_2D c1_f_x;
  c1_coder_array_real_T_2D c1_j_x;
  c1_coder_array_real_T_2D c1_sortIdx;
  c1_coder_array_sOA5t73y81YtFHGIDxk c1_b_s;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_i_y = NULL;
  const mxArray *c1_j_y = NULL;
  const mxArray *c1_k_y = NULL;
  const mxArray *c1_l_y = NULL;
  creal_T c1_b_x;
  real_T c1_domainSizeT[2];
  real_T c1_sizeB[2];
  real_T c1_startIdxT[2];
  real_T c1_b;
  real_T c1_b_accumMatrixRe;
  real_T c1_b_idx;
  real_T c1_b_y;
  real_T c1_c_a;
  real_T c1_c_j;
  real_T c1_c_x;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d_a;
  real_T c1_d_i;
  real_T c1_d_k;
  real_T c1_d_x;
  real_T c1_e_a;
  real_T c1_e_x;
  real_T c1_f_a;
  real_T c1_f_k;
  real_T c1_g_a;
  real_T c1_g_x;
  real_T c1_h_k;
  real_T c1_h_x;
  real_T c1_x1;
  real_T c1_x2;
  int32_T c1_b_iv[2];
  int32_T c1_b_iv1[2];
  int32_T c1_tmp_data[2];
  int32_T c1_b_sortIdx[1];
  int32_T c1_b_c;
  int32_T c1_b_i;
  int32_T c1_b_j;
  int32_T c1_b_k;
  int32_T c1_b_loop_ub;
  int32_T c1_c;
  int32_T c1_c_c;
  int32_T c1_c_i;
  int32_T c1_c_idx;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_d_c;
  int32_T c1_d_centers;
  int32_T c1_d_idx;
  int32_T c1_d_j;
  int32_T c1_d_loop_ub;
  int32_T c1_e_i;
  int32_T c1_e_idx;
  int32_T c1_e_j;
  int32_T c1_e_k;
  int32_T c1_e_loop_ub;
  int32_T c1_f_i;
  int32_T c1_f_idx;
  int32_T c1_f_j;
  int32_T c1_f_loop_ub;
  int32_T c1_g_b;
  int32_T c1_g_i;
  int32_T c1_g_idx;
  int32_T c1_g_j;
  int32_T c1_g_k;
  int32_T c1_g_loop_ub;
  int32_T c1_h_a;
  int32_T c1_h_b;
  int32_T c1_h_i;
  int32_T c1_h_j;
  int32_T c1_h_loop_ub;
  int32_T c1_h_y;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i_a;
  int32_T c1_i_loop_ub;
  int32_T c1_i_x;
  int32_T c1_idx;
  int32_T c1_j;
  int32_T c1_j_loop_ub;
  int32_T c1_k;
  int32_T c1_k_loop_ub;
  int32_T c1_l_loop_ub;
  int32_T c1_loop_ub;
  int32_T c1_m_loop_ub;
  int32_T c1_n;
  int32_T c1_nrows;
  int32_T c1_nrowx;
  boolean_T c1_bw[19200];
  boolean_T c1_x_data[19200];
  boolean_T c1_conn[9];
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_c_b;
  boolean_T c1_c_p;
  boolean_T c1_d_b;
  boolean_T c1_e_b;
  boolean_T c1_exitg1;
  boolean_T c1_f_b;
  boolean_T c1_flat;
  boolean_T c1_guard1;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_st.site = &c1_gj_emlrtRSI;
  c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_centers, &c1_cc_emlrtRTEI,
    0, 0);
  c1_st.site = &c1_fj_emlrtRSI;
  c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_metric, &c1_dc_emlrtRTEI,
    0, 0);
  for (c1_k = 0; c1_k < 19200; c1_k++) {
    c1_b_k = c1_k;
    c1_b_x = c1_c_varargin_1[c1_b_k];
    c1_x1 = c1_b_x.re;
    c1_x2 = c1_b_x.im;
    c1_c_a = c1_x1;
    c1_b = c1_x2;
    c1_b_y = muDoubleScalarHypot(c1_c_a, c1_b);
    chartInstance->c1_accumMatrixRe[c1_b_k] = c1_b_y;
  }

  c1_b_accumMatrixRe = chartInstance->c1_accumMatrixRe[0];
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_bw[c1_i] = (chartInstance->c1_accumMatrixRe[c1_i] == c1_b_accumMatrixRe);
  }

  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    c1_x_data[c1_i1] = c1_bw[c1_i1];
  }

  c1_flat = true;
  c1_c_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_c_k < 19200)) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    if (!c1_x_data[(int32_T)c1_d_k - 1]) {
      c1_flat = false;
      c1_exitg1 = true;
    } else {
      c1_c_k++;
    }
  }

  if (!c1_flat) {
    c1_st.site = &c1_bd_emlrtRSI;
    c1_b_st.site = &c1_id_emlrtRSI;
    for (c1_j = 0; c1_j < 2; c1_j++) {
      c1_c_j = (real_T)c1_j + 1.0;
      for (c1_b_i = 0; c1_b_i < 124; c1_b_i++) {
        c1_d_i = (real_T)c1_b_i + 1.0;
        chartInstance->c1_Apad[((int32_T)c1_d_i + 124 * ((int32_T)c1_c_j - 1)) -
          1] = 0.0;
      }
    }

    for (c1_b_j = 0; c1_b_j < 2; c1_b_j++) {
      for (c1_c_i = 0; c1_c_i < 124; c1_c_i++) {
        c1_d_i = (real_T)c1_c_i + 1.0;
        chartInstance->c1_Apad[((int32_T)c1_d_i + 124 * (c1_b_j + 162)) - 1] =
          0.0;
      }
    }

    for (c1_d_j = 0; c1_d_j < 160; c1_d_j++) {
      c1_c_j = (real_T)c1_d_j + 1.0;
      for (c1_e_i = 0; c1_e_i < 2; c1_e_i++) {
        c1_d_i = (real_T)c1_e_i + 1.0;
        c1_d_a = c1_c_j;
        c1_c = (int32_T)c1_d_a;
        chartInstance->c1_Apad[((int32_T)c1_d_i + 124 * (c1_c + 1)) - 1] = 0.0;
      }
    }

    for (c1_e_j = 0; c1_e_j < 160; c1_e_j++) {
      c1_c_j = (real_T)c1_e_j + 1.0;
      for (c1_f_i = 0; c1_f_i < 2; c1_f_i++) {
        c1_e_a = c1_c_j;
        c1_b_c = (int32_T)c1_e_a;
        chartInstance->c1_Apad[(c1_f_i + 124 * (c1_b_c + 1)) + 122] = 0.0;
      }
    }

    for (c1_f_j = 0; c1_f_j < 160; c1_f_j++) {
      c1_c_j = (real_T)c1_f_j + 1.0;
      for (c1_g_i = 0; c1_g_i < 120; c1_g_i++) {
        c1_d_i = (real_T)c1_g_i + 1.0;
        c1_f_a = c1_d_i;
        c1_c_c = (int32_T)c1_f_a;
        c1_g_a = c1_c_j;
        c1_d_c = (int32_T)c1_g_a;
        chartInstance->c1_Apad[(c1_c_c + 124 * (c1_d_c + 1)) + 1] =
          chartInstance->c1_accumMatrixRe[((int32_T)c1_d_i + 120 * ((int32_T)
          c1_c_j - 1)) - 1];
      }
    }

    c1_c_st.site = &c1_jd_emlrtRSI;
    c1_d_st.site = &c1_kd_emlrtRSI;
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_domainSizeT[c1_i2] = 5.0;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_startIdxT[c1_i3] = 2.0;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_sizeB[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    ordfilt2_real64(&chartInstance->c1_Apad[0], 124.0, &c1_startIdxT[0],
                    &c1_offsets[0], 25.0, &c1_domainSizeT[0], 12.0,
                    &chartInstance->c1_Hd[0], &c1_sizeB[0], true);
    c1_st.site = &c1_cd_emlrtRSI;
    c1_b_st.site = &c1_ld_emlrtRSI;
    for (c1_i5 = 0; c1_i5 < 19200; c1_i5++) {
      chartInstance->c1_marker[c1_i5] = chartInstance->c1_Hd[c1_i5] - 0.15;
    }

    c1_c_st.site = &c1_md_emlrtRSI;
    c1_validateattributes(chartInstance, &c1_c_st, chartInstance->c1_marker);
    c1_c_st.site = &c1_nd_emlrtRSI;
    c1_validateattributes(chartInstance, &c1_c_st, chartInstance->c1_Hd);
    c1_c_st.site = &c1_pb_emlrtRSI;
    for (c1_i6 = 0; c1_i6 < 19200; c1_i6++) {
      chartInstance->c1_mask[c1_i6] = chartInstance->c1_Hd[c1_i6];
    }

    for (c1_i7 = 0; c1_i7 < 19200; c1_i7++) {
      chartInstance->c1_Hd[c1_i7] = chartInstance->c1_marker[c1_i7];
    }

    for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
      c1_domainSizeT[c1_i8] = 120.0 + 40.0 * (real_T)c1_i8;
    }

    ippreconstruct_real64(&chartInstance->c1_Hd[0], &chartInstance->c1_mask[0],
                          &c1_domainSizeT[0], 2.0);
    c1_st.site = &c1_dd_emlrtRSI;
    c1_b_st.site = &c1_od_emlrtRSI;
    c1_c_st.site = &c1_s_emlrtRSI;
    c1_p = true;
    c1_e_k = 0;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_e_k < 19200)) {
      c1_f_k = (real_T)c1_e_k + 1.0;
      c1_c_x = chartInstance->c1_Hd[(int32_T)c1_f_k - 1];
      c1_d_x = c1_c_x;
      c1_c_b = muDoubleScalarIsNaN(c1_d_x);
      c1_b_p = !c1_c_b;
      if (c1_b_p) {
        c1_e_k++;
      } else {
        c1_p = false;
        c1_exitg1 = true;
      }
    }

    if (c1_p) {
      c1_b_b = true;
    } else {
      c1_b_b = false;
    }

    if (!c1_b_b) {
      c1_c_y = NULL;
      sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 35),
                    false);
      c1_d_y = NULL;
      sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv3, 10, 0U, 1, 0U, 2, 1, 46),
                    false);
      c1_e_y = NULL;
      sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1, 0U, 2, 1,
        18), false);
      sf_mex_call(&c1_c_st, &c1_i_emlrtMCI, "error", 0U, 2U, 14, c1_c_y, 14,
                  sf_mex_call(&c1_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c1_c_st, NULL, "message", 1U, 2U, 14, c1_d_y, 14, c1_e_y)));
    }

    c1_b_st.site = &c1_pd_emlrtRSI;
    for (c1_g_k = 0; c1_g_k < 19200; c1_g_k++) {
      c1_h_k = (real_T)c1_g_k + 1.0;
      c1_e_x = chartInstance->c1_Hd[(int32_T)c1_h_k - 1];
      c1_d_b = muDoubleScalarIsNaN(c1_e_x);
      if (c1_d_b) {
        c1_f_y = NULL;
        sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_b_cv2, 10, 0U, 1, 0U, 2, 1,
          19), false);
        c1_g_y = NULL;
        sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_b_cv2, 10, 0U, 1, 0U, 2, 1,
          19), false);
        sf_mex_call(&c1_b_st, &c1_j_emlrtMCI, "error", 0U, 2U, 14, c1_f_y, 14,
                    sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c1_b_st, NULL, "message", 1U, 1U, 14, c1_g_y)));
      }
    }

    c1_b_st.site = &c1_qd_emlrtRSI;
    for (c1_i9 = 0; c1_i9 < 9; c1_i9++) {
      c1_conn[c1_i9] = true;
    }

    for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
      c1_domainSizeT[c1_i10] = 120.0 + 40.0 * (real_T)c1_i10;
    }

    for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
      c1_startIdxT[c1_i11] = 3.0;
    }

    imregionalmax_real64(&chartInstance->c1_Hd[0], &c1_bw[0], 2.0,
                         &c1_domainSizeT[0], &c1_conn[0], 2.0, &c1_startIdxT[0]);
    c1_array_sOA5t73y81YtFHGIDxk0fKF_C(chartInstance, &c1_b_s);
    c1_st.site = &c1_ed_emlrtRSI;
    c1_regionprops(chartInstance, &c1_st, c1_bw, chartInstance->c1_accumMatrixRe,
                   &c1_b_s);
    if (c1_b_s.size[0] != 0) {
      c1_st.site = &c1_ej_emlrtRSI;
      c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_centers,
        &c1_ec_emlrtRTEI, c1_b_s.size[0], 2);
      c1_d = (real_T)c1_b_s.size[0];
      c1_i12 = (int32_T)c1_d - 1;
      for (c1_idx = 0; c1_idx <= c1_i12; c1_idx++) {
        c1_b_idx = (real_T)c1_idx + 1.0;
        c1_i14 = c1_centers->size[0];
        c1_i15 = (int32_T)c1_b_idx;
        if ((c1_i15 < 1) || (c1_i15 > c1_i14)) {
          emlrtDynamicBoundsCheckR2012b(c1_i15, 1, c1_i14, &c1_nc_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_i16 = c1_i15;
        for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
          c1_tmp_data[c1_i17] = c1_i17;
        }

        for (c1_i20 = 0; c1_i20 < 2; c1_i20++) {
          c1_b_iv[c1_i20] = 1 + c1_i20;
        }

        for (c1_i21 = 0; c1_i21 < 2; c1_i21++) {
          c1_b_iv1[c1_i21] = 1 + c1_i21;
        }

        emlrtSubAssignSizeCheckR2012b(&c1_b_iv[0], 2, &c1_b_iv1[0], 2,
          &c1_emlrtECI, (void *)c1_sp);
        c1_i22 = c1_i16 - 1;
        for (c1_i23 = 0; c1_i23 < 2; c1_i23++) {
          c1_i27 = c1_b_s.size[0];
          c1_i28 = (int32_T)c1_b_idx;
          if ((c1_i28 < 1) || (c1_i28 > c1_i27)) {
            emlrtDynamicBoundsCheckR2012b(c1_i28, 1, c1_i27, &c1_pc_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_centers->vector.data[c1_i22 + c1_centers->size[0] *
            c1_tmp_data[c1_i23]] = c1_b_s.vector.data[c1_i28 - 1].
            WeightedCentroid[c1_i23];
        }
      }

      c1_d1 = (real_T)c1_centers->size[0];
      c1_i13 = (int32_T)-((-1.0 - c1_d1) + 1.0);
      emlrtForLoopVectorCheckR2021a(c1_d1, -1.0, 1.0, mxDOUBLE_CLASS, c1_i13,
        &c1_hi_emlrtRTEI, (emlrtConstCTX)c1_sp);
      c1_array_real_T_2D_Constructor(chartInstance, &c1_f_x);
      for (c1_c_idx = 0; c1_c_idx < c1_i13; c1_c_idx++) {
        c1_b_idx = c1_d1 - (real_T)c1_c_idx;
        c1_i18 = c1_centers->size[0];
        c1_i19 = (int32_T)c1_b_idx;
        if ((c1_i19 < 1) || (c1_i19 > c1_i18)) {
          emlrtDynamicBoundsCheckR2012b(c1_i19, 1, c1_i18, &c1_oc_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_g_x = c1_centers->vector.data[c1_i19 - 1];
        c1_e_b = muDoubleScalarIsNaN(c1_g_x);
        c1_guard1 = false;
        if (c1_e_b) {
          c1_guard1 = true;
        } else {
          c1_i25 = c1_centers->size[0];
          c1_i26 = (int32_T)c1_b_idx;
          if ((c1_i26 < 1) || (c1_i26 > c1_i25)) {
            emlrtDynamicBoundsCheckR2012b(c1_i26, 1, c1_i25, &c1_qc_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_h_x = c1_centers->vector.data[(c1_i26 + c1_centers->size[0]) - 1];
          c1_f_b = muDoubleScalarIsNaN(c1_h_x);
          if (c1_f_b) {
            c1_guard1 = true;
          }
        }

        if (c1_guard1) {
          c1_st.site = &c1_fd_emlrtRSI;
          c1_b_st.site = &c1_fd_emlrtRSI;
          c1_array_real_T_2D_SetSize(chartInstance, &c1_b_st, &c1_f_x,
            &c1_gc_emlrtRTEI, c1_centers->size[0], c1_centers->size[1]);
          c1_b_loop_ub = c1_centers->size[0] * c1_centers->size[1] - 1;
          for (c1_i29 = 0; c1_i29 <= c1_b_loop_ub; c1_i29++) {
            c1_f_x.vector.data[c1_i29] = c1_centers->vector.data[c1_i29];
          }

          c1_d_idx = (int32_T)c1_b_idx;
          c1_b_st.site = &c1_uf_emlrtRSI;
          c1_e_idx = c1_d_idx;
          c1_f_idx = c1_e_idx;
          c1_n = c1_f_x.size[0];
          c1_c_p = true;
          if (c1_f_idx > c1_n) {
            c1_c_p = false;
          } else {
            c1_i_x = c1_f_idx;
            c1_h_y = c1_i_x;
            if (c1_f_idx != c1_h_y) {
              c1_c_p = false;
            }
          }

          if (!c1_c_p) {
            c1_i_y = NULL;
            sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_b_cv3, 10, 0U, 1, 0U, 2,
              1, 25), false);
            c1_j_y = NULL;
            sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_b_cv3, 10, 0U, 1, 0U, 2,
              1, 25), false);
            sf_mex_call(&c1_b_st, &c1_r_emlrtMCI, "error", 0U, 2U, 14, c1_i_y,
                        14, sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c1_b_st, NULL, "message", 1U, 1U, 14, c1_j_y)));
          }

          c1_b_st.site = &c1_vf_emlrtRSI;
          c1_g_idx = c1_d_idx;
          c1_nrowx = c1_f_x.size[0];
          c1_nrows = c1_nrowx - 1;
          c1_c_st.site = &c1_wf_emlrtRSI;
          for (c1_g_j = 0; c1_g_j < 2; c1_g_j++) {
            c1_h_j = c1_g_j;
            c1_c_st.site = &c1_xf_emlrtRSI;
            c1_h_a = c1_g_idx;
            c1_g_b = c1_nrows;
            c1_i_a = c1_h_a;
            c1_h_b = c1_g_b;
            if (c1_i_a > c1_h_b) {
              c1_overflow = false;
            } else {
              c1_overflow = (c1_h_b > 2147483646);
            }

            if (c1_overflow) {
              c1_d_st.site = &c1_yc_emlrtRSI;
              c1_check_forloop_overflow_error(chartInstance, &c1_d_st);
            }

            for (c1_h_i = c1_g_idx; c1_h_i <= c1_nrows; c1_h_i++) {
              c1_f_x.vector.data[(c1_h_i + c1_f_x.size[0] * c1_h_j) - 1] =
                c1_f_x.vector.data[c1_h_i + c1_f_x.size[0] * c1_h_j];
            }
          }

          if (c1_nrows > c1_nrowx) {
            c1_k_y = NULL;
            sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_cv2, 10, 0U, 1, 0U, 2,
              1, 30), false);
            c1_l_y = NULL;
            sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_cv2, 10, 0U, 1, 0U, 2,
              1, 30), false);
            sf_mex_call(&c1_b_st, &c1_s_emlrtMCI, "error", 0U, 2U, 14, c1_k_y,
                        14, sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c1_b_st, NULL, "message", 1U, 1U, 14, c1_l_y)));
          }

          c1_b2 = (c1_nrows < 1);
          if (c1_b2) {
            c1_i34 = -1;
          } else {
            c1_i34 = c1_nrows - 1;
          }

          for (c1_i36 = 0; c1_i36 < 2; c1_i36++) {
            c1_g_loop_ub = c1_i34;
            for (c1_i37 = 0; c1_i37 <= c1_g_loop_ub; c1_i37++) {
              c1_f_x.vector.data[c1_i37 + (c1_i34 + 1) * c1_i36] =
                c1_f_x.vector.data[c1_i37 + c1_f_x.size[0] * c1_i36];
            }
          }

          c1_array_real_T_2D_SetSize(chartInstance, &c1_b_st, &c1_f_x,
            &c1_hc_emlrtRTEI, c1_i34 + 1, 2);
          c1_st.site = &c1_fd_emlrtRSI;
          c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_centers,
            &c1_gc_emlrtRTEI, c1_f_x.size[0], 2);
          c1_h_loop_ub = (c1_f_x.size[0] << 1) - 1;
          for (c1_i38 = 0; c1_i38 <= c1_h_loop_ub; c1_i38++) {
            c1_centers->vector.data[c1_i38] = c1_f_x.vector.data[c1_i38];
          }
        }
      }

      c1_array_real_T_2D_Destructor(chartInstance, &c1_f_x);
      c1_b1 = (c1_centers->size[0] == 0);
      if (!c1_b1) {
        c1_array_real_T_Constructor(chartInstance, &c1_ndx);
        c1_st.site = &c1_gd_emlrtRSI;
        c1_array_real_T_Constructor(chartInstance, &c1_b_centers);
        c1_b_st.site = &c1_gd_emlrtRSI;
        c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_b_centers,
          &c1_ic_emlrtRTEI, c1_centers->size[0]);
        c1_loop_ub = c1_centers->size[0] - 1;
        for (c1_i24 = 0; c1_i24 <= c1_loop_ub; c1_i24++) {
          c1_b_centers.vector.data[c1_i24] = c1_centers->vector.data[c1_i24 +
            c1_centers->size[0]];
        }

        c1_b_st.site = &c1_gd_emlrtRSI;
        c1_round(chartInstance, &c1_b_st, &c1_b_centers, &c1_ndx);
        c1_array_real_T_Destructor(chartInstance, &c1_b_centers);
        c1_array_real_T_Constructor(chartInstance, &c1_c_centers);
        c1_b_st.site = &c1_gd_emlrtRSI;
        c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_c_centers,
          &c1_jc_emlrtRTEI, c1_centers->size[0]);
        c1_c_loop_ub = c1_centers->size[0] - 1;
        for (c1_i30 = 0; c1_i30 <= c1_c_loop_ub; c1_i30++) {
          c1_c_centers.vector.data[c1_i30] = c1_centers->vector.data[c1_i30];
        }

        c1_array_real_T_Constructor(chartInstance, &c1_b_varargin_2);
        c1_b_st.site = &c1_gd_emlrtRSI;
        c1_round(chartInstance, &c1_b_st, &c1_c_centers, &c1_b_varargin_2);
        c1_array_real_T_Destructor(chartInstance, &c1_c_centers);
        c1_array_int32_T_Constructor(chartInstance, &c1_r);
        c1_b_st.site = &c1_uc_emlrtRSI;
        c1_sub2ind(chartInstance, &c1_b_st, &c1_ndx, &c1_b_varargin_2, &c1_r);
        c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_ndx, &c1_w_emlrtRTEI,
          c1_r.size[0]);
        c1_d_loop_ub = c1_r.size[0] - 1;
        for (c1_i31 = 0; c1_i31 <= c1_d_loop_ub; c1_i31++) {
          c1_ndx.vector.data[c1_i31] = (real_T)c1_r.vector.data[c1_i31];
        }

        c1_array_int32_T_Destructor(chartInstance, &c1_r);
        c1_st.site = &c1_gd_emlrtRSI;
        c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_b_varargin_2,
          &c1_kc_emlrtRTEI, c1_ndx.size[0]);
        c1_e_loop_ub = c1_ndx.size[0] - 1;
        for (c1_i32 = 0; c1_i32 <= c1_e_loop_ub; c1_i32++) {
          c1_i33 = (int32_T)c1_ndx.vector.data[c1_i32];
          if ((c1_i33 < 1) || (c1_i33 > 19200)) {
            emlrtDynamicBoundsCheckR2012b(c1_i33, 1, 19200, &c1_rc_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_b_varargin_2.vector.data[c1_i32] = chartInstance->c1_Hd[c1_i33 - 1];
        }

        c1_array_real_T_Destructor(chartInstance, &c1_ndx);
        c1_st.site = &c1_gd_emlrtRSI;
        c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_metric,
          &c1_lc_emlrtRTEI, c1_b_varargin_2.size[0], 1);
        c1_f_loop_ub = c1_b_varargin_2.size[0] - 1;
        for (c1_i35 = 0; c1_i35 <= c1_f_loop_ub; c1_i35++) {
          c1_metric->vector.data[c1_i35] = c1_b_varargin_2.vector.data[c1_i35];
        }

        c1_array_real_T_Destructor(chartInstance, &c1_b_varargin_2);
        c1_st.site = &c1_hd_emlrtRSI;
        c1_array_real_T_2D_Constructor(chartInstance, &c1_j_x);
        c1_b_st.site = &c1_hd_emlrtRSI;
        c1_array_real_T_2D_SetSize(chartInstance, &c1_b_st, &c1_j_x,
          &c1_mc_emlrtRTEI, c1_metric->size[0], c1_metric->size[1]);
        c1_i_loop_ub = c1_metric->size[0] * c1_metric->size[1] - 1;
        for (c1_i39 = 0; c1_i39 <= c1_i_loop_ub; c1_i39++) {
          c1_j_x.vector.data[c1_i39] = c1_metric->vector.data[c1_i39];
        }

        c1_array_int32_T_2D_Constructor(chartInstance, &c1_iidx);
        c1_b_st.site = &c1_bg_emlrtRSI;
        c1_b_sort(chartInstance, &c1_b_st, &c1_j_x, &c1_iidx);
        c1_array_real_T_2D_Constructor(chartInstance, &c1_sortIdx);
        c1_array_real_T_2D_SetSize(chartInstance, &c1_st, &c1_sortIdx,
          &c1_nc_emlrtRTEI, c1_iidx.size[0], 1);
        c1_j_loop_ub = c1_iidx.size[0] - 1;
        for (c1_i40 = 0; c1_i40 <= c1_j_loop_ub; c1_i40++) {
          c1_sortIdx.vector.data[c1_i40] = (real_T)c1_iidx.vector.data[c1_i40];
        }

        c1_array_int32_T_2D_Destructor(chartInstance, &c1_iidx);
        c1_st.site = &c1_hd_emlrtRSI;
        c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_metric,
          &c1_oc_emlrtRTEI, c1_j_x.size[0], 1);
        c1_k_loop_ub = c1_j_x.size[0] - 1;
        for (c1_i41 = 0; c1_i41 <= c1_k_loop_ub; c1_i41++) {
          c1_metric->vector.data[c1_i41] = c1_j_x.vector.data[c1_i41];
        }

        c1_array_real_T_2D_Destructor(chartInstance, &c1_j_x);
        c1_d_centers = c1_centers->size[0];
        c1_b_sortIdx[0] = c1_sortIdx.size[0];
        c1_array_real_T_2D_Constructor(chartInstance, &c1_e_centers);
        c1_st.site = &c1_dj_emlrtRSI;
        c1_array_real_T_2D_SetSize(chartInstance, &c1_st, &c1_e_centers,
          &c1_pc_emlrtRTEI, c1_b_sortIdx[0], 2);
        for (c1_i42 = 0; c1_i42 < 2; c1_i42++) {
          c1_l_loop_ub = c1_b_sortIdx[0] - 1;
          for (c1_i43 = 0; c1_i43 <= c1_l_loop_ub; c1_i43++) {
            c1_i44 = (int32_T)c1_sortIdx.vector.data[c1_i43];
            if ((c1_i44 < 1) || (c1_i44 > c1_d_centers)) {
              emlrtDynamicBoundsCheckR2012b(c1_i44, 1, c1_d_centers,
                &c1_sc_emlrtBCI, (emlrtConstCTX)c1_sp);
            }

            c1_e_centers.vector.data[c1_i43 + c1_e_centers.size[0] * c1_i42] =
              c1_centers->vector.data[(c1_i44 + c1_centers->size[0] * c1_i42) -
              1];
          }
        }

        c1_array_real_T_2D_Destructor(chartInstance, &c1_sortIdx);
        c1_st.site = &c1_dj_emlrtRSI;
        c1_array_real_T_2D_SetSize(chartInstance, &c1_st, c1_centers,
          &c1_qc_emlrtRTEI, c1_e_centers.size[0], c1_e_centers.size[1]);
        c1_m_loop_ub = c1_e_centers.size[0] * c1_e_centers.size[1] - 1;
        for (c1_i45 = 0; c1_i45 <= c1_m_loop_ub; c1_i45++) {
          c1_centers->vector.data[c1_i45] = c1_e_centers.vector.data[c1_i45];
        }

        c1_array_real_T_2D_Destructor(chartInstance, &c1_e_centers);
      }
    }

    c1_array_sOA5t73y81YtFHGIDxk0fKF_D(chartInstance, &c1_b_s);
  }
}

static void c1_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_c_a[19200])
{
  static char_T c1_b_cv[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'c', 'o', 'n', 's', 't', 'r', 'u', 'c', 't', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c1_b_cv1[5] = { 'i', 'n', 'p', 'u', 't' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  int32_T c1_k;
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_s_emlrtRSI;
  c1_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 19200)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_b_x = c1_c_a[(int32_T)c1_b_k - 1];
    c1_c_x = c1_b_x;
    c1_b_b = muDoubleScalarIsNaN(c1_c_x);
    c1_b_p = !c1_b_b;
    if (c1_b_p) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 35),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv3, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c1_st, &c1_i_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_c_y, 14, c1_d_y)));
  }
}

static void c1_regionprops(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200], real_T
  c1_b_varargin_2[19200], c1_coder_array_sOA5t73y81YtFHGIDxk *c1_outstats)
{
  static char_T c1_b_cv[31] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'r', 'e', 'g',
    'i', 'o', 'n', 'p', 'r', 'o', 'p', 's', ':', 's', 'i', 'z', 'e', 'M', 'i',
    's', 'm', 'a', 't', 'c', 'h' };

  c1_coder_array_boolean_T c1_tile;
  c1_coder_array_int32_T c1_b_regionLengths;
  c1_coder_array_int32_T c1_idxCount;
  c1_coder_array_int32_T c1_regionLengths;
  c1_coder_array_real_T c1_regionIndices;
  c1_coder_array_s_R6Og1x0kmqQXSF9Pw c1_stats;
  c1_sHtk0WM4OMtyqkehwQYcq2 c1_statsAlreadyComputed;
  c1_sOA5t73y81YtFHGIDxk0fKF c1_b_s;
  c1_s_7KvKuzB0WpLeFthPVHAilE c1_CC;
  c1_s_R6Og1x0kmqQXSF9Pwa49FD c1_statsOneObj;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  real_T c1_imageSize[2];
  real_T c1_b_k;
  real_T c1_b_numObjs;
  real_T c1_b_vIdx;
  real_T c1_c_numObjs;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d_k;
  real_T c1_d_numObjs;
  real_T c1_e_numObjs;
  real_T c1_e_varargin_1;
  real_T c1_f_k;
  real_T c1_f_varargin_1;
  real_T c1_numObjs;
  real_T c1_x1;
  real_T c1_x2;
  int32_T c1_b_outsize[2];
  int32_T c1_outsize[2];
  int32_T c1_b_loop_ub;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_d_loop_ub;
  int32_T c1_dim;
  int32_T c1_e_k;
  int32_T c1_e_loop_ub;
  int32_T c1_f_loop_ub;
  int32_T c1_g_loop_ub;
  int32_T c1_h_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i_loop_ub;
  int32_T c1_k;
  int32_T c1_loop_ub;
  int32_T c1_vIdx;
  boolean_T c1_d_varargin_1[19200];
  boolean_T c1_b;
  boolean_T c1_b_p;
  boolean_T c1_c_p;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_array_s_7KvKuzB0WpLeFthPVHAilE_(chartInstance, &c1_CC);
  c1_st.site = &c1_rd_emlrtRSI;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_d_varargin_1[c1_i] = c1_c_varargin_1[c1_i];
  }

  c1_bwconncomp(chartInstance, &c1_st, c1_d_varargin_1, &c1_CC);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_imageSize[c1_i1] = c1_CC.ImageSize[c1_i1];
  }

  c1_numObjs = c1_CC.NumObjects;
  c1_st.site = &c1_sd_emlrtRSI;
  c1_b_numObjs = c1_numObjs;
  c1_p = false;
  c1_b_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 2)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_x1 = c1_imageSize[(int32_T)c1_b_k - 1];
    c1_x2 = 120.0 + 40.0 * (real_T)((int32_T)c1_b_k - 1);
    c1_c_p = (c1_x1 == c1_x2);
    if (!c1_c_p) {
      c1_b_p = false;
      c1_exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (c1_b_p) {
    c1_p = true;
  }

  if (!c1_p) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 31),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c1_st, &c1_n_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_c_y)));
  }

  c1_b_st.site = &c1_gf_emlrtRSI;
  c1_c_numObjs = c1_b_numObjs;
  c1_c_st.site = &c1_hf_emlrtRSI;
  c1_e_varargin_1 = c1_c_numObjs;
  c1_d_st.site = &c1_ef_emlrtRSI;
  c1_assertValidSizeArg(chartInstance, &c1_d_st, c1_e_varargin_1);
  c1_array_boolean_T_Constructor(chartInstance, &c1_tile);
  c1_array_boolean_T_SetSize(chartInstance, &c1_c_st, &c1_tile, &c1_rc_emlrtRTEI,
    (int32_T)c1_e_varargin_1);
  c1_loop_ub = (int32_T)c1_e_varargin_1 - 1;
  for (c1_i2 = 0; c1_i2 <= c1_loop_ub; c1_i2++) {
    c1_tile.vector.data[c1_i2] = false;
  }

  c1_outsize[0] = c1_tile.size[0];
  if (!((real_T)c1_outsize[0] == (real_T)c1_tile.size[0])) {
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv4, 10, 0U, 1, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c1_c_st, &c1_k_emlrtMCI, "error", 0U, 1U, 14, c1_d_y);
  }

  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_b_s.WeightedCentroid[c1_i3] = 0.0;
  }

  c1_array_sOA5t73y81YtFHGIDxk0fKF_S(chartInstance, &c1_c_st, c1_outstats,
    &c1_sc_emlrtRTEI, c1_outsize[0]);
  c1_b_loop_ub = c1_outsize[0] - 1;
  for (c1_i4 = 0; c1_i4 <= c1_b_loop_ub; c1_i4++) {
    c1_outstats->vector.data[c1_i4] = c1_b_s;
  }

  c1_st.site = &c1_td_emlrtRSI;
  c1_d_numObjs = c1_numObjs;
  c1_statsAlreadyComputed.Area = false;
  c1_c_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c1_statsOneObj);
  c1_statsOneObj.Area = 0.0;
  c1_statsAlreadyComputed.Centroid = false;
  for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
    c1_statsOneObj.Centroid[c1_i5] = 0.0;
  }

  c1_statsAlreadyComputed.BoundingBox = false;
  for (c1_i6 = 0; c1_i6 < 4; c1_i6++) {
    c1_statsOneObj.BoundingBox[c1_i6] = 0.0;
  }

  c1_statsAlreadyComputed.MajorAxisLength = false;
  c1_statsOneObj.MajorAxisLength = 0.0;
  c1_statsAlreadyComputed.MinorAxisLength = false;
  c1_statsOneObj.MinorAxisLength = 0.0;
  c1_statsAlreadyComputed.Eccentricity = false;
  c1_statsOneObj.Eccentricity = 0.0;
  c1_statsAlreadyComputed.Orientation = false;
  c1_statsOneObj.Orientation = 0.0;
  c1_statsAlreadyComputed.Image = false;
  c1_statsOneObj.Image.size[0] = 0;
  c1_statsOneObj.Image.size[1] = 0;
  c1_statsAlreadyComputed.FilledImage = false;
  c1_statsOneObj.FilledImage.size[0] = 0;
  c1_statsOneObj.FilledImage.size[1] = 0;
  c1_statsAlreadyComputed.FilledArea = false;
  c1_statsOneObj.FilledArea = 0.0;
  c1_statsAlreadyComputed.EulerNumber = false;
  c1_statsOneObj.EulerNumber = 0.0;
  c1_statsAlreadyComputed.Extrema = false;
  for (c1_i7 = 0; c1_i7 < 16; c1_i7++) {
    c1_statsOneObj.Extrema[c1_i7] = 0.0;
  }

  c1_statsAlreadyComputed.EquivDiameter = false;
  c1_statsOneObj.EquivDiameter = 0.0;
  c1_statsAlreadyComputed.Extent = false;
  c1_statsOneObj.Extent = 0.0;
  c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_statsOneObj.PixelIdxList,
    &c1_vc_emlrtRTEI, 0);
  c1_statsAlreadyComputed.PixelList = false;
  c1_array_real_T_2D_SetSize(chartInstance, &c1_st, &c1_statsOneObj.PixelList,
    &c1_wc_emlrtRTEI, 0, 2);
  c1_statsAlreadyComputed.Perimeter = false;
  c1_statsOneObj.Perimeter = 0.0;
  c1_statsAlreadyComputed.Circularity = false;
  c1_statsOneObj.Circularity = 0.0;
  c1_statsAlreadyComputed.PixelValues = false;
  c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_statsOneObj.PixelValues,
    &c1_xc_emlrtRTEI, 0);
  c1_statsAlreadyComputed.WeightedCentroid = false;
  for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
    c1_statsOneObj.WeightedCentroid[c1_i8] = 0.0;
  }

  c1_statsAlreadyComputed.MeanIntensity = false;
  c1_statsOneObj.MeanIntensity = 0.0;
  c1_statsAlreadyComputed.MinIntensity = false;
  c1_statsOneObj.MinIntensity = 0.0;
  c1_statsAlreadyComputed.MaxIntensity = false;
  c1_statsOneObj.MaxIntensity = 0.0;
  c1_statsAlreadyComputed.SubarrayIdx = false;
  c1_statsOneObj.SubarrayIdx.size[0] = 1;
  c1_statsOneObj.SubarrayIdx.size[1] = 0;
  for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
    c1_statsOneObj.SubarrayIdxLengths[c1_i9] = 0.0;
  }

  c1_b_st.site = &c1_if_emlrtRSI;
  c1_f_varargin_1 = c1_d_numObjs;
  c1_c_st.site = &c1_ef_emlrtRSI;
  c1_assertValidSizeArg(chartInstance, &c1_c_st, c1_f_varargin_1);
  c1_array_boolean_T_SetSize(chartInstance, &c1_b_st, &c1_tile, &c1_rc_emlrtRTEI,
    (int32_T)c1_f_varargin_1);
  c1_c_loop_ub = (int32_T)c1_f_varargin_1 - 1;
  for (c1_i10 = 0; c1_i10 <= c1_c_loop_ub; c1_i10++) {
    c1_tile.vector.data[c1_i10] = false;
  }

  c1_b_outsize[0] = c1_tile.size[0];
  if (!((real_T)c1_b_outsize[0] == (real_T)c1_tile.size[0])) {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv4, 10, 0U, 1, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c1_b_st, &c1_k_emlrtMCI, "error", 0U, 1U, 14, c1_e_y);
  }

  c1_array_boolean_T_Destructor(chartInstance, &c1_tile);
  c1_e_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c1_stats);
  c1_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c1_b_st, &c1_stats,
    &c1_ad_emlrtRTEI, c1_b_outsize[0]);
  c1_d_loop_ub = c1_b_outsize[0] - 1;
  for (c1_i11 = 0; c1_i11 <= c1_d_loop_ub; c1_i11++) {
    c1_d_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c1_b_st,
      &c1_stats.vector.data[c1_i11], &c1_statsOneObj, &c1_ad_emlrtRTEI);
  }

  c1_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c1_statsOneObj);
  c1_st.site = &c1_ud_emlrtRSI;
  c1_e_numObjs = c1_numObjs;
  c1_statsAlreadyComputed.PixelIdxList = true;
  if (c1_e_numObjs != 0.0) {
    c1_array_real_T_Constructor(chartInstance, &c1_regionIndices);
    c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_regionIndices,
      &c1_bd_emlrtRTEI, c1_CC.RegionIndices.size[0]);
    c1_e_loop_ub = c1_CC.RegionIndices.size[0] - 1;
    for (c1_i13 = 0; c1_i13 <= c1_e_loop_ub; c1_i13++) {
      c1_regionIndices.vector.data[c1_i13] =
        c1_CC.RegionIndices.vector.data[c1_i13];
    }

    c1_array_int32_T_Constructor(chartInstance, &c1_regionLengths);
    c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_regionLengths,
      &c1_cd_emlrtRTEI, c1_CC.RegionLengths.size[0]);
    c1_f_loop_ub = c1_CC.RegionLengths.size[0] - 1;
    for (c1_i15 = 0; c1_i15 <= c1_f_loop_ub; c1_i15++) {
      c1_regionLengths.vector.data[c1_i15] =
        c1_CC.RegionLengths.vector.data[c1_i15];
    }

    c1_b_st.site = &c1_jf_emlrtRSI;
    c1_c_st.site = &c1_xe_emlrtRSI;
    c1_dim = 2;
    if ((real_T)c1_regionLengths.size[0] != 1.0) {
      c1_dim = 1;
    }

    c1_array_int32_T_Constructor(chartInstance, &c1_b_regionLengths);
    c1_array_int32_T_SetSize(chartInstance, &c1_c_st, &c1_b_regionLengths,
      &c1_dd_emlrtRTEI, c1_regionLengths.size[0]);
    c1_g_loop_ub = c1_regionLengths.size[0] - 1;
    for (c1_i20 = 0; c1_i20 <= c1_g_loop_ub; c1_i20++) {
      c1_b_regionLengths.vector.data[c1_i20] =
        c1_regionLengths.vector.data[c1_i20];
    }

    c1_d_st.site = &c1_ye_emlrtRSI;
    c1_useConstantDim(chartInstance, &c1_d_st, &c1_b_regionLengths, c1_dim,
                      &c1_regionLengths);
    c1_array_int32_T_Destructor(chartInstance, &c1_b_regionLengths);
    c1_array_int32_T_Constructor(chartInstance, &c1_idxCount);
    c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_idxCount,
      &c1_ed_emlrtRTEI, 1 + c1_regionLengths.size[0]);
    c1_idxCount.vector.data[0] = 0;
    c1_h_loop_ub = c1_regionLengths.size[0] - 1;
    for (c1_i24 = 0; c1_i24 <= c1_h_loop_ub; c1_i24++) {
      c1_idxCount.vector.data[c1_i24 + 1] = c1_regionLengths.vector.data[c1_i24];
    }

    c1_array_int32_T_Destructor(chartInstance, &c1_regionLengths);
    c1_d1 = (real_T)c1_stats.size[0];
    c1_i27 = (int32_T)c1_d1 - 1;
    for (c1_e_k = 0; c1_e_k <= c1_i27; c1_e_k++) {
      c1_f_k = (real_T)c1_e_k + 1.0;
      c1_i29 = c1_idxCount.size[0];
      c1_i30 = (int32_T)c1_f_k;
      if ((c1_i30 < 1) || (c1_i30 > c1_i29)) {
        emlrtDynamicBoundsCheckR2012b(c1_i30, 1, c1_i29, &c1_ad_emlrtBCI, &c1_st);
      }

      c1_i31 = c1_idxCount.vector.data[c1_i30 - 1] + 1;
      c1_i32 = c1_idxCount.size[0];
      c1_i33 = (int32_T)(c1_f_k + 1.0);
      if ((c1_i33 < 1) || (c1_i33 > c1_i32)) {
        emlrtDynamicBoundsCheckR2012b(c1_i33, 1, c1_i32, &c1_bd_emlrtBCI, &c1_st);
      }

      c1_i34 = c1_idxCount.vector.data[c1_i33 - 1];
      c1_b = (c1_i31 > c1_i34);
      if (c1_b) {
        c1_i36 = 0;
        c1_i37 = -1;
      } else {
        c1_i35 = c1_regionIndices.size[0];
        if ((c1_i31 < 1) || (c1_i31 > c1_i35)) {
          emlrtDynamicBoundsCheckR2012b(c1_i31, 1, c1_i35, &c1_uc_emlrtBCI,
            &c1_st);
        }

        c1_i36 = c1_i31 - 1;
        c1_i39 = c1_regionIndices.size[0];
        if ((c1_i34 < 1) || (c1_i34 > c1_i39)) {
          emlrtDynamicBoundsCheckR2012b(c1_i34, 1, c1_i39, &c1_tc_emlrtBCI,
            &c1_st);
        }

        c1_i37 = c1_i34 - 1;
      }

      c1_i38 = c1_stats.size[0];
      c1_i40 = (int32_T)c1_f_k;
      if ((c1_i40 < 1) || (c1_i40 > c1_i38)) {
        emlrtDynamicBoundsCheckR2012b(c1_i40, 1, c1_i38, &c1_cd_emlrtBCI, &c1_st);
      }

      c1_array_real_T_SetSize(chartInstance, &c1_st,
        &c1_stats.vector.data[c1_i40 - 1].PixelIdxList, &c1_fd_emlrtRTEI,
        (c1_i37 - c1_i36) + 1);
      c1_i_loop_ub = c1_i37 - c1_i36;
      for (c1_i41 = 0; c1_i41 <= c1_i_loop_ub; c1_i41++) {
        c1_i42 = c1_stats.size[0];
        c1_i43 = (int32_T)c1_f_k;
        if ((c1_i43 < 1) || (c1_i43 > c1_i42)) {
          emlrtDynamicBoundsCheckR2012b(c1_i43, 1, c1_i42, &c1_cd_emlrtBCI,
            &c1_st);
        }

        c1_stats.vector.data[c1_i43 - 1].PixelIdxList.vector.data[c1_i41] =
          c1_regionIndices.vector.data[c1_i36 + c1_i41];
      }
    }

    c1_array_int32_T_Destructor(chartInstance, &c1_idxCount);
    c1_array_real_T_Destructor(chartInstance, &c1_regionIndices);
  }

  c1_b_array_s_7KvKuzB0WpLeFthPVHAilE_(chartInstance, &c1_CC);
  c1_st.site = &c1_vd_emlrtRSI;
  for (c1_i12 = 0; c1_i12 < 19200; c1_i12++) {
    chartInstance->c1_varargin_2[c1_i12] = c1_b_varargin_2[c1_i12];
  }

  c1_b_ComputeWeightedCentroid(chartInstance, &c1_st,
    chartInstance->c1_varargin_2, &c1_stats, &c1_statsAlreadyComputed);
  c1_st.site = &c1_wd_emlrtRSI;
  c1_d = (real_T)c1_stats.size[0];
  c1_i14 = (int32_T)c1_d - 1;
  for (c1_c_k = 0; c1_c_k <= c1_i14; c1_c_k++) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_i16 = c1_stats.size[0];
    c1_i17 = (int32_T)c1_d_k;
    if ((c1_i17 < 1) || (c1_i17 > c1_i16)) {
      emlrtDynamicBoundsCheckR2012b(c1_i17, 1, c1_i16, &c1_vc_emlrtBCI, &c1_st);
    }

    c1_i18 = c1_outstats->size[0];
    c1_i19 = (int32_T)c1_d_k;
    if ((c1_i19 < 1) || (c1_i19 > c1_i18)) {
      emlrtDynamicBoundsCheckR2012b(c1_i19, 1, c1_i18, &c1_wc_emlrtBCI, &c1_st);
    }

    for (c1_vIdx = 0; c1_vIdx < 2; c1_vIdx++) {
      c1_b_vIdx = (real_T)c1_vIdx + 1.0;
      c1_i21 = c1_stats.size[0];
      c1_i22 = (int32_T)c1_d_k;
      if ((c1_i22 < 1) || (c1_i22 > c1_i21)) {
        emlrtDynamicBoundsCheckR2012b(c1_i22, 1, c1_i21, &c1_yc_emlrtBCI, &c1_st);
      }

      c1_i23 = c1_i22 - 1;
      c1_i25 = c1_outstats->size[0];
      c1_i26 = (int32_T)c1_d_k;
      if ((c1_i26 < 1) || (c1_i26 > c1_i25)) {
        emlrtDynamicBoundsCheckR2012b(c1_i26, 1, c1_i25, &c1_xc_emlrtBCI, &c1_st);
      }

      c1_i28 = c1_i26 - 1;
      c1_outstats->vector.data[c1_i28].WeightedCentroid[(int32_T)c1_b_vIdx - 1] =
        c1_stats.vector.data[c1_i23].WeightedCentroid[(int32_T)c1_b_vIdx - 1];
    }
  }

  c1_f_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c1_stats);
}

static void c1_bwconncomp(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200],
  c1_s_7KvKuzB0WpLeFthPVHAilE *c1_CC)
{
  c1_cell_wrap_46 c1_rv[1];
  c1_cell_wrap_46 c1_r2;
  c1_coder_array_cell_wrap_46_2D c1_r1;
  c1_coder_array_int32_T c1_b_x;
  c1_coder_array_int32_T c1_c_x;
  c1_coder_array_int32_T c1_d_x;
  c1_coder_array_int32_T c1_endRow;
  c1_coder_array_int32_T c1_idxCount;
  c1_coder_array_int32_T c1_labelForEachRun;
  c1_coder_array_int32_T c1_labelsRenumbered;
  c1_coder_array_int32_T c1_startCol;
  c1_coder_array_int32_T c1_startRow;
  c1_coder_array_real_T c1_r;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_g_st;
  emlrtStack c1_h_st;
  emlrtStack c1_st;
  real_T c1_b_col;
  real_T c1_b_k;
  real_T c1_b_s;
  real_T c1_b_y;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d_col;
  real_T c1_k_k;
  real_T c1_numComponents;
  int32_T c1_b_iv[1];
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_c;
  int32_T c1_b_dim;
  int32_T c1_b_loop_ub;
  int32_T c1_b_node;
  int32_T c1_b_p;
  int32_T c1_b_root_k;
  int32_T c1_b_root_p;
  int32_T c1_b_vlen;
  int32_T c1_c;
  int32_T c1_c_a;
  int32_T c1_c_b;
  int32_T c1_c_col;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_c_p;
  int32_T c1_c_vlen;
  int32_T c1_col;
  int32_T c1_column_offset;
  int32_T c1_currentColumn;
  int32_T c1_d_a;
  int32_T c1_d_b;
  int32_T c1_d_k;
  int32_T c1_d_loop_ub;
  int32_T c1_d_vlen;
  int32_T c1_dim;
  int32_T c1_e_a;
  int32_T c1_e_b;
  int32_T c1_e_k;
  int32_T c1_e_loop_ub;
  int32_T c1_exitg1;
  int32_T c1_f_a;
  int32_T c1_f_b;
  int32_T c1_f_k;
  int32_T c1_f_loop_ub;
  int32_T c1_firstRunOnPreviousColumn;
  int32_T c1_firstRunOnThisColumn;
  int32_T c1_g_a;
  int32_T c1_g_b;
  int32_T c1_g_k;
  int32_T c1_g_loop_ub;
  int32_T c1_h_a;
  int32_T c1_h_b;
  int32_T c1_h_k;
  int32_T c1_h_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i5;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i6;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i7;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i8;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i9;
  int32_T c1_i_k;
  int32_T c1_i_loop_ub;
  int32_T c1_ib;
  int32_T c1_idx;
  int32_T c1_inb;
  int32_T c1_j_k;
  int32_T c1_j_loop_ub;
  int32_T c1_k;
  int32_T c1_k_loop_ub;
  int32_T c1_l_loop_ub;
  int32_T c1_lastRunOnPreviousColumn;
  int32_T c1_lidx;
  int32_T c1_loop_ub;
  int32_T c1_nextLabel;
  int32_T c1_nfb;
  int32_T c1_nleft;
  int32_T c1_node;
  int32_T c1_numRuns;
  int32_T c1_p;
  int32_T c1_root_k;
  int32_T c1_root_p;
  int32_T c1_row;
  int32_T c1_rowidx;
  int32_T c1_runCounter;
  int32_T c1_vlen;
  boolean_T c1_b_overflow;
  boolean_T c1_c_overflow;
  boolean_T c1_d_overflow;
  boolean_T c1_i_b;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_g_st.prev = &c1_f_st;
  c1_g_st.tls = c1_f_st.tls;
  c1_h_st.prev = &c1_g_st;
  c1_h_st.tls = c1_g_st.tls;
  c1_CC->Connectivity = 8.0;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_CC->ImageSize[c1_i] = 120.0 + 40.0 * (real_T)c1_i;
  }

  c1_st.site = &c1_xd_emlrtRSI;
  c1_b_st.site = &c1_he_emlrtRSI;
  c1_numRuns = 0;
  for (c1_col = 0; c1_col < 160; c1_col++) {
    c1_b_col = (real_T)c1_col + 1.0;
    if (c1_c_varargin_1[120 * ((int32_T)c1_b_col - 1)]) {
      c1_numRuns++;
    }

    for (c1_k = 0; c1_k < 119; c1_k++) {
      c1_b_k = (real_T)c1_k + 2.0;
      if (c1_c_varargin_1[((int32_T)c1_b_k + 120 * ((int32_T)c1_b_col - 1)) - 1]
          && (!c1_c_varargin_1[((int32_T)(c1_b_k - 1.0) + 120 * ((int32_T)
             c1_b_col - 1)) - 1])) {
        c1_numRuns++;
      }
    }
  }

  c1_array_int32_T_Constructor(chartInstance, &c1_startRow);
  c1_array_int32_T_Constructor(chartInstance, &c1_endRow);
  c1_array_int32_T_Constructor(chartInstance, &c1_startCol);
  c1_array_int32_T_Constructor(chartInstance, &c1_labelForEachRun);
  if (c1_numRuns == 0) {
    c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_startRow,
      &c1_kd_emlrtRTEI, 0);
    c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_endRow,
      &c1_ld_emlrtRTEI, 0);
    c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_startCol,
      &c1_md_emlrtRTEI, 0);
    c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_labelForEachRun,
      &c1_nd_emlrtRTEI, 0);
    c1_numRuns = 0;
  } else {
    c1_d = (real_T)c1_numRuns;
    if (!(c1_d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c1_d, &c1_k_emlrtDCI, &c1_b_st);
    }

    c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_startRow,
      &c1_gd_emlrtRTEI, (int32_T)muDoubleScalarFloor(c1_d));
    c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_endRow,
      &c1_hd_emlrtRTEI, c1_numRuns);
    c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_startCol,
      &c1_id_emlrtRTEI, c1_numRuns);
    c1_c_st.site = &c1_ie_emlrtRSI;
    c1_runCounter = 1;
    for (c1_c_col = 0; c1_c_col < 160; c1_c_col++) {
      c1_d_col = (real_T)c1_c_col + 1.0;
      c1_row = 1;
      while (c1_row <= 120) {
        while ((c1_row <= 120) && (!c1_c_varargin_1[(c1_row + 120 * ((int32_T)
                  c1_d_col - 1)) - 1])) {
          c1_row++;
        }

        if ((c1_row <= 120) && c1_c_varargin_1[(c1_row + 120 * ((int32_T)
              c1_d_col - 1)) - 1]) {
          c1_i2 = c1_startCol.size[0];
          if ((c1_runCounter < 1) || (c1_runCounter > c1_i2)) {
            emlrtDynamicBoundsCheckR2012b(c1_runCounter, 1, c1_i2,
              &c1_fd_emlrtBCI, &c1_c_st);
          }

          c1_startCol.vector.data[c1_runCounter - 1] = (int32_T)c1_d_col;
          c1_i3 = c1_startRow.size[0];
          if ((c1_runCounter < 1) || (c1_runCounter > c1_i3)) {
            emlrtDynamicBoundsCheckR2012b(c1_runCounter, 1, c1_i3,
              &c1_hd_emlrtBCI, &c1_c_st);
          }

          c1_startRow.vector.data[c1_runCounter - 1] = c1_row;
          while ((c1_row <= 120) && c1_c_varargin_1[(c1_row + 120 * ((int32_T)
                   c1_d_col - 1)) - 1]) {
            c1_row++;
          }

          c1_i8 = c1_endRow.size[0];
          if ((c1_runCounter < 1) || (c1_runCounter > c1_i8)) {
            emlrtDynamicBoundsCheckR2012b(c1_runCounter, 1, c1_i8,
              &c1_ld_emlrtBCI, &c1_c_st);
          }

          c1_endRow.vector.data[c1_runCounter - 1] = c1_row - 1;
          c1_runCounter++;
        }
      }
    }

    c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_labelForEachRun,
      &c1_jd_emlrtRTEI, c1_numRuns);
    c1_loop_ub = c1_numRuns - 1;
    for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
      c1_labelForEachRun.vector.data[c1_i1] = 0;
    }

    c1_c_k = 1;
    c1_currentColumn = 2;
    c1_nextLabel = 1;
    c1_firstRunOnPreviousColumn = -1;
    c1_lastRunOnPreviousColumn = 0;
    c1_firstRunOnThisColumn = 1;
    while (c1_c_k <= c1_numRuns) {
      c1_i4 = c1_startCol.size[0];
      if ((c1_c_k < 1) || (c1_c_k > c1_i4)) {
        emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i4, &c1_gd_emlrtBCI,
          &c1_b_st);
      }

      if (c1_startCol.vector.data[c1_c_k - 1] == c1_currentColumn) {
        c1_firstRunOnPreviousColumn = c1_firstRunOnThisColumn;
        c1_firstRunOnThisColumn = c1_c_k;
        c1_lastRunOnPreviousColumn = c1_c_k;
        c1_i13 = c1_startCol.size[0];
        if ((c1_c_k < 1) || (c1_c_k > c1_i13)) {
          emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i13, &c1_kd_emlrtBCI,
            &c1_b_st);
        }

        c1_currentColumn = c1_startCol.vector.data[c1_c_k - 1] + 1;
      } else {
        c1_i7 = c1_startCol.size[0];
        if ((c1_c_k < 1) || (c1_c_k > c1_i7)) {
          emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i7, &c1_id_emlrtBCI,
            &c1_b_st);
        }

        if (c1_startCol.vector.data[c1_c_k - 1] > c1_currentColumn) {
          c1_firstRunOnPreviousColumn = -1;
          c1_lastRunOnPreviousColumn = 0;
          c1_firstRunOnThisColumn = c1_c_k;
          c1_i16 = c1_startCol.size[0];
          if ((c1_c_k < 1) || (c1_c_k > c1_i16)) {
            emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i16, &c1_md_emlrtBCI,
              &c1_b_st);
          }

          c1_currentColumn = c1_startCol.vector.data[c1_c_k - 1] + 1;
        }
      }

      if (c1_firstRunOnPreviousColumn >= 0) {
        for (c1_p = c1_firstRunOnPreviousColumn; c1_p <
             c1_lastRunOnPreviousColumn; c1_p++) {
          c1_i20 = c1_endRow.size[0];
          if ((c1_c_k < 1) || (c1_c_k > c1_i20)) {
            emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i20, &c1_td_emlrtBCI,
              &c1_b_st);
          }

          c1_i22 = c1_startRow.size[0];
          if ((c1_p < 1) || (c1_p > c1_i22)) {
            emlrtDynamicBoundsCheckR2012b(c1_p, 1, c1_i22, &c1_ud_emlrtBCI,
              &c1_b_st);
          }

          if (c1_endRow.vector.data[c1_c_k - 1] >= c1_startRow.vector.data[c1_p
              - 1] - 1) {
            c1_i24 = c1_startRow.size[0];
            if ((c1_c_k < 1) || (c1_c_k > c1_i24)) {
              emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i24, &c1_vd_emlrtBCI,
                &c1_b_st);
            }

            c1_i26 = c1_endRow.size[0];
            if ((c1_p < 1) || (c1_p > c1_i26)) {
              emlrtDynamicBoundsCheckR2012b(c1_p, 1, c1_i26, &c1_wd_emlrtBCI,
                &c1_b_st);
            }

            if (c1_startRow.vector.data[c1_c_k - 1] <=
                c1_endRow.vector.data[c1_p - 1] + 1) {
              c1_i28 = c1_labelForEachRun.size[0];
              if ((c1_c_k < 1) || (c1_c_k > c1_i28)) {
                emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i28, &c1_xd_emlrtBCI,
                  &c1_b_st);
              }

              if (c1_labelForEachRun.vector.data[c1_c_k - 1] == 0) {
                c1_i31 = c1_labelForEachRun.size[0];
                if ((c1_p < 1) || (c1_p > c1_i31)) {
                  emlrtDynamicBoundsCheckR2012b(c1_p, 1, c1_i31, &c1_be_emlrtBCI,
                    &c1_b_st);
                }

                c1_i34 = c1_labelForEachRun.size[0];
                if ((c1_c_k < 1) || (c1_c_k > c1_i34)) {
                  emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i34,
                    &c1_ce_emlrtBCI, &c1_b_st);
                }

                c1_labelForEachRun.vector.data[c1_c_k - 1] =
                  c1_labelForEachRun.vector.data[c1_p - 1];
                c1_nextLabel++;
              } else {
                c1_i30 = c1_labelForEachRun.size[0];
                if ((c1_c_k < 1) || (c1_c_k > c1_i30)) {
                  emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i30,
                    &c1_yd_emlrtBCI, &c1_b_st);
                }

                c1_i33 = c1_labelForEachRun.size[0];
                if ((c1_p < 1) || (c1_p > c1_i33)) {
                  emlrtDynamicBoundsCheckR2012b(c1_p, 1, c1_i33, &c1_ae_emlrtBCI,
                    &c1_b_st);
                }

                if (c1_labelForEachRun.vector.data[c1_c_k - 1] !=
                    c1_labelForEachRun.vector.data[c1_p - 1]) {
                  c1_c_st.site = &c1_je_emlrtRSI;
                  c1_g_k = c1_c_k;
                  c1_b_p = c1_p;
                  c1_d_st.site = &c1_ke_emlrtRSI;
                  c1_node = c1_g_k;
                  c1_root_k = c1_node;
                  do {
                    c1_exitg1 = 0;
                    c1_i36 = c1_labelForEachRun.size[0];
                    if ((c1_root_k < 1) || (c1_root_k > c1_i36)) {
                      emlrtDynamicBoundsCheckR2012b(c1_root_k, 1, c1_i36,
                        &c1_ie_emlrtBCI, &c1_d_st);
                    }

                    if (c1_root_k != c1_labelForEachRun.vector.data[c1_root_k -
                        1]) {
                      c1_i38 = c1_labelForEachRun.size[0];
                      c1_i39 = c1_labelForEachRun.size[0];
                      if ((c1_root_k < 1) || (c1_root_k > c1_i39)) {
                        emlrtDynamicBoundsCheckR2012b(c1_root_k, 1, c1_i39,
                          &c1_ke_emlrtBCI, &c1_d_st);
                      }

                      c1_i40 = c1_labelForEachRun.vector.data[c1_root_k - 1];
                      if ((c1_i40 < 1) || (c1_i40 > c1_i38)) {
                        emlrtDynamicBoundsCheckR2012b(c1_i40, 1, c1_i38,
                          &c1_je_emlrtBCI, &c1_d_st);
                      }

                      c1_i42 = c1_labelForEachRun.size[0];
                      if ((c1_root_k < 1) || (c1_root_k > c1_i42)) {
                        emlrtDynamicBoundsCheckR2012b(c1_root_k, 1, c1_i42,
                          &c1_le_emlrtBCI, &c1_d_st);
                      }

                      c1_labelForEachRun.vector.data[c1_root_k - 1] =
                        c1_labelForEachRun.vector.data[c1_i40 - 1];
                      c1_i44 = c1_labelForEachRun.size[0];
                      if ((c1_root_k < 1) || (c1_root_k > c1_i44)) {
                        emlrtDynamicBoundsCheckR2012b(c1_root_k, 1, c1_i44,
                          &c1_me_emlrtBCI, &c1_d_st);
                      }

                      c1_root_k = c1_labelForEachRun.vector.data[c1_root_k - 1];
                    } else {
                      c1_exitg1 = 1;
                    }
                  } while (c1_exitg1 == 0);

                  c1_d_st.site = &c1_le_emlrtRSI;
                  c1_b_node = c1_b_p;
                  c1_root_p = c1_b_node;
                  do {
                    c1_exitg1 = 0;
                    c1_i43 = c1_labelForEachRun.size[0];
                    if ((c1_root_p < 1) || (c1_root_p > c1_i43)) {
                      emlrtDynamicBoundsCheckR2012b(c1_root_p, 1, c1_i43,
                        &c1_ie_emlrtBCI, &c1_d_st);
                    }

                    if (c1_root_p != c1_labelForEachRun.vector.data[c1_root_p -
                        1]) {
                      c1_i45 = c1_labelForEachRun.size[0];
                      c1_i46 = c1_labelForEachRun.size[0];
                      if ((c1_root_p < 1) || (c1_root_p > c1_i46)) {
                        emlrtDynamicBoundsCheckR2012b(c1_root_p, 1, c1_i46,
                          &c1_ke_emlrtBCI, &c1_d_st);
                      }

                      c1_i47 = c1_labelForEachRun.vector.data[c1_root_p - 1];
                      if ((c1_i47 < 1) || (c1_i47 > c1_i45)) {
                        emlrtDynamicBoundsCheckR2012b(c1_i47, 1, c1_i45,
                          &c1_je_emlrtBCI, &c1_d_st);
                      }

                      c1_i48 = c1_labelForEachRun.size[0];
                      if ((c1_root_p < 1) || (c1_root_p > c1_i48)) {
                        emlrtDynamicBoundsCheckR2012b(c1_root_p, 1, c1_i48,
                          &c1_le_emlrtBCI, &c1_d_st);
                      }

                      c1_labelForEachRun.vector.data[c1_root_p - 1] =
                        c1_labelForEachRun.vector.data[c1_i47 - 1];
                      c1_i52 = c1_labelForEachRun.size[0];
                      if ((c1_root_p < 1) || (c1_root_p > c1_i52)) {
                        emlrtDynamicBoundsCheckR2012b(c1_root_p, 1, c1_i52,
                          &c1_me_emlrtBCI, &c1_d_st);
                      }

                      c1_root_p = c1_labelForEachRun.vector.data[c1_root_p - 1];
                    } else {
                      c1_exitg1 = 1;
                    }
                  } while (c1_exitg1 == 0);

                  if (c1_root_k != c1_root_p) {
                    c1_d_st.site = &c1_me_emlrtRSI;
                    c1_b_root_k = c1_root_k;
                    c1_b_root_p = c1_root_p;
                    c1_i_k = c1_g_k;
                    c1_c_p = c1_b_p;
                    if (c1_b_root_p < c1_b_root_k) {
                      c1_i51 = c1_labelForEachRun.size[0];
                      if ((c1_b_root_k < 1) || (c1_b_root_k > c1_i51)) {
                        emlrtDynamicBoundsCheckR2012b(c1_b_root_k, 1, c1_i51,
                          &c1_oe_emlrtBCI, &c1_d_st);
                      }

                      c1_labelForEachRun.vector.data[c1_b_root_k - 1] =
                        c1_b_root_p;
                      c1_i54 = c1_labelForEachRun.size[0];
                      if ((c1_i_k < 1) || (c1_i_k > c1_i54)) {
                        emlrtDynamicBoundsCheckR2012b(c1_i_k, 1, c1_i54,
                          &c1_qe_emlrtBCI, &c1_d_st);
                      }

                      c1_labelForEachRun.vector.data[c1_i_k - 1] = c1_b_root_p;
                    } else {
                      c1_i50 = c1_labelForEachRun.size[0];
                      if ((c1_b_root_p < 1) || (c1_b_root_p > c1_i50)) {
                        emlrtDynamicBoundsCheckR2012b(c1_b_root_p, 1, c1_i50,
                          &c1_ne_emlrtBCI, &c1_d_st);
                      }

                      c1_labelForEachRun.vector.data[c1_b_root_p - 1] =
                        c1_b_root_k;
                      c1_i53 = c1_labelForEachRun.size[0];
                      if ((c1_c_p < 1) || (c1_c_p > c1_i53)) {
                        emlrtDynamicBoundsCheckR2012b(c1_c_p, 1, c1_i53,
                          &c1_pe_emlrtBCI, &c1_d_st);
                      }

                      c1_labelForEachRun.vector.data[c1_c_p - 1] = c1_b_root_k;
                    }
                  }
                }
              }
            }
          }
        }
      }

      c1_i17 = c1_labelForEachRun.size[0];
      if ((c1_c_k < 1) || (c1_c_k > c1_i17)) {
        emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i17, &c1_rd_emlrtBCI,
          &c1_b_st);
      }

      if (c1_labelForEachRun.vector.data[c1_c_k - 1] == 0) {
        c1_i21 = c1_labelForEachRun.size[0];
        if ((c1_c_k < 1) || (c1_c_k > c1_i21)) {
          emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i21, &c1_sd_emlrtBCI,
            &c1_b_st);
        }

        c1_labelForEachRun.vector.data[c1_c_k - 1] = c1_nextLabel;
        c1_nextLabel++;
      }

      c1_c_k++;
    }
  }

  c1_array_real_T_Constructor(chartInstance, &c1_r);
  c1_array_cell_wrap_46_2D_Construct(chartInstance, &c1_r1);
  if (c1_numRuns == 0) {
    c1_d1 = 0.0;
    c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_r, &c1_xd_emlrtRTEI, 0);
    c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_labelForEachRun,
      &c1_yd_emlrtRTEI, 1);
    c1_labelForEachRun.vector.data[0] = 0;
    c1_array_cell_wrap_46_2D_SetSize(chartInstance, &c1_st, &c1_r1,
      &c1_ae_emlrtRTEI, 1, 0);
  } else {
    c1_array_int32_T_Constructor(chartInstance, &c1_labelsRenumbered);
    c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_labelsRenumbered,
      &c1_od_emlrtRTEI, c1_labelForEachRun.size[0]);
    c1_numComponents = 0.0;
    c1_b_st.site = &c1_ge_emlrtRSI;
    c1_b = c1_numRuns;
    c1_b_b = c1_b;
    if (c1_b_b < 1) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_c_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
    }

    for (c1_d_k = 0; c1_d_k < c1_numRuns; c1_d_k++) {
      c1_e_k = c1_d_k + 1;
      c1_i6 = c1_labelForEachRun.size[0];
      if ((c1_e_k < 1) || (c1_e_k > c1_i6)) {
        emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i6, &c1_jd_emlrtBCI, &c1_st);
      }

      if (c1_labelForEachRun.vector.data[c1_e_k - 1] == c1_e_k) {
        c1_numComponents++;
        c1_i11 = c1_labelsRenumbered.size[0];
        if ((c1_e_k < 1) || (c1_e_k > c1_i11)) {
          emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i11, &c1_qd_emlrtBCI,
            &c1_st);
        }

        c1_labelsRenumbered.vector.data[c1_e_k - 1] = (int32_T)c1_numComponents;
      }

      c1_i10 = c1_labelsRenumbered.size[0];
      c1_i14 = c1_labelForEachRun.size[0];
      if ((c1_e_k < 1) || (c1_e_k > c1_i14)) {
        emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i14, &c1_od_emlrtBCI, &c1_st);
      }

      c1_i15 = c1_labelForEachRun.vector.data[c1_e_k - 1];
      if ((c1_i15 < 1) || (c1_i15 > c1_i10)) {
        emlrtDynamicBoundsCheckR2012b(c1_i15, 1, c1_i10, &c1_nd_emlrtBCI, &c1_st);
      }

      c1_i19 = c1_labelsRenumbered.size[0];
      if ((c1_e_k < 1) || (c1_e_k > c1_i19)) {
        emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i19, &c1_pd_emlrtBCI, &c1_st);
      }

      c1_labelsRenumbered.vector.data[c1_e_k - 1] =
        c1_labelsRenumbered.vector.data[c1_i15 - 1];
    }

    if (c1_numComponents != (real_T)(int32_T)muDoubleScalarFloor
        (c1_numComponents)) {
      emlrtIntegerCheckR2012b(c1_numComponents, &c1_h_emlrtDCI, &c1_st);
    }

    c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_labelForEachRun,
      &c1_pd_emlrtRTEI, (int32_T)c1_numComponents);
    if (c1_numComponents != (real_T)(int32_T)muDoubleScalarFloor
        (c1_numComponents)) {
      emlrtIntegerCheckR2012b(c1_numComponents, &c1_h_emlrtDCI, &c1_st);
    }

    c1_c_loop_ub = (int32_T)c1_numComponents - 1;
    for (c1_i9 = 0; c1_i9 <= c1_c_loop_ub; c1_i9++) {
      c1_labelForEachRun.vector.data[c1_i9] = 0;
    }

    c1_b_st.site = &c1_fe_emlrtRSI;
    c1_c_b = c1_numRuns;
    c1_d_b = c1_c_b;
    if (c1_d_b < 1) {
      c1_b_overflow = false;
    } else {
      c1_b_overflow = (c1_d_b > 2147483646);
    }

    if (c1_b_overflow) {
      c1_c_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
    }

    for (c1_f_k = 0; c1_f_k < c1_numRuns; c1_f_k++) {
      c1_e_k = c1_f_k + 1;
      c1_i23 = c1_labelsRenumbered.size[0];
      if ((c1_e_k < 1) || (c1_e_k > c1_i23)) {
        emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i23, &c1_de_emlrtBCI, &c1_st);
      }

      c1_idx = c1_labelsRenumbered.vector.data[c1_e_k - 1];
      c1_i25 = c1_labelForEachRun.size[0];
      if ((c1_idx < 1) || (c1_idx > c1_i25)) {
        emlrtDynamicBoundsCheckR2012b(c1_idx, 1, c1_i25, &c1_ee_emlrtBCI, &c1_st);
      }

      c1_i27 = c1_endRow.size[0];
      if ((c1_e_k < 1) || (c1_e_k > c1_i27)) {
        emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i27, &c1_fe_emlrtBCI, &c1_st);
      }

      c1_i29 = c1_startRow.size[0];
      if ((c1_e_k < 1) || (c1_e_k > c1_i29)) {
        emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i29, &c1_ge_emlrtBCI, &c1_st);
      }

      c1_i32 = c1_labelForEachRun.size[0];
      if ((c1_idx < 1) || (c1_idx > c1_i32)) {
        emlrtDynamicBoundsCheckR2012b(c1_idx, 1, c1_i32, &c1_he_emlrtBCI, &c1_st);
      }

      c1_labelForEachRun.vector.data[c1_idx - 1] =
        ((c1_labelForEachRun.vector.data[c1_idx - 1] +
          c1_endRow.vector.data[c1_e_k - 1]) - c1_startRow.vector.data[c1_e_k -
         1]) + 1;
    }

    c1_d1 = c1_numComponents;
    c1_b_st.site = &c1_ee_emlrtRSI;
    c1_c_st.site = &c1_ne_emlrtRSI;
    c1_d_st.site = &c1_oe_emlrtRSI;
    c1_vlen = c1_labelForEachRun.size[0];
    c1_e_st.site = &c1_pe_emlrtRSI;
    c1_b_vlen = c1_vlen;
    if ((c1_labelForEachRun.size[0] == 0) || (c1_b_vlen == 0)) {
      c1_b_y = 0.0;
    } else {
      c1_f_st.site = &c1_qe_emlrtRSI;
      c1_c_vlen = c1_b_vlen;
      c1_g_st.site = &c1_re_emlrtRSI;
      c1_d_vlen = c1_c_vlen;
      if (c1_d_vlen < 4096) {
        c1_h_st.site = &c1_se_emlrtRSI;
        c1_b_y = c1_sumColumnB(chartInstance, &c1_h_st, &c1_labelForEachRun,
          c1_d_vlen);
      } else {
        c1_c_a = c1_d_vlen;
        c1_nfb = (int32_T)((uint32_T)c1_c_a >> 12);
        c1_inb = c1_nfb << 12;
        c1_lidx = c1_inb;
        c1_nleft = c1_d_vlen - c1_inb;
        c1_b_s = c1_sumColumnB4(chartInstance, &c1_labelForEachRun, 1);
        for (c1_ib = 2; c1_ib <= c1_nfb; c1_ib++) {
          c1_b_s += c1_sumColumnB4(chartInstance, &c1_labelForEachRun, 1 +
            ((c1_ib - 1) << 12));
        }

        if (c1_nleft > 0) {
          c1_h_st.site = &c1_te_emlrtRSI;
          c1_b_s += c1_b_sumColumnB(chartInstance, &c1_h_st, &c1_labelForEachRun,
            c1_nleft, c1_lidx + 1);
        }

        c1_b_y = c1_b_s;
      }
    }

    if (!(c1_b_y >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c1_b_y, &c1_j_emlrtDCI, &c1_st);
    }

    c1_d2 = c1_b_y;
    if (c1_d2 != (real_T)(int32_T)muDoubleScalarFloor(c1_d2)) {
      emlrtIntegerCheckR2012b(c1_d2, &c1_i_emlrtDCI, &c1_st);
    }

    c1_b_iv[0] = (int32_T)c1_d2;
    c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_r, &c1_qd_emlrtRTEI,
      c1_b_iv[0]);
    c1_array_int32_T_Constructor(chartInstance, &c1_b_x);
    c1_b_st.site = &c1_de_emlrtRSI;
    c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_b_x, &c1_rd_emlrtRTEI,
      c1_labelForEachRun.size[0]);
    c1_f_loop_ub = c1_labelForEachRun.size[0] - 1;
    for (c1_i35 = 0; c1_i35 <= c1_f_loop_ub; c1_i35++) {
      c1_b_x.vector.data[c1_i35] = c1_labelForEachRun.vector.data[c1_i35];
    }

    c1_c_st.site = &c1_xe_emlrtRSI;
    c1_dim = 2;
    if ((real_T)c1_b_x.size[0] != 1.0) {
      c1_dim = 1;
    }

    c1_array_int32_T_Constructor(chartInstance, &c1_c_x);
    c1_array_int32_T_SetSize(chartInstance, &c1_c_st, &c1_c_x, &c1_dd_emlrtRTEI,
      c1_b_x.size[0]);
    c1_g_loop_ub = c1_b_x.size[0] - 1;
    for (c1_i37 = 0; c1_i37 <= c1_g_loop_ub; c1_i37++) {
      c1_c_x.vector.data[c1_i37] = c1_b_x.vector.data[c1_i37];
    }

    c1_d_st.site = &c1_ye_emlrtRSI;
    c1_useConstantDim(chartInstance, &c1_d_st, &c1_c_x, c1_dim, &c1_b_x);
    c1_array_int32_T_Destructor(chartInstance, &c1_c_x);
    c1_array_int32_T_Constructor(chartInstance, &c1_idxCount);
    c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_idxCount,
      &c1_sd_emlrtRTEI, 1 + c1_b_x.size[0]);
    c1_idxCount.vector.data[0] = 0;
    c1_h_loop_ub = c1_b_x.size[0] - 1;
    for (c1_i41 = 0; c1_i41 <= c1_h_loop_ub; c1_i41++) {
      c1_idxCount.vector.data[c1_i41 + 1] = c1_b_x.vector.data[c1_i41];
    }

    c1_b_st.site = &c1_ce_emlrtRSI;
    c1_e_b = c1_numRuns;
    c1_f_b = c1_e_b;
    if (c1_f_b < 1) {
      c1_c_overflow = false;
    } else {
      c1_c_overflow = (c1_f_b > 2147483646);
    }

    if (c1_c_overflow) {
      c1_c_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
    }

    for (c1_h_k = 0; c1_h_k < c1_numRuns; c1_h_k++) {
      c1_e_k = c1_h_k + 1;
      c1_i49 = c1_startCol.size[0];
      if ((c1_e_k < 1) || (c1_e_k > c1_i49)) {
        emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i49, &c1_re_emlrtBCI, &c1_st);
      }

      c1_d_a = c1_startCol.vector.data[c1_e_k - 1] - 1;
      c1_c = c1_d_a;
      c1_e_a = c1_c;
      c1_column_offset = c1_e_a * 120;
      c1_i55 = c1_labelsRenumbered.size[0];
      if ((c1_e_k < 1) || (c1_e_k > c1_i55)) {
        emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i55, &c1_se_emlrtBCI, &c1_st);
      }

      c1_idx = c1_labelsRenumbered.vector.data[c1_e_k - 1];
      c1_i57 = c1_startRow.size[0];
      if ((c1_e_k < 1) || (c1_e_k > c1_i57)) {
        emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i57, &c1_te_emlrtBCI, &c1_st);
      }

      c1_i58 = c1_startRow.vector.data[c1_e_k - 1];
      c1_i59 = c1_endRow.size[0];
      if ((c1_e_k < 1) || (c1_e_k > c1_i59)) {
        emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i59, &c1_ue_emlrtBCI, &c1_st);
      }

      c1_i60 = c1_endRow.vector.data[c1_e_k - 1];
      c1_b_st.site = &c1_be_emlrtRSI;
      c1_f_a = c1_i58;
      c1_g_b = c1_i60;
      c1_g_a = c1_f_a;
      c1_h_b = c1_g_b;
      if (c1_g_a > c1_h_b) {
        c1_d_overflow = false;
      } else {
        c1_d_overflow = (c1_h_b > 2147483646);
      }

      if (c1_d_overflow) {
        c1_c_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
      }

      for (c1_rowidx = c1_i58; c1_rowidx <= c1_i60; c1_rowidx++) {
        c1_i64 = c1_idxCount.size[0];
        if ((c1_idx < 1) || (c1_idx > c1_i64)) {
          emlrtDynamicBoundsCheckR2012b(c1_idx, 1, c1_i64, &c1_xe_emlrtBCI,
            &c1_st);
        }

        c1_h_a = c1_idxCount.vector.data[c1_idx - 1] + 1;
        c1_b_c = c1_h_a;
        c1_i66 = c1_idxCount.size[0];
        if ((c1_idx < 1) || (c1_idx > c1_i66)) {
          emlrtDynamicBoundsCheckR2012b(c1_idx, 1, c1_i66, &c1_ye_emlrtBCI,
            &c1_st);
        }

        c1_idxCount.vector.data[c1_idx - 1] = c1_b_c;
        c1_i69 = c1_r.size[0];
        c1_i71 = c1_idxCount.size[0];
        if ((c1_idx < 1) || (c1_idx > c1_i71)) {
          emlrtDynamicBoundsCheckR2012b(c1_idx, 1, c1_i71, &c1_bf_emlrtBCI,
            &c1_st);
        }

        c1_i73 = c1_idxCount.vector.data[c1_idx - 1];
        if ((c1_i73 < 1) || (c1_i73 > c1_i69)) {
          emlrtDynamicBoundsCheckR2012b(c1_i73, 1, c1_i69, &c1_af_emlrtBCI,
            &c1_st);
        }

        c1_r.vector.data[c1_i73 - 1] = (real_T)(c1_rowidx + c1_column_offset);
      }
    }

    c1_array_int32_T_Destructor(chartInstance, &c1_labelsRenumbered);
    c1_array_cell_wrap_46_Constructor(chartInstance, &c1_r2);
    c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_r2.f1, &c1_td_emlrtRTEI,
      0);
    c1_array_cell_wrap_46_1s_Construct(chartInstance, c1_rv);
    c1_array_cell_wrap_46_Copy(chartInstance, &c1_st, &c1_rv[0], &c1_r2,
      &c1_td_emlrtRTEI);
    c1_array_cell_wrap_46_Destructor(chartInstance, &c1_r2);
    c1_b_st.site = &c1_ae_emlrtRSI;
    c1_repmat(chartInstance, &c1_b_st, c1_rv, c1_numComponents, &c1_r1);
    c1_array_cell_wrap_46_1s_Destructo(chartInstance, c1_rv);
    c1_b_st.site = &c1_yd_emlrtRSI;
    c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_b_x, &c1_ud_emlrtRTEI,
      c1_labelForEachRun.size[0]);
    c1_i_loop_ub = c1_labelForEachRun.size[0] - 1;
    for (c1_i56 = 0; c1_i56 <= c1_i_loop_ub; c1_i56++) {
      c1_b_x.vector.data[c1_i56] = c1_labelForEachRun.vector.data[c1_i56];
    }

    c1_c_st.site = &c1_xe_emlrtRSI;
    c1_b_dim = 2;
    if ((real_T)c1_b_x.size[0] != 1.0) {
      c1_b_dim = 1;
    }

    c1_array_int32_T_Constructor(chartInstance, &c1_d_x);
    c1_array_int32_T_SetSize(chartInstance, &c1_c_st, &c1_d_x, &c1_dd_emlrtRTEI,
      c1_b_x.size[0]);
    c1_j_loop_ub = c1_b_x.size[0] - 1;
    for (c1_i61 = 0; c1_i61 <= c1_j_loop_ub; c1_i61++) {
      c1_d_x.vector.data[c1_i61] = c1_b_x.vector.data[c1_i61];
    }

    c1_d_st.site = &c1_ye_emlrtRSI;
    c1_useConstantDim(chartInstance, &c1_d_st, &c1_d_x, c1_b_dim, &c1_b_x);
    c1_array_int32_T_Destructor(chartInstance, &c1_d_x);
    c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_idxCount,
      &c1_vd_emlrtRTEI, 1 + c1_b_x.size[0]);
    c1_idxCount.vector.data[0] = 0;
    c1_k_loop_ub = c1_b_x.size[0] - 1;
    for (c1_i62 = 0; c1_i62 <= c1_k_loop_ub; c1_i62++) {
      c1_idxCount.vector.data[c1_i62 + 1] = c1_b_x.vector.data[c1_i62];
    }

    c1_array_int32_T_Destructor(chartInstance, &c1_b_x);
    c1_i63 = (int32_T)c1_numComponents;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c1_numComponents, mxDOUBLE_CLASS,
      c1_i63, &c1_ii_emlrtRTEI, &c1_st);
    for (c1_j_k = 0; c1_j_k < c1_i63; c1_j_k++) {
      c1_k_k = (real_T)c1_j_k + 1.0;
      c1_i65 = c1_idxCount.size[0];
      c1_i67 = (int32_T)c1_k_k;
      if ((c1_i67 < 1) || (c1_i67 > c1_i65)) {
        emlrtDynamicBoundsCheckR2012b(c1_i67, 1, c1_i65, &c1_ve_emlrtBCI, &c1_st);
      }

      c1_i68 = c1_idxCount.vector.data[c1_i67 - 1] + 1;
      c1_i70 = c1_idxCount.size[0];
      c1_i72 = (int32_T)(c1_k_k + 1.0);
      if ((c1_i72 < 1) || (c1_i72 > c1_i70)) {
        emlrtDynamicBoundsCheckR2012b(c1_i72, 1, c1_i70, &c1_we_emlrtBCI, &c1_st);
      }

      c1_i74 = c1_idxCount.vector.data[c1_i72 - 1];
      c1_i_b = (c1_i68 > c1_i74);
      if (c1_i_b) {
        c1_i76 = 0;
        c1_i77 = -1;
      } else {
        c1_i75 = c1_r.size[0];
        if ((c1_i68 < 1) || (c1_i68 > c1_i75)) {
          emlrtDynamicBoundsCheckR2012b(c1_i68, 1, c1_i75, &c1_ed_emlrtBCI,
            &c1_st);
        }

        c1_i76 = c1_i68 - 1;
        c1_i79 = c1_r.size[0];
        if ((c1_i74 < 1) || (c1_i74 > c1_i79)) {
          emlrtDynamicBoundsCheckR2012b(c1_i74, 1, c1_i79, &c1_dd_emlrtBCI,
            &c1_st);
        }

        c1_i77 = c1_i74 - 1;
      }

      c1_i78 = c1_r1.size[1] - 1;
      c1_i80 = (int32_T)c1_k_k - 1;
      if ((c1_i80 < 0) || (c1_i80 > c1_i78)) {
        emlrtDynamicBoundsCheckR2012b(c1_i80, 0, c1_i78, &c1_cf_emlrtBCI, &c1_st);
      }

      c1_array_real_T_SetSize(chartInstance, &c1_st,
        &c1_r1.vector.data[c1_r1.size[0] * c1_i80].f1, &c1_wd_emlrtRTEI, (c1_i77
        - c1_i76) + 1);
      c1_l_loop_ub = c1_i77 - c1_i76;
      for (c1_i81 = 0; c1_i81 <= c1_l_loop_ub; c1_i81++) {
        c1_i82 = c1_r1.size[1] - 1;
        c1_i83 = (int32_T)c1_k_k - 1;
        if ((c1_i83 < 0) || (c1_i83 > c1_i82)) {
          emlrtDynamicBoundsCheckR2012b(c1_i83, 0, c1_i82, &c1_cf_emlrtBCI,
            &c1_st);
        }

        c1_r1.vector.data[c1_i83].f1.vector.data[c1_i81] =
          c1_r.vector.data[c1_i76 + c1_i81];
      }
    }

    c1_array_int32_T_Destructor(chartInstance, &c1_idxCount);
  }

  c1_array_int32_T_Destructor(chartInstance, &c1_startCol);
  c1_array_int32_T_Destructor(chartInstance, &c1_endRow);
  c1_array_int32_T_Destructor(chartInstance, &c1_startRow);
  c1_CC->NumObjects = c1_d1;
  c1_st.site = &c1_xd_emlrtRSI;
  c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_CC->RegionIndices,
    &c1_be_emlrtRTEI, c1_r.size[0]);
  c1_b_loop_ub = c1_r.size[0] - 1;
  for (c1_i5 = 0; c1_i5 <= c1_b_loop_ub; c1_i5++) {
    c1_CC->RegionIndices.vector.data[c1_i5] = c1_r.vector.data[c1_i5];
  }

  c1_array_real_T_Destructor(chartInstance, &c1_r);
  c1_st.site = &c1_xd_emlrtRSI;
  c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_CC->RegionLengths,
    &c1_ce_emlrtRTEI, c1_labelForEachRun.size[0]);
  c1_d_loop_ub = c1_labelForEachRun.size[0] - 1;
  for (c1_i12 = 0; c1_i12 <= c1_d_loop_ub; c1_i12++) {
    c1_CC->RegionLengths.vector.data[c1_i12] =
      c1_labelForEachRun.vector.data[c1_i12];
  }

  c1_array_int32_T_Destructor(chartInstance, &c1_labelForEachRun);
  c1_st.site = &c1_xd_emlrtRSI;
  c1_array_cell_wrap_46_2D_SetSize(chartInstance, &c1_st, &c1_CC->PixelIdxList,
    &c1_de_emlrtRTEI, 1, c1_r1.size[1]);
  c1_e_loop_ub = c1_r1.size[1] - 1;
  for (c1_i18 = 0; c1_i18 <= c1_e_loop_ub; c1_i18++) {
    c1_st.site = &c1_xd_emlrtRSI;
    c1_array_cell_wrap_46_Copy(chartInstance, &c1_st,
      &c1_CC->PixelIdxList.vector.data[c1_i18], &c1_r1.vector.data[c1_i18],
      &c1_de_emlrtRTEI);
  }

  c1_array_cell_wrap_46_2D_Destructo(chartInstance, &c1_r1);
}

static real_T c1_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T *c1_b_x,
  int32_T c1_vlen)
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  real_T c1_b_y;
  real_T c1_c_y;
  real_T c1_d_y;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_b_vlen;
  int32_T c1_b_vstart;
  int32_T c1_c_a;
  int32_T c1_c_b;
  int32_T c1_c_k;
  int32_T c1_c_vlen;
  int32_T c1_d_b;
  int32_T c1_d_k;
  int32_T c1_e_k;
  int32_T c1_f_k;
  int32_T c1_g_k;
  int32_T c1_h_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i_k;
  int32_T c1_inb;
  int32_T c1_k;
  int32_T c1_lidx;
  int32_T c1_nfb;
  int32_T c1_nleft;
  int32_T c1_vstart;
  boolean_T c1_b_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  if (c1_vlen <= 1024) {
    c1_st.site = &c1_ue_emlrtRSI;
    c1_b_vlen = c1_vlen - 1;
    c1_b_y = (real_T)c1_b_x->vector.data[0];
    c1_i = c1_b_vlen;
    c1_b_st.site = &c1_we_emlrtRSI;
    c1_b = c1_i;
    c1_b_b = c1_b;
    if (c1_b_b < 1) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_c_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
    }

    c1_i1 = (uint16_T)c1_i - 1;
    for (c1_f_k = 0; c1_f_k <= c1_i1; c1_f_k++) {
      c1_g_k = c1_f_k;
      c1_b_y += (real_T)c1_b_x->vector.data[c1_g_k + 1];
    }
  } else {
    c1_c_a = c1_vlen;
    c1_nfb = (int32_T)((uint32_T)c1_c_a >> 10);
    c1_inb = c1_nfb << 10;
    c1_b_y = (real_T)c1_b_x->vector.data[0];
    for (c1_k = 0; c1_k < 1023; c1_k++) {
      c1_c_k = c1_k;
      c1_b_y += (real_T)c1_b_x->vector.data[c1_c_k + 1];
    }

    for (c1_b_k = 2; c1_b_k <= c1_nfb; c1_b_k++) {
      c1_vstart = (c1_b_k - 1) << 10;
      c1_c_y = (real_T)c1_b_x->vector.data[c1_vstart];
      for (c1_d_k = 0; c1_d_k < 1023; c1_d_k++) {
        c1_e_k = c1_d_k;
        c1_c_y += (real_T)c1_b_x->vector.data[(c1_vstart + c1_e_k) + 1];
      }

      c1_b_y += c1_c_y;
    }

    if (c1_vlen > c1_inb) {
      c1_nleft = c1_vlen - c1_inb;
      c1_lidx = c1_inb;
      c1_st.site = &c1_ve_emlrtRSI;
      c1_c_vlen = c1_nleft - 1;
      c1_b_vstart = c1_lidx;
      c1_d_y = (real_T)c1_b_x->vector.data[c1_b_vstart];
      c1_i2 = c1_c_vlen;
      c1_b_st.site = &c1_we_emlrtRSI;
      c1_c_b = c1_i2;
      c1_d_b = c1_c_b;
      if (c1_d_b < 1) {
        c1_b_overflow = false;
      } else {
        c1_b_overflow = (c1_d_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_c_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
      }

      for (c1_h_k = 0; c1_h_k < c1_i2; c1_h_k++) {
        c1_i_k = c1_h_k;
        c1_d_y += (real_T)c1_b_x->vector.data[(c1_b_vstart + c1_i_k) + 1];
      }

      c1_b_y += c1_d_y;
    }
  }

  return c1_b_y;
}

static real_T c1_sumColumnB4(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_int32_T *c1_b_x, int32_T c1_vstart)
{
  real_T c1_psum1;
  real_T c1_psum2;
  real_T c1_psum3;
  real_T c1_psum4;
  int32_T c1_b_k;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_k;
  (void)chartInstance;
  c1_i2 = c1_vstart + 1023;
  c1_i3 = c1_vstart + 2047;
  c1_i4 = c1_vstart + 3071;
  c1_psum1 = (real_T)c1_b_x->vector.data[c1_vstart - 1];
  c1_psum2 = (real_T)c1_b_x->vector.data[c1_i2];
  c1_psum3 = (real_T)c1_b_x->vector.data[c1_i3];
  c1_psum4 = (real_T)c1_b_x->vector.data[c1_i4];
  for (c1_k = 0; c1_k < 1023; c1_k++) {
    c1_b_k = c1_k + 1;
    c1_psum1 += (real_T)c1_b_x->vector.data[(c1_vstart + c1_b_k) - 1];
    c1_psum2 += (real_T)c1_b_x->vector.data[c1_i2 + c1_b_k];
    c1_psum3 += (real_T)c1_b_x->vector.data[c1_i3 + c1_b_k];
    c1_psum4 += (real_T)c1_b_x->vector.data[c1_i4 + c1_b_k];
  }

  return (c1_psum1 + c1_psum2) + (c1_psum3 + c1_psum4);
}

static real_T c1_b_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T *c1_b_x,
  int32_T c1_vlen, int32_T c1_vstart)
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  real_T c1_b_y;
  real_T c1_c_y;
  real_T c1_d_y;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_b_vlen;
  int32_T c1_b_vstart;
  int32_T c1_c_a;
  int32_T c1_c_b;
  int32_T c1_c_k;
  int32_T c1_c_vlen;
  int32_T c1_c_vstart;
  int32_T c1_d_b;
  int32_T c1_d_k;
  int32_T c1_d_vstart;
  int32_T c1_e_k;
  int32_T c1_e_vstart;
  int32_T c1_f_k;
  int32_T c1_g_k;
  int32_T c1_h_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i_k;
  int32_T c1_inb;
  int32_T c1_k;
  int32_T c1_lidx;
  int32_T c1_nfb;
  int32_T c1_nleft;
  boolean_T c1_b_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  if (c1_vlen <= 1024) {
    c1_st.site = &c1_ue_emlrtRSI;
    c1_b_vlen = c1_vlen - 1;
    c1_b_vstart = c1_vstart - 1;
    c1_b_y = (real_T)c1_b_x->vector.data[c1_b_vstart];
    c1_i = c1_b_vlen;
    c1_b_st.site = &c1_we_emlrtRSI;
    c1_b = c1_i;
    c1_b_b = c1_b;
    if (c1_b_b < 1) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_c_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
    }

    for (c1_f_k = 0; c1_f_k < c1_i; c1_f_k++) {
      c1_g_k = c1_f_k;
      c1_b_y += (real_T)c1_b_x->vector.data[(c1_b_vstart + c1_g_k) + 1];
    }
  } else {
    c1_c_a = c1_vlen;
    c1_nfb = (int32_T)((uint32_T)c1_c_a >> 10);
    c1_inb = c1_nfb << 10;
    c1_c_vstart = c1_vstart - 1;
    c1_b_y = (real_T)c1_b_x->vector.data[c1_c_vstart];
    for (c1_k = 0; c1_k < 1023; c1_k++) {
      c1_c_k = c1_k;
      c1_b_y += (real_T)c1_b_x->vector.data[(c1_c_vstart + c1_c_k) + 1];
    }

    for (c1_b_k = 2; c1_b_k <= c1_nfb; c1_b_k++) {
      c1_d_vstart = (c1_vstart + ((c1_b_k - 1) << 10)) - 1;
      c1_c_y = (real_T)c1_b_x->vector.data[c1_d_vstart];
      for (c1_d_k = 0; c1_d_k < 1023; c1_d_k++) {
        c1_e_k = c1_d_k;
        c1_c_y += (real_T)c1_b_x->vector.data[(c1_d_vstart + c1_e_k) + 1];
      }

      c1_b_y += c1_c_y;
    }

    if (c1_vlen > c1_inb) {
      c1_nleft = c1_vlen - c1_inb;
      c1_lidx = c1_vstart + c1_inb;
      c1_st.site = &c1_ve_emlrtRSI;
      c1_c_vlen = c1_nleft - 1;
      c1_e_vstart = c1_lidx - 1;
      c1_d_y = (real_T)c1_b_x->vector.data[c1_e_vstart];
      c1_i1 = c1_c_vlen;
      c1_b_st.site = &c1_we_emlrtRSI;
      c1_c_b = c1_i1;
      c1_d_b = c1_c_b;
      if (c1_d_b < 1) {
        c1_b_overflow = false;
      } else {
        c1_b_overflow = (c1_d_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_c_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
      }

      for (c1_h_k = 0; c1_h_k < c1_i1; c1_h_k++) {
        c1_i_k = c1_h_k;
        c1_d_y += (real_T)c1_b_x->vector.data[(c1_e_vstart + c1_i_k) + 1];
      }

      c1_b_y += c1_d_y;
    }
  }

  return c1_b_y;
}

static void c1_useConstantDim(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T
  *c1_b_varargin_2, int32_T c1_varargin_3, c1_coder_array_int32_T
  *c1_varargout_1)
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_st;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_k;
  int32_T c1_loop_ub;
  int32_T c1_nx;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  if (c1_varargin_3 == 1) {
    c1_st.site = &c1_af_emlrtRSI;
    c1_array_int32_T_SetSize(chartInstance, &c1_st, c1_varargout_1,
      &c1_ee_emlrtRTEI, c1_b_varargin_2->size[0]);
    c1_b_loop_ub = c1_b_varargin_2->size[0] - 1;
    for (c1_i1 = 0; c1_i1 <= c1_b_loop_ub; c1_i1++) {
      c1_varargout_1->vector.data[c1_i1] = c1_b_varargin_2->vector.data[c1_i1];
    }

    c1_b_st.site = &c1_bf_emlrtRSI;
    if (c1_varargout_1->size[0] != 0) {
      c1_c_st.site = &c1_cf_emlrtRSI;
      c1_nx = c1_varargout_1->size[0] - 1;
      if (!((real_T)c1_varargout_1->size[0] == 1.0)) {
        c1_i2 = c1_nx;
        c1_d_st.site = &c1_df_emlrtRSI;
        c1_b = c1_i2;
        c1_b_b = c1_b;
        if (c1_b_b < 1) {
          c1_overflow = false;
        } else {
          c1_overflow = (c1_b_b > 2147483646);
        }

        if (c1_overflow) {
          c1_e_st.site = &c1_yc_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
        }

        for (c1_k = 0; c1_k < c1_i2; c1_k++) {
          c1_b_k = c1_k;
          c1_varargout_1->vector.data[c1_b_k + 1] += c1_varargout_1->
            vector.data[c1_b_k];
        }
      }
    }
  } else {
    c1_array_int32_T_SetSize(chartInstance, c1_sp, c1_varargout_1,
      &c1_ee_emlrtRTEI, c1_b_varargin_2->size[0]);
    c1_loop_ub = c1_b_varargin_2->size[0] - 1;
    for (c1_i = 0; c1_i <= c1_loop_ub; c1_i++) {
      c1_varargout_1->vector.data[c1_i] = c1_b_varargin_2->vector.data[c1_i];
    }
  }
}

static void c1_repmat(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, c1_cell_wrap_46 c1_c_a[1], real_T
                      c1_b_varargin_2, c1_coder_array_cell_wrap_46_2D *c1_b)
{
  c1_coder_array_boolean_T_2D c1_tile;
  c1_coder_array_cell_wrap_46_2D c1_r;
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  real_T c1_arg;
  real_T c1_b_arg;
  real_T c1_b_x;
  real_T c1_c_varargin_2;
  real_T c1_d_varargin_2;
  real_T c1_n;
  int32_T c1_outsize[2];
  int32_T c1_b_jtilecol;
  int32_T c1_b_loop_ub;
  int32_T c1_b_u;
  int32_T c1_c_u;
  int32_T c1_d_b;
  int32_T c1_e_b;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_ibtile;
  int32_T c1_jtilecol;
  int32_T c1_loop_ub;
  int32_T c1_ntilecols;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_c_b;
  boolean_T c1_c_p;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_st.site = &c1_ef_emlrtRSI;
  c1_c_varargin_2 = c1_b_varargin_2;
  c1_arg = c1_c_varargin_2;
  if (c1_arg != c1_arg) {
    c1_p = false;
  } else {
    c1_b_x = c1_arg;
    c1_b_b = muDoubleScalarIsInf(c1_b_x);
    if (c1_b_b) {
      c1_p = false;
    } else {
      c1_p = true;
    }
  }

  if (c1_p) {
    c1_b_arg = c1_c_varargin_2;
    if (c1_b_arg > 2.147483647E+9) {
      c1_b_p = false;
    } else {
      c1_b_p = true;
    }

    if (c1_b_p) {
      c1_c_b = true;
    } else {
      c1_c_b = false;
    }
  } else {
    c1_c_b = false;
  }

  if (!c1_c_b) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv6, 10, 0U, 1, 0U, 2, 1, 28),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv6, 10, 0U, 1, 0U, 2, 1, 28),
                  false);
    c1_b_u = MIN_int32_T;
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0, 0U, 0), false);
    c1_c_u = MAX_int32_T;
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0, 0U, 0), false);
    sf_mex_call(&c1_st, &c1_l_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 3U, 14, c1_c_y, 14, c1_d_y, 14, c1_g_y)));
  }

  c1_d_varargin_2 = c1_c_varargin_2;
  if (c1_d_varargin_2 <= 0.0) {
    c1_n = 0.0;
  } else {
    c1_n = c1_d_varargin_2;
  }

  if (!(c1_n <= 2.147483647E+9)) {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv5, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv5, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    sf_mex_call(&c1_st, &c1_m_emlrtMCI, "error", 0U, 2U, 14, c1_e_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_f_y)));
  }

  c1_array_boolean_T_2D_Constructor(chartInstance, &c1_tile);
  c1_st.site = &c1_pj_emlrtRSI;
  c1_array_boolean_T_2D_SetSize(chartInstance, &c1_st, &c1_tile,
    &c1_rc_emlrtRTEI, 1, (int32_T)c1_b_varargin_2);
  c1_loop_ub = (int32_T)c1_b_varargin_2 - 1;
  for (c1_i = 0; c1_i <= c1_loop_ub; c1_i++) {
    c1_tile.vector.data[c1_i] = false;
  }

  c1_outsize[0] = 1;
  c1_outsize[1] = c1_tile.size[1];
  if (!((real_T)c1_outsize[1] == (real_T)c1_tile.size[1])) {
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_cv4, 10, 0U, 1, 0U, 2, 1, 15),
                  false);
    sf_mex_call(c1_sp, &c1_k_emlrtMCI, "error", 0U, 1U, 14, c1_h_y);
  }

  c1_array_cell_wrap_46_2D_Construct(chartInstance, &c1_r);
  c1_st.site = &c1_dk_emlrtRSI;
  c1_array_cell_wrap_46_2D_SetSize(chartInstance, &c1_st, &c1_r,
    &c1_fe_emlrtRTEI, c1_outsize[0], c1_outsize[1]);
  c1_st.site = &c1_dk_emlrtRSI;
  c1_array_cell_wrap_46_2D_SetSize(chartInstance, &c1_st, c1_b, &c1_ge_emlrtRTEI,
    1, c1_r.size[1]);
  c1_array_cell_wrap_46_2D_Destructo(chartInstance, &c1_r);
  if (c1_outsize[1] == 0) {
    c1_c_p = true;
  } else {
    c1_c_p = false;
  }

  if (!c1_c_p) {
    c1_ntilecols = c1_tile.size[1];
    c1_st.site = &c1_ff_emlrtRSI;
    c1_d_b = c1_ntilecols;
    c1_e_b = c1_d_b;
    if (c1_e_b < 1) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_e_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_jtilecol = 0; c1_jtilecol < c1_ntilecols; c1_jtilecol++) {
      c1_b_jtilecol = c1_jtilecol;
      c1_ibtile = c1_b_jtilecol;
      c1_array_real_T_SetSize(chartInstance, c1_sp, &c1_b->vector.data
        [c1_b->size[0] * c1_ibtile].f1, &c1_he_emlrtRTEI, c1_c_a[0].f1.size[0]);
      c1_b_loop_ub = c1_c_a[0].f1.size[0] - 1;
      for (c1_i1 = 0; c1_i1 <= c1_b_loop_ub; c1_i1++) {
        c1_b->vector.data[c1_ibtile].f1.vector.data[c1_i1] = c1_c_a[0].
          f1.vector.data[c1_i1];
      }
    }
  }

  c1_array_boolean_T_2D_Destructor(chartInstance, &c1_tile);
}

static void c1_assertValidSizeArg(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_c_varargin_1)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  real_T c1_arg;
  real_T c1_b_arg;
  real_T c1_b_x;
  real_T c1_d_varargin_1;
  real_T c1_n;
  int32_T c1_b_u;
  int32_T c1_c_u;
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_p;
  (void)chartInstance;
  c1_arg = c1_c_varargin_1;
  if (c1_arg != c1_arg) {
    c1_p = false;
  } else {
    c1_b_x = c1_arg;
    c1_b = muDoubleScalarIsInf(c1_b_x);
    if (c1_b) {
      c1_p = false;
    } else {
      c1_p = true;
    }
  }

  if (c1_p) {
    c1_b_arg = c1_c_varargin_1;
    if (c1_b_arg > 2.147483647E+9) {
      c1_b_p = false;
    } else {
      c1_b_p = true;
    }

    if (c1_b_p) {
      c1_b_b = true;
    } else {
      c1_b_b = false;
    }
  } else {
    c1_b_b = false;
  }

  if (!c1_b_b) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv6, 10, 0U, 1, 0U, 2, 1, 28),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv6, 10, 0U, 1, 0U, 2, 1, 28),
                  false);
    c1_b_u = MIN_int32_T;
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0, 0U, 0), false);
    c1_c_u = MAX_int32_T;
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0, 0U, 0), false);
    sf_mex_call(c1_sp, &c1_l_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 3U, 14, c1_c_y, 14, c1_d_y, 14, c1_g_y)));
  }

  c1_d_varargin_1 = c1_c_varargin_1;
  if (c1_d_varargin_1 <= 0.0) {
    c1_n = 0.0;
  } else {
    c1_n = c1_d_varargin_1;
  }

  if (!(c1_n <= 2.147483647E+9)) {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv5, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv5, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    sf_mex_call(c1_sp, &c1_m_emlrtMCI, "error", 0U, 2U, 14, c1_e_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 1U, 14, c1_f_y)));
  }
}

static void c1_ComputeWeightedCentroid(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_I[19200],
  c1_coder_array_s_R6Og1x0kmqQXSF9Pw *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  c1_statsAlreadyComputed, c1_coder_array_s_R6Og1x0kmqQXSF9Pw *c1_b_stats,
  c1_sHtk0WM4OMtyqkehwQYcq2 *c1_b_statsAlreadyComputed)
{
  real_T c1_b_I[19200];
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_loop_ub;
  c1_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, c1_sp, c1_b_stats,
    &c1_ie_emlrtRTEI, c1_stats->size[0]);
  c1_loop_ub = c1_stats->size[0] - 1;
  for (c1_i = 0; c1_i <= c1_loop_ub; c1_i++) {
    c1_d_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, c1_sp,
      &c1_b_stats->vector.data[c1_i], &c1_stats->vector.data[c1_i],
      &c1_ie_emlrtRTEI);
  }

  *c1_b_statsAlreadyComputed = c1_statsAlreadyComputed;
  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    c1_b_I[c1_i1] = c1_I[c1_i1];
  }

  c1_b_ComputeWeightedCentroid(chartInstance, c1_sp, c1_b_I, c1_b_stats,
    c1_b_statsAlreadyComputed);
}

static real_T c1_sum(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, c1_coder_array_real_T *c1_b_x)
{
  static char_T c1_b_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_st;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  real_T c1_b_s;
  real_T c1_b_y;
  int32_T c1_b_vlen;
  int32_T c1_c_a;
  int32_T c1_c_vlen;
  int32_T c1_d_vlen;
  int32_T c1_ib;
  int32_T c1_inb;
  int32_T c1_lidx;
  int32_T c1_nfb;
  int32_T c1_nleft;
  int32_T c1_vlen;
  boolean_T c1_b;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_st.site = &c1_ne_emlrtRSI;
  if ((c1_b_x->size[0] == 1) || ((real_T)c1_b_x->size[0] != 1.0)) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c1_st, &c1_q_emlrtMCI, "error", 0U, 2U, 14, c1_c_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_d_y)));
  }

  c1_b_st.site = &c1_oe_emlrtRSI;
  c1_vlen = c1_b_x->size[0];
  c1_c_st.site = &c1_pe_emlrtRSI;
  c1_b_vlen = c1_vlen;
  if ((c1_b_x->size[0] == 0) || (c1_b_vlen == 0)) {
    c1_b_y = 0.0;
  } else {
    c1_d_st.site = &c1_qe_emlrtRSI;
    c1_c_vlen = c1_b_vlen;
    c1_e_st.site = &c1_re_emlrtRSI;
    c1_d_vlen = c1_c_vlen;
    if (c1_d_vlen < 4096) {
      c1_f_st.site = &c1_se_emlrtRSI;
      c1_b_y = c1_c_sumColumnB(chartInstance, &c1_f_st, c1_b_x, c1_d_vlen);
    } else {
      c1_c_a = c1_d_vlen;
      c1_nfb = (int32_T)((uint32_T)c1_c_a >> 12);
      c1_inb = c1_nfb << 12;
      c1_lidx = c1_inb;
      c1_nleft = c1_d_vlen - c1_inb;
      c1_b_s = c1_b_sumColumnB4(chartInstance, c1_b_x, 1);
      for (c1_ib = 2; c1_ib <= c1_nfb; c1_ib++) {
        c1_b_s += c1_b_sumColumnB4(chartInstance, c1_b_x, 1 + ((c1_ib - 1) << 12));
      }

      if (c1_nleft > 0) {
        c1_f_st.site = &c1_te_emlrtRSI;
        c1_b_s += c1_d_sumColumnB(chartInstance, &c1_f_st, c1_b_x, c1_nleft,
          c1_lidx + 1);
      }

      c1_b_y = c1_b_s;
    }
  }

  return c1_b_y;
}

static real_T c1_c_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T *c1_b_x,
  int32_T c1_vlen)
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  real_T c1_b_y;
  real_T c1_c_y;
  real_T c1_d_y;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_b_vlen;
  int32_T c1_b_vstart;
  int32_T c1_c_a;
  int32_T c1_c_b;
  int32_T c1_c_k;
  int32_T c1_c_vlen;
  int32_T c1_d_b;
  int32_T c1_d_k;
  int32_T c1_e_k;
  int32_T c1_f_k;
  int32_T c1_g_k;
  int32_T c1_h_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i_k;
  int32_T c1_inb;
  int32_T c1_k;
  int32_T c1_lidx;
  int32_T c1_nfb;
  int32_T c1_nleft;
  int32_T c1_vstart;
  boolean_T c1_b_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  if (c1_vlen <= 1024) {
    c1_st.site = &c1_ue_emlrtRSI;
    c1_b_vlen = c1_vlen - 1;
    c1_b_y = c1_b_x->vector.data[0];
    c1_i = c1_b_vlen;
    c1_b_st.site = &c1_we_emlrtRSI;
    c1_b = c1_i;
    c1_b_b = c1_b;
    if (c1_b_b < 1) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_c_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
    }

    c1_i1 = (uint16_T)c1_i - 1;
    for (c1_f_k = 0; c1_f_k <= c1_i1; c1_f_k++) {
      c1_g_k = c1_f_k;
      c1_b_y += c1_b_x->vector.data[c1_g_k + 1];
    }
  } else {
    c1_c_a = c1_vlen;
    c1_nfb = (int32_T)((uint32_T)c1_c_a >> 10);
    c1_inb = c1_nfb << 10;
    c1_b_y = c1_b_x->vector.data[0];
    for (c1_k = 0; c1_k < 1023; c1_k++) {
      c1_c_k = c1_k;
      c1_b_y += c1_b_x->vector.data[c1_c_k + 1];
    }

    for (c1_b_k = 2; c1_b_k <= c1_nfb; c1_b_k++) {
      c1_vstart = (c1_b_k - 1) << 10;
      c1_c_y = c1_b_x->vector.data[c1_vstart];
      for (c1_d_k = 0; c1_d_k < 1023; c1_d_k++) {
        c1_e_k = c1_d_k;
        c1_c_y += c1_b_x->vector.data[(c1_vstart + c1_e_k) + 1];
      }

      c1_b_y += c1_c_y;
    }

    if (c1_vlen > c1_inb) {
      c1_nleft = c1_vlen - c1_inb;
      c1_lidx = c1_inb;
      c1_st.site = &c1_ve_emlrtRSI;
      c1_c_vlen = c1_nleft - 1;
      c1_b_vstart = c1_lidx;
      c1_d_y = c1_b_x->vector.data[c1_b_vstart];
      c1_i2 = c1_c_vlen;
      c1_b_st.site = &c1_we_emlrtRSI;
      c1_c_b = c1_i2;
      c1_d_b = c1_c_b;
      if (c1_d_b < 1) {
        c1_b_overflow = false;
      } else {
        c1_b_overflow = (c1_d_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_c_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
      }

      for (c1_h_k = 0; c1_h_k < c1_i2; c1_h_k++) {
        c1_i_k = c1_h_k;
        c1_d_y += c1_b_x->vector.data[(c1_b_vstart + c1_i_k) + 1];
      }

      c1_b_y += c1_d_y;
    }
  }

  return c1_b_y;
}

static real_T c1_b_sumColumnB4(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_real_T *c1_b_x, int32_T c1_vstart)
{
  real_T c1_psum1;
  real_T c1_psum2;
  real_T c1_psum3;
  real_T c1_psum4;
  int32_T c1_b_k;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_k;
  (void)chartInstance;
  c1_i2 = c1_vstart + 1023;
  c1_i3 = c1_vstart + 2047;
  c1_i4 = c1_vstart + 3071;
  c1_psum1 = c1_b_x->vector.data[c1_vstart - 1];
  c1_psum2 = c1_b_x->vector.data[c1_i2];
  c1_psum3 = c1_b_x->vector.data[c1_i3];
  c1_psum4 = c1_b_x->vector.data[c1_i4];
  for (c1_k = 0; c1_k < 1023; c1_k++) {
    c1_b_k = c1_k + 1;
    c1_psum1 += c1_b_x->vector.data[(c1_vstart + c1_b_k) - 1];
    c1_psum2 += c1_b_x->vector.data[c1_i2 + c1_b_k];
    c1_psum3 += c1_b_x->vector.data[c1_i3 + c1_b_k];
    c1_psum4 += c1_b_x->vector.data[c1_i4 + c1_b_k];
  }

  return (c1_psum1 + c1_psum2) + (c1_psum3 + c1_psum4);
}

static real_T c1_d_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T *c1_b_x,
  int32_T c1_vlen, int32_T c1_vstart)
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  real_T c1_b_y;
  real_T c1_c_y;
  real_T c1_d_y;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_b_vlen;
  int32_T c1_b_vstart;
  int32_T c1_c_a;
  int32_T c1_c_b;
  int32_T c1_c_k;
  int32_T c1_c_vlen;
  int32_T c1_c_vstart;
  int32_T c1_d_b;
  int32_T c1_d_k;
  int32_T c1_d_vstart;
  int32_T c1_e_k;
  int32_T c1_e_vstart;
  int32_T c1_f_k;
  int32_T c1_g_k;
  int32_T c1_h_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i_k;
  int32_T c1_inb;
  int32_T c1_k;
  int32_T c1_lidx;
  int32_T c1_nfb;
  int32_T c1_nleft;
  boolean_T c1_b_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  if (c1_vlen <= 1024) {
    c1_st.site = &c1_ue_emlrtRSI;
    c1_b_vlen = c1_vlen - 1;
    c1_b_vstart = c1_vstart - 1;
    c1_b_y = c1_b_x->vector.data[c1_b_vstart];
    c1_i = c1_b_vlen;
    c1_b_st.site = &c1_we_emlrtRSI;
    c1_b = c1_i;
    c1_b_b = c1_b;
    if (c1_b_b < 1) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_c_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
    }

    for (c1_f_k = 0; c1_f_k < c1_i; c1_f_k++) {
      c1_g_k = c1_f_k;
      c1_b_y += c1_b_x->vector.data[(c1_b_vstart + c1_g_k) + 1];
    }
  } else {
    c1_c_a = c1_vlen;
    c1_nfb = (int32_T)((uint32_T)c1_c_a >> 10);
    c1_inb = c1_nfb << 10;
    c1_c_vstart = c1_vstart - 1;
    c1_b_y = c1_b_x->vector.data[c1_c_vstart];
    for (c1_k = 0; c1_k < 1023; c1_k++) {
      c1_c_k = c1_k;
      c1_b_y += c1_b_x->vector.data[(c1_c_vstart + c1_c_k) + 1];
    }

    for (c1_b_k = 2; c1_b_k <= c1_nfb; c1_b_k++) {
      c1_d_vstart = (c1_vstart + ((c1_b_k - 1) << 10)) - 1;
      c1_c_y = c1_b_x->vector.data[c1_d_vstart];
      for (c1_d_k = 0; c1_d_k < 1023; c1_d_k++) {
        c1_e_k = c1_d_k;
        c1_c_y += c1_b_x->vector.data[(c1_d_vstart + c1_e_k) + 1];
      }

      c1_b_y += c1_c_y;
    }

    if (c1_vlen > c1_inb) {
      c1_nleft = c1_vlen - c1_inb;
      c1_lidx = c1_vstart + c1_inb;
      c1_st.site = &c1_ve_emlrtRSI;
      c1_c_vlen = c1_nleft - 1;
      c1_e_vstart = c1_lidx - 1;
      c1_d_y = c1_b_x->vector.data[c1_e_vstart];
      c1_i1 = c1_c_vlen;
      c1_b_st.site = &c1_we_emlrtRSI;
      c1_c_b = c1_i1;
      c1_d_b = c1_c_b;
      if (c1_d_b < 1) {
        c1_b_overflow = false;
      } else {
        c1_b_overflow = (c1_d_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_c_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
      }

      for (c1_h_k = 0; c1_h_k < c1_i1; c1_h_k++) {
        c1_i_k = c1_h_k;
        c1_d_y += c1_b_x->vector.data[(c1_e_vstart + c1_i_k) + 1];
      }

      c1_b_y += c1_d_y;
    }
  }

  return c1_b_y;
}

static void c1_round(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, c1_coder_array_real_T *c1_b_x,
                     c1_coder_array_real_T *c1_b_y)
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  real_T c1_c_x;
  real_T c1_d_x;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_i;
  int32_T c1_k;
  int32_T c1_loop_ub;
  int32_T c1_nx;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_yf_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_array_real_T_SetSize(chartInstance, &c1_st, c1_b_y, &c1_je_emlrtRTEI,
    c1_b_x->size[0]);
  c1_loop_ub = c1_b_x->size[0] - 1;
  for (c1_i = 0; c1_i <= c1_loop_ub; c1_i++) {
    c1_b_y->vector.data[c1_i] = c1_b_x->vector.data[c1_i];
  }

  c1_nx = c1_b_y->size[0];
  c1_b_st.site = &c1_ag_emlrtRSI;
  c1_b = c1_nx;
  c1_b_b = c1_b;
  if (c1_b_b < 1) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_b_b > 2147483646);
  }

  if (c1_overflow) {
    c1_c_st.site = &c1_yc_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
  }

  for (c1_k = 0; c1_k < c1_nx; c1_k++) {
    c1_b_k = c1_k;
    c1_c_x = c1_b_y->vector.data[c1_b_k];
    c1_d_x = c1_c_x;
    c1_d_x = muDoubleScalarRound(c1_d_x);
    c1_b_y->vector.data[c1_b_k] = c1_d_x;
  }
}

static void c1_sort(SFc1_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c1_sp, c1_coder_array_real_T_2D *c1_b_x,
                    c1_coder_array_real_T_2D *c1_c_x, c1_coder_array_int32_T_2D *
                    c1_idx)
{
  int32_T c1_i;
  int32_T c1_loop_ub;
  c1_array_real_T_2D_SetSize(chartInstance, c1_sp, c1_c_x, &c1_ke_emlrtRTEI,
    c1_b_x->size[0], 1);
  c1_loop_ub = c1_b_x->size[0] - 1;
  for (c1_i = 0; c1_i <= c1_loop_ub; c1_i++) {
    c1_c_x->vector.data[c1_i] = c1_b_x->vector.data[c1_i];
  }

  c1_b_sort(chartInstance, c1_sp, c1_c_x, c1_idx);
}

static void c1_merge_pow2_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_idx,
  c1_coder_array_real_T_2D *c1_b_x, int32_T c1_offset, c1_coder_array_int32_T_2D
  *c1_b_idx, c1_coder_array_real_T_2D *c1_c_x)
{
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_loop_ub;
  c1_array_int32_T_2D_SetSize(chartInstance, c1_sp, c1_b_idx, &c1_le_emlrtRTEI,
    c1_idx->size[0], 1);
  c1_loop_ub = c1_idx->size[0] - 1;
  for (c1_i = 0; c1_i <= c1_loop_ub; c1_i++) {
    c1_b_idx->vector.data[c1_i] = c1_idx->vector.data[c1_i];
  }

  c1_array_real_T_2D_SetSize(chartInstance, c1_sp, c1_c_x, &c1_le_emlrtRTEI,
    c1_b_x->size[0], 1);
  c1_b_loop_ub = c1_b_x->size[0] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_b_loop_ub; c1_i1++) {
    c1_c_x->vector.data[c1_i1] = c1_b_x->vector.data[c1_i1];
  }

  c1_b_merge_pow2_block(chartInstance, c1_sp, c1_b_idx, c1_c_x, c1_offset);
}

static void c1_merge_block(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_idx,
  c1_coder_array_real_T_2D *c1_b_x, int32_T c1_offset, int32_T c1_n, int32_T
  c1_preSortLevel, c1_coder_array_int32_T *c1_iwork, c1_coder_array_real_T
  *c1_xwork, c1_coder_array_int32_T_2D *c1_b_idx, c1_coder_array_real_T_2D
  *c1_c_x, c1_coder_array_int32_T *c1_b_iwork, c1_coder_array_real_T *c1_b_xwork)
{
  int32_T c1_b_loop_ub;
  int32_T c1_c_loop_ub;
  int32_T c1_d_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_loop_ub;
  c1_array_int32_T_2D_SetSize(chartInstance, c1_sp, c1_b_idx, &c1_me_emlrtRTEI,
    c1_idx->size[0], 1);
  c1_loop_ub = c1_idx->size[0] - 1;
  for (c1_i = 0; c1_i <= c1_loop_ub; c1_i++) {
    c1_b_idx->vector.data[c1_i] = c1_idx->vector.data[c1_i];
  }

  c1_array_real_T_2D_SetSize(chartInstance, c1_sp, c1_c_x, &c1_me_emlrtRTEI,
    c1_b_x->size[0], 1);
  c1_b_loop_ub = c1_b_x->size[0] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_b_loop_ub; c1_i1++) {
    c1_c_x->vector.data[c1_i1] = c1_b_x->vector.data[c1_i1];
  }

  c1_array_int32_T_SetSize(chartInstance, c1_sp, c1_b_iwork, &c1_me_emlrtRTEI,
    c1_iwork->size[0]);
  c1_c_loop_ub = c1_iwork->size[0] - 1;
  for (c1_i2 = 0; c1_i2 <= c1_c_loop_ub; c1_i2++) {
    c1_b_iwork->vector.data[c1_i2] = c1_iwork->vector.data[c1_i2];
  }

  c1_array_real_T_SetSize(chartInstance, c1_sp, c1_b_xwork, &c1_me_emlrtRTEI,
    c1_xwork->size[0]);
  c1_d_loop_ub = c1_xwork->size[0] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_d_loop_ub; c1_i3++) {
    c1_b_xwork->vector.data[c1_i3] = c1_xwork->vector.data[c1_i3];
  }

  c1_b_merge_block(chartInstance, c1_sp, c1_b_idx, c1_c_x, c1_offset, c1_n,
                   c1_preSortLevel, c1_b_iwork, c1_b_xwork);
}

static void c1_merge(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_idx,
                     c1_coder_array_real_T_2D *c1_b_x, int32_T c1_offset,
                     int32_T c1_np, int32_T c1_nq, c1_coder_array_int32_T
                     *c1_iwork, c1_coder_array_real_T *c1_xwork,
                     c1_coder_array_int32_T_2D *c1_b_idx,
                     c1_coder_array_real_T_2D *c1_c_x, c1_coder_array_int32_T
                     *c1_b_iwork, c1_coder_array_real_T *c1_b_xwork)
{
  int32_T c1_b_loop_ub;
  int32_T c1_c_loop_ub;
  int32_T c1_d_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_loop_ub;
  c1_array_int32_T_2D_SetSize(chartInstance, c1_sp, c1_b_idx, &c1_ne_emlrtRTEI,
    c1_idx->size[0], 1);
  c1_loop_ub = c1_idx->size[0] - 1;
  for (c1_i = 0; c1_i <= c1_loop_ub; c1_i++) {
    c1_b_idx->vector.data[c1_i] = c1_idx->vector.data[c1_i];
  }

  c1_array_real_T_2D_SetSize(chartInstance, c1_sp, c1_c_x, &c1_ne_emlrtRTEI,
    c1_b_x->size[0], 1);
  c1_b_loop_ub = c1_b_x->size[0] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_b_loop_ub; c1_i1++) {
    c1_c_x->vector.data[c1_i1] = c1_b_x->vector.data[c1_i1];
  }

  c1_array_int32_T_SetSize(chartInstance, c1_sp, c1_b_iwork, &c1_ne_emlrtRTEI,
    c1_iwork->size[0]);
  c1_c_loop_ub = c1_iwork->size[0] - 1;
  for (c1_i2 = 0; c1_i2 <= c1_c_loop_ub; c1_i2++) {
    c1_b_iwork->vector.data[c1_i2] = c1_iwork->vector.data[c1_i2];
  }

  c1_array_real_T_SetSize(chartInstance, c1_sp, c1_b_xwork, &c1_ne_emlrtRTEI,
    c1_xwork->size[0]);
  c1_d_loop_ub = c1_xwork->size[0] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_d_loop_ub; c1_i3++) {
    c1_b_xwork->vector.data[c1_i3] = c1_xwork->vector.data[c1_i3];
  }

  c1_b_merge(chartInstance, c1_sp, c1_b_idx, c1_c_x, c1_offset, c1_np, c1_nq,
             c1_b_iwork, c1_b_xwork);
}

static boolean_T c1_all(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_coder_array_boolean_T *c1_b_x)
{
  static char_T c1_b_cv[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
    'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  real_T c1_c_a;
  real_T c1_vlen;
  int32_T c1_b_b;
  int32_T c1_c;
  int32_T c1_c_b;
  int32_T c1_d_a;
  int32_T c1_d_b;
  int32_T c1_e_a;
  int32_T c1_i2;
  int32_T c1_ix;
  int32_T c1_vspread;
  boolean_T c1_b;
  boolean_T c1_b_y;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_st.site = &c1_mh_emlrtRSI;
  if ((c1_b_x->size[0] == 1) || ((real_T)c1_b_x->size[0] != 1.0)) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 51),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c1_st, &c1_y_emlrtMCI, "error", 0U, 2U, 14, c1_c_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_d_y)));
  }

  c1_b_y = true;
  c1_vlen = (real_T)c1_b_x->size[0];
  c1_c_a = c1_vlen;
  c1_c = (int32_T)c1_c_a;
  c1_d_a = c1_c - 1;
  c1_vspread = c1_d_a;
  c1_b_b = c1_vspread;
  c1_i2 = c1_b_b;
  c1_e_a = c1_i2 + 1;
  c1_i2 = c1_e_a;
  c1_b_st.site = &c1_nh_emlrtRSI;
  c1_c_b = c1_i2;
  c1_d_b = c1_c_b;
  if (c1_d_b < 1) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_d_b > 2147483646);
  }

  if (c1_overflow) {
    c1_c_st.site = &c1_yc_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
  }

  c1_ix = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_ix + 1 <= c1_i2)) {
    if (!c1_b_x->vector.data[c1_ix]) {
      c1_b_y = false;
      c1_exitg1 = true;
    } else {
      c1_ix++;
    }
  }

  return c1_b_y;
}

static void c1_hough(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200],
                     real_T c1_h[71820])
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  real_T c1_cost[180];
  real_T c1_sint[180];
  real_T c1_tempBin[120];
  real_T c1_b_j;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_j;
  real_T c1_d_x;
  real_T c1_e_i;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_myRho;
  real_T c1_tempNum;
  int32_T c1_b_nonZeroPixelMatrix[19200];
  int32_T c1_rhoIdxVector[399];
  int32_T c1_numNonZeros[160];
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_i;
  int32_T c1_b_thetaIdx;
  int32_T c1_b_y;
  int32_T c1_c;
  int32_T c1_c_a;
  int32_T c1_c_i;
  int32_T c1_c_j;
  int32_T c1_d_i;
  int32_T c1_f_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_j;
  int32_T c1_k;
  int32_T c1_n;
  int32_T c1_rhoIdx;
  int32_T c1_thetaIdx;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_rh_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  for (c1_i = 0; c1_i < 180; c1_i++) {
    c1_b_i = c1_i;
    c1_b_x = (-90.0 + (real_T)c1_b_i) * 3.1415926535897931 / 180.0;
    c1_c_x = c1_b_x;
    c1_c_x = muDoubleScalarCos(c1_c_x);
    c1_cost[c1_b_i] = c1_c_x;
    c1_d_x = (-90.0 + (real_T)c1_b_i) * 3.1415926535897931 / 180.0;
    c1_e_x = c1_d_x;
    c1_e_x = muDoubleScalarSin(c1_e_x);
    c1_sint[c1_b_i] = c1_e_x;
  }

  c1_b_st.site = &c1_sh_emlrtRSI;
  for (c1_j = 0; c1_j < 160; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    c1_tempNum = 0.0;
    for (c1_c_i = 0; c1_c_i < 120; c1_c_i++) {
      c1_e_i = (real_T)c1_c_i + 1.0;
      if (c1_c_varargin_1[((int32_T)c1_e_i + 120 * ((int32_T)c1_b_j - 1)) - 1])
      {
        c1_tempNum++;
        c1_i2 = (int32_T)c1_tempNum;
        if ((c1_i2 < 1) || (c1_i2 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c1_i2, 1, 120, &c1_ef_emlrtBCI, &c1_b_st);
        }

        c1_tempBin[c1_i2 - 1] = c1_e_i;
      }
    }

    c1_numNonZeros[(int32_T)c1_b_j - 1] = (int32_T)c1_tempNum;
    c1_k = 0;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k < 120)) {
      c1_b_k = (real_T)c1_k + 1.0;
      if (c1_b_k > c1_tempNum) {
        c1_exitg1 = true;
      } else {
        c1_b_nonZeroPixelMatrix[((int32_T)c1_b_k + 120 * ((int32_T)c1_b_j - 1))
          - 1] = (int32_T)c1_tempBin[(int32_T)c1_b_k - 1];
        c1_k++;
      }
    }
  }

  for (c1_thetaIdx = 0; c1_thetaIdx < 180; c1_thetaIdx++) {
    c1_b_thetaIdx = c1_thetaIdx;
    for (c1_d_i = 0; c1_d_i < 399; c1_d_i++) {
      c1_rhoIdxVector[c1_d_i] = 0;
    }

    for (c1_c_j = 0; c1_c_j < 160; c1_c_j++) {
      c1_d_j = (real_T)c1_c_j + 1.0;
      c1_i3 = c1_numNonZeros[(int32_T)c1_d_j - 1];
      c1_b_st.site = &c1_th_emlrtRSI;
      c1_b = c1_i3;
      c1_b_b = c1_b;
      if (c1_b_b < 1) {
        c1_overflow = false;
      } else {
        c1_overflow = (c1_b_b > 2147483646);
      }

      if (c1_overflow) {
        c1_c_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
      }

      c1_i4 = (uint8_T)c1_i3 - 1;
      for (c1_f_i = 0; c1_f_i <= c1_i4; c1_f_i++) {
        c1_b_i = c1_f_i;
        c1_n = c1_b_nonZeroPixelMatrix[c1_b_i + 120 * ((int32_T)c1_d_j - 1)];
        c1_myRho = (c1_d_j - 1.0) * c1_cost[c1_b_thetaIdx] + ((real_T)c1_n - 1.0)
          * c1_sint[c1_b_thetaIdx];
        c1_f_x = c1_myRho - -199.0;
        c1_b_y = (int32_T)(c1_f_x + 0.5) + 1;
        c1_rhoIdx = c1_b_y;
        c1_c_a = c1_rhoIdxVector[c1_rhoIdx - 1] + 1;
        c1_c = c1_c_a;
        if ((c1_rhoIdx < 1) || (c1_rhoIdx > 399)) {
          emlrtDynamicBoundsCheckR2012b(c1_rhoIdx, 1, 399, &c1_df_emlrtBCI,
            &c1_st);
        }

        c1_rhoIdxVector[c1_rhoIdx - 1] = c1_c;
      }
    }

    for (c1_i1 = 0; c1_i1 < 399; c1_i1++) {
      c1_h[c1_i1 + 399 * c1_b_thetaIdx] = (real_T)c1_rhoIdxVector[c1_i1];
    }
  }
}

static void c1_houghpeaks(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_c_varargin_1[71820], real_T c1_varargin_4,
  real_T c1_peaks_data[], int32_T c1_peaks_size[2])
{
  static char_T c1_b_cv3[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'n', 'e', 'g', 'a', 't', 'i', 'v', 'e' };

  static char_T c1_b_cv6[43] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'h', 'o',
    'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i',
    'd', 'T', 'h', 'e', 't', 'a', 'V', 'e', 'c', 't', 'o', 'r', 'S', 'p', 'a',
    'c', 'i', 'n', 'g' };

  static char_T c1_b_cv2[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
    'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'N', 'o', 'n', 'n', 'e', 'g', 'a', 't', 'i', 'v', 'e' };

  static char_T c1_b_cv[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
    'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c1_b_cv1[9] = { 'T', 'h', 'r', 'e', 's', 'h', 'o', 'l', 'd' };

  static char_T c1_b_cv4[9] = { 'T', 'h', 'r', 'e', 's', 'h', 'o', 'l', 'd' };

  static char_T c1_b_cv5[5] = { 'T', 'h', 'e', 't', 'a' };

  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_i_y = NULL;
  const mxArray *c1_j_y = NULL;
  const mxArray *c1_m_y = NULL;
  const mxArray *c1_n_y = NULL;
  real_T c1_b_dv1[180];
  real_T c1_thetaInterval[179];
  real_T c1_g_x[178];
  real_T c1_peakCoordinates[10];
  real_T c1_c_dv[2];
  real_T c1_b_ex;
  real_T c1_b_k;
  real_T c1_b_ndx;
  real_T c1_b_threshold;
  real_T c1_b_varargin_2;
  real_T c1_b_varargin_4;
  real_T c1_b_x;
  real_T c1_c_a;
  real_T c1_c_ex;
  real_T c1_c_threshold;
  real_T c1_c_varargin_2;
  real_T c1_c_x;
  real_T c1_d_a;
  real_T c1_d_varargin_2;
  real_T c1_d_x;
  real_T c1_e_a;
  real_T c1_e_idx;
  real_T c1_e_x;
  real_T c1_ex;
  real_T c1_f_a;
  real_T c1_f_x;
  real_T c1_g_a;
  real_T c1_h_x;
  real_T c1_iPeak;
  real_T c1_i_x;
  real_T c1_jPeak;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_k_y;
  real_T c1_l_x;
  real_T c1_l_y;
  real_T c1_m_x;
  real_T c1_maxTheta;
  real_T c1_minTheta;
  real_T c1_n_x;
  real_T c1_ndx;
  real_T c1_o_x;
  real_T c1_o_y;
  real_T c1_p_x;
  real_T c1_p_y;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_thetaResolution;
  real_T c1_threshold;
  int32_T c1_b_iPeak;
  int32_T c1_b_idx;
  int32_T c1_b_jPeak;
  int32_T c1_c_idx;
  int32_T c1_c_k;
  int32_T c1_d_idx;
  int32_T c1_d_k;
  int32_T c1_e_k;
  int32_T c1_f_idx;
  int32_T c1_f_k;
  int32_T c1_first;
  int32_T c1_g_b;
  int32_T c1_h_a;
  int32_T c1_h_b;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i_a;
  int32_T c1_i_b;
  int32_T c1_idx;
  int32_T c1_iindx;
  int32_T c1_j_a;
  int32_T c1_j_b;
  int32_T c1_k;
  int32_T c1_k_a;
  int32_T c1_l_a;
  int32_T c1_loop_ub;
  int32_T c1_peakIdx;
  int32_T c1_rho;
  int32_T c1_rhoMax;
  int32_T c1_rhoMin;
  int32_T c1_rhoToRemove;
  int32_T c1_theta;
  int32_T c1_thetaMax;
  int32_T c1_thetaMin;
  int32_T c1_thetaToRemove;
  int32_T c1_v1;
  int32_T c1_varargout_3;
  int32_T c1_varargout_4;
  int32_T c1_vk;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b_b;
  boolean_T c1_b_overflow;
  boolean_T c1_b_p;
  boolean_T c1_c_b;
  boolean_T c1_c_p;
  boolean_T c1_d_b;
  boolean_T c1_d_p;
  boolean_T c1_e_b;
  boolean_T c1_e_p;
  boolean_T c1_exitg1;
  boolean_T c1_f_b;
  boolean_T c1_f_p;
  boolean_T c1_g_p;
  boolean_T c1_isDone;
  boolean_T c1_isThetaAntisymmetric;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_st.site = &c1_xh_emlrtRSI;
  c1_b_varargin_4 = c1_varargin_4;
  c1_b_st.site = &c1_yh_emlrtRSI;
  c1_b_validateattributes(chartInstance, &c1_b_st, c1_c_varargin_1);
  c1_b_varargin_2 = c1_b_varargin_4;
  c1_c_varargin_2 = c1_b_varargin_2;
  c1_d_varargin_2 = c1_c_varargin_2;
  c1_threshold = c1_d_varargin_2;
  c1_b_threshold = c1_threshold;
  c1_b_st.site = &c1_ai_emlrtRSI;
  c1_c_threshold = c1_threshold;
  c1_c_st.site = &c1_di_emlrtRSI;
  c1_c_a = c1_c_threshold;
  c1_d_st.site = &c1_s_emlrtRSI;
  c1_d_a = c1_c_a;
  c1_e_a = c1_d_a;
  c1_p = true;
  c1_b_x = c1_e_a;
  c1_c_x = c1_b_x;
  c1_b = muDoubleScalarIsNaN(c1_c_x);
  c1_b_p = !c1_b;
  if (!c1_b_p) {
    c1_p = false;
  }

  if (c1_p) {
    c1_b_b = true;
  } else {
    c1_b_b = false;
  }

  if (!c1_b_b) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 32),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv3, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_d_st, &c1_i_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_d_st, NULL, "message", 1U, 2U, 14, c1_c_y, 14, c1_d_y)));
  }

  c1_d_st.site = &c1_s_emlrtRSI;
  c1_f_a = c1_c_a;
  c1_g_a = c1_f_a;
  c1_c_p = true;
  c1_d_x = c1_g_a;
  c1_d_p = !(c1_d_x < 0.0);
  if (!c1_d_p) {
    c1_c_p = false;
  }

  if (c1_c_p) {
    c1_b1 = true;
  } else {
    c1_b1 = false;
  }

  if (!c1_b1) {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv2, 10, 0U, 1, 0U, 2, 1, 37),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_b_cv3, 10, 0U, 1, 0U, 2, 1, 51),
                  false);
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_b_cv4, 10, 0U, 1, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_d_st, &c1_b_emlrtMCI, "error", 0U, 2U, 14, c1_e_y, 14,
                sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_d_st, NULL, "message", 1U, 2U, 14, c1_f_y, 14, c1_g_y)));
  }

  c1_b_st.site = &c1_bi_emlrtRSI;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_c_dv[c1_i] = 9.0 + -4.0 * (real_T)c1_i;
  }

  c1_c_st.site = &c1_ei_emlrtRSI;
  c1_c_validateattributes(chartInstance, &c1_c_st, c1_c_dv);
  c1_b_st.site = &c1_ci_emlrtRSI;
  c1_c_st.site = &c1_gi_emlrtRSI;
  c1_d_st.site = &c1_s_emlrtRSI;
  c1_e_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 180)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_e_x = -90.0 + (real_T)((int32_T)c1_b_k - 1);
    c1_f_x = c1_e_x;
    c1_c_b = muDoubleScalarIsInf(c1_f_x);
    c1_b3 = !c1_c_b;
    c1_d_b = c1_b3;
    if (c1_d_b) {
      c1_k++;
    } else {
      c1_e_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_e_p) {
    c1_b2 = true;
  } else {
    c1_b2 = false;
  }

  if (!c1_b2) {
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_cv7, 10, 0U, 1, 0U, 2, 1, 32),
                  false);
    c1_i_y = NULL;
    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c1_j_y = NULL;
    sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_b_cv5, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c1_d_st, &c1_emlrtMCI, "error", 0U, 2U, 14, c1_h_y, 14,
                sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_d_st, NULL, "message", 1U, 2U, 14, c1_i_y, 14, c1_j_y)));
  }

  for (c1_i1 = 0; c1_i1 < 180; c1_i1++) {
    c1_b_dv1[c1_i1] = -90.0 + (real_T)c1_i1;
  }

  c1_diff(chartInstance, c1_b_dv1, c1_thetaInterval);
  c1_c_st.site = &c1_fi_emlrtRSI;
  c1_b_diff(chartInstance, c1_thetaInterval, c1_g_x);
  c1_k_y = c1_e_sumColumnB(chartInstance, c1_g_x);
  c1_h_x = c1_k_y;
  c1_i_x = c1_h_x;
  c1_j_x = c1_i_x;
  c1_l_y = muDoubleScalarAbs(c1_j_x);
  if (c1_l_y > 1.4901161193847656E-8) {
    c1_m_y = NULL;
    sf_mex_assign(&c1_m_y, sf_mex_create("y", c1_b_cv6, 10, 0U, 1, 0U, 2, 1, 43),
                  false);
    c1_n_y = NULL;
    sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_b_cv6, 10, 0U, 1, 0U, 2, 1, 43),
                  false);
    sf_mex_call(&c1_b_st, &c1_db_emlrtMCI, "error", 0U, 2U, 14, c1_m_y, 14,
                sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_b_st, NULL, "message", 1U, 1U, 14, c1_n_y)));
  }

  c1_isDone = false;
  for (c1_i2 = 0; c1_i2 < 71820; c1_i2++) {
    chartInstance->c1_hnew[c1_i2] = c1_c_varargin_1[c1_i2];
  }

  c1_peakIdx = 0;
  c1_ex = -90.0;
  for (c1_c_k = 0; c1_c_k < 179; c1_c_k++) {
    if (c1_ex > -90.0 + (real_T)(c1_c_k + 1)) {
      c1_ex = -90.0 + (real_T)(c1_c_k + 1);
    }
  }

  c1_minTheta = c1_ex;
  c1_b_ex = -90.0;
  for (c1_d_k = 0; c1_d_k < 179; c1_d_k++) {
    if (c1_b_ex < -90.0 + (real_T)(c1_d_k + 1)) {
      c1_b_ex = -90.0 + (real_T)(c1_d_k + 1);
    }
  }

  c1_maxTheta = c1_b_ex;
  c1_k_x = c1_maxTheta - c1_minTheta;
  c1_l_x = c1_k_x;
  c1_m_x = c1_l_x;
  c1_o_y = muDoubleScalarAbs(c1_m_x);
  c1_thetaResolution = c1_o_y / 179.0;
  c1_n_x = c1_minTheta + c1_thetaResolution * 5.0;
  c1_o_x = c1_n_x;
  c1_p_x = c1_o_x;
  c1_p_y = muDoubleScalarAbs(c1_p_x);
  c1_isThetaAntisymmetric = (c1_p_y <= c1_maxTheta);
  while (!c1_isDone) {
    for (c1_i3 = 0; c1_i3 < 71820; c1_i3++) {
      chartInstance->c1_b_varargin_1[c1_i3] = chartInstance->c1_hnew[c1_i3];
    }

    c1_q_x = chartInstance->c1_b_varargin_1[0];
    c1_r_x = c1_q_x;
    c1_e_b = muDoubleScalarIsNaN(c1_r_x);
    c1_f_p = !c1_e_b;
    if (c1_f_p) {
      c1_idx = 1;
    } else {
      c1_idx = 0;
      c1_e_k = 2;
      c1_exitg1 = false;
      while ((!c1_exitg1) && (c1_e_k < 71821)) {
        c1_s_x = chartInstance->c1_b_varargin_1[c1_e_k - 1];
        c1_t_x = c1_s_x;
        c1_f_b = muDoubleScalarIsNaN(c1_t_x);
        c1_g_p = !c1_f_b;
        if (c1_g_p) {
          c1_idx = c1_e_k;
          c1_exitg1 = true;
        } else {
          c1_e_k++;
        }
      }
    }

    if (c1_idx == 0) {
      c1_idx = 1;
    } else {
      c1_first = c1_idx;
      c1_c_ex = chartInstance->c1_b_varargin_1[c1_first - 1];
      c1_b_idx = c1_first;
      c1_i6 = c1_first;
      for (c1_f_k = c1_i6 + 1; c1_f_k < 71821; c1_f_k++) {
        if (c1_c_ex < chartInstance->c1_b_varargin_1[c1_f_k - 1]) {
          c1_c_ex = chartInstance->c1_b_varargin_1[c1_f_k - 1];
          c1_b_idx = c1_f_k;
        }
      }

      c1_idx = c1_b_idx;
    }

    c1_c_idx = c1_idx;
    c1_d_idx = c1_c_idx;
    c1_iindx = c1_d_idx;
    c1_e_idx = (real_T)c1_iindx;
    c1_st.site = &c1_wh_emlrtRSI;
    c1_ndx = c1_e_idx;
    c1_b_st.site = &c1_qf_emlrtRSI;
    c1_b_ndx = c1_ndx;
    c1_f_idx = (int32_T)c1_b_ndx - 1;
    c1_v1 = c1_f_idx;
    c1_h_a = c1_v1;
    c1_vk = (int32_T)((uint32_T)c1_h_a / 399U);
    c1_varargout_4 = c1_vk;
    c1_v1 = (c1_v1 - c1_vk * 399) + 1;
    c1_varargout_3 = c1_v1;
    c1_iPeak = (real_T)c1_varargout_3;
    c1_jPeak = (real_T)(c1_varargout_4 + 1);
    c1_b_iPeak = (int32_T)c1_iPeak;
    c1_b_jPeak = (int32_T)c1_jPeak;
    if ((c1_b_iPeak < 1) || (c1_b_iPeak > 399)) {
      emlrtDynamicBoundsCheckR2012b(c1_b_iPeak, 1, 399, &c1_gf_emlrtBCI,
        (emlrtConstCTX)c1_sp);
    }

    if (chartInstance->c1_hnew[(c1_b_iPeak + 399 * (c1_b_jPeak - 1)) - 1] >=
        c1_b_threshold) {
      c1_peakIdx++;
      if ((c1_peakIdx < 1) || (c1_peakIdx > 5)) {
        emlrtDynamicBoundsCheckR2012b(c1_peakIdx, 1, 5, &c1_ff_emlrtBCI,
          (emlrtConstCTX)c1_sp);
      }

      c1_peakCoordinates[c1_peakIdx - 1] = (real_T)c1_b_iPeak;
      c1_peakCoordinates[c1_peakIdx + 4] = (real_T)c1_b_jPeak;
      c1_rhoMin = c1_b_iPeak - 4;
      c1_rhoMax = c1_b_iPeak + 4;
      c1_thetaMin = c1_b_jPeak - 2;
      c1_thetaMax = c1_b_jPeak + 2;
      if (c1_rhoMin < 1) {
        c1_rhoMin = 1;
      }

      if (c1_rhoMax > 399) {
        c1_rhoMax = 399;
      }

      c1_st.site = &c1_vh_emlrtRSI;
      c1_i_a = c1_thetaMin;
      c1_g_b = c1_thetaMax;
      c1_j_a = c1_i_a;
      c1_h_b = c1_g_b;
      if (c1_j_a > c1_h_b) {
        c1_overflow = false;
      } else {
        c1_overflow = (c1_h_b > 2147483646);
      }

      if (c1_overflow) {
        c1_b_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
      }

      for (c1_theta = c1_thetaMin; c1_theta <= c1_thetaMax; c1_theta++) {
        c1_st.site = &c1_uh_emlrtRSI;
        c1_k_a = c1_rhoMin;
        c1_i_b = c1_rhoMax;
        c1_l_a = c1_k_a;
        c1_j_b = c1_i_b;
        if (c1_l_a > c1_j_b) {
          c1_b_overflow = false;
        } else {
          c1_b_overflow = (c1_j_b > 2147483646);
        }

        if (c1_b_overflow) {
          c1_b_st.site = &c1_yc_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
        }

        for (c1_rho = c1_rhoMin; c1_rho <= c1_rhoMax; c1_rho++) {
          c1_rhoToRemove = c1_rho;
          c1_thetaToRemove = c1_theta;
          if (c1_isThetaAntisymmetric) {
            if (c1_theta > 180) {
              c1_rhoToRemove = 400 - c1_rho;
              c1_thetaToRemove = c1_theta - 180;
            } else if (c1_theta < 1) {
              c1_rhoToRemove = 400 - c1_rho;
              c1_thetaToRemove = c1_theta + 180;
            }
          }

          if ((c1_thetaToRemove > 180) || (c1_thetaToRemove < 1)) {
          } else {
            chartInstance->c1_hnew[(c1_rhoToRemove + 399 * (c1_thetaToRemove - 1))
              - 1] = 0.0;
          }
        }
      }

      c1_isDone = (c1_peakIdx == 5);
    } else {
      c1_isDone = true;
    }
  }

  if (c1_peakIdx == 0) {
    c1_peaks_size[0] = 0;
    c1_peaks_size[1] = 0;
  } else {
    c1_peaks_size[0] = c1_peakIdx;
    c1_peaks_size[1] = 2;
    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_loop_ub = c1_peakIdx - 1;
      for (c1_i5 = 0; c1_i5 <= c1_loop_ub; c1_i5++) {
        c1_peaks_data[c1_i5 + c1_peaks_size[0] * c1_i4] =
          c1_peakCoordinates[c1_i5 + 5 * c1_i4];
      }
    }
  }
}

static void c1_b_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_c_a[71820])
{
  static char_T c1_b_cv[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'H', ',' };

  static char_T c1_b_cv1[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'H', ',' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_k;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_h_y;
  int32_T c1_c_k;
  int32_T c1_k;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_c_b;
  boolean_T c1_c_p;
  boolean_T c1_d_b;
  boolean_T c1_d_p;
  boolean_T c1_e_b;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_s_emlrtRSI;
  c1_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 71820)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_b_x = c1_c_a[(int32_T)c1_b_k - 1];
    c1_c_x = c1_b_x;
    c1_b_b = muDoubleScalarIsInf(c1_c_x);
    c1_b1 = !c1_b_b;
    c1_c_b = c1_b1;
    if (c1_c_b) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv7, 10, 0U, 1, 0U, 2, 1, 32),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c1_st, &c1_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_c_y, 14, c1_d_y)));
  }

  c1_st.site = &c1_s_emlrtRSI;
  c1_b_p = true;
  c1_c_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_c_k < 71820)) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_d_x = c1_c_a[(int32_T)c1_d_k - 1];
    c1_e_x = c1_d_x;
    c1_f_x = c1_e_x;
    c1_d_b = muDoubleScalarIsInf(c1_f_x);
    c1_b3 = !c1_d_b;
    c1_e_b = c1_b3;
    if (c1_e_b) {
      c1_g_x = c1_d_x;
      c1_h_x = c1_g_x;
      c1_h_y = c1_h_x;
      c1_h_y = muDoubleScalarFloor(c1_h_y);
      if (c1_h_y == c1_d_x) {
        c1_c_p = true;
      } else {
        c1_c_p = false;
      }
    } else {
      c1_c_p = false;
    }

    c1_d_p = c1_c_p;
    if (c1_d_p) {
      c1_c_k++;
    } else {
      c1_b_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_b_p) {
    c1_b2 = true;
  } else {
    c1_b2 = false;
  }

  if (!c1_b2) {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv8, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv9, 10, 0U, 1, 0U, 2, 1, 47),
                  false);
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c1_st, &c1_ab_emlrtMCI, "error", 0U, 2U, 14, c1_e_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_f_y, 14, c1_g_y)));
  }
}

static void c1_c_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_c_a[2])
{
  static char_T c1_b_cv5[43] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'O', 'd', 'd' };

  static char_T c1_b_cv2[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
    'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c1_b_cv4[29] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
    'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'O', 'd', 'd' };

  static char_T c1_b_cv[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  static char_T c1_b_cv1[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  static char_T c1_b_cv3[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  static char_T c1_b_cv6[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_i_y = NULL;
  const mxArray *c1_j_y = NULL;
  const mxArray *c1_k_y = NULL;
  const mxArray *c1_l_y = NULL;
  const mxArray *c1_m_y = NULL;
  const mxArray *c1_n_y = NULL;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_a;
  real_T c1_d_k;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_k;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_k;
  real_T c1_h_x;
  real_T c1_h_y;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_r;
  int32_T c1_c_k;
  int32_T c1_e_k;
  int32_T c1_g_k;
  int32_T c1_k;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_c_b;
  boolean_T c1_c_p;
  boolean_T c1_d_b;
  boolean_T c1_d_p;
  boolean_T c1_e_b;
  boolean_T c1_e_p;
  boolean_T c1_exitg1;
  boolean_T c1_f_b;
  boolean_T c1_f_p;
  boolean_T c1_g_b;
  boolean_T c1_g_p;
  boolean_T c1_h_p;
  boolean_T c1_p;
  boolean_T c1_rEQ0;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_s_emlrtRSI;
  c1_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 2)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_b_x = c1_c_a[(int32_T)c1_b_k - 1];
    c1_c_x = c1_b_x;
    c1_b_b = muDoubleScalarIsInf(c1_c_x);
    c1_b1 = !c1_b_b;
    c1_c_b = c1_b1;
    if (c1_c_b) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv7, 10, 0U, 1, 0U, 2, 1, 32),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_st, &c1_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_c_y, 14, c1_d_y)));
  }

  c1_st.site = &c1_s_emlrtRSI;
  c1_b_p = true;
  c1_c_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_c_k < 2)) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_d_x = c1_c_a[(int32_T)c1_d_k - 1];
    c1_e_x = c1_d_x;
    c1_f_x = c1_e_x;
    c1_d_b = muDoubleScalarIsInf(c1_f_x);
    c1_b3 = !c1_d_b;
    c1_e_b = c1_b3;
    if (c1_e_b) {
      c1_g_x = c1_d_x;
      c1_h_x = c1_g_x;
      c1_h_y = c1_h_x;
      c1_h_y = muDoubleScalarFloor(c1_h_y);
      if (c1_h_y == c1_d_x) {
        c1_d_p = true;
      } else {
        c1_d_p = false;
      }
    } else {
      c1_d_p = false;
    }

    c1_e_p = c1_d_p;
    if (c1_e_p) {
      c1_c_k++;
    } else {
      c1_b_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_b_p) {
    c1_b2 = true;
  } else {
    c1_b2 = false;
  }

  if (!c1_b2) {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv8, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv9, 10, 0U, 1, 0U, 2, 1, 47),
                  false);
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_st, &c1_ab_emlrtMCI, "error", 0U, 2U, 14, c1_e_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_f_y, 14, c1_g_y)));
  }

  c1_st.site = &c1_s_emlrtRSI;
  c1_c_p = true;
  c1_e_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_e_k < 2)) {
    c1_f_k = (real_T)c1_e_k + 1.0;
    c1_i_x = c1_c_a[(int32_T)c1_f_k - 1];
    c1_f_p = !(c1_i_x <= 0.0);
    if (c1_f_p) {
      c1_e_k++;
    } else {
      c1_c_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_c_p) {
    c1_b4 = true;
  } else {
    c1_b4 = false;
  }

  if (!c1_b4) {
    c1_i_y = NULL;
    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_b_cv2, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    c1_j_y = NULL;
    sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_cv1, 10, 0U, 1, 0U, 2, 1, 48),
                  false);
    c1_k_y = NULL;
    sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_b_cv3, 10, 0U, 1, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_st, &c1_u_emlrtMCI, "error", 0U, 2U, 14, c1_i_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_j_y, 14, c1_k_y)));
  }

  c1_st.site = &c1_s_emlrtRSI;
  c1_g_p = true;
  c1_g_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_g_k < 2)) {
    c1_h_k = (real_T)c1_g_k + 1.0;
    c1_j_x = c1_c_a[(int32_T)c1_h_k - 1];
    c1_k_x = c1_j_x;
    c1_d_a = c1_k_x;
    c1_l_x = c1_d_a;
    c1_m_x = c1_l_x;
    c1_n_x = c1_m_x;
    c1_f_b = muDoubleScalarIsNaN(c1_n_x);
    if (c1_f_b) {
      c1_r = rtNaN;
    } else {
      c1_o_x = c1_m_x;
      c1_g_b = muDoubleScalarIsInf(c1_o_x);
      if (c1_g_b) {
        c1_r = rtNaN;
      } else {
        c1_r = muDoubleScalarRem(c1_m_x, 2.0);
        c1_rEQ0 = (c1_r == 0.0);
        if (c1_rEQ0) {
          c1_r = 0.0;
        }
      }
    }

    c1_h_p = (c1_r == 1.0);
    if (c1_h_p) {
      c1_g_k++;
    } else {
      c1_g_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_g_p) {
    c1_b5 = true;
  } else {
    c1_b5 = false;
  }

  if (!c1_b5) {
    c1_l_y = NULL;
    sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_b_cv4, 10, 0U, 1, 0U, 2, 1, 29),
                  false);
    c1_m_y = NULL;
    sf_mex_assign(&c1_m_y, sf_mex_create("y", c1_b_cv5, 10, 0U, 1, 0U, 2, 1, 43),
                  false);
    c1_n_y = NULL;
    sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_b_cv6, 10, 0U, 1, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_st, &c1_cb_emlrtMCI, "error", 0U, 2U, 14, c1_l_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_m_y, 14, c1_n_y)));
  }
}

static void c1_diff(SFc1_flightControlSystemInstanceStruct *chartInstance,
                    real_T c1_b_x[180], real_T c1_b_y[179])
{
  real_T c1_tmp1;
  real_T c1_tmp2;
  real_T c1_work;
  int32_T c1_ixLead;
  int32_T c1_iyLead;
  int32_T c1_m;
  (void)chartInstance;
  c1_ixLead = 1;
  c1_iyLead = 0;
  c1_work = c1_b_x[0];
  for (c1_m = 0; c1_m < 179; c1_m++) {
    c1_tmp1 = c1_b_x[c1_ixLead];
    c1_tmp2 = c1_work;
    c1_work = c1_tmp1;
    c1_tmp1 -= c1_tmp2;
    c1_ixLead++;
    c1_b_y[c1_iyLead] = c1_tmp1;
    c1_iyLead++;
  }
}

static void c1_b_diff(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      real_T c1_b_x[179], real_T c1_b_y[178])
{
  real_T c1_tmp1;
  real_T c1_tmp2;
  real_T c1_work;
  int32_T c1_ixLead;
  int32_T c1_iyLead;
  int32_T c1_m;
  (void)chartInstance;
  c1_ixLead = 1;
  c1_iyLead = 0;
  c1_work = c1_b_x[0];
  for (c1_m = 0; c1_m < 178; c1_m++) {
    c1_tmp1 = c1_b_x[c1_ixLead];
    c1_tmp2 = c1_work;
    c1_work = c1_tmp1;
    c1_tmp1 -= c1_tmp2;
    c1_ixLead++;
    c1_b_y[c1_iyLead] = c1_tmp1;
    c1_iyLead++;
  }
}

static real_T c1_e_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_b_x[178])
{
  real_T c1_b_y;
  int32_T c1_b_k;
  int32_T c1_k;
  (void)chartInstance;
  c1_b_y = c1_b_x[0];
  for (c1_k = 0; c1_k < 177; c1_k++) {
    c1_b_k = c1_k;
    c1_b_y += c1_b_x[c1_b_k + 1];
  }

  return c1_b_y;
}

static void c1_houghlines(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_c_varargin_1[19200], real_T
  c1_varargin_4_data[], int32_T c1_varargin_4_size[2],
  c1_coder_array_s52BVvgcaqgLKaYLjO1 *c1_lines)
{
  static char_T c1_b_cv[30] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'h', 'o', 'u',
    'g', 'h', 'l', 'i', 'n', 'e', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'P', 'E', 'A', 'K', 'S' };

  c1_coder_array_int32_T_2D c1_b_point1Array;
  c1_coder_array_int32_T_2D c1_b_point2Array;
  c1_coder_array_int32_T_2D c1_houghPix;
  c1_coder_array_int32_T_2D c1_point1Array;
  c1_coder_array_int32_T_2D c1_point2Array;
  c1_coder_array_int32_T_2D c1_r;
  c1_coder_array_real32_T c1_rhoArray;
  c1_coder_array_real32_T c1_thetaArray;
  c1_coder_array_real_T c1_distances2;
  c1_coder_array_real_T c1_indices;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  real_T c1_tempBin[120];
  real_T c1_peaks_data[10];
  real_T c1_sortingOrder[2];
  real_T c1_b_j;
  real_T c1_b_n;
  real_T c1_b_numHoughPix;
  real_T c1_b_peakIdx;
  real_T c1_b_varargin_2;
  real_T c1_b_x;
  real_T c1_c_a;
  real_T c1_c_i;
  real_T c1_c_varargin_2;
  real_T c1_c_x;
  real_T c1_colMax;
  real_T c1_colMin;
  real_T c1_colRange;
  real_T c1_cosTheta;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_d_a;
  real_T c1_d_varargin_1;
  real_T c1_d_varargin_2;
  real_T c1_d_x;
  real_T c1_d_y;
  real_T c1_e_k;
  real_T c1_e_varargin_1;
  real_T c1_e_varargin_2;
  real_T c1_e_x;
  real_T c1_e_y;
  real_T c1_f_i;
  real_T c1_f_varargin_1;
  real_T c1_f_x;
  real_T c1_f_y;
  real_T c1_g_b;
  real_T c1_g_varargin_1;
  real_T c1_g_x;
  real_T c1_g_y;
  real_T c1_h_b;
  real_T c1_h_k;
  real_T c1_h_x;
  real_T c1_h_y;
  real_T c1_i_b;
  real_T c1_i_x;
  real_T c1_i_y;
  real_T c1_j_a;
  real_T c1_j_b;
  real_T c1_j_k;
  real_T c1_j_x;
  real_T c1_j_y;
  real_T c1_k_x;
  real_T c1_k_y;
  real_T c1_l_x;
  real_T c1_l_y;
  real_T c1_m_k;
  real_T c1_m_x;
  real_T c1_m_y;
  real_T c1_n;
  real_T c1_n_x;
  real_T c1_n_y;
  real_T c1_numPairs;
  real_T c1_numPeaks;
  real_T c1_o_x;
  real_T c1_o_y;
  real_T c1_p_a;
  real_T c1_p_x;
  real_T c1_p_y;
  real_T c1_q_x;
  real_T c1_q_y;
  real_T c1_r_x;
  real_T c1_r_y;
  real_T c1_rhoVal;
  real_T c1_rowMax;
  real_T c1_rowMin;
  real_T c1_rowRange;
  real_T c1_s_x;
  real_T c1_s_y;
  real_T c1_sinTheta;
  real_T c1_t_x;
  real_T c1_t_y;
  real_T c1_tempNum;
  real_T c1_thetaVal;
  real_T c1_u_x;
  real_T c1_u_y;
  real_T c1_v_x;
  real_T c1_v_y;
  real_T c1_w_x;
  real_T c1_w_y;
  real_T c1_x_x;
  int32_T c1_houghPixTemp[19200];
  int32_T c1_tempHoughPixNumsVector[160];
  int32_T c1_tempNumsVector[160];
  int32_T c1_b_tempBin[120];
  int32_T c1_peaks_size[2];
  int32_T c1_point1_data[2];
  int32_T c1_point1_size[2];
  int32_T c1_point2_data[2];
  int32_T c1_point2_size[2];
  int32_T c1_ab_a;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_bu;
  int32_T c1_b_c;
  int32_T c1_b_i;
  int32_T c1_b_indices;
  int32_T c1_b_k;
  int32_T c1_b_loop_ub;
  int32_T c1_b_numLines;
  int32_T c1_b_peak1;
  int32_T c1_b_peak2;
  int32_T c1_b_tempNum;
  int32_T c1_bu;
  int32_T c1_c;
  int32_T c1_c_b;
  int32_T c1_c_bu;
  int32_T c1_c_c;
  int32_T c1_c_indices;
  int32_T c1_c_j;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_c_numLines;
  int32_T c1_d_b;
  int32_T c1_d_bu;
  int32_T c1_d_c;
  int32_T c1_d_i;
  int32_T c1_d_j;
  int32_T c1_d_k;
  int32_T c1_d_loop_ub;
  int32_T c1_e_a;
  int32_T c1_e_b;
  int32_T c1_e_i;
  int32_T c1_e_j;
  int32_T c1_e_loop_ub;
  int32_T c1_exitg2;
  int32_T c1_f_a;
  int32_T c1_f_b;
  int32_T c1_f_k;
  int32_T c1_f_loop_ub;
  int32_T c1_g_a;
  int32_T c1_g_k;
  int32_T c1_g_loop_ub;
  int32_T c1_h_a;
  int32_T c1_h_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i5;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i6;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i7;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i8;
  int32_T c1_i80;
  int32_T c1_i9;
  int32_T c1_i_a;
  int32_T c1_i_k;
  int32_T c1_i_loop_ub;
  int32_T c1_j;
  int32_T c1_k;
  int32_T c1_k_a;
  int32_T c1_k_k;
  int32_T c1_l_a;
  int32_T c1_l_k;
  int32_T c1_lineLength2;
  int32_T c1_loop_ub;
  int32_T c1_m_a;
  int32_T c1_n_a;
  int32_T c1_numHoughPix;
  int32_T c1_numLines;
  int32_T c1_o_a;
  int32_T c1_peak1;
  int32_T c1_peak2;
  int32_T c1_peakIdx;
  int32_T c1_q_a;
  int32_T c1_r_a;
  int32_T c1_rhoBinIdx;
  int32_T c1_s_a;
  int32_T c1_t_a;
  int32_T c1_u_a;
  int32_T c1_v_a;
  int32_T c1_w_a;
  int32_T c1_x_a;
  int32_T c1_y_a;
  boolean_T c1_b_overflow;
  boolean_T c1_c_overflow;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_st.site = &c1_hi_emlrtRSI;
  c1_b_st.site = &c1_ni_emlrtRSI;
  c1_d_validateattributes(chartInstance, &c1_b_st, c1_varargin_4_data,
    c1_varargin_4_size);
  if ((real_T)c1_varargin_4_size[1] != 2.0) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c1_st, &c1_eb_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_c_y)));
  }

  c1_peaks_size[0] = c1_varargin_4_size[0];
  c1_loop_ub = c1_varargin_4_size[0] * c1_varargin_4_size[1] - 1;
  for (c1_i = 0; c1_i <= c1_loop_ub; c1_i++) {
    c1_peaks_data[c1_i] = c1_varargin_4_data[c1_i];
  }

  c1_st.site = &c1_ii_emlrtRSI;
  for (c1_j = 0; c1_j < 160; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    c1_tempNum = 0.0;
    for (c1_b_i = 0; c1_b_i < 120; c1_b_i++) {
      c1_c_i = (real_T)c1_b_i + 1.0;
      if (c1_c_varargin_1[((int32_T)c1_c_i + 120 * ((int32_T)c1_b_j - 1)) - 1])
      {
        c1_tempNum++;
        c1_i1 = (int32_T)c1_tempNum;
        if ((c1_i1 < 1) || (c1_i1 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c1_i1, 1, 120, &c1_nf_emlrtBCI, &c1_st);
        }

        c1_tempBin[c1_i1 - 1] = c1_c_i - 1.0;
      }
    }

    c1_tempNumsVector[(int32_T)c1_b_j - 1] = (int32_T)c1_tempNum;
    c1_d_i = 0;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_d_i < 120)) {
      c1_c_i = (real_T)c1_d_i + 1.0;
      if (c1_c_i > c1_tempNum) {
        c1_exitg1 = true;
      } else {
        chartInstance->c1_nonZeroPixelMatrix[((int32_T)c1_c_i + 120 * ((int32_T)
          c1_b_j - 1)) - 1] = (int32_T)c1_tempBin[(int32_T)c1_c_i - 1];
        c1_d_i++;
      }
    }
  }

  c1_numLines = 0;
  c1_array_int32_T_2D_Constructor(chartInstance, &c1_point1Array);
  c1_st.site = &c1_hk_emlrtRSI;
  c1_array_int32_T_2D_SetSize(chartInstance, &c1_st, &c1_point1Array,
    &c1_re_emlrtRTEI, 0, 2);
  c1_array_int32_T_2D_Constructor(chartInstance, &c1_point2Array);
  c1_st.site = &c1_gk_emlrtRSI;
  c1_array_int32_T_2D_SetSize(chartInstance, &c1_st, &c1_point2Array,
    &c1_se_emlrtRTEI, 0, 2);
  c1_array_real32_T_Constructor(chartInstance, &c1_thetaArray);
  c1_st.site = &c1_lk_emlrtRSI;
  c1_array_real32_T_SetSize(chartInstance, &c1_st, &c1_thetaArray,
    &c1_te_emlrtRTEI, 0);
  c1_array_real32_T_Constructor(chartInstance, &c1_rhoArray);
  c1_st.site = &c1_kk_emlrtRSI;
  c1_array_real32_T_SetSize(chartInstance, &c1_st, &c1_rhoArray,
    &c1_ue_emlrtRTEI, 0);
  c1_numPeaks = (real_T)c1_peaks_size[0];
  c1_i2 = (int32_T)c1_numPeaks - 1;
  c1_array_real_T_Constructor(chartInstance, &c1_indices);
  c1_array_int32_T_2D_Constructor(chartInstance, &c1_houghPix);
  c1_array_real_T_Constructor(chartInstance, &c1_distances2);
  c1_array_int32_T_2D_Constructor(chartInstance, &c1_r);
  c1_array_int32_T_2D_Constructor(chartInstance, &c1_b_point1Array);
  c1_array_int32_T_2D_Constructor(chartInstance, &c1_b_point2Array);
  for (c1_peakIdx = 0; c1_peakIdx <= c1_i2; c1_peakIdx++) {
    c1_b_peakIdx = (real_T)c1_peakIdx + 1.0;
    c1_i3 = (int32_T)c1_b_peakIdx;
    if ((c1_i3 < 1) || (c1_i3 > c1_peaks_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c1_i3, 1, c1_peaks_size[0], &c1_bg_emlrtBCI,
        (emlrtConstCTX)c1_sp);
    }

    c1_peak1 = (int32_T)c1_peaks_data[c1_i3 - 1];
    c1_i4 = (int32_T)c1_b_peakIdx;
    if ((c1_i4 < 1) || (c1_i4 > c1_peaks_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c1_i4, 1, c1_peaks_size[0], &c1_cg_emlrtBCI,
        (emlrtConstCTX)c1_sp);
    }

    c1_peak2 = (int32_T)c1_peaks_data[(c1_i4 + c1_peaks_size[0]) - 1];
    c1_st.site = &c1_ji_emlrtRSI;
    c1_b_peak1 = c1_peak1;
    c1_b_peak2 = c1_peak2;
    c1_numHoughPix = 0;
    if ((c1_b_peak2 < 1) || (c1_b_peak2 > 180)) {
      emlrtDynamicBoundsCheckR2012b(c1_b_peak2, 1, 180, &c1_rf_emlrtBCI, &c1_st);
    }

    c1_thetaVal = (-90.0 + (real_T)(c1_b_peak2 - 1)) * 3.1415926535897931 /
      180.0;
    c1_b_x = c1_thetaVal;
    c1_cosTheta = c1_b_x;
    c1_cosTheta = muDoubleScalarCos(c1_cosTheta);
    c1_c_x = c1_thetaVal;
    c1_sinTheta = c1_c_x;
    c1_sinTheta = muDoubleScalarSin(c1_sinTheta);
    c1_rowMax = 0.0;
    c1_rowMin = rtInf;
    c1_colMax = 0.0;
    c1_colMin = rtInf;
    for (c1_d_k = 0; c1_d_k < 160; c1_d_k++) {
      c1_e_k = (real_T)c1_d_k + 1.0;
      c1_b_tempNum = 0;
      c1_i9 = c1_tempNumsVector[(int32_T)c1_e_k - 1];
      c1_b_st.site = &c1_qi_emlrtRSI;
      c1_c_b = c1_i9;
      c1_d_b = c1_c_b;
      if (c1_d_b < 1) {
        c1_b_overflow = false;
      } else {
        c1_b_overflow = (c1_d_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_c_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
      }

      c1_i17 = (uint8_T)c1_i9 - 1;
      for (c1_c_j = 0; c1_c_j <= c1_i17; c1_c_j++) {
        c1_d_j = c1_c_j;
        c1_rhoVal = (c1_e_k - 1.0) * c1_cosTheta + (real_T)
          chartInstance->c1_nonZeroPixelMatrix[c1_d_j + 120 * ((int32_T)c1_e_k -
          1)] * c1_sinTheta;
        c1_d_x = (c1_rhoVal - -199.0) + 1.0;
        c1_rhoBinIdx = (int32_T)(c1_d_x + 0.5);
        if (c1_rhoBinIdx == c1_b_peak1) {
          c1_b_tempNum++;
          if ((c1_b_tempNum < 1) || (c1_b_tempNum > 120)) {
            emlrtDynamicBoundsCheckR2012b(c1_b_tempNum, 1, 120, &c1_kg_emlrtBCI,
              &c1_st);
          }

          c1_b_tempBin[c1_b_tempNum - 1] = chartInstance->
            c1_nonZeroPixelMatrix[c1_d_j + 120 * ((int32_T)c1_e_k - 1)] + 1;
        }
      }

      c1_tempHoughPixNumsVector[(int32_T)c1_e_k - 1] = c1_b_tempNum;
      c1_numHoughPix += c1_b_tempNum;
      if (c1_b_tempNum != 0) {
        c1_d_varargin_1 = c1_rowMax;
        c1_b_varargin_2 = (real_T)c1_b_tempBin[c1_b_tempNum - 1];
        c1_e_x = c1_d_varargin_1;
        c1_d_y = c1_b_varargin_2;
        c1_f_x = c1_e_x;
        c1_e_y = c1_d_y;
        c1_g_x = c1_f_x;
        c1_f_y = c1_e_y;
        c1_c_a = c1_g_x;
        c1_g_b = c1_f_y;
        c1_h_x = c1_c_a;
        c1_g_y = c1_g_b;
        c1_i_x = c1_h_x;
        c1_h_y = c1_g_y;
        c1_rowMax = muDoubleScalarMax(c1_i_x, c1_h_y);
        c1_e_varargin_1 = c1_rowMin;
        c1_c_varargin_2 = (real_T)c1_b_tempBin[0];
        c1_j_x = c1_e_varargin_1;
        c1_i_y = c1_c_varargin_2;
        c1_k_x = c1_j_x;
        c1_j_y = c1_i_y;
        c1_l_x = c1_k_x;
        c1_k_y = c1_j_y;
        c1_d_a = c1_l_x;
        c1_h_b = c1_k_y;
        c1_m_x = c1_d_a;
        c1_l_y = c1_h_b;
        c1_n_x = c1_m_x;
        c1_m_y = c1_l_y;
        c1_rowMin = muDoubleScalarMin(c1_n_x, c1_m_y);
        c1_f_varargin_1 = c1_colMax;
        c1_d_varargin_2 = c1_e_k;
        c1_o_x = c1_f_varargin_1;
        c1_n_y = c1_d_varargin_2;
        c1_p_x = c1_o_x;
        c1_o_y = c1_n_y;
        c1_q_x = c1_p_x;
        c1_p_y = c1_o_y;
        c1_j_a = c1_q_x;
        c1_i_b = c1_p_y;
        c1_r_x = c1_j_a;
        c1_q_y = c1_i_b;
        c1_s_x = c1_r_x;
        c1_r_y = c1_q_y;
        c1_colMax = muDoubleScalarMax(c1_s_x, c1_r_y);
        c1_g_varargin_1 = c1_colMin;
        c1_e_varargin_2 = c1_e_k;
        c1_t_x = c1_g_varargin_1;
        c1_s_y = c1_e_varargin_2;
        c1_u_x = c1_t_x;
        c1_t_y = c1_s_y;
        c1_v_x = c1_u_x;
        c1_u_y = c1_t_y;
        c1_p_a = c1_v_x;
        c1_j_b = c1_u_y;
        c1_w_x = c1_p_a;
        c1_v_y = c1_j_b;
        c1_x_x = c1_w_x;
        c1_w_y = c1_v_y;
        c1_colMin = muDoubleScalarMin(c1_x_x, c1_w_y);
      }

      c1_e_i = 0;
      c1_exitg1 = false;
      while ((!c1_exitg1) && (c1_e_i < 120)) {
        c1_f_i = (real_T)c1_e_i + 1.0;
        if (c1_f_i > (real_T)c1_b_tempNum) {
          c1_exitg1 = true;
        } else {
          c1_houghPixTemp[((int32_T)c1_f_i + 120 * ((int32_T)c1_e_k - 1)) - 1] =
            c1_b_tempBin[(int32_T)c1_f_i - 1];
          c1_e_i++;
        }
      }
    }

    if (c1_numHoughPix < 1) {
      c1_array_int32_T_2D_SetSize(chartInstance, &c1_st, &c1_houghPix,
        &c1_xe_emlrtRTEI, 0, 0);
    } else {
      c1_n = 0.0;
      for (c1_f_k = 0; c1_f_k < 160; c1_f_k++) {
        c1_h_k = (real_T)c1_f_k + 1.0;
        c1_i11 = c1_tempHoughPixNumsVector[(int32_T)c1_h_k - 1];
        c1_b_st.site = &c1_pi_emlrtRSI;
        c1_e_b = c1_i11;
        c1_f_b = c1_e_b;
        if (c1_f_b < 1) {
          c1_c_overflow = false;
        } else {
          c1_c_overflow = (c1_f_b > 2147483646);
        }

        if (c1_c_overflow) {
          c1_c_st.site = &c1_yc_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
        }

        c1_i21 = (uint8_T)c1_i11 - 1;
        for (c1_e_j = 0; c1_e_j <= c1_i21; c1_e_j++) {
          c1_d_j = c1_e_j;
          c1_n++;
          c1_i26 = (int32_T)c1_n;
          if ((c1_i26 < 1) || (c1_i26 > 19200)) {
            emlrtDynamicBoundsCheckR2012b(c1_i26, 1, 19200, &c1_jg_emlrtBCI,
              &c1_st);
          }

          chartInstance->c1_houghPixIdx[c1_i26 - 1] = c1_houghPixTemp[c1_d_j +
            120 * ((int32_T)c1_h_k - 1)];
          chartInstance->c1_houghPixIdx[(int32_T)c1_n + 19199] = (int32_T)c1_h_k;
        }
      }

      c1_rowRange = c1_rowMax - c1_rowMin;
      c1_colRange = c1_colMax - c1_colMin;
      if (c1_rowRange > c1_colRange) {
        for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
          c1_sortingOrder[c1_i15] = 1.0 + (real_T)c1_i15;
        }
      } else {
        for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
          c1_sortingOrder[c1_i14] = 2.0 - (real_T)c1_i14;
        }
      }

      if ((c1_numHoughPix < 1) || (c1_numHoughPix > 19200)) {
        emlrtDynamicBoundsCheckR2012b(c1_numHoughPix, 1, 19200, &c1_qf_emlrtBCI,
          &c1_st);
      }

      c1_i18 = c1_numHoughPix - 1;
      c1_array_int32_T_2D_SetSize(chartInstance, &c1_st, &c1_r, &c1_ve_emlrtRTEI,
        c1_i18 + 1, 2);
      for (c1_i20 = 0; c1_i20 < 2; c1_i20++) {
        c1_b_loop_ub = c1_i18;
        for (c1_i24 = 0; c1_i24 <= c1_b_loop_ub; c1_i24++) {
          c1_r.vector.data[c1_i24 + c1_r.size[0] * c1_i20] =
            chartInstance->c1_houghPixIdx[c1_i24 + 19200 * c1_i20];
        }
      }

      c1_b_st.site = &c1_oi_emlrtRSI;
      c1_b_sortrows(chartInstance, &c1_b_st, &c1_r, c1_sortingOrder);
      c1_array_int32_T_2D_SetSize(chartInstance, &c1_st, &c1_houghPix,
        &c1_we_emlrtRTEI, c1_r.size[0], 2);
      c1_c_loop_ub = (c1_r.size[0] << 1) - 1;
      for (c1_i28 = 0; c1_i28 <= c1_c_loop_ub; c1_i28++) {
        c1_houghPix.vector.data[c1_i28] = c1_r.vector.data[c1_i28];
      }
    }

    if (c1_numHoughPix >= 1) {
      c1_st.site = &c1_ki_emlrtRSI;
      c1_b_numHoughPix = (real_T)c1_houghPix.size[0];
      c1_b_st.site = &c1_yi_emlrtRSI;
      c1_c_st.site = &c1_t_emlrtRSI;
      c1_d = c1_b_numHoughPix - 1.0;
      if (!(c1_d >= 0.0)) {
        emlrtNonNegativeCheckR2012b(c1_d, &c1_l_emlrtDCI, &c1_st);
      }

      c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_distances2,
        &c1_ye_emlrtRTEI, (int32_T)c1_d);
      c1_numPairs = 0.0;
      c1_d1 = c1_b_numHoughPix - 1.0;
      c1_i22 = (int32_T)c1_d1 - 1;
      for (c1_i_k = 0; c1_i_k <= c1_i22; c1_i_k++) {
        c1_j_k = (real_T)c1_i_k + 1.0;
        c1_i25 = c1_houghPix.size[1];
        c1_i27 = 1;
        if ((c1_i27 < 1) || (c1_i27 > c1_i25)) {
          emlrtDynamicBoundsCheckR2012b(c1_i27, 1, c1_i25, &c1_sf_emlrtBCI,
            &c1_st);
        }

        c1_i30 = c1_houghPix.size[1];
        c1_i32 = 1;
        if ((c1_i32 < 1) || (c1_i32 > c1_i30)) {
          emlrtDynamicBoundsCheckR2012b(c1_i32, 1, c1_i30, &c1_tf_emlrtBCI,
            &c1_st);
        }

        c1_i33 = c1_houghPix.size[1];
        c1_i34 = 2;
        if ((c1_i34 < 1) || (c1_i34 > c1_i33)) {
          emlrtDynamicBoundsCheckR2012b(c1_i34, 1, c1_i33, &c1_uf_emlrtBCI,
            &c1_st);
        }

        c1_i36 = c1_houghPix.size[1];
        c1_i37 = 2;
        if ((c1_i37 < 1) || (c1_i37 > c1_i36)) {
          emlrtDynamicBoundsCheckR2012b(c1_i37, 1, c1_i36, &c1_vf_emlrtBCI,
            &c1_st);
        }

        c1_i41 = c1_houghPix.size[0];
        c1_i42 = (int32_T)(c1_j_k + 1.0);
        if ((c1_i42 < 1) || (c1_i42 > c1_i41)) {
          emlrtDynamicBoundsCheckR2012b(c1_i42, 1, c1_i41, &c1_mg_emlrtBCI,
            &c1_st);
        }

        c1_i45 = c1_houghPix.size[0];
        c1_i48 = (int32_T)c1_j_k;
        if ((c1_i48 < 1) || (c1_i48 > c1_i45)) {
          emlrtDynamicBoundsCheckR2012b(c1_i48, 1, c1_i45, &c1_ng_emlrtBCI,
            &c1_st);
        }

        c1_e_a = c1_houghPix.vector.data[c1_i42 - 1] -
          c1_houghPix.vector.data[c1_i48 - 1];
        c1_f_a = c1_e_a;
        c1_g_a = c1_f_a;
        c1_h_a = c1_g_a;
        c1_i_a = c1_h_a;
        c1_c = 1;
        c1_bu = 2;
        do {
          c1_exitg2 = 0;
          if ((c1_bu & 1) != 0) {
            c1_c *= c1_i_a;
          }

          c1_bu >>= 1;
          if (c1_bu == 0) {
            c1_exitg2 = 1;
          } else {
            c1_i_a *= c1_i_a;
          }
        } while (c1_exitg2 == 0);

        c1_i56 = c1_houghPix.size[0];
        c1_i57 = (int32_T)(c1_j_k + 1.0);
        if ((c1_i57 < 1) || (c1_i57 > c1_i56)) {
          emlrtDynamicBoundsCheckR2012b(c1_i57, 1, c1_i56, &c1_sg_emlrtBCI,
            &c1_st);
        }

        c1_i59 = c1_houghPix.size[0];
        c1_i60 = (int32_T)c1_j_k;
        if ((c1_i60 < 1) || (c1_i60 > c1_i59)) {
          emlrtDynamicBoundsCheckR2012b(c1_i60, 1, c1_i59, &c1_tg_emlrtBCI,
            &c1_st);
        }

        c1_k_a = c1_houghPix.vector.data[(c1_i57 + c1_houghPix.size[0]) - 1] -
          c1_houghPix.vector.data[(c1_i60 + c1_houghPix.size[0]) - 1];
        c1_l_a = c1_k_a;
        c1_m_a = c1_l_a;
        c1_n_a = c1_m_a;
        c1_o_a = c1_n_a;
        c1_b_c = 1;
        c1_b_bu = 2;
        do {
          c1_exitg2 = 0;
          if ((c1_b_bu & 1) != 0) {
            c1_b_c *= c1_o_a;
          }

          c1_b_bu >>= 1;
          if (c1_b_bu == 0) {
            c1_exitg2 = 1;
          } else {
            c1_o_a *= c1_o_a;
          }
        } while (c1_exitg2 == 0);

        c1_i65 = c1_distances2.size[0];
        c1_i66 = (int32_T)c1_j_k;
        if ((c1_i66 < 1) || (c1_i66 > c1_i65)) {
          emlrtDynamicBoundsCheckR2012b(c1_i66, 1, c1_i65, &c1_ug_emlrtBCI,
            &c1_st);
        }

        c1_distances2.vector.data[c1_i66 - 1] = (real_T)(c1_c + c1_b_c);
        c1_i67 = c1_distances2.size[0];
        c1_i68 = (int32_T)c1_j_k;
        if ((c1_i68 < 1) || (c1_i68 > c1_i67)) {
          emlrtDynamicBoundsCheckR2012b(c1_i68, 1, c1_i67, &c1_vg_emlrtBCI,
            &c1_st);
        }

        if (c1_distances2.vector.data[c1_i68 - 1] > 25.0) {
          c1_numPairs++;
        }
      }

      c1_d2 = c1_numPairs + 2.0;
      if (c1_d2 != (real_T)(int32_T)muDoubleScalarFloor(c1_d2)) {
        emlrtIntegerCheckR2012b(c1_d2, &c1_m_emlrtDCI, &c1_st);
      }

      c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_indices,
        &c1_af_emlrtRTEI, (int32_T)c1_d2);
      c1_indices.vector.data[0] = 0.0;
      c1_i29 = c1_indices.size[0];
      c1_i31 = c1_indices.size[0];
      if ((c1_i31 < 1) || (c1_i31 > c1_i29)) {
        emlrtDynamicBoundsCheckR2012b(c1_i31, 1, c1_i29, &c1_lg_emlrtBCI, &c1_st);
      }

      c1_indices.vector.data[c1_i31 - 1] = c1_b_numHoughPix;
      c1_b_n = 1.0;
      c1_d3 = c1_b_numHoughPix - 1.0;
      c1_i35 = (int32_T)c1_d3 - 1;
      for (c1_k_k = 0; c1_k_k <= c1_i35; c1_k_k++) {
        c1_j_k = (real_T)c1_k_k + 1.0;
        c1_i39 = c1_distances2.size[0];
        c1_i40 = (int32_T)c1_j_k;
        if ((c1_i40 < 1) || (c1_i40 > c1_i39)) {
          emlrtDynamicBoundsCheckR2012b(c1_i40, 1, c1_i39, &c1_og_emlrtBCI,
            &c1_st);
        }

        if (c1_distances2.vector.data[c1_i40 - 1] > 25.0) {
          c1_b_n++;
          c1_i47 = c1_indices.size[0];
          c1_i49 = (int32_T)c1_b_n;
          if ((c1_i49 < 1) || (c1_i49 > c1_i47)) {
            emlrtDynamicBoundsCheckR2012b(c1_i49, 1, c1_i47, &c1_pg_emlrtBCI,
              &c1_st);
          }

          c1_indices.vector.data[c1_i49 - 1] = c1_j_k;
        }
      }

      c1_d4 = (real_T)c1_indices.size[0] - 1.0;
      c1_i38 = (int32_T)c1_d4 - 1;
      for (c1_l_k = 0; c1_l_k <= c1_i38; c1_l_k++) {
        c1_m_k = (real_T)c1_l_k + 1.0;
        c1_i43 = c1_houghPix.size[0];
        c1_i44 = c1_indices.size[0];
        c1_i46 = (int32_T)c1_m_k;
        if ((c1_i46 < 1) || (c1_i46 > c1_i44)) {
          emlrtDynamicBoundsCheckR2012b(c1_i46, 1, c1_i44, &c1_qg_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_i50 = (int32_T)(c1_indices.vector.data[c1_i46 - 1] + 1.0);
        if ((c1_i50 < 1) || (c1_i50 > c1_i43)) {
          emlrtDynamicBoundsCheckR2012b(c1_i50, 1, c1_i43, &c1_hf_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_b_indices = c1_i50 - 1;
        c1_point1_size[1] = c1_houghPix.size[1];
        c1_d_loop_ub = c1_houghPix.size[1] - 1;
        for (c1_i51 = 0; c1_i51 <= c1_d_loop_ub; c1_i51++) {
          c1_point1_data[c1_i51] = c1_houghPix.vector.data[c1_b_indices +
            c1_houghPix.size[0] * c1_i51];
        }

        c1_i52 = c1_houghPix.size[0];
        c1_i53 = c1_indices.size[0];
        c1_i54 = (int32_T)(c1_m_k + 1.0);
        if ((c1_i54 < 1) || (c1_i54 > c1_i53)) {
          emlrtDynamicBoundsCheckR2012b(c1_i54, 1, c1_i53, &c1_rg_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_i55 = (int32_T)c1_indices.vector.data[c1_i54 - 1];
        if ((c1_i55 < 1) || (c1_i55 > c1_i52)) {
          emlrtDynamicBoundsCheckR2012b(c1_i55, 1, c1_i52, &c1_if_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_c_indices = c1_i55 - 1;
        c1_point2_size[1] = c1_houghPix.size[1];
        c1_e_loop_ub = c1_houghPix.size[1] - 1;
        for (c1_i58 = 0; c1_i58 <= c1_e_loop_ub; c1_i58++) {
          c1_point2_data[c1_i58] = c1_houghPix.vector.data[c1_c_indices +
            c1_houghPix.size[0] * c1_i58];
        }

        c1_st.site = &c1_li_emlrtRSI;
        c1_i61 = 1;
        if ((c1_i61 < 1) || (c1_i61 > c1_point2_size[1])) {
          emlrtDynamicBoundsCheckR2012b(c1_i61, 1, c1_point2_size[1],
            &c1_wf_emlrtBCI, &c1_st);
        }

        c1_i62 = 1;
        if ((c1_i62 < 1) || (c1_i62 > c1_point1_size[1])) {
          emlrtDynamicBoundsCheckR2012b(c1_i62, 1, c1_point1_size[1],
            &c1_xf_emlrtBCI, &c1_st);
        }

        c1_i63 = 2;
        if ((c1_i63 < 1) || (c1_i63 > c1_point2_size[1])) {
          emlrtDynamicBoundsCheckR2012b(c1_i63, 1, c1_point2_size[1],
            &c1_yf_emlrtBCI, &c1_st);
        }

        c1_i64 = 2;
        if ((c1_i64 < 1) || (c1_i64 > c1_point1_size[1])) {
          emlrtDynamicBoundsCheckR2012b(c1_i64, 1, c1_point1_size[1],
            &c1_ag_emlrtBCI, &c1_st);
        }

        c1_q_a = c1_point2_data[0] - c1_point1_data[0];
        c1_r_a = c1_q_a;
        c1_s_a = c1_r_a;
        c1_t_a = c1_s_a;
        c1_u_a = c1_t_a;
        c1_c_c = 1;
        c1_c_bu = 2;
        do {
          c1_exitg2 = 0;
          if ((c1_c_bu & 1) != 0) {
            c1_c_c *= c1_u_a;
          }

          c1_c_bu >>= 1;
          if (c1_c_bu == 0) {
            c1_exitg2 = 1;
          } else {
            c1_u_a *= c1_u_a;
          }
        } while (c1_exitg2 == 0);

        c1_v_a = c1_point2_data[1] - c1_point1_data[1];
        c1_w_a = c1_v_a;
        c1_x_a = c1_w_a;
        c1_y_a = c1_x_a;
        c1_ab_a = c1_y_a;
        c1_d_c = 1;
        c1_d_bu = 2;
        do {
          c1_exitg2 = 0;
          if ((c1_d_bu & 1) != 0) {
            c1_d_c *= c1_ab_a;
          }

          c1_d_bu >>= 1;
          if (c1_d_bu == 0) {
            c1_exitg2 = 1;
          } else {
            c1_ab_a *= c1_ab_a;
          }
        } while (c1_exitg2 == 0);

        c1_lineLength2 = c1_c_c + c1_d_c;
        if (c1_lineLength2 >= 100) {
          c1_numLines++;
          c1_i69 = 2;
          if ((c1_i69 < 1) || (c1_i69 > c1_point1_size[1])) {
            emlrtDynamicBoundsCheckR2012b(c1_i69, 1, c1_point1_size[1],
              &c1_jf_emlrtBCI, (emlrtConstCTX)c1_sp);
          }

          c1_i70 = 1;
          if ((c1_i70 < 1) || (c1_i70 > c1_point1_size[1])) {
            emlrtDynamicBoundsCheckR2012b(c1_i70, 1, c1_point1_size[1],
              &c1_kf_emlrtBCI, (emlrtConstCTX)c1_sp);
          }

          c1_st.site = &c1_fk_emlrtRSI;
          c1_array_int32_T_2D_SetSize(chartInstance, &c1_st, &c1_b_point1Array,
            &c1_df_emlrtRTEI, c1_point1Array.size[0] + 1, 2);
          for (c1_i71 = 0; c1_i71 < 2; c1_i71++) {
            c1_f_loop_ub = c1_point1Array.size[0] - 1;
            for (c1_i72 = 0; c1_i72 <= c1_f_loop_ub; c1_i72++) {
              c1_b_point1Array.vector.data[c1_i72 + c1_b_point1Array.size[0] *
                c1_i71] = c1_point1Array.vector.data[c1_i72 +
                c1_point1Array.size[0] * c1_i71];
            }
          }

          c1_b_point1Array.vector.data[c1_point1Array.size[0]] = c1_point1_data
            [1];
          c1_b_point1Array.vector.data[c1_point1Array.size[0] +
            c1_b_point1Array.size[0]] = c1_point1_data[0];
          c1_st.site = &c1_fk_emlrtRSI;
          c1_array_int32_T_2D_SetSize(chartInstance, &c1_st, &c1_point1Array,
            &c1_ef_emlrtRTEI, c1_b_point1Array.size[0], 2);
          c1_g_loop_ub = (c1_b_point1Array.size[0] << 1) - 1;
          for (c1_i73 = 0; c1_i73 <= c1_g_loop_ub; c1_i73++) {
            c1_point1Array.vector.data[c1_i73] =
              c1_b_point1Array.vector.data[c1_i73];
          }

          c1_i74 = 2;
          if ((c1_i74 < 1) || (c1_i74 > c1_point2_size[1])) {
            emlrtDynamicBoundsCheckR2012b(c1_i74, 1, c1_point2_size[1],
              &c1_lf_emlrtBCI, (emlrtConstCTX)c1_sp);
          }

          c1_i75 = 1;
          if ((c1_i75 < 1) || (c1_i75 > c1_point2_size[1])) {
            emlrtDynamicBoundsCheckR2012b(c1_i75, 1, c1_point2_size[1],
              &c1_mf_emlrtBCI, (emlrtConstCTX)c1_sp);
          }

          c1_st.site = &c1_ek_emlrtRSI;
          c1_array_int32_T_2D_SetSize(chartInstance, &c1_st, &c1_b_point2Array,
            &c1_ff_emlrtRTEI, c1_point2Array.size[0] + 1, 2);
          for (c1_i76 = 0; c1_i76 < 2; c1_i76++) {
            c1_h_loop_ub = c1_point2Array.size[0] - 1;
            for (c1_i77 = 0; c1_i77 <= c1_h_loop_ub; c1_i77++) {
              c1_b_point2Array.vector.data[c1_i77 + c1_b_point2Array.size[0] *
                c1_i76] = c1_point2Array.vector.data[c1_i77 +
                c1_point2Array.size[0] * c1_i76];
            }
          }

          c1_b_point2Array.vector.data[c1_point2Array.size[0]] = c1_point2_data
            [1];
          c1_b_point2Array.vector.data[c1_point2Array.size[0] +
            c1_b_point2Array.size[0]] = c1_point2_data[0];
          c1_st.site = &c1_ek_emlrtRSI;
          c1_array_int32_T_2D_SetSize(chartInstance, &c1_st, &c1_point2Array,
            &c1_gf_emlrtRTEI, c1_b_point2Array.size[0], 2);
          c1_i_loop_ub = (c1_b_point2Array.size[0] << 1) - 1;
          for (c1_i78 = 0; c1_i78 <= c1_i_loop_ub; c1_i78++) {
            c1_point2Array.vector.data[c1_i78] =
              c1_b_point2Array.vector.data[c1_i78];
          }

          c1_i79 = c1_thetaArray.size[0];
          c1_st.site = &c1_jk_emlrtRSI;
          c1_array_real32_T_SetSize(chartInstance, &c1_st, &c1_thetaArray,
            &c1_hf_emlrtRTEI, c1_thetaArray.size[0] + 1);
          if ((c1_peak2 < 1) || (c1_peak2 > 180)) {
            emlrtDynamicBoundsCheckR2012b(c1_peak2, 1, 180, &c1_wg_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_thetaArray.vector.data[c1_i79] = (real32_T)(-90.0 + (real_T)
            (c1_peak2 - 1));
          c1_i80 = c1_rhoArray.size[0];
          c1_st.site = &c1_ik_emlrtRSI;
          c1_array_real32_T_SetSize(chartInstance, &c1_st, &c1_rhoArray,
            &c1_if_emlrtRTEI, c1_rhoArray.size[0] + 1);
          if ((c1_peak1 < 1) || (c1_peak1 > 399)) {
            emlrtDynamicBoundsCheckR2012b(c1_peak1, 1, 399, &c1_xg_emlrtBCI,
              (emlrtConstCTX)c1_sp);
          }

          c1_rhoArray.vector.data[c1_i80] = (real32_T)(-199.0 + (real_T)
            (c1_peak1 - 1));
        }
      }
    }
  }

  c1_array_int32_T_2D_Destructor(chartInstance, &c1_b_point2Array);
  c1_array_int32_T_2D_Destructor(chartInstance, &c1_b_point1Array);
  c1_array_int32_T_2D_Destructor(chartInstance, &c1_r);
  c1_array_real_T_Destructor(chartInstance, &c1_distances2);
  c1_array_int32_T_2D_Destructor(chartInstance, &c1_houghPix);
  c1_array_real_T_Destructor(chartInstance, &c1_indices);
  c1_st.site = &c1_mi_emlrtRSI;
  c1_b_numLines = c1_numLines;
  c1_b_st.site = &c1_aj_emlrtRSI;
  c1_c_numLines = c1_b_numLines;
  c1_c_st.site = &c1_cj_emlrtRSI;
  c1_b_repmat(chartInstance, &c1_c_st, c1_c_numLines, c1_lines);
  c1_b_st.site = &c1_bj_emlrtRSI;
  c1_b = c1_b_numLines;
  c1_b_b = c1_b;
  if (c1_b_b < 1) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_b_b > 2147483646);
  }

  if (c1_overflow) {
    c1_c_st.site = &c1_yc_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
  }

  for (c1_k = 0; c1_k < c1_b_numLines; c1_k++) {
    c1_b_k = c1_k + 1;
    c1_i5 = c1_point1Array.size[0];
    if ((c1_b_k < 1) || (c1_b_k > c1_i5)) {
      emlrtDynamicBoundsCheckR2012b(c1_b_k, 1, c1_i5, &c1_of_emlrtBCI, &c1_st);
    }

    c1_c_k = c1_b_k - 1;
    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_i8 = c1_lines->size[1];
      if ((c1_b_k < 1) || (c1_b_k > c1_i8)) {
        emlrtDynamicBoundsCheckR2012b(c1_b_k, 1, c1_i8, &c1_dg_emlrtBCI, &c1_st);
      }

      c1_lines->vector.data[c1_b_k - 1].point1[c1_i6] = (real_T)
        c1_point1Array.vector.data[c1_c_k + c1_point1Array.size[0] * c1_i6];
    }

    c1_i7 = c1_point2Array.size[0];
    if ((c1_b_k < 1) || (c1_b_k > c1_i7)) {
      emlrtDynamicBoundsCheckR2012b(c1_b_k, 1, c1_i7, &c1_pf_emlrtBCI, &c1_st);
    }

    c1_g_k = c1_b_k - 1;
    for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
      c1_i13 = c1_lines->size[1];
      if ((c1_b_k < 1) || (c1_b_k > c1_i13)) {
        emlrtDynamicBoundsCheckR2012b(c1_b_k, 1, c1_i13, &c1_eg_emlrtBCI, &c1_st);
      }

      c1_lines->vector.data[c1_b_k - 1].point2[c1_i10] = (real_T)
        c1_point2Array.vector.data[c1_g_k + c1_point2Array.size[0] * c1_i10];
    }

    c1_i12 = c1_thetaArray.size[0];
    if ((c1_b_k < 1) || (c1_b_k > c1_i12)) {
      emlrtDynamicBoundsCheckR2012b(c1_b_k, 1, c1_i12, &c1_fg_emlrtBCI, &c1_st);
    }

    c1_i16 = c1_lines->size[1];
    if ((c1_b_k < 1) || (c1_b_k > c1_i16)) {
      emlrtDynamicBoundsCheckR2012b(c1_b_k, 1, c1_i16, &c1_gg_emlrtBCI, &c1_st);
    }

    c1_lines->vector.data[c1_b_k - 1].theta = c1_thetaArray.vector.data[c1_b_k -
      1];
    c1_i19 = c1_rhoArray.size[0];
    if ((c1_b_k < 1) || (c1_b_k > c1_i19)) {
      emlrtDynamicBoundsCheckR2012b(c1_b_k, 1, c1_i19, &c1_hg_emlrtBCI, &c1_st);
    }

    c1_i23 = c1_lines->size[1];
    if ((c1_b_k < 1) || (c1_b_k > c1_i23)) {
      emlrtDynamicBoundsCheckR2012b(c1_b_k, 1, c1_i23, &c1_ig_emlrtBCI, &c1_st);
    }

    c1_lines->vector.data[c1_b_k - 1].rho = c1_rhoArray.vector.data[c1_b_k - 1];
  }

  c1_array_real32_T_Destructor(chartInstance, &c1_rhoArray);
  c1_array_real32_T_Destructor(chartInstance, &c1_thetaArray);
  c1_array_int32_T_2D_Destructor(chartInstance, &c1_point2Array);
  c1_array_int32_T_2D_Destructor(chartInstance, &c1_point1Array);
}

static void c1_d_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_a_data[], int32_T
  c1_a_size[2])
{
  static char_T c1_b_cv[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
    'g', 'h', 'l', 'i', 'n', 'e', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c1_b_cv2[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
    'u', 'g', 'h', 'l', 'i', 'n', 'e', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

  static char_T c1_b_cv1[22] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '4', ',', ' ', 'P', 'E', 'A', 'K', 'S', ',' };

  static char_T c1_b_cv3[22] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '4', ',', ' ', 'P', 'E', 'A', 'K', 'S', ',' };

  c1_coder_array_real_T_2D c1_c_a;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d_k;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_y;
  int32_T c1_c_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_k;
  int32_T c1_loop_ub;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_c_b;
  boolean_T c1_c_p;
  boolean_T c1_d_p;
  boolean_T c1_e_p;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_s_emlrtRSI;
  c1_array_real_T_2D_Constructor(chartInstance, &c1_c_a);
  c1_array_real_T_2D_SetSize(chartInstance, &c1_st, &c1_c_a, &c1_jf_emlrtRTEI,
    c1_a_size[0], c1_a_size[1]);
  c1_loop_ub = c1_a_size[0] * c1_a_size[1] - 1;
  for (c1_i = 0; c1_i <= c1_loop_ub; c1_i++) {
    c1_c_a.vector.data[c1_i] = c1_a_data[c1_i];
  }

  c1_p = true;
  c1_d = (real_T)(c1_c_a.size[0] * c1_c_a.size[1]);
  c1_i1 = (int32_T)c1_d - 1;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k <= c1_i1)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_b_x = c1_c_a.vector.data[(int32_T)c1_b_k - 1];
    c1_b_p = !(c1_b_x <= 0.0);
    if (c1_b_p) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  c1_array_real_T_2D_Destructor(chartInstance, &c1_c_a);
  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv1, 10, 0U, 1, 0U, 2, 1, 48),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1, 0U, 2, 1, 22),
                  false);
    sf_mex_call(&c1_st, &c1_u_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_c_y, 14, c1_d_y)));
  }

  c1_st.site = &c1_s_emlrtRSI;
  c1_c_p = true;
  c1_d1 = (real_T)(c1_a_size[0] * c1_a_size[1]);
  c1_i2 = (int32_T)c1_d1 - 1;
  c1_c_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_c_k <= c1_i2)) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_c_x = c1_a_data[(int32_T)c1_d_k - 1];
    c1_d_x = c1_c_x;
    c1_e_x = c1_d_x;
    c1_b_b = muDoubleScalarIsInf(c1_e_x);
    c1_b2 = !c1_b_b;
    c1_c_b = c1_b2;
    if (c1_c_b) {
      c1_f_x = c1_c_x;
      c1_g_x = c1_f_x;
      c1_h_y = c1_g_x;
      c1_h_y = muDoubleScalarFloor(c1_h_y);
      if (c1_h_y == c1_c_x) {
        c1_d_p = true;
      } else {
        c1_d_p = false;
      }
    } else {
      c1_d_p = false;
    }

    c1_e_p = c1_d_p;
    if (c1_e_p) {
      c1_c_k++;
    } else {
      c1_c_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_c_p) {
    c1_b1 = true;
  } else {
    c1_b1 = false;
  }

  if (!c1_b1) {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv2, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv9, 10, 0U, 1, 0U, 2, 1, 47),
                  false);
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_b_cv3, 10, 0U, 1, 0U, 2, 1, 22),
                  false);
    sf_mex_call(&c1_st, &c1_ab_emlrtMCI, "error", 0U, 2U, 14, c1_e_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_f_y, 14, c1_g_y)));
  }
}

static void c1_sortrows(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_b_y, real_T
  c1_c_varargin_1[2], c1_coder_array_int32_T_2D *c1_c_y)
{
  real_T c1_d_varargin_1[2];
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_loop_ub;
  c1_array_int32_T_2D_SetSize(chartInstance, c1_sp, c1_c_y, &c1_kf_emlrtRTEI,
    c1_b_y->size[0], 2);
  c1_loop_ub = (c1_b_y->size[0] << 1) - 1;
  for (c1_i = 0; c1_i <= c1_loop_ub; c1_i++) {
    c1_c_y->vector.data[c1_i] = c1_b_y->vector.data[c1_i];
  }

  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_d_varargin_1[c1_i1] = c1_c_varargin_1[c1_i1];
  }

  c1_b_sortrows(chartInstance, c1_sp, c1_c_y, c1_d_varargin_1);
}

static boolean_T c1_sortLE(SFc1_flightControlSystemInstanceStruct *chartInstance,
  c1_coder_array_int32_T_2D *c1_v, int32_T c1_dir[2], int32_T c1_idx1, int32_T
  c1_idx2)
{
  int32_T c1_abscolk;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_b_x;
  int32_T c1_c_a;
  int32_T c1_c_x;
  int32_T c1_colk;
  int32_T c1_d_a;
  int32_T c1_d_x;
  int32_T c1_irow1;
  int32_T c1_irow2;
  int32_T c1_k;
  int32_T c1_v1;
  int32_T c1_v2;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  boolean_T c1_v1eqv2;
  (void)chartInstance;
  c1_irow1 = c1_idx1 - 1;
  c1_irow2 = c1_idx2 - 1;
  c1_p = true;
  c1_k = 1;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k - 1 < 2)) {
    c1_b_k = c1_k - 1;
    c1_colk = c1_dir[c1_b_k];
    c1_b_x = c1_colk;
    c1_c_x = c1_b_x;
    c1_d_x = c1_c_x;
    c1_abscolk = c1_d_x - 1;
    c1_v1 = c1_v->vector.data[c1_irow1 + c1_v->size[0] * c1_abscolk];
    c1_v2 = c1_v->vector.data[c1_irow2 + c1_v->size[0] * c1_abscolk];
    c1_v1eqv2 = (c1_v1 == c1_v2);
    if (c1_v1eqv2) {
      c1_k++;
    } else {
      c1_c_a = c1_v1;
      c1_b = c1_v2;
      c1_d_a = c1_c_a;
      c1_b_b = c1_b;
      c1_p = (c1_d_a <= c1_b_b);
      c1_exitg1 = true;
    }
  }

  return c1_p;
}

static void c1_b_repmat(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, int32_T c1_b_varargin_2,
  c1_coder_array_s52BVvgcaqgLKaYLjO1 *c1_b)
{
  c1_coder_array_boolean_T_2D c1_tile;
  c1_s52BVvgcaqgLKaYLjO15CeF c1_b_s;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  real_T c1_d;
  real_T c1_d1;
  int32_T c1_outsize[2];
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_loop_ub;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_ef_emlrtRSI;
  c1_array_boolean_T_2D_Constructor(chartInstance, &c1_tile);
  c1_d = (real_T)c1_b_varargin_2;
  if (!(c1_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c1_d, &c1_n_emlrtDCI, (emlrtConstCTX)c1_sp);
  }

  c1_i = (int32_T)muDoubleScalarFloor(c1_d);
  c1_st.site = &c1_pj_emlrtRSI;
  c1_array_boolean_T_2D_SetSize(chartInstance, &c1_st, &c1_tile,
    &c1_rc_emlrtRTEI, 1, c1_i);
  c1_d1 = (real_T)c1_b_varargin_2;
  if (!(c1_d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c1_d1, &c1_o_emlrtDCI, (emlrtConstCTX)c1_sp);
  }

  c1_loop_ub = (int32_T)muDoubleScalarFloor(c1_d1) - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_tile.vector.data[c1_i1] = false;
  }

  c1_outsize[1] = c1_tile.size[1];
  if (!((real_T)c1_outsize[1] == (real_T)c1_tile.size[1])) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv4, 10, 0U, 1, 0U, 2, 1, 15),
                  false);
    sf_mex_call(c1_sp, &c1_k_emlrtMCI, "error", 0U, 1U, 14, c1_b_y);
  }

  c1_array_boolean_T_2D_Destructor(chartInstance, &c1_tile);
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_b_s.point1[c1_i2] = 0.0;
  }

  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_b_s.point2[c1_i3] = 0.0;
  }

  c1_b_s.theta = 0.0;
  c1_b_s.rho = 0.0;
  c1_st.site = &c1_mk_emlrtRSI;
  c1_array_s52BVvgcaqgLKaYLjO15CeF_2(chartInstance, &c1_st, c1_b,
    &c1_lf_emlrtRTEI, 1, c1_outsize[1]);
  c1_b_loop_ub = c1_outsize[1] - 1;
  for (c1_i4 = 0; c1_i4 <= c1_b_loop_ub; c1_i4++) {
    c1_b->vector.data[c1_i4] = c1_b_s;
  }
}

const mxArray *sf_c1_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static real_T c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr),
    &c1_thisId);
  sf_mex_destroy(&c1_nullptr);
  return c1_b_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_b_y;
  real_T c1_d;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_d, 1, 0, 0U, 0, 0U, 0);
  c1_b_y = c1_d;
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_slStringInitializeDynamicBuffers
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_chart_data_browse_helper(SFc1_flightControlSystemInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig)
{
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_d5;
  *c1_mxData = NULL;
  *c1_mxData = NULL;
  *c1_isValueTooBig = 0U;
  switch (c1_ssIdNumber) {
   case 5U:
    c1_d = *chartInstance->c1_y;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_d, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 9U:
    c1_d1 = *chartInstance->c1_number;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_d1, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 7U:
    c1_d2 = *chartInstance->c1_data1;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_d2, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 10U:
    c1_d3 = *chartInstance->c1_angelina;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_d3, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 4U:
    *c1_isValueTooBig = 1U;
    break;

   case 6U:
    c1_d4 = *chartInstance->c1_data;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_d4, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 8U:
    c1_d5 = *chartInstance->c1_angle_;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_d5, 0, 0U, 0, 0U, 0),
                  false);
    break;
  }
}

static const mxArray *c1_feval(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, const mxArray *c1_input0, const
  mxArray *c1_input1)
{
  const mxArray *c1_m = NULL;
  (void)chartInstance;
  c1_m = NULL;
  sf_mex_assign(&c1_m, sf_mex_call(c1_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c1_input0), 14, sf_mex_dup(c1_input1)), false);
  sf_mex_destroy(&c1_input0);
  sf_mex_destroy(&c1_input1);
  return c1_m;
}

static void c1_b_feval(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, const mxArray *c1_input0, const mxArray *c1_input1)
{
  (void)chartInstance;
  sf_mex_call(c1_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c1_input0), 14,
              sf_mex_dup(c1_input1));
  sf_mex_destroy(&c1_input0);
  sf_mex_destroy(&c1_input1);
}

static void c1_b_ComputeWeightedCentroid(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, real_T c1_I[19200],
  c1_coder_array_s_R6Og1x0kmqQXSF9Pw *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  *c1_statsAlreadyComputed)
{
  static char_T c1_b_cv[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  c1_cell_wrap_46 c1_reshapes[2];
  c1_coder_array_int32_T c1_idx;
  c1_coder_array_int32_T c1_varargout_4;
  c1_coder_array_int32_T c1_vk;
  c1_coder_array_real_T c1_Intensity;
  c1_coder_array_real_T c1_j;
  c1_coder_array_real_T c1_r;
  c1_coder_array_real_T c1_r1;
  c1_coder_array_real_T_2D c1_result;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  real_T c1_wc[2];
  real_T c1_M;
  real_T c1_b_k;
  real_T c1_b_n;
  real_T c1_c_idx;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d_k;
  real_T c1_f_k;
  real_T c1_sumIntensity;
  int32_T c1_sizes[2];
  int32_T c1_ab_loop_ub;
  int32_T c1_b_idx;
  int32_T c1_b_loop_ub;
  int32_T c1_b_result;
  int32_T c1_bb_loop_ub;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_c_n;
  int32_T c1_cb_loop_ub;
  int32_T c1_d_loop_ub;
  int32_T c1_db_loop_ub;
  int32_T c1_e_k;
  int32_T c1_e_loop_ub;
  int32_T c1_eb_loop_ub;
  int32_T c1_expected;
  int32_T c1_f_loop_ub;
  int32_T c1_fb_loop_ub;
  int32_T c1_g_loop_ub;
  int32_T c1_gb_loop_ub;
  int32_T c1_h_loop_ub;
  int32_T c1_hb_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i100;
  int32_T c1_i101;
  int32_T c1_i102;
  int32_T c1_i103;
  int32_T c1_i104;
  int32_T c1_i105;
  int32_T c1_i106;
  int32_T c1_i107;
  int32_T c1_i108;
  int32_T c1_i109;
  int32_T c1_i11;
  int32_T c1_i110;
  int32_T c1_i111;
  int32_T c1_i112;
  int32_T c1_i113;
  int32_T c1_i114;
  int32_T c1_i115;
  int32_T c1_i116;
  int32_T c1_i117;
  int32_T c1_i118;
  int32_T c1_i119;
  int32_T c1_i12;
  int32_T c1_i120;
  int32_T c1_i121;
  int32_T c1_i122;
  int32_T c1_i123;
  int32_T c1_i124;
  int32_T c1_i125;
  int32_T c1_i126;
  int32_T c1_i127;
  int32_T c1_i128;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i5;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i6;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i7;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i8;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i9;
  int32_T c1_i90;
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  int32_T c1_i97;
  int32_T c1_i98;
  int32_T c1_i99;
  int32_T c1_i_loop_ub;
  int32_T c1_ib_loop_ub;
  int32_T c1_j_loop_ub;
  int32_T c1_k;
  int32_T c1_k_loop_ub;
  int32_T c1_l_loop_ub;
  int32_T c1_loop_ub;
  int32_T c1_m_loop_ub;
  int32_T c1_n;
  int32_T c1_n_loop_ub;
  int32_T c1_o_loop_ub;
  int32_T c1_p_loop_ub;
  int32_T c1_q_loop_ub;
  int32_T c1_r_loop_ub;
  int32_T c1_s_loop_ub;
  int32_T c1_t_loop_ub;
  int32_T c1_u_loop_ub;
  int32_T c1_v_loop_ub;
  int32_T c1_w_loop_ub;
  int32_T c1_x_loop_ub;
  int32_T c1_y_loop_ub;
  boolean_T c1_b;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_statsAlreadyComputed->WeightedCentroid = true;
  c1_st.site = &c1_nf_emlrtRSI;
  c1_statsAlreadyComputed->PixelList = true;
  c1_d = (real_T)c1_stats->size[0];
  c1_i = (int32_T)c1_d - 1;
  c1_array_real_T_Constructor(chartInstance, &c1_Intensity);
  c1_array_real_T_Constructor(chartInstance, &c1_j);
  c1_array_real_T_Constructor(chartInstance, &c1_r);
  c1_array_int32_T_Constructor(chartInstance, &c1_varargout_4);
  c1_array_real_T_2D_Constructor(chartInstance, &c1_result);
  c1_array_cell_wrap_46_2s_Construct(chartInstance, c1_reshapes);
  c1_array_int32_T_Constructor(chartInstance, &c1_idx);
  c1_array_int32_T_Constructor(chartInstance, &c1_vk);
  for (c1_k = 0; c1_k <= c1_i; c1_k++) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_i1 = c1_stats->size[0];
    c1_i2 = (int32_T)c1_b_k;
    if ((c1_i2 < 1) || (c1_i2 > c1_i1)) {
      emlrtDynamicBoundsCheckR2012b(c1_i2, 1, c1_i1, &c1_kh_emlrtBCI, &c1_st);
    }

    c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_r, &c1_mf_emlrtRTEI,
      c1_stats->vector.data[c1_i2 - 1].PixelIdxList.size[0]);
    c1_i4 = c1_stats->size[0];
    c1_i5 = (int32_T)c1_b_k;
    if ((c1_i5 < 1) || (c1_i5 > c1_i4)) {
      emlrtDynamicBoundsCheckR2012b(c1_i5, 1, c1_i4, &c1_kh_emlrtBCI, &c1_st);
    }

    c1_loop_ub = c1_stats->vector.data[c1_i5 - 1].PixelIdxList.size[0] - 1;
    for (c1_i8 = 0; c1_i8 <= c1_loop_ub; c1_i8++) {
      c1_i11 = c1_stats->size[0];
      c1_i14 = (int32_T)c1_b_k;
      if ((c1_i14 < 1) || (c1_i14 > c1_i11)) {
        emlrtDynamicBoundsCheckR2012b(c1_i14, 1, c1_i11, &c1_kh_emlrtBCI, &c1_st);
      }

      c1_r.vector.data[c1_i8] = c1_stats->vector.data[c1_i14 - 1].
        PixelIdxList.vector.data[c1_i8];
    }

    if (c1_r.size[0] != 0) {
      c1_b_st.site = &c1_pf_emlrtRSI;
      c1_i16 = c1_stats->size[0];
      c1_i17 = (int32_T)c1_b_k;
      if ((c1_i17 < 1) || (c1_i17 > c1_i16)) {
        emlrtDynamicBoundsCheckR2012b(c1_i17, 1, c1_i16, &c1_mh_emlrtBCI,
          &c1_b_st);
      }

      c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_Intensity,
        &c1_of_emlrtRTEI, c1_stats->vector.data[c1_i17 - 1].PixelIdxList.size[0]);
      c1_i24 = c1_stats->size[0];
      c1_i28 = (int32_T)c1_b_k;
      if ((c1_i28 < 1) || (c1_i28 > c1_i24)) {
        emlrtDynamicBoundsCheckR2012b(c1_i28, 1, c1_i24, &c1_mh_emlrtBCI,
          &c1_b_st);
      }

      c1_c_loop_ub = c1_stats->vector.data[c1_i28 - 1].PixelIdxList.size[0] - 1;
      for (c1_i34 = 0; c1_i34 <= c1_c_loop_ub; c1_i34++) {
        c1_i37 = c1_stats->size[0];
        c1_i40 = (int32_T)c1_b_k;
        if ((c1_i40 < 1) || (c1_i40 > c1_i37)) {
          emlrtDynamicBoundsCheckR2012b(c1_i40, 1, c1_i37, &c1_mh_emlrtBCI,
            &c1_b_st);
        }

        c1_Intensity.vector.data[c1_i34] = c1_stats->vector.data[c1_i40 - 1].
          PixelIdxList.vector.data[c1_i34];
      }

      c1_c_st.site = &c1_qf_emlrtRSI;
      c1_array_int32_T_SetSize(chartInstance, &c1_c_st, &c1_idx,
        &c1_pf_emlrtRTEI, c1_Intensity.size[0]);
      c1_e_loop_ub = c1_Intensity.size[0] - 1;
      for (c1_i44 = 0; c1_i44 <= c1_e_loop_ub; c1_i44++) {
        c1_idx.vector.data[c1_i44] = (int32_T)c1_Intensity.vector.data[c1_i44];
      }

      c1_f_loop_ub = c1_idx.size[0] - 1;
      for (c1_i50 = 0; c1_i50 <= c1_f_loop_ub; c1_i50++) {
        c1_idx.vector.data[c1_i50]--;
      }

      c1_array_int32_T_SetSize(chartInstance, &c1_c_st, &c1_vk, &c1_qf_emlrtRTEI,
        c1_idx.size[0]);
      c1_g_loop_ub = c1_idx.size[0] - 1;
      for (c1_i52 = 0; c1_i52 <= c1_g_loop_ub; c1_i52++) {
        c1_vk.vector.data[c1_i52] = c1_div_nzp_s32(chartInstance,
          c1_idx.vector.data[c1_i52], 120, 0, 0U, 0, 0);
      }

      c1_array_int32_T_SetSize(chartInstance, &c1_c_st, &c1_varargout_4,
        &c1_rf_emlrtRTEI, c1_vk.size[0]);
      c1_i_loop_ub = c1_vk.size[0] - 1;
      for (c1_i61 = 0; c1_i61 <= c1_i_loop_ub; c1_i61++) {
        c1_varargout_4.vector.data[c1_i61] = c1_vk.vector.data[c1_i61] + 1;
      }

      c1_k_loop_ub = c1_vk.size[0] - 1;
      for (c1_i65 = 0; c1_i65 <= c1_k_loop_ub; c1_i65++) {
        c1_vk.vector.data[c1_i65] *= 120;
      }

      c1_m_loop_ub = c1_idx.size[0] - 1;
      for (c1_i68 = 0; c1_i68 <= c1_m_loop_ub; c1_i68++) {
        c1_idx.vector.data[c1_i68] -= c1_vk.vector.data[c1_i68];
      }

      c1_o_loop_ub = c1_idx.size[0] - 1;
      for (c1_i71 = 0; c1_i71 <= c1_o_loop_ub; c1_i71++) {
        c1_idx.vector.data[c1_i71]++;
      }

      c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_Intensity,
        &c1_sf_emlrtRTEI, c1_idx.size[0]);
      c1_q_loop_ub = c1_idx.size[0] - 1;
      for (c1_i76 = 0; c1_i76 <= c1_q_loop_ub; c1_i76++) {
        c1_Intensity.vector.data[c1_i76] = (real_T)c1_idx.vector.data[c1_i76];
      }

      c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_j, &c1_sf_emlrtRTEI,
        c1_varargout_4.size[0]);
      c1_t_loop_ub = c1_varargout_4.size[0] - 1;
      for (c1_i79 = 0; c1_i79 <= c1_t_loop_ub; c1_i79++) {
        c1_j.vector.data[c1_i79] = (real_T)c1_varargout_4.vector.data[c1_i79];
      }

      c1_b_st.site = &c1_of_emlrtRSI;
      c1_c_st.site = &c1_rf_emlrtRSI;
      c1_b_result = c1_j.size[0];
      c1_sizes[0] = c1_b_result;
      c1_d_st.site = &c1_sf_emlrtRSI;
      c1_expected = c1_sizes[0];
      if (c1_j.size[0] == c1_expected) {
        c1_b = true;
      } else {
        c1_b = false;
      }

      if (!c1_b) {
        c1_b_y = NULL;
        sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1,
          39), false);
        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1,
          39), false);
        sf_mex_call(&c1_d_st, &c1_p_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                    sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c1_d_st, NULL, "message", 1U, 1U, 14, c1_c_y)));
      }

      if (c1_Intensity.size[0] == c1_expected) {
        c1_b = true;
      } else {
        c1_b = false;
      }

      if (!c1_b) {
        c1_d_y = NULL;
        sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1,
          39), false);
        c1_e_y = NULL;
        sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1,
          39), false);
        sf_mex_call(&c1_d_st, &c1_p_emlrtMCI, "error", 0U, 2U, 14, c1_d_y, 14,
                    sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c1_d_st, NULL, "message", 1U, 1U, 14, c1_e_y)));
      }

      c1_array_real_T_SetSize(chartInstance, &c1_c_st, &c1_reshapes[0].f1,
        &c1_tf_emlrtRTEI, c1_j.size[0]);
      c1_bb_loop_ub = c1_j.size[0] - 1;
      for (c1_i93 = 0; c1_i93 <= c1_bb_loop_ub; c1_i93++) {
        c1_reshapes[0].f1.vector.data[c1_i93] = c1_j.vector.data[c1_i93];
      }

      c1_array_real_T_SetSize(chartInstance, &c1_c_st, &c1_reshapes[1].f1,
        &c1_tf_emlrtRTEI, c1_Intensity.size[0]);
      c1_cb_loop_ub = c1_Intensity.size[0] - 1;
      for (c1_i95 = 0; c1_i95 <= c1_cb_loop_ub; c1_i95++) {
        c1_reshapes[1].f1.vector.data[c1_i95] = c1_Intensity.vector.data[c1_i95];
      }

      c1_array_real_T_SetSize(chartInstance, &c1_c_st, &c1_Intensity,
        &c1_uf_emlrtRTEI, c1_reshapes[0].f1.size[0]);
      c1_eb_loop_ub = c1_reshapes[0].f1.size[0] - 1;
      for (c1_i100 = 0; c1_i100 <= c1_eb_loop_ub; c1_i100++) {
        c1_Intensity.vector.data[c1_i100] = c1_reshapes[0]
          .f1.vector.data[c1_i100];
      }

      c1_array_real_T_SetSize(chartInstance, &c1_c_st, &c1_j, &c1_uf_emlrtRTEI,
        c1_reshapes[1].f1.size[0]);
      c1_fb_loop_ub = c1_reshapes[1].f1.size[0] - 1;
      for (c1_i102 = 0; c1_i102 <= c1_fb_loop_ub; c1_i102++) {
        c1_j.vector.data[c1_i102] = c1_reshapes[1].f1.vector.data[c1_i102];
      }

      c1_array_real_T_2D_SetSize(chartInstance, &c1_c_st, &c1_result,
        &c1_vf_emlrtRTEI, c1_Intensity.size[0], 2);
      c1_gb_loop_ub = c1_Intensity.size[0] - 1;
      for (c1_i105 = 0; c1_i105 <= c1_gb_loop_ub; c1_i105++) {
        c1_result.vector.data[c1_i105] = c1_Intensity.vector.data[c1_i105];
      }

      c1_hb_loop_ub = c1_j.size[0] - 1;
      for (c1_i108 = 0; c1_i108 <= c1_hb_loop_ub; c1_i108++) {
        c1_result.vector.data[c1_i108 + c1_result.size[0]] =
          c1_j.vector.data[c1_i108];
      }

      c1_i110 = c1_result.size[0] << 1;
      c1_i111 = c1_stats->size[0];
      c1_i112 = (int32_T)c1_b_k;
      if ((c1_i112 < 1) || (c1_i112 > c1_i111)) {
        emlrtDynamicBoundsCheckR2012b(c1_i112, 1, c1_i111, &c1_eh_emlrtBCI,
          &c1_st);
      }

      c1_i115 = c1_i112 - 1;
      c1_array_real_T_2D_SetSize(chartInstance, &c1_st, &c1_stats->
        vector.data[c1_i115].PixelList, &c1_wf_emlrtRTEI, c1_result.size[0],
        c1_stats->vector.data[c1_i115].PixelList.size[1]);
      c1_i117 = c1_stats->size[0];
      c1_i119 = (int32_T)c1_b_k;
      if ((c1_i119 < 1) || (c1_i119 > c1_i117)) {
        emlrtDynamicBoundsCheckR2012b(c1_i119, 1, c1_i117, &c1_eh_emlrtBCI,
          &c1_st);
      }

      c1_i120 = c1_i119 - 1;
      c1_array_real_T_2D_SetSize(chartInstance, &c1_st, &c1_stats->
        vector.data[c1_i120].PixelList, &c1_wf_emlrtRTEI, c1_stats->
        vector.data[c1_i120].PixelList.size[0], 2);
      c1_i121 = c1_stats->size[0];
      c1_i122 = (int32_T)c1_b_k;
      if ((c1_i122 < 1) || (c1_i122 > c1_i121)) {
        emlrtDynamicBoundsCheckR2012b(c1_i122, 1, c1_i121, &c1_eh_emlrtBCI,
          &c1_st);
      }

      c1_i123 = c1_stats->size[0];
      c1_i124 = (int32_T)c1_b_k;
      if ((c1_i124 < 1) || (c1_i124 > c1_i123)) {
        emlrtDynamicBoundsCheckR2012b(c1_i124, 1, c1_i123, &c1_eh_emlrtBCI,
          &c1_st);
      }

      c1_i125 = c1_i110;
      c1_ib_loop_ub = c1_i125 - 1;
      for (c1_i126 = 0; c1_i126 <= c1_ib_loop_ub; c1_i126++) {
        c1_i127 = c1_stats->size[0];
        c1_i128 = (int32_T)c1_b_k;
        if ((c1_i128 < 1) || (c1_i128 > c1_i127)) {
          emlrtDynamicBoundsCheckR2012b(c1_i128, 1, c1_i127, &c1_rh_emlrtBCI,
            &c1_st);
        }

        c1_stats->vector.data[c1_i128 - 1].PixelList.vector.data[c1_i126] =
          c1_result.vector.data[c1_i126];
      }
    } else {
      c1_i13 = c1_stats->size[0];
      c1_i15 = (int32_T)c1_b_k;
      if ((c1_i15 < 1) || (c1_i15 > c1_i13)) {
        emlrtDynamicBoundsCheckR2012b(c1_i15, 1, c1_i13, &c1_ch_emlrtBCI, &c1_st);
      }

      c1_i21 = c1_i15 - 1;
      c1_array_real_T_2D_SetSize(chartInstance, &c1_st, &c1_stats->
        vector.data[c1_i21].PixelList, &c1_nf_emlrtRTEI, 0,
        c1_stats->vector.data[c1_i21].PixelList.size[1]);
      c1_i23 = c1_stats->size[0];
      c1_i27 = (int32_T)c1_b_k;
      if ((c1_i27 < 1) || (c1_i27 > c1_i23)) {
        emlrtDynamicBoundsCheckR2012b(c1_i27, 1, c1_i23, &c1_ch_emlrtBCI, &c1_st);
      }

      c1_i32 = c1_i27 - 1;
      c1_array_real_T_2D_SetSize(chartInstance, &c1_st, &c1_stats->
        vector.data[c1_i32].PixelList, &c1_nf_emlrtRTEI, c1_stats->
        vector.data[c1_i32].PixelList.size[0], 2);
      c1_i35 = c1_stats->size[0];
      c1_i36 = (int32_T)c1_b_k;
      if ((c1_i36 < 1) || (c1_i36 > c1_i35)) {
        emlrtDynamicBoundsCheckR2012b(c1_i36, 1, c1_i35, &c1_ch_emlrtBCI, &c1_st);
      }

      c1_i43 = c1_stats->size[0];
      c1_i46 = (int32_T)c1_b_k;
      if ((c1_i46 < 1) || (c1_i46 > c1_i43)) {
        emlrtDynamicBoundsCheckR2012b(c1_i46, 1, c1_i43, &c1_ch_emlrtBCI, &c1_st);
      }
    }
  }

  c1_array_cell_wrap_46_2s_Destructo(chartInstance, c1_reshapes);
  c1_st.site = &c1_mf_emlrtRSI;
  c1_statsAlreadyComputed->PixelValues = true;
  c1_d1 = (real_T)c1_stats->size[0];
  c1_i3 = (int32_T)c1_d1 - 1;
  for (c1_c_k = 0; c1_c_k <= c1_i3; c1_c_k++) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_i6 = c1_stats->size[0];
    c1_i7 = (int32_T)c1_d_k;
    if ((c1_i7 < 1) || (c1_i7 > c1_i6)) {
      emlrtDynamicBoundsCheckR2012b(c1_i7, 1, c1_i6, &c1_lh_emlrtBCI, &c1_st);
    }

    c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_r, &c1_xf_emlrtRTEI,
      c1_stats->vector.data[c1_i7 - 1].PixelIdxList.size[0]);
    c1_i10 = c1_stats->size[0];
    c1_i12 = (int32_T)c1_d_k;
    if ((c1_i12 < 1) || (c1_i12 > c1_i10)) {
      emlrtDynamicBoundsCheckR2012b(c1_i12, 1, c1_i10, &c1_lh_emlrtBCI, &c1_st);
    }

    c1_b_loop_ub = c1_stats->vector.data[c1_i12 - 1].PixelIdxList.size[0] - 1;
    for (c1_i20 = 0; c1_i20 <= c1_b_loop_ub; c1_i20++) {
      c1_i22 = c1_stats->size[0];
      c1_i26 = (int32_T)c1_d_k;
      if ((c1_i26 < 1) || (c1_i26 > c1_i22)) {
        emlrtDynamicBoundsCheckR2012b(c1_i26, 1, c1_i22, &c1_lh_emlrtBCI, &c1_st);
      }

      c1_r.vector.data[c1_i20] = c1_stats->vector.data[c1_i26 - 1].
        PixelIdxList.vector.data[c1_i20];
    }

    c1_wc[0] = (real_T)c1_r.size[0];
    c1_i25 = c1_stats->size[0];
    c1_i29 = (int32_T)c1_d_k;
    if ((c1_i29 < 1) || (c1_i29 > c1_i25)) {
      emlrtDynamicBoundsCheckR2012b(c1_i29, 1, c1_i25, &c1_bh_emlrtBCI, &c1_st);
    }

    c1_i33 = c1_i29;
    c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_stats->vector.data[c1_i33
      - 1].PixelValues, &c1_yf_emlrtRTEI, (int32_T)c1_wc[0]);
    c1_b_st.site = &c1_tf_emlrtRSI;
    c1_i39 = c1_stats->size[0];
    c1_i41 = (int32_T)c1_d_k;
    if ((c1_i41 < 1) || (c1_i41 > c1_i39)) {
      emlrtDynamicBoundsCheckR2012b(c1_i41, 1, c1_i39, &c1_ph_emlrtBCI, &c1_b_st);
    }

    c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_Intensity,
      &c1_ag_emlrtRTEI, c1_stats->vector.data[c1_i41 - 1].PixelIdxList.size[0]);
    c1_i49 = c1_stats->size[0];
    c1_i51 = (int32_T)c1_d_k;
    if ((c1_i51 < 1) || (c1_i51 > c1_i49)) {
      emlrtDynamicBoundsCheckR2012b(c1_i51, 1, c1_i49, &c1_ph_emlrtBCI, &c1_b_st);
    }

    c1_h_loop_ub = c1_stats->vector.data[c1_i51 - 1].PixelIdxList.size[0] - 1;
    for (c1_i54 = 0; c1_i54 <= c1_h_loop_ub; c1_i54++) {
      c1_i58 = c1_stats->size[0];
      c1_i60 = (int32_T)c1_d_k;
      if ((c1_i60 < 1) || (c1_i60 > c1_i58)) {
        emlrtDynamicBoundsCheckR2012b(c1_i60, 1, c1_i58, &c1_ph_emlrtBCI,
          &c1_b_st);
      }

      c1_Intensity.vector.data[c1_i54] = c1_stats->vector.data[c1_i60 - 1].
        PixelIdxList.vector.data[c1_i54];
    }

    c1_c_st.site = &c1_qf_emlrtRSI;
    c1_array_int32_T_SetSize(chartInstance, &c1_c_st, &c1_idx, &c1_pf_emlrtRTEI,
      c1_Intensity.size[0]);
    c1_j_loop_ub = c1_Intensity.size[0] - 1;
    for (c1_i63 = 0; c1_i63 <= c1_j_loop_ub; c1_i63++) {
      c1_idx.vector.data[c1_i63] = (int32_T)c1_Intensity.vector.data[c1_i63];
    }

    c1_l_loop_ub = c1_idx.size[0] - 1;
    for (c1_i66 = 0; c1_i66 <= c1_l_loop_ub; c1_i66++) {
      c1_idx.vector.data[c1_i66]--;
    }

    c1_array_int32_T_SetSize(chartInstance, &c1_c_st, &c1_vk, &c1_qf_emlrtRTEI,
      c1_idx.size[0]);
    c1_n_loop_ub = c1_idx.size[0] - 1;
    for (c1_i70 = 0; c1_i70 <= c1_n_loop_ub; c1_i70++) {
      c1_vk.vector.data[c1_i70] = c1_div_nzp_s32(chartInstance,
        c1_idx.vector.data[c1_i70], 120, 0, 0U, 0, 0);
    }

    c1_array_int32_T_SetSize(chartInstance, &c1_c_st, &c1_varargout_4,
      &c1_rf_emlrtRTEI, c1_vk.size[0]);
    c1_p_loop_ub = c1_vk.size[0] - 1;
    for (c1_i75 = 0; c1_i75 <= c1_p_loop_ub; c1_i75++) {
      c1_varargout_4.vector.data[c1_i75] = c1_vk.vector.data[c1_i75] + 1;
    }

    c1_s_loop_ub = c1_vk.size[0] - 1;
    for (c1_i78 = 0; c1_i78 <= c1_s_loop_ub; c1_i78++) {
      c1_vk.vector.data[c1_i78] *= 120;
    }

    c1_u_loop_ub = c1_idx.size[0] - 1;
    for (c1_i82 = 0; c1_i82 <= c1_u_loop_ub; c1_i82++) {
      c1_idx.vector.data[c1_i82] -= c1_vk.vector.data[c1_i82];
    }

    c1_w_loop_ub = c1_idx.size[0] - 1;
    for (c1_i84 = 0; c1_i84 <= c1_w_loop_ub; c1_i84++) {
      c1_idx.vector.data[c1_i84]++;
    }

    c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_j, &c1_sf_emlrtRTEI,
      c1_idx.size[0]);
    c1_x_loop_ub = c1_idx.size[0] - 1;
    for (c1_i87 = 0; c1_i87 <= c1_x_loop_ub; c1_i87++) {
      c1_j.vector.data[c1_i87] = (real_T)c1_idx.vector.data[c1_i87];
    }

    c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_Intensity,
      &c1_sf_emlrtRTEI, c1_varargout_4.size[0]);
    c1_y_loop_ub = c1_varargout_4.size[0] - 1;
    for (c1_i88 = 0; c1_i88 <= c1_y_loop_ub; c1_i88++) {
      c1_Intensity.vector.data[c1_i88] = (real_T)
        c1_varargout_4.vector.data[c1_i88];
    }

    c1_i90 = c1_stats->size[0];
    c1_i91 = (int32_T)c1_d_k;
    if ((c1_i91 < 1) || (c1_i91 > c1_i90)) {
      emlrtDynamicBoundsCheckR2012b(c1_i91, 1, c1_i90, &c1_qh_emlrtBCI, &c1_st);
    }

    c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_r, &c1_bg_emlrtRTEI,
      c1_stats->vector.data[c1_i91 - 1].PixelValues.size[0]);
    c1_i92 = c1_stats->size[0];
    c1_i94 = (int32_T)c1_d_k;
    if ((c1_i94 < 1) || (c1_i94 > c1_i92)) {
      emlrtDynamicBoundsCheckR2012b(c1_i94, 1, c1_i92, &c1_qh_emlrtBCI, &c1_st);
    }

    c1_db_loop_ub = c1_stats->vector.data[c1_i94 - 1].PixelValues.size[0] - 1;
    for (c1_i96 = 0; c1_i96 <= c1_db_loop_ub; c1_i96++) {
      c1_i97 = c1_stats->size[0];
      c1_i99 = (int32_T)c1_d_k;
      if ((c1_i99 < 1) || (c1_i99 > c1_i97)) {
        emlrtDynamicBoundsCheckR2012b(c1_i99, 1, c1_i97, &c1_qh_emlrtBCI, &c1_st);
      }

      c1_r.vector.data[c1_i96] = c1_stats->vector.data[c1_i99 - 1].
        PixelValues.vector.data[c1_i96];
    }

    c1_d3 = (real_T)c1_r.size[0];
    c1_i98 = (int32_T)c1_d3 - 1;
    for (c1_b_idx = 0; c1_b_idx <= c1_i98; c1_b_idx++) {
      c1_c_idx = (real_T)c1_b_idx + 1.0;
      c1_i101 = c1_stats->size[0];
      c1_i103 = (int32_T)c1_d_k;
      if ((c1_i103 < 1) || (c1_i103 > c1_i101)) {
        emlrtDynamicBoundsCheckR2012b(c1_i103, 1, c1_i101, &c1_ah_emlrtBCI,
          &c1_st);
      }

      c1_i104 = c1_i103 - 1;
      c1_i106 = c1_j.size[0];
      c1_i107 = (int32_T)c1_c_idx;
      if ((c1_i107 < 1) || (c1_i107 > c1_i106)) {
        emlrtDynamicBoundsCheckR2012b(c1_i107, 1, c1_i106, &c1_hh_emlrtBCI,
          &c1_st);
      }

      c1_i109 = (int32_T)c1_j.vector.data[c1_i107 - 1];
      if ((c1_i109 < 1) || (c1_i109 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c1_i109, 1, 120, &c1_gh_emlrtBCI, &c1_st);
      }

      c1_i113 = c1_Intensity.size[0];
      c1_i114 = (int32_T)c1_c_idx;
      if ((c1_i114 < 1) || (c1_i114 > c1_i113)) {
        emlrtDynamicBoundsCheckR2012b(c1_i114, 1, c1_i113, &c1_ih_emlrtBCI,
          &c1_st);
      }

      c1_i116 = c1_stats->vector.data[c1_i104].PixelValues.size[0];
      c1_i118 = (int32_T)c1_c_idx;
      if ((c1_i118 < 1) || (c1_i118 > c1_i116)) {
        emlrtDynamicBoundsCheckR2012b(c1_i118, 1, c1_i116, &c1_jh_emlrtBCI,
          &c1_st);
      }

      c1_stats->vector.data[c1_i104].PixelValues.vector.data[c1_i118 - 1] =
        c1_I[(c1_i109 + 120 * ((int32_T)c1_Intensity.vector.data[c1_i114 - 1] -
               1)) - 1];
    }
  }

  c1_array_int32_T_Destructor(chartInstance, &c1_vk);
  c1_array_int32_T_Destructor(chartInstance, &c1_idx);
  c1_array_int32_T_Destructor(chartInstance, &c1_varargout_4);
  c1_array_real_T_Destructor(chartInstance, &c1_j);
  c1_d2 = (real_T)c1_stats->size[0];
  c1_i9 = (int32_T)c1_d2 - 1;
  c1_array_real_T_Constructor(chartInstance, &c1_r1);
  for (c1_e_k = 0; c1_e_k <= c1_i9; c1_e_k++) {
    c1_f_k = (real_T)c1_e_k + 1.0;
    c1_i18 = c1_stats->size[0];
    c1_i19 = (int32_T)c1_f_k;
    if ((c1_i19 < 1) || (c1_i19 > c1_i18)) {
      emlrtDynamicBoundsCheckR2012b(c1_i19, 1, c1_i18, &c1_nh_emlrtBCI,
        (emlrtConstCTX)c1_sp);
    }

    c1_st.site = &c1_vj_emlrtRSI;
    c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_Intensity,
      &c1_cg_emlrtRTEI, c1_stats->vector.data[c1_i19 - 1].PixelValues.size[0]);
    c1_i30 = c1_stats->size[0];
    c1_i31 = (int32_T)c1_f_k;
    if ((c1_i31 < 1) || (c1_i31 > c1_i30)) {
      emlrtDynamicBoundsCheckR2012b(c1_i31, 1, c1_i30, &c1_nh_emlrtBCI,
        (emlrtConstCTX)c1_sp);
    }

    c1_d_loop_ub = c1_stats->vector.data[c1_i31 - 1].PixelValues.size[0] - 1;
    for (c1_i38 = 0; c1_i38 <= c1_d_loop_ub; c1_i38++) {
      c1_i42 = c1_stats->size[0];
      c1_i45 = (int32_T)c1_f_k;
      if ((c1_i45 < 1) || (c1_i45 > c1_i42)) {
        emlrtDynamicBoundsCheckR2012b(c1_i45, 1, c1_i42, &c1_oh_emlrtBCI,
          (emlrtConstCTX)c1_sp);
      }

      c1_Intensity.vector.data[c1_i38] = c1_stats->vector.data[c1_i45 - 1].
        PixelValues.vector.data[c1_i38];
    }

    c1_st.site = &c1_lf_emlrtRSI;
    c1_sumIntensity = c1_sum(chartInstance, &c1_st, &c1_Intensity);
    c1_i47 = c1_stats->size[0];
    c1_i48 = (int32_T)c1_f_k;
    if ((c1_i48 < 1) || (c1_i48 > c1_i47)) {
      emlrtDynamicBoundsCheckR2012b(c1_i48, 1, c1_i47, &c1_yg_emlrtBCI,
        (emlrtConstCTX)c1_sp);
    }

    for (c1_n = 0; c1_n < 2; c1_n++) {
      c1_b_n = (real_T)c1_n + 1.0;
      c1_i55 = c1_stats->size[0];
      c1_i57 = (int32_T)c1_f_k;
      if ((c1_i57 < 1) || (c1_i57 > c1_i55)) {
        emlrtDynamicBoundsCheckR2012b(c1_i57, 1, c1_i55, &c1_dh_emlrtBCI,
          (emlrtConstCTX)c1_sp);
      }

      c1_i62 = c1_i57 - 1;
      c1_i64 = c1_stats->vector.data[c1_i62].PixelList.size[0];
      c1_st.site = &c1_kf_emlrtRSI;
      c1_array_real_T_2D_SetSize(chartInstance, &c1_st, &c1_result,
        &c1_dg_emlrtRTEI, c1_i64, 2);
      c1_i67 = c1_stats->size[0];
      c1_i69 = (int32_T)c1_f_k;
      if ((c1_i69 < 1) || (c1_i69 > c1_i67)) {
        emlrtDynamicBoundsCheckR2012b(c1_i69, 1, c1_i67, &c1_dh_emlrtBCI,
          (emlrtConstCTX)c1_sp);
      }

      c1_i72 = c1_i69 - 1;
      c1_i73 = c1_stats->size[0];
      c1_i74 = (int32_T)c1_f_k;
      if ((c1_i74 < 1) || (c1_i74 > c1_i73)) {
        emlrtDynamicBoundsCheckR2012b(c1_i74, 1, c1_i73, &c1_dh_emlrtBCI,
          (emlrtConstCTX)c1_sp);
      }

      c1_r_loop_ub = (c1_stats->vector.data[c1_i72].PixelList.size[0] << 1) - 1;
      for (c1_i77 = 0; c1_i77 <= c1_r_loop_ub; c1_i77++) {
        c1_i80 = c1_stats->size[0];
        c1_i81 = (int32_T)c1_f_k;
        if ((c1_i81 < 1) || (c1_i81 > c1_i80)) {
          emlrtDynamicBoundsCheckR2012b(c1_i81, 1, c1_i80, &c1_dh_emlrtBCI,
            (emlrtConstCTX)c1_sp);
        }

        c1_result.vector.data[c1_i77] = c1_stats->vector.data[c1_i81 - 1].
          PixelList.vector.data[c1_i77];
      }

      c1_c_n = (int32_T)c1_b_n - 1;
      c1_st.site = &c1_kf_emlrtRSI;
      c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_r, &c1_dg_emlrtRTEI,
        c1_result.size[0]);
      c1_v_loop_ub = c1_result.size[0] - 1;
      for (c1_i83 = 0; c1_i83 <= c1_v_loop_ub; c1_i83++) {
        c1_r.vector.data[c1_i83] = c1_result.vector.data[c1_i83 +
          c1_result.size[0] * c1_c_n];
      }

      c1_i85 = c1_r.size[0];
      c1_i86 = c1_Intensity.size[0];
      if ((c1_i85 != c1_i86) && ((c1_i85 != 1) && (c1_i86 != 1))) {
        emlrtDimSizeImpxCheckR2021b(c1_i85, c1_i86, &c1_b_emlrtECI,
          (emlrtConstCTX)c1_sp);
      }

      if (c1_r.size[0] == c1_Intensity.size[0]) {
        c1_st.site = &c1_kf_emlrtRSI;
        c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_r1, &c1_dg_emlrtRTEI,
          c1_r.size[0]);
        c1_ab_loop_ub = c1_r.size[0] - 1;
        for (c1_i89 = 0; c1_i89 <= c1_ab_loop_ub; c1_i89++) {
          c1_r1.vector.data[c1_i89] = c1_r.vector.data[c1_i89] *
            c1_Intensity.vector.data[c1_i89];
        }

        c1_st.site = &c1_kf_emlrtRSI;
        c1_M = c1_sum(chartInstance, &c1_st, &c1_r1);
      } else {
        c1_st.site = &c1_kf_emlrtRSI;
        c1_M = c1_binary_expand_op(chartInstance, &c1_st, c1_kf_emlrtRSI, &c1_r,
          &c1_Intensity);
      }

      c1_wc[(int32_T)c1_b_n - 1] = c1_M / c1_sumIntensity;
    }

    for (c1_i53 = 0; c1_i53 < 2; c1_i53++) {
      c1_i56 = c1_stats->size[0];
      c1_i59 = (int32_T)c1_f_k;
      if ((c1_i59 < 1) || (c1_i59 > c1_i56)) {
        emlrtDynamicBoundsCheckR2012b(c1_i59, 1, c1_i56, &c1_fh_emlrtBCI,
          (emlrtConstCTX)c1_sp);
      }

      c1_stats->vector.data[c1_i59 - 1].WeightedCentroid[c1_i53] = c1_wc[c1_i53];
    }
  }

  c1_array_real_T_Destructor(chartInstance, &c1_r1);
  c1_array_real_T_2D_Destructor(chartInstance, &c1_result);
  c1_array_real_T_Destructor(chartInstance, &c1_r);
  c1_array_real_T_Destructor(chartInstance, &c1_Intensity);
}

static void c1_b_sort(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, c1_coder_array_real_T_2D *c1_b_x,
                      c1_coder_array_int32_T_2D *c1_idx)
{
  c1_coder_array_int32_T c1_iwork;
  c1_coder_array_real_T c1_xwork;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_st;
  real_T c1_x4[4];
  real_T c1_c_dv[2];
  real_T c1_c_x;
  int32_T c1_idx4[4];
  int32_T c1_perm[4];
  int32_T c1_b_b;
  int32_T c1_b_i1;
  int32_T c1_b_i2;
  int32_T c1_b_i3;
  int32_T c1_b_i4;
  int32_T c1_b_k;
  int32_T c1_b_loop_ub;
  int32_T c1_b_n;
  int32_T c1_b_nNaNs;
  int32_T c1_b_nNonNaN;
  int32_T c1_c_b;
  int32_T c1_c_k;
  int32_T c1_c_n;
  int32_T c1_d_k;
  int32_T c1_e_b;
  int32_T c1_e_k;
  int32_T c1_f_b;
  int32_T c1_f_k;
  int32_T c1_g_b;
  int32_T c1_g_k;
  int32_T c1_h_b;
  int32_T c1_h_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i_b;
  int32_T c1_i_k;
  int32_T c1_ib;
  int32_T c1_itmp;
  int32_T c1_j_b;
  int32_T c1_k;
  int32_T c1_k_b;
  int32_T c1_l_b;
  int32_T c1_loop_ub;
  int32_T c1_m;
  int32_T c1_m_b;
  int32_T c1_n;
  int32_T c1_nBlocks;
  int32_T c1_nLastBlock;
  int32_T c1_nNaNs;
  int32_T c1_nNonNaN;
  int32_T c1_n_b;
  int32_T c1_o_b;
  int32_T c1_p_b;
  int32_T c1_preSortLevel;
  int32_T c1_quartetOffset;
  int32_T c1_tailOffset;
  int32_T c1_wOffset;
  boolean_T c1_b;
  boolean_T c1_b_overflow;
  boolean_T c1_c_overflow;
  boolean_T c1_d_b;
  boolean_T c1_d_overflow;
  boolean_T c1_e_overflow;
  boolean_T c1_f_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_cg_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_c_dv[c1_i] = (real_T)c1_b_x->size[c1_i];
  }

  c1_array_int32_T_2D_SetSize(chartInstance, &c1_st, c1_idx, &c1_eg_emlrtRTEI,
    (int32_T)c1_c_dv[0], 1);
  c1_loop_ub = (int32_T)c1_c_dv[0] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_idx->vector.data[c1_i1] = 0;
  }

  c1_b = (c1_b_x->size[0] == 0);
  if (!c1_b) {
    c1_b_st.site = &c1_dg_emlrtRSI;
    c1_array_int32_T_Constructor(chartInstance, &c1_iwork);
    c1_array_real_T_Constructor(chartInstance, &c1_xwork);
    for (c1_k = 0; c1_k < 1; c1_k++) {
      c1_b_st.site = &c1_eg_emlrtRSI;
      c1_n = c1_b_x->size[0];
      c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_iwork,
        &c1_fg_emlrtRTEI, c1_idx->size[0]);
      c1_b_loop_ub = c1_idx->size[0] - 1;
      for (c1_i2 = 0; c1_i2 <= c1_b_loop_ub; c1_i2++) {
        c1_iwork.vector.data[c1_i2] = 0;
      }

      c1_c_dv[0] = (real_T)c1_b_x->size[0];
      c1_array_real_T_SetSize(chartInstance, &c1_b_st, &c1_xwork,
        &c1_gg_emlrtRTEI, (int32_T)c1_c_dv[0]);
      c1_c_st.site = &c1_fg_emlrtRSI;
      c1_b_n = c1_b_x->size[0];
      for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
        c1_x4[c1_i3] = 0.0;
      }

      for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
        c1_idx4[c1_i4] = 0;
      }

      c1_nNaNs = 0;
      c1_ib = 0;
      c1_d_st.site = &c1_lg_emlrtRSI;
      c1_b_b = c1_b_n;
      c1_c_b = c1_b_b;
      if (c1_c_b < 1) {
        c1_overflow = false;
      } else {
        c1_overflow = (c1_c_b > 2147483646);
      }

      if (c1_overflow) {
        c1_e_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
      }

      for (c1_b_k = 0; c1_b_k < c1_b_n; c1_b_k++) {
        c1_c_k = c1_b_k;
        c1_c_x = c1_b_x->vector.data[c1_c_k];
        c1_d_b = muDoubleScalarIsNaN(c1_c_x);
        if (c1_d_b) {
          c1_idx->vector.data[(c1_b_n - c1_nNaNs) - 1] = c1_c_k + 1;
          c1_xwork.vector.data[(c1_b_n - c1_nNaNs) - 1] = c1_b_x->
            vector.data[c1_c_k];
          c1_nNaNs++;
        } else {
          c1_ib++;
          c1_idx4[c1_ib - 1] = c1_c_k + 1;
          c1_x4[c1_ib - 1] = c1_b_x->vector.data[c1_c_k];
          if (c1_ib == 4) {
            c1_quartetOffset = c1_c_k - c1_nNaNs;
            if (c1_x4[0] >= c1_x4[1]) {
              c1_b_i1 = 1;
              c1_b_i2 = 2;
            } else {
              c1_b_i1 = 2;
              c1_b_i2 = 1;
            }

            if (c1_x4[2] >= c1_x4[3]) {
              c1_b_i3 = 3;
              c1_b_i4 = 4;
            } else {
              c1_b_i3 = 4;
              c1_b_i4 = 3;
            }

            if (c1_x4[c1_b_i1 - 1] >= c1_x4[c1_b_i3 - 1]) {
              if (c1_x4[c1_b_i2 - 1] >= c1_x4[c1_b_i3 - 1]) {
                c1_perm[0] = c1_b_i1;
                c1_perm[1] = c1_b_i2;
                c1_perm[2] = c1_b_i3;
                c1_perm[3] = c1_b_i4;
              } else if (c1_x4[c1_b_i2 - 1] >= c1_x4[c1_b_i4 - 1]) {
                c1_perm[0] = c1_b_i1;
                c1_perm[1] = c1_b_i3;
                c1_perm[2] = c1_b_i2;
                c1_perm[3] = c1_b_i4;
              } else {
                c1_perm[0] = c1_b_i1;
                c1_perm[1] = c1_b_i3;
                c1_perm[2] = c1_b_i4;
                c1_perm[3] = c1_b_i2;
              }
            } else if (c1_x4[c1_b_i1 - 1] >= c1_x4[c1_b_i4 - 1]) {
              if (c1_x4[c1_b_i2 - 1] >= c1_x4[c1_b_i4 - 1]) {
                c1_perm[0] = c1_b_i3;
                c1_perm[1] = c1_b_i1;
                c1_perm[2] = c1_b_i2;
                c1_perm[3] = c1_b_i4;
              } else {
                c1_perm[0] = c1_b_i3;
                c1_perm[1] = c1_b_i1;
                c1_perm[2] = c1_b_i4;
                c1_perm[3] = c1_b_i2;
              }
            } else {
              c1_perm[0] = c1_b_i3;
              c1_perm[1] = c1_b_i4;
              c1_perm[2] = c1_b_i1;
              c1_perm[3] = c1_b_i2;
            }

            c1_idx->vector.data[c1_quartetOffset - 3] = c1_idx4[c1_perm[0] - 1];
            c1_idx->vector.data[c1_quartetOffset - 2] = c1_idx4[c1_perm[1] - 1];
            c1_idx->vector.data[c1_quartetOffset - 1] = c1_idx4[c1_perm[2] - 1];
            c1_idx->vector.data[c1_quartetOffset] = c1_idx4[c1_perm[3] - 1];
            c1_b_x->vector.data[c1_quartetOffset - 3] = c1_x4[c1_perm[0] - 1];
            c1_b_x->vector.data[c1_quartetOffset - 2] = c1_x4[c1_perm[1] - 1];
            c1_b_x->vector.data[c1_quartetOffset - 1] = c1_x4[c1_perm[2] - 1];
            c1_b_x->vector.data[c1_quartetOffset] = c1_x4[c1_perm[3] - 1];
            c1_ib = 0;
          }
        }
      }

      c1_wOffset = (c1_b_n - c1_nNaNs) - 1;
      if (c1_ib > 0) {
        c1_c_n = c1_ib;
        for (c1_i5 = 0; c1_i5 < 4; c1_i5++) {
          c1_perm[c1_i5] = 0;
        }

        if (c1_c_n == 1) {
          c1_perm[0] = 1;
        } else if (c1_c_n == 2) {
          if (c1_x4[0] >= c1_x4[1]) {
            c1_perm[0] = 1;
            c1_perm[1] = 2;
          } else {
            c1_perm[0] = 2;
            c1_perm[1] = 1;
          }
        } else if (c1_x4[0] >= c1_x4[1]) {
          if (c1_x4[1] >= c1_x4[2]) {
            c1_perm[0] = 1;
            c1_perm[1] = 2;
            c1_perm[2] = 3;
          } else if (c1_x4[0] >= c1_x4[2]) {
            c1_perm[0] = 1;
            c1_perm[1] = 3;
            c1_perm[2] = 2;
          } else {
            c1_perm[0] = 3;
            c1_perm[1] = 1;
            c1_perm[2] = 2;
          }
        } else if (c1_x4[0] >= c1_x4[2]) {
          c1_perm[0] = 2;
          c1_perm[1] = 1;
          c1_perm[2] = 3;
        } else if (c1_x4[1] >= c1_x4[2]) {
          c1_perm[0] = 2;
          c1_perm[1] = 3;
          c1_perm[2] = 1;
        } else {
          c1_perm[0] = 3;
          c1_perm[1] = 2;
          c1_perm[2] = 1;
        }

        c1_d_st.site = &c1_mg_emlrtRSI;
        c1_g_b = c1_ib;
        c1_h_b = c1_g_b;
        if (c1_h_b < 1) {
          c1_c_overflow = false;
        } else {
          c1_c_overflow = (c1_h_b > 2147483646);
        }

        if (c1_c_overflow) {
          c1_e_st.site = &c1_yc_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
        }

        c1_i6 = (uint8_T)c1_ib - 1;
        for (c1_e_k = 0; c1_e_k <= c1_i6; c1_e_k++) {
          c1_c_k = c1_e_k;
          c1_idx->vector.data[((c1_wOffset - c1_ib) + c1_c_k) + 1] =
            c1_idx4[c1_perm[c1_c_k] - 1];
          c1_b_x->vector.data[((c1_wOffset - c1_ib) + c1_c_k) + 1] =
            c1_x4[c1_perm[c1_c_k] - 1];
        }
      }

      c1_m = c1_nNaNs >> 1;
      c1_d_st.site = &c1_ng_emlrtRSI;
      c1_e_b = c1_m;
      c1_f_b = c1_e_b;
      if (c1_f_b < 1) {
        c1_b_overflow = false;
      } else {
        c1_b_overflow = (c1_f_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_e_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
      }

      for (c1_d_k = 0; c1_d_k < c1_m; c1_d_k++) {
        c1_c_k = c1_d_k + 1;
        c1_itmp = c1_idx->vector.data[c1_wOffset + c1_c_k];
        c1_idx->vector.data[c1_wOffset + c1_c_k] = c1_idx->vector.data[c1_b_n -
          c1_c_k];
        c1_idx->vector.data[c1_b_n - c1_c_k] = c1_itmp;
        c1_b_x->vector.data[c1_wOffset + c1_c_k] = c1_xwork.vector.data[c1_b_n -
          c1_c_k];
        c1_b_x->vector.data[c1_b_n - c1_c_k] = c1_xwork.vector.data[c1_wOffset +
          c1_c_k];
      }

      if ((c1_nNaNs & 1) != 0) {
        c1_b_x->vector.data[(c1_wOffset + c1_m) + 1] = c1_xwork.vector.data
          [(c1_wOffset + c1_m) + 1];
      }

      c1_nNonNaN = c1_n - c1_nNaNs;
      c1_preSortLevel = 2;
      if (c1_nNonNaN > 1) {
        if (c1_n >= 256) {
          c1_nBlocks = c1_nNonNaN >> 8;
          if (c1_nBlocks > 0) {
            c1_c_st.site = &c1_gg_emlrtRSI;
            c1_i_b = c1_nBlocks;
            c1_j_b = c1_i_b;
            if (c1_j_b < 1) {
              c1_d_overflow = false;
            } else {
              c1_d_overflow = (c1_j_b > 2147483646);
            }

            if (c1_d_overflow) {
              c1_d_st.site = &c1_yc_emlrtRSI;
              c1_check_forloop_overflow_error(chartInstance, &c1_d_st);
            }

            for (c1_m_b = 0; c1_m_b < c1_nBlocks; c1_m_b++) {
              c1_n_b = c1_m_b;
              c1_c_st.site = &c1_hg_emlrtRSI;
              c1_b_merge_pow2_block(chartInstance, &c1_c_st, c1_idx, c1_b_x,
                                    c1_n_b << 8);
            }

            c1_tailOffset = c1_nBlocks << 8;
            c1_nLastBlock = c1_nNonNaN - c1_tailOffset;
            if (c1_nLastBlock > 0) {
              c1_c_st.site = &c1_ig_emlrtRSI;
              c1_b_merge_block(chartInstance, &c1_c_st, c1_idx, c1_b_x,
                               c1_tailOffset, c1_nLastBlock, 2, &c1_iwork,
                               &c1_xwork);
            }

            c1_preSortLevel = 8;
          }
        }

        c1_c_st.site = &c1_jg_emlrtRSI;
        c1_b_merge_block(chartInstance, &c1_c_st, c1_idx, c1_b_x, 0, c1_nNonNaN,
                         c1_preSortLevel, &c1_iwork, &c1_xwork);
      }

      if ((c1_nNaNs > 0) && (c1_nNonNaN > 0)) {
        c1_c_st.site = &c1_kg_emlrtRSI;
        c1_b_nNonNaN = c1_nNonNaN - 1;
        c1_b_nNaNs = c1_nNaNs - 1;
        c1_d_st.site = &c1_xg_emlrtRSI;
        c1_k_b = c1_b_nNaNs + 1;
        c1_l_b = c1_k_b;
        if (c1_l_b < 1) {
          c1_e_overflow = false;
        } else {
          c1_e_overflow = (c1_l_b > 2147483646);
        }

        if (c1_e_overflow) {
          c1_e_st.site = &c1_yc_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
        }

        for (c1_f_k = 0; c1_f_k <= c1_b_nNaNs; c1_f_k++) {
          c1_h_k = c1_f_k;
          c1_xwork.vector.data[c1_h_k] = c1_b_x->vector.data[(c1_b_nNonNaN +
            c1_h_k) + 1];
          c1_iwork.vector.data[c1_h_k] = c1_idx->vector.data[(c1_b_nNonNaN +
            c1_h_k) + 1];
        }

        for (c1_g_k = c1_b_nNonNaN + 1; c1_g_k >= 1; c1_g_k--) {
          c1_b_x->vector.data[c1_b_nNaNs + c1_g_k] = c1_b_x->vector.data[c1_g_k
            - 1];
          c1_idx->vector.data[c1_b_nNaNs + c1_g_k] = c1_idx->vector.data[c1_g_k
            - 1];
        }

        c1_d_st.site = &c1_yg_emlrtRSI;
        c1_o_b = c1_b_nNaNs + 1;
        c1_p_b = c1_o_b;
        if (c1_p_b < 1) {
          c1_f_overflow = false;
        } else {
          c1_f_overflow = (c1_p_b > 2147483646);
        }

        if (c1_f_overflow) {
          c1_e_st.site = &c1_yc_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
        }

        for (c1_i_k = 0; c1_i_k <= c1_b_nNaNs; c1_i_k++) {
          c1_h_k = c1_i_k;
          c1_b_x->vector.data[c1_h_k] = c1_xwork.vector.data[c1_h_k];
          c1_idx->vector.data[c1_h_k] = c1_iwork.vector.data[c1_h_k];
        }
      }
    }

    c1_array_real_T_Destructor(chartInstance, &c1_xwork);
    c1_array_int32_T_Destructor(chartInstance, &c1_iwork);
  }
}

static void c1_b_merge_pow2_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_idx,
  c1_coder_array_real_T_2D *c1_b_x, int32_T c1_offset)
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_xwork[256];
  int32_T c1_iwork[256];
  int32_T c1_b;
  int32_T c1_bLen;
  int32_T c1_bLen2;
  int32_T c1_b_b;
  int32_T c1_b_j;
  int32_T c1_b_k;
  int32_T c1_blockOffset;
  int32_T c1_c_a;
  int32_T c1_c_b;
  int32_T c1_c_j;
  int32_T c1_d_a;
  int32_T c1_d_b;
  int32_T c1_e_b;
  int32_T c1_exitg1;
  int32_T c1_f_b;
  int32_T c1_g_b;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_iout;
  int32_T c1_j;
  int32_T c1_k;
  int32_T c1_nPairs;
  int32_T c1_offset1;
  int32_T c1_p;
  int32_T c1_q;
  boolean_T c1_b_overflow;
  boolean_T c1_c_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  for (c1_b = 0; c1_b < 6; c1_b++) {
    c1_bLen = 1 << (c1_b + 2);
    c1_bLen2 = c1_bLen << 1;
    c1_nPairs = 256 >> (c1_b + 3);
    c1_st.site = &c1_og_emlrtRSI;
    c1_b_b = c1_nPairs;
    c1_c_b = c1_b_b;
    if (c1_c_b < 1) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_c_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    c1_i = (uint8_T)c1_nPairs - 1;
    for (c1_k = 0; c1_k <= c1_i; c1_k++) {
      c1_b_k = c1_k;
      c1_blockOffset = (c1_offset + c1_b_k * c1_bLen2) - 1;
      c1_st.site = &c1_pg_emlrtRSI;
      c1_d_b = c1_bLen2;
      c1_e_b = c1_d_b;
      if (c1_e_b < 1) {
        c1_b_overflow = false;
      } else {
        c1_b_overflow = (c1_e_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_b_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
      }

      c1_i1 = (uint16_T)c1_bLen2 - 1;
      for (c1_j = 0; c1_j <= c1_i1; c1_j++) {
        c1_b_j = c1_j;
        c1_iwork[c1_b_j] = c1_idx->vector.data[(c1_blockOffset + c1_b_j) + 1];
        c1_xwork[c1_b_j] = c1_b_x->vector.data[(c1_blockOffset + c1_b_j) + 1];
      }

      c1_p = 0;
      c1_q = c1_bLen;
      c1_iout = c1_blockOffset;
      do {
        c1_exitg1 = 0;
        c1_iout++;
        if (c1_xwork[c1_p] >= c1_xwork[c1_q]) {
          c1_idx->vector.data[c1_iout] = c1_iwork[c1_p];
          c1_b_x->vector.data[c1_iout] = c1_xwork[c1_p];
          if (c1_p + 1 < c1_bLen) {
            c1_p++;
          } else {
            c1_exitg1 = 1;
          }
        } else {
          c1_idx->vector.data[c1_iout] = c1_iwork[c1_q];
          c1_b_x->vector.data[c1_iout] = c1_xwork[c1_q];
          if (c1_q + 1 < c1_bLen2) {
            c1_q++;
          } else {
            c1_offset1 = c1_iout - c1_p;
            c1_st.site = &c1_qg_emlrtRSI;
            c1_c_a = c1_p + 1;
            c1_f_b = c1_bLen;
            c1_d_a = c1_c_a;
            c1_g_b = c1_f_b;
            if (c1_d_a > c1_g_b) {
              c1_c_overflow = false;
            } else {
              c1_c_overflow = (c1_g_b > 2147483646);
            }

            if (c1_c_overflow) {
              c1_b_st.site = &c1_yc_emlrtRSI;
              c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
            }

            for (c1_c_j = c1_p + 1; c1_c_j <= c1_bLen; c1_c_j++) {
              c1_idx->vector.data[c1_offset1 + c1_c_j] = c1_iwork[c1_c_j - 1];
              c1_b_x->vector.data[c1_offset1 + c1_c_j] = c1_xwork[c1_c_j - 1];
            }

            c1_exitg1 = 1;
          }
        }
      } while (c1_exitg1 == 0);
    }
  }
}

static void c1_b_merge_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_idx,
  c1_coder_array_real_T_2D *c1_b_x, int32_T c1_offset, int32_T c1_n, int32_T
  c1_preSortLevel, c1_coder_array_int32_T *c1_iwork, c1_coder_array_real_T
  *c1_xwork)
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_b;
  int32_T c1_bLen;
  int32_T c1_bLen2;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_k;
  int32_T c1_nBlocks;
  int32_T c1_nPairs;
  int32_T c1_nTail;
  int32_T c1_tailOffset;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_nBlocks = c1_n >> c1_preSortLevel;
  c1_bLen = 1 << c1_preSortLevel;
  while (c1_nBlocks > 1) {
    if ((c1_nBlocks & 1) != 0) {
      c1_nBlocks--;
      c1_tailOffset = c1_bLen * c1_nBlocks;
      c1_nTail = c1_n - c1_tailOffset;
      if (c1_nTail > c1_bLen) {
        c1_st.site = &c1_rg_emlrtRSI;
        c1_b_merge(chartInstance, &c1_st, c1_idx, c1_b_x, c1_offset +
                   c1_tailOffset, c1_bLen, c1_nTail - c1_bLen, c1_iwork,
                   c1_xwork);
      }
    }

    c1_bLen2 = c1_bLen << 1;
    c1_nPairs = c1_nBlocks >> 1;
    c1_st.site = &c1_sg_emlrtRSI;
    c1_b = c1_nPairs;
    c1_b_b = c1_b;
    if (c1_b_b < 1) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_k = 0; c1_k < c1_nPairs; c1_k++) {
      c1_b_k = c1_k;
      c1_st.site = &c1_tg_emlrtRSI;
      c1_b_merge(chartInstance, &c1_st, c1_idx, c1_b_x, c1_offset + c1_b_k *
                 c1_bLen2, c1_bLen, c1_bLen, c1_iwork, c1_xwork);
    }

    c1_bLen = c1_bLen2;
    c1_nBlocks = c1_nPairs;
  }

  if (c1_n > c1_bLen) {
    c1_st.site = &c1_ug_emlrtRSI;
    c1_b_merge(chartInstance, &c1_st, c1_idx, c1_b_x, c1_offset, c1_bLen, c1_n -
               c1_bLen, c1_iwork, c1_xwork);
  }
}

static void c1_b_merge(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_idx,
  c1_coder_array_real_T_2D *c1_b_x, int32_T c1_offset, int32_T c1_np, int32_T
  c1_nq, c1_coder_array_int32_T *c1_iwork, c1_coder_array_real_T *c1_xwork)
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_j;
  int32_T c1_c_a;
  int32_T c1_c_b;
  int32_T c1_c_j;
  int32_T c1_d_a;
  int32_T c1_d_b;
  int32_T c1_exitg1;
  int32_T c1_iout;
  int32_T c1_j;
  int32_T c1_n;
  int32_T c1_offset1;
  int32_T c1_p;
  int32_T c1_q;
  int32_T c1_qend;
  boolean_T c1_b_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  if (c1_nq != 0) {
    c1_n = c1_np + c1_nq;
    c1_st.site = &c1_wg_emlrtRSI;
    c1_b = c1_n;
    c1_b_b = c1_b;
    if (c1_b_b < 1) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_j = 0; c1_j < c1_n; c1_j++) {
      c1_b_j = c1_j;
      c1_iwork->vector.data[c1_b_j] = c1_idx->vector.data[c1_offset + c1_b_j];
      c1_xwork->vector.data[c1_b_j] = c1_b_x->vector.data[c1_offset + c1_b_j];
    }

    c1_p = 0;
    c1_q = c1_np;
    c1_qend = c1_np + c1_nq;
    c1_iout = c1_offset - 1;
    do {
      c1_exitg1 = 0;
      c1_iout++;
      if (c1_xwork->vector.data[c1_p] >= c1_xwork->vector.data[c1_q]) {
        c1_idx->vector.data[c1_iout] = c1_iwork->vector.data[c1_p];
        c1_b_x->vector.data[c1_iout] = c1_xwork->vector.data[c1_p];
        if (c1_p + 1 < c1_np) {
          c1_p++;
        } else {
          c1_exitg1 = 1;
        }
      } else {
        c1_idx->vector.data[c1_iout] = c1_iwork->vector.data[c1_q];
        c1_b_x->vector.data[c1_iout] = c1_xwork->vector.data[c1_q];
        if (c1_q + 1 < c1_qend) {
          c1_q++;
        } else {
          c1_offset1 = c1_iout - c1_p;
          c1_st.site = &c1_vg_emlrtRSI;
          c1_c_a = c1_p + 1;
          c1_c_b = c1_np;
          c1_d_a = c1_c_a;
          c1_d_b = c1_c_b;
          if (c1_d_a > c1_d_b) {
            c1_b_overflow = false;
          } else {
            c1_b_overflow = (c1_d_b > 2147483646);
          }

          if (c1_b_overflow) {
            c1_b_st.site = &c1_yc_emlrtRSI;
            c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
          }

          for (c1_c_j = c1_p + 1; c1_c_j <= c1_np; c1_c_j++) {
            c1_idx->vector.data[c1_offset1 + c1_c_j] = c1_iwork->
              vector.data[c1_c_j - 1];
            c1_b_x->vector.data[c1_offset1 + c1_c_j] = c1_xwork->
              vector.data[c1_c_j - 1];
          }

          c1_exitg1 = 1;
        }
      }
    } while (c1_exitg1 == 0);
  }
}

static void c1_b_sortrows(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_coder_array_int32_T_2D *c1_b_y, real_T
  c1_c_varargin_1[2])
{
  static char_T c1_b_cv[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 's', 's',
    'o', 'r', 't', 'e', 'd', 'r', 'o', 'w', 's', ':', 'C', 'o', 'l', 'M', 'i',
    's', 'm', 'a', 't', 'c', 'h', 'X' };

  c1_coder_array_int32_T c1_idx;
  c1_coder_array_int32_T c1_ycol;
  c1_coder_array_int32_T_2D c1_g_x;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_ck;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_e_y;
  real_T c1_f_x;
  int32_T c1_col[2];
  int32_T c1_b_iv[1];
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_i;
  int32_T c1_b_i2;
  int32_T c1_b_j;
  int32_T c1_b_loop_ub;
  int32_T c1_b_n;
  int32_T c1_b_p;
  int32_T c1_c_a;
  int32_T c1_c_b;
  int32_T c1_c_i;
  int32_T c1_c_j;
  int32_T c1_c_k;
  int32_T c1_d_b;
  int32_T c1_d_i;
  int32_T c1_d_k;
  int32_T c1_e_b;
  int32_T c1_e_i;
  int32_T c1_e_k;
  int32_T c1_exitg1;
  int32_T c1_f_b;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_j;
  int32_T c1_k;
  int32_T c1_kEnd;
  int32_T c1_len;
  int32_T c1_loop_ub;
  int32_T c1_m;
  int32_T c1_n;
  int32_T c1_np1;
  int32_T c1_pEnd;
  int32_T c1_q;
  int32_T c1_qEnd;
  boolean_T c1_b_overflow;
  boolean_T c1_c_overflow;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_st.site = &c1_ri_emlrtRSI;
  c1_k = 0;
  do {
    c1_exitg1 = 0;
    if (c1_k < 2) {
      c1_b_k = (real_T)c1_k + 1.0;
      c1_b_x = c1_c_varargin_1[(int32_T)c1_b_k - 1];
      c1_c_x = c1_b_x;
      c1_d_x = c1_c_x;
      c1_ck = muDoubleScalarAbs(c1_d_x);
      c1_e_x = c1_ck;
      c1_f_x = c1_e_x;
      c1_e_y = c1_f_x;
      c1_e_y = muDoubleScalarFloor(c1_e_y);
      if ((c1_e_y != c1_ck) || (c1_ck < 1.0) || (c1_ck > 2.0)) {
        c1_p = false;
        c1_exitg1 = 1;
      } else {
        c1_k++;
      }
    } else {
      c1_p = true;
      c1_exitg1 = 1;
    }
  } while (c1_exitg1 == 0);

  if (!c1_p) {
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 32),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 32),
                  false);
    sf_mex_call(&c1_st, &c1_fb_emlrtMCI, "error", 0U, 2U, 14, c1_c_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_d_y)));
  }

  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_col[c1_i] = (int32_T)c1_c_varargin_1[c1_i];
  }

  c1_st.site = &c1_si_emlrtRSI;
  c1_array_int32_T_2D_Constructor(chartInstance, &c1_g_x);
  c1_b_st.site = &c1_si_emlrtRSI;
  c1_array_int32_T_2D_SetSize(chartInstance, &c1_b_st, &c1_g_x, &c1_hg_emlrtRTEI,
    c1_b_y->size[0], 2);
  c1_loop_ub = (c1_b_y->size[0] << 1) - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_g_x.vector.data[c1_i1] = c1_b_y->vector.data[c1_i1];
  }

  c1_n = c1_g_x.size[0];
  c1_array_int32_T_Constructor(chartInstance, &c1_idx);
  c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_idx, &c1_ig_emlrtRTEI,
    c1_g_x.size[0]);
  c1_b_loop_ub = c1_g_x.size[0] - 1;
  for (c1_i2 = 0; c1_i2 <= c1_b_loop_ub; c1_i2++) {
    c1_idx.vector.data[c1_i2] = 0;
  }

  c1_b_st.site = &c1_ui_emlrtRSI;
  c1_b_n = c1_n;
  c1_array_int32_T_Constructor(chartInstance, &c1_ycol);
  c1_len = c1_idx.size[0];
  c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_ycol, &c1_jg_emlrtRTEI,
    c1_len);
  c1_b_iv[0] = c1_ycol.size[0];
  c1_array_int32_T_SetSize(chartInstance, &c1_b_st, &c1_ycol, &c1_kg_emlrtRTEI,
    c1_b_iv[0]);
  c1_np1 = c1_b_n + 1;
  c1_i3 = c1_b_n;
  for (c1_c_k = 1; c1_c_k <= c1_i3 - 1; c1_c_k += 2) {
    if (c1_sortLE(chartInstance, &c1_g_x, c1_col, c1_c_k, c1_c_k + 1)) {
      c1_idx.vector.data[c1_c_k - 1] = c1_c_k;
      c1_idx.vector.data[c1_c_k] = c1_c_k + 1;
    } else {
      c1_idx.vector.data[c1_c_k - 1] = c1_c_k + 1;
      c1_idx.vector.data[c1_c_k] = c1_c_k;
    }
  }

  if ((c1_b_n & 1) != 0) {
    c1_idx.vector.data[c1_b_n - 1] = c1_b_n;
  }

  c1_b_i = 2;
  while (c1_b_i < c1_b_n) {
    c1_c_a = c1_b_i;
    c1_b_i2 = c1_c_a << 1;
    c1_j = 1;
    for (c1_pEnd = 1 + c1_b_i; c1_pEnd < c1_np1; c1_pEnd = c1_qEnd + c1_b_i) {
      c1_b_p = c1_j - 1;
      c1_q = c1_pEnd - 1;
      c1_qEnd = c1_j + c1_b_i2;
      if (c1_qEnd > c1_np1) {
        c1_qEnd = c1_np1;
      }

      c1_d_k = 0;
      c1_kEnd = c1_qEnd - c1_j;
      while (c1_d_k + 1 <= c1_kEnd) {
        if (c1_sortLE(chartInstance, &c1_g_x, c1_col, c1_idx.vector.data[c1_b_p],
                      c1_idx.vector.data[c1_q])) {
          c1_ycol.vector.data[c1_d_k] = c1_idx.vector.data[c1_b_p];
          c1_b_p++;
          if (c1_b_p + 1 == c1_pEnd) {
            while (c1_q + 1 < c1_qEnd) {
              c1_d_k++;
              c1_ycol.vector.data[c1_d_k] = c1_idx.vector.data[c1_q];
              c1_q++;
            }
          }
        } else {
          c1_ycol.vector.data[c1_d_k] = c1_idx.vector.data[c1_q];
          c1_q++;
          if (c1_q + 1 == c1_qEnd) {
            while (c1_b_p + 1 < c1_pEnd) {
              c1_d_k++;
              c1_ycol.vector.data[c1_d_k] = c1_idx.vector.data[c1_b_p];
              c1_b_p++;
            }
          }
        }

        c1_d_k++;
      }

      c1_b_p = c1_j - 2;
      c1_c_st.site = &c1_vi_emlrtRSI;
      c1_c_b = c1_kEnd;
      c1_d_b = c1_c_b;
      if (c1_d_b < 1) {
        c1_b_overflow = false;
      } else {
        c1_b_overflow = (c1_d_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_d_st.site = &c1_yc_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_d_st);
      }

      for (c1_e_k = 0; c1_e_k < c1_kEnd; c1_e_k++) {
        c1_d_k = c1_e_k;
        c1_idx.vector.data[(c1_b_p + c1_d_k) + 1] = c1_ycol.vector.data[c1_d_k];
      }

      c1_j = c1_qEnd;
    }

    c1_b_i = c1_b_i2;
  }

  c1_array_int32_T_2D_Destructor(chartInstance, &c1_g_x);
  c1_st.site = &c1_ti_emlrtRSI;
  c1_m = c1_b_y->size[0];
  c1_col[0] = c1_m;
  c1_array_int32_T_SetSize(chartInstance, &c1_st, &c1_ycol, &c1_lg_emlrtRTEI,
    c1_col[0]);
  for (c1_b_j = 0; c1_b_j < 2; c1_b_j++) {
    c1_c_j = c1_b_j;
    c1_b_st.site = &c1_wi_emlrtRSI;
    c1_b = c1_m;
    c1_b_b = c1_b;
    if (c1_b_b < 1) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_c_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
    }

    c1_i4 = (uint16_T)c1_m - 1;
    for (c1_c_i = 0; c1_c_i <= c1_i4; c1_c_i++) {
      c1_d_i = c1_c_i;
      c1_ycol.vector.data[c1_d_i] = c1_b_y->vector.data
        [(c1_idx.vector.data[c1_d_i] + c1_b_y->size[0] * c1_c_j) - 1];
    }

    c1_b_st.site = &c1_xi_emlrtRSI;
    c1_e_b = c1_m;
    c1_f_b = c1_e_b;
    if (c1_f_b < 1) {
      c1_c_overflow = false;
    } else {
      c1_c_overflow = (c1_f_b > 2147483646);
    }

    if (c1_c_overflow) {
      c1_c_st.site = &c1_yc_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
    }

    c1_i5 = (uint16_T)c1_m - 1;
    for (c1_e_i = 0; c1_e_i <= c1_i5; c1_e_i++) {
      c1_d_i = c1_e_i;
      c1_b_y->vector.data[c1_d_i + c1_b_y->size[0] * c1_c_j] =
        c1_ycol.vector.data[c1_d_i];
    }
  }

  c1_array_int32_T_Destructor(chartInstance, &c1_ycol);
  c1_array_int32_T_Destructor(chartInstance, &c1_idx);
}

static real_T c1_binary_expand_op(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, emlrtRSInfo c1_in1,
  c1_coder_array_real_T *c1_in2, c1_coder_array_real_T *c1_in3)
{
  c1_coder_array_real_T c1_b_in2;
  emlrtStack c1_st;
  real_T c1_out1;
  int32_T c1_aux_0_0;
  int32_T c1_aux_1_0;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_loop_ub;
  int32_T c1_stride_0_0;
  int32_T c1_stride_1_0;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_array_real_T_Constructor(chartInstance, &c1_b_in2);
  c1_st.site = &c1_kf_emlrtRSI;
  if (c1_in3->size[0] == 1) {
    c1_i = c1_in2->size[0];
  } else {
    c1_i = c1_in3->size[0];
  }

  c1_array_real_T_SetSize(chartInstance, &c1_st, &c1_b_in2, &c1_dg_emlrtRTEI,
    c1_i);
  c1_stride_0_0 = (c1_in2->size[0] != 1);
  c1_stride_1_0 = (c1_in3->size[0] != 1);
  c1_aux_0_0 = 0;
  c1_aux_1_0 = 0;
  if (c1_in3->size[0] == 1) {
    c1_i1 = c1_in2->size[0];
  } else {
    c1_i1 = c1_in3->size[0];
  }

  c1_loop_ub = c1_i1 - 1;
  for (c1_i2 = 0; c1_i2 <= c1_loop_ub; c1_i2++) {
    c1_b_in2.vector.data[c1_i2] = c1_in2->vector.data[c1_aux_0_0] *
      c1_in3->vector.data[c1_aux_1_0];
    c1_aux_1_0 += c1_stride_1_0;
    c1_aux_0_0 += c1_stride_0_0;
  }

  c1_st.site = &c1_in1;
  c1_out1 = c1_sum(chartInstance, &c1_st, &c1_b_in2);
  c1_array_real_T_Destructor(chartInstance, &c1_b_in2);
  return c1_out1;
}

static void c1_array_real_T_2D_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T_2D
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0, int32_T
  c1_size1)
{
  real_T *c1_newData;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  (void)chartInstance;
  c1_coderArray->size[0] = c1_size0;
  c1_coderArray->size[1] = c1_size1;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c1_coderArray->size[0],
                       c1_srcLocation, (void *)c1_sp), (size_t)(uint32_T)
    c1_coderArray->size[1], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_creal_T_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_creal_T *c1_coderArray,
  const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0)
{
  creal_T *c1_newData;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  (void)chartInstance;
  c1_coderArray->size[0] = c1_size0;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c1_coderArray->size[0], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (creal_T *)emlrtMallocMex(sizeof(creal_T) * (uint32_T)
      c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof(creal_T) * (uint32_T)
             c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_boolean_T_2D_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_boolean_T_2D
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0, int32_T
  c1_size1)
{
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  boolean_T *c1_newData;
  (void)chartInstance;
  c1_coderArray->size[0] = c1_size0;
  c1_coderArray->size[1] = c1_size1;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c1_coderArray->size[0],
                       c1_srcLocation, (void *)c1_sp), (size_t)(uint32_T)
    c1_coderArray->size[1], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (boolean_T *)emlrtMallocMex(sizeof(boolean_T) * (uint32_T)
      c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof(boolean_T)
             * (uint32_T)c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_int32_T_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T *c1_coderArray,
  const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0)
{
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  int32_T *c1_newData;
  (void)chartInstance;
  c1_coderArray->size[0] = c1_size0;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c1_coderArray->size[0], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_real_T_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T *c1_coderArray,
  const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0)
{
  real_T *c1_newData;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  (void)chartInstance;
  c1_coderArray->size[0] = c1_size0;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c1_coderArray->size[0], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_boolean_T_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_boolean_T
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0)
{
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  boolean_T *c1_newData;
  (void)chartInstance;
  c1_coderArray->size[0] = c1_size0;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c1_coderArray->size[0], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (boolean_T *)emlrtMallocMex(sizeof(boolean_T) * (uint32_T)
      c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof(boolean_T)
             * (uint32_T)c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_real32_T_2D_SetSize(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, c1_coder_array_real32_T_2D
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0, int32_T
  c1_size1)
{
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  real32_T *c1_newData;
  (void)chartInstance;
  c1_coderArray->size[0] = c1_size0;
  c1_coderArray->size[1] = c1_size1;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c1_coderArray->size[0],
                       c1_srcLocation, (void *)c1_sp), (size_t)(uint32_T)
    c1_coderArray->size[1], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (real32_T *)emlrtMallocMex(sizeof(real32_T) * (uint32_T)
      c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof(real32_T)
             * (uint32_T)c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_creal_T_2D_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_creal_T_2D
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0, int32_T
  c1_size1)
{
  creal_T *c1_newData;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  (void)chartInstance;
  c1_coderArray->size[0] = c1_size0;
  c1_coderArray->size[1] = c1_size1;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c1_coderArray->size[0],
                       c1_srcLocation, (void *)c1_sp), (size_t)(uint32_T)
    c1_coderArray->size[1], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (creal_T *)emlrtMallocMex(sizeof(creal_T) * (uint32_T)
      c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof(creal_T) * (uint32_T)
             c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_sOA5t73y81YtFHGIDxk0fKF_S
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_coder_array_sOA5t73y81YtFHGIDxk *c1_coderArray, const emlrtRTEInfo
   *c1_srcLocation, int32_T c1_size0)
{
  c1_sOA5t73y81YtFHGIDxk0fKF *c1_newData;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  (void)chartInstance;
  c1_coderArray->size[0] = c1_size0;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c1_coderArray->size[0], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (c1_sOA5t73y81YtFHGIDxk0fKF *)emlrtMallocMex(sizeof
      (c1_sOA5t73y81YtFHGIDxk0fKF) * (uint32_T)c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof
             (c1_sOA5t73y81YtFHGIDxk0fKF) * (uint32_T)
             c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_coder_array_s_R6Og1x0kmqQXSF9Pw *c1_coderArray, const emlrtRTEInfo
   *c1_srcLocation, int32_T c1_size0)
{
  c1_s_R6Og1x0kmqQXSF9Pwa49FD *c1_newData;
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  c1_coderArray->size[0] = c1_size0;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c1_coderArray->size[0], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel < c1_coderArray->vector.numel) {
    for (c1_i = c1_newNumel; c1_i < c1_coderArray->vector.numel; c1_i++) {
      c1_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance,
        &c1_coderArray->vector.data[c1_i]);
    }
  }

  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (c1_s_R6Og1x0kmqQXSF9Pwa49FD *)emlrtMallocMex(sizeof
      (c1_s_R6Og1x0kmqQXSF9Pwa49FD) * (uint32_T)c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof
             (c1_s_R6Og1x0kmqQXSF9Pwa49FD) * (uint32_T)
             c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  for (c1_b_i = c1_coderArray->vector.numel; c1_b_i < c1_newNumel; c1_b_i++) {
    c1_c_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance,
      &c1_coderArray->vector.data[c1_b_i]);
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_real_T_Destructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_real_T *c1_coderArray)
{
  (void)chartInstance;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s_R6Og1x0kmqQXSF9Pwa49FD *c1_pStruct)
{
  c1_array_real_T_Destructor(chartInstance, &c1_pStruct->PixelIdxList);
  c1_array_real_T_2D_Destructor(chartInstance, &c1_pStruct->PixelList);
  c1_array_real_T_Destructor(chartInstance, &c1_pStruct->PixelValues);
}

static void c1_array_real_T_2D_Destructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_real_T_2D *c1_coderArray)
{
  (void)chartInstance;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_c_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s_R6Og1x0kmqQXSF9Pwa49FD *c1_pStruct)
{
  c1_array_boolean_T_0x0_Constructor(chartInstance, &c1_pStruct->Image);
  c1_array_boolean_T_0x0_Constructor(chartInstance, &c1_pStruct->FilledImage);
  c1_array_real_T_Constructor(chartInstance, &c1_pStruct->PixelIdxList);
  c1_array_real_T_2D_Constructor(chartInstance, &c1_pStruct->PixelList);
  c1_array_real_T_Constructor(chartInstance, &c1_pStruct->PixelValues);
  c1_array_real_T_1x0_Constructor(chartInstance, &c1_pStruct->SubarrayIdx);
}

static void c1_array_boolean_T_0x0_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_boolean_T_0x0 *c1_pArray)
{
  (void)chartInstance;
  c1_pArray->size[0] = 0;
  c1_pArray->size[1] = 0;
}

static void c1_array_real_T_Constructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_real_T *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (real_T *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
}

static void c1_array_real_T_2D_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_real_T_2D *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (real_T *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
  c1_coderArray->size[1] = 0;
}

static void c1_array_real_T_1x0_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_real_T_1x0 *c1_pArray)
{
  (void)chartInstance;
  c1_pArray->size[0] = 0;
  c1_pArray->size[1] = 0;
}

static void c1_array_cell_wrap_46_2D_SetSize
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_coder_array_cell_wrap_46_2D *c1_coderArray, const emlrtRTEInfo
   *c1_srcLocation, int32_T c1_size0, int32_T c1_size1)
{
  c1_cell_wrap_46 *c1_newData;
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  c1_coderArray->size[0] = c1_size0;
  c1_coderArray->size[1] = c1_size1;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c1_coderArray->size[0],
                       c1_srcLocation, (void *)c1_sp), (size_t)(uint32_T)
    c1_coderArray->size[1], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel < c1_coderArray->vector.numel) {
    for (c1_i = c1_newNumel; c1_i < c1_coderArray->vector.numel; c1_i++) {
      c1_array_cell_wrap_46_Destructor(chartInstance,
        &c1_coderArray->vector.data[c1_i]);
    }
  }

  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (c1_cell_wrap_46 *)emlrtMallocMex(sizeof(c1_cell_wrap_46) *
      (uint32_T)c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof(c1_cell_wrap_46) *
             (uint32_T)c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  for (c1_b_i = c1_coderArray->vector.numel; c1_b_i < c1_newNumel; c1_b_i++) {
    c1_array_cell_wrap_46_Constructor(chartInstance, &c1_coderArray->
      vector.data[c1_b_i]);
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_cell_wrap_46_Destructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance, c1_cell_wrap_46
   *c1_pStruct)
{
  c1_array_real_T_Destructor(chartInstance, &c1_pStruct->f1);
}

static void c1_array_cell_wrap_46_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance, c1_cell_wrap_46
   *c1_pStruct)
{
  c1_array_real_T_Constructor(chartInstance, &c1_pStruct->f1);
}

static void c1_array_int32_T_2D_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_int32_T_2D
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0, int32_T
  c1_size1)
{
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  int32_T *c1_newData;
  (void)chartInstance;
  c1_coderArray->size[0] = c1_size0;
  c1_coderArray->size[1] = c1_size1;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c1_coderArray->size[0],
                       c1_srcLocation, (void *)c1_sp), (size_t)(uint32_T)
    c1_coderArray->size[1], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_real32_T_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real32_T
  *c1_coderArray, const emlrtRTEInfo *c1_srcLocation, int32_T c1_size0)
{
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  real32_T *c1_newData;
  (void)chartInstance;
  c1_coderArray->size[0] = c1_size0;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c1_coderArray->size[0], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (real32_T *)emlrtMallocMex(sizeof(real32_T) * (uint32_T)
      c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof(real32_T)
             * (uint32_T)c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_array_s52BVvgcaqgLKaYLjO15CeF_2
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_coder_array_s52BVvgcaqgLKaYLjO1 *c1_coderArray, const emlrtRTEInfo
   *c1_srcLocation, int32_T c1_size0, int32_T c1_size1)
{
  c1_s52BVvgcaqgLKaYLjO15CeF *c1_newData;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  (void)chartInstance;
  c1_coderArray->size[0] = c1_size0;
  c1_coderArray->size[1] = c1_size1;
  c1_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c1_coderArray->size[0],
                       c1_srcLocation, (void *)c1_sp), (size_t)(uint32_T)
    c1_coderArray->size[1], c1_srcLocation, (void *)c1_sp);
  if (c1_newNumel > c1_coderArray->vector.allocated) {
    c1_newCapacity = c1_coderArray->vector.allocated;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = (c1_s52BVvgcaqgLKaYLjO15CeF *)emlrtMallocMex(sizeof
      (c1_s52BVvgcaqgLKaYLjO15CeF) * (uint32_T)c1_newCapacity);
    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if ((void *)c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, (void *)c1_sp);
    }

    if (c1_coderArray->vector.data != NULL) {
      memcpy(c1_newData, c1_coderArray->vector.data, sizeof
             (c1_s52BVvgcaqgLKaYLjO15CeF) * (uint32_T)
             c1_coderArray->vector.numel);
      if (c1_coderArray->vector.owner) {
        emlrtFreeMex(c1_coderArray->vector.data);
      }
    }

    c1_coderArray->vector.data = c1_newData;
    c1_coderArray->vector.allocated = c1_newCapacity;
    c1_coderArray->vector.owner = true;
  }

  c1_coderArray->vector.numel = c1_newNumel;
}

static void c1_b_array_s52BVvgcaqgLKaYLjO15CeF_2
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_s52BVvgcaqgLKaYLjO1 *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (c1_s52BVvgcaqgLKaYLjO15CeF *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
  c1_coderArray->size[1] = 0;
}

static void c1_c_array_s52BVvgcaqgLKaYLjO15CeF_2
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_s52BVvgcaqgLKaYLjO1 *c1_coderArray)
{
  (void)chartInstance;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data !=
       (c1_s52BVvgcaqgLKaYLjO15CeF *)NULL)) {
    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_array_boolean_T_2D_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_boolean_T_2D *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (boolean_T *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
  c1_coderArray->size[1] = 0;
}

static void c1_array_int32_T_Constructor(SFc1_flightControlSystemInstanceStruct *
  chartInstance, c1_coder_array_int32_T *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (int32_T *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
}

static void c1_array_creal_T_Constructor(SFc1_flightControlSystemInstanceStruct *
  chartInstance, c1_coder_array_creal_T *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (creal_T *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
}

static void c1_array_boolean_T_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_boolean_T *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (boolean_T *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
}

static void c1_array_boolean_T_2D_Destructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_boolean_T_2D *c1_coderArray)
{
  (void)chartInstance;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data != (boolean_T *)
       NULL)) {
    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_array_int32_T_Destructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_int32_T *c1_coderArray)
{
  (void)chartInstance;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_array_creal_T_Destructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_creal_T *c1_coderArray)
{
  (void)chartInstance;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data != (creal_T *)
       NULL)) {
    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_array_boolean_T_Destructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_boolean_T *c1_coderArray)
{
  (void)chartInstance;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data != (boolean_T *)
       NULL)) {
    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_array_real32_T_2D_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_real32_T_2D *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (real32_T *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
  c1_coderArray->size[1] = 0;
}

static void c1_array_creal_T_2D_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_creal_T_2D *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (creal_T *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
  c1_coderArray->size[1] = 0;
}

static void c1_array_real32_T_2D_Destructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_real32_T_2D *c1_coderArray)
{
  (void)chartInstance;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data != (real32_T *)
       NULL)) {
    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_array_creal_T_2D_Destructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_creal_T_2D *c1_coderArray)
{
  (void)chartInstance;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data != (creal_T *)
       NULL)) {
    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_array_sOA5t73y81YtFHGIDxk0fKF_C
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_sOA5t73y81YtFHGIDxk *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (c1_sOA5t73y81YtFHGIDxk0fKF *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
}

static void c1_array_int32_T_2D_Constructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_int32_T_2D *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (int32_T *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
  c1_coderArray->size[1] = 0;
}

static void c1_array_sOA5t73y81YtFHGIDxk0fKF_D
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_sOA5t73y81YtFHGIDxk *c1_coderArray)
{
  (void)chartInstance;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data !=
       (c1_sOA5t73y81YtFHGIDxk0fKF *)NULL)) {
    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_array_int32_T_2D_Destructor
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_int32_T_2D *c1_coderArray)
{
  (void)chartInstance;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_d_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_s_R6Og1x0kmqQXSF9Pwa49FD *c1_dst, const
   c1_s_R6Og1x0kmqQXSF9Pwa49FD *c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  c1_dst->Area = c1_src->Area;
  c1_array_real_T_1x2s_Copy(chartInstance, c1_dst->Centroid, c1_src->Centroid);
  c1_array_real_T_1x4s_Copy(chartInstance, c1_dst->BoundingBox,
    c1_src->BoundingBox);
  c1_dst->MajorAxisLength = c1_src->MajorAxisLength;
  c1_dst->MinorAxisLength = c1_src->MinorAxisLength;
  c1_dst->Eccentricity = c1_src->Eccentricity;
  c1_dst->Orientation = c1_src->Orientation;
  c1_array_boolean_T_0x0_Copy(chartInstance, c1_sp, &c1_dst->Image,
    &c1_src->Image, c1_srcLocation);
  c1_array_boolean_T_0x0_Copy(chartInstance, c1_sp, &c1_dst->FilledImage,
    &c1_src->FilledImage, c1_srcLocation);
  c1_dst->FilledArea = c1_src->FilledArea;
  c1_dst->EulerNumber = c1_src->EulerNumber;
  c1_array_real_T_8x2s_Copy(chartInstance, c1_dst->Extrema, c1_src->Extrema);
  c1_dst->EquivDiameter = c1_src->EquivDiameter;
  c1_dst->Extent = c1_src->Extent;
  c1_array_real_T_Copy(chartInstance, c1_sp, &c1_dst->PixelIdxList,
                       &c1_src->PixelIdxList, c1_srcLocation);
  c1_array_real_T_2D_Copy(chartInstance, c1_sp, &c1_dst->PixelList,
    &c1_src->PixelList, c1_srcLocation);
  c1_dst->Perimeter = c1_src->Perimeter;
  c1_dst->Circularity = c1_src->Circularity;
  c1_array_real_T_Copy(chartInstance, c1_sp, &c1_dst->PixelValues,
                       &c1_src->PixelValues, c1_srcLocation);
  c1_array_real_T_1x2s_Copy(chartInstance, c1_dst->WeightedCentroid,
    c1_src->WeightedCentroid);
  c1_dst->MeanIntensity = c1_src->MeanIntensity;
  c1_dst->MinIntensity = c1_src->MinIntensity;
  c1_dst->MaxIntensity = c1_src->MaxIntensity;
  c1_array_real_T_1x0_Copy(chartInstance, c1_sp, &c1_dst->SubarrayIdx,
    &c1_src->SubarrayIdx, c1_srcLocation);
  c1_array_real_T_1x2s_Copy(chartInstance, c1_dst->SubarrayIdxLengths,
    c1_src->SubarrayIdxLengths);
}

static void c1_array_real_T_1x2s_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[2], const real_T c1_src[2])
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_dst[c1_i] = c1_src[c1_i];
  }
}

static void c1_array_real_T_1x4s_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[4], const real_T c1_src[4])
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 4; c1_i++) {
    c1_dst[c1_i] = c1_src[c1_i];
  }
}

static void c1_array_boolean_T_0x0_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_boolean_T_0x0 *c1_dst,
  const c1_coder_array_boolean_T_0x0 *c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  c1_array_boolean_T_0x0_SetSize(chartInstance, c1_sp, c1_dst->size,
    c1_srcLocation, c1_src->size[0], c1_src->size[1]);
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c1_src->size[0], c1_srcLocation, (void *)c1_sp), (size_t)
                     (uint32_T)c1_src->size[1], c1_srcLocation, (void *)c1_sp);
}

static void c1_array_boolean_T_0x0_SetSize
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, int32_T c1_size[2], const emlrtRTEInfo *c1_srcLocation, int32_T
   c1_size0, int32_T c1_size1)
{
  (void)chartInstance;
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c1_size[0], c1_srcLocation, (void *)c1_sp), (size_t)
                     (uint32_T)c1_size[1], c1_srcLocation, (void *)c1_sp);
  c1_size[0] = c1_size0;
  c1_size[1] = c1_size1;
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c1_size[0], c1_srcLocation, (void *)c1_sp), (size_t)
                     (uint32_T)c1_size[1], c1_srcLocation, (void *)c1_sp);
}

static void c1_array_real_T_8x2s_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[16], const real_T c1_src[16])
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 16; c1_i++) {
    c1_dst[c1_i] = c1_src[c1_i];
  }
}

static void c1_array_real_T_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T *c1_dst, const
  c1_coder_array_real_T *c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  c1_array_real_T_SetSize(chartInstance, c1_sp, c1_dst, c1_srcLocation,
    c1_src->size[0]);
  for (c1_i = 0; c1_i < c1_src->vector.numel; c1_i++) {
    c1_dst->vector.data[c1_i] = c1_src->vector.data[c1_i];
  }
}

static void c1_array_real_T_2D_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T_2D *c1_dst,
  const c1_coder_array_real_T_2D *c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  c1_array_real_T_2D_SetSize(chartInstance, c1_sp, c1_dst, c1_srcLocation,
    c1_src->size[0], c1_src->size[1]);
  for (c1_i = 0; c1_i < c1_src->vector.numel; c1_i++) {
    c1_dst->vector.data[c1_i] = c1_src->vector.data[c1_i];
  }
}

static void c1_array_real_T_1x0_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_coder_array_real_T_1x0 *c1_dst,
  const c1_coder_array_real_T_1x0 *c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  c1_array_real_T_1x0_SetSize(chartInstance, c1_sp, c1_dst->size, c1_srcLocation,
    c1_src->size[0], c1_src->size[1]);
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c1_src->size[0], c1_srcLocation, (void *)c1_sp), (size_t)
                     (uint32_T)c1_src->size[1], c1_srcLocation, (void *)c1_sp);
}

static void c1_array_real_T_1x0_SetSize(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, int32_T c1_size[2], const
  emlrtRTEInfo *c1_srcLocation, int32_T c1_size0, int32_T c1_size1)
{
  (void)chartInstance;
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c1_size[0], c1_srcLocation, (void *)c1_sp), (size_t)
                     (uint32_T)c1_size[1], c1_srcLocation, (void *)c1_sp);
  c1_size[0] = c1_size0;
  c1_size[1] = c1_size1;
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c1_size[0], c1_srcLocation, (void *)c1_sp), (size_t)
                     (uint32_T)c1_size[1], c1_srcLocation, (void *)c1_sp);
}

static void c1_array_s_7KvKuzB0WpLeFthPVHAilE_
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s_7KvKuzB0WpLeFthPVHAilE *c1_pStruct)
{
  c1_array_real_T_Constructor(chartInstance, &c1_pStruct->RegionIndices);
  c1_array_int32_T_Constructor(chartInstance, &c1_pStruct->RegionLengths);
  c1_array_cell_wrap_46_2D_Construct(chartInstance, &c1_pStruct->PixelIdxList);
}

static void c1_array_cell_wrap_46_2D_Construct
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_cell_wrap_46_2D *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (c1_cell_wrap_46 *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
  c1_coderArray->size[1] = 0;
}

static void c1_e_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_s_R6Og1x0kmqQXSF9Pw *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (c1_s_R6Og1x0kmqQXSF9Pwa49FD *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
}

static void c1_b_array_s_7KvKuzB0WpLeFthPVHAilE_
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s_7KvKuzB0WpLeFthPVHAilE *c1_pStruct)
{
  c1_array_real_T_Destructor(chartInstance, &c1_pStruct->RegionIndices);
  c1_array_int32_T_Destructor(chartInstance, &c1_pStruct->RegionLengths);
  c1_array_cell_wrap_46_2D_Destructo(chartInstance, &c1_pStruct->PixelIdxList);
}

static void c1_array_cell_wrap_46_2D_Destructo
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_cell_wrap_46_2D *c1_coderArray)
{
  int32_T c1_i;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data !=
       (c1_cell_wrap_46 *)NULL)) {
    for (c1_i = 0; c1_i < c1_coderArray->vector.numel; c1_i++) {
      c1_array_cell_wrap_46_Destructor(chartInstance,
        &c1_coderArray->vector.data[c1_i]);
    }

    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_f_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_coder_array_s_R6Og1x0kmqQXSF9Pw *c1_coderArray)
{
  int32_T c1_i;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data !=
       (c1_s_R6Og1x0kmqQXSF9Pwa49FD *)NULL)) {
    for (c1_i = 0; c1_i < c1_coderArray->vector.numel; c1_i++) {
      c1_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance,
        &c1_coderArray->vector.data[c1_i]);
    }

    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_array_cell_wrap_46_Copy(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_cell_wrap_46 *c1_dst, const
  c1_cell_wrap_46 *c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  c1_array_real_T_Copy(chartInstance, c1_sp, &c1_dst->f1, &c1_src->f1,
                       c1_srcLocation);
}

static void c1_array_cell_wrap_46_1s_Construct
  (SFc1_flightControlSystemInstanceStruct *chartInstance, c1_cell_wrap_46
   c1_pMatrix[1])
{
  int32_T c1_i;
  for (c1_i = 0; c1_i < 1; c1_i++) {
    c1_array_cell_wrap_46_Constructor(chartInstance, &c1_pMatrix[c1_i]);
  }
}

static void c1_array_cell_wrap_46_1s_Destructo
  (SFc1_flightControlSystemInstanceStruct *chartInstance, c1_cell_wrap_46
   c1_pMatrix[1])
{
  int32_T c1_i;
  for (c1_i = 0; c1_i < 1; c1_i++) {
    c1_array_cell_wrap_46_Destructor(chartInstance, &c1_pMatrix[c1_i]);
  }
}

static void c1_array_real32_T_Constructor(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_coder_array_real32_T *c1_coderArray)
{
  (void)chartInstance;
  c1_coderArray->vector.data = (real32_T *)NULL;
  c1_coderArray->vector.numel = 0;
  c1_coderArray->vector.allocated = 0;
  c1_coderArray->vector.owner = true;
  c1_coderArray->size[0] = 0;
}

static void c1_array_real32_T_Destructor(SFc1_flightControlSystemInstanceStruct *
  chartInstance, c1_coder_array_real32_T *c1_coderArray)
{
  (void)chartInstance;
  if (c1_coderArray->vector.owner && (c1_coderArray->vector.data != (real32_T *)
       NULL)) {
    emlrtFreeMex(c1_coderArray->vector.data);
  }
}

static void c1_array_cell_wrap_46_2s_Construct
  (SFc1_flightControlSystemInstanceStruct *chartInstance, c1_cell_wrap_46
   c1_pMatrix[2])
{
  int32_T c1_i;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_array_cell_wrap_46_Constructor(chartInstance, &c1_pMatrix[c1_i]);
  }
}

static void c1_array_cell_wrap_46_2s_Destructo
  (SFc1_flightControlSystemInstanceStruct *chartInstance, c1_cell_wrap_46
   c1_pMatrix[2])
{
  int32_T c1_i;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_array_cell_wrap_46_Destructor(chartInstance, &c1_pMatrix[c1_i]);
  }
}

static int32_T c1_div_nzp_s32(SFc1_flightControlSystemInstanceStruct
  *chartInstance, int32_T c1_numerator, int32_T c1_denominator, int32_T
  c1_EMLOvCount_src_loc, uint32_T c1_ssid_src_loc, int32_T c1_offset_src_loc,
  int32_T c1_length_src_loc)
{
  int32_T c1_quotient;
  uint32_T c1_absDenominator;
  uint32_T c1_absNumerator;
  uint32_T c1_tempAbsQuotient;
  boolean_T c1_quotientNeedsNegation;
  (void)chartInstance;
  (void)c1_EMLOvCount_src_loc;
  (void)c1_ssid_src_loc;
  (void)c1_offset_src_loc;
  (void)c1_length_src_loc;
  if (c1_numerator < 0) {
    c1_absNumerator = ~(uint32_T)c1_numerator + 1U;
  } else {
    c1_absNumerator = (uint32_T)c1_numerator;
  }

  if (c1_denominator < 0) {
    c1_absDenominator = ~(uint32_T)c1_denominator + 1U;
  } else {
    c1_absDenominator = (uint32_T)c1_denominator;
  }

  c1_quotientNeedsNegation = ((c1_numerator < 0) != (c1_denominator < 0));
  c1_tempAbsQuotient = c1_absNumerator / c1_absDenominator;
  if (c1_quotientNeedsNegation) {
    c1_quotient = -(int32_T)c1_tempAbsQuotient;
  } else {
    c1_quotient = (int32_T)c1_tempAbsQuotient;
  }

  return c1_quotient;
}

static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_y = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c1_number = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_data1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_angelina = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c1_u = (real_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_data = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_angle_ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1963043334U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1090196829U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1572150187U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3125710960U);
}

mxArray *sf_c1_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,9);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Grayto8Buildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.GetnumcoresBuildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "images.internal.coder.buildable.CannyThresholdingTbbBuildable"));
  mxSetCell(mxcell3p, 5, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  mxSetCell(mxcell3p, 6, mxCreateString(
             "images.internal.coder.buildable.Bwlookup_tbb_Buildable"));
  mxSetCell(mxcell3p, 7, mxCreateString(
             "images.internal.coder.buildable.Ordfilt2Buildable"));
  mxSetCell(mxcell3p, 8, mxCreateString(
             "images.internal.coder.buildable.ImregionalmaxBuildable"));
  return(mxcell3p);
}

mxArray *sf_c1_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("grayto8_real64");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiAuYGZgYAPSHEDMxAABrFA+IxCzQGmIOAtcXAGISyoLUkHixUXJnilAOi8xF8x"
    "PLK3wzEvLB5tvwYAwnw2L+YxI5nNCxSHggz1l+lUc0PWzYNHPgaRfAMpPzEtPzcnMS+SDig+sP2"
    "SI8gcrmj9A/JTEkkRDqPsH3h9KRPmDDc0fIH5eaW5SatFg8YcI2B8GBPzBiOIPRoZKpHgAADcDH"
    "eo="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "syzodyOq5CWlchXM65OWTCH";
}

static void sf_opaque_initialize_c1_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_flightControlSystem(void *chartInstanceVar)
{
  enable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_flightControlSystem(void *chartInstanceVar)
{
  disable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc1_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c1_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [22] = {
    "eNrdWFtv40QUnrTZ0kXLUiTERVppV4gHXpDoRkU8cGk3FzZSQyKcbhEvaGKfxKOOx+5ckmbFD0D",
    "8Enjgmb/CG3+BRx454zhp5ITEk4BSsOQ4x84355zP5zYhpWaL4PEQz5/eJeQAr4d47pHJcS+TS3",
    "Pn5H6ZfJrJnVcJ8UMqdVP0Y+J++HEAAxCe6ffZjSNWmKhDJY3UBnoFjeBrUDE3msXCzXgm+iBB+",
    "LhAEkvtpFexyHAmrhpG+FazugyZH3phbHjwDBekQVvw8d/pTYzuoMYak+DrBkCgQxmbQdjgdLCa",
    "BalH1RD8K2UiZ64UaM8k1lXVMlyzhEP9BvymUJoiC2qNv56mGqr6xjlCmPKm6DhKOKOiONchVR4",
    "kGB0aLpIAP9tGI3sF9aK+HhNUx5JRXo941UZ4QWyHo50tDGvuzLOOdA16ZjBgYmDZlSYCgf5jnB",
    "Tgql+NhyDpANrCMQetd/Wb9AXP4rJ4DjZtWG6UgyaavBW1ETbVWx8iQ2pDvQ1fVCnnyg3bjZNzG",
    "AJP9deophtgJ/odwEqxoBu/oNJmgWMmGcGuDWTYaiwCVvwND3OotOB+hcWzAJxFNqQgQJpnps8W",
    "WheTRuk4qmIa1c7PC+pbxDaFBtmnPhSufZIyBWhwGleOegOmaI9bNLKkUy8LrwBiYyhRfSNqo1h",
    "eIceuRfaWK5sJbmgIBlADDWnBqGN0v6DcFLQ5UljhbHhcKKxYbnoRa/NnI7BP/RAC208YhxYou4",
    "AqXJ+xj5yht0OmxzVQvmRJ0UwyCgJsJJal7jiBC3El4pFoyDjysolgRVwBYNWgUmBbeIZtSY4ba",
    "HwxqyVcd21kbTKeRVRz2rOx8SUI7CzWV9sJqY9ZVRc4uqFB22A99hJbu1BMaRynxvU0B4J0Hn2n",
    "5DaPvpHJlVkuNVVX4pui2IYFTkpnvXTYgy6LIL3hUZwpJmJ2WL0fkVu99/dW693Db6UNcWRL3PM",
    "5XHkJP2/N4Y4y2T/+rs/ZILRFWMuYe2PkPVq040EBvpfZn8eRBdwtz9PrB3P40hK9ZO66jq/9Bb",
    "72SalUSnGnc7jXcnrKOdxBxtlnPxz+Uvm98uP3P/d+fVx5/ZVt4uNJ2S2eH2byo+l8Nutgw4UiX",
    "yQe3s7Fg5XV+GUcjNvXJ9VL7offtD4+aV92q8/T9ZL91faWc/ZO7z/BU2OBS+ul9JtBtteyMjWT",
    "PYBd/5M5ew/W8HF/Lp4I+eOL7fDvn+bxy/g6zPFlZSoGgJWazsfv7vx4VMiPezk/rIzbIXqcy8P",
    "d+fFeIT8Ocn4cTObpHsi74sebp/n6UF6DP8Jv49x7uOv9Z1f9bpd2FumH+xviyuTf67//JG5b/1",
    "z7/H/996vqAMn9/ugO+0FW1CeXee+u+fUbcZvHHmfy57P/Yqoh48GS3WD2GDds/WVP/yfx/acjf",
    "9P5s275y/5M/rZyJigf4/Zvsr3Obnek/R9z9kgCVcv32LvoQ9Pr6Zo+/yCX31YeMRHEI/Xh8dOT",
    "p9v0tb8AspQPzA==",
    ""
  };

  static char newstr [1517] = "";
  newstr[0] = '\0';
  for (i = 0; i < 22; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c1_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2903017533U));
  ssSetChecksum1(S,(2318655283U));
  ssSetChecksum2(S,(3076696444U));
  ssSetChecksum3(S,(118436639U));
}

static void mdlRTW_c1_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_flightControlSystem(SimStruct *S)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc1_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_flightControlSystem;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c1_flightControlSystem(chartInstance);
}

void c1_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
