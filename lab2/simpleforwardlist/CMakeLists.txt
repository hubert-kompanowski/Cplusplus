
project(simpleforwardlist)

set(HEDEAR_FILES SimpleForwardList.h)
set(SOURCE_FILES SimpleForwardList.cpp)

add_library(libsimpleforwardlist STATIC ${SOURCE_FILES})
target_include_directories(libsimpleforwardlist PUBLIC .)

add_executable(simpleforwardlist ${SOURCE_FILES} main.cpp)

target_link_libraries(simpleforwardlist libsimpleforwardlist)

