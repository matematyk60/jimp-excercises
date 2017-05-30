
project(square)

set(HEDEAR_FILES Square.h Point.h)
set(SOURCE_FILES Square.cpp Point.cpp)

add_library(libsquare STATIC ${SOURCE_FILES} ../netstemplateengine/SimpleTemplateEngine.cpp ../netstemplateengine/SimpleTemplateEngine.h ../netstemplateengine/main.cpp)
target_include_directories(libsquare PUBLIC .)

add_executable(square ${SOURCE_FILES} main.cpp)

target_link_libraries(square libsquare)

