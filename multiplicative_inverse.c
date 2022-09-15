#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <string.h>

int main() {

	mpz_t a, m, res, t, r;
	char inputStr[1024];

	mpz_init(a); mpz_init(m); mpz_init(res); mpz_init(t); mpz_init(r);
	mpz_set_ui(res, 1);

	memset(inputStr, '\0', 1024);
	printf("a=");
	scanf("%1023s", inputStr);
	mpz_set_str(a, inputStr, 10);

	memset(inputStr, '\0', 1024);
	printf("m=");
	scanf("%1023s", inputStr);
	mpz_set_str(m, inputStr, 10);


	while(mpz_cmp(res, m) < 0) {
		mpz_mul(t, a, res);
		mpz_fdiv_r(r, t, m);

		if(mpz_cmp_ui(r, 1) == 0) {
			printf("Multiplicative Inverse = ");
			mpz_out_str(stdout, 10, res);
			printf("\n");
		}

		mpz_add_ui(res, res, 1);
	}

	return 0;
}