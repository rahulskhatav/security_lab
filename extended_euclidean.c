#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <string.h>

int main() {

	int i;
	mpz_t a, b, x0, x1, y0, y1, q, r, t;
	char inputStr[1024];

	// initializing the integers
	mpz_init(a); mpz_init(b); mpz_init(x0); mpz_init(x1); mpz_init(y0); mpz_init(y1); mpz_init(q); mpz_init(r); mpz_init(t);

	// input the numbers 'a' and 'b'
	memset(inputStr, '\0', 1024);
	printf("a=");
	scanf("%1023s", inputStr);
	mpz_set_str(a, inputStr, 10);

	memset(inputStr, '\0', 1024);
	printf("b=");
	scanf("%1023s", inputStr);
	mpz_set_str(b, inputStr, 10);

	mpz_set_ui(x0, 0); mpz_set_ui(x1, 1);
	mpz_set_ui(y0, 1); mpz_set_ui(y1, 0);
	mpz_set_ui(q, 0); mpz_set_ui(r, 0);

	mpz_fdiv_qr(q, r, a, b);
	
	i = 0;
	while(1) {
		mpz_fdiv_qr(q, r, a, b);

		printf("i=%d ", i);
		printf("r=");
		mpz_out_str(stdout, 10, r);
		printf(" q=");
		mpz_out_str(stdout, 10, q);

		if(i%2==0) {
			mpz_mul(t, q, x0);
			mpz_sub(x1, x1, t);
			printf(" x=");
			mpz_out_str(stdout, 10, x1);

			mpz_mul(t, q, y0);
			mpz_sub(y1, y1, t);
			printf(" y=");
			mpz_out_str(stdout, 10, y1);
		}
		else {
			mpz_mul(t, q, x1);
			mpz_sub(x0, x0, t);
			printf(" x=");
			mpz_out_str(stdout, 10, x0);

			mpz_mul(t, q, y1);
			mpz_sub(y0, y0, t);
			printf(" y=");
			mpz_out_str(stdout, 10, y0);	
		}

		// gcd is found. remainder is 0
		// print final solution
		if(mpz_cmp_ui(r, 0) == 0) {
			printf("\ngcd = ");
			mpz_out_str(stdout, 10, b);


			printf("\nx = ");
			if(i%2==0) mpz_out_str(stdout, 10, x0);
			else mpz_out_str(stdout, 10, x1);

			printf("\ny = ");
			if(i%2==0) mpz_out_str(stdout, 10, y0);
			else mpz_out_str(stdout, 10, y1);

			printf("\n");
			break;
		}	

		mpz_set(a, b);
		mpz_set(b, r);

		i++;
		printf("\n");
	}


	return 0;
}
