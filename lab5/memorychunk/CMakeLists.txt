
project(memorychunk)

set(HEDEAR_FILES MemoryChunk.h)
set(SOURCE_FILES MemoryChunk.cpp)

add_library(libmemorychunk STATIC ${SOURCE_FILES})
target_include_directories(libmemorychunk PUBLIC .)

add_executable(memorychunk ${SOURCE_FILES} main.cpp)

target_link_libraries(memorychunk libmemorychunk)

