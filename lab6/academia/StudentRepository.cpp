//
// Created by matematyk60 on 04.04.17.
//

#include "StudentRepository.h"


namespace academia{



    StudentRepository::StudentRepository(std::initializer_list<Student> init) {
        for(auto n : init){
            repo_.emplace_back(n);
        }
    }

    Student& StudentRepository::operator[](const string cmp) {
        for(auto &n : repo_){
            if(n.Id() == cmp){
                return n;
            }
        }
        Student null_student {};
        return null_student;
    }

    unsigned long StudentRepository::StudentCount(void) const{
        return repo_.size();
    }

    const bool StudentRepository::operator==(const StudentRepository &other) const{
        if(this->StudentCount() == other.StudentCount()){
            return true;
        } else{
            return false;
        }
    }

    std::vector<Student> StudentRepository::FindByQuery(const Query &query)const {
        std::vector<Student> answer;
        for(auto n : repo_){
            if(query.Accept(n)){
                answer.emplace_back(n);
            }
        }
        return answer;
    }

}