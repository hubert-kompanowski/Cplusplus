
project(numbers)

set(SOURCE_FILES main.cpp)

add_library(libnumbers STATIC ${SOURCE_FILES})
target_include_directories(libnumbers PUBLIC .)

add_executable(numbers ${SOURCE_FILES} main.cpp)

target_link_libraries(numbers libnumbers)

