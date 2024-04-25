/**
 * ALGEBRA PLUGIN library, part of the ACTS project (R&D line)
 *
 * (c) 2024 CERN for the benefit of the ACTS project
 *
 * Mozilla Public License Version 2.0
 */

#pragma once

// Local include(s).
#include "algebra/qualifiers.hpp"

// System include(s).
#include <cstdlib>

namespace algebra {

/// Type meant to make it easier to declare scalar literals in the code
///
/// To be able to declare float or double literals in the (test) code, without
/// writing an excessive amount of code, this helper type can be used. It stores
/// an FP64 value internally, which it can return as FP32 or FP64,
/// depending on the context. (It doesn't use "long double", because that
/// doesn't generally work in device code.)
///
class scalar {

 public:
  /// Constructor from a double
  ALGEBRA_HOST_DEVICE inline constexpr scalar(double value) : m_value(value) {}

  /// Conversion to double
  ALGEBRA_HOST_DEVICE
  inline constexpr operator double() const { return m_value; }

  /// Conversion to float
  ALGEBRA_HOST_DEVICE
  inline constexpr operator float() const {
    return static_cast<float>(m_value);
  }

  /// Helper function for creating a "zero" scalar
  ALGEBRA_HOST_DEVICE
  inline static constexpr scalar zero() { return scalar{0.}; }

  /// Helper function for creating a "one" scalar
  ALGEBRA_HOST_DEVICE
  inline static constexpr scalar one() { return scalar{1.}; }

 private:
  /// The stored value
  double m_value = 0.0;

};  // class scalar

/// Helper operator to create a scalar from a double literal
ALGEBRA_HOST_DEVICE
inline constexpr scalar operator"" _sc(long double value) {
  return scalar{static_cast<double>(value)};
}

}  // namespace algebra
