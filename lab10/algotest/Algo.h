//
// Created by janek on 16.05.17.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H


#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using ::std::set;
using ::std::string;
using ::std::map;
using ::std::vector;
using ::std::pair;
using ::std::tuple;

namespace algo {
    set<string> Keys(const map<string, int> &m);

    vector<int> Values(const map<string, int> &m);

    map<string, int> DivisableBy(const map<string, int> &m, int divisor);

    void SortInPlace(vector<int> *v);

    vector<int> Sort(const vector<int> &v);

    void SortByFirstInPlace(vector<pair<int, int>> *v);

    void SortBySecondInPlace(vector<pair<int, int>> *v);

    void SortByThirdInPlace(vector<tuple<int, int, int>> *v);

    vector<string> MapToString(const vector<double> &v);

    string Join(const string &joiner, const vector<double> &v);

    int Sum(const vector<int> &v);

    int Product(const vector<int> &v);

    bool Contains(const vector<int> &v, int element);

    bool ContainsKey(const map<string, int> &v, const string &key);

    bool ContainsValue(const map<string, int> &v, int value);

    vector<string> RemoveDuplicates(const vector<string> &v);

    void RemoveDuplicatesInPlace(vector<string> *v);

    void InitializeWith(int initial_value, vector<int> *v);

    vector<int> InitializedVectorOfLength(int length, int initial_value);

    int FindYear(std::map<int,set<int>> years, int course_id);

    void CopyInto(const vector<int> &v, int n_elements, vector<int> *out);

    int HowManyShortStrings(const vector<string> &v, int inclusive_short_length);
}


#endif //JIMP_EXERCISES_ALGO_H
