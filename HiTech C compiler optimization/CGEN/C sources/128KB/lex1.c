/*
 * File - lex1u.c
 */

#include "cgen.h"

/* clang-format on */

/* offsets into character array below */
static int16_t array_987D[] = { 0,     0,     4,     9,     0x0A,  0x0C,  0x0E,  0x1C,  0x2D,
                         0x31,  0x3E,  0x52,  0x54,  0x62,  0x7C,  0x8E,  0x0A0, 0x0A1,
                         0x0A3, 0x0B3, 0x0C3, 0x0D7, 0x0E7, 0x0E8, 0x0EB, 0x0F9, 0x0FB,
                         0x0FD, 0x10B, 0x119, 0x11A, 0x11F, 0x12F, 0x130, 0x147, 0x155,
                         0x165, 0x173, 0x18B, 0x19B, 0x1A9, 0x1B9, 0x1BE, 0x1CE, 0x1DE,
                         0x1EE, 0x1EF, 0x1F4, 0x204, 0x214, 0x216, 0x217, 0x218, 0x219,
                         0x21A, 0x21B, 0x21C, 0x21D, 0x21E, 0x22E, 0x22F, 0x23F, 0x243,
                         0x244, 0x254, 0x255, 0x256, 0x26F, 0x28D, 0x2A6, 0x2B6, 0x2B8 };

static uint8_t array_990D[] = {
    "Qhi\0"                           /* [0 or 1] 000h */
    "PQhi\0"                          /* [2] 004h */
    "\0"                              /* [3] 009h */
    "H\0"                             /* [4] 00Ah */
    "H\0"                             /* [5] 00Ch */
    "HNSTZ]^_djprs\0"                 /* [6] 00Eh */
    "HNSTUVZ]^_dgjprs\0"              /* [7] 01Ch */
    "Qhi\0"                           /* [8] 02Dh */
    "HNTYZ]^djprs\0"                  /* [9] 031h */
    "HNRSTUVZ[]^_`djnprs\0"           /* [10] 03Eh */
    "H\0"                             /* [11] 052h */
    "HNSTZ]^_djprs\0"                 /* [12] 054h */
    "HIMNRSTUVZ[\\]^_`abcdfjprs\0"    /* [13] 062h */
    "HNSTUVYZ]^_djprsw\0"             /* [14] 07Ch */
    "HNSTUVZ]^_djklprs\0"             /* [15] 08Eh */
    "\0"                              /* [16] 0A0h */
    "N\0"                             /* [17] 0A1h */
    "HNSTUVZ]^_djprs\0"               /* [18] 0A3h */
    "HNSTUVZ]^_djprs\0"               /* [19] 0B3h */
    "HNRSTUVYZ[]^_`djprs\0"           /* [20] 0C3h */
    "HNSTUVZ]^_djprs\0"               /* [21] 0D7h */
    "\0"                              /* [22] 0E7h */
    "Nt\0"                            /* [23] 0E8h */
    "HNSTZ]^_djprs\0"                 /* [24] 0EBh */
    "m\0"                             /* [25] 0F9h */
    "H\0"                             /* [26] 0FBh */
    "HNOTYZ]^djprs\0"                 /* [27] 0FDh */
    "HNTUVZ]^djprs\0"                 /* [28] 10Bh */
    "\0"                              /* [29] 119h */
    "PQhi\0"                          /* [30] 11Ah */
    "HNSTUVZ]^_djprs\0"               /* [31] 11Fh */
    "\0"                              /* [32] 12Fh */
    "HNRSTUVWZ[]^_`cdfjprsw\0"        /* [33] 130h */
    "HNSTZ]^_djprs\0"                 /* [34] 147h */
    "HNSTUVZ]^_djprs\0"               /* [35] 155h */
    "HNSTZ]^_djprs\0"                 /* [36] 165h */
    "HINSTUVWZ]^_abcdfjprsvw\0"       /* [37] 173h */
    "HNSTUVZ]^_djprs\0"               /* [38] 18Bh */
    "HNSTZ]^_djprs\0"                 /* [39] 19Bh */
    "HNSTUVZ]^_djprs\0"               /* [40] 1A9h */
    "PQhi\0"                          /* [41] 1B9h */
    "HNSTUVZ]^_djprs\0"               /* [42] 1BEh */
    "HNSTUVZ]^_djprs\0"               /* [43] 1CEh */
    "HNSTUVZ]^_djprs\0"               /* [44] 1DEh */
    "\0"                              /* [45] 1EEh */
    "PQhi\0"                          /* [46] 1EFh */
    "HNSTUVZ]^_djprs\0"               /* [47] 1F4h */
    "HNSTUVZ]^_djprs\0"               /* [48] 204h */
    "H\0"                             /* [49] 214h */
    "\0"                              /* [50] 216h */
    "\0"                              /* [51] 217h */
    "\0"                              /* [52] 218h */
    "\0"                              /* [53] 219h */
    "\0"                              /* [54] 21Ah */
    "\0"                              /* [55] 21Bh */
    "\0"                              /* [56] 21Ch */
    "\0"                              /* [57] 21Dh */
    "HNSTUVZ]^_djprs\0"               /* [58] 21Eh */
    "\0"                              /* [59] 22Eh */
    "HNSTUVZ]^_djprs\0"               /* [60] 22Fh */
    "Qhi\0"                           /* [61] 23Fh */
    "\0"                              /* [62] 243h */
    "HNSTUVZ]^_djprs\0"               /* [63] 244h */
    "\0"                              /* [64] 254h */
    "\0"                              /* [65] 255h */
    "HMNORSTUVZ[\\]^_`acdfjprs\0"     /* [66] 256h */
    "HIJKLNOSTUVYZ]^_abcdfjopqrsux\0" /* [67] 26Fh */
    "HMNRSTUVXZ[\\]^_`acdfjprs\0"     /* [68] 28Dh */
    "HNTWZ]^cdfjprsw\0"               /* [69] 2A6h */
    "H\0"                             /* [70] 2B6h */
    "HNTZ]^cdefjprs"                  /* [71] 2B8h */
};

static int16_t array_9BD4[] = {
    -66,  -65,  -68,  0,    89,   -69,  -65,  -68,  0,    0,    1,    0,    -8,   0,    3,
    62,   -221, 141,  -167, 231,  251,  -151, 264,  -70,  -106, 276,  -100, 0,    5,    64,
    -221, 141,  -90,  163,  170,  234,  251,  -151, 264,  -63,  -70,  274,  278,  -100, 0,
    -64,  -65,  -68,  0,    -28,  -47,  141,  -33,  172,  239,  251,  264,  -70,  -106, -102,
    -100, 0,    8,    68,   -245, -215, 141,  -84,  163,  174,  -250, 234,  251,  -151, -243,
    264,  -70,  -98,  274,  278,  -100, 0,    13,   0,    3,    62,   -221, 141,  -167, 231,
    251,  -151, 264,  -70,  -106, 276,  -100, 0,    9,    58,

    60,   68,   116,  118,  141,  143,  163,  176,  229,  -111, 241,  251,  -151, 253,  255,
    257,  259,  264,  266,  -70,  274,  278,  -100, 0,    5,    64,   121,  141,  -89,  163,
    -36,  182,  234,  251,  -151, 264,  -70,  274,  278,  -100, 283,  0,    18,   64,   -220,
    141,  147,  163,  187,  234,  251,  -151, 264,  -70,  -141, -137, 274,  278,  -100, 0,
    0,    -49,  0,    5,    64,   -221, 141,  -90,  163,  -197, 234,  251,  -151, 264,  -70,
    274,  278,  -100, 0,    23,   64,   -220, 141,  147,  163,  189,  234,  251,  -151, 264,
    -70,  274,  278,  -100, 0,    9,    68,   -245, 123,  141,

    149,  163,  -35,  191,  -251, 234,  251,  -151, -243, 264,  -70,  274,  278,  -100, 0,
    5,    64,   132,  141,  -96,  163,  -202, 234,  251,  -151, 264,  -70,  274,  278,  -100,
    0,    0,    -50,  -114, 0,    3,    62,   -221, 141,  -167, 231,  251,  -151, 264,  -70,
    -106, 276,  -100, 0,    -99,  0,    -16,  0,    -28,  -47,  -148, 141,  -32,  -161, 239,
    251,  264,  -70,  -106, -102, -100, 0,    27,   73,   141,  -74,  163,  -164, 247,  251,
    264,  -70,  274,  279,  -100, 0,    0,    102,  -69,  -65,  -68,  0,    5,    64,   -223,
    141,  155,  163,  200,  234,  251,  -151, 264,  -70,  274,

    278,  -100, 0,    0,    30,   76,   -245, 134,  141,  157,  163,  165,  202,  -247, 234,
    251,  -151, -243, -54,  264,  269,  -70,  274,  278,  -100, -139, 0,    3,    62,   -219,
    141,  -166, 231,  251,  -151, 264,  -70,  -106, 276,  -100, 0,    38,   64,   -219, 141,
    -92,  163,  209,  234,  251,  -151, 264,  -70,  274,  278,  -100, 0,    3,    62,   -219,
    141,  -166, 231,  251,  -151, 264,  -70,  -106, 276,  -100, 0,    42,   -238, 82,   137,
    141,  159,  163,  168,  211,  241,  251,  -151, -51,  -152, 262,  264,  271,  -70,  274,
    278,  -100, 281,  -139, 0,    23,   64,   -219, 141,  -92,

    163,  217,  234,  251,  -151, 264,  -70,  274,  278,  -100, 0,    3,    62,   -219, 141,
    -166, 231,  251,  -151, 264,  -70,  -106, 276,  -100, 0,    5,    64,   -222, 141,  161,
    163,  -170, 234,  251,  -151, 264,  -70,  274,  278,  -100, 0,    89,   -69,  -65,  -68,
    0,    5,    64,   -222, 141,  161,  163,  -170, 234,  251,  -151, 264,  -70,  274,  278,
    -100, 0,    5,    64,   -219, 141,  -92,  163,  -179, 234,  251,  -151, 264,  -70,  274,
    278,  -100, 0,    48,   64,   -219, 141,  -92,  163,  219,  234,  251,  -151, 264,  -70,
    274,  278,  -100, 0,    0,    109,  -69,  -65,  -68,  0,

    5,    64,   -223, 141,  155,  163,  221,  234,  251,  -151, 264,  -70,  274,  278,  -100,
    0,    5,    64,   -216, 141,  -76,  163,  -160, 234,  251,  -151, 264,  -70,  274,  278,
    -100, 0,    52,   0,    0,    0,    0,    0,    0,    0,    0,    0,    5,    64,   -221,
    141,  -90,  163,  -178, 234,  251,  -151, 264,  -70,  274,  278,  -100, 0,    0,    5,
    64,   -221, 141,  -90,  163,  223,  234,  251,  -151, 264,  -70,  274,  278,  -100, 0,
    -67,  -65,  -68,  0,    0,    5,    64,   -227, 141,  -95,  163,  -202, 234,  251,  -151,
    264,  -70,  274,  278,  -100, 0,    0,    0,    9,    -133,

    68,   -149, -245, -212, 141,  -97,  163,  225,  -248, -112, 234,  251,  -151, -243, -52,
    -53,  264,  -61,  -70,  274,  278,  -100, 0,    5,    -237, -104, -252, -242, 64,   -150,
    139,  141,  -73,  163,  -34,  227,  241,  251,  -151, -51,  -152, -55,  264,  272,  -70,
    -241, 274,  -155, 278,  -100, -253, -154, 0,    9,    -133, 68,   -245, -212, 141,  -97,
    163,  -115, 225,  -248, -113, 234,  251,  -151, -243, -52,  -53,  264,  -61,  -70,  274,
    278,  -100, 0,    56,   87,   141,  -142, -165, 239,  251,  -54,  264,  269,  -70,  -106,
    -102, -100, -139, 0,    -18,  0,    -28,  -47,  141,  -158,

    239,  251,  -57,  264,  -62,  -61,  -70,  -106, -102, -100, 0
};

/*********************************************************
 * sub_13D	Ok++ PMO		Used in: sub_1F4B
 * This function wasn't optimised in original code hence
 * it is split out separately
 *********************************************************/
int sub_13D(int a, int b) {
    int i;

    for (i = array_987D[b]; array_990D[i] != 0 && array_990D[i] != a; i++)
        ;
    return array_9BD4[i];
}

/* end of file lex1u.c */
