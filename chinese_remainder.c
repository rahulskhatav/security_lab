#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <string.h>

void multiplicative_inverse(mpz_t res, const mpz_t a, const mpz_t m);

int main() {

	mpz_t a, b, c, m1, m2, m3, M1, M2, M3, M, x1, x2, x3, res;
	char inputStr[1024];

	mpz_init(a); mpz_init(b); mpz_init(c); mpz_init(M); mpz_init(res);
	mpz_init(m1); mpz_init(m2); mpz_init(m3);
	mpz_init(x1); mpz_init(x2); mpz_init(x3);
	mpz_init(M1); mpz_init(M2); mpz_init(M3);

	mpz_set_ui(M1, 1); mpz_set_ui(M2, 1); mpz_set_ui(M3, 1); mpz_set_ui(M, 1);
	mpz_set_ui(res, 0);

	printf("x ~= a mod m1\n");
	memset(inputStr, '\0', 1024);
	printf("a=");
	scanf("%1023s", inputStr);
	mpz_set_str(a, inputStr, 10);
	memset(inputStr, '\0', 1024);
	printf("m1=");
	scanf("%1023s", inputStr);
	mpz_set_str(m1, inputStr, 10);

	printf("x ~= b mod m2\n");
	memset(inputStr, '\0', 1024);
	printf("b=");
	scanf("%1023s", inputStr);
	mpz_set_str(b, inputStr, 10);
	memset(inputStr, '\0', 1024);
	printf("m2=");
	scanf("%1023s", inputStr);
	mpz_set_str(m2, inputStr, 10);

	printf("x ~= c mod m3\n");
	memset(inputStr, '\0', 1024);
	printf("c=");
	scanf("%1023s", inputStr);
	mpz_set_str(c, inputStr, 10);
	memset(inputStr, '\0', 1024);
	printf("m3=");
	scanf("%1023s", inputStr);
	mpz_set_str(m3, inputStr, 10);

	mpz_mul(M, M, m1); mpz_mul(M, M, m2); mpz_mul(M, M, m3);
	mpz_mul(M1, M1, m2); mpz_mul(M1, M1, m3);
	mpz_mul(M2, M2, m1); mpz_mul(M2, M2, m3);
	mpz_mul(M3, M3, m1); mpz_mul(M3, M3, m2);
	
	multiplicative_inverse(x1, M1, m1);
	multiplicative_inverse(x2, M2, m2);
	multiplicative_inverse(x3, M3, m3);

	mpz_mul(M1, M1, a); mpz_mul(M1, M1, x1);
	mpz_mul(M2, M2, b); mpz_mul(M2, M2, x2);
	mpz_mul(M3, M3, c); mpz_mul(M3, M3, x3);

	mpz_add(res, res, M1); mpz_add(res, res, M2); mpz_add(res, res, M3);
	mpz_fdiv_r(res, res, M);

	printf("res = ");
	mpz_out_str(stdout, 10, res);
	printf("\n");

	return 0;
}

void multiplicative_inverse(mpz_t res, const mpz_t a, const mpz_t m) {
	mpz_t t, r;

	mpz_init(t); mpz_init(r);
	mpz_set_ui(res, 1);

	while(mpz_cmp(res, m) < 0) {
		mpz_mul(t, a, res);
		mpz_fdiv_r(r, t, m);

		if(mpz_cmp_ui(r, 1) == 0) return;

		mpz_add_ui(res, res, 1);
	}
}