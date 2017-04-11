//
// Created by matematyk60 on 10.04.17.
//

#include "WordCounter.h"

#include <iostream>
#include <algorithm>
#include <list>

using std::cout;


namespace datastructures {
    WordCounter::WordCounter() {
        index_.clear();
    }

    WordCounter::~WordCounter() {
        index_.clear();
    }

    WordCounter::WordCounter(std::initializer_list<Word> elements){
        std::pair<Word,Counts> tmp;
        for(auto n : elements){
            if(this->IsAlreadyHere(n)){
                ;
            } else{
                tmp.first = n;
                tmp.second = Counts{1};
                index_.emplace_back(tmp);
            }
        }
        this->Sort();
    }



    bool WordCounter::IsAlreadyHere(const Word &text){

        for(int i = 0 ; i < index_.size() ; i++){
            if(index_[i].first == text){
                index_[i].second++;
                return true;
            }
        }
        //else
        return false;
    }

    void WordCounter::Sort() {
        struct {
            bool operator()(std::pair<Word,Counts> first, std::pair<Word,Counts> second){
                return(first.second > second.second);
            }
        } Compare;
        std::sort(index_.begin(), index_.end(), Compare);
    }


    int WordCounter::TotalWords() const{
        int answer = 0;
        for(auto n : index_){
            answer += n.second.GetCounts();
        }
        return answer;
    }

    int WordCounter::DistinctWords() const{
        return (int)index_.size();
    }

    Counts WordCounter::operator[](const char *text) const {
        for(auto n : index_){
            if(n.first == (text)){
                return n.second;
            }
        }
        //else
        return Counts{0};
    }

    std::ostream& operator<<(std::ostream& output,const WordCounter &wc){
        for(auto n : wc.index_){
            output << "Word: ";
            output << n.first.GetWord();
            output << " Appearances: ";
            output << n.second.GetCounts();
            output << std::endl;
        }
        return output;
    }



    std::set<Word> WordCounter::Words() const{
        std::set<Word> answer;
        for(auto n : index_){
            answer.emplace(n.first);
        }
        return answer;
    }







}