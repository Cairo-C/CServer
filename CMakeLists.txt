cmake_minimum_required (VERSION 2.8)

project(CServer)

# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS)

find_package (Threads)

# 指定生成目标
add_executable(CServer ${DIR_SRCS})

target_link_libraries (CServer ${CMAKE_THREAD_LIBS_INIT})
