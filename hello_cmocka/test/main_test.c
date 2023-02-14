/**
 * \file main_test.c
 *
 */
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Déclaration du nombre de suites de tests et de ces suites.
 *
 * A compléter si besoin est.
 *
 */

/** Nombre de suites de tests à exécuter. */
#define NB_SUITE_TESTS 2

extern int mod1_run_tests(void);

extern int mod2_run_tests(void);

/** Liste des suites de tests à exécuter. */
int (* suite_tests[])(void) = 
{ 
	mod1_run_tests,
	mod2_run_tests
};


/*
 * Code générique de lancement des suites de tests.
 *
 */

static void test_runner();
static void affiche_aide(char * nom);

/**
 * Fonction principal du programme de test.
 */
int main(int argc, char * argv[])
{
	if ( (argc > 1) )
	{
		if (! strcmp(argv[1], "-text")) {
			cmocka_set_message_output(CM_OUTPUT_STDOUT);
		} else 
		if (! strcmp(argv[1], "-subunit")) {
			cmocka_set_message_output(CM_OUTPUT_SUBUNIT);
		} else 
		if (! strcmp(argv[1], "-tap")) {
			cmocka_set_message_output(CM_OUTPUT_TAP);
		} else
		if (! strcmp(argv[1], "-xml")) {
			cmocka_set_message_output(CM_OUTPUT_XML);
		} else {
			affiche_aide(argv[0]);
		}
	}

	test_runner();

	return 0;
}


/**
 * Lancement de chacune des suites de test avec CMocka.
 */
static void test_runner()
{
	int i;
	
	for (i = 0; i < NB_SUITE_TESTS; i++)
	{
		suite_tests[i]();
	}
}


/**
 * Affichage d'une aide sur la sortie standard pour utiliser le programme de test.
 */
static void affiche_aide(char * nom)
{
	printf("Suite de tests pour le programme à tester\n");
	printf("Usage : %s [-text] [-subunit] [-tap] [-xml]\n", nom);

	exit(0);
}

