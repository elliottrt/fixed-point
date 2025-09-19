#include "fixed_point.hpp"
#include "test.hpp"

test_case {
	fixed32_t f = 0;
	test(f.integral() == 0);
	test(f.fractional() == 0);

	f = 5.5;
	test(f.integral() == 5);
	test(f.fractional() == 0.5);

	f = (int) f;
	test(f.integral() == 5);
	test(f.fractional() == 0);
}
