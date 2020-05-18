//  ----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./group_ops.h"

namespace geo {
namespace pose3 {

template <typename Scalar>
Pose3<Scalar> GroupOps<Scalar>::Identity() {
    // Input arrays

    // Output array
    Eigen::Matrix<Scalar, 7, 1> res;

    // Intermediate terms (0)

    // Output terms (7)
    res[0] = 0;
    res[1] = 0;
    res[2] = 0;
    res[3] = 1;
    res[4] = 0;
    res[5] = 0;
    res[6] = 0;

    return Pose3<Scalar>(res);
}

template <typename Scalar>
Pose3<Scalar> GroupOps<Scalar>::Inverse(const Pose3<Scalar>& a) {
    // Input arrays
    const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();

    // Output array
    Eigen::Matrix<Scalar, 7, 1> res;

    // Intermediate terms (11)
    const Scalar _tmp0 = 2*_a[1];
    const Scalar _tmp1 = _a[3]*_tmp0;
    const Scalar _tmp2 = 2*_a[0]*_a[2];
    const Scalar _tmp3 = 2*_a[3];
    const Scalar _tmp4 = _a[2]*_tmp3;
    const Scalar _tmp5 = _a[0]*_tmp0;
    const Scalar _tmp6 = -2*(_a[2] * _a[2]);
    const Scalar _tmp7 = -2*(_a[1] * _a[1]);
    const Scalar _tmp8 = _a[0]*_tmp3;
    const Scalar _tmp9 = _a[2]*_tmp0;
    const Scalar _tmp10 = -2*(_a[0] * _a[0]) + 1;

    // Output terms (7)
    res[0] = -_a[0];
    res[1] = -_a[1];
    res[2] = -_a[2];
    res[3] = _a[3];
    res[4] = -_a[4]*(_tmp6 + _tmp7 + 1) - _a[5]*(_tmp4 + _tmp5) - _a[6]*(-_tmp1 + _tmp2);
    res[5] = -_a[4]*(-_tmp4 + _tmp5) - _a[5]*(_tmp10 + _tmp6) - _a[6]*(_tmp8 + _tmp9);
    res[6] = -_a[4]*(_tmp1 + _tmp2) - _a[5]*(-_tmp8 + _tmp9) - _a[6]*(_tmp10 + _tmp7);

    return Pose3<Scalar>(res);
}

template <typename Scalar>
Pose3<Scalar> GroupOps<Scalar>::Compose(const Pose3<Scalar>& a, const Pose3<Scalar>& b) {
    // Input arrays
    const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
    const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

    // Output array
    Eigen::Matrix<Scalar, 7, 1> res;

    // Intermediate terms (11)
    const Scalar _tmp0 = 2*_a[1]*_a[3];
    const Scalar _tmp1 = 2*_a[2];
    const Scalar _tmp2 = _a[0]*_tmp1;
    const Scalar _tmp3 = _a[3]*_tmp1;
    const Scalar _tmp4 = 2*_a[0];
    const Scalar _tmp5 = _a[1]*_tmp4;
    const Scalar _tmp6 = -2*(_a[2] * _a[2]);
    const Scalar _tmp7 = -2*(_a[1] * _a[1]) + 1;
    const Scalar _tmp8 = _a[3]*_tmp4;
    const Scalar _tmp9 = _a[1]*_tmp1;
    const Scalar _tmp10 = -2*(_a[0] * _a[0]);

    // Output terms (7)
    res[0] = _a[0]*_b[3] + _a[1]*_b[2] - _a[2]*_b[1] + _a[3]*_b[0];
    res[1] = -_a[0]*_b[2] + _a[1]*_b[3] + _a[2]*_b[0] + _a[3]*_b[1];
    res[2] = _a[0]*_b[1] - _a[1]*_b[0] + _a[2]*_b[3] + _a[3]*_b[2];
    res[3] = -_a[0]*_b[0] - _a[1]*_b[1] - _a[2]*_b[2] + _a[3]*_b[3];
    res[4] = _a[4] + _b[4]*(_tmp6 + _tmp7) + _b[5]*(-_tmp3 + _tmp5) + _b[6]*(_tmp0 + _tmp2);
    res[5] = _a[5] + _b[4]*(_tmp3 + _tmp5) + _b[5]*(_tmp10 + _tmp6 + 1) + _b[6]*(-_tmp8 + _tmp9);
    res[6] = _a[6] + _b[4]*(-_tmp0 + _tmp2) + _b[5]*(_tmp8 + _tmp9) + _b[6]*(_tmp10 + _tmp7);

    return Pose3<Scalar>(res);
}

template <typename Scalar>
Pose3<Scalar> GroupOps<Scalar>::Between(const Pose3<Scalar>& a, const Pose3<Scalar>& b) {
    // Input arrays
    const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
    const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

    // Output array
    Eigen::Matrix<Scalar, 7, 1> res;

    // Intermediate terms (20)
    const Scalar _tmp0 = 2*_a[3];
    const Scalar _tmp1 = _a[1]*_tmp0;
    const Scalar _tmp2 = 2*_a[2];
    const Scalar _tmp3 = _a[0]*_tmp2;
    const Scalar _tmp4 = -_tmp1 + _tmp3;
    const Scalar _tmp5 = _a[3]*_tmp2;
    const Scalar _tmp6 = 2*_a[0]*_a[1];
    const Scalar _tmp7 = _tmp5 + _tmp6;
    const Scalar _tmp8 = -2*(_a[1] * _a[1]);
    const Scalar _tmp9 = -2*(_a[2] * _a[2]) + 1;
    const Scalar _tmp10 = _tmp8 + _tmp9;
    const Scalar _tmp11 = _a[0]*_tmp0;
    const Scalar _tmp12 = _a[1]*_tmp2;
    const Scalar _tmp13 = _tmp11 + _tmp12;
    const Scalar _tmp14 = -2*(_a[0] * _a[0]);
    const Scalar _tmp15 = _tmp14 + _tmp9;
    const Scalar _tmp16 = -_tmp5 + _tmp6;
    const Scalar _tmp17 = _tmp14 + _tmp8 + 1;
    const Scalar _tmp18 = -_tmp11 + _tmp12;
    const Scalar _tmp19 = _tmp1 + _tmp3;

    // Output terms (7)
    res[0] = -_a[0]*_b[3] - _a[1]*_b[2] + _a[2]*_b[1] + _a[3]*_b[0];
    res[1] = _a[0]*_b[2] - _a[1]*_b[3] - _a[2]*_b[0] + _a[3]*_b[1];
    res[2] = -_a[0]*_b[1] + _a[1]*_b[0] - _a[2]*_b[3] + _a[3]*_b[2];
    res[3] = _a[0]*_b[0] + _a[1]*_b[1] + _a[2]*_b[2] + _a[3]*_b[3];
    res[4] = -_a[4]*_tmp10 - _a[5]*_tmp7 - _a[6]*_tmp4 + _b[4]*_tmp10 + _b[5]*_tmp7 + _b[6]*_tmp4;
    res[5] = -_a[4]*_tmp16 - _a[5]*_tmp15 - _a[6]*_tmp13 + _b[4]*_tmp16 + _b[5]*_tmp15 + _b[6]*_tmp13;
    res[6] = -_a[4]*_tmp19 - _a[5]*_tmp18 - _a[6]*_tmp17 + _b[4]*_tmp19 + _b[5]*_tmp18 + _b[6]*_tmp17;

    return Pose3<Scalar>(res);
}


}  // namespace pose3
}  // namespace geo

// Explicit instantiation
template struct geo::pose3::GroupOps<double>;
template struct geo::pose3::GroupOps<float>;
