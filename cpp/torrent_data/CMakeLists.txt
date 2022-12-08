add_library(torrentdata "")

target_sources(torrentdata
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/torrent_attribute_type.h
    ${CMAKE_CURRENT_LIST_DIR}/inc/torrent_attribute.h
    ${CMAKE_CURRENT_LIST_DIR}/inc/torrent_dict_attribute.h
    ${CMAKE_CURRENT_LIST_DIR}/inc/torrent_list_attribute.h
    ${CMAKE_CURRENT_LIST_DIR}/inc/torrent_string_attribute.h
    ${CMAKE_CURRENT_LIST_DIR}/inc/torrent_int_attribute.h
    ${CMAKE_CURRENT_LIST_DIR}/inc/torrent_file_decoder.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_attribute.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_dict_attribute.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_list_attribute.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_string_attribute.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_int_attribute.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_file_decoder.cpp
  )
target_include_directories(torrentdata
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  )

set_target_properties(torrentdata PROPERTIES LINKER_LANGUAGE CXX)