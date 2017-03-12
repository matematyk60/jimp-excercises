
project(doublebasepalindrome)

set(HEDEAR_FILES DoubleBasePalindrome.h)
set(SOURCE_FILES DoubleBasePalindrome.cpp)

add_library(libdoublebasepalindrome STATIC ${SOURCE_FILES})
target_include_directories(libdoublebasepalindrome PUBLIC .)

add_executable(doublebasepalindrome ${SOURCE_FILES} main.cpp)

target_link_libraries(doublebasepalindrome libdoublebasepalindrome)

