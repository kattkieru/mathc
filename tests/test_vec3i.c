#include "mathc.h"
#include "minunit.h"

MU_TEST(test_vec3i_create)
{
	mint_t result[VEC3_SIZE];
	vec3i(result, 3, 7, 11);
	mu_assert_int_eq(3, result[0]);
	mu_assert_int_eq(7, result[1]);
	mu_assert_int_eq(11, result[2]);
}

MU_TEST(test_vec3i_zero)
{
	mint_t result[VEC3_SIZE];
	vec3i_zero(result);
	mu_assert_int_eq(0, result[0]);
	mu_assert_int_eq(0, result[1]);
	mu_assert_int_eq(0, result[2]);
}

MU_TEST(test_vec3i_one)
{
	mint_t result[VEC3_SIZE];
	vec3i_one(result);
	mu_assert_int_eq(1, result[0]);
	mu_assert_int_eq(1, result[1]);
	mu_assert_int_eq(1, result[2]);
}

MU_TEST(test_vec3i_is_zero)
{
	mint_t v1[VEC3_SIZE] = {0, 0, 0};
	mint_t v2[VEC3_SIZE] = {0, 0, 1};
	mu_assert(vec3i_is_zero(v1), "zero");
	mu_assert(!vec3i_is_zero(v2), "not zero");
}

MU_TEST(test_vec3i_add)
{
	mint_t v0[VEC3_SIZE] = {3, 5, 7};
	mint_t v1[VEC3_SIZE] = {2, 4, 6};
	mint_t result[VEC3_SIZE];
	vec3i_add(result, v0, v1);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(9, result[1]);
	mu_assert_int_eq(13, result[2]);
}

MU_TEST(test_vec3i_subtract)
{
	mint_t v0[VEC3_SIZE] = {10, 20, 30};
	mint_t v1[VEC3_SIZE] = {3, 5, 7};
	mint_t result[VEC3_SIZE];
	vec3i_subtract(result, v0, v1);
	mu_assert_int_eq(7, result[0]);
	mu_assert_int_eq(15, result[1]);
	mu_assert_int_eq(23, result[2]);
}

MU_TEST(test_vec3i_multiply)
{
	mint_t v0[VEC3_SIZE] = {3, 5, 7};
	mint_t v1[VEC3_SIZE] = {2, 4, 6};
	mint_t result[VEC3_SIZE];
	vec3i_multiply(result, v0, v1);
	mu_assert_int_eq(6, result[0]);
	mu_assert_int_eq(20, result[1]);
	mu_assert_int_eq(42, result[2]);
}

MU_TEST(test_vec3i_divide)
{
	mint_t v0[VEC3_SIZE] = {10, 20, 30};
	mint_t v1[VEC3_SIZE] = {2, 4, 5};
	mint_t result[VEC3_SIZE];
	vec3i_divide(result, v0, v1);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(5, result[1]);
	mu_assert_int_eq(6, result[2]);
}

MU_TEST(test_vec3i_cross)
{
	mint_t x[VEC3_SIZE] = {1, 0, 0};
	mint_t y[VEC3_SIZE] = {0, 1, 0};
	mint_t result[VEC3_SIZE];

	vec3i_cross(result, x, y);
	mu_assert_int_eq(0, result[0]);
	mu_assert_int_eq(0, result[1]);
	mu_assert_int_eq(1, result[2]);

	vec3i_cross(result, y, x);
	mu_assert_int_eq(0, result[0]);
	mu_assert_int_eq(0, result[1]);
	mu_assert_int_eq(-1, result[2]);
}

MU_TEST(test_vec3i_cross_parallel)
{
	mint_t v0[VEC3_SIZE] = {2, 0, 0};
	mint_t v1[VEC3_SIZE] = {4, 0, 0};
	mint_t result[VEC3_SIZE];
	vec3i_cross(result, v0, v1);
	mu_assert_int_eq(0, result[0]);
	mu_assert_int_eq(0, result[1]);
	mu_assert_int_eq(0, result[2]);
}

MU_TEST(test_vec3i_negative)
{
	mint_t v0[VEC3_SIZE] = {3, -5, 7};
	mint_t result[VEC3_SIZE];
	vec3i_negative(result, v0);
	mu_assert_int_eq(-3, result[0]);
	mu_assert_int_eq(5, result[1]);
	mu_assert_int_eq(-7, result[2]);
}

MU_TEST(test_vec3i_abs)
{
	mint_t v0[VEC3_SIZE] = {-3, -5, 7};
	mint_t result[VEC3_SIZE];
	vec3i_abs(result, v0);
	mu_assert_int_eq(3, result[0]);
	mu_assert_int_eq(5, result[1]);
	mu_assert_int_eq(7, result[2]);
}

MU_TEST(test_vec3i_max)
{
	mint_t v0[VEC3_SIZE] = {3, 10, 5};
	mint_t v1[VEC3_SIZE] = {5, 2, 8};
	mint_t result[VEC3_SIZE];
	vec3i_max(result, v0, v1);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(10, result[1]);
	mu_assert_int_eq(8, result[2]);
}

MU_TEST(test_vec3i_min)
{
	mint_t v0[VEC3_SIZE] = {3, 10, 5};
	mint_t v1[VEC3_SIZE] = {5, 2, 8};
	mint_t result[VEC3_SIZE];
	vec3i_min(result, v0, v1);
	mu_assert_int_eq(3, result[0]);
	mu_assert_int_eq(2, result[1]);
	mu_assert_int_eq(5, result[2]);
}

MU_TEST(test_vec3i_clamp)
{
	mint_t v0[VEC3_SIZE] = {-5, 15, 5};
	mint_t vmin[VEC3_SIZE] = {0, 0, 0};
	mint_t vmax[VEC3_SIZE] = {10, 10, 10};
	mint_t result[VEC3_SIZE];
	vec3i_clamp(result, v0, vmin, vmax);
	mu_assert_int_eq(0, result[0]);
	mu_assert_int_eq(10, result[1]);
	mu_assert_int_eq(5, result[2]);
}

MU_TEST(test_vec3i_sign)
{
	mint_t v0[VEC3_SIZE] = {-5, 10, 0};
	mint_t result[VEC3_SIZE];
	vec3i_sign(result, v0);
	mu_assert_int_eq(-1, result[0]);
	mu_assert_int_eq(1, result[1]);
	mu_assert_int_eq(0, result[2]);
}

/* struct API */

MU_TEST(test_svec3i_create)
{
	struct vec3i v = svec3i(3, 7, 11);
	mu_assert_int_eq(3, v.x);
	mu_assert_int_eq(7, v.y);
	mu_assert_int_eq(11, v.z);
}

MU_TEST(test_svec3i_add)
{
	struct vec3i v0 = svec3i(3, 5, 7);
	struct vec3i v1 = svec3i(2, 4, 6);
	struct vec3i result = svec3i_add(v0, v1);
	mu_assert_int_eq(5, result.x);
	mu_assert_int_eq(9, result.y);
	mu_assert_int_eq(13, result.z);
}

MU_TEST(test_svec3i_cross)
{
	struct vec3i x = svec3i(1, 0, 0);
	struct vec3i y = svec3i(0, 1, 0);
	struct vec3i result = svec3i_cross(x, y);
	mu_assert_int_eq(0, result.x);
	mu_assert_int_eq(0, result.y);
	mu_assert_int_eq(1, result.z);
}

MU_TEST(test_svec3i_negative)
{
	struct vec3i v0 = svec3i(3, -5, 7);
	struct vec3i result = svec3i_negative(v0);
	mu_assert_int_eq(-3, result.x);
	mu_assert_int_eq(5, result.y);
	mu_assert_int_eq(-7, result.z);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_vec3i_create);
	MU_RUN_TEST(test_vec3i_zero);
	MU_RUN_TEST(test_vec3i_one);
	MU_RUN_TEST(test_vec3i_is_zero);
	MU_RUN_TEST(test_vec3i_add);
	MU_RUN_TEST(test_vec3i_subtract);
	MU_RUN_TEST(test_vec3i_multiply);
	MU_RUN_TEST(test_vec3i_divide);
	MU_RUN_TEST(test_vec3i_cross);
	MU_RUN_TEST(test_vec3i_cross_parallel);
	MU_RUN_TEST(test_vec3i_negative);
	MU_RUN_TEST(test_vec3i_abs);
	MU_RUN_TEST(test_vec3i_max);
	MU_RUN_TEST(test_vec3i_min);
	MU_RUN_TEST(test_vec3i_clamp);
	MU_RUN_TEST(test_vec3i_sign);

	MU_RUN_TEST(test_svec3i_create);
	MU_RUN_TEST(test_svec3i_add);
	MU_RUN_TEST(test_svec3i_cross);
	MU_RUN_TEST(test_svec3i_negative);
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
