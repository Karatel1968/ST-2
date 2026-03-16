add_executable(${PROJECT_NAME}.test
  tests.cpp
)

target_include_directories(${PROJECT_NAME}.test
  PRIVATE 
    ${${PROJECT_NAME}_SOURCE_DIR}/include
    ${gtest_SOURCE_DIR}/googletest/include
)

find_package(Threads REQUIRED)

target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME}
  gtest
  gtest_main
  Threads::Threads
)

target_link_directories(${PROJECT_NAME}.test
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../src/Release"
)

add_dependencies(${PROJECT_NAME}.test ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}.test PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/Release"
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}.test)

install(TARGETS ${PROJECT_NAME}.test
  RUNTIME DESTINATION "${tool_dest}"
  COMPONENT testing
)

