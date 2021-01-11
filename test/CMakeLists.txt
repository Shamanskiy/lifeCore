add_executable(
    unit_tests
    lifeCore_test.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    lifeCore
    )

target_include_directories(unit_tests PRIVATE "${PROJECT_SOURCE_DIR}/src")


add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/bin/unit_tests
  )
