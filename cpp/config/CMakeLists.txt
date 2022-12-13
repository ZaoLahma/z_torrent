add_library(config "")

target_link_libraries(config
    PUBLIC
        core
  )

target_sources(config
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/config.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/config.cpp
  )
target_include_directories(config
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  )

set_target_properties(config PROPERTIES LINKER_LANGUAGE CXX)