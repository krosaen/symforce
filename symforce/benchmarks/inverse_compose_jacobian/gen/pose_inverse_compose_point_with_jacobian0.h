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
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: pose_inverse_compose_point
 *
 * Args:
 *     pose: Pose3
 *     point: Matrix31
 *
 * Outputs:
 *     res: Matrix31
 *     res_D_pose: (3x6) jacobian of res (3) wrt arg pose (6)
 */
template <typename Scalar>
__attribute__((noinline)) Eigen::Matrix<Scalar, 3, 1> PoseInverseComposePointWithJacobian0(
    const sym::Pose3<Scalar>& pose, const Eigen::Matrix<Scalar, 3, 1>& point,
    Eigen::Matrix<Scalar, 3, 6>* const res_D_pose = nullptr) {
  // Total ops: 91

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _pose = pose.Data();

  // Intermediate terms (39)
  const Scalar _tmp0 = 2 * _pose[1];
  const Scalar _tmp1 = _pose[3] * _tmp0;
  const Scalar _tmp2 = 2 * _pose[2];
  const Scalar _tmp3 = _pose[0] * _tmp2;
  const Scalar _tmp4 = _tmp1 - _tmp3;
  const Scalar _tmp5 = _tmp4 * point(2, 0);
  const Scalar _tmp6 = _pose[3] * _tmp2;
  const Scalar _tmp7 = _pose[0] * _tmp0;
  const Scalar _tmp8 = _tmp6 + _tmp7;
  const Scalar _tmp9 = _pose[5] * _tmp8;
  const Scalar _tmp10 = _tmp8 * point(1, 0);
  const Scalar _tmp11 = _pose[6] * _tmp4;
  const Scalar _tmp12 = std::pow(_pose[1], Scalar(2));
  const Scalar _tmp13 = 2 * _tmp12;
  const Scalar _tmp14 = std::pow(_pose[2], Scalar(2));
  const Scalar _tmp15 = 2 * _tmp14 - 1;
  const Scalar _tmp16 = _tmp13 + _tmp15;
  const Scalar _tmp17 = std::pow(_pose[0], Scalar(2));
  const Scalar _tmp18 = 2 * _tmp17;
  const Scalar _tmp19 = _tmp15 + _tmp18;
  const Scalar _tmp20 = _tmp6 - _tmp7;
  const Scalar _tmp21 = 2 * _pose[0] * _pose[3];
  const Scalar _tmp22 = _pose[1] * _tmp2;
  const Scalar _tmp23 = _tmp21 + _tmp22;
  const Scalar _tmp24 =
      -_pose[4] * _tmp20 + _pose[6] * _tmp23 + _tmp20 * point(0, 0) - _tmp23 * point(2, 0);
  const Scalar _tmp25 = _tmp13 + _tmp18 - 1;
  const Scalar _tmp26 = _tmp1 + _tmp3;
  const Scalar _tmp27 = _tmp21 - _tmp22;
  const Scalar _tmp28 =
      -_pose[4] * _tmp26 + _pose[5] * _tmp27 + _tmp26 * point(0, 0) - _tmp27 * point(1, 0);
  const Scalar _tmp29 = -_tmp12;
  const Scalar _tmp30 = std::pow(_pose[3], Scalar(2));
  const Scalar _tmp31 = -_tmp17 + _tmp30;
  const Scalar _tmp32 = _tmp14 + _tmp29 + _tmp31;
  const Scalar _tmp33 = -_pose[6] * _tmp32 + _tmp28 + _tmp32 * point(2, 0);
  const Scalar _tmp34 = -_tmp14;
  const Scalar _tmp35 = _tmp12 + _tmp31 + _tmp34;
  const Scalar _tmp36 = _pose[5] * _tmp35 + _tmp24 - _tmp35 * point(1, 0);
  const Scalar _tmp37 = _tmp17 + _tmp29 + _tmp30 + _tmp34;
  const Scalar _tmp38 = -_pose[4] * _tmp37 + _tmp10 + _tmp11 + _tmp37 * point(0, 0) - _tmp5 - _tmp9;

  // Output terms (2)
  Eigen::Matrix<Scalar, 3, 1> _res;

  _res(0, 0) = _pose[4] * _tmp16 + _tmp10 + _tmp11 - _tmp16 * point(0, 0) - _tmp5 - _tmp9;
  _res(1, 0) = _pose[5] * _tmp19 - _tmp19 * point(1, 0) - _tmp24;
  _res(2, 0) = _pose[6] * _tmp25 - _tmp25 * point(2, 0) + _tmp28;

  if (res_D_pose != nullptr) {
    Eigen::Matrix<Scalar, 3, 6>& _res_D_pose = (*res_D_pose);

    _res_D_pose(0, 0) = 0;
    _res_D_pose(0, 1) = -_tmp33;
    _res_D_pose(0, 2) = -_tmp36;
    _res_D_pose(0, 3) = _tmp16;
    _res_D_pose(0, 4) = -_tmp8;
    _res_D_pose(0, 5) = _tmp4;
    _res_D_pose(1, 0) = _tmp33;
    _res_D_pose(1, 1) = 0;
    _res_D_pose(1, 2) = -_tmp38;
    _res_D_pose(1, 3) = _tmp20;
    _res_D_pose(1, 4) = _tmp19;
    _res_D_pose(1, 5) = -_tmp23;
    _res_D_pose(2, 0) = _tmp36;
    _res_D_pose(2, 1) = _tmp38;
    _res_D_pose(2, 2) = 0;
    _res_D_pose(2, 3) = -_tmp26;
    _res_D_pose(2, 4) = _tmp27;
    _res_D_pose(2, 5) = _tmp25;
  }

  return _res;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
