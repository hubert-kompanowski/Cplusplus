
project(ccounter)

set(HEDEAR_FILES CCounter.h)
set(SOURCE_FILES CCounter.cpp)

add_library(libccounter STATIC ${SOURCE_FILES})
target_include_directories(libccounter PUBLIC .)

add_executable(ccounter ${SOURCE_FILES} main.cpp)

target_link_libraries(ccounter libccounter)

