
project(serialization)

set(HEDEAR_FILES Serialization.h)
set(SOURCE_FILES Serialization.cpp)

add_library(libserialization STATIC ${SOURCE_FILES})
target_include_directories(libserialization PUBLIC .)

add_executable(serialization ${SOURCE_FILES} main.cpp)

target_link_libraries(serialization libserialization)

