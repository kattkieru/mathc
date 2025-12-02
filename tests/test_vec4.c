#include <float.h>

#include "mathc.h"
#include "minunit.h"

#define EPSILON 0.0001f

static bool float_eq(mfloat_t a, mfloat_t b)
{
	return MFABS(a - b) < EPSILON;
}

MU_TEST(test_vec4_create)
{
	mfloat_t result[VEC4_SIZE];
	vec4(result, 3.5f, 7.25f, 11.5f, 1.0f);
	mu_assert(float_eq(3.5f, result[0]), "x");
	mu_assert(float_eq(7.25f, result[1]), "y");
	mu_assert(float_eq(11.5f, result[2]), "z");
	mu_assert(float_eq(1.0f, result[3]), "w");
}

MU_TEST(test_vec4_zero)
{
	mfloat_t result[VEC4_SIZE];
	vec4_zero(result);
	for (int i = 0; i < VEC4_SIZE; i++) {
		mu_assert(float_eq(0.0f, result[i]), "zero");
	}
}

MU_TEST(test_vec4_one)
{
	mfloat_t result[VEC4_SIZE];
	vec4_one(result);
	for (int i = 0; i < VEC4_SIZE; i++) {
		mu_assert(float_eq(1.0f, result[i]), "one");
	}
}

MU_TEST(test_vec4_is_zero)
{
	mfloat_t v1[VEC4_SIZE] = {0.0f, 0.0f, 0.0f, 0.0f};
	mfloat_t v2[VEC4_SIZE] = {0.0f, 0.0f, 0.0f, 0.001f};
	mu_assert(vec4_is_zero(v1), "zero");
	mu_assert(!vec4_is_zero(v2), "not zero");
}

MU_TEST(test_vec4_add)
{
	mfloat_t v0[VEC4_SIZE] = {3.0f, 5.0f, 7.0f, 9.0f};
	mfloat_t v1[VEC4_SIZE] = {2.0f, 4.0f, 6.0f, 8.0f};
	mfloat_t result[VEC4_SIZE];
	vec4_add(result, v0, v1);
	mu_assert(float_eq(5.0f, result[0]), "x");
	mu_assert(float_eq(9.0f, result[1]), "y");
	mu_assert(float_eq(13.0f, result[2]), "z");
	mu_assert(float_eq(17.0f, result[3]), "w");
}

MU_TEST(test_vec4_subtract)
{
	mfloat_t v0[VEC4_SIZE] = {10.0f, 20.0f, 30.0f, 40.0f};
	mfloat_t v1[VEC4_SIZE] = {3.0f, 5.0f, 7.0f, 9.0f};
	mfloat_t result[VEC4_SIZE];
	vec4_subtract(result, v0, v1);
	mu_assert(float_eq(7.0f, result[0]), "x");
	mu_assert(float_eq(15.0f, result[1]), "y");
	mu_assert(float_eq(23.0f, result[2]), "z");
	mu_assert(float_eq(31.0f, result[3]), "w");
}

MU_TEST(test_vec4_multiply)
{
	mfloat_t v0[VEC4_SIZE] = {3.0f, 5.0f, 7.0f, 9.0f};
	mfloat_t v1[VEC4_SIZE] = {2.0f, 4.0f, 6.0f, 8.0f};
	mfloat_t result[VEC4_SIZE];
	vec4_multiply(result, v0, v1);
	mu_assert(float_eq(6.0f, result[0]), "x");
	mu_assert(float_eq(20.0f, result[1]), "y");
	mu_assert(float_eq(42.0f, result[2]), "z");
	mu_assert(float_eq(72.0f, result[3]), "w");
}

MU_TEST(test_vec4_divide)
{
	mfloat_t v0[VEC4_SIZE] = {10.0f, 20.0f, 30.0f, 40.0f};
	mfloat_t v1[VEC4_SIZE] = {2.0f, 4.0f, 5.0f, 8.0f};
	mfloat_t result[VEC4_SIZE];
	vec4_divide(result, v0, v1);
	mu_assert(float_eq(5.0f, result[0]), "x");
	mu_assert(float_eq(5.0f, result[1]), "y");
	mu_assert(float_eq(6.0f, result[2]), "z");
	mu_assert(float_eq(5.0f, result[3]), "w");
}

MU_TEST(test_vec4_negative)
{
	mfloat_t v0[VEC4_SIZE] = {3.0f, -5.0f, 7.0f, -9.0f};
	mfloat_t result[VEC4_SIZE];
	vec4_negative(result, v0);
	mu_assert(float_eq(-3.0f, result[0]), "x");
	mu_assert(float_eq(5.0f, result[1]), "y");
	mu_assert(float_eq(-7.0f, result[2]), "z");
	mu_assert(float_eq(9.0f, result[3]), "w");
}

MU_TEST(test_vec4_normalize)
{
	mfloat_t v0[VEC4_SIZE] = {2.0f, 0.0f, 0.0f, 0.0f};
	mfloat_t result[VEC4_SIZE];
	vec4_normalize(result, v0);
	mu_assert(float_eq(1.0f, result[0]), "x");
	mu_assert(float_eq(0.0f, result[1]), "y");
}

MU_TEST(test_vec4_lerp)
{
	mfloat_t v0[VEC4_SIZE] = {0.0f, 0.0f, 0.0f, 0.0f};
	mfloat_t v1[VEC4_SIZE] = {10.0f, 20.0f, 30.0f, 40.0f};
	mfloat_t result[VEC4_SIZE];
	vec4_lerp(result, v0, v1, 0.5f);
	mu_assert(float_eq(5.0f, result[0]), "x");
	mu_assert(float_eq(10.0f, result[1]), "y");
	mu_assert(float_eq(15.0f, result[2]), "z");
	mu_assert(float_eq(20.0f, result[3]), "w");
}

MU_TEST(test_vec4_clamp)
{
	mfloat_t v0[VEC4_SIZE] = {-5.0f, 15.0f, 5.0f, 25.0f};
	mfloat_t vmin[VEC4_SIZE] = {0.0f, 0.0f, 0.0f, 0.0f};
	mfloat_t vmax[VEC4_SIZE] = {10.0f, 10.0f, 10.0f, 10.0f};
	mfloat_t result[VEC4_SIZE];
	vec4_clamp(result, v0, vmin, vmax);
	mu_assert(float_eq(0.0f, result[0]), "clamped min");
	mu_assert(float_eq(10.0f, result[1]), "clamped max");
	mu_assert(float_eq(5.0f, result[2]), "unchanged");
	mu_assert(float_eq(10.0f, result[3]), "clamped max");
}

/* struct API */

MU_TEST(test_svec4_create)
{
	struct vec4 v = svec4(3.5f, 7.25f, 11.5f, 1.0f);
	mu_assert(float_eq(3.5f, v.x), "x");
	mu_assert(float_eq(7.25f, v.y), "y");
	mu_assert(float_eq(11.5f, v.z), "z");
	mu_assert(float_eq(1.0f, v.w), "w");
}

MU_TEST(test_svec4_add)
{
	struct vec4 v0 = svec4(3.0f, 5.0f, 7.0f, 9.0f);
	struct vec4 v1 = svec4(2.0f, 4.0f, 6.0f, 8.0f);
	struct vec4 result = svec4_add(v0, v1);
	mu_assert(float_eq(5.0f, result.x), "x");
	mu_assert(float_eq(9.0f, result.y), "y");
	mu_assert(float_eq(13.0f, result.z), "z");
	mu_assert(float_eq(17.0f, result.w), "w");
}

MU_TEST(test_svec4_normalize)
{
	struct vec4 v0 = svec4(2.0f, 0.0f, 0.0f, 0.0f);
	struct vec4 result = svec4_normalize(v0);
	mu_assert(float_eq(1.0f, result.x), "x");
	mu_assert(float_eq(0.0f, result.y), "y");
}

MU_TEST(test_svec4_lerp)
{
	struct vec4 v0 = svec4(0.0f, 0.0f, 0.0f, 0.0f);
	struct vec4 v1 = svec4(10.0f, 20.0f, 30.0f, 40.0f);
	struct vec4 result = svec4_lerp(v0, v1, 0.5f);
	mu_assert(float_eq(5.0f, result.x), "x");
	mu_assert(float_eq(10.0f, result.y), "y");
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_vec4_create);
	MU_RUN_TEST(test_vec4_zero);
	MU_RUN_TEST(test_vec4_one);
	MU_RUN_TEST(test_vec4_is_zero);
	MU_RUN_TEST(test_vec4_add);
	MU_RUN_TEST(test_vec4_subtract);
	MU_RUN_TEST(test_vec4_multiply);
	MU_RUN_TEST(test_vec4_divide);
	MU_RUN_TEST(test_vec4_negative);
	MU_RUN_TEST(test_vec4_normalize);
	MU_RUN_TEST(test_vec4_lerp);
	MU_RUN_TEST(test_vec4_clamp);

	MU_RUN_TEST(test_svec4_create);
	MU_RUN_TEST(test_svec4_add);
	MU_RUN_TEST(test_svec4_normalize);
	MU_RUN_TEST(test_svec4_lerp);
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
