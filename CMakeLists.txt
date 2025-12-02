cmake_minimum_required(VERSION 3.16)
project(mathc VERSION 2019.02.16 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# =============================================================================
# Main Library
# =============================================================================

add_library(mathc STATIC
    source/mathc.c
    source/mathc.h
)

target_include_directories(mathc PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/source/
)

# =============================================================================
# Tests
# =============================================================================

option(MATHC_BUILD_TESTS "Build mathc tests" ON)

if(MATHC_BUILD_TESTS)
    enable_testing()

    # minunit header-only library
    add_library(minunit INTERFACE)
    target_include_directories(minunit INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/minunit)

    # Helper function to add tests
    function(mathc_add_test TEST_NAME)
        add_executable(${TEST_NAME} tests/${TEST_NAME}.c)
        target_link_libraries(${TEST_NAME} PRIVATE mathc minunit)
        target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
        add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
    endfunction()

    # Test executables
    mathc_add_test(test_utils)
    mathc_add_test(test_vec2i)
    mathc_add_test(test_vec3i)
    mathc_add_test(test_vec4i)
    mathc_add_test(test_vec2)
    mathc_add_test(test_vec3)
    mathc_add_test(test_vec4)
    mathc_add_test(test_quat)
    mathc_add_test(test_mat2)
    mathc_add_test(test_mat3)
    mathc_add_test(test_mat4)
    mathc_add_test(test_easing)
endif()

# =============================================================================
# Install
# =============================================================================

include(GNUInstallDirs)

install(TARGETS mathc
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(FILES source/mathc.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
