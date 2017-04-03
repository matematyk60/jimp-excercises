
project(classs)

set(HEDEAR_FILES XXX.h)
set(SOURCE_FILES XXX.cpp)

add_library(libclasss STATIC ${SOURCE_FILES})
target_include_directories(libclasss PUBLIC .)

add_executable(classs ${SOURCE_FILES} main.cpp)

target_link_libraries(classs libclasss)

