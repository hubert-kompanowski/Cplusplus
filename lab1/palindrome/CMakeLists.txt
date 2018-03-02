project(palindrome)

set(HEDEAR_FILES Palindrome.h)
set(SOURCE_FILES Palindrome.cpp)

add_library(libpalindrome STATIC ${SOURCE_FILES} Palindrome.cpp Palindrome.h main.cpp)
target_include_directories(libpalindrome PUBLIC .)

add_executable(palindrome ${SOURCE_FILES} main.cpp)

target_link_libraries(palindrome libpalindrome)
