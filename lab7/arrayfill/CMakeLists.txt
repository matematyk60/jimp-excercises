
project(arrayfill)

set(HEDEAR_FILES ArrayFill.h)
set(SOURCE_FILES ArrayFill.cpp)

add_library(libarrayfill STATIC ${SOURCE_FILES})
target_include_directories(libarrayfill PUBLIC .)

add_executable(arrayfill ${SOURCE_FILES} main.cpp ../point3D/Point3D.cpp ../point3D/Point3D.h ../point3D/main.cpp ../punkt3d/Punkt3d.cpp ../punkt3d/Punkt3d.h ../punkt3d/main.cpp ../roundly/Kolo.cpp ../roundly/Kolo.h ../roundly/Kula.cpp ../roundly/Kula.h ../roundly/main.cpp ../comparable/Comparable.cpp ../comparable/Comparable.h ../comparable/main.cpp ../academiaqueries/StudentRepositoryQueries.cpp ../academiaqueries/StudentRepositoryQueries.h)

target_link_libraries(arrayfill libarrayfill)

