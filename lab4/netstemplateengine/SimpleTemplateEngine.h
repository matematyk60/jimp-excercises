//
// Created by matematyk60 on 26.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <unordered_map>
#include <string>

namespace nets{

    class View {

    public:
        View(std::string);
        View();
        ~View();
        std::string Render(const std::unordered_map <std::string, std::string> &model) const;

    private:
        std::string text_;

    };
}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
