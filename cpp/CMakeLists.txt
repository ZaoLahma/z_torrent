add_executable(ztorrent main/src/main.cpp)
target_compile_options(ztorrent PRIVATE -Werror -Wall -Wextra -Wconversion)


add_executable(test_ztorrent 
    test/src/main.cpp 
    util/test/util_test.cpp 
    config/test/config_test.cpp
)
target_compile_options(test_ztorrent PRIVATE -Werror -Wall -Wextra -Wconversion)

add_subdirectory(util)
add_subdirectory(config)


# Link the executable
target_link_libraries(ztorrent
    PRIVATE
        util
        config
)

# Link the test executable
target_link_libraries(test_ztorrent 
    PRIVATE 
        gtest 
        gmock
        util
        config
)