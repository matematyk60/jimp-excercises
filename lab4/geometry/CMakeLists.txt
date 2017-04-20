project(square)

set(HEDEAR_FILES Square.h Point.h ../../lab7/point3d/Point3D.h)
set(SOURCE_FILES Square.cpp Point.cpp ../../lab7/point3d/Point3D.cpp)

add_library(libsquare STATIC ${SOURCE_FILES})
target_include_directories(libsquare PUBLIC .)

add_executable(square ${SOURCE_FILES} main.cpp)

target_link_libraries(square libsquare)

