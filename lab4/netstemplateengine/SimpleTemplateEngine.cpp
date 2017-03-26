//
// Created by janek on 26.03.17.
//


#include "SimpleTemplateEngine.h"
#include <ostream>
#include <string>
#include <unordered_map>


namespace nets {
    
    View::View() {}
    
    std::string View::Render(const std::unordered_map<std::string, std::string> &model) {
        std::string tmp = "";
        unsigned long k;
        bool first = true;
        for (const auto &n : model) {
            if (first) {
                str = n.first;
                first = false;
            } else
                break;
        }
        first = true;
        for (unsigned long i = 0; i < str.length(); i++) {
            if (str[i] == '{' && str[i + 1]) {
                i += 2;
                k = i;
                for (i; str[i] != '}'; i++) {
                    for (int j = 0; j < i; j++) {
                        tmp[j] = str[i];
                    }
                }
                str.erase(k, (i - k));
                for (const auto &n : model) {
                    if (first) {
                        first = false;
                        continue;
                    } else if (tmp == n.first) {
                        str.insert(k, n.second);
                    }
                }
            }
        }
        return str;
    }
}