
project(parent)

set(HEDEAR_FILES Parent.h Child.h)
set(SOURCE_FILES Parent.cpp Child.cpp)

add_library(libparent STATIC ${SOURCE_FILES})
target_include_directories(libparent PUBLIC .)

add_executable(parent ${SOURCE_FILES} main.cpp)

target_link_libraries(parent libparent)

