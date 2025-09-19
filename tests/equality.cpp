#include "fixed_point.hpp"
#include "test.hpp"

test_case {
	fixed32_t f0 = 5;
	fixed32_t f1 = 5;

	test(f0 == 5);
	test(f0 == f1);
	test(f0 == f0);

	f1 = 5.5;
	test(f0 != f1);
	test(f1 == 5.5);

	f0 = f1;
	test(f0 == 5.5);
	test(f0 == f1);
}
