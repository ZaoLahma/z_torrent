add_library(core "")

target_link_libraries(core
    PUBLIC
        zlog
  )

target_sources(core
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/log_context.h
    ${CMAKE_CURRENT_LIST_DIR}/inc/thread_object.h
    ${CMAKE_CURRENT_LIST_DIR}/inc/task.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/log_context.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/thread_object.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/task.cpp
  )
target_include_directories(core
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  )

set_target_properties(core PROPERTIES LINKER_LANGUAGE CXX)