set (CMAKE_CXX_STANDARD 17)

cmake_minimum_required(VERSION 3.0.0)
project(challenge1 VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(./)

file(GLOB Target_Files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS *.cpp)

add_executable(main ${Target_Files})
# add_executable(challenge1 main.cpp)




set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)