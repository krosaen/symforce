// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/ops/CLASS/storage_ops.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./storage_ops.h"

#include <algorithm>

#include <Eigen/Dense>

#include <sym/linear_camera_cal.h>

namespace sym {

template <typename ScalarType>
void StorageOps<LinearCameraCal<ScalarType>>::ToStorage(const LinearCameraCal<ScalarType>& a,
                                                        ScalarType* out) {
  assert(out != nullptr);
  std::copy_n(a.Data().data(), a.StorageDim(), out);
}

template <typename ScalarType>
LinearCameraCal<ScalarType> StorageOps<LinearCameraCal<ScalarType>>::FromStorage(
    const ScalarType* data) {
  assert(data != nullptr);
  return LinearCameraCal<ScalarType>(
      Eigen::Map<const typename LinearCameraCal<ScalarType>::DataVec>(data));
}

}  // namespace sym

// Explicit instantiation
template struct sym::StorageOps<sym::LinearCameraCal<double>>;
template struct sym::StorageOps<sym::LinearCameraCal<float>>;
