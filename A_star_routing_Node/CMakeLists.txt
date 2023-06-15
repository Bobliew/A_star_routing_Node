# 添加库
add_library(A_star_routing_Node OBJECT aStarUtils.cc object.cc)

# 添加头文件路径
target_include_directories(A_star_routing_Node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 设置编译选项
target_compile_options(A_star_routing_Node PRIVATE -Wall -Wextra -pedantic)
