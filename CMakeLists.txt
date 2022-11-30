cmake_minimum_required(VERSION 3.0.0)
project(tcg VERSION 0.1.0)

set(TCG_SOURCE_DIR "src")
set(TCG_HEADERS_DIR "headers")

aux_source_directory(${TCG_SOURCE_DIR}  DIR_SRCS)
add_subdirectory(${TCG_SOURCE_DIR})

include_directories(
    ${TCG_SOURCE_DIR}
    ${TCG_HEADERS_DIR}
)
  
add_executable(tcg ${DIR_SRCS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)