/* ATMega238pb sound processing experiments - Look-up tables
Copyright 2019 Alex Isabelle Shuping

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */

#pragma once
#include <avr/io.h>
#include <avr/pgmspace.h>

/* 4096-step cosine lookup table */

const uint16_t PROGMEM cosine_lut[4096] = {
0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,
0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xffe,
0xffe,0xffe,0xffe,0xffe,0xffe,0xffe,0xffe,0xffe,
0xffe,0xffd,0xffd,0xffd,0xffd,0xffd,0xffd,0xffd,
0xffd,0xffc,0xffc,0xffc,0xffc,0xffc,0xffc,0xffb,
0xffb,0xffb,0xffb,0xffb,0xffa,0xffa,0xffa,0xffa,
0xff9,0xff9,0xff9,0xff9,0xff8,0xff8,0xff8,0xff8,
0xff7,0xff7,0xff7,0xff7,0xff6,0xff6,0xff6,0xff5,
0xff5,0xff5,0xff5,0xff4,0xff4,0xff4,0xff3,0xff3,
0xff3,0xff2,0xff2,0xff1,0xff1,0xff1,0xff0,0xff0,
0xff0,0xfef,0xfef,0xfee,0xfee,0xfee,0xfed,0xfed,
0xfec,0xfec,0xfec,0xfeb,0xfeb,0xfea,0xfea,0xfe9,
0xfe9,0xfe8,0xfe8,0xfe7,0xfe7,0xfe6,0xfe6,0xfe5,
0xfe5,0xfe4,0xfe4,0xfe3,0xfe3,0xfe2,0xfe2,0xfe1,
0xfe1,0xfe0,0xfe0,0xfdf,0xfdf,0xfde,0xfde,0xfdd,
0xfdc,0xfdc,0xfdb,0xfdb,0xfda,0xfd9,0xfd9,0xfd8,
0xfd8,0xfd7,0xfd6,0xfd6,0xfd5,0xfd5,0xfd4,0xfd3,
0xfd3,0xfd2,0xfd1,0xfd1,0xfd0,0xfcf,0xfcf,0xfce,
0xfcd,0xfcd,0xfcc,0xfcb,0xfca,0xfca,0xfc9,0xfc8,
0xfc8,0xfc7,0xfc6,0xfc5,0xfc5,0xfc4,0xfc3,0xfc2,
0xfc2,0xfc1,0xfc0,0xfbf,0xfbf,0xfbe,0xfbd,0xfbc,
0xfbb,0xfbb,0xfba,0xfb9,0xfb8,0xfb7,0xfb6,0xfb6,
0xfb5,0xfb4,0xfb3,0xfb2,0xfb1,0xfb1,0xfb0,0xfaf,
0xfae,0xfad,0xfac,0xfab,0xfaa,0xfaa,0xfa9,0xfa8,
0xfa7,0xfa6,0xfa5,0xfa4,0xfa3,0xfa2,0xfa1,0xfa0,
0xf9f,0xf9e,0xf9d,0xf9d,0xf9c,0xf9b,0xf9a,0xf99,
0xf98,0xf97,0xf96,0xf95,0xf94,0xf93,0xf92,0xf91,
0xf90,0xf8f,0xf8e,0xf8d,0xf8c,0xf8a,0xf89,0xf88,
0xf87,0xf86,0xf85,0xf84,0xf83,0xf82,0xf81,0xf80,
0xf7f,0xf7e,0xf7d,0xf7b,0xf7a,0xf79,0xf78,0xf77,
0xf76,0xf75,0xf74,0xf72,0xf71,0xf70,0xf6f,0xf6e,
0xf6d,0xf6b,0xf6a,0xf69,0xf68,0xf67,0xf66,0xf64,
0xf63,0xf62,0xf61,0xf60,0xf5e,0xf5d,0xf5c,0xf5b,
0xf59,0xf58,0xf57,0xf56,0xf54,0xf53,0xf52,0xf51,
0xf4f,0xf4e,0xf4d,0xf4c,0xf4a,0xf49,0xf48,0xf46,
0xf45,0xf44,0xf42,0xf41,0xf40,0xf3e,0xf3d,0xf3c,
0xf3a,0xf39,0xf38,0xf36,0xf35,0xf34,0xf32,0xf31,
0xf30,0xf2e,0xf2d,0xf2b,0xf2a,0xf29,0xf27,0xf26,
0xf24,0xf23,0xf22,0xf20,0xf1f,0xf1d,0xf1c,0xf1a,
0xf19,0xf17,0xf16,0xf15,0xf13,0xf12,0xf10,0xf0f,
0xf0d,0xf0c,0xf0a,0xf09,0xf07,0xf06,0xf04,0xf03,
0xf01,0xf00,0xefe,0xefd,0xefb,0xefa,0xef8,0xef7,
0xef5,0xef3,0xef2,0xef0,0xeef,0xeed,0xeec,0xeea,
0xee8,0xee7,0xee5,0xee4,0xee2,0xee1,0xedf,0xedd,
0xedc,0xeda,0xed8,0xed7,0xed5,0xed4,0xed2,0xed0,
0xecf,0xecd,0xecb,0xeca,0xec8,0xec6,0xec5,0xec3,
0xec1,0xec0,0xebe,0xebc,0xebb,0xeb9,0xeb7,0xeb5,
0xeb4,0xeb2,0xeb0,0xeaf,0xead,0xeab,0xea9,0xea8,
0xea6,0xea4,0xea2,0xea1,0xe9f,0xe9d,0xe9b,0xe9a,
0xe98,0xe96,0xe94,0xe92,0xe91,0xe8f,0xe8d,0xe8b,
0xe8a,0xe88,0xe86,0xe84,0xe82,0xe80,0xe7f,0xe7d,
0xe7b,0xe79,0xe77,0xe75,0xe74,0xe72,0xe70,0xe6e,
0xe6c,0xe6a,0xe68,0xe66,0xe65,0xe63,0xe61,0xe5f,
0xe5d,0xe5b,0xe59,0xe57,0xe55,0xe53,0xe51,0xe50,
0xe4e,0xe4c,0xe4a,0xe48,0xe46,0xe44,0xe42,0xe40,
0xe3e,0xe3c,0xe3a,0xe38,0xe36,0xe34,0xe32,0xe30,
0xe2e,0xe2c,0xe2a,0xe28,0xe26,0xe24,0xe22,0xe20,
0xe1e,0xe1c,0xe1a,0xe18,0xe16,0xe14,0xe12,0xe10,
0xe0e,0xe0c,0xe0a,0xe08,0xe06,0xe04,0xe02,0xdff,
0xdfd,0xdfb,0xdf9,0xdf7,0xdf5,0xdf3,0xdf1,0xdef,
0xded,0xdea,0xde8,0xde6,0xde4,0xde2,0xde0,0xdde,
0xddc,0xdd9,0xdd7,0xdd5,0xdd3,0xdd1,0xdcf,0xdcd,
0xdca,0xdc8,0xdc6,0xdc4,0xdc2,0xdc0,0xdbd,0xdbb,
0xdb9,0xdb7,0xdb5,0xdb2,0xdb0,0xdae,0xdac,0xdaa,
0xda7,0xda5,0xda3,0xda1,0xd9e,0xd9c,0xd9a,0xd98,
0xd95,0xd93,0xd91,0xd8f,0xd8c,0xd8a,0xd88,0xd86,
0xd83,0xd81,0xd7f,0xd7c,0xd7a,0xd78,0xd76,0xd73,
0xd71,0xd6f,0xd6c,0xd6a,0xd68,0xd65,0xd63,0xd61,
0xd5f,0xd5c,0xd5a,0xd58,0xd55,0xd53,0xd50,0xd4e,
0xd4c,0xd49,0xd47,0xd45,0xd42,0xd40,0xd3e,0xd3b,
0xd39,0xd36,0xd34,0xd32,0xd2f,0xd2d,0xd2b,0xd28,
0xd26,0xd23,0xd21,0xd1f,0xd1c,0xd1a,0xd17,0xd15,
0xd12,0xd10,0xd0e,0xd0b,0xd09,0xd06,0xd04,0xd01,
0xcff,0xcfc,0xcfa,0xcf8,0xcf5,0xcf3,0xcf0,0xcee,
0xceb,0xce9,0xce6,0xce4,0xce1,0xcdf,0xcdc,0xcda,
0xcd7,0xcd5,0xcd2,0xcd0,0xccd,0xccb,0xcc8,0xcc6,
0xcc3,0xcc1,0xcbe,0xcbc,0xcb9,0xcb7,0xcb4,0xcb1,
0xcaf,0xcac,0xcaa,0xca7,0xca5,0xca2,0xca0,0xc9d,
0xc9a,0xc98,0xc95,0xc93,0xc90,0xc8e,0xc8b,0xc88,
0xc86,0xc83,0xc81,0xc7e,0xc7b,0xc79,0xc76,0xc74,
0xc71,0xc6e,0xc6c,0xc69,0xc67,0xc64,0xc61,0xc5f,
0xc5c,0xc59,0xc57,0xc54,0xc52,0xc4f,0xc4c,0xc4a,
0xc47,0xc44,0xc42,0xc3f,0xc3c,0xc3a,0xc37,0xc34,
0xc32,0xc2f,0xc2c,0xc2a,0xc27,0xc24,0xc22,0xc1f,
0xc1c,0xc19,0xc17,0xc14,0xc11,0xc0f,0xc0c,0xc09,
0xc06,0xc04,0xc01,0xbfe,0xbfc,0xbf9,0xbf6,0xbf3,
0xbf1,0xbee,0xbeb,0xbe9,0xbe6,0xbe3,0xbe0,0xbde,
0xbdb,0xbd8,0xbd5,0xbd3,0xbd0,0xbcd,0xbca,0xbc7,
0xbc5,0xbc2,0xbbf,0xbbc,0xbba,0xbb7,0xbb4,0xbb1,
0xbae,0xbac,0xba9,0xba6,0xba3,0xba0,0xb9e,0xb9b,
0xb98,0xb95,0xb92,0xb90,0xb8d,0xb8a,0xb87,0xb84,
0xb82,0xb7f,0xb7c,0xb79,0xb76,0xb73,0xb71,0xb6e,
0xb6b,0xb68,0xb65,0xb62,0xb60,0xb5d,0xb5a,0xb57,
0xb54,0xb51,0xb4e,0xb4c,0xb49,0xb46,0xb43,0xb40,
0xb3d,0xb3a,0xb37,0xb35,0xb32,0xb2f,0xb2c,0xb29,
0xb26,0xb23,0xb20,0xb1e,0xb1b,0xb18,0xb15,0xb12,
0xb0f,0xb0c,0xb09,0xb06,0xb03,0xb01,0xafe,0xafb,
0xaf8,0xaf5,0xaf2,0xaef,0xaec,0xae9,0xae6,0xae3,
0xae0,0xadd,0xadb,0xad8,0xad5,0xad2,0xacf,0xacc,
0xac9,0xac6,0xac3,0xac0,0xabd,0xaba,0xab7,0xab4,
0xab1,0xaae,0xaab,0xaa8,0xaa5,0xaa2,0xaa0,0xa9d,
0xa9a,0xa97,0xa94,0xa91,0xa8e,0xa8b,0xa88,0xa85,
0xa82,0xa7f,0xa7c,0xa79,0xa76,0xa73,0xa70,0xa6d,
0xa6a,0xa67,0xa64,0xa61,0xa5e,0xa5b,0xa58,0xa55,
0xa52,0xa4f,0xa4c,0xa49,0xa46,0xa43,0xa40,0xa3d,
0xa3a,0xa37,0xa34,0xa31,0xa2e,0xa2b,0xa28,0xa25,
0xa22,0xa1f,0xa1c,0xa19,0xa15,0xa12,0xa0f,0xa0c,
0xa09,0xa06,0xa03,0xa00,0x9fd,0x9fa,0x9f7,0x9f4,
0x9f1,0x9ee,0x9eb,0x9e8,0x9e5,0x9e2,0x9df,0x9dc,
0x9d9,0x9d6,0x9d2,0x9cf,0x9cc,0x9c9,0x9c6,0x9c3,
0x9c0,0x9bd,0x9ba,0x9b7,0x9b4,0x9b1,0x9ae,0x9ab,
0x9a8,0x9a4,0x9a1,0x99e,0x99b,0x998,0x995,0x992,
0x98f,0x98c,0x989,0x986,0x983,0x980,0x97c,0x979,
0x976,0x973,0x970,0x96d,0x96a,0x967,0x964,0x961,
0x95e,0x95a,0x957,0x954,0x951,0x94e,0x94b,0x948,
0x945,0x942,0x93f,0x93b,0x938,0x935,0x932,0x92f,
0x92c,0x929,0x926,0x923,0x91f,0x91c,0x919,0x916,
0x913,0x910,0x90d,0x90a,0x907,0x903,0x900,0x8fd,
0x8fa,0x8f7,0x8f4,0x8f1,0x8ee,0x8eb,0x8e7,0x8e4,
0x8e1,0x8de,0x8db,0x8d8,0x8d5,0x8d2,0x8ce,0x8cb,
0x8c8,0x8c5,0x8c2,0x8bf,0x8bc,0x8b9,0x8b5,0x8b2,
0x8af,0x8ac,0x8a9,0x8a6,0x8a3,0x8a0,0x89c,0x899,
0x896,0x893,0x890,0x88d,0x88a,0x886,0x883,0x880,
0x87d,0x87a,0x877,0x874,0x871,0x86d,0x86a,0x867,
0x864,0x861,0x85e,0x85b,0x857,0x854,0x851,0x84e,
0x84b,0x848,0x845,0x841,0x83e,0x83b,0x838,0x835,
0x832,0x82f,0x82b,0x828,0x825,0x822,0x81f,0x81c,
0x819,0x815,0x812,0x80f,0x80c,0x809,0x806,0x803,
0x800,0x7fc,0x7f9,0x7f6,0x7f3,0x7f0,0x7ed,0x7ea,
0x7e6,0x7e3,0x7e0,0x7dd,0x7da,0x7d7,0x7d4,0x7d0,
0x7cd,0x7ca,0x7c7,0x7c4,0x7c1,0x7be,0x7ba,0x7b7,
0x7b4,0x7b1,0x7ae,0x7ab,0x7a8,0x7a4,0x7a1,0x79e,
0x79b,0x798,0x795,0x792,0x78e,0x78b,0x788,0x785,
0x782,0x77f,0x77c,0x779,0x775,0x772,0x76f,0x76c,
0x769,0x766,0x763,0x75f,0x75c,0x759,0x756,0x753,
0x750,0x74d,0x74a,0x746,0x743,0x740,0x73d,0x73a,
0x737,0x734,0x731,0x72d,0x72a,0x727,0x724,0x721,
0x71e,0x71b,0x718,0x714,0x711,0x70e,0x70b,0x708,
0x705,0x702,0x6ff,0x6fc,0x6f8,0x6f5,0x6f2,0x6ef,
0x6ec,0x6e9,0x6e6,0x6e3,0x6e0,0x6dc,0x6d9,0x6d6,
0x6d3,0x6d0,0x6cd,0x6ca,0x6c7,0x6c4,0x6c0,0x6bd,
0x6ba,0x6b7,0x6b4,0x6b1,0x6ae,0x6ab,0x6a8,0x6a5,
0x6a1,0x69e,0x69b,0x698,0x695,0x692,0x68f,0x68c,
0x689,0x686,0x683,0x67f,0x67c,0x679,0x676,0x673,
0x670,0x66d,0x66a,0x667,0x664,0x661,0x65e,0x65b,
0x657,0x654,0x651,0x64e,0x64b,0x648,0x645,0x642,
0x63f,0x63c,0x639,0x636,0x633,0x630,0x62d,0x629,
0x626,0x623,0x620,0x61d,0x61a,0x617,0x614,0x611,
0x60e,0x60b,0x608,0x605,0x602,0x5ff,0x5fc,0x5f9,
0x5f6,0x5f3,0x5f0,0x5ed,0x5ea,0x5e6,0x5e3,0x5e0,
0x5dd,0x5da,0x5d7,0x5d4,0x5d1,0x5ce,0x5cb,0x5c8,
0x5c5,0x5c2,0x5bf,0x5bc,0x5b9,0x5b6,0x5b3,0x5b0,
0x5ad,0x5aa,0x5a7,0x5a4,0x5a1,0x59e,0x59b,0x598,
0x595,0x592,0x58f,0x58c,0x589,0x586,0x583,0x580,
0x57d,0x57a,0x577,0x574,0x571,0x56e,0x56b,0x568,
0x565,0x562,0x55f,0x55d,0x55a,0x557,0x554,0x551,
0x54e,0x54b,0x548,0x545,0x542,0x53f,0x53c,0x539,
0x536,0x533,0x530,0x52d,0x52a,0x527,0x524,0x522,
0x51f,0x51c,0x519,0x516,0x513,0x510,0x50d,0x50a,
0x507,0x504,0x501,0x4fe,0x4fc,0x4f9,0x4f6,0x4f3,
0x4f0,0x4ed,0x4ea,0x4e7,0x4e4,0x4e1,0x4df,0x4dc,
0x4d9,0x4d6,0x4d3,0x4d0,0x4cd,0x4ca,0x4c8,0x4c5,
0x4c2,0x4bf,0x4bc,0x4b9,0x4b6,0x4b3,0x4b1,0x4ae,
0x4ab,0x4a8,0x4a5,0x4a2,0x49f,0x49d,0x49a,0x497,
0x494,0x491,0x48e,0x48c,0x489,0x486,0x483,0x480,
0x47d,0x47b,0x478,0x475,0x472,0x46f,0x46d,0x46a,
0x467,0x464,0x461,0x45f,0x45c,0x459,0x456,0x453,
0x451,0x44e,0x44b,0x448,0x445,0x443,0x440,0x43d,
0x43a,0x438,0x435,0x432,0x42f,0x42c,0x42a,0x427,
0x424,0x421,0x41f,0x41c,0x419,0x416,0x414,0x411,
0x40e,0x40c,0x409,0x406,0x403,0x401,0x3fe,0x3fb,
0x3f9,0x3f6,0x3f3,0x3f0,0x3ee,0x3eb,0x3e8,0x3e6,
0x3e3,0x3e0,0x3dd,0x3db,0x3d8,0x3d5,0x3d3,0x3d0,
0x3cd,0x3cb,0x3c8,0x3c5,0x3c3,0x3c0,0x3bd,0x3bb,
0x3b8,0x3b5,0x3b3,0x3b0,0x3ad,0x3ab,0x3a8,0x3a6,
0x3a3,0x3a0,0x39e,0x39b,0x398,0x396,0x393,0x391,
0x38e,0x38b,0x389,0x386,0x384,0x381,0x37e,0x37c,
0x379,0x377,0x374,0x371,0x36f,0x36c,0x36a,0x367,
0x365,0x362,0x35f,0x35d,0x35a,0x358,0x355,0x353,
0x350,0x34e,0x34b,0x348,0x346,0x343,0x341,0x33e,
0x33c,0x339,0x337,0x334,0x332,0x32f,0x32d,0x32a,
0x328,0x325,0x323,0x320,0x31e,0x31b,0x319,0x316,
0x314,0x311,0x30f,0x30c,0x30a,0x307,0x305,0x303,
0x300,0x2fe,0x2fb,0x2f9,0x2f6,0x2f4,0x2f1,0x2ef,
0x2ed,0x2ea,0x2e8,0x2e5,0x2e3,0x2e0,0x2de,0x2dc,
0x2d9,0x2d7,0x2d4,0x2d2,0x2d0,0x2cd,0x2cb,0x2c9,
0x2c6,0x2c4,0x2c1,0x2bf,0x2bd,0x2ba,0x2b8,0x2b6,
0x2b3,0x2b1,0x2af,0x2ac,0x2aa,0x2a7,0x2a5,0x2a3,
0x2a0,0x29e,0x29c,0x29a,0x297,0x295,0x293,0x290,
0x28e,0x28c,0x289,0x287,0x285,0x283,0x280,0x27e,
0x27c,0x279,0x277,0x275,0x273,0x270,0x26e,0x26c,
0x26a,0x267,0x265,0x263,0x261,0x25e,0x25c,0x25a,
0x258,0x255,0x253,0x251,0x24f,0x24d,0x24a,0x248,
0x246,0x244,0x242,0x23f,0x23d,0x23b,0x239,0x237,
0x235,0x232,0x230,0x22e,0x22c,0x22a,0x228,0x226,
0x223,0x221,0x21f,0x21d,0x21b,0x219,0x217,0x215,
0x212,0x210,0x20e,0x20c,0x20a,0x208,0x206,0x204,
0x202,0x200,0x1fd,0x1fb,0x1f9,0x1f7,0x1f5,0x1f3,
0x1f1,0x1ef,0x1ed,0x1eb,0x1e9,0x1e7,0x1e5,0x1e3,
0x1e1,0x1df,0x1dd,0x1db,0x1d9,0x1d7,0x1d5,0x1d3,
0x1d1,0x1cf,0x1cd,0x1cb,0x1c9,0x1c7,0x1c5,0x1c3,
0x1c1,0x1bf,0x1bd,0x1bb,0x1b9,0x1b7,0x1b5,0x1b3,
0x1b1,0x1af,0x1ae,0x1ac,0x1aa,0x1a8,0x1a6,0x1a4,
0x1a2,0x1a0,0x19e,0x19c,0x19a,0x199,0x197,0x195,
0x193,0x191,0x18f,0x18d,0x18b,0x18a,0x188,0x186,
0x184,0x182,0x180,0x17f,0x17d,0x17b,0x179,0x177,
0x175,0x174,0x172,0x170,0x16e,0x16d,0x16b,0x169,
0x167,0x165,0x164,0x162,0x160,0x15e,0x15d,0x15b,
0x159,0x157,0x156,0x154,0x152,0x150,0x14f,0x14d,
0x14b,0x14a,0x148,0x146,0x144,0x143,0x141,0x13f,
0x13e,0x13c,0x13a,0x139,0x137,0x135,0x134,0x132,
0x130,0x12f,0x12d,0x12b,0x12a,0x128,0x127,0x125,
0x123,0x122,0x120,0x11e,0x11d,0x11b,0x11a,0x118,
0x117,0x115,0x113,0x112,0x110,0x10f,0x10d,0x10c,
0x10a,0x108,0x107,0x105,0x104,0x102,0x101,0xff,
0xfe,0xfc,0xfb,0xf9,0xf8,0xf6,0xf5,0xf3,
0xf2,0xf0,0xef,0xed,0xec,0xea,0xe9,0xe8,
0xe6,0xe5,0xe3,0xe2,0xe0,0xdf,0xdd,0xdc,
0xdb,0xd9,0xd8,0xd6,0xd5,0xd4,0xd2,0xd1,
0xcf,0xce,0xcd,0xcb,0xca,0xc9,0xc7,0xc6,
0xc5,0xc3,0xc2,0xc1,0xbf,0xbe,0xbd,0xbb,
0xba,0xb9,0xb7,0xb6,0xb5,0xb3,0xb2,0xb1,
0xb0,0xae,0xad,0xac,0xab,0xa9,0xa8,0xa7,
0xa6,0xa4,0xa3,0xa2,0xa1,0x9f,0x9e,0x9d,
0x9c,0x9b,0x99,0x98,0x97,0x96,0x95,0x94,
0x92,0x91,0x90,0x8f,0x8e,0x8d,0x8b,0x8a,
0x89,0x88,0x87,0x86,0x85,0x84,0x82,0x81,
0x80,0x7f,0x7e,0x7d,0x7c,0x7b,0x7a,0x79,
0x78,0x77,0x76,0x75,0x73,0x72,0x71,0x70,
0x6f,0x6e,0x6d,0x6c,0x6b,0x6a,0x69,0x68,
0x67,0x66,0x65,0x64,0x63,0x62,0x62,0x61,
0x60,0x5f,0x5e,0x5d,0x5c,0x5b,0x5a,0x59,
0x58,0x57,0x56,0x55,0x55,0x54,0x53,0x52,
0x51,0x50,0x4f,0x4e,0x4e,0x4d,0x4c,0x4b,
0x4a,0x49,0x49,0x48,0x47,0x46,0x45,0x44,
0x44,0x43,0x42,0x41,0x40,0x40,0x3f,0x3e,
0x3d,0x3d,0x3c,0x3b,0x3a,0x3a,0x39,0x38,
0x37,0x37,0x36,0x35,0x35,0x34,0x33,0x32,
0x32,0x31,0x30,0x30,0x2f,0x2e,0x2e,0x2d,
0x2c,0x2c,0x2b,0x2a,0x2a,0x29,0x29,0x28,
0x27,0x27,0x26,0x26,0x25,0x24,0x24,0x23,
0x23,0x22,0x21,0x21,0x20,0x20,0x1f,0x1f,
0x1e,0x1e,0x1d,0x1d,0x1c,0x1c,0x1b,0x1b,
0x1a,0x1a,0x19,0x19,0x18,0x18,0x17,0x17,
0x16,0x16,0x15,0x15,0x14,0x14,0x13,0x13,
0x13,0x12,0x12,0x11,0x11,0x11,0x10,0x10,
0xf,0xf,0xf,0xe,0xe,0xe,0xd,0xd,
0xc,0xc,0xc,0xb,0xb,0xb,0xa,0xa,
0xa,0xa,0x9,0x9,0x9,0x8,0x8,0x8,
0x8,0x7,0x7,0x7,0x7,0x6,0x6,0x6,
0x6,0x5,0x5,0x5,0x5,0x4,0x4,0x4,
0x4,0x4,0x3,0x3,0x3,0x3,0x3,0x3,
0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,
0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
0x1,0x1,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,
0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
0x1,0x2,0x2,0x2,0x2,0x2,0x2,0x2,
0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x4,
0x4,0x4,0x4,0x4,0x5,0x5,0x5,0x5,
0x6,0x6,0x6,0x6,0x7,0x7,0x7,0x7,
0x8,0x8,0x8,0x8,0x9,0x9,0x9,0xa,
0xa,0xa,0xa,0xb,0xb,0xb,0xc,0xc,
0xc,0xd,0xd,0xe,0xe,0xe,0xf,0xf,
0xf,0x10,0x10,0x11,0x11,0x11,0x12,0x12,
0x13,0x13,0x13,0x14,0x14,0x15,0x15,0x16,
0x16,0x17,0x17,0x18,0x18,0x19,0x19,0x1a,
0x1a,0x1b,0x1b,0x1c,0x1c,0x1d,0x1d,0x1e,
0x1e,0x1f,0x1f,0x20,0x20,0x21,0x21,0x22,
0x23,0x23,0x24,0x24,0x25,0x26,0x26,0x27,
0x27,0x28,0x29,0x29,0x2a,0x2a,0x2b,0x2c,
0x2c,0x2d,0x2e,0x2e,0x2f,0x30,0x30,0x31,
0x32,0x32,0x33,0x34,0x35,0x35,0x36,0x37,
0x37,0x38,0x39,0x3a,0x3a,0x3b,0x3c,0x3d,
0x3d,0x3e,0x3f,0x40,0x40,0x41,0x42,0x43,
0x44,0x44,0x45,0x46,0x47,0x48,0x49,0x49,
0x4a,0x4b,0x4c,0x4d,0x4e,0x4e,0x4f,0x50,
0x51,0x52,0x53,0x54,0x55,0x55,0x56,0x57,
0x58,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x5f,
0x60,0x61,0x62,0x62,0x63,0x64,0x65,0x66,
0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,
0x6f,0x70,0x71,0x72,0x73,0x75,0x76,0x77,
0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
0x80,0x81,0x82,0x84,0x85,0x86,0x87,0x88,
0x89,0x8a,0x8b,0x8d,0x8e,0x8f,0x90,0x91,
0x92,0x94,0x95,0x96,0x97,0x98,0x99,0x9b,
0x9c,0x9d,0x9e,0x9f,0xa1,0xa2,0xa3,0xa4,
0xa6,0xa7,0xa8,0xa9,0xab,0xac,0xad,0xae,
0xb0,0xb1,0xb2,0xb3,0xb5,0xb6,0xb7,0xb9,
0xba,0xbb,0xbd,0xbe,0xbf,0xc1,0xc2,0xc3,
0xc5,0xc6,0xc7,0xc9,0xca,0xcb,0xcd,0xce,
0xcf,0xd1,0xd2,0xd4,0xd5,0xd6,0xd8,0xd9,
0xdb,0xdc,0xdd,0xdf,0xe0,0xe2,0xe3,0xe5,
0xe6,0xe8,0xe9,0xea,0xec,0xed,0xef,0xf0,
0xf2,0xf3,0xf5,0xf6,0xf8,0xf9,0xfb,0xfc,
0xfe,0xff,0x101,0x102,0x104,0x105,0x107,0x108,
0x10a,0x10c,0x10d,0x10f,0x110,0x112,0x113,0x115,
0x117,0x118,0x11a,0x11b,0x11d,0x11e,0x120,0x122,
0x123,0x125,0x127,0x128,0x12a,0x12b,0x12d,0x12f,
0x130,0x132,0x134,0x135,0x137,0x139,0x13a,0x13c,
0x13e,0x13f,0x141,0x143,0x144,0x146,0x148,0x14a,
0x14b,0x14d,0x14f,0x150,0x152,0x154,0x156,0x157,
0x159,0x15b,0x15d,0x15e,0x160,0x162,0x164,0x165,
0x167,0x169,0x16b,0x16d,0x16e,0x170,0x172,0x174,
0x175,0x177,0x179,0x17b,0x17d,0x17f,0x180,0x182,
0x184,0x186,0x188,0x18a,0x18b,0x18d,0x18f,0x191,
0x193,0x195,0x197,0x199,0x19a,0x19c,0x19e,0x1a0,
0x1a2,0x1a4,0x1a6,0x1a8,0x1aa,0x1ac,0x1ae,0x1af,
0x1b1,0x1b3,0x1b5,0x1b7,0x1b9,0x1bb,0x1bd,0x1bf,
0x1c1,0x1c3,0x1c5,0x1c7,0x1c9,0x1cb,0x1cd,0x1cf,
0x1d1,0x1d3,0x1d5,0x1d7,0x1d9,0x1db,0x1dd,0x1df,
0x1e1,0x1e3,0x1e5,0x1e7,0x1e9,0x1eb,0x1ed,0x1ef,
0x1f1,0x1f3,0x1f5,0x1f7,0x1f9,0x1fb,0x1fd,0x200,
0x202,0x204,0x206,0x208,0x20a,0x20c,0x20e,0x210,
0x212,0x215,0x217,0x219,0x21b,0x21d,0x21f,0x221,
0x223,0x226,0x228,0x22a,0x22c,0x22e,0x230,0x232,
0x235,0x237,0x239,0x23b,0x23d,0x23f,0x242,0x244,
0x246,0x248,0x24a,0x24d,0x24f,0x251,0x253,0x255,
0x258,0x25a,0x25c,0x25e,0x261,0x263,0x265,0x267,
0x26a,0x26c,0x26e,0x270,0x273,0x275,0x277,0x279,
0x27c,0x27e,0x280,0x283,0x285,0x287,0x289,0x28c,
0x28e,0x290,0x293,0x295,0x297,0x29a,0x29c,0x29e,
0x2a0,0x2a3,0x2a5,0x2a7,0x2aa,0x2ac,0x2af,0x2b1,
0x2b3,0x2b6,0x2b8,0x2ba,0x2bd,0x2bf,0x2c1,0x2c4,
0x2c6,0x2c9,0x2cb,0x2cd,0x2d0,0x2d2,0x2d4,0x2d7,
0x2d9,0x2dc,0x2de,0x2e0,0x2e3,0x2e5,0x2e8,0x2ea,
0x2ed,0x2ef,0x2f1,0x2f4,0x2f6,0x2f9,0x2fb,0x2fe,
0x300,0x303,0x305,0x307,0x30a,0x30c,0x30f,0x311,
0x314,0x316,0x319,0x31b,0x31e,0x320,0x323,0x325,
0x328,0x32a,0x32d,0x32f,0x332,0x334,0x337,0x339,
0x33c,0x33e,0x341,0x343,0x346,0x348,0x34b,0x34e,
0x350,0x353,0x355,0x358,0x35a,0x35d,0x35f,0x362,
0x365,0x367,0x36a,0x36c,0x36f,0x371,0x374,0x377,
0x379,0x37c,0x37e,0x381,0x384,0x386,0x389,0x38b,
0x38e,0x391,0x393,0x396,0x398,0x39b,0x39e,0x3a0,
0x3a3,0x3a6,0x3a8,0x3ab,0x3ad,0x3b0,0x3b3,0x3b5,
0x3b8,0x3bb,0x3bd,0x3c0,0x3c3,0x3c5,0x3c8,0x3cb,
0x3cd,0x3d0,0x3d3,0x3d5,0x3d8,0x3db,0x3dd,0x3e0,
0x3e3,0x3e6,0x3e8,0x3eb,0x3ee,0x3f0,0x3f3,0x3f6,
0x3f9,0x3fb,0x3fe,0x401,0x403,0x406,0x409,0x40c,
0x40e,0x411,0x414,0x416,0x419,0x41c,0x41f,0x421,
0x424,0x427,0x42a,0x42c,0x42f,0x432,0x435,0x438,
0x43a,0x43d,0x440,0x443,0x445,0x448,0x44b,0x44e,
0x451,0x453,0x456,0x459,0x45c,0x45f,0x461,0x464,
0x467,0x46a,0x46d,0x46f,0x472,0x475,0x478,0x47b,
0x47d,0x480,0x483,0x486,0x489,0x48c,0x48e,0x491,
0x494,0x497,0x49a,0x49d,0x49f,0x4a2,0x4a5,0x4a8,
0x4ab,0x4ae,0x4b1,0x4b3,0x4b6,0x4b9,0x4bc,0x4bf,
0x4c2,0x4c5,0x4c8,0x4ca,0x4cd,0x4d0,0x4d3,0x4d6,
0x4d9,0x4dc,0x4df,0x4e1,0x4e4,0x4e7,0x4ea,0x4ed,
0x4f0,0x4f3,0x4f6,0x4f9,0x4fc,0x4fe,0x501,0x504,
0x507,0x50a,0x50d,0x510,0x513,0x516,0x519,0x51c,
0x51f,0x522,0x524,0x527,0x52a,0x52d,0x530,0x533,
0x536,0x539,0x53c,0x53f,0x542,0x545,0x548,0x54b,
0x54e,0x551,0x554,0x557,0x55a,0x55d,0x55f,0x562,
0x565,0x568,0x56b,0x56e,0x571,0x574,0x577,0x57a,
0x57d,0x580,0x583,0x586,0x589,0x58c,0x58f,0x592,
0x595,0x598,0x59b,0x59e,0x5a1,0x5a4,0x5a7,0x5aa,
0x5ad,0x5b0,0x5b3,0x5b6,0x5b9,0x5bc,0x5bf,0x5c2,
0x5c5,0x5c8,0x5cb,0x5ce,0x5d1,0x5d4,0x5d7,0x5da,
0x5dd,0x5e0,0x5e3,0x5e6,0x5ea,0x5ed,0x5f0,0x5f3,
0x5f6,0x5f9,0x5fc,0x5ff,0x602,0x605,0x608,0x60b,
0x60e,0x611,0x614,0x617,0x61a,0x61d,0x620,0x623,
0x626,0x629,0x62d,0x630,0x633,0x636,0x639,0x63c,
0x63f,0x642,0x645,0x648,0x64b,0x64e,0x651,0x654,
0x657,0x65b,0x65e,0x661,0x664,0x667,0x66a,0x66d,
0x670,0x673,0x676,0x679,0x67c,0x67f,0x683,0x686,
0x689,0x68c,0x68f,0x692,0x695,0x698,0x69b,0x69e,
0x6a1,0x6a5,0x6a8,0x6ab,0x6ae,0x6b1,0x6b4,0x6b7,
0x6ba,0x6bd,0x6c0,0x6c4,0x6c7,0x6ca,0x6cd,0x6d0,
0x6d3,0x6d6,0x6d9,0x6dc,0x6e0,0x6e3,0x6e6,0x6e9,
0x6ec,0x6ef,0x6f2,0x6f5,0x6f8,0x6fc,0x6ff,0x702,
0x705,0x708,0x70b,0x70e,0x711,0x714,0x718,0x71b,
0x71e,0x721,0x724,0x727,0x72a,0x72d,0x731,0x734,
0x737,0x73a,0x73d,0x740,0x743,0x746,0x74a,0x74d,
0x750,0x753,0x756,0x759,0x75c,0x75f,0x763,0x766,
0x769,0x76c,0x76f,0x772,0x775,0x779,0x77c,0x77f,
0x782,0x785,0x788,0x78b,0x78e,0x792,0x795,0x798,
0x79b,0x79e,0x7a1,0x7a4,0x7a8,0x7ab,0x7ae,0x7b1,
0x7b4,0x7b7,0x7ba,0x7be,0x7c1,0x7c4,0x7c7,0x7ca,
0x7cd,0x7d0,0x7d4,0x7d7,0x7da,0x7dd,0x7e0,0x7e3,
0x7e6,0x7ea,0x7ed,0x7f0,0x7f3,0x7f6,0x7f9,0x7fc,
0x800,0x803,0x806,0x809,0x80c,0x80f,0x812,0x815,
0x819,0x81c,0x81f,0x822,0x825,0x828,0x82b,0x82f,
0x832,0x835,0x838,0x83b,0x83e,0x841,0x845,0x848,
0x84b,0x84e,0x851,0x854,0x857,0x85b,0x85e,0x861,
0x864,0x867,0x86a,0x86d,0x871,0x874,0x877,0x87a,
0x87d,0x880,0x883,0x886,0x88a,0x88d,0x890,0x893,
0x896,0x899,0x89c,0x8a0,0x8a3,0x8a6,0x8a9,0x8ac,
0x8af,0x8b2,0x8b5,0x8b9,0x8bc,0x8bf,0x8c2,0x8c5,
0x8c8,0x8cb,0x8ce,0x8d2,0x8d5,0x8d8,0x8db,0x8de,
0x8e1,0x8e4,0x8e7,0x8eb,0x8ee,0x8f1,0x8f4,0x8f7,
0x8fa,0x8fd,0x900,0x903,0x907,0x90a,0x90d,0x910,
0x913,0x916,0x919,0x91c,0x91f,0x923,0x926,0x929,
0x92c,0x92f,0x932,0x935,0x938,0x93b,0x93f,0x942,
0x945,0x948,0x94b,0x94e,0x951,0x954,0x957,0x95a,
0x95e,0x961,0x964,0x967,0x96a,0x96d,0x970,0x973,
0x976,0x979,0x97c,0x980,0x983,0x986,0x989,0x98c,
0x98f,0x992,0x995,0x998,0x99b,0x99e,0x9a1,0x9a4,
0x9a8,0x9ab,0x9ae,0x9b1,0x9b4,0x9b7,0x9ba,0x9bd,
0x9c0,0x9c3,0x9c6,0x9c9,0x9cc,0x9cf,0x9d2,0x9d6,
0x9d9,0x9dc,0x9df,0x9e2,0x9e5,0x9e8,0x9eb,0x9ee,
0x9f1,0x9f4,0x9f7,0x9fa,0x9fd,0xa00,0xa03,0xa06,
0xa09,0xa0c,0xa0f,0xa12,0xa15,0xa19,0xa1c,0xa1f,
0xa22,0xa25,0xa28,0xa2b,0xa2e,0xa31,0xa34,0xa37,
0xa3a,0xa3d,0xa40,0xa43,0xa46,0xa49,0xa4c,0xa4f,
0xa52,0xa55,0xa58,0xa5b,0xa5e,0xa61,0xa64,0xa67,
0xa6a,0xa6d,0xa70,0xa73,0xa76,0xa79,0xa7c,0xa7f,
0xa82,0xa85,0xa88,0xa8b,0xa8e,0xa91,0xa94,0xa97,
0xa9a,0xa9d,0xaa0,0xaa2,0xaa5,0xaa8,0xaab,0xaae,
0xab1,0xab4,0xab7,0xaba,0xabd,0xac0,0xac3,0xac6,
0xac9,0xacc,0xacf,0xad2,0xad5,0xad8,0xadb,0xadd,
0xae0,0xae3,0xae6,0xae9,0xaec,0xaef,0xaf2,0xaf5,
0xaf8,0xafb,0xafe,0xb01,0xb03,0xb06,0xb09,0xb0c,
0xb0f,0xb12,0xb15,0xb18,0xb1b,0xb1e,0xb20,0xb23,
0xb26,0xb29,0xb2c,0xb2f,0xb32,0xb35,0xb37,0xb3a,
0xb3d,0xb40,0xb43,0xb46,0xb49,0xb4c,0xb4e,0xb51,
0xb54,0xb57,0xb5a,0xb5d,0xb60,0xb62,0xb65,0xb68,
0xb6b,0xb6e,0xb71,0xb73,0xb76,0xb79,0xb7c,0xb7f,
0xb82,0xb84,0xb87,0xb8a,0xb8d,0xb90,0xb92,0xb95,
0xb98,0xb9b,0xb9e,0xba0,0xba3,0xba6,0xba9,0xbac,
0xbae,0xbb1,0xbb4,0xbb7,0xbba,0xbbc,0xbbf,0xbc2,
0xbc5,0xbc7,0xbca,0xbcd,0xbd0,0xbd3,0xbd5,0xbd8,
0xbdb,0xbde,0xbe0,0xbe3,0xbe6,0xbe9,0xbeb,0xbee,
0xbf1,0xbf3,0xbf6,0xbf9,0xbfc,0xbfe,0xc01,0xc04,
0xc06,0xc09,0xc0c,0xc0f,0xc11,0xc14,0xc17,0xc19,
0xc1c,0xc1f,0xc22,0xc24,0xc27,0xc2a,0xc2c,0xc2f,
0xc32,0xc34,0xc37,0xc3a,0xc3c,0xc3f,0xc42,0xc44,
0xc47,0xc4a,0xc4c,0xc4f,0xc52,0xc54,0xc57,0xc59,
0xc5c,0xc5f,0xc61,0xc64,0xc67,0xc69,0xc6c,0xc6e,
0xc71,0xc74,0xc76,0xc79,0xc7b,0xc7e,0xc81,0xc83,
0xc86,0xc88,0xc8b,0xc8e,0xc90,0xc93,0xc95,0xc98,
0xc9a,0xc9d,0xca0,0xca2,0xca5,0xca7,0xcaa,0xcac,
0xcaf,0xcb1,0xcb4,0xcb7,0xcb9,0xcbc,0xcbe,0xcc1,
0xcc3,0xcc6,0xcc8,0xccb,0xccd,0xcd0,0xcd2,0xcd5,
0xcd7,0xcda,0xcdc,0xcdf,0xce1,0xce4,0xce6,0xce9,
0xceb,0xcee,0xcf0,0xcf3,0xcf5,0xcf8,0xcfa,0xcfc,
0xcff,0xd01,0xd04,0xd06,0xd09,0xd0b,0xd0e,0xd10,
0xd12,0xd15,0xd17,0xd1a,0xd1c,0xd1f,0xd21,0xd23,
0xd26,0xd28,0xd2b,0xd2d,0xd2f,0xd32,0xd34,0xd36,
0xd39,0xd3b,0xd3e,0xd40,0xd42,0xd45,0xd47,0xd49,
0xd4c,0xd4e,0xd50,0xd53,0xd55,0xd58,0xd5a,0xd5c,
0xd5f,0xd61,0xd63,0xd65,0xd68,0xd6a,0xd6c,0xd6f,
0xd71,0xd73,0xd76,0xd78,0xd7a,0xd7c,0xd7f,0xd81,
0xd83,0xd86,0xd88,0xd8a,0xd8c,0xd8f,0xd91,0xd93,
0xd95,0xd98,0xd9a,0xd9c,0xd9e,0xda1,0xda3,0xda5,
0xda7,0xdaa,0xdac,0xdae,0xdb0,0xdb2,0xdb5,0xdb7,
0xdb9,0xdbb,0xdbd,0xdc0,0xdc2,0xdc4,0xdc6,0xdc8,
0xdca,0xdcd,0xdcf,0xdd1,0xdd3,0xdd5,0xdd7,0xdd9,
0xddc,0xdde,0xde0,0xde2,0xde4,0xde6,0xde8,0xdea,
0xded,0xdef,0xdf1,0xdf3,0xdf5,0xdf7,0xdf9,0xdfb,
0xdfd,0xdff,0xe02,0xe04,0xe06,0xe08,0xe0a,0xe0c,
0xe0e,0xe10,0xe12,0xe14,0xe16,0xe18,0xe1a,0xe1c,
0xe1e,0xe20,0xe22,0xe24,0xe26,0xe28,0xe2a,0xe2c,
0xe2e,0xe30,0xe32,0xe34,0xe36,0xe38,0xe3a,0xe3c,
0xe3e,0xe40,0xe42,0xe44,0xe46,0xe48,0xe4a,0xe4c,
0xe4e,0xe50,0xe51,0xe53,0xe55,0xe57,0xe59,0xe5b,
0xe5d,0xe5f,0xe61,0xe63,0xe65,0xe66,0xe68,0xe6a,
0xe6c,0xe6e,0xe70,0xe72,0xe74,0xe75,0xe77,0xe79,
0xe7b,0xe7d,0xe7f,0xe80,0xe82,0xe84,0xe86,0xe88,
0xe8a,0xe8b,0xe8d,0xe8f,0xe91,0xe92,0xe94,0xe96,
0xe98,0xe9a,0xe9b,0xe9d,0xe9f,0xea1,0xea2,0xea4,
0xea6,0xea8,0xea9,0xeab,0xead,0xeaf,0xeb0,0xeb2,
0xeb4,0xeb5,0xeb7,0xeb9,0xebb,0xebc,0xebe,0xec0,
0xec1,0xec3,0xec5,0xec6,0xec8,0xeca,0xecb,0xecd,
0xecf,0xed0,0xed2,0xed4,0xed5,0xed7,0xed8,0xeda,
0xedc,0xedd,0xedf,0xee1,0xee2,0xee4,0xee5,0xee7,
0xee8,0xeea,0xeec,0xeed,0xeef,0xef0,0xef2,0xef3,
0xef5,0xef7,0xef8,0xefa,0xefb,0xefd,0xefe,0xf00,
0xf01,0xf03,0xf04,0xf06,0xf07,0xf09,0xf0a,0xf0c,
0xf0d,0xf0f,0xf10,0xf12,0xf13,0xf15,0xf16,0xf17,
0xf19,0xf1a,0xf1c,0xf1d,0xf1f,0xf20,0xf22,0xf23,
0xf24,0xf26,0xf27,0xf29,0xf2a,0xf2b,0xf2d,0xf2e,
0xf30,0xf31,0xf32,0xf34,0xf35,0xf36,0xf38,0xf39,
0xf3a,0xf3c,0xf3d,0xf3e,0xf40,0xf41,0xf42,0xf44,
0xf45,0xf46,0xf48,0xf49,0xf4a,0xf4c,0xf4d,0xf4e,
0xf4f,0xf51,0xf52,0xf53,0xf54,0xf56,0xf57,0xf58,
0xf59,0xf5b,0xf5c,0xf5d,0xf5e,0xf60,0xf61,0xf62,
0xf63,0xf64,0xf66,0xf67,0xf68,0xf69,0xf6a,0xf6b,
0xf6d,0xf6e,0xf6f,0xf70,0xf71,0xf72,0xf74,0xf75,
0xf76,0xf77,0xf78,0xf79,0xf7a,0xf7b,0xf7d,0xf7e,
0xf7f,0xf80,0xf81,0xf82,0xf83,0xf84,0xf85,0xf86,
0xf87,0xf88,0xf89,0xf8a,0xf8c,0xf8d,0xf8e,0xf8f,
0xf90,0xf91,0xf92,0xf93,0xf94,0xf95,0xf96,0xf97,
0xf98,0xf99,0xf9a,0xf9b,0xf9c,0xf9d,0xf9d,0xf9e,
0xf9f,0xfa0,0xfa1,0xfa2,0xfa3,0xfa4,0xfa5,0xfa6,
0xfa7,0xfa8,0xfa9,0xfaa,0xfaa,0xfab,0xfac,0xfad,
0xfae,0xfaf,0xfb0,0xfb1,0xfb1,0xfb2,0xfb3,0xfb4,
0xfb5,0xfb6,0xfb6,0xfb7,0xfb8,0xfb9,0xfba,0xfbb,
0xfbb,0xfbc,0xfbd,0xfbe,0xfbf,0xfbf,0xfc0,0xfc1,
0xfc2,0xfc2,0xfc3,0xfc4,0xfc5,0xfc5,0xfc6,0xfc7,
0xfc8,0xfc8,0xfc9,0xfca,0xfca,0xfcb,0xfcc,0xfcd,
0xfcd,0xfce,0xfcf,0xfcf,0xfd0,0xfd1,0xfd1,0xfd2,
0xfd3,0xfd3,0xfd4,0xfd5,0xfd5,0xfd6,0xfd6,0xfd7,
0xfd8,0xfd8,0xfd9,0xfd9,0xfda,0xfdb,0xfdb,0xfdc,
0xfdc,0xfdd,0xfde,0xfde,0xfdf,0xfdf,0xfe0,0xfe0,
0xfe1,0xfe1,0xfe2,0xfe2,0xfe3,0xfe3,0xfe4,0xfe4,
0xfe5,0xfe5,0xfe6,0xfe6,0xfe7,0xfe7,0xfe8,0xfe8,
0xfe9,0xfe9,0xfea,0xfea,0xfeb,0xfeb,0xfec,0xfec,
0xfec,0xfed,0xfed,0xfee,0xfee,0xfee,0xfef,0xfef,
0xff0,0xff0,0xff0,0xff1,0xff1,0xff1,0xff2,0xff2,
0xff3,0xff3,0xff3,0xff4,0xff4,0xff4,0xff5,0xff5,
0xff5,0xff5,0xff6,0xff6,0xff6,0xff7,0xff7,0xff7,
0xff7,0xff8,0xff8,0xff8,0xff8,0xff9,0xff9,0xff9,
0xff9,0xffa,0xffa,0xffa,0xffa,0xffb,0xffb,0xffb,
0xffb,0xffb,0xffc,0xffc,0xffc,0xffc,0xffc,0xffc,
0xffd,0xffd,0xffd,0xffd,0xffd,0xffd,0xffd,0xffd,
0xffe,0xffe,0xffe,0xffe,0xffe,0xffe,0xffe,0xffe,
0xffe,0xffe,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,
0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff
};