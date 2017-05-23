
project(scheduler)

set(HEDEAR_FILES Scheduler.h SchedulingItem.h)
set(SOURCE_FILES Scheduler.cpp SchedulingItem.cpp)

add_library(libscheduler STATIC ${SOURCE_FILES})
target_include_directories(libscheduler PUBLIC .)

add_executable(scheduler ${SOURCE_FILES} main.cpp)

target_link_libraries(scheduler libscheduler)
target_link_libraries(libscheduler libalgo)

