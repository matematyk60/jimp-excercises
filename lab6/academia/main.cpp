//
// Created by matematyk60 on 04.04.17.
//

#include "StudentRepository.h"

using namespace academia;

using namespace std;

int main() {
    StudentRepository repo{{"23123", "bysui", "end", "matma", 2}, {"231", "ewqe", "weqe", "ewqe", 3}, {"2321", "ewqe", "weqe", "ewqe", 3}, {"3231", "ewqe", "weqe", "ewqe", 3}};
    repo["23123"].ChangeFirstName("malpa");
    cout << repo.StudentCount();
}