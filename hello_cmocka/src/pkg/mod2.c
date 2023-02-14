#include "mod2.h"
#include "mod1.h"

int mod2_fct1(int p) {
	mod1_att0 = (p + 2);
	return p * 20;
}

int mod2_fct2(int p, int * pt) {
	*(pt) = p + 3;
	return p * 30;
}

