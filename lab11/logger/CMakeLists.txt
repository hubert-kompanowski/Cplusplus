
project(logger)

set(HEDEAR_FILES Logger.h)
set(SOURCE_FILES Logger.cpp)

add_library(liblogger STATIC ${SOURCE_FILES})
target_include_directories(liblogger PUBLIC .)

add_executable(logger ${SOURCE_FILES} main.cpp)

target_link_libraries(logger liblogger)

