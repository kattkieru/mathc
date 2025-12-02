#include <float.h>

#include "mathc.h"
#include "minunit.h"

#define EPSILON 0.0001f

static bool float_eq(mfloat_t a, mfloat_t b)
{
	return MFABS(a - b) < EPSILON;
}

MU_TEST(test_vec3_create)
{
	mfloat_t result[VEC3_SIZE];
	vec3(result, 3.5f, 7.25f, 11.5f);
	mu_assert(float_eq(3.5f, result[0]), "x");
	mu_assert(float_eq(7.25f, result[1]), "y");
	mu_assert(float_eq(11.5f, result[2]), "z");
}

MU_TEST(test_vec3_zero)
{
	mfloat_t result[VEC3_SIZE];
	vec3_zero(result);
	mu_assert(float_eq(0.0f, result[0]), "x");
	mu_assert(float_eq(0.0f, result[1]), "y");
	mu_assert(float_eq(0.0f, result[2]), "z");
}

MU_TEST(test_vec3_is_zero)
{
	mfloat_t v1[VEC3_SIZE] = {0.0f, 0.0f, 0.0f};
	mfloat_t v2[VEC3_SIZE] = {0.0f, 0.0f, 0.001f};
	mu_assert(vec3_is_zero(v1), "zero");
	mu_assert(!vec3_is_zero(v2), "not zero");
}

MU_TEST(test_vec3_add)
{
	mfloat_t v0[VEC3_SIZE] = {3.0f, 5.0f, 7.0f};
	mfloat_t v1[VEC3_SIZE] = {2.0f, 4.0f, 6.0f};
	mfloat_t result[VEC3_SIZE];
	vec3_add(result, v0, v1);
	mu_assert(float_eq(5.0f, result[0]), "x");
	mu_assert(float_eq(9.0f, result[1]), "y");
	mu_assert(float_eq(13.0f, result[2]), "z");
}

MU_TEST(test_vec3_subtract)
{
	mfloat_t v0[VEC3_SIZE] = {10.0f, 20.0f, 30.0f};
	mfloat_t v1[VEC3_SIZE] = {3.0f, 5.0f, 7.0f};
	mfloat_t result[VEC3_SIZE];
	vec3_subtract(result, v0, v1);
	mu_assert(float_eq(7.0f, result[0]), "x");
	mu_assert(float_eq(15.0f, result[1]), "y");
	mu_assert(float_eq(23.0f, result[2]), "z");
}

MU_TEST(test_vec3_multiply)
{
	mfloat_t v0[VEC3_SIZE] = {3.0f, 5.0f, 7.0f};
	mfloat_t v1[VEC3_SIZE] = {2.0f, 4.0f, 6.0f};
	mfloat_t result[VEC3_SIZE];
	vec3_multiply(result, v0, v1);
	mu_assert(float_eq(6.0f, result[0]), "x");
	mu_assert(float_eq(20.0f, result[1]), "y");
	mu_assert(float_eq(42.0f, result[2]), "z");
}

MU_TEST(test_vec3_divide)
{
	mfloat_t v0[VEC3_SIZE] = {10.0f, 20.0f, 30.0f};
	mfloat_t v1[VEC3_SIZE] = {2.0f, 4.0f, 5.0f};
	mfloat_t result[VEC3_SIZE];
	vec3_divide(result, v0, v1);
	mu_assert(float_eq(5.0f, result[0]), "x");
	mu_assert(float_eq(5.0f, result[1]), "y");
	mu_assert(float_eq(6.0f, result[2]), "z");
}

MU_TEST(test_vec3_cross)
{
	mfloat_t x[VEC3_SIZE] = {1.0f, 0.0f, 0.0f};
	mfloat_t y[VEC3_SIZE] = {0.0f, 1.0f, 0.0f};
	mfloat_t result[VEC3_SIZE];

	vec3_cross(result, x, y);
	mu_assert(float_eq(0.0f, result[0]), "x");
	mu_assert(float_eq(0.0f, result[1]), "y");
	mu_assert(float_eq(1.0f, result[2]), "z");

	vec3_cross(result, y, x);
	mu_assert(float_eq(-1.0f, result[2]), "reversed");
}

MU_TEST(test_vec3_cross_parallel)
{
	mfloat_t v0[VEC3_SIZE] = {2.0f, 0.0f, 0.0f};
	mfloat_t v1[VEC3_SIZE] = {4.0f, 0.0f, 0.0f};
	mfloat_t result[VEC3_SIZE];
	vec3_cross(result, v0, v1);
	mu_assert(float_eq(0.0f, result[0]), "x");
	mu_assert(float_eq(0.0f, result[1]), "y");
	mu_assert(float_eq(0.0f, result[2]), "z");
}

MU_TEST(test_vec3_negative)
{
	mfloat_t v0[VEC3_SIZE] = {3.0f, -5.0f, 7.0f};
	mfloat_t result[VEC3_SIZE];
	vec3_negative(result, v0);
	mu_assert(float_eq(-3.0f, result[0]), "x");
	mu_assert(float_eq(5.0f, result[1]), "y");
	mu_assert(float_eq(-7.0f, result[2]), "z");
}

MU_TEST(test_vec3_normalize)
{
	mfloat_t v0[VEC3_SIZE] = {5.0f, 0.0f, 0.0f};
	mfloat_t result[VEC3_SIZE];
	vec3_normalize(result, v0);
	mu_assert(float_eq(1.0f, result[0]), "x");
	mu_assert(float_eq(0.0f, result[1]), "y");
	mu_assert(float_eq(0.0f, result[2]), "z");
}

MU_TEST(test_vec3_dot)
{
	mfloat_t v0[VEC3_SIZE] = {3.0f, 4.0f, 5.0f};
	mfloat_t v1[VEC3_SIZE] = {2.0f, 3.0f, 4.0f};
	mu_assert(float_eq(38.0f, vec3_dot(v0, v1)), "3*2 + 4*3 + 5*4");
}

MU_TEST(test_vec3_length)
{
	mfloat_t v0[VEC3_SIZE] = {2.0f, 3.0f, 6.0f};
	mu_assert(float_eq(7.0f, vec3_length(v0)), "sqrt(49)");
}

MU_TEST(test_vec3_distance)
{
	mfloat_t v0[VEC3_SIZE] = {0.0f, 0.0f, 0.0f};
	mfloat_t v1[VEC3_SIZE] = {2.0f, 3.0f, 6.0f};
	mu_assert(float_eq(7.0f, vec3_distance(v0, v1)), "distance");
}

MU_TEST(test_vec3_lerp)
{
	mfloat_t v0[VEC3_SIZE] = {0.0f, 0.0f, 0.0f};
	mfloat_t v1[VEC3_SIZE] = {10.0f, 20.0f, 30.0f};
	mfloat_t result[VEC3_SIZE];
	vec3_lerp(result, v0, v1, 0.5f);
	mu_assert(float_eq(5.0f, result[0]), "x");
	mu_assert(float_eq(10.0f, result[1]), "y");
	mu_assert(float_eq(15.0f, result[2]), "z");
}

MU_TEST(test_vec3_clamp)
{
	mfloat_t v0[VEC3_SIZE] = {-5.0f, 15.0f, 5.0f};
	mfloat_t vmin[VEC3_SIZE] = {0.0f, 0.0f, 0.0f};
	mfloat_t vmax[VEC3_SIZE] = {10.0f, 10.0f, 10.0f};
	mfloat_t result[VEC3_SIZE];
	vec3_clamp(result, v0, vmin, vmax);
	mu_assert(float_eq(0.0f, result[0]), "clamped to min");
	mu_assert(float_eq(10.0f, result[1]), "clamped to max");
	mu_assert(float_eq(5.0f, result[2]), "unchanged");
}

/* struct API */

MU_TEST(test_svec3_create)
{
	struct vec3 v = svec3(3.5f, 7.25f, 11.5f);
	mu_assert(float_eq(3.5f, v.x), "x");
	mu_assert(float_eq(7.25f, v.y), "y");
	mu_assert(float_eq(11.5f, v.z), "z");
}

MU_TEST(test_svec3_add)
{
	struct vec3 v0 = svec3(3.0f, 5.0f, 7.0f);
	struct vec3 v1 = svec3(2.0f, 4.0f, 6.0f);
	struct vec3 result = svec3_add(v0, v1);
	mu_assert(float_eq(5.0f, result.x), "x");
	mu_assert(float_eq(9.0f, result.y), "y");
	mu_assert(float_eq(13.0f, result.z), "z");
}

MU_TEST(test_svec3_cross)
{
	struct vec3 x = svec3(1.0f, 0.0f, 0.0f);
	struct vec3 y = svec3(0.0f, 1.0f, 0.0f);
	struct vec3 result = svec3_cross(x, y);
	mu_assert(float_eq(0.0f, result.x), "x");
	mu_assert(float_eq(0.0f, result.y), "y");
	mu_assert(float_eq(1.0f, result.z), "z");
}

MU_TEST(test_svec3_normalize)
{
	struct vec3 v0 = svec3(5.0f, 0.0f, 0.0f);
	struct vec3 result = svec3_normalize(v0);
	mu_assert(float_eq(1.0f, result.x), "x");
	mu_assert(float_eq(0.0f, result.y), "y");
	mu_assert(float_eq(0.0f, result.z), "z");
}

MU_TEST(test_svec3_dot)
{
	struct vec3 v0 = svec3(3.0f, 4.0f, 5.0f);
	struct vec3 v1 = svec3(2.0f, 3.0f, 4.0f);
	mu_assert(float_eq(38.0f, svec3_dot(v0, v1)), "dot");
}

MU_TEST(test_svec3_length)
{
	struct vec3 v0 = svec3(2.0f, 3.0f, 6.0f);
	mu_assert(float_eq(7.0f, svec3_length(v0)), "length");
}

MU_TEST(test_svec3_chained)
{
	struct vec3 a = svec3(1.0f, 2.0f, 3.0f);
	struct vec3 b = svec3(4.0f, 5.0f, 6.0f);
	struct vec3 result = svec3_multiply_f(svec3_add(a, b), 2.0f);
	mu_assert(float_eq(10.0f, result.x), "x");
	mu_assert(float_eq(14.0f, result.y), "y");
	mu_assert(float_eq(18.0f, result.z), "z");
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_vec3_create);
	MU_RUN_TEST(test_vec3_zero);
	MU_RUN_TEST(test_vec3_is_zero);
	MU_RUN_TEST(test_vec3_add);
	MU_RUN_TEST(test_vec3_subtract);
	MU_RUN_TEST(test_vec3_multiply);
	MU_RUN_TEST(test_vec3_divide);
	MU_RUN_TEST(test_vec3_cross);
	MU_RUN_TEST(test_vec3_cross_parallel);
	MU_RUN_TEST(test_vec3_negative);
	MU_RUN_TEST(test_vec3_normalize);
	MU_RUN_TEST(test_vec3_dot);
	MU_RUN_TEST(test_vec3_length);
	MU_RUN_TEST(test_vec3_distance);
	MU_RUN_TEST(test_vec3_lerp);
	MU_RUN_TEST(test_vec3_clamp);

	MU_RUN_TEST(test_svec3_create);
	MU_RUN_TEST(test_svec3_add);
	MU_RUN_TEST(test_svec3_cross);
	MU_RUN_TEST(test_svec3_normalize);
	MU_RUN_TEST(test_svec3_dot);
	MU_RUN_TEST(test_svec3_length);
	MU_RUN_TEST(test_svec3_chained);
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
