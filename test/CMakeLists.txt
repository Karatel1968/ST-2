add_executable(${PROJECT_NAME}.test
  tests.cpp
)

target_include_directories(${PROJECT_NAME}.test
  PRIVATE ${${PROJECT_NAME}_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME}
  GTest::gtest
  GTest::gtest_main
  pthread
)

# Регистрируем тесты
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}.test)

# Установка тестового исполняемого файла
install(TARGETS ${PROJECT_NAME}.test
  RUNTIME DESTINATION "${tool_dest}"
  COMPONENT testing
)
