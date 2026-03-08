set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")

# Заголовочные файлы
set(circle_header ${header_path}/circle.h)
set(tasks_header ${header_path}/tasks.h)

# Исходные файлы
set(circle_src circle.cpp)
set(tasks_src tasks.cpp)

# Создаем общую библиотеку со всеми исходниками
add_library(${PROJECT_NAME} SHARED
  ${circle_header}
  ${circle_src}
  ${tasks_header}
  ${tasks_src}
)
  
target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
  pthread
)

# Исполняемый файл для демонстрации
add_executable(${PROJECT_NAME}.info 
  main.cpp
)

target_include_directories(${PROJECT_NAME}.info
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}.info
  ${PROJECT_NAME}
)

# Установка
install(TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION "${lib_dest}"
  ARCHIVE DESTINATION "${lib_dest}"
  COMPONENT library
)

install(TARGETS ${PROJECT_NAME}.info
  RUNTIME DESTINATION "${tool_dest}"
  COMPONENT library
)

install(FILES 
  ${header_path}/circle.h 
  ${header_path}/tasks.h
  DESTINATION "${include_dest}"
)

