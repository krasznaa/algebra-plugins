/** Algebra plugins, part of the ACTS project
 *
 * (c) 2023 CERN for the benefit of the ACTS project
 *
 * Mozilla Public License Version 2.0
 */
#pragma once

// Project include(s)
#include "algebra/concepts.hpp"
#include "algebra/qualifiers.hpp"

// System include(s).
#include <cstddef>
#include <type_traits>

namespace algebra::storage {

/// @name Operators on N-element arrays
/// @{
template <template <typename, std::size_t> class array_t,
          concepts::scalar scalar_t, std::size_t N>
ALGEBRA_HOST_DEVICE constexpr array_t<scalar_t, N> operator*(
    const array_t<scalar_t, N> &a, scalar_t s) noexcept {

  array_t<scalar_t, N> result;
  for (std::size_t i = 0u; i < N; ++i) {
    result[i] = a[i] * s;
  }

  return result;
}

template <template <typename, std::size_t> class array_t,
          concepts::scalar scalar_t, std::size_t N>
ALGEBRA_HOST_DEVICE constexpr array_t<scalar_t, N> operator*(
    scalar_t s, const array_t<scalar_t, N> &a) noexcept {

  array_t<scalar_t, N> result;
  for (std::size_t i = 0u; i < N; ++i) {
    result[i] = s * a[i];
  }

  return result;
}

template <template <typename, std::size_t> class array_t,
          concepts::scalar scalar_t, std::size_t N>
ALGEBRA_HOST_DEVICE constexpr array_t<scalar_t, N> operator-(
    const array_t<scalar_t, N> &a, const array_t<scalar_t, N> &b) noexcept {

  array_t<scalar_t, N> result;
  for (std::size_t i = 0u; i < N; ++i) {
    result[i] = a[i] - b[i];
  }

  return result;
}

template <template <typename, std::size_t> class array_t,
          concepts::scalar scalar_t, std::size_t N>
ALGEBRA_HOST_DEVICE constexpr array_t<scalar_t, N> operator+(
    const array_t<scalar_t, N> &a, const array_t<scalar_t, N> &b) noexcept {

  array_t<scalar_t, N> result;
  for (std::size_t i = 0u; i < N; ++i) {
    result[i] = a[i] + b[i];
  }

  return result;
}

template <template <typename, std::size_t> class array_t,
          concepts::scalar scalar_t, std::size_t N>
ALGEBRA_HOST_DEVICE constexpr array_t<scalar_t, N> operator*(
    const array_t<scalar_t, N> &a, const array_t<scalar_t, N> &b) noexcept {

  array_t<scalar_t, N> result;
  for (std::size_t i = 0u; i < N; ++i) {
    result[i] = a[i] * b[i];
  }

  return result;
}

template <template <typename, std::size_t> class array_t,
          concepts::scalar scalar_t, std::size_t N>
ALGEBRA_HOST_DEVICE constexpr array_t<scalar_t, N> operator/(
    const array_t<scalar_t, N> &a, const array_t<scalar_t, N> &b) noexcept {

  array_t<scalar_t, N> result;
  for (std::size_t i = 0u; i < N; ++i) {
    result[i] = a[i] / b[i];
  }

  return result;
}
/// @}

}  // namespace algebra::storage
