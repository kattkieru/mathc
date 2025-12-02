#include <float.h>

#include "mathc.h"
#include "minunit.h"

#define EPSILON 0.0001f

static bool float_eq(mfloat_t a, mfloat_t b)
{
	return MFABS(a - b) < EPSILON;
}

MU_TEST(test_quat_create)
{
	mfloat_t result[QUAT_SIZE];
	quat(result, 0.0f, 0.0f, 0.0f, 1.0f);
	mu_assert(float_eq(0.0f, result[0]), "x");
	mu_assert(float_eq(0.0f, result[1]), "y");
	mu_assert(float_eq(0.0f, result[2]), "z");
	mu_assert(float_eq(1.0f, result[3]), "w");
}

MU_TEST(test_quat_null)
{
	mfloat_t result[QUAT_SIZE];
	quat_null(result);
	mu_assert(float_eq(0.0f, result[0]), "x");
	mu_assert(float_eq(0.0f, result[1]), "y");
	mu_assert(float_eq(0.0f, result[2]), "z");
	mu_assert(float_eq(1.0f, result[3]), "w (identity)");
}

MU_TEST(test_quat_is_zero)
{
	mfloat_t q1[QUAT_SIZE] = {0.0f, 0.0f, 0.0f, 0.0f};
	mfloat_t q2[QUAT_SIZE] = {0.0f, 0.0f, 0.0f, 1.0f};
	mu_assert(quat_is_zero(q1), "zero");
	mu_assert(!quat_is_zero(q2), "identity not zero");
}

MU_TEST(test_quat_multiply_identity)
{
	mfloat_t q[QUAT_SIZE] = {0.5f, 0.5f, 0.5f, 0.5f};
	mfloat_t identity[QUAT_SIZE] = {0.0f, 0.0f, 0.0f, 1.0f};
	mfloat_t result[QUAT_SIZE];
	quat_multiply(result, q, identity);
	mu_assert(float_eq(0.5f, result[0]), "x");
	mu_assert(float_eq(0.5f, result[1]), "y");
	mu_assert(float_eq(0.5f, result[2]), "z");
	mu_assert(float_eq(0.5f, result[3]), "w");
}

MU_TEST(test_quat_conjugate)
{
	mfloat_t q[QUAT_SIZE] = {1.0f, 2.0f, 3.0f, 4.0f};
	mfloat_t result[QUAT_SIZE];
	quat_conjugate(result, q);
	mu_assert(float_eq(-1.0f, result[0]), "x");
	mu_assert(float_eq(-2.0f, result[1]), "y");
	mu_assert(float_eq(-3.0f, result[2]), "z");
	mu_assert(float_eq(4.0f, result[3]), "w unchanged");
}

MU_TEST(test_quat_normalize)
{
	mfloat_t q[QUAT_SIZE] = {0.0f, 0.0f, 0.0f, 2.0f};
	mfloat_t result[QUAT_SIZE];
	quat_normalize(result, q);
	mu_assert(float_eq(0.0f, result[0]), "x");
	mu_assert(float_eq(0.0f, result[1]), "y");
	mu_assert(float_eq(0.0f, result[2]), "z");
	mu_assert(float_eq(1.0f, result[3]), "w");
}

MU_TEST(test_quat_dot)
{
	mfloat_t q0[QUAT_SIZE] = {1.0f, 2.0f, 3.0f, 4.0f};
	mfloat_t q1[QUAT_SIZE] = {5.0f, 6.0f, 7.0f, 8.0f};
	mu_assert(float_eq(70.0f, quat_dot(q0, q1)), "1*5 + 2*6 + 3*7 + 4*8");
}

MU_TEST(test_quat_length)
{
	mfloat_t q[QUAT_SIZE] = {0.0f, 0.0f, 0.0f, 2.0f};
	mu_assert(float_eq(2.0f, quat_length(q)), "length");
}

MU_TEST(test_quat_from_axis_angle)
{
	mfloat_t axis[VEC3_SIZE] = {0.0f, 0.0f, 1.0f};
	mfloat_t result[QUAT_SIZE];

	quat_from_axis_angle(result, axis, 0.0f);
	mu_assert(float_eq(0.0f, result[0]), "x");
	mu_assert(float_eq(0.0f, result[1]), "y");
	mu_assert(float_eq(0.0f, result[2]), "z");
	mu_assert(float_eq(1.0f, result[3]), "w");
}

MU_TEST(test_quat_from_axis_angle_90)
{
	mfloat_t axis[VEC3_SIZE] = {0.0f, 0.0f, 1.0f};
	mfloat_t result[QUAT_SIZE];
	quat_from_axis_angle(result, axis, MPI_2);
	mfloat_t sin45 = MSIN(MPI_4);
	mfloat_t cos45 = MCOS(MPI_4);
	mu_assert(float_eq(sin45, result[2]), "z");
	mu_assert(float_eq(cos45, result[3]), "w");
}

MU_TEST(test_quat_lerp)
{
	mfloat_t q0[QUAT_SIZE] = {0.0f, 0.0f, 0.0f, 1.0f};
	mfloat_t q1[QUAT_SIZE] = {1.0f, 0.0f, 0.0f, 0.0f};
	mfloat_t result[QUAT_SIZE];
	quat_lerp(result, q0, q1, 0.0f);
	mu_assert(float_eq(0.0f, result[0]), "x");
	mu_assert(float_eq(1.0f, result[3]), "w");
}

MU_TEST(test_quat_inverse_multiply)
{
	mfloat_t q[QUAT_SIZE];
	mfloat_t q_inv[QUAT_SIZE];
	mfloat_t result[QUAT_SIZE];

	mfloat_t axis[VEC3_SIZE] = {0.0f, 1.0f, 0.0f};
	quat_from_axis_angle(q, axis, MPI_4);
	quat_inverse(q_inv, q);
	quat_multiply(result, q, q_inv);

	mu_assert(float_eq(0.0f, result[0]), "x ~ 0");
	mu_assert(float_eq(0.0f, result[1]), "y ~ 0");
	mu_assert(float_eq(0.0f, result[2]), "z ~ 0");
	mu_assert(float_eq(1.0f, result[3]), "w ~ 1");
}

/* struct API */

MU_TEST(test_squat_create)
{
	struct quat q = squat(0.0f, 0.0f, 0.0f, 1.0f);
	mu_assert(float_eq(0.0f, q.x), "x");
	mu_assert(float_eq(0.0f, q.y), "y");
	mu_assert(float_eq(0.0f, q.z), "z");
	mu_assert(float_eq(1.0f, q.w), "w");
}

MU_TEST(test_squat_null)
{
	struct quat q = squat_null();
	mu_assert(float_eq(0.0f, q.x), "x");
	mu_assert(float_eq(1.0f, q.w), "w");
}

MU_TEST(test_squat_multiply_identity)
{
	struct quat q = squat(0.5f, 0.5f, 0.5f, 0.5f);
	struct quat identity = squat_null();
	struct quat result = squat_multiply(q, identity);
	mu_assert(float_eq(0.5f, result.x), "x");
	mu_assert(float_eq(0.5f, result.w), "w");
}

MU_TEST(test_squat_conjugate)
{
	struct quat q = squat(1.0f, 2.0f, 3.0f, 4.0f);
	struct quat result = squat_conjugate(q);
	mu_assert(float_eq(-1.0f, result.x), "x");
	mu_assert(float_eq(-2.0f, result.y), "y");
	mu_assert(float_eq(-3.0f, result.z), "z");
	mu_assert(float_eq(4.0f, result.w), "w");
}

MU_TEST(test_squat_normalize)
{
	struct quat q = squat(0.0f, 0.0f, 0.0f, 2.0f);
	struct quat result = squat_normalize(q);
	mu_assert(float_eq(1.0f, result.w), "w");
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_quat_create);
	MU_RUN_TEST(test_quat_null);
	MU_RUN_TEST(test_quat_is_zero);
	MU_RUN_TEST(test_quat_multiply_identity);
	MU_RUN_TEST(test_quat_conjugate);
	MU_RUN_TEST(test_quat_normalize);
	MU_RUN_TEST(test_quat_dot);
	MU_RUN_TEST(test_quat_length);
	MU_RUN_TEST(test_quat_from_axis_angle);
	MU_RUN_TEST(test_quat_from_axis_angle_90);
	MU_RUN_TEST(test_quat_lerp);
	MU_RUN_TEST(test_quat_inverse_multiply);

	MU_RUN_TEST(test_squat_create);
	MU_RUN_TEST(test_squat_null);
	MU_RUN_TEST(test_squat_multiply_identity);
	MU_RUN_TEST(test_squat_conjugate);
	MU_RUN_TEST(test_squat_normalize);
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
