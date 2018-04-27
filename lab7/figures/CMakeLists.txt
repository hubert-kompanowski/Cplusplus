
project(kolo)

set(HEDEAR_FILES Kolo.h Kula.h)
set(SOURCE_FILES Kolo.cpp Kula.cpp)

add_library(libkolo STATIC ${SOURCE_FILES})
target_include_directories(libkolo PUBLIC .)

add_executable(kolo ${SOURCE_FILES} main.cpp)

target_link_libraries(kolo libkolo)

