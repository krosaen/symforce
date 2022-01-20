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
 * Reprojects the landmark into the target camera and returns the delta from the correspondence to
 * the reprojection.
 *
 * The landmark is specified as a pixel in the source camera and an inverse range; this means the
 * landmark is fixed in the source camera and always has residual 0 there (this 0 residual is not
 * returned, only the residual in the target camera is returned).
 *
 * Args:
 *     source_pose: The pose of the source camera
 *     source_calibration_storage: The storage vector of the source camera calibration
 *     target_pose: The pose of the target camera
 *     target_calibration_storage: The storage vector of the target camera calibration
 *     source_inverse_range: The inverse range of the landmark in the source camera
 *     source_pixel: The location of the landmark in the source camera
 *     target_pixel: The location of the correspondence in the target camera
 *     epsilon: Small positive value
 *     camera_model_class: The subclass of CameraCal to use as the camera model
 *
 * Outputs:
 *     res: 2dof pixel reprojection error
 *     valid: is valid projection or not
 *
 */
template <typename Scalar>
void AtanReprojectionDelta(const sym::Pose3<Scalar>& source_pose,
                           const Eigen::Matrix<Scalar, 5, 1>& source_calibration_storage,
                           const sym::Pose3<Scalar>& target_pose,
                           const Eigen::Matrix<Scalar, 5, 1>& target_calibration_storage,
                           const Scalar source_inverse_range,
                           const Eigen::Matrix<Scalar, 2, 1>& source_pixel,
                           const Eigen::Matrix<Scalar, 2, 1>& target_pixel, const Scalar epsilon,
                           Eigen::Matrix<Scalar, 2, 1>* const reprojection_delta = nullptr,
                           Scalar* const is_valid = nullptr) {
  // Total ops: 180

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _source_pose = source_pose.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _target_pose = target_pose.Data();

  // Intermediate terms (46)
  const Scalar _tmp0 = -2 * std::pow(_target_pose[2], Scalar(2));
  const Scalar _tmp1 = 1 - 2 * std::pow(_target_pose[1], Scalar(2));
  const Scalar _tmp2 = -2 * std::pow(_source_pose[2], Scalar(2));
  const Scalar _tmp3 = 1 - 2 * std::pow(_source_pose[1], Scalar(2));
  const Scalar _tmp4 = -source_calibration_storage(2, 0) + source_pixel(0, 0);
  const Scalar _tmp5 = -source_calibration_storage(3, 0) + source_pixel(1, 0);
  const Scalar _tmp6 =
      std::pow(_tmp5, Scalar(2)) / std::pow(source_calibration_storage(1, 0), Scalar(2));
  const Scalar _tmp7 =
      std::pow(_tmp4, Scalar(2)) / std::pow(source_calibration_storage(0, 0), Scalar(2));
  const Scalar _tmp8 = _tmp6 + _tmp7 + epsilon;
  const Scalar _tmp9 = std::sqrt(_tmp8);
  const Scalar _tmp10 = _tmp9 * source_calibration_storage(4, 0);
  const Scalar _tmp11 = std::tan(_tmp10);
  const Scalar _tmp12 = std::tan(Scalar(0.5) * source_calibration_storage(4, 0));
  const Scalar _tmp13 =
      (Scalar(1) / Scalar(4)) * std::pow(_tmp11, Scalar(2)) / (std::pow(_tmp12, Scalar(2)) * _tmp8);
  const Scalar _tmp14 =
      std::pow(Scalar(_tmp13 * _tmp6 + _tmp13 * _tmp7 + 1), Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp15 = (Scalar(1) / Scalar(2)) * _tmp11 * _tmp14 / (_tmp12 * _tmp9);
  const Scalar _tmp16 = _tmp15 * _tmp4 / source_calibration_storage(0, 0);
  const Scalar _tmp17 = 2 * _source_pose[0] * _source_pose[2];
  const Scalar _tmp18 = 2 * _source_pose[3];
  const Scalar _tmp19 = _source_pose[1] * _tmp18;
  const Scalar _tmp20 = 2 * _source_pose[1];
  const Scalar _tmp21 = _source_pose[0] * _tmp20;
  const Scalar _tmp22 = _source_pose[2] * _tmp18;
  const Scalar _tmp23 = _tmp15 * _tmp5 / source_calibration_storage(1, 0);
  const Scalar _tmp24 = _tmp14 * (_tmp17 + _tmp19) + _tmp16 * (_tmp2 + _tmp3) +
                        _tmp23 * (_tmp21 - _tmp22) +
                        source_inverse_range * (_source_pose[4] - _target_pose[4]);
  const Scalar _tmp25 = 2 * _target_pose[2];
  const Scalar _tmp26 = _target_pose[3] * _tmp25;
  const Scalar _tmp27 = 2 * _target_pose[1];
  const Scalar _tmp28 = _target_pose[0] * _tmp27;
  const Scalar _tmp29 = -2 * std::pow(_source_pose[0], Scalar(2));
  const Scalar _tmp30 = _source_pose[0] * _tmp18;
  const Scalar _tmp31 = _source_pose[2] * _tmp20;
  const Scalar _tmp32 = _tmp14 * (-_tmp30 + _tmp31) + _tmp16 * (_tmp21 + _tmp22) +
                        _tmp23 * (_tmp2 + _tmp29 + 1) +
                        source_inverse_range * (_source_pose[5] - _target_pose[5]);
  const Scalar _tmp33 = _target_pose[0] * _tmp25;
  const Scalar _tmp34 = _target_pose[3] * _tmp27;
  const Scalar _tmp35 = _tmp14 * (_tmp29 + _tmp3) + _tmp16 * (_tmp17 - _tmp19) +
                        _tmp23 * (_tmp30 + _tmp31) +
                        source_inverse_range * (_source_pose[6] - _target_pose[6]);
  const Scalar _tmp36 =
      _tmp24 * (_tmp0 + _tmp1) + _tmp32 * (_tmp26 + _tmp28) + _tmp35 * (_tmp33 - _tmp34);
  const Scalar _tmp37 = _target_pose[2] * _tmp27;
  const Scalar _tmp38 = 2 * _target_pose[0] * _target_pose[3];
  const Scalar _tmp39 = -2 * std::pow(_target_pose[0], Scalar(2));
  const Scalar _tmp40 =
      _tmp24 * (_tmp33 + _tmp34) + _tmp32 * (_tmp37 - _tmp38) + _tmp35 * (_tmp1 + _tmp39);
  const Scalar _tmp41 = std::max<Scalar>(epsilon, std::fabs(_tmp40));
  const Scalar _tmp42 = std::pow(_tmp41, Scalar(-2));
  const Scalar _tmp43 =
      _tmp24 * (-_tmp26 + _tmp28) + _tmp32 * (_tmp0 + _tmp39 + 1) + _tmp35 * (_tmp37 + _tmp38);
  const Scalar _tmp44 = std::sqrt(Scalar(std::pow(_tmp36, Scalar(2)) * _tmp42 +
                                         _tmp42 * std::pow(_tmp43, Scalar(2)) + epsilon));
  const Scalar _tmp45 =
      std::atan(2 * _tmp44 * std::tan(Scalar(0.5) * target_calibration_storage(4, 0))) /
      (_tmp41 * _tmp44 * target_calibration_storage(4, 0));

  // Output terms (2)
  if (reprojection_delta != nullptr) {
    Eigen::Matrix<Scalar, 2, 1>& _reprojection_delta = (*reprojection_delta);

    _reprojection_delta(0, 0) = _tmp36 * _tmp45 * target_calibration_storage(0, 0) +
                                target_calibration_storage(2, 0) - target_pixel(0, 0);
    _reprojection_delta(1, 0) = _tmp43 * _tmp45 * target_calibration_storage(1, 0) +
                                target_calibration_storage(3, 0) - target_pixel(1, 0);
  }

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(0, (((_tmp40) > 0) - ((_tmp40) < 0))) *
                std::max<Scalar>(0, (((-std::fabs(_tmp10) + Scalar(M_PI_2)) > 0) -
                                     ((-std::fabs(_tmp10) + Scalar(M_PI_2)) < 0)));
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
