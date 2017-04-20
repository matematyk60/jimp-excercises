//
// Created by matematyk60 on 20.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
#define JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H


#include <Student.h>
#include <vector>
#include <memory>

using std::unique_ptr;

namespace academia{
    class Query{
    public:
        virtual bool Accept(const Student &student) const = 0;
        virtual ~Query() {};
    };

    class ByFirstName : public Query{
    public:
        ByFirstName(string name = "");
        bool Accept(const Student &student) const override;

    private:
        string name_;
    };

    class ByLastName : public Query{
    public:

        ByLastName(string name = "");
        bool Accept(const Student &student) const override;
    private:
        string name_;
    };

    class ByOneOfPrograms : public Query{
    public:

        ByOneOfPrograms(std::initializer_list<string> elements);
        bool Accept(const Student &student) const override;
    private:
        std::vector<string> programs_;
    };

    class ByYearLowerOrEqualTo : public Query {
    public:

        ByYearLowerOrEqualTo(StudyYear year);
        bool Accept(const Student &student) const override;
    private:
        StudyYear year_;
    };

    class OrQuery : public Query {
    public:

        OrQuery(unique_ptr<Query> q1, unique_ptr<Query> q2);

        bool Accept(const Student &student) const override;
    private:
        unique_ptr<Query> q1_;
        unique_ptr<Query> q2_;
    };

    class AndQuery : public Query {
    public:
        AndQuery(unique_ptr<Query> q1, unique_ptr<Query> q2);

        bool Accept(const Student &student) const override;
    private:
        unique_ptr<Query> q1_;
        unique_ptr<Query> q2_;
    };


}


#endif //JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
