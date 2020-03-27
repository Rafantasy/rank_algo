project(helloCFA)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_LIST src/sort)
add_executable(algo_print ${SRC_LIST})
