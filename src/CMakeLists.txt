set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")
set(circle_header ${header_path}/circle.h)
set(tasks_header ${header_path}/tasks.h)

set(circle_src circle.cpp)
set(tasks_src tasks.cpp)

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

find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME}
  Threads::Threads
)

set_target_properties(${PROJECT_NAME} PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/Release"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/Release"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/Release"
)

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

add_dependencies(${PROJECT_NAME}.info ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}.info PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/Release"
)

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
