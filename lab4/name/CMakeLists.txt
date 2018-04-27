
project(name)

set(HEDEAR_FILES Name.h)
set(SOURCE_FILES Name.cpp)

add_library(libname STATIC ${SOURCE_FILES})
target_include_directories(libname PUBLIC .)

add_executable(name ${SOURCE_FILES} main.cpp)

target_link_libraries(name libname)

