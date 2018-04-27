
project(iterable)

set(HEDEAR_FILES Iterable.h)
set(SOURCE_FILES Iterable.cpp)

add_library(libiterable STATIC ${SOURCE_FILES})
target_include_directories(libiterable PUBLIC .)

add_executable(iterable ${SOURCE_FILES} main.cpp)

target_link_libraries(iterable libiterable)

