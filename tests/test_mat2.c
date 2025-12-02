#include "minunit.h"
#include "mathc.h"
#include <float.h>

// ============================================================================
// Test Helpers
// ============================================================================

#define EPSILON 0.0001f

static bool float_eq(mfloat_t a, mfloat_t b)
{
    return MFABS(a - b) < EPSILON;
}

// ============================================================================
// Pointer-based API tests (mat2_*)
// ============================================================================

MU_TEST(test_mat2_zero)
{
    mfloat_t result[MAT2_SIZE];
    mat2_zero(result);
    for (int i = 0; i < MAT2_SIZE; i++)
    {
        mu_assert(float_eq(0.0f, result[i]), "all elements zero");
    }
}

MU_TEST(test_mat2_identity)
{
    mfloat_t result[MAT2_SIZE];
    mat2_identity(result);
    // Identity: [1 0; 0 1] in column-major: [1, 0, 0, 1]
    mu_assert(float_eq(1.0f, result[0]), "m[0,0] = 1");
    mu_assert(float_eq(0.0f, result[1]), "m[1,0] = 0");
    mu_assert(float_eq(0.0f, result[2]), "m[0,1] = 0");
    mu_assert(float_eq(1.0f, result[3]), "m[1,1] = 1");
}

MU_TEST(test_mat2_assign)
{
    mfloat_t m0[MAT2_SIZE] = {1.0f, 2.0f, 3.0f, 4.0f};
    mfloat_t result[MAT2_SIZE];
    mat2_assign(result, m0);
    for (int i = 0; i < MAT2_SIZE; i++)
    {
        mu_assert(float_eq(m0[i], result[i]), "assigned correctly");
    }
}

MU_TEST(test_mat2_determinant_identity)
{
    mfloat_t m[MAT2_SIZE];
    mat2_identity(m);
    mfloat_t det = mat2_determinant(m);
    mu_assert(float_eq(1.0f, det), "identity determinant = 1");
}

MU_TEST(test_mat2_determinant_zero)
{
    // Singular matrix (zero determinant)
    mfloat_t m[MAT2_SIZE] = {1.0f, 2.0f, 2.0f, 4.0f};  // rows are linearly dependent
    mfloat_t det = mat2_determinant(m);
    mu_assert(float_eq(0.0f, det), "singular matrix determinant = 0");
}

MU_TEST(test_mat2_determinant_general)
{
    // [[1,3],[2,4]] -> det = 1*4 - 3*2 = -2
    // Column-major: [1, 2, 3, 4]
    mfloat_t m[MAT2_SIZE] = {1.0f, 2.0f, 3.0f, 4.0f};
    mfloat_t det = mat2_determinant(m);
    mu_assert(float_eq(-2.0f, det), "determinant = -2");
}

MU_TEST(test_mat2_negative)
{
    mfloat_t m[MAT2_SIZE] = {1.0f, -2.0f, 3.0f, -4.0f};
    mfloat_t result[MAT2_SIZE];
    mat2_negative(result, m);
    mu_assert(float_eq(-1.0f, result[0]), "negative m[0]");
    mu_assert(float_eq(2.0f, result[1]), "negative m[1]");
    mu_assert(float_eq(-3.0f, result[2]), "negative m[2]");
    mu_assert(float_eq(4.0f, result[3]), "negative m[3]");
}

MU_TEST(test_mat2_transpose)
{
    // [[1,3],[2,4]] -> [[1,2],[3,4]]
    // Column-major in: [1, 2, 3, 4] -> [1, 3, 2, 4]
    mfloat_t m[MAT2_SIZE] = {1.0f, 2.0f, 3.0f, 4.0f};
    mfloat_t result[MAT2_SIZE];
    mat2_transpose(result, m);
    mu_assert(float_eq(1.0f, result[0]), "transpose m[0,0]");
    mu_assert(float_eq(3.0f, result[1]), "transpose m[1,0]");
    mu_assert(float_eq(2.0f, result[2]), "transpose m[0,1]");
    mu_assert(float_eq(4.0f, result[3]), "transpose m[1,1]");
}

MU_TEST(test_mat2_multiply_identity)
{
    mfloat_t m[MAT2_SIZE] = {1.0f, 2.0f, 3.0f, 4.0f};
    mfloat_t identity[MAT2_SIZE];
    mat2_identity(identity);
    mfloat_t result[MAT2_SIZE];
    mat2_multiply(result, m, identity);
    for (int i = 0; i < MAT2_SIZE; i++)
    {
        mu_assert(float_eq(m[i], result[i]), "M * I = M");
    }
}

MU_TEST(test_mat2_multiply_f)
{
    mfloat_t m[MAT2_SIZE] = {1.0f, 2.0f, 3.0f, 4.0f};
    mfloat_t result[MAT2_SIZE];
    mat2_multiply_f(result, m, 2.0f);
    mu_assert(float_eq(2.0f, result[0]), "scaled m[0]");
    mu_assert(float_eq(4.0f, result[1]), "scaled m[1]");
    mu_assert(float_eq(6.0f, result[2]), "scaled m[2]");
    mu_assert(float_eq(8.0f, result[3]), "scaled m[3]");
}

MU_TEST(test_mat2_inverse)
{
    mfloat_t m[MAT2_SIZE];
    mat2_identity(m);
    mfloat_t result[MAT2_SIZE];
    mat2_inverse(result, m);
    // Inverse of identity is identity
    mu_assert(float_eq(1.0f, result[0]), "inverse identity m[0,0]");
    mu_assert(float_eq(0.0f, result[1]), "inverse identity m[1,0]");
    mu_assert(float_eq(0.0f, result[2]), "inverse identity m[0,1]");
    mu_assert(float_eq(1.0f, result[3]), "inverse identity m[1,1]");
}

MU_TEST(test_mat2_rotation_z)
{
    mfloat_t result[MAT2_SIZE];
    mat2_rotation_z(result, MPI_2);  // 90 degree rotation
    // Rotation matrix for 90°: [[0,-1],[1,0]]
    // Column-major: [cos, sin, -sin, cos] = [0, 1, -1, 0]
    mu_assert(float_eq(0.0f, result[0]), "rotation m[0,0]");
    mu_assert(float_eq(1.0f, result[1]), "rotation m[1,0]");
    mu_assert(float_eq(-1.0f, result[2]), "rotation m[0,1]");
    mu_assert(float_eq(0.0f, result[3]), "rotation m[1,1]");
}

MU_TEST(test_mat2_scaling)
{
    mfloat_t v[VEC2_SIZE] = {2.0f, 3.0f};
    mfloat_t result[MAT2_SIZE];
    mat2_scaling(result, v);
    mu_assert(float_eq(2.0f, result[0]), "scale x");
    mu_assert(float_eq(0.0f, result[1]), "scale m[1,0]");
    mu_assert(float_eq(0.0f, result[2]), "scale m[0,1]");
    mu_assert(float_eq(3.0f, result[3]), "scale y");
}

MU_TEST(test_mat2_lerp)
{
    mfloat_t m0[MAT2_SIZE];
    mfloat_t m1[MAT2_SIZE];
    mat2_identity(m0);
    mat2_zero(m1);
    mfloat_t result[MAT2_SIZE];
    mat2_lerp(result, m0, m1, 0.5f);
    mu_assert(float_eq(0.5f, result[0]), "lerp m[0,0]");
    mu_assert(float_eq(0.5f, result[3]), "lerp m[1,1]");
}

// ============================================================================
// Struct-based API tests (smat2_*)
// ============================================================================

MU_TEST(test_smat2_zero)
{
    struct mat2 m = smat2_zero();
    mu_assert(float_eq(0.0f, m.m11), "m11 zero");
    mu_assert(float_eq(0.0f, m.m21), "m21 zero");
    mu_assert(float_eq(0.0f, m.m12), "m12 zero");
    mu_assert(float_eq(0.0f, m.m22), "m22 zero");
}

MU_TEST(test_smat2_identity)
{
    struct mat2 m = smat2_identity();
    mu_assert(float_eq(1.0f, m.m11), "m[0,0] = 1");
    mu_assert(float_eq(0.0f, m.m21), "m[1,0] = 0");
    mu_assert(float_eq(0.0f, m.m12), "m[0,1] = 0");
    mu_assert(float_eq(1.0f, m.m22), "m[1,1] = 1");
}

MU_TEST(test_smat2_determinant)
{
    struct mat2 m = smat2_identity();
    mfloat_t det = smat2_determinant(m);
    mu_assert(float_eq(1.0f, det), "identity determinant = 1");
}

MU_TEST(test_smat2_negative)
{
    struct mat2 m = smat2(1.0f, 3.0f, 2.0f, 4.0f);
    struct mat2 result = smat2_negative(m);
    mu_assert(float_eq(-1.0f, result.m11), "negative m11");
    mu_assert(float_eq(-2.0f, result.m21), "negative m21");
    mu_assert(float_eq(-3.0f, result.m12), "negative m12");
    mu_assert(float_eq(-4.0f, result.m22), "negative m22");
}

MU_TEST(test_smat2_transpose)
{
    struct mat2 m = smat2(1.0f, 3.0f, 2.0f, 4.0f);
    struct mat2 result = smat2_transpose(m);
    mu_assert(float_eq(1.0f, result.m11), "transpose m[0,0]");
    mu_assert(float_eq(3.0f, result.m21), "transpose m[1,0]");
    mu_assert(float_eq(2.0f, result.m12), "transpose m[0,1]");
    mu_assert(float_eq(4.0f, result.m22), "transpose m[1,1]");
}

MU_TEST(test_smat2_multiply)
{
    struct mat2 identity = smat2_identity();
    struct mat2 m = smat2(1.0f, 3.0f, 2.0f, 4.0f);
    struct mat2 result = smat2_multiply(m, identity);
    mu_assert(float_eq(m.m11, result.m11), "M * I = M (m11)");
    mu_assert(float_eq(m.m21, result.m21), "M * I = M (m21)");
    mu_assert(float_eq(m.m12, result.m12), "M * I = M (m12)");
    mu_assert(float_eq(m.m22, result.m22), "M * I = M (m22)");
}

MU_TEST(test_smat2_multiply_f)
{
    struct mat2 m = smat2(1.0f, 3.0f, 2.0f, 4.0f);
    struct mat2 result = smat2_multiply_f(m, 2.0f);
    mu_assert(float_eq(2.0f, result.m11), "scaled m11");
    mu_assert(float_eq(4.0f, result.m21), "scaled m21");
    mu_assert(float_eq(6.0f, result.m12), "scaled m12");
    mu_assert(float_eq(8.0f, result.m22), "scaled m22");
}

MU_TEST(test_smat2_inverse)
{
    struct mat2 m = smat2_identity();
    struct mat2 result = smat2_inverse(m);
    mu_assert(float_eq(1.0f, result.m11), "inverse identity m[0,0]");
    mu_assert(float_eq(0.0f, result.m21), "inverse identity m[1,0]");
    mu_assert(float_eq(0.0f, result.m12), "inverse identity m[0,1]");
    mu_assert(float_eq(1.0f, result.m22), "inverse identity m[1,1]");
}

MU_TEST(test_smat2_rotation_z)
{
    struct mat2 result = smat2_rotation_z(MPI_2);
    mu_assert(float_eq(0.0f, result.m11), "rotation m[0,0]");
    mu_assert(float_eq(1.0f, result.m21), "rotation m[1,0]");
    mu_assert(float_eq(-1.0f, result.m12), "rotation m[0,1]");
    mu_assert(float_eq(0.0f, result.m22), "rotation m[1,1]");
}

MU_TEST(test_smat2_scaling)
{
    struct vec2 v = svec2(2.0f, 3.0f);
    struct mat2 result = smat2_scaling(v);
    mu_assert(float_eq(2.0f, result.m11), "scale x");
    mu_assert(float_eq(0.0f, result.m21), "scale m[1,0]");
    mu_assert(float_eq(0.0f, result.m12), "scale m[0,1]");
    mu_assert(float_eq(3.0f, result.m22), "scale y");
}

MU_TEST(test_smat2_lerp)
{
    struct mat2 m0 = smat2_identity();
    struct mat2 m1 = smat2_zero();
    struct mat2 result = smat2_lerp(m0, m1, 0.5f);
    mu_assert(float_eq(0.5f, result.m11), "lerp m[0,0]");
    mu_assert(float_eq(0.5f, result.m22), "lerp m[1,1]");
}

// ============================================================================
// Edge case / Negative tests
// ============================================================================

MU_TEST(test_mat2_multiply_inverse_is_identity)
{
    // M * M^-1 = I
    mfloat_t m[MAT2_SIZE] = {4.0f, 3.0f, 2.0f, 1.0f};
    mfloat_t m_inv[MAT2_SIZE];
    mfloat_t result[MAT2_SIZE];
    
    mat2_inverse(m_inv, m);
    mat2_multiply(result, m, m_inv);
    
    // Should be close to identity
    mu_assert(float_eq(1.0f, result[0]), "M*M^-1 = I [0,0]");
    mu_assert(float_eq(0.0f, result[1]), "M*M^-1 = I [1,0]");
    mu_assert(float_eq(0.0f, result[2]), "M*M^-1 = I [0,1]");
    mu_assert(float_eq(1.0f, result[3]), "M*M^-1 = I [1,1]");
}

// ============================================================================
// Test Suite
// ============================================================================

MU_TEST_SUITE(test_suite)
{
    // Pointer-based API tests
    MU_RUN_TEST(test_mat2_zero);
    MU_RUN_TEST(test_mat2_identity);
    MU_RUN_TEST(test_mat2_assign);
    MU_RUN_TEST(test_mat2_determinant_identity);
    MU_RUN_TEST(test_mat2_determinant_zero);
    MU_RUN_TEST(test_mat2_determinant_general);
    MU_RUN_TEST(test_mat2_negative);
    MU_RUN_TEST(test_mat2_transpose);
    MU_RUN_TEST(test_mat2_multiply_identity);
    MU_RUN_TEST(test_mat2_multiply_f);
    MU_RUN_TEST(test_mat2_inverse);
    MU_RUN_TEST(test_mat2_rotation_z);
    MU_RUN_TEST(test_mat2_scaling);
    MU_RUN_TEST(test_mat2_lerp);

    // Struct-based API tests
    MU_RUN_TEST(test_smat2_zero);
    MU_RUN_TEST(test_smat2_identity);
    MU_RUN_TEST(test_smat2_determinant);
    MU_RUN_TEST(test_smat2_negative);
    MU_RUN_TEST(test_smat2_transpose);
    MU_RUN_TEST(test_smat2_multiply);
    MU_RUN_TEST(test_smat2_multiply_f);
    MU_RUN_TEST(test_smat2_inverse);
    MU_RUN_TEST(test_smat2_rotation_z);
    MU_RUN_TEST(test_smat2_scaling);
    MU_RUN_TEST(test_smat2_lerp);

    // Edge case / Negative tests
    MU_RUN_TEST(test_mat2_multiply_inverse_is_identity);
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
