#ifndef FIXED_POINT_HPP
#define FIXED_POINT_HPP

#include <cstdint>
#include <type_traits>

#define INTEGRAL_ASSIGN(V) ((uintmax_t)V << Point)
#define FLOAT_ASSIGN(V) (V * (1 << Point))

template<typename I, const unsigned Point>
struct fixed {
	using integral_type = I;
	using this_type = fixed<I, Point>;

	// make sure out integral type is actually an integral type
	static_assert(std::is_integral<I>::value, "integral type must be an integral type");
	// make sure the type is signed
	static_assert(std::is_signed<I>::value, "integral type must be signed");
	// make sure the decimal point exists within the integral type
	static_assert(Point < sizeof(I) * 8, "point must be within integral type");
	// TODO: make sure the fixed type is the size of its integral type
	// static_assert(sizeof(fixed<I, Point>) == sizeof(I), "fixed type must have same size as its integral type");

	constexpr inline fixed() noexcept: value(0) {}

	// TODO: requires is_arithmetic. could I make all fixed types arithmetic?
	template<typename T>
	constexpr inline fixed(T v) noexcept {
		static_assert(std::is_arithmetic<T>::value, "constructor requires arithmetic type");

		if (std::is_integral<T>::value)
			value = (integral_type) INTEGRAL_ASSIGN(v);
		else if (std::is_floating_point<T>::value)
			value = (integral_type) FLOAT_ASSIGN(v);
		// else: unreachable, see static_assert
	}

	// TODO: commutative operators (==, !=)
	// TODO: math operators (+, -, *, /)
	// TODO: specialize common operations like square root

	template <typename T>
	constexpr inline bool operator==(const T &o) const noexcept {
		return operator==(this_type(o));
	}

	constexpr inline bool operator==(const this_type &o) const noexcept {
		return value == o.value;
	}

	template <typename T>
	constexpr inline bool operator!=(const T &o) const noexcept {
		return !operator==(o);
	}

	template <typename T>
	constexpr inline operator T() const noexcept {
		static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, "fixed cast must have integral or floating point type");

		if (std::is_integral<T>::value)
			return value >> Point;
		else if (std::is_floating_point<T>::value)
			return value / T(1 << Point);
	}

	constexpr inline this_type integral() const noexcept {
		// clear bits below point
		this_type f;
		f.value = value & ~((integral_type(1) << Point) - 1);
		return f;
	}

	constexpr inline this_type fractional() const noexcept {
		// clear bits above point
		this_type f;
		f.value = value & ((integral_type(1) << Point) - 1);
		return f;
	}

private:
	integral_type value;
};

#undef INTEGRAL_ASSIGN
#undef FLOAT_ASSIGN

typedef fixed<int8_t, 4> fixed8_t;
typedef fixed<int16_t, 8> fixed16_t;
typedef fixed<int32_t, 16> fixed32_t;
typedef fixed<int64_t, 32> fixed64_t;

#endif
