#include <float.h>

#include "mathc.h"
#include "minunit.h"

#define EPSILON 0.0001f

static bool float_eq(mfloat_t a, mfloat_t b)
{
	return MFABS(a - b) < EPSILON;
}

MU_TEST(test_vec2_create)
{
	mfloat_t result[VEC2_SIZE];
	vec2(result, 3.5f, 7.25f);
	mu_assert(float_eq(3.5f, result[0]), "x");
	mu_assert(float_eq(7.25f, result[1]), "y");
}

MU_TEST(test_vec2_zero)
{
	mfloat_t result[VEC2_SIZE];
	vec2_zero(result);
	mu_assert(float_eq(0.0f, result[0]), "x");
	mu_assert(float_eq(0.0f, result[1]), "y");
}

MU_TEST(test_vec2_one)
{
	mfloat_t result[VEC2_SIZE];
	vec2_one(result);
	mu_assert(float_eq(1.0f, result[0]), "x");
	mu_assert(float_eq(1.0f, result[1]), "y");
}

MU_TEST(test_vec2_is_zero)
{
	mfloat_t v1[VEC2_SIZE] = {0.0f, 0.0f};
	mfloat_t v2[VEC2_SIZE] = {0.001f, 0.0f};
	mu_assert(vec2_is_zero(v1), "zero");
	mu_assert(!vec2_is_zero(v2), "not zero");
}

MU_TEST(test_vec2_add)
{
	mfloat_t v0[VEC2_SIZE] = {3.0f, 5.0f};
	mfloat_t v1[VEC2_SIZE] = {2.0f, 4.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_add(result, v0, v1);
	mu_assert(float_eq(5.0f, result[0]), "x");
	mu_assert(float_eq(9.0f, result[1]), "y");
}

MU_TEST(test_vec2_add_f)
{
	mfloat_t v0[VEC2_SIZE] = {3.0f, 5.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_add_f(result, v0, 2.5f);
	mu_assert(float_eq(5.5f, result[0]), "x");
	mu_assert(float_eq(7.5f, result[1]), "y");
}

MU_TEST(test_vec2_subtract)
{
	mfloat_t v0[VEC2_SIZE] = {10.0f, 20.0f};
	mfloat_t v1[VEC2_SIZE] = {3.0f, 5.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_subtract(result, v0, v1);
	mu_assert(float_eq(7.0f, result[0]), "x");
	mu_assert(float_eq(15.0f, result[1]), "y");
}

MU_TEST(test_vec2_multiply)
{
	mfloat_t v0[VEC2_SIZE] = {3.0f, 5.0f};
	mfloat_t v1[VEC2_SIZE] = {2.0f, 4.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_multiply(result, v0, v1);
	mu_assert(float_eq(6.0f, result[0]), "x");
	mu_assert(float_eq(20.0f, result[1]), "y");
}

MU_TEST(test_vec2_multiply_f)
{
	mfloat_t v0[VEC2_SIZE] = {3.0f, 5.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_multiply_f(result, v0, 2.0f);
	mu_assert(float_eq(6.0f, result[0]), "x");
	mu_assert(float_eq(10.0f, result[1]), "y");
}

MU_TEST(test_vec2_divide)
{
	mfloat_t v0[VEC2_SIZE] = {10.0f, 20.0f};
	mfloat_t v1[VEC2_SIZE] = {2.0f, 4.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_divide(result, v0, v1);
	mu_assert(float_eq(5.0f, result[0]), "x");
	mu_assert(float_eq(5.0f, result[1]), "y");
}

MU_TEST(test_vec2_negative)
{
	mfloat_t v0[VEC2_SIZE] = {3.0f, -5.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_negative(result, v0);
	mu_assert(float_eq(-3.0f, result[0]), "x");
	mu_assert(float_eq(5.0f, result[1]), "y");
}

MU_TEST(test_vec2_abs)
{
	mfloat_t v0[VEC2_SIZE] = {-3.0f, -5.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_abs(result, v0);
	mu_assert(float_eq(3.0f, result[0]), "x");
	mu_assert(float_eq(5.0f, result[1]), "y");
}

MU_TEST(test_vec2_floor)
{
	mfloat_t v0[VEC2_SIZE] = {3.7f, 5.2f};
	mfloat_t result[VEC2_SIZE];
	vec2_floor(result, v0);
	mu_assert(float_eq(3.0f, result[0]), "x");
	mu_assert(float_eq(5.0f, result[1]), "y");
}

MU_TEST(test_vec2_ceil)
{
	mfloat_t v0[VEC2_SIZE] = {3.2f, 5.7f};
	mfloat_t result[VEC2_SIZE];
	vec2_ceil(result, v0);
	mu_assert(float_eq(4.0f, result[0]), "x");
	mu_assert(float_eq(6.0f, result[1]), "y");
}

MU_TEST(test_vec2_round)
{
	mfloat_t v0[VEC2_SIZE] = {3.4f, 5.6f};
	mfloat_t result[VEC2_SIZE];
	vec2_round(result, v0);
	mu_assert(float_eq(3.0f, result[0]), "round down");
	mu_assert(float_eq(6.0f, result[1]), "round up");
}

MU_TEST(test_vec2_max)
{
	mfloat_t v0[VEC2_SIZE] = {3.0f, 10.0f};
	mfloat_t v1[VEC2_SIZE] = {5.0f, 2.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_max(result, v0, v1);
	mu_assert(float_eq(5.0f, result[0]), "x");
	mu_assert(float_eq(10.0f, result[1]), "y");
}

MU_TEST(test_vec2_min)
{
	mfloat_t v0[VEC2_SIZE] = {3.0f, 10.0f};
	mfloat_t v1[VEC2_SIZE] = {5.0f, 2.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_min(result, v0, v1);
	mu_assert(float_eq(3.0f, result[0]), "x");
	mu_assert(float_eq(2.0f, result[1]), "y");
}

MU_TEST(test_vec2_clamp)
{
	mfloat_t v0[VEC2_SIZE] = {-5.0f, 15.0f};
	mfloat_t vmin[VEC2_SIZE] = {0.0f, 0.0f};
	mfloat_t vmax[VEC2_SIZE] = {10.0f, 10.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_clamp(result, v0, vmin, vmax);
	mu_assert(float_eq(0.0f, result[0]), "clamped to min");
	mu_assert(float_eq(10.0f, result[1]), "clamped to max");
}

MU_TEST(test_vec2_normalize)
{
	mfloat_t v0[VEC2_SIZE] = {3.0f, 4.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_normalize(result, v0);
	mu_assert(float_eq(0.6f, result[0]), "x");
	mu_assert(float_eq(0.8f, result[1]), "y");
}

MU_TEST(test_vec2_normalize_zero)
{
	mfloat_t v0[VEC2_SIZE] = {0.0f, 0.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_normalize(result, v0);
	mu_assert(result[0] != result[0], "NaN x");
	mu_assert(result[1] != result[1], "NaN y");
}

MU_TEST(test_vec2_dot)
{
	mfloat_t v0[VEC2_SIZE] = {3.0f, 4.0f};
	mfloat_t v1[VEC2_SIZE] = {2.0f, 5.0f};
	mu_assert(float_eq(26.0f, vec2_dot(v0, v1)), "3*2 + 4*5");
}

MU_TEST(test_vec2_dot_perpendicular)
{
	mfloat_t v0[VEC2_SIZE] = {1.0f, 0.0f};
	mfloat_t v1[VEC2_SIZE] = {0.0f, 1.0f};
	mu_assert(float_eq(0.0f, vec2_dot(v0, v1)), "perpendicular");
}

MU_TEST(test_vec2_length)
{
	mfloat_t v0[VEC2_SIZE] = {3.0f, 4.0f};
	mu_assert(float_eq(5.0f, vec2_length(v0)), "3-4-5 triangle");
}

MU_TEST(test_vec2_length_squared)
{
	mfloat_t v0[VEC2_SIZE] = {3.0f, 4.0f};
	mu_assert(float_eq(25.0f, vec2_length_squared(v0)), "squared");
}

MU_TEST(test_vec2_distance)
{
	mfloat_t v0[VEC2_SIZE] = {0.0f, 0.0f};
	mfloat_t v1[VEC2_SIZE] = {3.0f, 4.0f};
	mu_assert(float_eq(5.0f, vec2_distance(v0, v1)), "distance");
}

MU_TEST(test_vec2_lerp)
{
	mfloat_t v0[VEC2_SIZE] = {0.0f, 0.0f};
	mfloat_t v1[VEC2_SIZE] = {10.0f, 20.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_lerp(result, v0, v1, 0.5f);
	mu_assert(float_eq(5.0f, result[0]), "x");
	mu_assert(float_eq(10.0f, result[1]), "y");
}

MU_TEST(test_vec2_lerp_endpoints)
{
	mfloat_t v0[VEC2_SIZE] = {1.0f, 2.0f};
	mfloat_t v1[VEC2_SIZE] = {10.0f, 20.0f};
	mfloat_t r0[VEC2_SIZE], r1[VEC2_SIZE];
	vec2_lerp(r0, v0, v1, 0.0f);
	vec2_lerp(r1, v0, v1, 1.0f);
	mu_assert(float_eq(1.0f, r0[0]), "t=0 x");
	mu_assert(float_eq(10.0f, r1[0]), "t=1 x");
}

MU_TEST(test_vec2_tangent)
{
	mfloat_t v0[VEC2_SIZE] = {3.0f, 5.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_tangent(result, v0);
	mu_assert(float_eq(5.0f, result[0]), "x");
	mu_assert(float_eq(-3.0f, result[1]), "y");
}

MU_TEST(test_vec2_angle)
{
	mfloat_t v0[VEC2_SIZE] = {1.0f, 0.0f};
	mfloat_t v1[VEC2_SIZE] = {0.0f, 1.0f};
	mu_assert(float_eq(0.0f, vec2_angle(v0)), "(1,0)");
	mu_assert(float_eq(MPI_2, vec2_angle(v1)), "(0,1)");
}

MU_TEST(test_vec2_rotate)
{
	mfloat_t v0[VEC2_SIZE] = {1.0f, 0.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_rotate(result, v0, MPI_2);
	mu_assert(float_eq(0.0f, result[0]), "x");
	mu_assert(float_eq(1.0f, result[1]), "y");
}

MU_TEST(test_vec2_sign)
{
	mfloat_t v0[VEC2_SIZE] = {-5.0f, 10.0f};
	mfloat_t result[VEC2_SIZE];
	vec2_sign(result, v0);
	mu_assert(float_eq(-1.0f, result[0]), "negative");
	mu_assert(float_eq(1.0f, result[1]), "positive");
}

/* struct API */

MU_TEST(test_svec2_create)
{
	struct vec2 v = svec2(3.5f, 7.25f);
	mu_assert(float_eq(3.5f, v.x), "x");
	mu_assert(float_eq(7.25f, v.y), "y");
}

MU_TEST(test_svec2_zero)
{
	struct vec2 v = svec2_zero();
	mu_assert(float_eq(0.0f, v.x), "x");
	mu_assert(float_eq(0.0f, v.y), "y");
}

MU_TEST(test_svec2_add)
{
	struct vec2 v0 = svec2(3.0f, 5.0f);
	struct vec2 v1 = svec2(2.0f, 4.0f);
	struct vec2 result = svec2_add(v0, v1);
	mu_assert(float_eq(5.0f, result.x), "x");
	mu_assert(float_eq(9.0f, result.y), "y");
}

MU_TEST(test_svec2_subtract)
{
	struct vec2 v0 = svec2(10.0f, 20.0f);
	struct vec2 v1 = svec2(3.0f, 5.0f);
	struct vec2 result = svec2_subtract(v0, v1);
	mu_assert(float_eq(7.0f, result.x), "x");
	mu_assert(float_eq(15.0f, result.y), "y");
}

MU_TEST(test_svec2_multiply)
{
	struct vec2 v0 = svec2(3.0f, 5.0f);
	struct vec2 v1 = svec2(2.0f, 4.0f);
	struct vec2 result = svec2_multiply(v0, v1);
	mu_assert(float_eq(6.0f, result.x), "x");
	mu_assert(float_eq(20.0f, result.y), "y");
}

MU_TEST(test_svec2_normalize)
{
	struct vec2 v0 = svec2(3.0f, 4.0f);
	struct vec2 result = svec2_normalize(v0);
	mu_assert(float_eq(0.6f, result.x), "x");
	mu_assert(float_eq(0.8f, result.y), "y");
}

MU_TEST(test_svec2_dot)
{
	struct vec2 v0 = svec2(3.0f, 4.0f);
	struct vec2 v1 = svec2(2.0f, 5.0f);
	mu_assert(float_eq(26.0f, svec2_dot(v0, v1)), "dot");
}

MU_TEST(test_svec2_length)
{
	struct vec2 v0 = svec2(3.0f, 4.0f);
	mu_assert(float_eq(5.0f, svec2_length(v0)), "length");
}

MU_TEST(test_svec2_lerp)
{
	struct vec2 v0 = svec2(0.0f, 0.0f);
	struct vec2 v1 = svec2(10.0f, 20.0f);
	struct vec2 result = svec2_lerp(v0, v1, 0.5f);
	mu_assert(float_eq(5.0f, result.x), "x");
	mu_assert(float_eq(10.0f, result.y), "y");
}

MU_TEST(test_svec2_rotate)
{
	struct vec2 v0 = svec2(1.0f, 0.0f);
	struct vec2 result = svec2_rotate(v0, MPI_2);
	mu_assert(float_eq(0.0f, result.x), "x");
	mu_assert(float_eq(1.0f, result.y), "y");
}

MU_TEST(test_svec2_chained)
{
	struct vec2 a = svec2(1.0f, 2.0f);
	struct vec2 b = svec2(3.0f, 4.0f);
	struct vec2 result = svec2_multiply_f(svec2_add(a, b), 2.0f);
	mu_assert(float_eq(8.0f, result.x), "x");
	mu_assert(float_eq(12.0f, result.y), "y");
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_vec2_create);
	MU_RUN_TEST(test_vec2_zero);
	MU_RUN_TEST(test_vec2_one);
	MU_RUN_TEST(test_vec2_is_zero);
	MU_RUN_TEST(test_vec2_add);
	MU_RUN_TEST(test_vec2_add_f);
	MU_RUN_TEST(test_vec2_subtract);
	MU_RUN_TEST(test_vec2_multiply);
	MU_RUN_TEST(test_vec2_multiply_f);
	MU_RUN_TEST(test_vec2_divide);
	MU_RUN_TEST(test_vec2_negative);
	MU_RUN_TEST(test_vec2_abs);
	MU_RUN_TEST(test_vec2_floor);
	MU_RUN_TEST(test_vec2_ceil);
	MU_RUN_TEST(test_vec2_round);
	MU_RUN_TEST(test_vec2_max);
	MU_RUN_TEST(test_vec2_min);
	MU_RUN_TEST(test_vec2_clamp);
	MU_RUN_TEST(test_vec2_normalize);
	MU_RUN_TEST(test_vec2_normalize_zero);
	MU_RUN_TEST(test_vec2_dot);
	MU_RUN_TEST(test_vec2_dot_perpendicular);
	MU_RUN_TEST(test_vec2_length);
	MU_RUN_TEST(test_vec2_length_squared);
	MU_RUN_TEST(test_vec2_distance);
	MU_RUN_TEST(test_vec2_lerp);
	MU_RUN_TEST(test_vec2_lerp_endpoints);
	MU_RUN_TEST(test_vec2_tangent);
	MU_RUN_TEST(test_vec2_angle);
	MU_RUN_TEST(test_vec2_rotate);
	MU_RUN_TEST(test_vec2_sign);

	MU_RUN_TEST(test_svec2_create);
	MU_RUN_TEST(test_svec2_zero);
	MU_RUN_TEST(test_svec2_add);
	MU_RUN_TEST(test_svec2_subtract);
	MU_RUN_TEST(test_svec2_multiply);
	MU_RUN_TEST(test_svec2_normalize);
	MU_RUN_TEST(test_svec2_dot);
	MU_RUN_TEST(test_svec2_length);
	MU_RUN_TEST(test_svec2_lerp);
	MU_RUN_TEST(test_svec2_rotate);
	MU_RUN_TEST(test_svec2_chained);
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
