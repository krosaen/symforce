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
 * Return the 2dof residual of reprojecting the landmark ray into the target spherical camera and
 * comparing it against the correspondence.
 *
 * The landmark is specified as a camera point in the source camera with an inverse range; this
 * means the landmark is fixed in the source camera and always has residual 0 there (this 0 residual
 * is not returned, only the residual in the target camera is returned).
 *
 * The norm of the residual is whitened using the Barron noise model.  Whitening each component of
 * the reprojection error separately would result in rejecting individual components as outliers.
 * Instead, we minimize the whitened norm of the full reprojection error for each point.  See the
 * docstring for `NoiseModel.whiten_norm` for more information on this, and the docstring of
 * `BarronNoiseModel` for more information on the noise model.
 *
 * Args:
 *     source_pose: The pose of the source camera
 *     target_pose: The pose of the target camera
 *     target_calibration_storage: The storage vector of the target spherical camera calibration
 *     source_inverse_range: The inverse range of the landmark in the source camera
 *     p_camera_source: The location of the landmark in the source camera coordinate, will be
 * normalized target_pixel: The location of the correspondence in the target camera weight: The
 * weight of the factor gnc_mu: The mu convexity parameter for the Barron noise model gnc_scale: The
 * scale parameter for the Barron noise model epsilon: Small positive value
 *     target_camera_model_class: The subclass of CameraCal to use as the target camera model
 *
 * Outputs:
 *     res: 2dof whiten residual of the reprojection
 *     jacobian: (2x13) jacobian of res wrt args source_pose (6), target_pose (6),
 *               source_inverse_range (1)
 *     hessian: (13x13) Gauss-Newton hessian for args source_pose (6), target_pose (6),
 *              source_inverse_range (1)
 *     rhs: (13x1) Gauss-Newton rhs for args source_pose (6), target_pose (6), source_inverse_range
 *          (1)
 */
template <typename Scalar>
void InverseRangeLandmarkPolynomialReprojectionErrorFactor(
    const sym::Pose3<Scalar>& source_pose, const sym::Pose3<Scalar>& target_pose,
    const Eigen::Matrix<Scalar, 8, 1>& target_calibration_storage,
    const Scalar source_inverse_range, const Eigen::Matrix<Scalar, 3, 1>& p_camera_source,
    const Eigen::Matrix<Scalar, 2, 1>& target_pixel, const Scalar weight, const Scalar gnc_mu,
    const Scalar gnc_scale, const Scalar epsilon, Eigen::Matrix<Scalar, 2, 1>* const res = nullptr,
    Eigen::Matrix<Scalar, 2, 13>* const jacobian = nullptr,
    Eigen::Matrix<Scalar, 13, 13>* const hessian = nullptr,
    Eigen::Matrix<Scalar, 13, 1>* const rhs = nullptr) {
  // Total ops: 1208

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _source_pose = source_pose.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _target_pose = target_pose.Data();

  // Intermediate terms (300)
  const Scalar _tmp0 = std::pow(_target_pose[1], Scalar(2));
  const Scalar _tmp1 = -2 * _tmp0;
  const Scalar _tmp2 = std::pow(_target_pose[0], Scalar(2));
  const Scalar _tmp3 = 1 - 2 * _tmp2;
  const Scalar _tmp4 = _tmp1 + _tmp3;
  const Scalar _tmp5 = 2 * _source_pose[0];
  const Scalar _tmp6 = _source_pose[3] * _tmp5;
  const Scalar _tmp7 = 2 * _source_pose[1];
  const Scalar _tmp8 = _source_pose[2] * _tmp7;
  const Scalar _tmp9 = _tmp6 + _tmp8;
  const Scalar _tmp10 = std::pow(Scalar(epsilon + std::pow(p_camera_source(0, 0), Scalar(2)) +
                                        std::pow(p_camera_source(1, 0), Scalar(2)) +
                                        std::pow(p_camera_source(2, 0), Scalar(2))),
                                 Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp11 = _tmp10 * p_camera_source(1, 0);
  const Scalar _tmp12 = _source_pose[2] * _tmp5;
  const Scalar _tmp13 = _source_pose[3] * _tmp7;
  const Scalar _tmp14 = -_tmp13;
  const Scalar _tmp15 = _tmp12 + _tmp14;
  const Scalar _tmp16 = _tmp10 * p_camera_source(0, 0);
  const Scalar _tmp17 = std::pow(_source_pose[1], Scalar(2));
  const Scalar _tmp18 = -2 * _tmp17;
  const Scalar _tmp19 = std::pow(_source_pose[0], Scalar(2));
  const Scalar _tmp20 = -2 * _tmp19;
  const Scalar _tmp21 = _tmp10 * p_camera_source(2, 0);
  const Scalar _tmp22 = _source_pose[6] - _target_pose[6];
  const Scalar _tmp23 = _tmp11 * _tmp9 + _tmp15 * _tmp16 + _tmp21 * (_tmp18 + _tmp20 + 1) +
                        _tmp22 * source_inverse_range;
  const Scalar _tmp24 = 2 * _target_pose[1] * _target_pose[2];
  const Scalar _tmp25 = 2 * _target_pose[3];
  const Scalar _tmp26 = _target_pose[0] * _tmp25;
  const Scalar _tmp27 = -_tmp26;
  const Scalar _tmp28 = _tmp24 + _tmp27;
  const Scalar _tmp29 = _source_pose[1] * _tmp5;
  const Scalar _tmp30 = 2 * _source_pose[2] * _source_pose[3];
  const Scalar _tmp31 = _tmp29 + _tmp30;
  const Scalar _tmp32 = -_tmp6;
  const Scalar _tmp33 = _tmp32 + _tmp8;
  const Scalar _tmp34 = std::pow(_source_pose[2], Scalar(2));
  const Scalar _tmp35 = 1 - 2 * _tmp34;
  const Scalar _tmp36 = _source_pose[5] - _target_pose[5];
  const Scalar _tmp37 = _tmp11 * (_tmp20 + _tmp35) + _tmp16 * _tmp31 + _tmp21 * _tmp33 +
                        _tmp36 * source_inverse_range;
  const Scalar _tmp38 = 2 * _target_pose[0];
  const Scalar _tmp39 = _target_pose[2] * _tmp38;
  const Scalar _tmp40 = _target_pose[1] * _tmp25;
  const Scalar _tmp41 = _tmp39 + _tmp40;
  const Scalar _tmp42 = -_tmp30;
  const Scalar _tmp43 = _tmp29 + _tmp42;
  const Scalar _tmp44 = _tmp12 + _tmp13;
  const Scalar _tmp45 = _source_pose[4] - _target_pose[4];
  const Scalar _tmp46 = _tmp11 * _tmp43 + _tmp16 * (_tmp18 + _tmp35) + _tmp21 * _tmp44 +
                        _tmp45 * source_inverse_range;
  const Scalar _tmp47 = _tmp28 * _tmp37 + _tmp41 * _tmp46;
  const Scalar _tmp48 = _tmp23 * _tmp4 + _tmp47;
  const Scalar _tmp49 = std::fabs(_tmp48);
  const Scalar _tmp50 = std::max<Scalar>(_tmp49, epsilon);
  const Scalar _tmp51 = std::pow(_tmp50, Scalar(-2));
  const Scalar _tmp52 = std::pow(_target_pose[2], Scalar(2));
  const Scalar _tmp53 = -2 * _tmp52;
  const Scalar _tmp54 = _tmp3 + _tmp53;
  const Scalar _tmp55 = _tmp24 + _tmp26;
  const Scalar _tmp56 = _target_pose[2] * _tmp25;
  const Scalar _tmp57 = -_tmp56;
  const Scalar _tmp58 = _target_pose[1] * _tmp38;
  const Scalar _tmp59 = _tmp57 + _tmp58;
  const Scalar _tmp60 = _tmp23 * _tmp55 + _tmp46 * _tmp59;
  const Scalar _tmp61 = _tmp37 * _tmp54 + _tmp60;
  const Scalar _tmp62 = std::pow(_tmp61, Scalar(2));
  const Scalar _tmp63 = _tmp1 + _tmp53 + 1;
  const Scalar _tmp64 = -_tmp40;
  const Scalar _tmp65 = _tmp39 + _tmp64;
  const Scalar _tmp66 = _tmp56 + _tmp58;
  const Scalar _tmp67 = _tmp23 * _tmp65 + _tmp37 * _tmp66;
  const Scalar _tmp68 = _tmp46 * _tmp63 + _tmp67;
  const Scalar _tmp69 = std::pow(_tmp68, Scalar(2));
  const Scalar _tmp70 = _tmp51 * _tmp62 + _tmp51 * _tmp69 + epsilon;
  const Scalar _tmp71 = std::pow(_tmp70, Scalar(2));
  const Scalar _tmp72 = Scalar(1.0) * target_calibration_storage(5, 0);
  const Scalar _tmp73 = Scalar(1.0) *
                            [&]() {
                              const Scalar base = _tmp70;
                              return base * base * base;
                            }() *
                            target_calibration_storage(7, 0) +
                        _tmp70 * _tmp72 + Scalar(1.0) * _tmp71 * target_calibration_storage(6, 0) +
                        Scalar(1.0);
  const Scalar _tmp74 = Scalar(1.0) / (_tmp50);
  const Scalar _tmp75 = _tmp68 * _tmp74 * target_calibration_storage(0, 0);
  const Scalar _tmp76 = _tmp73 * _tmp75 + target_calibration_storage(2, 0) - target_pixel(0, 0);
  const Scalar _tmp77 = _tmp74 * target_calibration_storage(1, 0);
  const Scalar _tmp78 = _tmp61 * _tmp77;
  const Scalar _tmp79 = _tmp73 * _tmp78 + target_calibration_storage(3, 0) - target_pixel(1, 0);
  const Scalar _tmp80 = std::pow(_tmp76, Scalar(2)) + std::pow(_tmp79, Scalar(2)) + epsilon;
  const Scalar _tmp81 = std::pow(_tmp80, Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp82 = (((_tmp48) > 0) - ((_tmp48) < 0));
  const Scalar _tmp83 =
      std::sqrt(weight) *
      std::sqrt(Scalar(std::max<Scalar>(
          0, std::min<Scalar>(_tmp82,
                              (((-std::sqrt(_tmp70) + target_calibration_storage(4, 0)) > 0) -
                               ((-std::sqrt(_tmp70) + target_calibration_storage(4, 0)) < 0))))));
  const Scalar _tmp84 = Scalar(1.0) / (epsilon - gnc_mu + 1);
  const Scalar _tmp85 = epsilon + std::fabs(_tmp84);
  const Scalar _tmp86 = 2 - _tmp84;
  const Scalar _tmp87 =
      _tmp86 + epsilon * (2 * std::min<Scalar>(0, (((_tmp86) > 0) - ((_tmp86) < 0))) + 1);
  const Scalar _tmp88 = std::pow(gnc_scale, Scalar(-2));
  const Scalar _tmp89 = _tmp80 * _tmp88 / _tmp85 + 1;
  const Scalar _tmp90 = (Scalar(1) / Scalar(2)) * _tmp87;
  const Scalar _tmp91 =
      std::sqrt(Scalar(2)) * std::sqrt(Scalar(_tmp85 * (std::pow(_tmp89, _tmp90) - 1) / _tmp87));
  const Scalar _tmp92 = _tmp83 * _tmp91;
  const Scalar _tmp93 = _tmp81 * _tmp92;
  const Scalar _tmp94 = _tmp76 * _tmp93;
  const Scalar _tmp95 = _tmp79 * _tmp93;
  const Scalar _tmp96 = -_tmp17;
  const Scalar _tmp97 = _tmp19 + _tmp96;
  const Scalar _tmp98 = std::pow(_source_pose[3], Scalar(2));
  const Scalar _tmp99 = -_tmp98;
  const Scalar _tmp100 = _tmp34 + _tmp99;
  const Scalar _tmp101 = _tmp11 * _tmp33 + _tmp21 * (_tmp100 + _tmp97);
  const Scalar _tmp102 = -_tmp8;
  const Scalar _tmp103 = -_tmp19;
  const Scalar _tmp104 =
      _tmp11 * (_tmp103 + _tmp34 + _tmp96 + _tmp98) + _tmp21 * (_tmp102 + _tmp32);
  const Scalar _tmp105 = -_tmp29;
  const Scalar _tmp106 = _tmp11 * _tmp44 + _tmp21 * (_tmp105 + _tmp30);
  const Scalar _tmp107 = _tmp101 * _tmp54 + _tmp104 * _tmp55 + _tmp106 * _tmp59;
  const Scalar _tmp108 = _tmp73 * _tmp77;
  const Scalar _tmp109 = _tmp101 * _tmp28 + _tmp104 * _tmp4 + _tmp106 * _tmp41;
  const Scalar _tmp110 = _tmp82 * ((((_tmp49 - epsilon) > 0) - ((_tmp49 - epsilon) < 0)) + 1);
  const Scalar _tmp111 = (Scalar(1) / Scalar(2)) * _tmp110 * _tmp51;
  const Scalar _tmp112 = _tmp61 * _tmp73 * target_calibration_storage(1, 0);
  const Scalar _tmp113 = _tmp111 * _tmp112;
  const Scalar _tmp114 = _tmp101 * _tmp66 + _tmp104 * _tmp65 + _tmp106 * _tmp63;
  const Scalar _tmp115 = 2 * _tmp51;
  const Scalar _tmp116 = _tmp115 * _tmp68;
  const Scalar _tmp117 = _tmp110 / [&]() {
    const Scalar base = _tmp50;
    return base * base * base;
  }();
  const Scalar _tmp118 = _tmp109 * _tmp117;
  const Scalar _tmp119 = _tmp115 * _tmp61;
  const Scalar _tmp120 =
      _tmp107 * _tmp119 + _tmp114 * _tmp116 - _tmp118 * _tmp62 - _tmp118 * _tmp69;
  const Scalar _tmp121 = Scalar(3.0) * _tmp71 * target_calibration_storage(7, 0);
  const Scalar _tmp122 = Scalar(2.0) * _tmp70 * target_calibration_storage(6, 0);
  const Scalar _tmp123 = _tmp120 * _tmp121 + _tmp120 * _tmp122 + _tmp120 * _tmp72;
  const Scalar _tmp124 = _tmp107 * _tmp108 - _tmp109 * _tmp113 + _tmp123 * _tmp78;
  const Scalar _tmp125 = 2 * _tmp79;
  const Scalar _tmp126 = _tmp73 * target_calibration_storage(0, 0);
  const Scalar _tmp127 = _tmp126 * _tmp68;
  const Scalar _tmp128 = _tmp111 * _tmp127;
  const Scalar _tmp129 = _tmp126 * _tmp74;
  const Scalar _tmp130 = -_tmp109 * _tmp128 + _tmp114 * _tmp129 + _tmp123 * _tmp75;
  const Scalar _tmp131 = 2 * _tmp76;
  const Scalar _tmp132 = _tmp124 * _tmp125 + _tmp130 * _tmp131;
  const Scalar _tmp133 = (Scalar(1) / Scalar(2)) * _tmp76;
  const Scalar _tmp134 = _tmp81 * _tmp83 * _tmp88 * std::pow(_tmp89, Scalar(_tmp90 - 1)) / _tmp91;
  const Scalar _tmp135 = _tmp133 * _tmp134;
  const Scalar _tmp136 = _tmp92 / (_tmp80 * std::sqrt(_tmp80));
  const Scalar _tmp137 = _tmp133 * _tmp136;
  const Scalar _tmp138 = _tmp130 * _tmp93 + _tmp132 * _tmp135 - _tmp132 * _tmp137;
  const Scalar _tmp139 = -_tmp12;
  const Scalar _tmp140 = -_tmp34;
  const Scalar _tmp141 = _tmp140 + _tmp98;
  const Scalar _tmp142 = _tmp16 * (_tmp139 + _tmp14) + _tmp21 * (_tmp141 + _tmp97);
  const Scalar _tmp143 = _tmp15 * _tmp21 + _tmp16 * (_tmp140 + _tmp17 + _tmp19 + _tmp99);
  const Scalar _tmp144 = _tmp16 * (_tmp102 + _tmp6) + _tmp21 * _tmp31;
  const Scalar _tmp145 = _tmp142 * _tmp63 + _tmp143 * _tmp65 + _tmp144 * _tmp66;
  const Scalar _tmp146 = _tmp142 * _tmp41 + _tmp143 * _tmp4 + _tmp144 * _tmp28;
  const Scalar _tmp147 = _tmp142 * _tmp59 + _tmp143 * _tmp55 + _tmp144 * _tmp54;
  const Scalar _tmp148 = _tmp117 * _tmp62;
  const Scalar _tmp149 = _tmp117 * _tmp69;
  const Scalar _tmp150 =
      _tmp116 * _tmp145 + _tmp119 * _tmp147 - _tmp146 * _tmp148 - _tmp146 * _tmp149;
  const Scalar _tmp151 = _tmp121 * _tmp150 + _tmp122 * _tmp150 + _tmp150 * _tmp72;
  const Scalar _tmp152 = -_tmp128 * _tmp146 + _tmp129 * _tmp145 + _tmp151 * _tmp75;
  const Scalar _tmp153 = _tmp108 * _tmp147 - _tmp113 * _tmp146 + _tmp151 * _tmp78;
  const Scalar _tmp154 = _tmp125 * _tmp153 + _tmp131 * _tmp152;
  const Scalar _tmp155 = _tmp135 * _tmp154 - _tmp137 * _tmp154 + _tmp152 * _tmp93;
  const Scalar _tmp156 = _tmp11 * (_tmp13 + _tmp139) + _tmp16 * _tmp9;
  const Scalar _tmp157 = _tmp103 + _tmp17;
  const Scalar _tmp158 = _tmp11 * (_tmp100 + _tmp157) + _tmp16 * _tmp43;
  const Scalar _tmp159 = _tmp11 * (_tmp105 + _tmp42) + _tmp16 * (_tmp141 + _tmp157);
  const Scalar _tmp160 = _tmp156 * _tmp4 + _tmp158 * _tmp41 + _tmp159 * _tmp28;
  const Scalar _tmp161 = _tmp156 * _tmp55 + _tmp158 * _tmp59 + _tmp159 * _tmp54;
  const Scalar _tmp162 = _tmp156 * _tmp65 + _tmp158 * _tmp63 + _tmp159 * _tmp66;
  const Scalar _tmp163 =
      _tmp116 * _tmp162 + _tmp119 * _tmp161 - _tmp148 * _tmp160 - _tmp149 * _tmp160;
  const Scalar _tmp164 = _tmp121 * _tmp163 + _tmp122 * _tmp163 + _tmp163 * _tmp72;
  const Scalar _tmp165 = _tmp108 * _tmp161 - _tmp113 * _tmp160 + _tmp164 * _tmp78;
  const Scalar _tmp166 = -_tmp128 * _tmp160 + _tmp129 * _tmp162 + _tmp164 * _tmp75;
  const Scalar _tmp167 = _tmp125 * _tmp165 + _tmp131 * _tmp166;
  const Scalar _tmp168 = _tmp135 * _tmp167 - _tmp137 * _tmp167 + _tmp166 * _tmp93;
  const Scalar _tmp169 = _tmp129 * source_inverse_range;
  const Scalar _tmp170 = _tmp169 * _tmp63;
  const Scalar _tmp171 = _tmp128 * source_inverse_range;
  const Scalar _tmp172 = _tmp171 * _tmp41;
  const Scalar _tmp173 = _tmp149 * source_inverse_range;
  const Scalar _tmp174 = _tmp173 * _tmp41;
  const Scalar _tmp175 = _tmp116 * source_inverse_range;
  const Scalar _tmp176 = _tmp175 * _tmp63;
  const Scalar _tmp177 = _tmp119 * source_inverse_range;
  const Scalar _tmp178 = _tmp177 * _tmp59;
  const Scalar _tmp179 = _tmp148 * source_inverse_range;
  const Scalar _tmp180 = _tmp179 * _tmp41;
  const Scalar _tmp181 = -_tmp174 + _tmp176 + _tmp178 - _tmp180;
  const Scalar _tmp182 = _tmp121 * _tmp181 + _tmp122 * _tmp181 + _tmp181 * _tmp72;
  const Scalar _tmp183 = _tmp170 - _tmp172 + _tmp182 * _tmp75;
  const Scalar _tmp184 = _tmp108 * source_inverse_range;
  const Scalar _tmp185 = _tmp184 * _tmp59;
  const Scalar _tmp186 = _tmp113 * source_inverse_range;
  const Scalar _tmp187 = _tmp186 * _tmp41;
  const Scalar _tmp188 = _tmp182 * _tmp78 + _tmp185 - _tmp187;
  const Scalar _tmp189 = _tmp125 * _tmp188 + _tmp131 * _tmp183;
  const Scalar _tmp190 = _tmp135 * _tmp189 - _tmp137 * _tmp189 + _tmp183 * _tmp93;
  const Scalar _tmp191 = _tmp186 * _tmp28;
  const Scalar _tmp192 = _tmp177 * _tmp54;
  const Scalar _tmp193 = _tmp173 * _tmp28;
  const Scalar _tmp194 = _tmp175 * _tmp66;
  const Scalar _tmp195 = _tmp179 * _tmp28;
  const Scalar _tmp196 = _tmp192 - _tmp193 + _tmp194 - _tmp195;
  const Scalar _tmp197 = _tmp121 * _tmp196 + _tmp122 * _tmp196 + _tmp196 * _tmp72;
  const Scalar _tmp198 = _tmp184 * _tmp54;
  const Scalar _tmp199 = -_tmp191 + _tmp197 * _tmp78 + _tmp198;
  const Scalar _tmp200 = _tmp169 * _tmp66;
  const Scalar _tmp201 = _tmp171 * _tmp28;
  const Scalar _tmp202 = _tmp197 * _tmp75 + _tmp200 - _tmp201;
  const Scalar _tmp203 = _tmp125 * _tmp199 + _tmp131 * _tmp202;
  const Scalar _tmp204 = _tmp135 * _tmp203 - _tmp137 * _tmp203 + _tmp202 * _tmp93;
  const Scalar _tmp205 = _tmp171 * _tmp4;
  const Scalar _tmp206 = _tmp169 * _tmp65;
  const Scalar _tmp207 = _tmp179 * _tmp4;
  const Scalar _tmp208 = _tmp175 * _tmp65;
  const Scalar _tmp209 = _tmp173 * _tmp4;
  const Scalar _tmp210 = _tmp177 * _tmp55;
  const Scalar _tmp211 = -_tmp207 + _tmp208 - _tmp209 + _tmp210;
  const Scalar _tmp212 = _tmp121 * _tmp211 + _tmp122 * _tmp211 + _tmp211 * _tmp72;
  const Scalar _tmp213 = -_tmp205 + _tmp206 + _tmp212 * _tmp75;
  const Scalar _tmp214 = _tmp186 * _tmp4;
  const Scalar _tmp215 = _tmp184 * _tmp55;
  const Scalar _tmp216 = _tmp212 * _tmp78 - _tmp214 + _tmp215;
  const Scalar _tmp217 = _tmp125 * _tmp216 + _tmp131 * _tmp213;
  const Scalar _tmp218 = _tmp135 * _tmp217 - _tmp137 * _tmp217 + _tmp213 * _tmp93;
  const Scalar _tmp219 = -_tmp24;
  const Scalar _tmp220 = std::pow(_target_pose[3], Scalar(2));
  const Scalar _tmp221 = -_tmp220;
  const Scalar _tmp222 = _tmp2 + _tmp221;
  const Scalar _tmp223 = -_tmp0;
  const Scalar _tmp224 = _tmp223 + _tmp52;
  const Scalar _tmp225 = -_tmp58;
  const Scalar _tmp226 =
      _tmp23 * (_tmp219 + _tmp27) + _tmp37 * (_tmp222 + _tmp224) + _tmp46 * (_tmp225 + _tmp56);
  const Scalar _tmp227 = -_tmp2;
  const Scalar _tmp228 = _tmp220 + _tmp227;
  const Scalar _tmp229 = _tmp23 * (_tmp224 + _tmp228) + _tmp47;
  const Scalar _tmp230 = _tmp119 * _tmp229 - _tmp148 * _tmp226 - _tmp149 * _tmp226;
  const Scalar _tmp231 = _tmp121 * _tmp230 + _tmp122 * _tmp230 + _tmp230 * _tmp72;
  const Scalar _tmp232 = _tmp111 * _tmp226;
  const Scalar _tmp233 = -_tmp127 * _tmp232 + _tmp231 * _tmp75;
  const Scalar _tmp234 = _tmp108 * _tmp229 - _tmp112 * _tmp232 + _tmp231 * _tmp78;
  const Scalar _tmp235 = _tmp125 * _tmp234 + _tmp131 * _tmp233;
  const Scalar _tmp236 = _tmp135 * _tmp235 - _tmp137 * _tmp235 + _tmp233 * _tmp93;
  const Scalar _tmp237 = -_tmp52;
  const Scalar _tmp238 = _tmp46 * (_tmp2 + _tmp220 + _tmp223 + _tmp237) + _tmp67;
  const Scalar _tmp239 = _tmp0 + _tmp237;
  const Scalar _tmp240 = -_tmp39;
  const Scalar _tmp241 =
      _tmp23 * (_tmp222 + _tmp239) + _tmp37 * (_tmp219 + _tmp26) + _tmp46 * (_tmp240 + _tmp64);
  const Scalar _tmp242 = _tmp116 * _tmp241 - _tmp148 * _tmp238 - _tmp149 * _tmp238;
  const Scalar _tmp243 = _tmp121 * _tmp242 + _tmp122 * _tmp242 + _tmp242 * _tmp72;
  const Scalar _tmp244 = -_tmp113 * _tmp238 + _tmp243 * _tmp78;
  const Scalar _tmp245 = -_tmp128 * _tmp238 + _tmp129 * _tmp241 + _tmp243 * _tmp75;
  const Scalar _tmp246 = _tmp125 * _tmp244 + _tmp131 * _tmp245;
  const Scalar _tmp247 = _tmp135 * _tmp246 - _tmp137 * _tmp246 + _tmp245 * _tmp93;
  const Scalar _tmp248 = _tmp37 * (_tmp228 + _tmp239) + _tmp60;
  const Scalar _tmp249 = _tmp23 * (_tmp240 + _tmp40) + _tmp37 * (_tmp225 + _tmp57) +
                         _tmp46 * (_tmp0 + _tmp221 + _tmp227 + _tmp52);
  const Scalar _tmp250 = _tmp116 * _tmp248 + _tmp119 * _tmp249;
  const Scalar _tmp251 = _tmp121 * _tmp250 + _tmp122 * _tmp250 + _tmp250 * _tmp72;
  const Scalar _tmp252 = _tmp129 * _tmp248 + _tmp251 * _tmp75;
  const Scalar _tmp253 = _tmp108 * _tmp249 + _tmp251 * _tmp78;
  const Scalar _tmp254 = _tmp125 * _tmp253 + _tmp131 * _tmp252;
  const Scalar _tmp255 = _tmp135 * _tmp254 - _tmp137 * _tmp254 + _tmp252 * _tmp93;
  const Scalar _tmp256 = _tmp174 - _tmp176 - _tmp178 + _tmp180;
  const Scalar _tmp257 = _tmp121 * _tmp256 + _tmp122 * _tmp256 + _tmp256 * _tmp72;
  const Scalar _tmp258 = -_tmp170 + _tmp172 + _tmp257 * _tmp75;
  const Scalar _tmp259 = -_tmp185 + _tmp187 + _tmp257 * _tmp78;
  const Scalar _tmp260 = _tmp125 * _tmp259 + _tmp131 * _tmp258;
  const Scalar _tmp261 = _tmp135 * _tmp260 - _tmp137 * _tmp260 + _tmp258 * _tmp93;
  const Scalar _tmp262 = -_tmp192 + _tmp193 - _tmp194 + _tmp195;
  const Scalar _tmp263 = _tmp121 * _tmp262 + _tmp122 * _tmp262 + _tmp262 * _tmp72;
  const Scalar _tmp264 = -_tmp200 + _tmp201 + _tmp263 * _tmp75;
  const Scalar _tmp265 = _tmp191 - _tmp198 + _tmp263 * _tmp78;
  const Scalar _tmp266 = _tmp125 * _tmp265 + _tmp131 * _tmp264;
  const Scalar _tmp267 = _tmp135 * _tmp266 - _tmp137 * _tmp266 + _tmp264 * _tmp93;
  const Scalar _tmp268 = _tmp207 - _tmp208 + _tmp209 - _tmp210;
  const Scalar _tmp269 = _tmp121 * _tmp268 + _tmp122 * _tmp268 + _tmp268 * _tmp72;
  const Scalar _tmp270 = _tmp205 - _tmp206 + _tmp269 * _tmp75;
  const Scalar _tmp271 = _tmp214 - _tmp215 + _tmp269 * _tmp78;
  const Scalar _tmp272 = _tmp125 * _tmp271 + _tmp131 * _tmp270;
  const Scalar _tmp273 = _tmp135 * _tmp272 - _tmp137 * _tmp272 + _tmp270 * _tmp93;
  const Scalar _tmp274 = _tmp22 * _tmp55 + _tmp36 * _tmp54 + _tmp45 * _tmp59;
  const Scalar _tmp275 = _tmp22 * _tmp4 + _tmp28 * _tmp36 + _tmp41 * _tmp45;
  const Scalar _tmp276 = _tmp22 * _tmp65 + _tmp36 * _tmp66 + _tmp45 * _tmp63;
  const Scalar _tmp277 =
      _tmp116 * _tmp276 + _tmp119 * _tmp274 - _tmp148 * _tmp275 - _tmp149 * _tmp275;
  const Scalar _tmp278 = _tmp121 * _tmp277 + _tmp122 * _tmp277 + _tmp277 * _tmp72;
  const Scalar _tmp279 = _tmp108 * _tmp274 - _tmp113 * _tmp275 + _tmp278 * _tmp78;
  const Scalar _tmp280 = -_tmp128 * _tmp275 + _tmp129 * _tmp276 + _tmp278 * _tmp75;
  const Scalar _tmp281 = _tmp125 * _tmp279 + _tmp131 * _tmp280;
  const Scalar _tmp282 = _tmp135 * _tmp281 - _tmp137 * _tmp281 + _tmp280 * _tmp93;
  const Scalar _tmp283 = (Scalar(1) / Scalar(2)) * _tmp79;
  const Scalar _tmp284 = _tmp134 * _tmp283;
  const Scalar _tmp285 = _tmp136 * _tmp283;
  const Scalar _tmp286 = _tmp124 * _tmp93 + _tmp132 * _tmp284 - _tmp132 * _tmp285;
  const Scalar _tmp287 = _tmp154 * _tmp283;
  const Scalar _tmp288 = _tmp134 * _tmp287 - _tmp136 * _tmp287 + _tmp153 * _tmp93;
  const Scalar _tmp289 = _tmp165 * _tmp93 + _tmp167 * _tmp284 - _tmp167 * _tmp285;
  const Scalar _tmp290 = _tmp188 * _tmp93 + _tmp189 * _tmp284 - _tmp189 * _tmp285;
  const Scalar _tmp291 = _tmp199 * _tmp93 + _tmp203 * _tmp284 - _tmp203 * _tmp285;
  const Scalar _tmp292 = _tmp216 * _tmp93 + _tmp217 * _tmp284 - _tmp217 * _tmp285;
  const Scalar _tmp293 = _tmp234 * _tmp93 + _tmp235 * _tmp284 - _tmp235 * _tmp285;
  const Scalar _tmp294 = _tmp244 * _tmp93 + _tmp246 * _tmp284 - _tmp246 * _tmp285;
  const Scalar _tmp295 = _tmp253 * _tmp93 + _tmp254 * _tmp284 - _tmp254 * _tmp285;
  const Scalar _tmp296 = _tmp259 * _tmp93 + _tmp260 * _tmp284 - _tmp260 * _tmp285;
  const Scalar _tmp297 = _tmp265 * _tmp93 + _tmp266 * _tmp284 - _tmp266 * _tmp285;
  const Scalar _tmp298 = _tmp271 * _tmp93 + _tmp272 * _tmp284 - _tmp272 * _tmp285;
  const Scalar _tmp299 = _tmp279 * _tmp93 + _tmp281 * _tmp284 - _tmp281 * _tmp285;

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 2, 1>& _res = (*res);

    _res(0, 0) = _tmp94;
    _res(1, 0) = _tmp95;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 2, 13>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp138;
    _jacobian(0, 1) = _tmp155;
    _jacobian(0, 2) = _tmp168;
    _jacobian(0, 3) = _tmp190;
    _jacobian(0, 4) = _tmp204;
    _jacobian(0, 5) = _tmp218;
    _jacobian(0, 6) = _tmp236;
    _jacobian(0, 7) = _tmp247;
    _jacobian(0, 8) = _tmp255;
    _jacobian(0, 9) = _tmp261;
    _jacobian(0, 10) = _tmp267;
    _jacobian(0, 11) = _tmp273;
    _jacobian(0, 12) = _tmp282;
    _jacobian(1, 0) = _tmp286;
    _jacobian(1, 1) = _tmp288;
    _jacobian(1, 2) = _tmp289;
    _jacobian(1, 3) = _tmp290;
    _jacobian(1, 4) = _tmp291;
    _jacobian(1, 5) = _tmp292;
    _jacobian(1, 6) = _tmp293;
    _jacobian(1, 7) = _tmp294;
    _jacobian(1, 8) = _tmp295;
    _jacobian(1, 9) = _tmp296;
    _jacobian(1, 10) = _tmp297;
    _jacobian(1, 11) = _tmp298;
    _jacobian(1, 12) = _tmp299;
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 13, 13>& _hessian = (*hessian);

    _hessian(0, 0) = std::pow(_tmp138, Scalar(2)) + std::pow(_tmp286, Scalar(2));
    _hessian(0, 1) = 0;
    _hessian(0, 2) = 0;
    _hessian(0, 3) = 0;
    _hessian(0, 4) = 0;
    _hessian(0, 5) = 0;
    _hessian(0, 6) = 0;
    _hessian(0, 7) = 0;
    _hessian(0, 8) = 0;
    _hessian(0, 9) = 0;
    _hessian(0, 10) = 0;
    _hessian(0, 11) = 0;
    _hessian(0, 12) = 0;
    _hessian(1, 0) = _tmp138 * _tmp155 + _tmp286 * _tmp288;
    _hessian(1, 1) = std::pow(_tmp155, Scalar(2)) + std::pow(_tmp288, Scalar(2));
    _hessian(1, 2) = 0;
    _hessian(1, 3) = 0;
    _hessian(1, 4) = 0;
    _hessian(1, 5) = 0;
    _hessian(1, 6) = 0;
    _hessian(1, 7) = 0;
    _hessian(1, 8) = 0;
    _hessian(1, 9) = 0;
    _hessian(1, 10) = 0;
    _hessian(1, 11) = 0;
    _hessian(1, 12) = 0;
    _hessian(2, 0) = _tmp138 * _tmp168 + _tmp286 * _tmp289;
    _hessian(2, 1) = _tmp155 * _tmp168 + _tmp288 * _tmp289;
    _hessian(2, 2) = std::pow(_tmp168, Scalar(2)) + std::pow(_tmp289, Scalar(2));
    _hessian(2, 3) = 0;
    _hessian(2, 4) = 0;
    _hessian(2, 5) = 0;
    _hessian(2, 6) = 0;
    _hessian(2, 7) = 0;
    _hessian(2, 8) = 0;
    _hessian(2, 9) = 0;
    _hessian(2, 10) = 0;
    _hessian(2, 11) = 0;
    _hessian(2, 12) = 0;
    _hessian(3, 0) = _tmp138 * _tmp190 + _tmp286 * _tmp290;
    _hessian(3, 1) = _tmp155 * _tmp190 + _tmp288 * _tmp290;
    _hessian(3, 2) = _tmp168 * _tmp190 + _tmp289 * _tmp290;
    _hessian(3, 3) = std::pow(_tmp190, Scalar(2)) + std::pow(_tmp290, Scalar(2));
    _hessian(3, 4) = 0;
    _hessian(3, 5) = 0;
    _hessian(3, 6) = 0;
    _hessian(3, 7) = 0;
    _hessian(3, 8) = 0;
    _hessian(3, 9) = 0;
    _hessian(3, 10) = 0;
    _hessian(3, 11) = 0;
    _hessian(3, 12) = 0;
    _hessian(4, 0) = _tmp138 * _tmp204 + _tmp286 * _tmp291;
    _hessian(4, 1) = _tmp155 * _tmp204 + _tmp288 * _tmp291;
    _hessian(4, 2) = _tmp168 * _tmp204 + _tmp289 * _tmp291;
    _hessian(4, 3) = _tmp190 * _tmp204 + _tmp290 * _tmp291;
    _hessian(4, 4) = std::pow(_tmp204, Scalar(2)) + std::pow(_tmp291, Scalar(2));
    _hessian(4, 5) = 0;
    _hessian(4, 6) = 0;
    _hessian(4, 7) = 0;
    _hessian(4, 8) = 0;
    _hessian(4, 9) = 0;
    _hessian(4, 10) = 0;
    _hessian(4, 11) = 0;
    _hessian(4, 12) = 0;
    _hessian(5, 0) = _tmp138 * _tmp218 + _tmp286 * _tmp292;
    _hessian(5, 1) = _tmp155 * _tmp218 + _tmp288 * _tmp292;
    _hessian(5, 2) = _tmp168 * _tmp218 + _tmp289 * _tmp292;
    _hessian(5, 3) = _tmp190 * _tmp218 + _tmp290 * _tmp292;
    _hessian(5, 4) = _tmp204 * _tmp218 + _tmp291 * _tmp292;
    _hessian(5, 5) = std::pow(_tmp218, Scalar(2)) + std::pow(_tmp292, Scalar(2));
    _hessian(5, 6) = 0;
    _hessian(5, 7) = 0;
    _hessian(5, 8) = 0;
    _hessian(5, 9) = 0;
    _hessian(5, 10) = 0;
    _hessian(5, 11) = 0;
    _hessian(5, 12) = 0;
    _hessian(6, 0) = _tmp138 * _tmp236 + _tmp286 * _tmp293;
    _hessian(6, 1) = _tmp155 * _tmp236 + _tmp288 * _tmp293;
    _hessian(6, 2) = _tmp168 * _tmp236 + _tmp289 * _tmp293;
    _hessian(6, 3) = _tmp190 * _tmp236 + _tmp290 * _tmp293;
    _hessian(6, 4) = _tmp204 * _tmp236 + _tmp291 * _tmp293;
    _hessian(6, 5) = _tmp218 * _tmp236 + _tmp292 * _tmp293;
    _hessian(6, 6) = std::pow(_tmp236, Scalar(2)) + std::pow(_tmp293, Scalar(2));
    _hessian(6, 7) = 0;
    _hessian(6, 8) = 0;
    _hessian(6, 9) = 0;
    _hessian(6, 10) = 0;
    _hessian(6, 11) = 0;
    _hessian(6, 12) = 0;
    _hessian(7, 0) = _tmp138 * _tmp247 + _tmp286 * _tmp294;
    _hessian(7, 1) = _tmp155 * _tmp247 + _tmp288 * _tmp294;
    _hessian(7, 2) = _tmp168 * _tmp247 + _tmp289 * _tmp294;
    _hessian(7, 3) = _tmp190 * _tmp247 + _tmp290 * _tmp294;
    _hessian(7, 4) = _tmp204 * _tmp247 + _tmp291 * _tmp294;
    _hessian(7, 5) = _tmp218 * _tmp247 + _tmp292 * _tmp294;
    _hessian(7, 6) = _tmp236 * _tmp247 + _tmp293 * _tmp294;
    _hessian(7, 7) = std::pow(_tmp247, Scalar(2)) + std::pow(_tmp294, Scalar(2));
    _hessian(7, 8) = 0;
    _hessian(7, 9) = 0;
    _hessian(7, 10) = 0;
    _hessian(7, 11) = 0;
    _hessian(7, 12) = 0;
    _hessian(8, 0) = _tmp138 * _tmp255 + _tmp286 * _tmp295;
    _hessian(8, 1) = _tmp155 * _tmp255 + _tmp288 * _tmp295;
    _hessian(8, 2) = _tmp168 * _tmp255 + _tmp289 * _tmp295;
    _hessian(8, 3) = _tmp190 * _tmp255 + _tmp290 * _tmp295;
    _hessian(8, 4) = _tmp204 * _tmp255 + _tmp291 * _tmp295;
    _hessian(8, 5) = _tmp218 * _tmp255 + _tmp292 * _tmp295;
    _hessian(8, 6) = _tmp236 * _tmp255 + _tmp293 * _tmp295;
    _hessian(8, 7) = _tmp247 * _tmp255 + _tmp294 * _tmp295;
    _hessian(8, 8) = std::pow(_tmp255, Scalar(2)) + std::pow(_tmp295, Scalar(2));
    _hessian(8, 9) = 0;
    _hessian(8, 10) = 0;
    _hessian(8, 11) = 0;
    _hessian(8, 12) = 0;
    _hessian(9, 0) = _tmp138 * _tmp261 + _tmp286 * _tmp296;
    _hessian(9, 1) = _tmp155 * _tmp261 + _tmp288 * _tmp296;
    _hessian(9, 2) = _tmp168 * _tmp261 + _tmp289 * _tmp296;
    _hessian(9, 3) = _tmp190 * _tmp261 + _tmp290 * _tmp296;
    _hessian(9, 4) = _tmp204 * _tmp261 + _tmp291 * _tmp296;
    _hessian(9, 5) = _tmp218 * _tmp261 + _tmp292 * _tmp296;
    _hessian(9, 6) = _tmp236 * _tmp261 + _tmp293 * _tmp296;
    _hessian(9, 7) = _tmp247 * _tmp261 + _tmp294 * _tmp296;
    _hessian(9, 8) = _tmp255 * _tmp261 + _tmp295 * _tmp296;
    _hessian(9, 9) = std::pow(_tmp261, Scalar(2)) + std::pow(_tmp296, Scalar(2));
    _hessian(9, 10) = 0;
    _hessian(9, 11) = 0;
    _hessian(9, 12) = 0;
    _hessian(10, 0) = _tmp138 * _tmp267 + _tmp286 * _tmp297;
    _hessian(10, 1) = _tmp155 * _tmp267 + _tmp288 * _tmp297;
    _hessian(10, 2) = _tmp168 * _tmp267 + _tmp289 * _tmp297;
    _hessian(10, 3) = _tmp190 * _tmp267 + _tmp290 * _tmp297;
    _hessian(10, 4) = _tmp204 * _tmp267 + _tmp291 * _tmp297;
    _hessian(10, 5) = _tmp218 * _tmp267 + _tmp292 * _tmp297;
    _hessian(10, 6) = _tmp236 * _tmp267 + _tmp293 * _tmp297;
    _hessian(10, 7) = _tmp247 * _tmp267 + _tmp294 * _tmp297;
    _hessian(10, 8) = _tmp255 * _tmp267 + _tmp295 * _tmp297;
    _hessian(10, 9) = _tmp261 * _tmp267 + _tmp296 * _tmp297;
    _hessian(10, 10) = std::pow(_tmp267, Scalar(2)) + std::pow(_tmp297, Scalar(2));
    _hessian(10, 11) = 0;
    _hessian(10, 12) = 0;
    _hessian(11, 0) = _tmp138 * _tmp273 + _tmp286 * _tmp298;
    _hessian(11, 1) = _tmp155 * _tmp273 + _tmp288 * _tmp298;
    _hessian(11, 2) = _tmp168 * _tmp273 + _tmp289 * _tmp298;
    _hessian(11, 3) = _tmp190 * _tmp273 + _tmp290 * _tmp298;
    _hessian(11, 4) = _tmp204 * _tmp273 + _tmp291 * _tmp298;
    _hessian(11, 5) = _tmp218 * _tmp273 + _tmp292 * _tmp298;
    _hessian(11, 6) = _tmp236 * _tmp273 + _tmp293 * _tmp298;
    _hessian(11, 7) = _tmp247 * _tmp273 + _tmp294 * _tmp298;
    _hessian(11, 8) = _tmp255 * _tmp273 + _tmp295 * _tmp298;
    _hessian(11, 9) = _tmp261 * _tmp273 + _tmp296 * _tmp298;
    _hessian(11, 10) = _tmp267 * _tmp273 + _tmp297 * _tmp298;
    _hessian(11, 11) = std::pow(_tmp273, Scalar(2)) + std::pow(_tmp298, Scalar(2));
    _hessian(11, 12) = 0;
    _hessian(12, 0) = _tmp138 * _tmp282 + _tmp286 * _tmp299;
    _hessian(12, 1) = _tmp155 * _tmp282 + _tmp288 * _tmp299;
    _hessian(12, 2) = _tmp168 * _tmp282 + _tmp289 * _tmp299;
    _hessian(12, 3) = _tmp190 * _tmp282 + _tmp290 * _tmp299;
    _hessian(12, 4) = _tmp204 * _tmp282 + _tmp291 * _tmp299;
    _hessian(12, 5) = _tmp218 * _tmp282 + _tmp292 * _tmp299;
    _hessian(12, 6) = _tmp236 * _tmp282 + _tmp293 * _tmp299;
    _hessian(12, 7) = _tmp247 * _tmp282 + _tmp294 * _tmp299;
    _hessian(12, 8) = _tmp255 * _tmp282 + _tmp295 * _tmp299;
    _hessian(12, 9) = _tmp261 * _tmp282 + _tmp296 * _tmp299;
    _hessian(12, 10) = _tmp267 * _tmp282 + _tmp297 * _tmp299;
    _hessian(12, 11) = _tmp273 * _tmp282 + _tmp298 * _tmp299;
    _hessian(12, 12) = std::pow(_tmp282, Scalar(2)) + std::pow(_tmp299, Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 13, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp138 * _tmp94 + _tmp286 * _tmp95;
    _rhs(1, 0) = _tmp155 * _tmp94 + _tmp288 * _tmp95;
    _rhs(2, 0) = _tmp168 * _tmp94 + _tmp289 * _tmp95;
    _rhs(3, 0) = _tmp190 * _tmp94 + _tmp290 * _tmp95;
    _rhs(4, 0) = _tmp204 * _tmp94 + _tmp291 * _tmp95;
    _rhs(5, 0) = _tmp218 * _tmp94 + _tmp292 * _tmp95;
    _rhs(6, 0) = _tmp236 * _tmp94 + _tmp293 * _tmp95;
    _rhs(7, 0) = _tmp247 * _tmp94 + _tmp294 * _tmp95;
    _rhs(8, 0) = _tmp255 * _tmp94 + _tmp295 * _tmp95;
    _rhs(9, 0) = _tmp261 * _tmp94 + _tmp296 * _tmp95;
    _rhs(10, 0) = _tmp267 * _tmp94 + _tmp297 * _tmp95;
    _rhs(11, 0) = _tmp273 * _tmp94 + _tmp298 * _tmp95;
    _rhs(12, 0) = _tmp282 * _tmp94 + _tmp299 * _tmp95;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
