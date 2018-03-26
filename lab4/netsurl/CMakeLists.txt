
project(simpleurl)

set(HEDEAR_FILES SimpleUrl.h)
set(SOURCE_FILES SimpleUrl.cpp)

add_library(libsimpleurl STATIC ${SOURCE_FILES})
target_include_directories(libsimpleurl PUBLIC .)

add_executable(simpleurl ${SOURCE_FILES} main.cpp)

target_link_libraries(simpleurl libsimpleurl)

