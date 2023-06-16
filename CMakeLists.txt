cmake_minimum_required(VERSION 3.5)

# 设置项目名称和版本号
project(my_project VERSION 1.0)

# 添加可执行文件
add_executable(my_executable ./test_1.cpp)

# 添加 A_star_routing_Node 目录下的源文件
add_subdirectory(A_star_routing_Node)

# 链接 A_star_routing_Node 库
target_link_libraries(my_executable A_star_routing_Node)
