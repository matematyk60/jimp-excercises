//
// Created by matematyk60 on 23.05.17.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

namespace factoryMethod {
    template<class T>
    T Create(void);

    template<class T>
    T Create(void) {
        T answer{};
        return answer;
    }

    template<class T>
    T Sum(const T &a, const T &b) {
        return (a + b);
    }


    class MyType {
    public:
        std::string SayHello(void) const;
    };

    template<class T>
    T Sum(const T &a, const T &b);

    template<class T>
    auto Value(const T pointer);

    template<class T>
    auto Value(const T pointer) {
        return *pointer;
    }

    template<class T>
    class Repository {
    public:
        Repository(std::initializer_list<T> elements) {
            for (auto n : elements) {
                repository_.emplace_back(n);
            }
        }

        size_t Size() const {
            return repository_.size();
        }

        T &operator[](int id) {
            auto answer = std::find_if(repository_.begin(), repository_.end(), [id](T &actual) -> bool {
                return (actual.Id() == id);
            });
            if (answer != repository_.end()) {
                return *answer;
            } else {
                return nullptr;
            }
        }

        int NextId(void) const {
            return (int) repository_.size();
        }

    private:
        std::vector<T> repository_;
    };

    template <class T>
    T Mean(std::vector<T> a){
        T sum1 = std::accumulate(a.begin(), a.end(), T{});
        return sum1/a.size();
    };


}










#endif //JIMP_EXERCISES_FACTORYMETHOD_H
