add_library(core "")

#target_link_libraries(core
#    PUBLIC
#        config
#  )

target_sources(core
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/thread_object.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/thread_object.cpp
  )
target_include_directories(core
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  )

set_target_properties(core PROPERTIES LINKER_LANGUAGE CXX)