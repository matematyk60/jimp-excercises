//
// Created by janek on 16.05.17.
//

#include "Algo.h"


namespace algo{
    set<string> Keys(const map<string, int> &m) {
        return set<string>();
    }

    vector<int> Values(const map<string, int> &m) {
        return vector<int>();
    }

    map<string, int> DivisableBy(const map<string, int> &m, int divisor) {
        return map<string, int>();
    }

    void SortInPlace(vector<int> *v) {

    }

    vector<int> Sort(const vector<int> &v) {
        return vector<int>();
    }

    void SortByFirstInPlace(vector<pair<int, int>> *v) {

    }

    void SortBySecondInPlace(vector<pair<int, int>> *v) {

    }

    void SortByThirdInPlace(vector<tuple<int, int, int>> *v) {

    }

    vector<string> MapToString(const vector<double> &v) {
        vector<string> vecMapString;
        transform(v.begin(), v.end(), back_inserter(vecMapString), [](const double &v_iterator){
            return std::to_string(v_iterator);
        });
        return vecMapString;
    }

    string Join(const string &joiner, const vector<double> &v) {
        return std::__cxx11::string();
    }

    int Sum(const vector<int> &v) {
        return 0;
    }

    int Product(const vector<int> &v) {
        return 0;
    }

    bool Contains(const vector<int> &v, int element) {
        return any_of(v.begin(), v.end(), [element](const int &v_iterator) {
            return (v_iterator == element);
        });
    }

    bool ContainsKey(const map<string, int> &v, const string &key) {
        //return any_of(v.begin(), v.end(), )
    }

    bool ContainsValue(const map<string, int> &v, int value) {
        return false;
    }

    vector<string> RemoveDuplicates(const vector<string> &v) {
        return vector<string>();
    }

    void RemoveDuplicatesInPlace(vector<string> *v) {

    }

    void InitializeWith(int initial_value, vector<int> *v) {
        fill(v->begin(), v->end(), initial_value);
    }

    vector<int> InitializedVectorOfLength(int length, int initial_value) {
        return vector<int> (length, initial_value);
    }

    void CopyInto(const vector<int> &v, int n_elements, vector<int> *out) {
        copy(v.begin(), v.begin() + n_elements, back_inserter(*out));
    }

    int HowManyShortStrings(const vector<string> &v, int inclusive_short_length) {
        return 0;
    }
}