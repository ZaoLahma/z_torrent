add_library(sha1 "")

target_sources(sha1
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/sha1/sha1.hpp
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/sha1/sha1.cpp
  )
target_include_directories(sha1
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/sha1
  )

set_target_properties(sha1 PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(zlog/cpp/zlog)