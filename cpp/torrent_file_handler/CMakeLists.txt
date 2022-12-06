add_library(torrentfilehandler "")

target_link_libraries(torrentfilehandler
    PUBLIC
        config
        core
        torrentdata
  )

target_sources(torrentfilehandler
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/watch_dir_task.h
    ${CMAKE_CURRENT_LIST_DIR}/inc/torrent_file_thread.h
    ${CMAKE_CURRENT_LIST_DIR}/inc/torrent_file_decoder_task.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/watch_dir_task.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_file_thread.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_file_decoder_task.cpp
  )
target_include_directories(torrentfilehandler
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  )

set_target_properties(torrentfilehandler PROPERTIES LINKER_LANGUAGE CXX)