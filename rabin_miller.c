#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <string.h>

void find_power(mpz_t m, mpz_t n);

int main(int argc, char **argv) {

	mpz_t a, m, r, k, b;

	if(argc != 2) {
		printf("[-] Sample Usage: ./rabin 672\n");
		return 0;
	}

	mpz_init(a); mpz_init(b); mpz_init(m); mpz_init(r); mpz_init(k);
	mpz_set_str(a, argv[1], 10);
	mpz_fdiv_r_ui(r, a, 2);

	if(mpz_cmp_ui(r, 0) == 0) {
		printf("Composite\n");
		return 0;
	}
	
	mpz_sub_ui(k, a, 1);
	find_power(m, k);

	mpz_set_ui(k, 2);
	mpz_powm(b, k, m, a);
	
	while(1) {
		if(mpz_cmp_ui(b, 1) == 0) {
			printf("Composite\n");
			return 0;
		}
		else if(mpz_cmp_ui(b, -1) == 0) {
			printf("Probably prime\n");
			return 0;	
		}
		else
			mpz_powm_ui(b, b, 2, a);
	}

	return 0;
}

void find_power(mpz_t m, mpz_t n) {
	mpz_t quo, rem;
	mpz_init(rem); mpz_init(quo);

	while(1) {
		mpz_fdiv_qr_ui(quo, rem, n, 2);
		if(mpz_cmp_ui(rem, 2) != 0) {
			mpz_set(m, n);
			return;
		}
		mpz_set(n, quo);
	}

	return;
}