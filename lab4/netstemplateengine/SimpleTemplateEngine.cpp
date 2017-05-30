//
// Created by jan on 26.03.17.
//

#include "SimpleTemplateEngine.h"



namespace nets{

    View::View(std::string text) {
        text_ = text;
    }

    View::View() {
        text_ = "";
    }

    View::~View(){
    };

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        std::string rendered = text_;

        unsigned long begin;
        bool conflicted = false;
        std::string tmp = "";

        for(unsigned long i = 0 ; i < rendered.length() ; i++){
            if(rendered[i] == '{' && rendered[i+1] == '{' && rendered[i+2] != '{'){
                begin = i;
                i += 2;

                while(rendered[i] != '}' || rendered[i+1] != '}'){
                    tmp += rendered[i];
                    if(rendered[i] == '}' && rendered[i+1] != '}'){
                        conflicted = true;
                        tmp = "";
                        break;
                    }
                    i++;
                }

                if(conflicted){
                    conflicted = false;
                    continue;
                }

                rendered.erase(begin, i - begin +2);

                for(const auto &n : model){
                    if(n.first == tmp){
                        rendered.insert(begin,n.second);
                    }
                }
                i = begin;
                tmp = "";
            }
        }

        return rendered;

    }


}