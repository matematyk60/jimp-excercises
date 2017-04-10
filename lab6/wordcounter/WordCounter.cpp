//
// Created by matematyk60 on 10.04.17.
//

#include "WordCounter.h"


namespace datastructures{
    WordCounter::WordCounter() {
        index_.clear();
    }

    WordCounter::WordCounter(std::pair<Word, Counts> new_pair) {
        index_.clear();
        index_.emplace_back(new_pair);
    }




    Counts::Counts() {
        number_ = 0;
    }

    Counts::Counts(int number) {
        number_ = number;
    }

    Word::Word(){
        word_ = "";
    }

    Word::Word(const char *text) {
        word_ = text;
    }

    bool WordCounter::IsAlreadyHere(const char *text) {
        for(auto n : index_){
            if(n.first.Compare(text)){
                return true;
            }
        }
    }

    int WordCounter::TotalWords() {
        int answer = 0;
        for(auto n : index_){
            answer += n.second.GetCounts();
        }
        return answer;
    }

    int WordCounter::DistinctWords() {
        return (int)index_.size();
    }

    int WordCounter::operator[](const char *text) const {
        int answer;
        for(auto n : index_){
            if(n.first.Compare(text)){
                return n.second.GetCounts();
            }
        }
        //else
        return 0;
    }

    bool Word::Compare(const char *text){
        if(word_.empty()){
            return false;
        }
        if(!word_.compare(text)){
            return true;
        } else{
            return false;
        }
    }

    std::set<Word> WordCounter::Words() {
        std::set<Word> answer;
        for(auto n : index_){
            answer.emplace(n.first);
        }
        return
    }

    string Word::GetWord() {
        return word_;
    }

    int Counts::GetCounts(){
        return number_;
    }
}