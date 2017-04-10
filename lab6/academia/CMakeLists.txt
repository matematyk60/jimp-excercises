
project(student)

set(HEDEAR_FILES StudentRepository.h)
set(SOURCE_FILES StudentRepository.cpp)

add_library(libstudentrepository STATIC ${SOURCE_FILES} ../wordcounter/WordCounter.cpp ../wordcounter/WordCounter.h ../wordcounter/main.cpp)
target_include_directories(libstudentrepository PUBLIC .)

add_executable(student ${SOURCE_FILES} main.cpp)

target_link_libraries(student libstudentrepository)

