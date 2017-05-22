//
// Created by janek on 19.03.17.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <utility>
#include <string>
#include <array>
#include <memory>
#include <string>

namespace tinyurl{
    using ::std::string;
    using ::std::array;

    struct TinyUrlCodec{
        array<char, 6> state;
        array<string, 500> url;
        int counter;
    };

    std::unique_ptr<TinyUrlCodec> Init();

    void NextHash(std::array<char, 6> *state);

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);

}


#endif //JIMP_EXERCISES_TINYURL_H
