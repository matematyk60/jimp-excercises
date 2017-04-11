#include <vector>
#include "ArrayFill.h"
#include <cstddef>

using namespace arrays;

using ::std::size_t;

int main(){
    std::vector<int> vs;
    FillArray(1024, UniformFill {77}, &vs);
}