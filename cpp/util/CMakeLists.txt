add_library(util "")

target_sources(util
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/util.h
#  PRIVATE
#    ${CMAKE_CURRENT_LIST_DIR}/src/util.cpp
  )
target_include_directories(util
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  )

set_target_properties(util PROPERTIES LINKER_LANGUAGE CXX)