add_library(workdir "")

target_link_libraries(workdir
    PUBLIC
        config
  )

target_sources(workdir
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/work_dir.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/work_dir.cpp
  )
target_include_directories(workdir
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  )

set_target_properties(workdir PROPERTIES LINKER_LANGUAGE CXX)