#include "mathc.h"
#include "minunit.h"

MU_TEST(test_vec4i_create)
{
	mint_t result[VEC4_SIZE];
	vec4i(result, 3, 7, 11, 13);
	mu_assert_int_eq(3, result[0]);
	mu_assert_int_eq(7, result[1]);
	mu_assert_int_eq(11, result[2]);
	mu_assert_int_eq(13, result[3]);
}

MU_TEST(test_vec4i_zero)
{
	mint_t result[VEC4_SIZE];
	vec4i_zero(result);
	mu_assert_int_eq(0, result[0]);
	mu_assert_int_eq(0, result[1]);
	mu_assert_int_eq(0, result[2]);
	mu_assert_int_eq(0, result[3]);
}

MU_TEST(test_vec4i_one)
{
	mint_t result[VEC4_SIZE];
	vec4i_one(result);
	mu_assert_int_eq(1, result[0]);
	mu_assert_int_eq(1, result[1]);
	mu_assert_int_eq(1, result[2]);
	mu_assert_int_eq(1, result[3]);
}

MU_TEST(test_vec4i_is_zero)
{
	mint_t v1[VEC4_SIZE] = {0, 0, 0, 0};
	mint_t v2[VEC4_SIZE] = {0, 0, 0, 1};
	mu_assert(vec4i_is_zero(v1), "zero");
	mu_assert(!vec4i_is_zero(v2), "not zero");
}

MU_TEST(test_vec4i_add)
{
	mint_t v0[VEC4_SIZE] = {3, 5, 7, 9};
	mint_t v1[VEC4_SIZE] = {2, 4, 6, 8};
	mint_t result[VEC4_SIZE];
	vec4i_add(result, v0, v1);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(9, result[1]);
	mu_assert_int_eq(13, result[2]);
	mu_assert_int_eq(17, result[3]);
}

MU_TEST(test_vec4i_subtract)
{
	mint_t v0[VEC4_SIZE] = {10, 20, 30, 40};
	mint_t v1[VEC4_SIZE] = {3, 5, 7, 9};
	mint_t result[VEC4_SIZE];
	vec4i_subtract(result, v0, v1);
	mu_assert_int_eq(7, result[0]);
	mu_assert_int_eq(15, result[1]);
	mu_assert_int_eq(23, result[2]);
	mu_assert_int_eq(31, result[3]);
}

MU_TEST(test_vec4i_multiply)
{
	mint_t v0[VEC4_SIZE] = {3, 5, 7, 9};
	mint_t v1[VEC4_SIZE] = {2, 4, 6, 8};
	mint_t result[VEC4_SIZE];
	vec4i_multiply(result, v0, v1);
	mu_assert_int_eq(6, result[0]);
	mu_assert_int_eq(20, result[1]);
	mu_assert_int_eq(42, result[2]);
	mu_assert_int_eq(72, result[3]);
}

MU_TEST(test_vec4i_divide)
{
	mint_t v0[VEC4_SIZE] = {10, 20, 30, 40};
	mint_t v1[VEC4_SIZE] = {2, 4, 5, 8};
	mint_t result[VEC4_SIZE];
	vec4i_divide(result, v0, v1);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(5, result[1]);
	mu_assert_int_eq(6, result[2]);
	mu_assert_int_eq(5, result[3]);
}

MU_TEST(test_vec4i_negative)
{
	mint_t v0[VEC4_SIZE] = {3, -5, 7, -9};
	mint_t result[VEC4_SIZE];
	vec4i_negative(result, v0);
	mu_assert_int_eq(-3, result[0]);
	mu_assert_int_eq(5, result[1]);
	mu_assert_int_eq(-7, result[2]);
	mu_assert_int_eq(9, result[3]);
}

MU_TEST(test_vec4i_abs)
{
	mint_t v0[VEC4_SIZE] = {-3, -5, 7, -9};
	mint_t result[VEC4_SIZE];
	vec4i_abs(result, v0);
	mu_assert_int_eq(3, result[0]);
	mu_assert_int_eq(5, result[1]);
	mu_assert_int_eq(7, result[2]);
	mu_assert_int_eq(9, result[3]);
}

MU_TEST(test_vec4i_max)
{
	mint_t v0[VEC4_SIZE] = {3, 10, 5, 12};
	mint_t v1[VEC4_SIZE] = {5, 2, 8, 4};
	mint_t result[VEC4_SIZE];
	vec4i_max(result, v0, v1);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(10, result[1]);
	mu_assert_int_eq(8, result[2]);
	mu_assert_int_eq(12, result[3]);
}

MU_TEST(test_vec4i_min)
{
	mint_t v0[VEC4_SIZE] = {3, 10, 5, 12};
	mint_t v1[VEC4_SIZE] = {5, 2, 8, 4};
	mint_t result[VEC4_SIZE];
	vec4i_min(result, v0, v1);
	mu_assert_int_eq(3, result[0]);
	mu_assert_int_eq(2, result[1]);
	mu_assert_int_eq(5, result[2]);
	mu_assert_int_eq(4, result[3]);
}

MU_TEST(test_vec4i_clamp)
{
	mint_t v0[VEC4_SIZE] = {-5, 15, 5, 25};
	mint_t vmin[VEC4_SIZE] = {0, 0, 0, 0};
	mint_t vmax[VEC4_SIZE] = {10, 10, 10, 10};
	mint_t result[VEC4_SIZE];
	vec4i_clamp(result, v0, vmin, vmax);
	mu_assert_int_eq(0, result[0]);
	mu_assert_int_eq(10, result[1]);
	mu_assert_int_eq(5, result[2]);
	mu_assert_int_eq(10, result[3]);
}

MU_TEST(test_vec4i_sign)
{
	mint_t v0[VEC4_SIZE] = {-5, 10, 0, -1};
	mint_t result[VEC4_SIZE];
	vec4i_sign(result, v0);
	mu_assert_int_eq(-1, result[0]);
	mu_assert_int_eq(1, result[1]);
	mu_assert_int_eq(0, result[2]);
	mu_assert_int_eq(-1, result[3]);
}

/* struct API */

MU_TEST(test_svec4i_create)
{
	struct vec4i v = svec4i(3, 7, 11, 13);
	mu_assert_int_eq(3, v.x);
	mu_assert_int_eq(7, v.y);
	mu_assert_int_eq(11, v.z);
	mu_assert_int_eq(13, v.w);
}

MU_TEST(test_svec4i_add)
{
	struct vec4i v0 = svec4i(3, 5, 7, 9);
	struct vec4i v1 = svec4i(2, 4, 6, 8);
	struct vec4i result = svec4i_add(v0, v1);
	mu_assert_int_eq(5, result.x);
	mu_assert_int_eq(9, result.y);
	mu_assert_int_eq(13, result.z);
	mu_assert_int_eq(17, result.w);
}

MU_TEST(test_svec4i_negative)
{
	struct vec4i v0 = svec4i(3, -5, 7, -9);
	struct vec4i result = svec4i_negative(v0);
	mu_assert_int_eq(-3, result.x);
	mu_assert_int_eq(5, result.y);
	mu_assert_int_eq(-7, result.z);
	mu_assert_int_eq(9, result.w);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_vec4i_create);
	MU_RUN_TEST(test_vec4i_zero);
	MU_RUN_TEST(test_vec4i_one);
	MU_RUN_TEST(test_vec4i_is_zero);
	MU_RUN_TEST(test_vec4i_add);
	MU_RUN_TEST(test_vec4i_subtract);
	MU_RUN_TEST(test_vec4i_multiply);
	MU_RUN_TEST(test_vec4i_divide);
	MU_RUN_TEST(test_vec4i_negative);
	MU_RUN_TEST(test_vec4i_abs);
	MU_RUN_TEST(test_vec4i_max);
	MU_RUN_TEST(test_vec4i_min);
	MU_RUN_TEST(test_vec4i_clamp);
	MU_RUN_TEST(test_vec4i_sign);

	MU_RUN_TEST(test_svec4i_create);
	MU_RUN_TEST(test_svec4i_add);
	MU_RUN_TEST(test_svec4i_negative);
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
