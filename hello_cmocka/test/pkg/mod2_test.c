/**
 * Module de test du module pkg/mod2.c
 *
 */
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"


#include "pkg/mod2.c"


static int set_up(void **state) {
	return 0;
}

static int tear_down(void **state) {
	return 0;
}

/**
 * Fonction de test de la fonction mod2_fct2
 *
 */
static void test_mod2_fct2(void **state) {
	int dt = 1, val, expected_val = 4, expected_res = 30;

	int res = mod2_fct2(dt, &val);

	assert_int_equal(expected_val, val);
	assert_int_equal(expected_res, res);
}

/**
 * Suite de test pour le module.
 *
 * A compléter si besoin est.
 *
 */
static const struct CMUnitTest tests[] =
{
	cmocka_unit_test(test_mod2_fct2)
};



/**
 * Lancement de la suite de tests pour le module.
 */
int mod2_run_tests()
{
	return cmocka_run_group_tests_name("Test du module mod1", tests, set_up, tear_down);
}


