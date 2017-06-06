//
// Created by janek on 05.06.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H


#include <iostream>
#include <chrono>


namespace profiling {
    template<typename T>
    auto TimeRecorder(T object) {
        typedef std::chrono::high_resolution_clock cl;

        static cl::time_point start = cl::now();

        auto result = object();

        std::chrono::duration<double, std::milli> elapsed = cl::now() - start;

        return std::pair<decltype(result), double>(result, elapsed.count());
    };
}


#endif //JIMP_EXERCISES_TIMERECORDER_H
