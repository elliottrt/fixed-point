#ifndef FIXED_POINT_TEST_HPP
#define FIXED_POINT_TEST_HPP

#include <cstdlib>
#include <cstdio>

#define test(COND) \
    do { if (!(COND)) { \
            result = EXIT_FAILURE; \
            fprintf(stderr, "%s:%d: test failed: %s\n", __FILE__, __LINE__, #COND); \
        } \
    } while (0)

#define test_case \
    int result = EXIT_SUCCESS; \
    void do_test(void); \
    int main(void) { \
        do_test(); \
        return result; \
    } \
    void do_test()

#endif
