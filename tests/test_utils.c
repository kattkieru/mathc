#include <float.h>

#include "mathc.h"
#include "minunit.h"

#define EPSILON 0.0001f

static bool float_eq(mfloat_t a, mfloat_t b)
{
	return MFABS(a - b) < EPSILON;
}

MU_TEST(test_clampi_within_range)
{
	mu_assert_int_eq(5, clampi(5, 0, 10));
	mu_assert_int_eq(0, clampi(0, 0, 10));
	mu_assert_int_eq(10, clampi(10, 0, 10));
}

MU_TEST(test_clampi_below_min)
{
	mu_assert_int_eq(0, clampi(-5, 0, 10));
	mu_assert_int_eq(-10, clampi(-100, -10, 10));
}

MU_TEST(test_clampi_above_max)
{
	mu_assert_int_eq(10, clampi(15, 0, 10));
	mu_assert_int_eq(100, clampi(1000, -100, 100));
}

MU_TEST(test_clampi_negative_range)
{
	mu_assert_int_eq(-5, clampi(-5, -10, -1));
	mu_assert_int_eq(-10, clampi(-100, -10, -1));
	mu_assert_int_eq(-1, clampi(0, -10, -1));
}

MU_TEST(test_clampf_within_range)
{
	mu_assert(float_eq(5.0f, clampf(5.0f, 0.0f, 10.0f)), "clampf within range");
	mu_assert(float_eq(0.0f, clampf(0.0f, 0.0f, 10.0f)), "clampf at min");
	mu_assert(float_eq(10.0f, clampf(10.0f, 0.0f, 10.0f)), "clampf at max");
}

MU_TEST(test_clampf_below_min)
{
	mu_assert(float_eq(0.0f, clampf(-5.0f, 0.0f, 10.0f)), "clampf below min");
	mu_assert(float_eq(-10.0f, clampf(-100.0f, -10.0f, 10.0f)), "clampf below negative min");
}

MU_TEST(test_clampf_above_max)
{
	mu_assert(float_eq(10.0f, clampf(15.0f, 0.0f, 10.0f)), "clampf above max");
	mu_assert(float_eq(1.0f, clampf(100.0f, 0.0f, 1.0f)), "clampf above max normalized");
}

MU_TEST(test_clampf_fractional)
{
	mu_assert(float_eq(0.5f, clampf(0.5f, 0.0f, 1.0f)), "clampf fractional within");
	mu_assert(float_eq(0.0f, clampf(-0.1f, 0.0f, 1.0f)), "clampf fractional below");
	mu_assert(float_eq(1.0f, clampf(1.1f, 0.0f, 1.0f)), "clampf fractional above");
}

MU_TEST(test_nearly_equal_identical)
{
	mu_assert(nearly_equal(1.0f, 1.0f, EPSILON), "identical values");
	mu_assert(nearly_equal(0.0f, 0.0f, EPSILON), "identical zero");
	mu_assert(nearly_equal(-5.0f, -5.0f, EPSILON), "identical negative");
}

MU_TEST(test_nearly_equal_within_epsilon)
{
	mu_assert(nearly_equal(1.0f, 1.0f + EPSILON * 0.5f, EPSILON), "within epsilon");
	mu_assert(nearly_equal(0.0f, EPSILON * 0.5f, EPSILON), "near zero within epsilon");
}

MU_TEST(test_nearly_equal_outside_epsilon)
{
	mu_assert(!nearly_equal(1.0f, 1.0f + EPSILON * 2.0f, EPSILON), "outside epsilon");
	mu_assert(!nearly_equal(0.0f, 1.0f, EPSILON), "very different values");
}

MU_TEST(test_nearly_equal_custom_epsilon)
{
	mu_assert(nearly_equal(1.0f, 1.5f, 1.0f), "large epsilon");
	mu_assert(!nearly_equal(1.0f, 1.5f, 0.1f), "small epsilon");
}

MU_TEST(test_to_radians_zero)
{
	mu_assert(float_eq(0.0f, to_radians(0.0f)), "0 deg");
}

MU_TEST(test_to_radians_90)
{
	mu_assert(float_eq(MPI_2, to_radians(90.0f)), "90 deg");
}

MU_TEST(test_to_radians_180)
{
	mu_assert(float_eq(MPI, to_radians(180.0f)), "180 deg");
}

MU_TEST(test_to_radians_360)
{
	mu_assert(float_eq(MPI * 2.0f, to_radians(360.0f)), "360 deg");
}

MU_TEST(test_to_radians_negative)
{
	mu_assert(float_eq(-MPI_2, to_radians(-90.0f)), "-90 deg");
}

MU_TEST(test_to_radians_45)
{
	mu_assert(float_eq(MPI_4, to_radians(45.0f)), "45 deg");
}

MU_TEST(test_to_degrees_zero)
{
	mu_assert(float_eq(0.0f, to_degrees(0.0f)), "0 rad");
}

MU_TEST(test_to_degrees_pi_2)
{
	mu_assert(float_eq(90.0f, to_degrees(MPI_2)), "pi/2 rad");
}

MU_TEST(test_to_degrees_pi)
{
	mu_assert(float_eq(180.0f, to_degrees(MPI)), "pi rad");
}

MU_TEST(test_to_degrees_2pi)
{
	mu_assert(float_eq(360.0f, to_degrees(MPI * 2.0f)), "2pi rad");
}

MU_TEST(test_to_degrees_negative)
{
	mu_assert(float_eq(-90.0f, to_degrees(-MPI_2)), "-pi/2 rad");
}

MU_TEST(test_to_degrees_roundtrip)
{
	mfloat_t original = 123.456f;
	mfloat_t result = to_degrees(to_radians(original));
	mu_assert(float_eq(original, result), "roundtrip");
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_clampi_within_range);
	MU_RUN_TEST(test_clampi_below_min);
	MU_RUN_TEST(test_clampi_above_max);
	MU_RUN_TEST(test_clampi_negative_range);

	MU_RUN_TEST(test_clampf_within_range);
	MU_RUN_TEST(test_clampf_below_min);
	MU_RUN_TEST(test_clampf_above_max);
	MU_RUN_TEST(test_clampf_fractional);

	MU_RUN_TEST(test_nearly_equal_identical);
	MU_RUN_TEST(test_nearly_equal_within_epsilon);
	MU_RUN_TEST(test_nearly_equal_outside_epsilon);
	MU_RUN_TEST(test_nearly_equal_custom_epsilon);

	MU_RUN_TEST(test_to_radians_zero);
	MU_RUN_TEST(test_to_radians_90);
	MU_RUN_TEST(test_to_radians_180);
	MU_RUN_TEST(test_to_radians_360);
	MU_RUN_TEST(test_to_radians_negative);
	MU_RUN_TEST(test_to_radians_45);

	MU_RUN_TEST(test_to_degrees_zero);
	MU_RUN_TEST(test_to_degrees_pi_2);
	MU_RUN_TEST(test_to_degrees_pi);
	MU_RUN_TEST(test_to_degrees_2pi);
	MU_RUN_TEST(test_to_degrees_negative);
	MU_RUN_TEST(test_to_degrees_roundtrip);
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
