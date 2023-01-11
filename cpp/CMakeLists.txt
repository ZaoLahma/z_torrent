add_executable(ztorrent main/src/main.cpp)
target_compile_options(ztorrent PRIVATE -Werror -Wall -Wextra -Wconversion)

add_executable(test_ztorrent 
    test/src/main.cpp 
    util/test/util_test.cpp 
    config/test/config_test.cpp
    torrent_file_handler/test/watch_dir_test.cpp
    core/test/thread_object_test.cpp
)
target_compile_options(test_ztorrent PRIVATE -Werror -Wall -Wextra -Wconversion)

add_subdirectory(util)
add_subdirectory(core)
add_subdirectory(config)
add_subdirectory(torrent_file_handler)
add_subdirectory(torrent_data)
add_subdirectory(torrent_data_handler)
add_subdirectory(external_deps)

target_compile_definitions(core PUBLIC 
    $<$<CONFIG:Debug>:DEBUG=1>
  )

# Link the executable
target_link_libraries(ztorrent
    PRIVATE
        util
        config
        torrentfilehandler
        torrentdatahandler
        core
        zlog
)

# Link the test executable
target_link_libraries(test_ztorrent 
    PRIVATE 
        gtest 
        gmock
        util
        config
        torrentfilehandler
        torrentdatahandler
        core
        zlog
)