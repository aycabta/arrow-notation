#include <gmp.h>
#include <limits.h>

int main(void)
{
    mpz_t base;
    mpz_t pentation;
    mpz_t exponent;
    mpz_t result;
    mpz_t pent_count;
    mpz_t pow_count;

    mpz_init(base);
    mpz_init(pentation);
    mpz_init(exponent);
    mpz_init(result);
    mpz_init(pent_count);
    mpz_init(pow_count);

    mpz_set_ui(base, 2L);
    mpz_set_ui(pentation, 5L);

    mpz_set_ui(exponent, 2L);
    mpz_set_ui(pent_count, 0L);
    mpz_sub_ui(pentation, pentation, 1L);
    while (mpz_cmp(pent_count, pentation) < 0) {
        mpz_set_ui(pow_count, 0L);
        mpz_set_ui(result, 1L);
        while (mpz_cmp(pow_count, exponent) < 0) {
            mpz_mul(result, result, base);
            mpz_add_ui(pow_count, pow_count, 1L);
        }
        mpz_set(exponent, result);
        mpz_add_ui(pent_count, pent_count, 1L);
    }

    gmp_printf("%Zd\n", result);

    int digit = 0;
    while (mpz_cmp_ui(result, 1L) >= 0) {
        digit++;
        mpz_fdiv_q_ui(result, result, 10UL);
    }
    gmp_printf("%d\n%", digit);

    return 0;
}

