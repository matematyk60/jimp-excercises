//
// Created by janek on 26.03.17.
//


#include "SimpleTemplateEngine.h"
#include <ostream>
#include <string>
#include <unordered_map>
#include <iostream>

using ::std::cout;
using ::std::ostream;
using ::std::endl;


namespace nets {

    View::View(std::string ToChange) {
        str = ToChange;
    }


    View::~View() {

    }

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        std::string changed = str;
        std::string tmp = "";
        unsigned long k;
        bool tf=true;

        for (unsigned long i = 0; i < changed.length(); i++) {
            if (changed[i] == '{' && changed[i + 1] == '{' && changed[i+2] != '{') {
                k = i;
                i += 2;

                for (i; changed[i] != '}'; i++) {
                    tmp += changed[i];
                    if(changed[i+1] == '}' && changed[i+2] != '}') {
                        tmp = "";
                        i = k;
                        tf=false;
                        break;
                    }
                }

                if(tf){
                    changed.erase(k, (i - k + 2));
                    i = 0;
                }
                tf=true;

                for (const auto &n : model) {
                    if (tmp == n.first) {
                        tmp = "";
                        changed.insert(k, n.second);
                        i = k+4;
                    }
                }
                tmp = "";
            }
        }
        return changed;
    }
}