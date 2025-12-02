#include <float.h>

#include "mathc.h"
#include "minunit.h"

// Test Helpers
#define EPSILON 0.0001f

static bool float_eq(mfloat_t a, mfloat_t b)
{
	return MFABS(a - b) < EPSILON;
}

// Pointer-based API tests (mat3_*)
MU_TEST(test_mat3_zero)
{
	mfloat_t result[MAT3_SIZE];
	mat3_zero(result);
	for (int i = 0; i < MAT3_SIZE; i++) {
		mu_assert(float_eq(0.0f, result[i]), "all elements zero");
	}
}

MU_TEST(test_mat3_identity)
{
	mfloat_t result[MAT3_SIZE];
	mat3_identity(result);
	// Column-major identity
	mu_assert(float_eq(1.0f, result[0]), "m[0,0] = 1");
	mu_assert(float_eq(0.0f, result[1]), "m[1,0] = 0");
	mu_assert(float_eq(0.0f, result[2]), "m[2,0] = 0");
	mu_assert(float_eq(0.0f, result[3]), "m[0,1] = 0");
	mu_assert(float_eq(1.0f, result[4]), "m[1,1] = 1");
	mu_assert(float_eq(0.0f, result[5]), "m[2,1] = 0");
	mu_assert(float_eq(0.0f, result[6]), "m[0,2] = 0");
	mu_assert(float_eq(0.0f, result[7]), "m[1,2] = 0");
	mu_assert(float_eq(1.0f, result[8]), "m[2,2] = 1");
}

MU_TEST(test_mat3_determinant_identity)
{
	mfloat_t m[MAT3_SIZE];
	mat3_identity(m);
	mfloat_t det = mat3_determinant(m);
	mu_assert(float_eq(1.0f, det), "identity determinant = 1");
}

MU_TEST(test_mat3_negative)
{
	mfloat_t m[MAT3_SIZE] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
	mfloat_t result[MAT3_SIZE];
	mat3_negative(result, m);
	for (int i = 0; i < MAT3_SIZE; i++) {
		mu_assert(float_eq(-m[i], result[i]), "negative element");
	}
}

MU_TEST(test_mat3_transpose)
{
	mfloat_t m[MAT3_SIZE] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
	mfloat_t result[MAT3_SIZE];
	mat3_transpose(result, m);
	mu_assert(float_eq(1.0f, result[0]), "transpose m[0,0]");
	mu_assert(float_eq(4.0f, result[1]), "transpose m[1,0]");
	mu_assert(float_eq(7.0f, result[2]), "transpose m[2,0]");
}

MU_TEST(test_mat3_multiply_identity)
{
	mfloat_t m[MAT3_SIZE] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
	mfloat_t identity[MAT3_SIZE];
	mat3_identity(identity);
	mfloat_t result[MAT3_SIZE];
	mat3_multiply(result, m, identity);
	for (int i = 0; i < MAT3_SIZE; i++) {
		mu_assert(float_eq(m[i], result[i]), "M * I = M");
	}
}

MU_TEST(test_mat3_multiply_f)
{
	mfloat_t m[MAT3_SIZE] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
	mfloat_t result[MAT3_SIZE];
	mat3_multiply_f(result, m, 2.0f);
	for (int i = 0; i < MAT3_SIZE; i++) {
		mu_assert(float_eq(m[i] * 2.0f, result[i]), "scaled element");
	}
}

MU_TEST(test_mat3_inverse_identity)
{
	mfloat_t m[MAT3_SIZE];
	mat3_identity(m);
	mfloat_t result[MAT3_SIZE];
	mat3_inverse(result, m);
	mu_assert(float_eq(1.0f, result[0]), "inverse identity m[0,0]");
	mu_assert(float_eq(1.0f, result[4]), "inverse identity m[1,1]");
	mu_assert(float_eq(1.0f, result[8]), "inverse identity m[2,2]");
}

MU_TEST(test_mat3_rotation_x)
{
	mfloat_t result[MAT3_SIZE];
	mat3_rotation_x(result, 0.0f);
	mu_assert(float_eq(1.0f, result[0]), "rotation_x(0) m[0,0]");
	mu_assert(float_eq(1.0f, result[4]), "rotation_x(0) m[1,1]");
	mu_assert(float_eq(1.0f, result[8]), "rotation_x(0) m[2,2]");
}

MU_TEST(test_mat3_rotation_y)
{
	mfloat_t result[MAT3_SIZE];
	mat3_rotation_y(result, 0.0f);
	mu_assert(float_eq(1.0f, result[0]), "rotation_y(0) m[0,0]");
	mu_assert(float_eq(1.0f, result[4]), "rotation_y(0) m[1,1]");
	mu_assert(float_eq(1.0f, result[8]), "rotation_y(0) m[2,2]");
}

MU_TEST(test_mat3_rotation_z)
{
	mfloat_t result[MAT3_SIZE];
	mat3_rotation_z(result, 0.0f);
	mu_assert(float_eq(1.0f, result[0]), "rotation_z(0) m[0,0]");
	mu_assert(float_eq(1.0f, result[4]), "rotation_z(0) m[1,1]");
	mu_assert(float_eq(1.0f, result[8]), "rotation_z(0) m[2,2]");
}

MU_TEST(test_mat3_rotation_axis)
{
	mfloat_t axis[VEC3_SIZE] = {0.0f, 0.0f, 1.0f};
	mfloat_t result[MAT3_SIZE];
	mat3_rotation_axis(result, axis, 0.0f);
	mu_assert(float_eq(1.0f, result[0]), "rotation_axis(0) m[0,0]");
	mu_assert(float_eq(1.0f, result[4]), "rotation_axis(0) m[1,1]");
	mu_assert(float_eq(1.0f, result[8]), "rotation_axis(0) m[2,2]");
}

MU_TEST(test_mat3_scaling)
{
	mfloat_t v[VEC3_SIZE] = {2.0f, 3.0f, 4.0f};
	mfloat_t result[MAT3_SIZE];
	mat3_scaling(result, v);
	mu_assert(float_eq(2.0f, result[0]), "scale x");
	mu_assert(float_eq(3.0f, result[4]), "scale y");
	mu_assert(float_eq(4.0f, result[8]), "scale z");
}

// Struct-based API tests (smat3_*)
MU_TEST(test_smat3_zero)
{
	struct mat3 m = smat3_zero();
	mu_assert(float_eq(0.0f, m.m11), "m11 zero");
	mu_assert(float_eq(0.0f, m.m22), "m22 zero");
	mu_assert(float_eq(0.0f, m.m33), "m33 zero");
}

MU_TEST(test_smat3_identity)
{
	struct mat3 m = smat3_identity();
	mu_assert(float_eq(1.0f, m.m11), "m[0,0] = 1");
	mu_assert(float_eq(1.0f, m.m22), "m[1,1] = 1");
	mu_assert(float_eq(1.0f, m.m33), "m[2,2] = 1");
	mu_assert(float_eq(0.0f, m.m12), "m[0,1] = 0");
	mu_assert(float_eq(0.0f, m.m21), "m[1,0] = 0");
}

MU_TEST(test_smat3_determinant)
{
	struct mat3 m = smat3_identity();
	mfloat_t det = smat3_determinant(m);
	mu_assert(float_eq(1.0f, det), "identity determinant = 1");
}

MU_TEST(test_smat3_negative)
{
	struct mat3 m = smat3_identity();
	struct mat3 result = smat3_negative(m);
	mu_assert(float_eq(-1.0f, result.m11), "negative m11");
	mu_assert(float_eq(-1.0f, result.m22), "negative m22");
	mu_assert(float_eq(-1.0f, result.m33), "negative m33");
}

MU_TEST(test_smat3_transpose)
{
	struct mat3 m = smat3(1.0f, 4.0f, 7.0f, 2.0f, 5.0f, 8.0f, 3.0f, 6.0f, 9.0f);
	struct mat3 result = smat3_transpose(m);
	mu_assert(float_eq(1.0f, result.m11), "transpose m[0,0]");
	mu_assert(float_eq(4.0f, result.m21), "transpose m[1,0]");
	mu_assert(float_eq(7.0f, result.m31), "transpose m[2,0]");
}

MU_TEST(test_smat3_multiply)
{
	struct mat3 identity = smat3_identity();
	struct mat3 m = smat3(1.0f, 4.0f, 7.0f, 2.0f, 5.0f, 8.0f, 3.0f, 6.0f, 9.0f);
	struct mat3 result = smat3_multiply(m, identity);
	mu_assert(float_eq(m.m11, result.m11), "M * I = M (m11)");
	mu_assert(float_eq(m.m22, result.m22), "M * I = M (m22)");
	mu_assert(float_eq(m.m33, result.m33), "M * I = M (m33)");
}

MU_TEST(test_smat3_multiply_f)
{
	struct mat3 m = smat3_identity();
	struct mat3 result = smat3_multiply_f(m, 2.0f);
	mu_assert(float_eq(2.0f, result.m11), "scaled m11");
	mu_assert(float_eq(2.0f, result.m22), "scaled m22");
	mu_assert(float_eq(2.0f, result.m33), "scaled m33");
}

MU_TEST(test_smat3_inverse)
{
	struct mat3 m = smat3_identity();
	struct mat3 result = smat3_inverse(m);
	mu_assert(float_eq(1.0f, result.m11), "inverse identity m[0,0]");
	mu_assert(float_eq(1.0f, result.m22), "inverse identity m[1,1]");
	mu_assert(float_eq(1.0f, result.m33), "inverse identity m[2,2]");
}

MU_TEST(test_smat3_rotation_x)
{
	struct mat3 result = smat3_rotation_x(0.0f);
	mu_assert(float_eq(1.0f, result.m11), "rotation_x(0) m[0,0]");
	mu_assert(float_eq(1.0f, result.m22), "rotation_x(0) m[1,1]");
	mu_assert(float_eq(1.0f, result.m33), "rotation_x(0) m[2,2]");
}

MU_TEST(test_smat3_rotation_y)
{
	struct mat3 result = smat3_rotation_y(0.0f);
	mu_assert(float_eq(1.0f, result.m11), "rotation_y(0) m[0,0]");
	mu_assert(float_eq(1.0f, result.m22), "rotation_y(0) m[1,1]");
	mu_assert(float_eq(1.0f, result.m33), "rotation_y(0) m[2,2]");
}

MU_TEST(test_smat3_rotation_z)
{
	struct mat3 result = smat3_rotation_z(0.0f);
	mu_assert(float_eq(1.0f, result.m11), "rotation_z(0) m[0,0]");
	mu_assert(float_eq(1.0f, result.m22), "rotation_z(0) m[1,1]");
	mu_assert(float_eq(1.0f, result.m33), "rotation_z(0) m[2,2]");
}

MU_TEST(test_smat3_scaling)
{
	struct vec3 v = svec3(2.0f, 3.0f, 4.0f);
	struct mat3 result = smat3_scaling(v);
	mu_assert(float_eq(2.0f, result.m11), "scale x");
	mu_assert(float_eq(3.0f, result.m22), "scale y");
	mu_assert(float_eq(4.0f, result.m33), "scale z");
}

// Edge case / Negative tests
MU_TEST(test_mat3_multiply_inverse_is_identity)
{
	// Use a diagonal matrix which is easily invertible
	mfloat_t m[MAT3_SIZE] = {2.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 4.0f};
	mfloat_t m_inv[MAT3_SIZE];
	mfloat_t result[MAT3_SIZE];

	mat3_inverse(m_inv, m);
	mat3_multiply(result, m, m_inv);

	mu_assert(float_eq(1.0f, result[0]), "M*M^-1 = I [0,0]");
	mu_assert(float_eq(1.0f, result[4]), "M*M^-1 = I [1,1]");
	mu_assert(float_eq(1.0f, result[8]), "M*M^-1 = I [2,2]");
}


MU_TEST_SUITE(test_suite)
{
	// Pointer-based API tests
	MU_RUN_TEST(test_mat3_zero);
	MU_RUN_TEST(test_mat3_identity);
	MU_RUN_TEST(test_mat3_determinant_identity);
	MU_RUN_TEST(test_mat3_negative);
	MU_RUN_TEST(test_mat3_transpose);
	MU_RUN_TEST(test_mat3_multiply_identity);
	MU_RUN_TEST(test_mat3_multiply_f);
	MU_RUN_TEST(test_mat3_inverse_identity);
	MU_RUN_TEST(test_mat3_rotation_x);
	MU_RUN_TEST(test_mat3_rotation_y);
	MU_RUN_TEST(test_mat3_rotation_z);
	MU_RUN_TEST(test_mat3_rotation_axis);
	MU_RUN_TEST(test_mat3_scaling);

	// Struct-based API tests
	MU_RUN_TEST(test_smat3_zero);
	MU_RUN_TEST(test_smat3_identity);
	MU_RUN_TEST(test_smat3_determinant);
	MU_RUN_TEST(test_smat3_negative);
	MU_RUN_TEST(test_smat3_transpose);
	MU_RUN_TEST(test_smat3_multiply);
	MU_RUN_TEST(test_smat3_multiply_f);
	MU_RUN_TEST(test_smat3_inverse);
	MU_RUN_TEST(test_smat3_rotation_x);
	MU_RUN_TEST(test_smat3_rotation_y);
	MU_RUN_TEST(test_smat3_rotation_z);
	MU_RUN_TEST(test_smat3_scaling);

	// Edge case / Negative tests
	MU_RUN_TEST(test_mat3_multiply_inverse_is_identity);
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
