#include "minunit.h"
#include "mathc.h"
#include <float.h>


#define EPSILON 0.0001f

static bool float_eq(mfloat_t a, mfloat_t b)
{
    return MFABS(a - b) < EPSILON;
}

// All easing functions should:
// - Return 0.0 when input is 0.0
// - Return 1.0 when input is 1.0
// - Return values generally between 0 and 1 for inputs between 0 and 1
//   (some functions like elastic and back may overshoot)


// Quadratic easing tests
MU_TEST(test_quadratic_ease_in_endpoints)
{
    mu_assert(float_eq(0.0f, quadratic_ease_in(0.0f)), "ease_in(0) = 0");
    mu_assert(float_eq(1.0f, quadratic_ease_in(1.0f)), "ease_in(1) = 1");
}

MU_TEST(test_quadratic_ease_in_midpoint)
{
    mfloat_t result = quadratic_ease_in(0.5f);
    mu_assert(result > 0.0f && result < 1.0f, "ease_in(0.5) in (0,1)");
    mu_assert(result < 0.5f, "quadratic ease_in slower at start");
}

MU_TEST(test_quadratic_ease_out_endpoints)
{
    mu_assert(float_eq(0.0f, quadratic_ease_out(0.0f)), "ease_out(0) = 0");
    mu_assert(float_eq(1.0f, quadratic_ease_out(1.0f)), "ease_out(1) = 1");
}

MU_TEST(test_quadratic_ease_out_midpoint)
{
    mfloat_t result = quadratic_ease_out(0.5f);
    mu_assert(result > 0.5f, "quadratic ease_out faster at start");
}

MU_TEST(test_quadratic_ease_in_out_endpoints)
{
    mu_assert(float_eq(0.0f, quadratic_ease_in_out(0.0f)), "ease_in_out(0) = 0");
    mu_assert(float_eq(1.0f, quadratic_ease_in_out(1.0f)), "ease_in_out(1) = 1");
}

MU_TEST(test_quadratic_ease_in_out_midpoint)
{
    mfloat_t result = quadratic_ease_in_out(0.5f);
    mu_assert(float_eq(0.5f, result), "ease_in_out(0.5) = 0.5");
}


// Cubic easing tests
MU_TEST(test_cubic_ease_in_endpoints)
{
    mu_assert(float_eq(0.0f, cubic_ease_in(0.0f)), "ease_in(0) = 0");
    mu_assert(float_eq(1.0f, cubic_ease_in(1.0f)), "ease_in(1) = 1");
}

MU_TEST(test_cubic_ease_out_endpoints)
{
    mu_assert(float_eq(0.0f, cubic_ease_out(0.0f)), "ease_out(0) = 0");
    mu_assert(float_eq(1.0f, cubic_ease_out(1.0f)), "ease_out(1) = 1");
}

MU_TEST(test_cubic_ease_in_out_endpoints)
{
    mu_assert(float_eq(0.0f, cubic_ease_in_out(0.0f)), "ease_in_out(0) = 0");
    mu_assert(float_eq(1.0f, cubic_ease_in_out(1.0f)), "ease_in_out(1) = 1");
}

// Quartic easing tests
MU_TEST(test_quartic_ease_in_endpoints)
{
    mu_assert(float_eq(0.0f, quartic_ease_in(0.0f)), "ease_in(0) = 0");
    mu_assert(float_eq(1.0f, quartic_ease_in(1.0f)), "ease_in(1) = 1");
}

MU_TEST(test_quartic_ease_out_endpoints)
{
    mu_assert(float_eq(0.0f, quartic_ease_out(0.0f)), "ease_out(0) = 0");
    mu_assert(float_eq(1.0f, quartic_ease_out(1.0f)), "ease_out(1) = 1");
}

MU_TEST(test_quartic_ease_in_out_endpoints)
{
    mu_assert(float_eq(0.0f, quartic_ease_in_out(0.0f)), "ease_in_out(0) = 0");
    mu_assert(float_eq(1.0f, quartic_ease_in_out(1.0f)), "ease_in_out(1) = 1");
}

// Quintic easing tests
MU_TEST(test_quintic_ease_in_endpoints)
{
    mu_assert(float_eq(0.0f, quintic_ease_in(0.0f)), "ease_in(0) = 0");
    mu_assert(float_eq(1.0f, quintic_ease_in(1.0f)), "ease_in(1) = 1");
}

MU_TEST(test_quintic_ease_out_endpoints)
{
    mu_assert(float_eq(0.0f, quintic_ease_out(0.0f)), "ease_out(0) = 0");
    mu_assert(float_eq(1.0f, quintic_ease_out(1.0f)), "ease_out(1) = 1");
}

MU_TEST(test_quintic_ease_in_out_endpoints)
{
    mu_assert(float_eq(0.0f, quintic_ease_in_out(0.0f)), "ease_in_out(0) = 0");
    mu_assert(float_eq(1.0f, quintic_ease_in_out(1.0f)), "ease_in_out(1) = 1");
}

// Sine easing tests
MU_TEST(test_sine_ease_in_endpoints)
{
    mu_assert(float_eq(0.0f, sine_ease_in(0.0f)), "ease_in(0) = 0");
    mu_assert(float_eq(1.0f, sine_ease_in(1.0f)), "ease_in(1) = 1");
}

MU_TEST(test_sine_ease_out_endpoints)
{
    mu_assert(float_eq(0.0f, sine_ease_out(0.0f)), "ease_out(0) = 0");
    mu_assert(float_eq(1.0f, sine_ease_out(1.0f)), "ease_out(1) = 1");
}

MU_TEST(test_sine_ease_in_out_endpoints)
{
    mu_assert(float_eq(0.0f, sine_ease_in_out(0.0f)), "ease_in_out(0) = 0");
    mu_assert(float_eq(1.0f, sine_ease_in_out(1.0f)), "ease_in_out(1) = 1");
}

// Circular easing tests
MU_TEST(test_circular_ease_in_endpoints)
{
    mu_assert(float_eq(0.0f, circular_ease_in(0.0f)), "ease_in(0) = 0");
    mu_assert(float_eq(1.0f, circular_ease_in(1.0f)), "ease_in(1) = 1");
}

MU_TEST(test_circular_ease_out_endpoints)
{
    mu_assert(float_eq(0.0f, circular_ease_out(0.0f)), "ease_out(0) = 0");
    mu_assert(float_eq(1.0f, circular_ease_out(1.0f)), "ease_out(1) = 1");
}

MU_TEST(test_circular_ease_in_out_endpoints)
{
    mu_assert(float_eq(0.0f, circular_ease_in_out(0.0f)), "ease_in_out(0) = 0");
    mu_assert(float_eq(1.0f, circular_ease_in_out(1.0f)), "ease_in_out(1) = 1");
}

// Exponential easing tests
MU_TEST(test_exponential_ease_in_endpoints)
{
    mu_assert(float_eq(0.0f, exponential_ease_in(0.0f)), "ease_in(0) = 0");
    mu_assert(float_eq(1.0f, exponential_ease_in(1.0f)), "ease_in(1) = 1");
}

MU_TEST(test_exponential_ease_out_endpoints)
{
    mu_assert(float_eq(0.0f, exponential_ease_out(0.0f)), "ease_out(0) = 0");
    mu_assert(float_eq(1.0f, exponential_ease_out(1.0f)), "ease_out(1) = 1");
}

MU_TEST(test_exponential_ease_in_out_endpoints)
{
    mu_assert(float_eq(0.0f, exponential_ease_in_out(0.0f)), "ease_in_out(0) = 0");
    mu_assert(float_eq(1.0f, exponential_ease_in_out(1.0f)), "ease_in_out(1) = 1");
}

// Elastic easing tests (can overshoot)
MU_TEST(test_elastic_ease_in_endpoints)
{
    mu_assert(float_eq(0.0f, elastic_ease_in(0.0f)), "ease_in(0) = 0");
    mu_assert(float_eq(1.0f, elastic_ease_in(1.0f)), "ease_in(1) = 1");
}

MU_TEST(test_elastic_ease_out_endpoints)
{
    mu_assert(float_eq(0.0f, elastic_ease_out(0.0f)), "ease_out(0) = 0");
    mu_assert(float_eq(1.0f, elastic_ease_out(1.0f)), "ease_out(1) = 1");
}

MU_TEST(test_elastic_ease_in_out_endpoints)
{
    mu_assert(float_eq(0.0f, elastic_ease_in_out(0.0f)), "ease_in_out(0) = 0");
    mu_assert(float_eq(1.0f, elastic_ease_in_out(1.0f)), "ease_in_out(1) = 1");
}

// Back easing tests (overshoots)
MU_TEST(test_back_ease_in_endpoints)
{
    mu_assert(float_eq(0.0f, back_ease_in(0.0f)), "ease_in(0) = 0");
    mu_assert(float_eq(1.0f, back_ease_in(1.0f)), "ease_in(1) = 1");
}

MU_TEST(test_back_ease_in_overshoots)
{
    // Back ease in goes negative at the start
    mfloat_t result = back_ease_in(0.2f);
    mu_assert(result < 0.0f, "back ease_in overshoots negative");
}

MU_TEST(test_back_ease_out_endpoints)
{
    mu_assert(float_eq(0.0f, back_ease_out(0.0f)), "ease_out(0) = 0");
    mu_assert(float_eq(1.0f, back_ease_out(1.0f)), "ease_out(1) = 1");
}

MU_TEST(test_back_ease_out_overshoots)
{
    // Back ease out goes above 1 before settling
    mfloat_t result = back_ease_out(0.8f);
    mu_assert(result > 1.0f, "back ease_out overshoots above 1");
}

MU_TEST(test_back_ease_in_out_endpoints)
{
    mu_assert(float_eq(0.0f, back_ease_in_out(0.0f)), "ease_in_out(0) = 0");
    mu_assert(float_eq(1.0f, back_ease_in_out(1.0f)), "ease_in_out(1) = 1");
}

// Bounce easing tests
MU_TEST(test_bounce_ease_in_endpoints)
{
    mu_assert(float_eq(0.0f, bounce_ease_in(0.0f)), "ease_in(0) = 0");
    mu_assert(float_eq(1.0f, bounce_ease_in(1.0f)), "ease_in(1) = 1");
}

MU_TEST(test_bounce_ease_out_endpoints)
{
    mu_assert(float_eq(0.0f, bounce_ease_out(0.0f)), "ease_out(0) = 0");
    mu_assert(float_eq(1.0f, bounce_ease_out(1.0f)), "ease_out(1) = 1");
}

MU_TEST(test_bounce_ease_in_out_endpoints)
{
    mu_assert(float_eq(0.0f, bounce_ease_in_out(0.0f)), "ease_in_out(0) = 0");
    mu_assert(float_eq(1.0f, bounce_ease_in_out(1.0f)), "ease_in_out(1) = 1");
}

// general behavior tests
MU_TEST(test_ease_functions_monotonic_increasing)
{
    // Most ease functions should be monotonically increasing (except elastic/back)
    mfloat_t prev = quadratic_ease_out(0.0f);
    for (mfloat_t t = 0.1f; t <= 1.0f; t += 0.1f)
    {
        mfloat_t curr = quadratic_ease_out(t);
        mu_assert(curr >= prev, "quadratic ease_out is monotonic");
        prev = curr;
    }
}

MU_TEST(test_ease_in_slower_than_linear)
{
    // Ease in should be slower than linear at the start
    mfloat_t t = 0.25f;
    mu_assert(quadratic_ease_in(t) < t, "quadratic ease_in slower than linear");
    mu_assert(cubic_ease_in(t) < t, "cubic ease_in slower than linear");
    mu_assert(quartic_ease_in(t) < t, "quartic ease_in slower than linear");
}

MU_TEST(test_ease_out_faster_than_linear)
{
    // Ease out should be faster than linear at the start
    mfloat_t t = 0.25f;
    mu_assert(quadratic_ease_out(t) > t, "quadratic ease_out faster than linear");
    mu_assert(cubic_ease_out(t) > t, "cubic ease_out faster than linear");
    mu_assert(quartic_ease_out(t) > t, "quartic ease_out faster than linear");
}


MU_TEST_SUITE(test_suite)
{
    // Quadratic
    MU_RUN_TEST(test_quadratic_ease_in_endpoints);
    MU_RUN_TEST(test_quadratic_ease_in_midpoint);
    MU_RUN_TEST(test_quadratic_ease_out_endpoints);
    MU_RUN_TEST(test_quadratic_ease_out_midpoint);
    MU_RUN_TEST(test_quadratic_ease_in_out_endpoints);
    MU_RUN_TEST(test_quadratic_ease_in_out_midpoint);

    // Cubic
    MU_RUN_TEST(test_cubic_ease_in_endpoints);
    MU_RUN_TEST(test_cubic_ease_out_endpoints);
    MU_RUN_TEST(test_cubic_ease_in_out_endpoints);

    // Quartic
    MU_RUN_TEST(test_quartic_ease_in_endpoints);
    MU_RUN_TEST(test_quartic_ease_out_endpoints);
    MU_RUN_TEST(test_quartic_ease_in_out_endpoints);

    // Quintic
    MU_RUN_TEST(test_quintic_ease_in_endpoints);
    MU_RUN_TEST(test_quintic_ease_out_endpoints);
    MU_RUN_TEST(test_quintic_ease_in_out_endpoints);

    // Sine
    MU_RUN_TEST(test_sine_ease_in_endpoints);
    MU_RUN_TEST(test_sine_ease_out_endpoints);
    MU_RUN_TEST(test_sine_ease_in_out_endpoints);

    // Circular
    MU_RUN_TEST(test_circular_ease_in_endpoints);
    MU_RUN_TEST(test_circular_ease_out_endpoints);
    MU_RUN_TEST(test_circular_ease_in_out_endpoints);

    // Exponential
    MU_RUN_TEST(test_exponential_ease_in_endpoints);
    MU_RUN_TEST(test_exponential_ease_out_endpoints);
    MU_RUN_TEST(test_exponential_ease_in_out_endpoints);

    // Elastic
    MU_RUN_TEST(test_elastic_ease_in_endpoints);
    MU_RUN_TEST(test_elastic_ease_out_endpoints);
    MU_RUN_TEST(test_elastic_ease_in_out_endpoints);

    // Back
    MU_RUN_TEST(test_back_ease_in_endpoints);
    MU_RUN_TEST(test_back_ease_in_overshoots);
    MU_RUN_TEST(test_back_ease_out_endpoints);
    MU_RUN_TEST(test_back_ease_out_overshoots);
    MU_RUN_TEST(test_back_ease_in_out_endpoints);

    // Bounce
    MU_RUN_TEST(test_bounce_ease_in_endpoints);
    MU_RUN_TEST(test_bounce_ease_out_endpoints);
    MU_RUN_TEST(test_bounce_ease_in_out_endpoints);

    // General behavior
    MU_RUN_TEST(test_ease_functions_monotonic_increasing);
    MU_RUN_TEST(test_ease_in_slower_than_linear);
    MU_RUN_TEST(test_ease_out_faster_than_linear);
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}


