/**
 * Module de test du module pkg/mod1.c
 *
 */
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"


#include "pkg/mod1.c"


static int set_up(void **state) {
	return 0;
}

static int tear_down(void **state) {
	return 0;
}

/**
 * Fonction de test de la fonction mod1_fct0
 *
 */
static void test_mod1_fct0(void **state) {
	int expected_result = 10, dt = 1;

	int res = mod1_fct0(dt);

	assert_int_equal(expected_result,res);
}

/**
 * Fonction de test de la fonction mod1_fct_st0
 */
static void test_mod1_fct_st0(void **state) {
	int expected_result = 11, dt = 1, expected_att = 2;

	int res = mod1_fct_st0(dt);

	assert_int_equal(expected_att, mod1_att_st0);
	assert_int_equal(expected_result, res);
}

/**
 * Fonction de test de la fonction mod1_fct1
 */
static void test_mod1_fct1(void **state)
{
	//Valeurs bouchonnées dans __wrap_mod2_fct1, pour l'affectation et le retour.
	int mock_aff = 3, mock_ret = 20;
	//Valeurs d'injection, de retour.
	int expected_result = 21, dt = 1, expected_att = mock_aff;

	//Verif appel function.
	expect_function_call(__wrap_mod2_fct1);

	//Verif parametre d’appel.
	expect_value(__wrap_mod2_fct1, p, dt);

	//Def valeur d'affectation bouchonnee.
	will_return(__wrap_mod2_fct1,expected_att);
	//Def valeur retour bouchonnee.
	will_return(__wrap_mod2_fct1, mock_ret);

	int res = mod1_fct1(dt);

	assert_int_equal(expected_att, mod1_att0);
	assert_int_equal(expected_result, res);
}

/**
 * Fonction de test de la fonction mod1_fct2
 */
static void test_mod1_fct2(void **state)
{
	//Valeurs bouchonnées dans __wrap_mod2_fct2, pour le retour.
	int mock_ret = 30, mock_aff = 2;
	//Valeurs d'injection, de retour.
	int dt = 1, v, expected_resultat = 32, expected_value = mock_aff;

	expect_function_call(__wrap_mod2_fct2);

	expect_value(__wrap_mod2_fct2, p, dt);

	expect_value(__wrap_mod2_fct2,pt, &v);

	will_return(__wrap_mod2_fct2,mock_aff);

	will_return(__wrap_mod2_fct2, mock_ret);

	int res = mod1_fct2(dt, &v);

	assert_int_equal(expected_value,v);
	assert_int_equal(expected_resultat,res);
}
/**
 * Fonction de test de la fonction mod1_fct3
 */
static void test_mod1_fct3(void **state)
{
	//Valeurs bouchonnées dans __wrap_mod1_fct4, pour le retour.
	int mock_ret = 40;
	//Valaurs d'injection, de retour.
	int dt = 1, expected_result = 43;

	#ifdef _WRAP_MOD1_FCT4
	expect_function_call(__wrap_mod1_fct4);

	expect_value(__wrap_mod1_fct4, p, dt);

	will_return(__wrap_mod1_fct4, mock_ret);
	#endif

	int res = mod1_fct3(dt);

	assert_int_equal(expected_result, res);
}

/**
 * Fonction de test de la fonction mod1_fct5
 */
static void test_mod1_fct5(void **state)
{
	//Valeurs bouchonnées dans __wrap_mod1_fct_st1 pour le retour.
	int mock_ret = 50;
	//Valeurs d'injection, de retour.
	int dt =1, expected_result = 55;

#ifdef _WRAP_MOD1_FCT_ST1
	expect_function_call(__wrap_mod1_fct_st1);

	expect_value(__wrap_mod1_fct_st1, p, dt);

	will_return(__wrap_mod1_fct_st1, mock_ret);
#endif

	int res = mod1_fct5(dt);

	assert_int_equal(expected_result, res);
}

/**
 * Fonction de test de la fonction mod1_fct5_bis
 */
static void test_mod1_fct5_bis(void **state)
{
	//Valeurs bouchonnées dans __wrap_mod1_fct_st1_bis pour le retour.
	int mock_ret = 50;
	//Valeurs d'injection, de retour.
	int dt =1, expected_result = 55;

#ifdef _MOCK_PERSO_MOD1_FCT_ST1
	expect_function_call(_mock_perso_mod1_fct_st1_bis);

	expect_value(_mock_perso_mod1_fct_st1_bis, p, dt);

	will_return(_mock_perso_mod1_fct_st1_bis, mock_ret);
#endif

	int res = mod1_fct5_bis(dt);

	assert_int_equal(expected_result, res);

}

/**
 * Suite de test pour le module.
 *
 * A compléter si besoin est.
 *
 */
static const struct CMUnitTest tests[] = 
{
	cmocka_unit_test(test_mod1_fct0),
	cmocka_unit_test(test_mod1_fct_st0),
	cmocka_unit_test(test_mod1_fct1),
	cmocka_unit_test(test_mod1_fct2),
	cmocka_unit_test(test_mod1_fct3),
	cmocka_unit_test(test_mod1_fct5),
	cmocka_unit_test(test_mod1_fct5_bis)
};



/**
 * Lancement de la suite de tests pour le module.
 */
int mod1_run_tests() 
{
	return cmocka_run_group_tests_name("Test du module mod1", tests, set_up, tear_down);
}


