#include "avx2-64bit-qsort.hpp"
#include <array>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono>
using namespace std;

void print(vector<int64_t> &array, string msg) {
    cout << msg << ": {" ;
    for (auto element : array) {
        cout << element << ", ";
    }
    cout << "}" << endl;
}

int main() {

    int64_t pivot = 4;
    vector<int64_t> array1 {4, 2, -13, -9}; //, 3, -4, 7, -8, 9, -10};
    vector<int64_t> array2 {4, -5, 7, -1, 3, -4, 2, -8};
    vector<int64_t> array = array1;
    print(array, "before part");
    int64_t pidx = avx2_partition((int64_t*) array.data(), (int64_t)0, (int64_t) array.size(), pivot);
    print(array, "after part");
    std::cout << "hello sort: pidx = " << pidx << std::endl;
    return 0;
}



/*
using namespace std;
using namespace std::chrono;

void print(vector<int32_t> &array, string msg) {
    cout << msg << ": {" ;
    for (auto element : array) {
        cout << element << ", ";
    }
    cout << "}" << endl;
}

void test32_common(vector<int32_t> &array, int32_t pivot) {
    vector<int32_t> array_copy(array);

    print(array, "before");
    int64_t pidx = partition<zmm_vector<int32_t>, int32_t>(array.data(), (int64_t)0, (int64_t) array.size(), pivot);
    print(array, "after");
    cout << "PIDX = " << pidx << endl;
}


void gen_random(vector<int32_t> &vec, int min, int max) {
    // First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    uniform_int_distribution<int> dist {min, max};

    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };

    generate(begin(vec), end(vec), gen);
}

int test32(int32_t pivot) {
    //vector<int32_t> array1 {1, 9, 9, 10, 4, 22, 9, 33, 44, 10, -8, 14, -2, 99, -5, 6, 12, 10 , 10, 9};
    //vector<int32_t> array1 {1, 9, 10, 9, 10, 10, 11, -1, 10, 11, 19, 13, -2, 10, 5, 10};
    //vector<int32_t> array1 {11, 11, 19, 13, 1, 9, 10, 9, 10, 10, -1, 10, -2, 10, 5, 10, };

    vector<int32_t> array1 {1, 5, 3, 1, 5, 3, 7, 9, 7, 9 };
    test32_common(array1, pivot);
    return 0;
}



int main(int argc, char* argv[]) {

    int32_t pivot = atoi(argv[1]);
    test32(pivot);
    return 0;
}
#include "src/avx512-16bit-qsort.hpp"
#include "src/avx512-32bit-qsort.hpp"
#include "src/avx512-64bit-qsort.hpp"
//#include "hwy/contrib/sort/vqsort.h"
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void print(vector<int32_t> &array, string msg) {
    cout << msg << ": {" ;
    for (auto element : array) {
        cout << element << ", ";
    }
    cout << "}" << endl;
}

void test32_common(vector<int32_t> &array, int32_t pivot) {
    vector<int32_t> array_copy(array);

    print(array, "before");
    int64_t pidx = partition<zmm_vector<int32_t>, int32_t>(array.data(), (int64_t)0, (int64_t) array.size(), pivot);
    print(array, "after");
    cout << "PIDX = " << pidx << endl;
}


void gen_random(vector<int32_t> &vec, int min, int max) {
    // First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    uniform_int_distribution<int> dist {min, max};

    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };

    generate(begin(vec), end(vec), gen);
}

int test32(int32_t pivot) {
    //vector<int32_t> array1 {1, 9, 9, 10, 4, 22, 9, 33, 44, 10, -8, 14, -2, 99, -5, 6, 12, 10 , 10, 9};
    //vector<int32_t> array1 {1, 9, 10, 9, 10, 10, 11, -1, 10, 11, 19, 13, -2, 10, 5, 10};
    //vector<int32_t> array1 {11, 11, 19, 13, 1, 9, 10, 9, 10, 10, -1, 10, -2, 10, 5, 10, };

    vector<int32_t> array1 {1, 5, 3, 1, 5, 3, 7, 9, 7, 9 };
    test32_common(array1, pivot);
    return 0;
}



int main(int argc, char* argv[]) {

    int32_t pivot = atoi(argv[1]);
    test32(pivot);
    return 0;
}

*/