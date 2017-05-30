//
// Created by janek on 23.05.17.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <vector>
#include <algorithm>

namespace factoryMethod {
    //template<class T>
    //T Create(void);

    template<class T>
    T Create(void) {
        T answer{};
        return answer;
    }

    template<class T>
    T Sum(const T &a, const T &b) {
        return (a + b);
    }

    template<class T>
    auto Value(const T pointer) {
        return *pointer;
    }


    template<class T>
    class Repository {
    public:
        Repository(std::initializer_list<int> in) {
            for (auto &n : in) {
                repository_.emplace_back(n);
            }
        }

        size_t Size(void) const {
            return repository_.size();
        }

        T operator[](int id) {
            auto found = find_if(repository_.begin(), repository_.end(), [id]()->bool{
            });

        }

    private:
        std::vector<int> repository_;

    };

    class MyType {
    public:
        std::string SayHello(void) const;
    };
}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
