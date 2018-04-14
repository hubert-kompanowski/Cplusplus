
project(arrayfill)

set(HEDEAR_FILES ArrayFill.h)
set(SOURCE_FILES ArrayFill.cpp)

add_library(libarrayfill STATIC ${SOURCE_FILES})
target_include_directories(libarrayfill PUBLIC .)

add_executable(arrayfill ${SOURCE_FILES} main.cpp)

target_link_libraries(arrayfill libarrayfill)

