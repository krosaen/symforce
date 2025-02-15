// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

#include <sym/pose3.h>

namespace sym {

/**
 * Composition of two elements in the group.
 *
 * Returns:
 *     res_D_a: (6x6) jacobian of res (6) wrt arg a (6)
 */
template <typename Scalar>
Eigen::Matrix<Scalar, 6, 6> ComposePose3Jacobian0(const sym::Pose3<Scalar>& a,
                                                  const sym::Pose3<Scalar>& b) {
  // Total ops: 249

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

  // Intermediate terms (99)
  const Scalar _tmp0 = _a[1] * _b[1];
  const Scalar _tmp1 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp2 = _a[0] * _b[0];
  const Scalar _tmp3 = (Scalar(1) / Scalar(2)) * _tmp2;
  const Scalar _tmp4 = _a[3] * _b[3];
  const Scalar _tmp5 = (Scalar(1) / Scalar(2)) * _tmp4;
  const Scalar _tmp6 = _a[2] * _b[2];
  const Scalar _tmp7 = (Scalar(1) / Scalar(2)) * _tmp6;
  const Scalar _tmp8 = _tmp5 + _tmp7;
  const Scalar _tmp9 = _tmp1 - _tmp3 + _tmp8;
  const Scalar _tmp10 = -2 * _tmp0 - 2 * _tmp2 + 2 * _tmp4 - 2 * _tmp6;
  const Scalar _tmp11 = _a[3] * _b[0];
  const Scalar _tmp12 = 2 * _tmp11;
  const Scalar _tmp13 = _a[0] * _b[3];
  const Scalar _tmp14 = 2 * _tmp13;
  const Scalar _tmp15 = _a[1] * _b[2];
  const Scalar _tmp16 = 2 * _tmp15;
  const Scalar _tmp17 = _a[2] * _b[1];
  const Scalar _tmp18 = 2 * _tmp17;
  const Scalar _tmp19 = -_tmp12 - _tmp14 - _tmp16 + _tmp18;
  const Scalar _tmp20 = (Scalar(1) / Scalar(2)) * _tmp15;
  const Scalar _tmp21 = (Scalar(1) / Scalar(2)) * _tmp13;
  const Scalar _tmp22 = -_tmp21;
  const Scalar _tmp23 = (Scalar(1) / Scalar(2)) * _tmp11;
  const Scalar _tmp24 = -Scalar(1) / Scalar(2) * _tmp17;
  const Scalar _tmp25 = -_tmp23 + _tmp24;
  const Scalar _tmp26 = _tmp20 + _tmp22 + _tmp25;
  const Scalar _tmp27 = _a[3] * _b[1];
  const Scalar _tmp28 = 2 * _tmp27;
  const Scalar _tmp29 = _a[0] * _b[2];
  const Scalar _tmp30 = 2 * _tmp29;
  const Scalar _tmp31 = _a[1] * _b[3];
  const Scalar _tmp32 = 2 * _tmp31;
  const Scalar _tmp33 = _a[2] * _b[0];
  const Scalar _tmp34 = 2 * _tmp33;
  const Scalar _tmp35 = -_tmp28 + _tmp30 - _tmp32 - _tmp34;
  const Scalar _tmp36 = (Scalar(1) / Scalar(2)) * _tmp27;
  const Scalar _tmp37 = (Scalar(1) / Scalar(2)) * _tmp33;
  const Scalar _tmp38 = -_tmp37;
  const Scalar _tmp39 = -Scalar(1) / Scalar(2) * _tmp29;
  const Scalar _tmp40 = (Scalar(1) / Scalar(2)) * _tmp31;
  const Scalar _tmp41 = _tmp39 - _tmp40;
  const Scalar _tmp42 = _tmp36 + _tmp38 + _tmp41;
  const Scalar _tmp43 = _a[2] * _b[3];
  const Scalar _tmp44 = (Scalar(1) / Scalar(2)) * _tmp43;
  const Scalar _tmp45 = _a[3] * _b[2];
  const Scalar _tmp46 = (Scalar(1) / Scalar(2)) * _tmp45;
  const Scalar _tmp47 = -_tmp46;
  const Scalar _tmp48 = _a[0] * _b[1];
  const Scalar _tmp49 = (Scalar(1) / Scalar(2)) * _tmp48;
  const Scalar _tmp50 = _a[1] * _b[0];
  const Scalar _tmp51 = -Scalar(1) / Scalar(2) * _tmp50;
  const Scalar _tmp52 = -_tmp49 + _tmp51;
  const Scalar _tmp53 = _tmp44 + _tmp47 + _tmp52;
  const Scalar _tmp54 = 2 * _tmp45;
  const Scalar _tmp55 = 2 * _tmp48;
  const Scalar _tmp56 = 2 * _tmp50;
  const Scalar _tmp57 = 2 * _tmp43;
  const Scalar _tmp58 = _tmp54 + _tmp55 - _tmp56 + _tmp57;
  const Scalar _tmp59 = -_tmp1 + _tmp3 + _tmp8;
  const Scalar _tmp60 = -_tmp44;
  const Scalar _tmp61 = _tmp46 + _tmp52 + _tmp60;
  const Scalar _tmp62 = -_tmp36;
  const Scalar _tmp63 = _tmp37 + _tmp41 + _tmp62;
  const Scalar _tmp64 = -_tmp20;
  const Scalar _tmp65 = _tmp21 + _tmp25 + _tmp64;
  const Scalar _tmp66 = _tmp1 + _tmp3 + _tmp5 - _tmp7;
  const Scalar _tmp67 = _tmp38 + _tmp39 + _tmp40 + _tmp62;
  const Scalar _tmp68 = _tmp47 + _tmp49 + _tmp51 + _tmp60;
  const Scalar _tmp69 = _tmp22 + _tmp23 + _tmp24 + _tmp64;
  const Scalar _tmp70 = -_tmp54 - _tmp55 + _tmp56 - _tmp57;
  const Scalar _tmp71 = _tmp12 + _tmp14 + _tmp16 - _tmp18;
  const Scalar _tmp72 = _tmp28 - _tmp30 + _tmp32 + _tmp34;
  const Scalar _tmp73 = 2 * _a[1];
  const Scalar _tmp74 = _a[3] * _tmp73;
  const Scalar _tmp75 = 2 * _a[2];
  const Scalar _tmp76 = _a[0] * _tmp75;
  const Scalar _tmp77 = _a[3] * _tmp75;
  const Scalar _tmp78 = _a[0] * _tmp73;
  const Scalar _tmp79 = -_tmp78;
  const Scalar _tmp80 = -_tmp74;
  const Scalar _tmp81 = -_tmp76;
  const Scalar _tmp82 = std::pow(_a[0], Scalar(2));
  const Scalar _tmp83 = std::pow(_a[1], Scalar(2));
  const Scalar _tmp84 = -_tmp83;
  const Scalar _tmp85 = _tmp82 + _tmp84;
  const Scalar _tmp86 = std::pow(_a[3], Scalar(2));
  const Scalar _tmp87 = std::pow(_a[2], Scalar(2));
  const Scalar _tmp88 = -_tmp87;
  const Scalar _tmp89 = _tmp86 + _tmp88;
  const Scalar _tmp90 = -_tmp77;
  const Scalar _tmp91 = -_tmp86;
  const Scalar _tmp92 = _tmp87 + _tmp91;
  const Scalar _tmp93 = -_tmp82;
  const Scalar _tmp94 = _tmp83 + _tmp93;
  const Scalar _tmp95 = 2 * _a[0] * _a[3];
  const Scalar _tmp96 = -_tmp95;
  const Scalar _tmp97 = _a[2] * _tmp73;
  const Scalar _tmp98 = -_tmp97;

  // Output terms (1)
  Eigen::Matrix<Scalar, 6, 6> _res_D_a;

  _res_D_a(0, 0) = _tmp10 * _tmp9 + _tmp19 * _tmp26 + _tmp35 * _tmp42 + _tmp53 * _tmp58;
  _res_D_a(0, 1) = _tmp10 * _tmp61 + _tmp19 * _tmp63 + _tmp35 * _tmp65 + _tmp58 * _tmp59;
  _res_D_a(0, 2) = _tmp10 * _tmp67 + _tmp19 * _tmp68 + _tmp35 * _tmp66 + _tmp58 * _tmp69;
  _res_D_a(0, 3) = 0;
  _res_D_a(0, 4) = 0;
  _res_D_a(0, 5) = 0;
  _res_D_a(1, 0) = _tmp10 * _tmp53 + _tmp26 * _tmp35 + _tmp42 * _tmp71 + _tmp70 * _tmp9;
  _res_D_a(1, 1) = _tmp10 * _tmp59 + _tmp35 * _tmp63 + _tmp61 * _tmp70 + _tmp65 * _tmp71;
  _res_D_a(1, 2) = _tmp10 * _tmp69 + _tmp35 * _tmp68 + _tmp66 * _tmp71 + _tmp67 * _tmp70;
  _res_D_a(1, 3) = 0;
  _res_D_a(1, 4) = 0;
  _res_D_a(1, 5) = 0;
  _res_D_a(2, 0) = _tmp10 * _tmp42 + _tmp19 * _tmp53 + _tmp26 * _tmp70 + _tmp72 * _tmp9;
  _res_D_a(2, 1) = _tmp10 * _tmp65 + _tmp19 * _tmp59 + _tmp61 * _tmp72 + _tmp63 * _tmp70;
  _res_D_a(2, 2) = _tmp10 * _tmp66 + _tmp19 * _tmp69 + _tmp67 * _tmp72 + _tmp68 * _tmp70;
  _res_D_a(2, 3) = 0;
  _res_D_a(2, 4) = 0;
  _res_D_a(2, 5) = 0;
  _res_D_a(3, 0) = _b[5] * (_tmp74 + _tmp76) + _b[6] * (_tmp77 + _tmp79);
  _res_D_a(3, 1) = _b[4] * (_tmp80 + _tmp81) + _b[6] * (_tmp85 + _tmp89);
  _res_D_a(3, 2) = _b[4] * (_tmp78 + _tmp90) + _b[5] * (_tmp92 + _tmp94);
  _res_D_a(3, 3) = 1;
  _res_D_a(3, 4) = 0;
  _res_D_a(3, 5) = 0;
  _res_D_a(4, 0) = _b[5] * (_tmp96 + _tmp97) + _b[6] * (_tmp85 + _tmp92);
  _res_D_a(4, 1) = _b[4] * (_tmp95 + _tmp98) + _b[6] * (_tmp77 + _tmp78);
  _res_D_a(4, 2) = _b[4] * (_tmp89 + _tmp94) + _b[5] * (_tmp79 + _tmp90);
  _res_D_a(4, 3) = 0;
  _res_D_a(4, 4) = 1;
  _res_D_a(4, 5) = 0;
  _res_D_a(5, 0) = _b[5] * (_tmp84 + _tmp86 + _tmp87 + _tmp93) + _b[6] * (_tmp96 + _tmp98);
  _res_D_a(5, 1) = _b[4] * (_tmp82 + _tmp83 + _tmp88 + _tmp91) + _b[6] * (_tmp76 + _tmp80);
  _res_D_a(5, 2) = _b[4] * (_tmp95 + _tmp97) + _b[5] * (_tmp74 + _tmp81);
  _res_D_a(5, 3) = 0;
  _res_D_a(5, 4) = 0;
  _res_D_a(5, 5) = 1;

  return _res_D_a;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
