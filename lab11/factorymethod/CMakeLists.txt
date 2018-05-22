
project(factorymethod)

set(HEDEAR_FILES FactoryMethod.h)
set(SOURCE_FILES FactoryMethod.cpp)

add_library(libfactorymethod STATIC ${SOURCE_FILES})
target_include_directories(libfactorymethod PUBLIC .)

add_executable(factorymethod ${SOURCE_FILES} main.cpp)

target_link_libraries(factorymethod libfactorymethod)
