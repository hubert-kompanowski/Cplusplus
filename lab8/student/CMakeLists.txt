
project(student)

set(HEDEAR_FILES Student.h)
set(SOURCE_FILES Student.cpp)

add_library(libstudent STATIC ${SOURCE_FILES})
target_include_directories(libstudent PUBLIC .)

add_executable(student ${SOURCE_FILES} main.cpp)

target_link_libraries(student libstudent)

