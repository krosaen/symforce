// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     matrix_multiplication_benchmark.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

///
/// Experiment to show timing for the matrix multiplication example in the SymForce paper.
///
/// Run with:
///
///     build/bin/benchmarks/matrix_multiplication_benchmark_lp_sc105
///
/// See run_matmul_benchmarks.py for more information
///

#include <chrono>
#include <thread>

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <spdlog/spdlog.h>

#include <symforce/opt/tic_toc.h>
#include <symforce/opt/util.h>

#include "catch.hpp"

using namespace sym;

#include "./lp_sc105_compute_a.h"
#include "./lp_sc105_compute_a_dense.h"
#include "./lp_sc105_compute_a_dense_dynamic.h"
#include "./lp_sc105_compute_at_b.h"
#include "./lp_sc105_compute_b.h"
#include "./lp_sc105_compute_b_dense.h"
#include "./lp_sc105_compute_b_dense_dynamic.h"

template <typename Scalar>
__attribute__((noinline)) Eigen::Matrix<Scalar, 163, 163> LpSc105ComputeDenseFixed(
    const Scalar x0, const Scalar x1) {
  Eigen::Matrix<Scalar, 105, 163> A = LpSc105ComputeADense<Scalar>(x0, x1);
  Eigen::Matrix<Scalar, 105, 163> B = LpSc105ComputeBDense<Scalar>(x0, x1);
  return A.transpose() * B;
}

template <typename Scalar>
__attribute__((noinline)) Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic>
LpSc105ComputeDenseDynamic(const Scalar x0, const Scalar x1) {
  const auto A = LpSc105ComputeADenseDynamic<Scalar>(x0, x1);
  const auto B = LpSc105ComputeBDenseDynamic<Scalar>(x0, x1);
  return A.transpose() * B;
}

template <typename Scalar>
__attribute__((noinline)) Eigen::SparseMatrix<Scalar> LpSc105ComputeSparse(const Scalar x0,
                                                                           const Scalar x1) {
  Eigen::SparseMatrix<Scalar> A = LpSc105ComputeA<Scalar>(x0, x1);
  Eigen::SparseMatrix<Scalar> B = LpSc105ComputeB<Scalar>(x0, x1);
  return A.transpose() * B;
}

// ----------------------------------------------------------------------------
// Test Cases
// ----------------------------------------------------------------------------

TEMPLATE_TEST_CASE("lp_sc105_sparse", "", double, float) {
  using Scalar = TestType;

  std::chrono::milliseconds timespan(100);
  std::this_thread::sleep_for(timespan);

  Scalar sum = 0.0;
  {
    SYM_TIME_SCOPE("lp_sc105_sparse_{}", typeid(Scalar).name());

    for (Scalar x0 = 0.1; x0 < 100.0; x0 += 0.1) {
      for (Scalar x1 = 0.1; x1 < 1.0; x1 += 0.1) {
        auto mat = LpSc105ComputeSparse(x0, x1);
        sum += mat.valuePtr()[0];
      }
    }
  }
}

TEMPLATE_TEST_CASE("lp_sc105_dense_dynamic", "", double, float) {
  using Scalar = TestType;

  std::chrono::milliseconds timespan(100);
  std::this_thread::sleep_for(timespan);

  Scalar sum = 0.0;
  {
    SYM_TIME_SCOPE("lp_sc105_dense_dynamic_{}", typeid(Scalar).name());
    for (Scalar x0 = 0.1; x0 < 100.0; x0 += 0.1) {
      for (Scalar x1 = 0.1; x1 < 1.0; x1 += 0.1) {
        auto mat = LpSc105ComputeDenseDynamic<Scalar>(x0, x1);
        sum += mat(0, 0);
      }
    }
  }
}

TEMPLATE_TEST_CASE("lp_sc105_flattened", "", double, float) {
  using Scalar = TestType;

  std::chrono::milliseconds timespan(100);
  std::this_thread::sleep_for(timespan);

  Scalar sum = 0.0;
  {
    SYM_TIME_SCOPE("lp_sc105_flattened_{}", typeid(Scalar).name());
    for (Scalar x0 = 0.1; x0 < 100.0; x0 += 0.1) {
      for (Scalar x1 = 0.1; x1 < 1.0; x1 += 0.1) {
        auto mat = LpSc105ComputeAtB(x0, x1);
        sum += mat.valuePtr()[0];
      }
    }
  }
}
