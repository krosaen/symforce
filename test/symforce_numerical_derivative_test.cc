#include <Eigen/Dense>
#include <symforce/opt/util.h>

// TODO(hayk): Use the catch unit testing framework (single header).
#define assertTrue(a)                                      \
  if (!(a)) {                                              \
    std::ostringstream o;                                  \
    o << __FILE__ << ":" << __LINE__ << ": Test failure."; \
    throw std::runtime_error(o.str());                     \
  }

int main(int argc, char** argv) {
  using BigMatrix = Eigen::Matrix<double, 42, 1>;
  const auto identity_function = [](const BigMatrix& m) -> BigMatrix { return m; };
  const Eigen::Matrix<double, 42, 42> jacobian =
      sym::NumericalDerivative(identity_function, BigMatrix::Zero().eval());

  assertTrue(jacobian.isApprox(Eigen::Matrix<double, 42, 42>::Identity(), 1e-10));
}
