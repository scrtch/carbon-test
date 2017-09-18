#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "func.h"


static void test_first_null_arg(void **state)
{
	int rv = func(0, 55);
	(void) state;
	assert_int_equal(rv, -1);
}

static void test_second_null_arg(void **state)
{
	int rv = func(22, 0);
	(void) state;
	assert_int_equal(rv, -2);
}

static void test_non_null_args(void **state)
{
	int rv = func(2, 5);
	(void) state;
	assert_int_equal(rv, 3);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_first_null_arg),
		cmocka_unit_test(test_second_null_arg),
		cmocka_unit_test(test_non_null_args),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
