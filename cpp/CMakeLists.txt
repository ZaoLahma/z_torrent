add_executable(ztorrent main/src/main.cpp)
  
add_subdirectory(util)

target_link_libraries(ztorrent
  PRIVATE
    util
  )