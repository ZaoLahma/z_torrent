add_library(torrentdatahandler "")

target_link_libraries(torrentdatahandler
  PUBLIC
    core
  )

target_sources(torrentdatahandler
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/torrent_data_task.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_data_task.cpp
  )
target_include_directories(torrentdatahandler
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  )

set_target_properties(torrentdatahandler PROPERTIES LINKER_LANGUAGE CXX)