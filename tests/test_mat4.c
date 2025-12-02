#include "minunit.h"
#include "mathc.h"
#include <float.h>

#define EPSILON 0.0001f

static bool float_eq(mfloat_t a, mfloat_t b)
{
    return MFABS(a - b) < EPSILON;
}

// Pointer-based API tests (mat4_*)
MU_TEST(test_mat4_zero)
{
    mfloat_t result[MAT4_SIZE];
    mat4_zero(result);
    for (int i = 0; i < MAT4_SIZE; i++)
    {
        mu_assert(float_eq(0.0f, result[i]), "all elements zero");
    }
}

MU_TEST(test_mat4_identity)
{
    mfloat_t result[MAT4_SIZE];
    mat4_identity(result);
    // Column-major identity
    mu_assert(float_eq(1.0f, result[0]), "m[0,0] = 1");
    mu_assert(float_eq(0.0f, result[1]), "m[1,0] = 0");
    mu_assert(float_eq(0.0f, result[4]), "m[0,1] = 0");
    mu_assert(float_eq(1.0f, result[5]), "m[1,1] = 1");
    mu_assert(float_eq(1.0f, result[10]), "m[2,2] = 1");
    mu_assert(float_eq(1.0f, result[15]), "m[3,3] = 1");
}

MU_TEST(test_mat4_determinant_identity)
{
    mfloat_t m[MAT4_SIZE];
    mat4_identity(m);
    mfloat_t det = mat4_determinant(m);
    mu_assert(float_eq(1.0f, det), "identity determinant = 1");
}

MU_TEST(test_mat4_negative)
{
    mfloat_t m[MAT4_SIZE];
    mat4_identity(m);
    mfloat_t result[MAT4_SIZE];
    mat4_negative(result, m);
    mu_assert(float_eq(-1.0f, result[0]), "negative m[0,0]");
    mu_assert(float_eq(-1.0f, result[5]), "negative m[1,1]");
}

MU_TEST(test_mat4_transpose)
{
    mfloat_t m[MAT4_SIZE];
    mat4_identity(m);
    m[4] = 2.0f;  // m[0,1]
    m[1] = 3.0f;  // m[1,0]
    
    mfloat_t result[MAT4_SIZE];
    mat4_transpose(result, m);
    
    mu_assert(float_eq(3.0f, result[4]), "transposed m[0,1]");
    mu_assert(float_eq(2.0f, result[1]), "transposed m[1,0]");
}

MU_TEST(test_mat4_multiply_identity)
{
    mfloat_t m[MAT4_SIZE];
    mat4_identity(m);
    m[12] = 5.0f;  // Translation X
    m[13] = 10.0f; // Translation Y
    m[14] = 15.0f; // Translation Z
    
    mfloat_t identity[MAT4_SIZE];
    mat4_identity(identity);
    
    mfloat_t result[MAT4_SIZE];
    mat4_multiply(result, m, identity);
    
    mu_assert(float_eq(5.0f, result[12]), "M * I preserves translation X");
    mu_assert(float_eq(10.0f, result[13]), "M * I preserves translation Y");
    mu_assert(float_eq(15.0f, result[14]), "M * I preserves translation Z");
}

MU_TEST(test_mat4_multiply_f)
{
    mfloat_t m[MAT4_SIZE];
    mat4_identity(m);
    mfloat_t result[MAT4_SIZE];
    mat4_multiply_f(result, m, 2.0f);
    mu_assert(float_eq(2.0f, result[0]), "scaled m[0,0]");
    mu_assert(float_eq(2.0f, result[5]), "scaled m[1,1]");
}

MU_TEST(test_mat4_inverse_identity)
{
    mfloat_t m[MAT4_SIZE];
    mat4_identity(m);
    mfloat_t result[MAT4_SIZE];
    mat4_inverse(result, m);
    mu_assert(float_eq(1.0f, result[0]), "inverse identity m[0,0]");
    mu_assert(float_eq(1.0f, result[5]), "inverse identity m[1,1]");
    mu_assert(float_eq(1.0f, result[10]), "inverse identity m[2,2]");
    mu_assert(float_eq(1.0f, result[15]), "inverse identity m[3,3]");
}

MU_TEST(test_mat4_translation)
{
    mfloat_t m[MAT4_SIZE];
    mat4_identity(m);
    mfloat_t v[VEC3_SIZE] = {10.0f, 20.0f, 30.0f};
    mfloat_t result[MAT4_SIZE];
    mat4_translation(result, m, v);
    mu_assert(float_eq(10.0f, result[12]), "translation x");
    mu_assert(float_eq(20.0f, result[13]), "translation y");
    mu_assert(float_eq(30.0f, result[14]), "translation z");
}

MU_TEST(test_mat4_rotation_x)
{
    mfloat_t result[MAT4_SIZE];
    mat4_rotation_x(result, 0.0f);
    mu_assert(float_eq(1.0f, result[0]), "rotation_x(0) m[0,0]");
    mu_assert(float_eq(1.0f, result[5]), "rotation_x(0) m[1,1]");
    mu_assert(float_eq(1.0f, result[10]), "rotation_x(0) m[2,2]");
    mu_assert(float_eq(1.0f, result[15]), "rotation_x(0) m[3,3]");
}

MU_TEST(test_mat4_rotation_y)
{
    mfloat_t result[MAT4_SIZE];
    mat4_rotation_y(result, 0.0f);
    mu_assert(float_eq(1.0f, result[0]), "rotation_y(0) m[0,0]");
    mu_assert(float_eq(1.0f, result[5]), "rotation_y(0) m[1,1]");
    mu_assert(float_eq(1.0f, result[10]), "rotation_y(0) m[2,2]");
}

MU_TEST(test_mat4_rotation_z)
{
    mfloat_t result[MAT4_SIZE];
    mat4_rotation_z(result, 0.0f);
    mu_assert(float_eq(1.0f, result[0]), "rotation_z(0) m[0,0]");
    mu_assert(float_eq(1.0f, result[5]), "rotation_z(0) m[1,1]");
    mu_assert(float_eq(1.0f, result[10]), "rotation_z(0) m[2,2]");
}

MU_TEST(test_mat4_rotation_axis)
{
    mfloat_t axis[VEC3_SIZE] = {0.0f, 0.0f, 1.0f};
    mfloat_t result[MAT4_SIZE];
    mat4_rotation_axis(result, axis, 0.0f);
    mu_assert(float_eq(1.0f, result[0]), "rotation_axis(0) m[0,0]");
    mu_assert(float_eq(1.0f, result[5]), "rotation_axis(0) m[1,1]");
    mu_assert(float_eq(1.0f, result[10]), "rotation_axis(0) m[2,2]");
}

MU_TEST(test_mat4_scaling)
{
    mfloat_t m[MAT4_SIZE];
    mat4_identity(m);
    mfloat_t v[VEC3_SIZE] = {2.0f, 3.0f, 4.0f};
    mfloat_t result[MAT4_SIZE];
    mat4_scaling(result, m, v);
    mu_assert(float_eq(2.0f, result[0]), "scale x");
    mu_assert(float_eq(3.0f, result[5]), "scale y");
    mu_assert(float_eq(4.0f, result[10]), "scale z");
}

MU_TEST(test_mat4_ortho)
{
    mfloat_t result[MAT4_SIZE];
    mat4_ortho(result, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    mu_assert(result[0] != 0.0f, "ortho m[0,0] defined");
    mu_assert(result[5] != 0.0f, "ortho m[1,1] defined");
    mu_assert(result[10] != 0.0f, "ortho m[2,2] defined");
}

MU_TEST(test_mat4_perspective)
{
    mfloat_t result[MAT4_SIZE];
    mfloat_t fov_y = to_radians(60.0f);
    mfloat_t aspect = 1.5f;
    mfloat_t n = 0.1f;
    mfloat_t f = 100.0f;
    mat4_perspective(result, fov_y, aspect, n, f);

    // Expected values for OpenGL-style perspective matrix (column-major):
    // cot(fov_y/2) = 1/tan(30°) = sqrt(3) ≈ 1.732
    mfloat_t cot_half_fov = MFLOAT_C(1.0) / MTAN(fov_y * MFLOAT_C(0.5));

    // result[0] = cot(fov_y/2) / aspect
    mu_assert(nearly_equal(result[0], cot_half_fov / aspect, 0.0001f), "perspective m[0,0] X scale");
    // result[5] = cot(fov_y/2)
    mu_assert(nearly_equal(result[5], cot_half_fov, 0.0001f), "perspective m[1,1] Y scale");
    // result[10] = f / (n - f)
    mu_assert(nearly_equal(result[10], f / (n - f), 0.0001f), "perspective m[2,2] depth");
    // result[11] = -1
    mu_assert(nearly_equal(result[11], -1.0f, 0.0001f), "perspective m[2,3] = -1");
    // result[14] = (n * f) / (n - f)
    mu_assert(nearly_equal(result[14], (n * f) / (n - f), 0.0001f), "perspective m[3,2] depth offset");

    // Verify Y scale > X scale when aspect > 1 (wide screen)
    mu_assert(result[5] > result[0], "Y scale > X scale for wide aspect");
}

MU_TEST(test_mat4_look_at)
{
    mfloat_t position[VEC3_SIZE] = {0.0f, 0.0f, 5.0f};
    mfloat_t target[VEC3_SIZE] = {0.0f, 0.0f, 0.0f};
    mfloat_t up[VEC3_SIZE] = {0.0f, 1.0f, 0.0f};
    mfloat_t result[MAT4_SIZE];
    mat4_look_at(result, position, target, up);
    mu_assert(result[0] != 0.0f || result[5] != 0.0f, "look_at defined");
}

// Struct-based API tests (smat4_*)
MU_TEST(test_smat4_zero)
{
    struct mat4 m = smat4_zero();
    mu_assert(float_eq(0.0f, m.m11), "m11 zero");
    mu_assert(float_eq(0.0f, m.m22), "m22 zero");
    mu_assert(float_eq(0.0f, m.m33), "m33 zero");
    mu_assert(float_eq(0.0f, m.m44), "m44 zero");
}

MU_TEST(test_smat4_identity)
{
    struct mat4 m = smat4_identity();
    mu_assert(float_eq(1.0f, m.m11), "m[0,0] = 1");
    mu_assert(float_eq(1.0f, m.m22), "m[1,1] = 1");
    mu_assert(float_eq(1.0f, m.m33), "m[2,2] = 1");
    mu_assert(float_eq(1.0f, m.m44), "m[3,3] = 1");
}

MU_TEST(test_smat4_determinant)
{
    struct mat4 m = smat4_identity();
    mfloat_t det = smat4_determinant(m);
    mu_assert(float_eq(1.0f, det), "identity determinant = 1");
}

MU_TEST(test_smat4_negative)
{
    struct mat4 m = smat4_identity();
    struct mat4 result = smat4_negative(m);
    mu_assert(float_eq(-1.0f, result.m11), "negative m[0,0]");
    mu_assert(float_eq(-1.0f, result.m22), "negative m[1,1]");
}

MU_TEST(test_smat4_transpose)
{
    struct mat4 m = smat4_identity();
    m.m12 = 2.0f;
    m.m21 = 3.0f;
    struct mat4 result = smat4_transpose(m);
    mu_assert(float_eq(3.0f, result.m12), "transposed m[0,1]");
    mu_assert(float_eq(2.0f, result.m21), "transposed m[1,0]");
}

MU_TEST(test_smat4_multiply)
{
    struct mat4 identity = smat4_identity();
    struct mat4 m = smat4_identity();
    m.m14 = 5.0f;  // Translation X
    struct mat4 result = smat4_multiply(m, identity);
    mu_assert(float_eq(5.0f, result.m14), "M * I preserves translation");
}

MU_TEST(test_smat4_multiply_f)
{
    struct mat4 m = smat4_identity();
    struct mat4 result = smat4_multiply_f(m, 2.0f);
    mu_assert(float_eq(2.0f, result.m11), "scaled m[0,0]");
    mu_assert(float_eq(2.0f, result.m22), "scaled m[1,1]");
}

MU_TEST(test_smat4_inverse)
{
    struct mat4 m = smat4_identity();
    struct mat4 result = smat4_inverse(m);
    mu_assert(float_eq(1.0f, result.m11), "inverse identity m[0,0]");
    mu_assert(float_eq(1.0f, result.m22), "inverse identity m[1,1]");
}

MU_TEST(test_smat4_translation)
{
    struct mat4 m = smat4_identity();
    struct vec3 v = svec3(10.0f, 20.0f, 30.0f);
    struct mat4 result = smat4_translation(m, v);
    mu_assert(float_eq(10.0f, result.m14), "translation x");
    mu_assert(float_eq(20.0f, result.m24), "translation y");
    mu_assert(float_eq(30.0f, result.m34), "translation z");
}

MU_TEST(test_smat4_rotation_x)
{
    struct mat4 result = smat4_rotation_x(0.0f);
    mu_assert(float_eq(1.0f, result.m11), "rotation_x(0) m[0,0]");
    mu_assert(float_eq(1.0f, result.m22), "rotation_x(0) m[1,1]");
    mu_assert(float_eq(1.0f, result.m33), "rotation_x(0) m[2,2]");
}

MU_TEST(test_smat4_rotation_y)
{
    struct mat4 result = smat4_rotation_y(0.0f);
    mu_assert(float_eq(1.0f, result.m11), "rotation_y(0) m[0,0]");
    mu_assert(float_eq(1.0f, result.m22), "rotation_y(0) m[1,1]");
    mu_assert(float_eq(1.0f, result.m33), "rotation_y(0) m[2,2]");
}

MU_TEST(test_smat4_rotation_z)
{
    struct mat4 result = smat4_rotation_z(0.0f);
    mu_assert(float_eq(1.0f, result.m11), "rotation_z(0) m[0,0]");
    mu_assert(float_eq(1.0f, result.m22), "rotation_z(0) m[1,1]");
    mu_assert(float_eq(1.0f, result.m33), "rotation_z(0) m[2,2]");
}

MU_TEST(test_smat4_scaling)
{
    struct mat4 m = smat4_identity();
    struct vec3 v = svec3(2.0f, 3.0f, 4.0f);
    struct mat4 result = smat4_scaling(m, v);
    mu_assert(float_eq(2.0f, result.m11), "scale x");
    mu_assert(float_eq(3.0f, result.m22), "scale y");
    mu_assert(float_eq(4.0f, result.m33), "scale z");
}

MU_TEST(test_smat4_ortho)
{
    struct mat4 result = smat4_ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    mu_assert(result.m11 != 0.0f, "ortho m[0,0] defined");
}

MU_TEST(test_smat4_perspective)
{
    mfloat_t fov_y = to_radians(60.0f);
    mfloat_t aspect = 1.5f;
    mfloat_t n = 0.1f;
    mfloat_t f = 100.0f;
    struct mat4 result = smat4_perspective(fov_y, aspect, n, f);

    mfloat_t cot_half_fov = MFLOAT_C(1.0) / MTAN(fov_y * MFLOAT_C(0.5));

    mu_assert(nearly_equal(result.m11, cot_half_fov / aspect, 0.0001f), "perspective m11 X scale");
    mu_assert(nearly_equal(result.m22, cot_half_fov, 0.0001f), "perspective m22 Y scale");
    mu_assert(result.m22 > result.m11, "Y scale > X scale for wide aspect");
}

MU_TEST(test_smat4_look_at)
{
    struct vec3 position = svec3(0.0f, 0.0f, 5.0f);
    struct vec3 target = svec3(0.0f, 0.0f, 0.0f);
    struct vec3 up = svec3(0.0f, 1.0f, 0.0f);
    struct mat4 result = smat4_look_at(position, target, up);
    mu_assert(result.m11 != 0.0f || result.m22 != 0.0f, "look_at defined");
}

// Edge case / Negative tests
MU_TEST(test_mat4_multiply_inverse_is_identity)
{
    // Use a translation matrix
    mfloat_t m[MAT4_SIZE];
    mat4_identity(m);
    m[12] = 10.0f;
    m[13] = 20.0f;
    m[14] = 30.0f;
    
    mfloat_t m_inv[MAT4_SIZE];
    mfloat_t result[MAT4_SIZE];
    
    mat4_inverse(m_inv, m);
    mat4_multiply(result, m, m_inv);
    
    mu_assert(float_eq(1.0f, result[0]), "M*M^-1 = I [0,0]");
    mu_assert(float_eq(1.0f, result[5]), "M*M^-1 = I [1,1]");
    mu_assert(float_eq(1.0f, result[10]), "M*M^-1 = I [2,2]");
    mu_assert(float_eq(1.0f, result[15]), "M*M^-1 = I [3,3]");
    mu_assert(float_eq(0.0f, result[12]), "M*M^-1 = I translation x");
}


MU_TEST_SUITE(test_suite)
{
    // Pointer-based API tests
    MU_RUN_TEST(test_mat4_zero);
    MU_RUN_TEST(test_mat4_identity);
    MU_RUN_TEST(test_mat4_determinant_identity);
    MU_RUN_TEST(test_mat4_negative);
    MU_RUN_TEST(test_mat4_transpose);
    MU_RUN_TEST(test_mat4_multiply_identity);
    MU_RUN_TEST(test_mat4_multiply_f);
    MU_RUN_TEST(test_mat4_inverse_identity);
    MU_RUN_TEST(test_mat4_translation);
    MU_RUN_TEST(test_mat4_rotation_x);
    MU_RUN_TEST(test_mat4_rotation_y);
    MU_RUN_TEST(test_mat4_rotation_z);
    MU_RUN_TEST(test_mat4_rotation_axis);
    MU_RUN_TEST(test_mat4_scaling);
    MU_RUN_TEST(test_mat4_ortho);
    MU_RUN_TEST(test_mat4_perspective);
    MU_RUN_TEST(test_mat4_look_at);

    // Struct-based API tests
    MU_RUN_TEST(test_smat4_zero);
    MU_RUN_TEST(test_smat4_identity);
    MU_RUN_TEST(test_smat4_determinant);
    MU_RUN_TEST(test_smat4_negative);
    MU_RUN_TEST(test_smat4_transpose);
    MU_RUN_TEST(test_smat4_multiply);
    MU_RUN_TEST(test_smat4_multiply_f);
    MU_RUN_TEST(test_smat4_inverse);
    MU_RUN_TEST(test_smat4_translation);
    MU_RUN_TEST(test_smat4_rotation_x);
    MU_RUN_TEST(test_smat4_rotation_y);
    MU_RUN_TEST(test_smat4_rotation_z);
    MU_RUN_TEST(test_smat4_scaling);
    MU_RUN_TEST(test_smat4_ortho);
    MU_RUN_TEST(test_smat4_perspective);
    MU_RUN_TEST(test_smat4_look_at);

    // Edge case / Negative tests
    MU_RUN_TEST(test_mat4_multiply_inverse_is_identity);
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
