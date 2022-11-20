add_library(watchdir "")

target_link_libraries(watchdir
    PUBLIC
        config
        core
  )

target_sources(watchdir
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/watch_dir.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/watch_dir.cpp
  )
target_include_directories(watchdir
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  )

set_target_properties(watchdir PROPERTIES LINKER_LANGUAGE CXX)