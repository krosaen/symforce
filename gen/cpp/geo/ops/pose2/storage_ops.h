//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <vector>
#include <Eigen/Dense>

#include <geo/pose2.h>

namespace geo {
namespace pose2 {

/**
 * C++ StorageOps implementation for <class 'symforce.geo.pose2.Pose2'>.
 */
template <typename ScalarType>
struct StorageOps {
  using Scalar = typename geo::Pose2<ScalarType>::Scalar;

  static constexpr int32_t StorageDim() {
    return 4;
  }

  static void ToStorage(const geo::Pose2<ScalarType>& a, ScalarType* out);
  static geo::Pose2<ScalarType> FromStorage(const ScalarType* data);
};

}  // namespace pose2

// Wrapper to specialize the public concept
template <>
struct StorageOps<Pose2<double>> : public pose2::StorageOps<double> {};
template <>
struct StorageOps<Pose2<float>> : public pose2::StorageOps<float> {};

}  // namespace geo