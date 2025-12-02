#include "mathc.h"
#include "minunit.h"

MU_TEST(test_vec2i_create)
{
	mint_t result[VEC2_SIZE];
	vec2i(result, 3, 7);
	mu_assert_int_eq(3, result[0]);
	mu_assert_int_eq(7, result[1]);
}

MU_TEST(test_vec2i_zero)
{
	mint_t result[VEC2_SIZE];
	vec2i_zero(result);
	mu_assert_int_eq(0, result[0]);
	mu_assert_int_eq(0, result[1]);
}

MU_TEST(test_vec2i_one)
{
	mint_t result[VEC2_SIZE];
	vec2i_one(result);
	mu_assert_int_eq(1, result[0]);
	mu_assert_int_eq(1, result[1]);
}

MU_TEST(test_vec2i_assign)
{
	mint_t v0[VEC2_SIZE] = {5, 10};
	mint_t result[VEC2_SIZE];
	vec2i_assign(result, v0);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(10, result[1]);
}

MU_TEST(test_vec2i_is_zero_true)
{
	mint_t v[VEC2_SIZE] = {0, 0};
	mu_assert(vec2i_is_zero(v), "zero vector");
}

MU_TEST(test_vec2i_is_zero_false)
{
	mint_t v1[VEC2_SIZE] = {1, 0};
	mint_t v2[VEC2_SIZE] = {0, 1};
	mu_assert(!vec2i_is_zero(v1), "x != 0");
	mu_assert(!vec2i_is_zero(v2), "y != 0");
}

MU_TEST(test_vec2i_is_equal)
{
	mint_t v0[VEC2_SIZE] = {3, 5};
	mint_t v1[VEC2_SIZE] = {3, 5};
	mint_t v2[VEC2_SIZE] = {3, 6};
	mu_assert(vec2i_is_equal(v0, v1), "equal");
	mu_assert(!vec2i_is_equal(v0, v2), "not equal");
}

MU_TEST(test_vec2i_add)
{
	mint_t v0[VEC2_SIZE] = {3, 5};
	mint_t v1[VEC2_SIZE] = {2, 4};
	mint_t result[VEC2_SIZE];
	vec2i_add(result, v0, v1);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(9, result[1]);
}

MU_TEST(test_vec2i_add_i)
{
	mint_t v0[VEC2_SIZE] = {3, 5};
	mint_t result[VEC2_SIZE];
	vec2i_add_i(result, v0, 10);
	mu_assert_int_eq(13, result[0]);
	mu_assert_int_eq(15, result[1]);
}

MU_TEST(test_vec2i_subtract)
{
	mint_t v0[VEC2_SIZE] = {10, 20};
	mint_t v1[VEC2_SIZE] = {3, 5};
	mint_t result[VEC2_SIZE];
	vec2i_subtract(result, v0, v1);
	mu_assert_int_eq(7, result[0]);
	mu_assert_int_eq(15, result[1]);
}

MU_TEST(test_vec2i_subtract_i)
{
	mint_t v0[VEC2_SIZE] = {10, 20};
	mint_t result[VEC2_SIZE];
	vec2i_subtract_i(result, v0, 5);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(15, result[1]);
}

MU_TEST(test_vec2i_multiply)
{
	mint_t v0[VEC2_SIZE] = {3, 5};
	mint_t v1[VEC2_SIZE] = {2, 4};
	mint_t result[VEC2_SIZE];
	vec2i_multiply(result, v0, v1);
	mu_assert_int_eq(6, result[0]);
	mu_assert_int_eq(20, result[1]);
}

MU_TEST(test_vec2i_multiply_i)
{
	mint_t v0[VEC2_SIZE] = {3, 5};
	mint_t result[VEC2_SIZE];
	vec2i_multiply_i(result, v0, 3);
	mu_assert_int_eq(9, result[0]);
	mu_assert_int_eq(15, result[1]);
}

MU_TEST(test_vec2i_divide)
{
	mint_t v0[VEC2_SIZE] = {10, 20};
	mint_t v1[VEC2_SIZE] = {2, 4};
	mint_t result[VEC2_SIZE];
	vec2i_divide(result, v0, v1);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(5, result[1]);
}

MU_TEST(test_vec2i_divide_i)
{
	mint_t v0[VEC2_SIZE] = {10, 20};
	mint_t result[VEC2_SIZE];
	vec2i_divide_i(result, v0, 5);
	mu_assert_int_eq(2, result[0]);
	mu_assert_int_eq(4, result[1]);
}

MU_TEST(test_vec2i_divide_truncation)
{
	mint_t v0[VEC2_SIZE] = {7, 9};
	mint_t v1[VEC2_SIZE] = {2, 2};
	mint_t result[VEC2_SIZE];
	vec2i_divide(result, v0, v1);
	mu_assert_int_eq(3, result[0]);
	mu_assert_int_eq(4, result[1]);
}

MU_TEST(test_vec2i_snap)
{
	mint_t v0[VEC2_SIZE] = {7, 13};
	mint_t v1[VEC2_SIZE] = {5, 5};
	mint_t result[VEC2_SIZE];
	vec2i_snap(result, v0, v1);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(10, result[1]);
}

MU_TEST(test_vec2i_snap_i)
{
	mint_t v0[VEC2_SIZE] = {7, 13};
	mint_t result[VEC2_SIZE];
	vec2i_snap_i(result, v0, 5);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(10, result[1]);
}

MU_TEST(test_vec2i_negative)
{
	mint_t v0[VEC2_SIZE] = {3, -5};
	mint_t result[VEC2_SIZE];
	vec2i_negative(result, v0);
	mu_assert_int_eq(-3, result[0]);
	mu_assert_int_eq(5, result[1]);
}

MU_TEST(test_vec2i_abs)
{
	mint_t v0[VEC2_SIZE] = {-3, -5};
	mint_t result[VEC2_SIZE];
	vec2i_abs(result, v0);
	mu_assert_int_eq(3, result[0]);
	mu_assert_int_eq(5, result[1]);
}

MU_TEST(test_vec2i_max)
{
	mint_t v0[VEC2_SIZE] = {3, 10};
	mint_t v1[VEC2_SIZE] = {5, 2};
	mint_t result[VEC2_SIZE];
	vec2i_max(result, v0, v1);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(10, result[1]);
}

MU_TEST(test_vec2i_min)
{
	mint_t v0[VEC2_SIZE] = {3, 10};
	mint_t v1[VEC2_SIZE] = {5, 2};
	mint_t result[VEC2_SIZE];
	vec2i_min(result, v0, v1);
	mu_assert_int_eq(3, result[0]);
	mu_assert_int_eq(2, result[1]);
}

MU_TEST(test_vec2i_clamp)
{
	mint_t v0[VEC2_SIZE] = {-5, 15};
	mint_t vmin[VEC2_SIZE] = {0, 0};
	mint_t vmax[VEC2_SIZE] = {10, 10};
	mint_t result[VEC2_SIZE];
	vec2i_clamp(result, v0, vmin, vmax);
	mu_assert_int_eq(0, result[0]);
	mu_assert_int_eq(10, result[1]);
}

MU_TEST(test_vec2i_sign)
{
	mint_t v0[VEC2_SIZE] = {-5, 10};
	mint_t result[VEC2_SIZE];
	vec2i_sign(result, v0);
	mu_assert_int_eq(-1, result[0]);
	mu_assert_int_eq(1, result[1]);
}

MU_TEST(test_vec2i_sign_zero)
{
	mint_t v0[VEC2_SIZE] = {0, 0};
	mint_t result[VEC2_SIZE];
	vec2i_sign(result, v0);
	mu_assert_int_eq(0, result[0]);
	mu_assert_int_eq(0, result[1]);
}

MU_TEST(test_vec2i_tangent)
{
	mint_t v0[VEC2_SIZE] = {3, 5};
	mint_t result[VEC2_SIZE];
	vec2i_tangent(result, v0);
	mu_assert_int_eq(5, result[0]);
	mu_assert_int_eq(-3, result[1]);
}

/* struct API */

MU_TEST(test_svec2i_create)
{
	struct vec2i v = svec2i(3, 7);
	mu_assert_int_eq(3, v.x);
	mu_assert_int_eq(7, v.y);
}

MU_TEST(test_svec2i_zero)
{
	struct vec2i v = svec2i_zero();
	mu_assert_int_eq(0, v.x);
	mu_assert_int_eq(0, v.y);
}

MU_TEST(test_svec2i_add)
{
	struct vec2i v0 = svec2i(3, 5);
	struct vec2i v1 = svec2i(2, 4);
	struct vec2i result = svec2i_add(v0, v1);
	mu_assert_int_eq(5, result.x);
	mu_assert_int_eq(9, result.y);
}

MU_TEST(test_svec2i_subtract)
{
	struct vec2i v0 = svec2i(10, 20);
	struct vec2i v1 = svec2i(3, 5);
	struct vec2i result = svec2i_subtract(v0, v1);
	mu_assert_int_eq(7, result.x);
	mu_assert_int_eq(15, result.y);
}

MU_TEST(test_svec2i_multiply)
{
	struct vec2i v0 = svec2i(3, 5);
	struct vec2i v1 = svec2i(2, 4);
	struct vec2i result = svec2i_multiply(v0, v1);
	mu_assert_int_eq(6, result.x);
	mu_assert_int_eq(20, result.y);
}

MU_TEST(test_svec2i_divide)
{
	struct vec2i v0 = svec2i(10, 20);
	struct vec2i v1 = svec2i(2, 4);
	struct vec2i result = svec2i_divide(v0, v1);
	mu_assert_int_eq(5, result.x);
	mu_assert_int_eq(5, result.y);
}

MU_TEST(test_svec2i_snap)
{
	struct vec2i v0 = svec2i(7, 13);
	struct vec2i v1 = svec2i(5, 5);
	struct vec2i result = svec2i_snap(v0, v1);
	mu_assert_int_eq(5, result.x);
	mu_assert_int_eq(10, result.y);
}

MU_TEST(test_svec2i_clamp)
{
	struct vec2i v0 = svec2i(-5, 15);
	struct vec2i vmin = svec2i(0, 0);
	struct vec2i vmax = svec2i(10, 10);
	struct vec2i result = svec2i_clamp(v0, vmin, vmax);
	mu_assert_int_eq(0, result.x);
	mu_assert_int_eq(10, result.y);
}

MU_TEST(test_svec2i_negative)
{
	struct vec2i v0 = svec2i(3, -5);
	struct vec2i result = svec2i_negative(v0);
	mu_assert_int_eq(-3, result.x);
	mu_assert_int_eq(5, result.y);
}

MU_TEST(test_svec2i_chained)
{
	struct vec2i a = svec2i(1, 2);
	struct vec2i b = svec2i(3, 4);
	struct vec2i result = svec2i_multiply_i(svec2i_add(a, b), 2);
	mu_assert_int_eq(8, result.x);
	mu_assert_int_eq(12, result.y);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_vec2i_create);
	MU_RUN_TEST(test_vec2i_zero);
	MU_RUN_TEST(test_vec2i_one);
	MU_RUN_TEST(test_vec2i_assign);
	MU_RUN_TEST(test_vec2i_is_zero_true);
	MU_RUN_TEST(test_vec2i_is_zero_false);
	MU_RUN_TEST(test_vec2i_is_equal);
	MU_RUN_TEST(test_vec2i_add);
	MU_RUN_TEST(test_vec2i_add_i);
	MU_RUN_TEST(test_vec2i_subtract);
	MU_RUN_TEST(test_vec2i_subtract_i);
	MU_RUN_TEST(test_vec2i_multiply);
	MU_RUN_TEST(test_vec2i_multiply_i);
	MU_RUN_TEST(test_vec2i_divide);
	MU_RUN_TEST(test_vec2i_divide_i);
	MU_RUN_TEST(test_vec2i_divide_truncation);
	MU_RUN_TEST(test_vec2i_snap);
	MU_RUN_TEST(test_vec2i_snap_i);
	MU_RUN_TEST(test_vec2i_negative);
	MU_RUN_TEST(test_vec2i_abs);
	MU_RUN_TEST(test_vec2i_max);
	MU_RUN_TEST(test_vec2i_min);
	MU_RUN_TEST(test_vec2i_clamp);
	MU_RUN_TEST(test_vec2i_sign);
	MU_RUN_TEST(test_vec2i_sign_zero);
	MU_RUN_TEST(test_vec2i_tangent);

	MU_RUN_TEST(test_svec2i_create);
	MU_RUN_TEST(test_svec2i_zero);
	MU_RUN_TEST(test_svec2i_add);
	MU_RUN_TEST(test_svec2i_subtract);
	MU_RUN_TEST(test_svec2i_multiply);
	MU_RUN_TEST(test_svec2i_divide);
	MU_RUN_TEST(test_svec2i_snap);
	MU_RUN_TEST(test_svec2i_clamp);
	MU_RUN_TEST(test_svec2i_negative);
	MU_RUN_TEST(test_svec2i_chained);
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
