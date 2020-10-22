//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>

#include "../storage_ops.h"

namespace geo {
namespace matrix {

/**
 * C++ StorageOps implementation for fixed size matrices.
 */
template <typename ScalarType, int Rows, int Cols>
struct StorageOps {
  using Scalar = ScalarType;
  using T = Eigen::Matrix<Scalar, Rows, Cols>;
  static_assert(std::is_floating_point<ScalarType>::value, "");

  static constexpr int32_t StorageDim() {
    return Rows * Cols;
  }

  static void ToStorage(const T& a, ScalarType* out) {
    assert(out != nullptr);
    std::copy_n(a.data(), a.size(), out);
  }

  static T FromStorage(const ScalarType* data) {
    assert(data != nullptr);
    return Eigen::Map<const T>(data);
  }
};

}  // namespace matrix

template <>
struct StorageOps<Eigen::Matrix<double, 1, 1>> : public matrix::StorageOps<double, 1, 1> {};
template <>
struct StorageOps<Eigen::Matrix<double, 2, 1>> : public matrix::StorageOps<double, 2, 1> {};
template <>
struct StorageOps<Eigen::Matrix<double, 3, 1>> : public matrix::StorageOps<double, 3, 1> {};
template <>
struct StorageOps<Eigen::Matrix<double, 4, 1>> : public matrix::StorageOps<double, 4, 1> {};
template <>
struct StorageOps<Eigen::Matrix<double, 5, 1>> : public matrix::StorageOps<double, 5, 1> {};
template <>
struct StorageOps<Eigen::Matrix<double, 6, 1>> : public matrix::StorageOps<double, 6, 1> {};
template <>
struct StorageOps<Eigen::Matrix<double, 7, 1>> : public matrix::StorageOps<double, 7, 1> {};
template <>
struct StorageOps<Eigen::Matrix<double, 8, 1>> : public matrix::StorageOps<double, 8, 1> {};
template <>
struct StorageOps<Eigen::Matrix<double, 9, 1>> : public matrix::StorageOps<double, 9, 1> {};
template <int Rows, int Cols>
struct StorageOps<Eigen::Matrix<double, Rows, Cols>>
    : public matrix::StorageOps<double, Rows, Cols> {};
template <>
struct StorageOps<Eigen::Matrix<float, 1, 1>> : public matrix::StorageOps<float, 1, 1> {};
template <>
struct StorageOps<Eigen::Matrix<float, 2, 1>> : public matrix::StorageOps<float, 2, 1> {};
template <>
struct StorageOps<Eigen::Matrix<float, 3, 1>> : public matrix::StorageOps<float, 3, 1> {};
template <>
struct StorageOps<Eigen::Matrix<float, 4, 1>> : public matrix::StorageOps<float, 4, 1> {};
template <>
struct StorageOps<Eigen::Matrix<float, 5, 1>> : public matrix::StorageOps<float, 5, 1> {};
template <>
struct StorageOps<Eigen::Matrix<float, 6, 1>> : public matrix::StorageOps<float, 6, 1> {};
template <>
struct StorageOps<Eigen::Matrix<float, 7, 1>> : public matrix::StorageOps<float, 7, 1> {};
template <>
struct StorageOps<Eigen::Matrix<float, 8, 1>> : public matrix::StorageOps<float, 8, 1> {};
template <>
struct StorageOps<Eigen::Matrix<float, 9, 1>> : public matrix::StorageOps<float, 9, 1> {};
template <int Rows, int Cols>
struct StorageOps<Eigen::Matrix<float, Rows, Cols>> : public matrix::StorageOps<float, Rows, Cols> {
};

}  // namespace geo
