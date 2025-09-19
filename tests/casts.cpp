#include "fixed_point.hpp"
#include "test.hpp"

test_case {
	fixed8_t f8;
	test((int) f8 == 0);
	test((uint8_t) f8 == 0);
	test((float) f8 == 0.0f);

	f8 = 5;
	test((int) f8 == 5);
	test((uint8_t) f8 == 5);
	test((float) f8 == 5.0f);

	f8 = -5;
	test((int) f8 == -5);
	test((int8_t) f8 == -5);
	test((float) f8 == -5.0f);

	f8 = 5.5f;
	test((int) f8 == 5);
	test((int8_t) f8 == 5);
	test((float) f8 == 5.5f);

	f8 = 0.5f;
	test((int) f8 == 0);
	test((int8_t) f8 == 0);
	test((float) f8 == 0.5f);
}
