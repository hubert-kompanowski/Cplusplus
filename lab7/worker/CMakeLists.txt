
project(worker)

set(HEDEAR_FILES Worker.h)
set(SOURCE_FILES Worker.cpp)

add_library(libworker STATIC ${SOURCE_FILES})
target_include_directories(libworker PUBLIC .)

add_executable(worker ${SOURCE_FILES} main.cpp)

target_link_libraries(worker libworker)

