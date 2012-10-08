#include <gmp.h>
#include <limits.h>

void arrow(mpz_t result, mpz_t base, mpz_t exponent, mpz_t arrows)
{
    mpz_t count;
    mpz_t temp_result;
    mpz_t temp_exponent;
    mpz_t temp_arrows;

    mpz_init(count);

    if (mpz_cmp_ui(arrows, 1L) == 0) {
        mpz_set_ui(result, 1L);
        mpz_set_ui(count, 0L);
        while (mpz_cmp(count, exponent) < 0) {
            mpz_mul(result, result, base);
            mpz_add_ui(count, count, 1L);
        }
    } else {
        mpz_init(temp_result);
        mpz_init(temp_exponent);
        mpz_init(temp_arrows);

        mpz_set_ui(count, 1L);
        mpz_sub_ui(temp_arrows, arrows, 1L);
        mpz_set(temp_exponent, base);
        while (mpz_cmp(count, exponent) < 0) {
            arrow(temp_result, base, temp_exponent, temp_arrows);
            mpz_add_ui(count, count, 1L);
            mpz_set(temp_exponent, temp_result);
        }
        mpz_set(result, temp_result);

        mpz_clear(temp_arrows);
        mpz_clear(temp_exponent);
        mpz_clear(temp_result);
    }

    mpz_clear(count);
}

int main(void)
{
    mpz_t base;
    mpz_t exponent;
    mpz_t arrows;
    mpz_t result;

    mpz_init(base);
    mpz_init(exponent);
    mpz_init(arrows);
    mpz_init(result);

    mpz_set_ui(base, 2L);
    mpz_set_ui(arrows, 2L);
    mpz_set_ui(exponent, 5L);

    arrow(result, base, exponent, arrows);

    gmp_printf("%Zd\n", result);

    int digit = 0;
    while (mpz_cmp_ui(result, 1L) >= 0) {
        digit++;
        mpz_fdiv_q_ui(result, result, 10UL);
    }
    gmp_printf("%d digits\n%", digit);

    return 0;
}

