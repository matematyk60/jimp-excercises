//
// Created by janek on 26.03.17.
//


#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <ostream>
#include <string>
#include <unordered_map>


namespace nets{

    class View{
    public:

        View();

        std::string Render(const std::unordered_map <std::string, std::string> &model);


    private:
        std::string str;

    };
}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H