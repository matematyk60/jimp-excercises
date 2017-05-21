//
// Created by janek on 16.05.17.
//

#include "Algo.h"


namespace algo{
    set<string> Keys(const map<string, int> &m) {
        set<string> answer;
        transform(m.begin(), m.end(), inserter(answer, answer.end()), [](pair<string, int> tmp){
            return tmp.first;
        });
        return answer;
    }

    vector<int> Values(const map<string, int> &m) {
        vector<int>answer;
        transform(m.begin(), m.end(), back_inserter(answer), [](pair<string, int> tmp){
            return tmp.second;
        });
        return answer;
    }

    map<string, int> DivisableBy(const map<string, int> &m, int divisor) {
        map<string, int> answer;
        copy_if(m.begin(), m.end(), inserter(m, m.end()), [divisor](pair<string, int> tmp){
            return (tmp.second%divisor == 0);
        });
        return answer;
    }

    void SortInPlace(vector<int> *v) {
        sort(v->begin(), v->end());
    }

    vector<int> Sort(const vector<int> &v) {
        vector<int> answer(v.begin(), v.end());
        sort(answer.begin(), answer.end());
        return answer;
    }

    void SortByFirstInPlace(vector<pair<int, int>> *v) {
        sort(v->begin(), v->end());
    }

    void SortBySecondInPlace(vector<pair<int, int>> *v) {

    }

    void SortByThirdInPlace(vector<tuple<int, int, int>> *v) {

    }

    vector<string> MapToString(const vector<double> &v) {
        vector<string> vecMapString;

        transform(v.begin(), v.end(), back_inserter(vecMapString), [](const double v_iterator){
            return std::to_string(v_iterator);
        });

        return vecMapString;
    }

    string Join(const string &joiner, const vector<double> &v) {
        return std::__cxx11::string();
    }

    int Sum(const vector<int> &v) {
        return accumulate(v.begin(), v.end(), 0);
    }

    int Product(const vector<int> &v) {
        return inner_product(v.begin(), v.end(), v.begin(), 0);
    }

    bool Contains(const vector<int> &v, int element) {
        return any_of(v.begin(), v.end(), [element](const int &v_iterator) {
            return (v_iterator == element);
        });
    }

    bool ContainsKey(const map<string, int> &v, const string &key) {
        auto search = v.find(key);
        return (search != v.end());
    }

    bool ContainsValue(const map<string, int> &v, int value) {
        return any_of(v.begin(), v.end(), [value](pair<string, int> tmp) {
            return (tmp.second == value);
        });
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