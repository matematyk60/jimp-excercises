//
// Created by janek on 16.05.17.
//

#include "Algo.h"


namespace algo{
    void CopyInto(const vector<int> &v, int n_elements, vector<int> *out) {
        copy(v.begin(), v.begin() + n_elements, back_inserter(*out));
    }

    bool Contains(const vector<int> &v, int element) {
        return any_of(v.begin(), v.end(), [element](const int &v_iterator){ return v_iterator;} );
    }
}