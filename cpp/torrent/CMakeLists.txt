add_library(torrent "")

target_link_libraries(torrent
    PUBLIC
        core
  )

target_sources(torrent
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/bdecode.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/bdecode.cpp
  )
target_include_directories(torrent
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  )

set_target_properties(torrent PROPERTIES LINKER_LANGUAGE CXX)