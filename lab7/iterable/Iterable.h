//
// Created by matematyk60 on 22.04.17.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <string>
#include <vector>
#include <memory>

namespace utility{
    class IterableIterator{
    public:
        virtual std::pair<int, std::string> Dereference() const = 0;
        virtual IterableIterator& Next() = 0;
        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const = 0;
        virtual ~IterableIterator(){};
    };

    class Iterable{
    public:
        virtual std::vector<std::pair<int,std::string>>::iterator Begin() = 0;
        virtual std::vector<std::pair<int,std::string>>::iterator End() = 0;
        virtual std::vector<std::pair<int,std::string>>::iterator begin() = 0;
        virtual std::vector<std::pair<int,std::string>>::iterator end() = 0;
        virtual ~Iterable(){};
    };

    class ZipperIterator : public IterableIterator{
    public:
        ZipperIterator(std::vector<int>::iterator int_it, std::vector<std::string>::iterator string_it,
                       std::vector<int>::iterator int_itend, std::vector<std::string>::iterator string_itend);

        IterableIterator &Next() override;

        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;

        std::pair<int, std::string> Dereference() const override;
    private:
        std::vector<int>::iterator int_it_;
        std::vector<std::string>::iterator string_it_;
        std::vector<int>::iterator int_itend_;
        std::vector<std::string>::iterator string_itend_;

    };
}


#endif //JIMP_EXERCISES_ITERABLE_H
