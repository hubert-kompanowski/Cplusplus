
project(studentrepositoryqueries)

set(HEDEAR_FILES StudentRepositoryQueries.h)
set(SOURCE_FILES StudentRepositoryQueries.cpp)

add_library(libstudentrepositoryqueries STATIC ${SOURCE_FILES})
target_include_directories(libstudentrepositoryqueries PUBLIC .)

add_executable(studentrepositoryqueries ${SOURCE_FILES} main.cpp)

target_link_libraries(libstudentrepositoryqueries libstudentrepository)
target_link_libraries(studentrepositoryqueries libstudentrepositoryqueries)

