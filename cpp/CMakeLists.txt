add_executable(ztorrent main/src/main.cpp)
target_compile_options(ztorrent PRIVATE -Werror -Wall -Wextra -Wconversion)


add_executable(test_ztorrent 
    test/src/main.cpp 
    util/test/util_test.cpp 
    config/test/config_test.cpp
    watch_dir/test/watch_dir_test.cpp
    core/test/thread_object_test.cpp
)
target_compile_options(test_ztorrent PRIVATE -Werror -Wall -Wextra -Wconversion)

add_subdirectory(util)
add_subdirectory(config)
add_subdirectory(watch_dir)
add_subdirectory(core)

# Link the executable
target_link_libraries(ztorrent
    PRIVATE
        util
        config
        watchdir
        core
)

# Link the test executable
target_link_libraries(test_ztorrent 
    PRIVATE 
        gtest 
        gmock
        util
        config
        watchdir
        core
)