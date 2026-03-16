add_executable(${PROJECT_NAME}.test
  tests.cpp
)

target_include_directories(${PROJECT_NAME}.test
  PRIVATE 
    ${${PROJECT_NAME}_SOURCE_DIR}/include
    ${gtest_SOURCE_DIR}/googletest/include
)

target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME}
  gtest
  gtest_main
  pthread  # В Linux нужен pthread
)

add_dependencies(${PROJECT_NAME}.test ${PROJECT_NAME})

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}.test)

install(TARGETS ${PROJECT_NAME}.test
  RUNTIME DESTINATION "${tool_dest}"
  COMPONENT testing
)

