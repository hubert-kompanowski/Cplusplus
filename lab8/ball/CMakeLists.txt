
project(ball)

set(HEDEAR_FILES Ball.h)
set(SOURCE_FILES Ball.cpp)

add_library(libball STATIC ${SOURCE_FILES})
target_include_directories(libball PUBLIC .)

add_executable(ball ${SOURCE_FILES} main.cpp)

target_link_libraries(ball libball)

