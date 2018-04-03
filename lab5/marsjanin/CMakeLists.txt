
project(marsjanie)

set(HEDEAR_FILES Marsjanie.h)
set(SOURCE_FILES Marsjanie.cpp)

add_library(libmarsjanie STATIC ${SOURCE_FILES})
target_include_directories(libmarsjanie PUBLIC .)

add_executable(marsjanie ${SOURCE_FILES} main.cpp)

target_link_libraries(marsjanie libmarsjanie)

