#include "pkg/mod1.h"
#include "pkg/mod2.h"

int mod1_att0;

static int mod1_att_st0;


int mod1_fct0(int p) {
	return p *10;
}

int mod1_fct1(int p) {
	int calcul = mod2_fct1(p);
	return calcul + 1;
}

int mod1_fct2(int p, int * pt) {
	return mod2_fct2(p,pt) + 2;
}

int mod1_fct3(int p) {
	return mod1_fct4(p) + 3;
}

#ifndef _WRAP_MOD1_FCT4
int mod1_fct4(int p) {
	return p * 40;
}
#endif

static int mod1_fct_st0(int p) {
	mod1_att_st0 = p + 1;
	return p + 10;
}

#ifndef _WRAP_MOD1_FCT_ST1
static int mod1_fct_st1(int p) {
	return p * 50;
}
#else
int mod1_fct_st1(int p);
#endif

#ifndef _MOCK_PERSO_MOD1_FCT_ST1
static int mod1_fct_st1_bis(int p) {
	return p*50;
}
#else
static int mod1_fct_st1_bis(int p) __attribute__((weakref("_mock_perso_mod1_fct_st1_bis")));
#endif

int mod1_fct5(int p) {
	return mod1_fct_st1(p) + 5;
}



int mod1_fct5_bis(int p) {
	return mod1_fct_st1_bis(p) + 5;
}

