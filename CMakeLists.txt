# ----------------------------------------------------------------------------
# SymForce - Copyright 2022, Skydio, Inc.
# This source code is under the Apache 2.0 license found in the LICENSE file.
# ----------------------------------------------------------------------------

# NOTE(aaron): This is the minimum version for FetchContent, not sure if we need newer; certainly no
# newer than 3.15 required
cmake_minimum_required(VERSION 3.11)

project(symforce)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==============================================================================
# User-Configurable Options
# ==============================================================================

# ------------------------------------------------------------------------------
# Enable/Disable Components

option(SYMFORCE_BUILD_OPT "Build symforce_opt and related targets for optimization" ON)
option(SYMFORCE_BUILD_CC_SYM "Build cc_sym and related targets for python wrapping" ON)
option(SYMFORCE_BUILD_EXAMPLES "Build the examples" ON)
option(SYMFORCE_BUILD_TESTS "Build the tests" ON)
option(SYMFORCE_BUILD_SYMENGINE "Build symengine[py]" ON)
option(SYMFORCE_GENERATE_MANIFEST "Generate build manifest" ON)
option(SYMFORCE_BUILD_BENCHMARKS "Generate examples for alternative libraries" OFF)

# ------------------------------------------------------------------------------
# TicTocs

option(SYMFORCE_CUSTOM_TIC_TOCS
  "Use the user-provided TicTocs instead of the builtin implementation"
  OFF
)
set(SYMFORCE_TIC_TOC_TARGET "" CACHE STRING
  "If SYMFORCE_CUSTOM_TIC_TOCS is on, this should be a target to depend on that provides TicTocs"
)
set(SYMFORCE_TIC_TOC_HEADER "" CACHE STRING
  "If SYMFORCE_CUSTOM_TIC_TOCS is on, this should be the name of a header to include that provides the TicTocs implementation"
)
set(SYMFORCE_TIC_TOC_MACRO "" CACHE STRING
  "If SYMFORCE_CUSTOM_TIC_TOCS is on, this should be the implementation of the SYM_TIME_SCOPE macro (typically another macro, or a function)"
)

# ------------------------------------------------------------------------------
# LCM

option(SYMFORCE_USE_EXTERNAL_LCM
  "Use external LCM and generated bindings instead of generating them ourselves"
  OFF
)

set(SYMFORCE_LCMTYPES_TARGET "" CACHE STRING
  "If SYMFORCE_LCMTYPES_EXTERNAL is on, this should be the name of a target we can depend on to get the already generated LCM types"
)

# ------------------------------------------------------------------------------
# Misc

option(SYMFORCE_BUILD_STATIC_LIBRARIES
  "Build libraries as static (symforce_cholesky is always built as shared)"
  OFF
)

find_program(SYMFORCE_DEFAULT_PYTHON python3 NO_CACHE)
set(SYMFORCE_PYTHON "${SYMFORCE_DEFAULT_PYTHON}" CACHE STRING "Python executable to use")


set(SYMFORCE_SYMENGINE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/symengine_install CACHE STRING
  "Directory to install symengine"
)

set(SYMENGINEPY_INSTALL_ENV "" CACHE STRING "Options for symenginepy install step")

set(SYMFORCE_PY_EXTENSION_MODULE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/pybind CACHE PATH
  "Location to place generated python extension modules"
)

set(SYMFORCE_EIGEN_TARGET "Eigen3::Eigen" CACHE STRING
  "Target to depend on for Eigen. Default is to find Eigen with find_package."
)

# ==============================================================================
# Setup
# ==============================================================================

if(SYMFORCE_BUILD_STATIC_LIBRARIES)
  set(SYMFORCE_LIBRARY_TYPE STATIC)
else()
  set(SYMFORCE_LIBRARY_TYPE SHARED)
endif()

if(SYMFORCE_BUILD_CC_SYM
   OR SYMFORCE_BUILD_EXAMPLES
   OR SYMFORCE_BUILD_TESTS
   OR SYMFORCE_GENERATE_MANIFEST)
  if(NOT SYMFORCE_BUILD_OPT)
    message(FATAL_ERROR
      "Attempting to build targets that depend on symforce_opt, without building symforce_opt"
    )
  endif()
endif()

# ==============================================================================
# Third Party Dependencies (needed for build)
# ==============================================================================

include(FetchContent)

# ------------------------------------------------------------------------------
# eigen3

if(SYMFORCE_EIGEN_TARGET STREQUAL "Eigen3::Eigen")
  find_package(Eigen3 QUIET)
  if(NOT Eigen3_FOUND)
    message(STATUS "Eigen3 not found, adding with FetchContent")
    function(add_eigen)
      FetchContent_Declare(
        eigen3
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen
        GIT_TAG 3147391d946bb4b6c68edd901f2add6ac1f31f8c  # release 3.4.0
        GIT_SHALLOW TRUE
      )

      set(EIGEN_BUILD_DOC OFF CACHE BOOL "Don't build Eigen docs")
      set(BUILD_TESTING OFF CACHE BOOL "Don't build Eigen tests")
      set(EIGEN_BUILD_PKGCONFIG OFF CACHE BOOL "Don't build Eigen pkg-config")
      FetchContent_MakeAvailable(eigen3)
    endfunction()

    add_eigen()

    # Enable use of Eigen3_ROOT, which is necessary for sophus to be able to find Eigen when
    # included this way
    # See https://cmake.org/cmake/help/latest/policy/CMP0074.html
    set(CMAKE_POLICY_DEFAULT_CMP0074 NEW CACHE STRING "" FORCE)
    set(Eigen3_ROOT "${FETCHCONTENT_BASE_DIR}/eigen3-src" CACHE PATH "Phooey" FORCE)
  else()
    message(STATUS "Eigen found at ${Eigen3_DIR}")
  endif()
endif()


# These dependencies are not needed for symforce_gen
if(SYMFORCE_BUILD_OPT)
  # ------------------------------------------------------------------------------
  # fmtlib

  find_package(fmt QUIET)
  if (NOT fmt_FOUND)
    message(STATUS "fmt not found, adding with FetchContent")
    function(add_fmt)
      FetchContent_Declare(
        fmtlib
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG d141cdbeb0fb422a3fb7173b285fd38e0d1772dc # release 8.0.1
        GIT_SHALLOW TRUE
      )
      set(CMAKE_POSITION_INDEPENDENT_CODE True)
      FetchContent_MakeAvailable(fmtlib)
    endfunction()

    add_fmt()
  else()
    message(STATUS "fmt found")
  endif()

  # ------------------------------------------------------------------------------
  # spdlog

  find_package(spdlog QUIET)
  if (NOT spdlog_FOUND)
    message(STATUS "spdlog not found, adding with FetchContent")
    function(add_spdlog)
      set(SPDLOG_FMT_EXTERNAL ON CACHE INTERNAL "spdlog shouldn't use its bundled fmtlib")
      set(CMAKE_POSITION_INDEPENDENT_CODE True)
      FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog
        GIT_TAG eb3220622e73a4889eee355ffa37972b3cac3df5 # release 1.9.2
        GIT_SHALLOW TRUE
      )
      FetchContent_MakeAvailable(spdlog)
    endfunction()

    add_spdlog()
  else()
    message(STATUS "spdlog found")
  endif()

  # ------------------------------------------------------------------------------
  # tl::optional

  find_package(tl-optional QUIET)
  if (NOT tl_optional_FOUND)
    message(STATUS "tl::optional not found, adding with FetchContent")
    function(add_tl_optional)
      set(OPTIONAL_ENABLE_TESTS OFF CACHE INTERNAL "tl::optional shouldn't build tests")
      FetchContent_Declare(
        tl_optional
        GIT_REPOSITORY https://github.com/TartanLlama/optional
        GIT_TAG v1.0.0
        GIT_SHALLOW TRUE
      )
      FetchContent_MakeAvailable(tl_optional)

      # tl::optional does this correctly for installs, but not direct includes with FetchContent
      add_library(tl::optional ALIAS optional)
    endfunction()

    add_tl_optional()
  else()
    message(STATUS "tl::optional found")
  endif()

  # ------------------------------------------------------------------------------
  # METIS

  function(add_metis)
    set(CMAKE_POSITION_INDEPENDENT_CODE True)
    FetchContent_Declare(
      metis
      # METIS does not have releases recently.  Previously were using nearly the initial commit on
      # github, which is newer than the release on the METIS website. All of the releases on github
      # seem to have memory bugs, which do not appear in this release:
      URL https://symforce-org.github.io/downloads/metis-5.1.0.tar.gz
      # GKlib builds some test executables we can't disable without patching
      PATCH_COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/cmake/patch_metis.sh" "${FETCHCONTENT_BASE_DIR}/metis-src"
    )

    # Tell metis where to find GKlib
    set(GKLIB_PATH
      "${FETCHCONTENT_BASE_DIR}/metis-src/GKlib" CACHE PATH "Path to GKlib for METIS" FORCE
    )

    set(METIS_LIBRARY_TYPE "SHARED" CACHE STRING "Always build METIS as a shared library" FORCE)

    FetchContent_MakeAvailable(metis)

    # Metis doesn't put its main header (metis.h) on the metis target
    FetchContent_GetProperties(metis SOURCE_DIR metis_SOURCE_DIR)
    target_include_directories(metis INTERFACE ${metis_SOURCE_DIR}/include)
  endfunction()

  add_metis()
endif(SYMFORCE_BUILD_OPT)

if(SYMFORCE_BUILD_CC_SYM)
  # ------------------------------------------------------------------------------
  # pybind11

  find_package(pybind11 QUIET)
  if (NOT pybind11_FOUND)
    message(STATUS "pybind11 not found, adding with FetchContent")
    FetchContent_Declare(
      pybind11
      GIT_REPOSITORY https://github.com/pybind/pybind11
      GIT_TAG e7c9753f1d35061d137ac3ce561e94a7407e5583 # release 2.8.1
    )
    FetchContent_MakeAvailable(pybind11)
  else()
    message(STATUS "pybind11 found")
  endif()
endif(SYMFORCE_BUILD_CC_SYM)

# Pull in third party packages used for benchmarking
if(SYMFORCE_BUILD_BENCHMARKS)

  # ------------------------------------------------------------------------------
  # Sophus

  find_package(Sophus QUIET)
  if (NOT Sophus_FOUND)
    message(STATUS "Sophus not found, adding with FetchContent")
    function(add_sophus)
      set(BUILD_TESTS OFF CACHE INTERNAL "Sophus shouldn't build tests by default")
      set(CMAKE_POSITION_INDEPENDENT_CODE True)
      FetchContent_Declare(
        sophus
        GIT_REPOSITORY https://github.com/strasdat/Sophus
        GIT_TAG v1.0.0
        GIT_SHALLOW TRUE
      )
      FetchContent_MakeAvailable(sophus)
      find_package(Sophus)
    endfunction()

    add_sophus()
  else()
    message(STATUS "Sophus found")
  endif()

  # ------------------------------------------------------------------------------
  # GTSAM

  find_package(gtsam QUIET)
  if (NOT gtsam_FOUND)
    # NOTE(aaron): gtsam will not build against a copy of Eigen we've downloaded but not installed,
    # because they include the eigen include directories in their install targets, and CMake
    # complains (correctly) about directories inside the build folder in install targets.  They
    # handle this correctly for their bundled version, but we cannot use that because the version of
    # Eigen that GTSAM is built with must match our version (which is what's used when we call GTSAM
    # code)
    message(STATUS "GTSAM not found, adding with FetchContent")
    function(add_gtsam)
      set(GTSAM_BUILD_WITH_MARCH_NATIVE OFF CACHE INTERNAL "GTSAM shouldn't build native by default")
      set(GTSAM_BUILD_TESTS OFF CACHE INTERNAL "Don't build GTSAM tests")
      set(GTSAM_BUILD_EXAMPLES_ALWAYS OFF CACHE INTERNAL "Don't build GTSAM examples")
      set(GTSAM_WITH_TBB OFF CACHE INTERNAL "Don't build TBB with GTSAM for accurate profiling")
      # NOTE(aaron): This seems to have no effect on the experiments we're doing
      set(GTSAM_SLOW_BUT_CORRECT_BETWEENFACTOR ON CACHE INTERNAL "Use the correct BetweenFactor")
      # NOTE(aaron): This has no effect other than making inverse compose chained slower
      set(GTSAM_USE_QUATERNIONS ON CACHE INTERNAL "Use quaternions for Rot3")
      set(CMAKE_POSITION_INDEPENDENT_CODE True)
      FetchContent_Declare(
        gtsam
        GIT_REPOSITORY https://github.com/borglab/gtsam
        GIT_TAG 4.1.1
        GIT_SHALLOW TRUE
      )
      FetchContent_MakeAvailable(gtsam)
    endfunction()

    add_gtsam()
  else()
    message(STATUS "GTSAM found")
  endif()

  # ------------------------------------------------------------------------------
  # Ceres

  find_package(Ceres QUIET)
  if (NOT Ceres_FOUND)
    message(STATUS "Ceres not found, adding with FetchContent")
    function(add_ceres)
      set(BUILD_TESTING OFF CACHE INTERNAL "Don't enable tests")
      set(BUILD_EXAMPLES OFF CACHE INTERNAL "Don't build examples")
      set(BUILD_BENCHMARKS OFF CACHE INTERNAL "Don't build Ceres benchmarking suite")
      set(PROVIDE_UNINSTALL_TARGET
        OFF CACHE INTERNAL
        "Ceres shouldn't add uninstall target, gtsam already adds a target with the same name that collides"
        FORCE
      )
      set(
        CERES_THREADING_MODEL "NO_THREADS" CACHE INTERNAL "Don't use threads for benchmarking" FORCE
      )
      set(CMAKE_POSITION_INDEPENDENT_CODE True)
      FetchContent_Declare(
        ceres
        GIT_REPOSITORY https://github.com/ceres-solver/ceres-solver
        GIT_TAG 2.0.0
        GIT_SHALLOW TRUE
      )
      FetchContent_MakeAvailable(ceres)
    endfunction()

    add_ceres()
  else()
    message(STATUS "Ceres found")
  endif()

endif()

# ==============================================================================
# SymForce Targets
# ==============================================================================

if(SYMFORCE_USE_EXTERNAL_LCM)
  add_library(symforce_lcmtypes_cpp INTERFACE)
  target_link_libraries(symforce_lcmtypes_cpp ${SYMFORCE_LCMTYPES_TARGET})
else()
  include(third_party/skymarshal/cmake/skymarshal.cmake)

  add_skymarshal_bindings(symforce_lcmtypes
    ${CMAKE_CURRENT_BINARY_DIR}/lcmtypes
    ${CMAKE_CURRENT_SOURCE_DIR}/lcmtypes
  )

  target_include_directories(symforce_lcmtypes_cpp
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/third_party/eigen_lcm/lcmtypes/eigen_lcm_lcm/cpp
  )

  add_skymarshal_bindings(eigen_lcm
    ${CMAKE_CURRENT_BINARY_DIR}/lcmtypes
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/eigen_lcm/lcmtypes
    LANGUAGES python
  )

  add_custom_target(symforce_eigen_lcm_py ALL DEPENDS eigen_lcm_py)

  # Get SymForce version
  execute_process(
    COMMAND ${SYMFORCE_PYTHON} -c "from _version import version; print(version, end='')"
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/symforce
    OUTPUT_VARIABLE SYMFORCE_VERSION
  )
  file(WRITE
    ${CMAKE_CURRENT_BINARY_DIR}/lcmtypes/python2.7/setup.py
    "
from setuptools import setup, find_packages
setup(
  name='lcmtypes',
  version='${SYMFORCE_VERSION}',
  description='lcmtype python bindings (installed by SymForce)',
  long_description='lcmtype python bindings (installed by SymForce)',
  author='Skydio, Inc',
  author_email='hayk@skydio.com',
  license='Apache 2.0',
  packages=find_packages(),
  zip_safe=False,
)
    "
  )
endif()

# ------------------------------------------------------------------------------
# symforce_gen

file(GLOB_RECURSE SYMFORCE_GEN_SOURCES CONFIGURE_DEPENDS gen/cpp/**/*.cc)
file(GLOB_RECURSE SYMFORCE_GEN_HEADERS CONFIGURE_DEPENDS gen/cpp/**/*.tcc gen/cpp/**/*.h)
add_library(
  symforce_gen
  ${SYMFORCE_LIBRARY_TYPE}
  ${SYMFORCE_GEN_SOURCES}
  ${SYMFORCE_GEN_HEADERS}
)
target_link_libraries(symforce_gen ${SYMFORCE_EIGEN_TARGET} symforce_lcmtypes_cpp)
target_include_directories(
  symforce_gen
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/gen/cpp
)

if(SYMFORCE_BUILD_OPT)
  # ------------------------------------------------------------------------------
  # symforce_cholesky

  # NOTE(hayk): For licensing reasons keep this as a shared library and
  # do not link statically. Treat this as code for which we can provide source.
  file(GLOB SYMFORCE_CHOLESKY_SOURCES CONFIGURE_DEPENDS symforce/opt/cholesky/*.cc)
  file(GLOB SYMFORCE_CHOLESKY_HEADERS CONFIGURE_DEPENDS symforce/opt/cholesky/*.h symforce/opt/cholesky/*.tcc)
  add_library(
    symforce_cholesky
    SHARED
    ${SYMFORCE_CHOLESKY_SOURCES}
    ${SYMFORCE_CHOLESKY_HEADERS}
  )
  target_link_libraries(symforce_cholesky metis ${SYMFORCE_EIGEN_TARGET})
  target_include_directories(symforce_cholesky PUBLIC .)

  # ------------------------------------------------------------------------------
  # symforce_opt

  file(GLOB_RECURSE SYMFORCE_OPT_SOURCES CONFIGURE_DEPENDS symforce/opt/*.cc symforce/opt/**/*.cc)
  file(GLOB_RECURSE SYMFORCE_OPT_HEADERS CONFIGURE_DEPENDS symforce/opt/*.h symforce/opt/**/*.h symforce/opt/*.tcc symforce/opt/**/*.tcc)
  add_library(
    symforce_opt
    ${SYMFORCE_LIBRARY_TYPE}
    ${SYMFORCE_OPT_SOURCES}
    ${SYMFORCE_OPT_HEADERS}
  )
  target_link_libraries(symforce_opt
    symforce_gen
    symforce_cholesky
    fmt::fmt
    spdlog::spdlog
    tl::optional
    ${SYMFORCE_EIGEN_TARGET}
  )

  if(SYMFORCE_CUSTOM_TIC_TOCS)
    target_link_libraries(symforce_opt ${SYMFORCE_TIC_TOC_TARGET})
    target_compile_definitions(symforce_opt
      PUBLIC SYMFORCE_TIC_TOC_HEADER=${SYMFORCE_TIC_TOC_HEADER}
      PUBLIC SYM_TIME_SCOPE=${SYMFORCE_TIC_TOC_MACRO}
    )
  endif(SYMFORCE_CUSTOM_TIC_TOCS)

endif(SYMFORCE_BUILD_OPT)

if(SYMFORCE_BUILD_CC_SYM)
  # ------------------------------------------------------------------------------
  # cc_sym

  add_subdirectory(symforce/pybind)
endif(SYMFORCE_BUILD_CC_SYM)


# ==============================================================================
# Examples, Benchmarks, and Tests
# ==============================================================================

if(SYMFORCE_BUILD_EXAMPLES)
  # ------------------------------------------------------------------------------
  # symforce_examples

  file(GLOB_RECURSE SYMFORCE_EXAMPLES_SOURCES CONFIGURE_DEPENDS symforce/examples/**/*.cc)
  file(GLOB_RECURSE SYMFORCE_EXAMPLES_HEADERS CONFIGURE_DEPENDS symforce/examples/**/*.h symforce/examples/**/*.tcc)
  add_library(
    symforce_examples
    ${SYMFORCE_LIBRARY_TYPE}
    ${SYMFORCE_EXAMPLES_SOURCES}
    ${SYMFORCE_EXAMPLES_HEADERS}
  )
  target_link_libraries(
    symforce_examples
    symforce_gen
    symforce_opt
    ${SYMFORCE_EIGEN_TARGET}
  )
  target_include_directories(
    symforce_examples
    PUBLIC symforce/examples/bundle_adjustment_fixed_size/gen/cpp
  )
endif()

if (SYMFORCE_BUILD_BENCHMARKS)
  add_subdirectory(symforce/benchmarks)
endif()

if(SYMFORCE_BUILD_TESTS)
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin/tests)

  # ------------------------------------------------------------------------------
  # symforce_test library

  # TODO(aaron): This goes away when we upgrade to Catch2 v3
  add_library(
    symforce_catch2
    ${SYMFORCE_LIBRARY_TYPE}
    third_party/catch2/src/catch_amalgamated.cpp test/catch_main.cc
  )
  target_include_directories(
    symforce_catch2
    PUBLIC third_party/catch2/include
  )

  add_library(symforce_test INTERFACE)
  target_link_libraries(symforce_test INTERFACE symforce_catch2)
  target_include_directories(symforce_test
    INTERFACE test/symforce_function_codegen_test_data/symengine/cam_function_codegen_test_data/cpp
    INTERFACE test/symforce_function_codegen_test_data/symengine/codegen_multi_function_test_data/cpp
    INTERFACE test/symforce_function_codegen_test_data/symengine/codegen_nan_test_data/cpp
    INTERFACE test/symforce_function_codegen_test_data/symengine/codegen_sparse_matrix_test_data/cpp
    INTERFACE test/symforce_function_codegen_test_data/symengine/codegen_cpp_test_data/cpp
  )
  target_compile_definitions(
    symforce_test
    INTERFACE SYMFORCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}
  )

  # ------------------------------------------------------------------------------
  # C++ tests

  enable_testing()
  add_library(symforce_tests_metadata INTERFACE)
  file(GLOB SYMFORCE_TEST_CC_SOURCES CONFIGURE_DEPENDS test/*_test.cc)
  set(SYMFORCE_CC_TEST_TARGETS "")
  foreach(SOURCE_FILE ${SYMFORCE_TEST_CC_SOURCES})
    get_filename_component(TEST_NAME ${SOURCE_FILE} NAME_WE)
    set(BINARY_NAME tests/${TEST_NAME})
    set(TARGET_NAME bin.tests.${TEST_NAME})

    add_executable(${TARGET_NAME} ${SOURCE_FILE})
    set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME ${BINARY_NAME})
    set_target_properties(${TARGET_NAME} PROPERTIES TEST_NAME ${TEST_NAME})
    set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    target_link_libraries(
      ${TARGET_NAME}
      symforce_gen
      symforce_opt
      symforce_examples
      symforce_test
    )

    list(APPEND SYMFORCE_CC_TEST_TARGETS ${TARGET_NAME})

    add_test(${TEST_NAME} ${CMAKE_BINARY_DIR}/bin/${BINARY_NAME})
  endforeach()

  get_directory_property(have_parent_scope PARENT_DIRECTORY)
  if(have_parent_scope)
    set(SYMFORCE_CC_TEST_TARGETS "${SYMFORCE_CC_TEST_TARGETS}" PARENT_SCOPE)
  endif()

endif(SYMFORCE_BUILD_TESTS)

# ==============================================================================
# Manifest
# ==============================================================================

# The manifest contains various paths which are known to CMake and used later by other parts of
# SymForce, such as include paths of libraries we compile generated code against, and the paths to
# the lcm-gen executable and symengine.

if(SYMFORCE_GENERATE_MANIFEST)
  function(generate_manifest)
    get_target_property(eigen_include_dirs ${SYMFORCE_EIGEN_TARGET} INTERFACE_INCLUDE_DIRECTORIES)
    get_target_property(spdlog_include_dirs spdlog::spdlog INTERFACE_INCLUDE_DIRECTORIES)
    get_target_property(catch2_include_dirs symforce_catch2 INTERFACE_INCLUDE_DIRECTORIES)
    execute_process(
      COMMAND ${SYMFORCE_PYTHON} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/generate_manifest.py
                                --eigen_include_dirs "${eigen_include_dirs}"
                                --spdlog_include_dirs "${spdlog_include_dirs}"
                                --catch2_include_dirs "${catch2_include_dirs}"
                                --symenginepy_install_dir "${SYMFORCE_SYMENGINE_INSTALL_PREFIX}"
                                --cc_sym_install_dir "${SYMFORCE_PY_EXTENSION_MODULE_OUTPUT_PATH}"
                                --binary_output_dir "${CMAKE_BINARY_DIR}"
                                # TODO(aaron): Put this somewhere smarter
                                --manifest_path ${CMAKE_CURRENT_SOURCE_DIR}/build/manifest.json
    )
  endfunction()

  generate_manifest()
endif()

# ==============================================================================
# Third Party Dependencies (not needed for build)
# ==============================================================================

if(SYMFORCE_BUILD_SYMENGINE)

  # ------------------------------------------------------------------------------
  # SymEngine
  include(ExternalProject)
  ExternalProject_Add(symengine
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/third_party/symengine
    INSTALL_DIR ${SYMFORCE_SYMENGINE_INSTALL_PREFIX}
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
               -DBUILD_TESTS=OFF
               -DBUILD_BENCHMARKS=OFF
  )

  # ------------------------------------------------------------------------------
  # symenginepy

  ExternalProject_Add(symenginepy
    DEPENDS symengine
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/third_party/symenginepy
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ${SYMFORCE_PYTHON} ${PROJECT_SOURCE_DIR}/third_party/symenginepy/setup.py
        --verbose
        build_ext
        --build-type=Release
        --symengine-dir ${SYMFORCE_SYMENGINE_INSTALL_PREFIX}/lib/
    INSTALL_COMMAND env ${SYMENGINEPY_INSTALL_ENV} ${SYMFORCE_PYTHON}
        ${PROJECT_SOURCE_DIR}/third_party/symenginepy/setup.py
        --verbose
        install
        --prefix ${SYMFORCE_SYMENGINE_INSTALL_PREFIX}
  )

  # Rebuild symengine[py] on changed files
  function(add_sourcechanged_dependency project_name)
    set(cmake_stampdir ${CMAKE_CURRENT_BINARY_DIR}/${project_name}-prefix/src/${project_name}-stamp)
    set(git_stampfile ${CMAKE_CURRENT_BINARY_DIR}/${project_name}.stamp)
    set(git_check_rulename ${project_name}_check_git_clean)
    add_custom_target(${git_check_rulename}
      COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/cmake/rerun_if_needed.py
                  --path_to_check ${PROJECT_SOURCE_DIR}/third_party/${project_name}
                  --stamp_file ${git_stampfile}
                  --command_to_run "rm -rf ${cmake_stampdir}"
      )

    add_dependencies(${project_name} ${git_check_rulename})
  endfunction()

  add_sourcechanged_dependency(symengine)
  add_sourcechanged_dependency(symenginepy)

endif(SYMFORCE_BUILD_SYMENGINE)
