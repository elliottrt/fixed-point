# filepath: /Users/reedelliott/code/c/cui/tests/CMakeLists.txt
function(create_test test_path)
  get_filename_component(test_name ${test_path} NAME_WE)

  add_executable(${test_name}
    ${test_path}
    ${PROJECT_SOURCE_DIR}/fixed_point.hpp
    ${PROJECT_SOURCE_DIR}/tests/test.hpp)

  target_include_directories(${test_name} PUBLIC ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/tests)
  # make sure all errors are known
  target_compile_options(${test_name} PUBLIC -Wall -Wextra -Wpedantic)
  # test for c++11
  target_compile_features(${test_name} PUBLIC cxx_std_11)
  # auto define the implementation macro for ease of use
  target_compile_definitions(${test_name} PUBLIC FIXED_POINT_IMPLEMENTATION)

  add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

file(GLOB tests *.cpp)
foreach(test_path ${tests})
  create_test(${test_path})
endforeach()