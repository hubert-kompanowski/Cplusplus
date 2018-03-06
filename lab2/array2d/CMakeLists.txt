
project(array2d)

set(HEDEAR_FILES Array2D.h)
set(SOURCE_FILES Array2D.cpp)

add_library(libarray2d STATIC ${SOURCE_FILES})
target_include_directories(libarray2d PUBLIC .)

add_executable(array2d ${SOURCE_FILES} main.cpp)

target_link_libraries(array2d libarray2d)
