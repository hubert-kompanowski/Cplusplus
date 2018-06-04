
project(repo)

set(HEDEAR_FILES Repo.h)
set(SOURCE_FILES Repo.cpp)

add_library(librepo STATIC ${SOURCE_FILES})
target_include_directories(librepo PUBLIC .)

add_executable(repo ${SOURCE_FILES} main.cpp)

target_link_libraries(repo librepo)

