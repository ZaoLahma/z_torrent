add_library(torrentdata "")

target_compile_definitions(torrentdata PRIVATE 
    $<$<CONFIG:Debug>:DEBUG=1>
  )

target_link_libraries(torrentdata
    PUBLIC
        core
  )

target_sources(torrentdata
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/torrent_data.h
    ${CMAKE_CURRENT_LIST_DIR}/inc/torrent_file_decoder.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_attribute.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_dict_attribute.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_list_attribute.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_string_attribute.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_int_attribute.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_file_decoder.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/torrent_data_impl.cpp
  )
target_include_directories(torrentdata
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/inc_internal
  )

set_target_properties(torrentdata PROPERTIES LINKER_LANGUAGE CXX)