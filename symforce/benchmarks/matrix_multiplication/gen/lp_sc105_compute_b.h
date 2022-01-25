// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>
#include <Eigen/Sparse>

namespace sym {

/**
 * This function was autogenerated. Do not modify by hand.
 *
 * Args:
 *     x0: Scalar
 *     x1: Scalar
 *
 * Outputs:
 *     result: Matrix105_163
 *
 */
template <typename Scalar>
Eigen::SparseMatrix<Scalar> LpSc105ComputeB(const Scalar x0, const Scalar x1) {
  // Total ops: 161

  // Input arrays

  // Intermediate terms (45)
  const Scalar _tmp0 = 2 * x0;
  const Scalar _tmp1 = -_tmp0;
  const Scalar _tmp2 = 2 * x1;
  const Scalar _tmp3 = _tmp2 - 2;
  const Scalar _tmp4 = std::pow(x0, Scalar(2));
  const Scalar _tmp5 = std::pow(x1, Scalar(2));
  const Scalar _tmp6 = -_tmp5;
  const Scalar _tmp7 = x1 + 4;
  const Scalar _tmp8 = x1 + 1;
  const Scalar _tmp9 = -_tmp8;
  const Scalar _tmp10 = x0 - 2;
  const Scalar _tmp11 = x0 + 1;
  const Scalar _tmp12 = x1 - 2;
  const Scalar _tmp13 = -x0;
  const Scalar _tmp14 = x0 + 2;
  const Scalar _tmp15 = -_tmp14;
  const Scalar _tmp16 = Scalar(1.0) / (x0);
  const Scalar _tmp17 = _tmp0 + 1;
  const Scalar _tmp18 = x0 - 1;
  const Scalar _tmp19 = 4 * x1;
  const Scalar _tmp20 = -_tmp19;
  const Scalar _tmp21 = -_tmp12;
  const Scalar _tmp22 = -x1;
  const Scalar _tmp23 = _tmp22 + x0;
  const Scalar _tmp24 = -_tmp23;
  const Scalar _tmp25 = x1 + 2;
  const Scalar _tmp26 = x1 - 1;
  const Scalar _tmp27 = 3 * x0;
  const Scalar _tmp28 = -_tmp4;
  const Scalar _tmp29 = 2 * _tmp4;
  const Scalar _tmp30 = -_tmp2;
  const Scalar _tmp31 = -_tmp18;
  const Scalar _tmp32 = -_tmp25;
  const Scalar _tmp33 = x1 + 3;
  const Scalar _tmp34 = 4 * x0;
  const Scalar _tmp35 = _tmp4 * x1;
  const Scalar _tmp36 = _tmp16 * x1;
  const Scalar _tmp37 = x0 - 3;
  const Scalar _tmp38 = -_tmp26;
  const Scalar _tmp39 = Scalar(1.0) / (x1);
  const Scalar _tmp40 = x0 * x1;
  const Scalar _tmp41 = -_tmp40;
  const Scalar _tmp42 = -2 * _tmp5;
  const Scalar _tmp43 = 2 * _tmp16;
  const Scalar _tmp44 = -_tmp3;

  // Output terms (1)
  static constexpr int kRows_result = 105;
  static constexpr int kCols_result = 163;
  static constexpr int kNumNonZero_result = 328;
  static constexpr int kColPtrs_result[] = {
      0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,  15,  16,  17,  18,
      19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,
      38,  39,  40,  41,  41,  42,  43,  44,  45,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,
      55,  56,  57,  58,  60,  63,  65,  67,  70,  73,  76,  79,  81,  83,  84,  87,  90,  93,  96,
      99,  102, 105, 108, 110, 112, 114, 117, 120, 123, 126, 129, 132, 134, 137, 139, 141, 143, 146,
      149, 152, 155, 158, 161, 164, 167, 169, 171, 173, 176, 179, 181, 184, 187, 190, 193, 196, 198,
      200, 202, 205, 208, 211, 214, 217, 220, 223, 225, 227, 228, 230, 233, 236, 239, 242, 245, 248,
      251, 254, 256, 258, 260, 263, 266, 269, 272, 275, 277, 280, 283, 285, 287, 289, 292, 295, 298,
      301, 302, 304, 306, 308, 310, 312, 314, 318, 321, 326, 328};
  static constexpr int kRowIndices_result[] = {
      0,   1,   2,  7,   8,   9,   10,  11, 12, 18, 19, 20, 21, 22,  23,  29,  30,  31,  32, 33,
      34,  40,  41, 42,  43,  44,  45,  51, 52, 53, 54, 55, 56, 62,  63,  64,  65,  66,  67, 73,
      74,  76,  77, 78,  84,  86,  87,  88, 89, 95, 96, 97, 98, 99,  100, 102, 103, 104, 0,  1,
      0,   1,   5,  1,   6,   3,   13,  3,  12, 14, 4,  7,  15, 5,   8,   16,  6,   9,   17, 7,
      10,  8,   11, 9,   10,  11,  15,  10, 11, 16, 10, 11, 17, 13,  14,  24,  14,  23,  25, 15,
      18,  26,  16, 19,  27,  17,  20,  28, 18, 21, 19, 22, 20, 23,  21,  22,  26,  21,  22, 27,
      21,  22,  28, 24,  25,  35,  25,  34, 36, 26, 29, 37, 27, 30,  28,  31,  39,  29,  32, 30,
      33,  31,  34, 32,  33,  37,  32,  33, 38, 32, 33, 39, 35, 36,  46,  36,  45,  47,  37, 40,
      48,  38,  41, 49,  39,  42,  50,  40, 43, 41, 44, 42, 45, 43,  44,  48,  43,  44,  49, 44,
      50,  46,  47, 57,  47,  56,  58,  48, 51, 59, 49, 52, 60, 50,  53,  61,  51,  54,  52, 55,
      53,  56,  54, 55,  59,  54,  55,  60, 54, 55, 61, 57, 58, 68,  58,  67,  69,  59,  62, 70,
      60,  63,  71, 64,  72,  62,  65,  63, 64, 67, 65, 66, 70, 65,  66,  71,  65,  66,  72, 68,
      69,  79,  69, 78,  80,  70,  73,  81, 71, 74, 82, 72, 75, 83,  73,  76,  74,  77,  75, 78,
      76,  77,  81, 76,  77,  82,  76,  77, 83, 79, 80, 90, 80, 89,  91,  84,  92,  82,  85, 93,
      83,  86,  94, 84,  87,  85,  88,  86, 89, 87, 88, 92, 87, 88,  93,  87,  88,  94,  90, 91,
      101, 100, 92, 95,  93,  96,  94,  97, 95, 98, 96, 99, 97, 100, 98,  99,  102, 103, 98, 102,
      103, 98,  99, 102, 103, 104, 101, 104};
  Scalar result_empty_value_ptr[328];
  Eigen::SparseMatrix<Scalar> result = Eigen::Map<const Eigen::SparseMatrix<Scalar>>(
      kRows_result, kCols_result, kNumNonZero_result, kColPtrs_result, kRowIndices_result,
      result_empty_value_ptr);
  Scalar* result_value_ptr = result.valuePtr();

  result_value_ptr[0] = -2;
  result_value_ptr[1] = _tmp1;
  result_value_ptr[2] = Scalar(-1.0);
  result_value_ptr[3] = Scalar(-1.0);
  result_value_ptr[4] = -Scalar(0.5) * x0;
  result_value_ptr[5] = _tmp0;
  result_value_ptr[6] = _tmp3;
  result_value_ptr[7] = 3;
  result_value_ptr[8] = 2;
  result_value_ptr[9] = 4;
  result_value_ptr[10] = 2;
  result_value_ptr[11] = _tmp0 - 4;
  result_value_ptr[12] = _tmp4 - 2;
  result_value_ptr[13] = x0;
  result_value_ptr[14] = _tmp6;
  result_value_ptr[15] = _tmp7;
  result_value_ptr[16] = _tmp2;
  result_value_ptr[17] = x0;
  result_value_ptr[18] = _tmp9;
  result_value_ptr[19] = -_tmp10;
  result_value_ptr[20] = _tmp11 * x1;
  result_value_ptr[21] = 2;
  result_value_ptr[22] = x1;
  result_value_ptr[23] = _tmp7;
  result_value_ptr[24] = _tmp2;
  result_value_ptr[25] = _tmp12;
  result_value_ptr[26] = -6;
  result_value_ptr[27] = _tmp13;
  result_value_ptr[28] = _tmp2 - 1;
  result_value_ptr[29] = _tmp15;
  result_value_ptr[30] = _tmp15;
  result_value_ptr[31] = -3;
  result_value_ptr[32] = -1;
  result_value_ptr[33] = _tmp0;
  result_value_ptr[34] = -_tmp16;
  result_value_ptr[35] = -1;
  result_value_ptr[36] = _tmp17;
  result_value_ptr[37] = _tmp17;
  result_value_ptr[38] = -1;
  result_value_ptr[39] = _tmp18 * x0;
  result_value_ptr[40] = _tmp0;
  result_value_ptr[41] = _tmp20;
  result_value_ptr[42] = 2;
  result_value_ptr[43] = _tmp21;
  result_value_ptr[44] = 4;
  result_value_ptr[45] = _tmp24;
  result_value_ptr[46] = _tmp20;
  result_value_ptr[47] = -2;
  result_value_ptr[48] = _tmp25;
  result_value_ptr[49] = 2;
  result_value_ptr[50] = _tmp26;
  result_value_ptr[51] = _tmp13;
  result_value_ptr[52] = 4;
  result_value_ptr[53] = -3;
  result_value_ptr[54] = Scalar(2.0);
  result_value_ptr[55] = -2;
  result_value_ptr[56] = _tmp13;
  result_value_ptr[57] = 1;
  result_value_ptr[58] = _tmp2 + 1;
  result_value_ptr[59] = _tmp27;
  result_value_ptr[60] = x0;
  result_value_ptr[61] = x1;
  result_value_ptr[62] = _tmp10;
  result_value_ptr[63] = 2;
  result_value_ptr[64] = _tmp22;
  result_value_ptr[65] = _tmp11;
  result_value_ptr[66] = _tmp18;
  result_value_ptr[67] = _tmp8 + x0;
  result_value_ptr[68] = _tmp11;
  result_value_ptr[69] = -1;
  result_value_ptr[70] = _tmp23;
  result_value_ptr[71] = 3;
  result_value_ptr[72] = _tmp2 + 4;
  result_value_ptr[73] = _tmp25 * x1;
  result_value_ptr[74] = _tmp9;
  result_value_ptr[75] = x0;
  result_value_ptr[76] = _tmp28;
  result_value_ptr[77] = _tmp29;
  result_value_ptr[78] = _tmp30;
  result_value_ptr[79] = x1;
  result_value_ptr[80] = -1;
  result_value_ptr[81] = -1;
  result_value_ptr[82] = 2;
  result_value_ptr[83] = x1;
  result_value_ptr[84] = _tmp28;
  result_value_ptr[85] = _tmp18 + x1;
  result_value_ptr[86] = _tmp22;
  result_value_ptr[87] = x1;
  result_value_ptr[88] = _tmp31;
  result_value_ptr[89] = -1;
  result_value_ptr[90] = 4;
  result_value_ptr[91] = x0;
  result_value_ptr[92] = Scalar(-2.0);
  result_value_ptr[93] = _tmp32;
  result_value_ptr[94] = _tmp26;
  result_value_ptr[95] = _tmp33;
  result_value_ptr[96] = -_tmp34;
  result_value_ptr[97] = _tmp22;
  result_value_ptr[98] = 1;
  result_value_ptr[99] = _tmp1;
  result_value_ptr[100] = _tmp35;
  result_value_ptr[101] = _tmp2 + 2;
  result_value_ptr[102] = -2;
  result_value_ptr[103] = _tmp10;
  result_value_ptr[104] = -3;
  result_value_ptr[105] = _tmp36 + 2;
  result_value_ptr[106] = -_tmp16 * _tmp26;
  result_value_ptr[107] = x1;
  result_value_ptr[108] = _tmp37;
  result_value_ptr[109] = _tmp38;
  result_value_ptr[110] = -_tmp29;
  result_value_ptr[111] = -2;
  result_value_ptr[112] = 1;
  result_value_ptr[113] = x1;
  result_value_ptr[114] = _tmp1;
  result_value_ptr[115] = Scalar(-1.5);
  result_value_ptr[116] = x1;
  result_value_ptr[117] = _tmp10;
  result_value_ptr[118] = 3 * x1;
  result_value_ptr[119] = _tmp38;
  result_value_ptr[120] = -2;
  result_value_ptr[121] = x1;
  result_value_ptr[122] = -3;
  result_value_ptr[123] = -2;
  result_value_ptr[124] = _tmp39;
  result_value_ptr[125] = _tmp0 + 2;
  result_value_ptr[126] = _tmp0;
  result_value_ptr[127] = _tmp2;
  result_value_ptr[128] = 1;
  result_value_ptr[129] = -2;
  result_value_ptr[130] = -2;
  result_value_ptr[131] = -1;
  result_value_ptr[132] = -4;
  result_value_ptr[133] = _tmp32;
  result_value_ptr[134] = 1;
  result_value_ptr[135] = -x0 - x1;
  result_value_ptr[136] = 1;
  result_value_ptr[137] = (Scalar(1) / Scalar(2)) * _tmp36;
  result_value_ptr[138] = -2;
  result_value_ptr[139] = -1;
  result_value_ptr[140] = -Scalar(1) / Scalar(2) * x1;
  result_value_ptr[141] = -1;
  result_value_ptr[142] = -1;
  result_value_ptr[143] = 2;
  result_value_ptr[144] = _tmp20;
  result_value_ptr[145] = -2;
  result_value_ptr[146] = _tmp33;
  result_value_ptr[147] = -3;
  result_value_ptr[148] = _tmp9;
  result_value_ptr[149] = x0;
  result_value_ptr[150] = _tmp21;
  result_value_ptr[151] = _tmp37;
  result_value_ptr[152] = _tmp30;
  result_value_ptr[153] = x0;
  result_value_ptr[154] = -2;
  result_value_ptr[155] = x1;
  result_value_ptr[156] = _tmp12;
  result_value_ptr[157] = -2;
  result_value_ptr[158] = 1;
  result_value_ptr[159] = _tmp2;
  result_value_ptr[160] = _tmp37;
  result_value_ptr[161] = -1;
  result_value_ptr[162] = _tmp1;
  result_value_ptr[163] = _tmp41;
  result_value_ptr[164] = _tmp13;
  result_value_ptr[165] = _tmp31;
  result_value_ptr[166] = 4;
  result_value_ptr[167] = 4;
  result_value_ptr[168] = -2;
  result_value_ptr[169] = -2;
  result_value_ptr[170] = -2;
  result_value_ptr[171] = -1;
  result_value_ptr[172] = x0;
  result_value_ptr[173] = _tmp32;
  result_value_ptr[174] = _tmp0;
  result_value_ptr[175] = 1;
  result_value_ptr[176] = -2 * _tmp39 + x0;
  result_value_ptr[177] = -5;
  result_value_ptr[178] = x0;
  result_value_ptr[179] = _tmp18;
  result_value_ptr[180] = _tmp14;
  result_value_ptr[181] = 1;
  result_value_ptr[182] = _tmp12;
  result_value_ptr[183] = x0;
  result_value_ptr[184] = Scalar(-3.0);
  result_value_ptr[185] = _tmp0;
  result_value_ptr[186] = 3;
  result_value_ptr[187] = x1;
  result_value_ptr[188] = _tmp20;
  result_value_ptr[189] = _tmp0 + 4;
  result_value_ptr[190] = 2;
  result_value_ptr[191] = x0;
  result_value_ptr[192] = 2;
  result_value_ptr[193] = -2;
  result_value_ptr[194] = -2;
  result_value_ptr[195] = -1;
  result_value_ptr[196] = _tmp18;
  result_value_ptr[197] = Scalar(1.0);
  result_value_ptr[198] = _tmp22;
  result_value_ptr[199] = x1 - 3;
  result_value_ptr[200] = -2;
  result_value_ptr[201] = -1;
  result_value_ptr[202] = -1;
  result_value_ptr[203] = 2;
  result_value_ptr[204] = x0;
  result_value_ptr[205] = x1;
  result_value_ptr[206] = _tmp6;
  result_value_ptr[207] = _tmp8;
  result_value_ptr[208] = _tmp42;
  result_value_ptr[209] = -2;
  result_value_ptr[210] = x0;
  result_value_ptr[211] = 4;
  result_value_ptr[212] = _tmp43;
  result_value_ptr[213] = -2;
  result_value_ptr[214] = _tmp24;
  result_value_ptr[215] = _tmp21;
  result_value_ptr[216] = _tmp26;
  result_value_ptr[217] = -2;
  result_value_ptr[218] = _tmp41;
  result_value_ptr[219] = _tmp0;
  result_value_ptr[220] = -1;
  result_value_ptr[221] = -2;
  result_value_ptr[222] = _tmp31;
  result_value_ptr[223] = -1;
  result_value_ptr[224] = 4;
  result_value_ptr[225] = x1;
  result_value_ptr[226] = 3;
  result_value_ptr[227] = 1;
  result_value_ptr[228] = _tmp20;
  result_value_ptr[229] = 4;
  result_value_ptr[230] = _tmp1;
  result_value_ptr[231] = _tmp10;
  result_value_ptr[232] = -2;
  result_value_ptr[233] = _tmp30;
  result_value_ptr[234] = Scalar(0.5);
  result_value_ptr[235] = -2;
  result_value_ptr[236] = 2;
  result_value_ptr[237] = 1;
  result_value_ptr[238] = -1;
  result_value_ptr[239] = _tmp19;
  result_value_ptr[240] = _tmp42;
  result_value_ptr[241] = _tmp30;
  result_value_ptr[242] = 2;
  result_value_ptr[243] = x1;
  result_value_ptr[244] = _tmp44;
  result_value_ptr[245] = x0;
  result_value_ptr[246] = x0;
  result_value_ptr[247] = _tmp28;
  result_value_ptr[248] = 2;
  result_value_ptr[249] = -4;
  result_value_ptr[250] = 4;
  result_value_ptr[251] = -2;
  result_value_ptr[252] = -3;
  result_value_ptr[253] = _tmp26;
  result_value_ptr[254] = -_tmp27;
  result_value_ptr[255] = _tmp26;
  result_value_ptr[256] = -2;
  result_value_ptr[257] = -1;
  result_value_ptr[258] = 1;
  result_value_ptr[259] = 2;
  result_value_ptr[260] = -_tmp43;
  result_value_ptr[261] = -_tmp22 - _tmp5;
  result_value_ptr[262] = 2 - _tmp0;
  result_value_ptr[263] = -4;
  result_value_ptr[264] = (Scalar(1) / Scalar(2)) * _tmp39;
  result_value_ptr[265] = _tmp9;
  result_value_ptr[266] = x1;
  result_value_ptr[267] = -1;
  result_value_ptr[268] = _tmp2;
  result_value_ptr[269] = -3;
  result_value_ptr[270] = _tmp35;
  result_value_ptr[271] = x1 + Scalar(-1.0);
  result_value_ptr[272] = Scalar(-1.0);
  result_value_ptr[273] = -1;
  result_value_ptr[274] = Scalar(-0.5);
  result_value_ptr[275] = _tmp10;
  result_value_ptr[276] = -2;
  result_value_ptr[277] = x0;
  result_value_ptr[278] = x1;
  result_value_ptr[279] = _tmp44;
  result_value_ptr[280] = _tmp9;
  result_value_ptr[281] = 3;
  result_value_ptr[282] = 1;
  result_value_ptr[283] = 2;
  result_value_ptr[284] = Scalar(-3.0);
  result_value_ptr[285] = x1;
  result_value_ptr[286] = 1;
  result_value_ptr[287] = -1;
  result_value_ptr[288] = -1;
  result_value_ptr[289] = _tmp12;
  result_value_ptr[290] = x0;
  result_value_ptr[291] = -2;
  result_value_ptr[292] = Scalar(1.0);
  result_value_ptr[293] = -1;
  result_value_ptr[294] = _tmp43 + x1;
  result_value_ptr[295] = -1;
  result_value_ptr[296] = -2;
  result_value_ptr[297] = _tmp31;
  result_value_ptr[298] = _tmp31;
  result_value_ptr[299] = x1;
  result_value_ptr[300] = -_tmp36;
  result_value_ptr[301] = 4;
  result_value_ptr[302] = 1;
  result_value_ptr[303] = _tmp13;
  result_value_ptr[304] = 2;
  result_value_ptr[305] = x1;
  result_value_ptr[306] = 1;
  result_value_ptr[307] = _tmp16;
  result_value_ptr[308] = 3;
  result_value_ptr[309] = 1;
  result_value_ptr[310] = x0;
  result_value_ptr[311] = _tmp2;
  result_value_ptr[312] = x1;
  result_value_ptr[313] = _tmp34;
  result_value_ptr[314] = 1;
  result_value_ptr[315] = _tmp0;
  result_value_ptr[316] = _tmp44;
  result_value_ptr[317] = -1;
  result_value_ptr[318] = -1;
  result_value_ptr[319] = _tmp29;
  result_value_ptr[320] = _tmp12;
  result_value_ptr[321] = -_tmp11;
  result_value_ptr[322] = -1;
  result_value_ptr[323] = -3;
  result_value_ptr[324] = -2;
  result_value_ptr[325] = x1;
  result_value_ptr[326] = _tmp40 - 1;
  result_value_ptr[327] = _tmp18;

  return result;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
