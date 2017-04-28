#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

// using anonymous functions to make map
// can prob extend this to class T functions
// and arbitrary data structures
void map(function<void(int&)> f, vector<int>& vec) {
    for_each(begin(vec), end(vec), f);
}

int main() {
    auto i = "jack zheng";
    int x = 10;
    auto addNumbers = [=](int a, int b) -> int {
        return a + b + x;
    };

    vector<int> arr = {1,2,3,4,5};
    
    for (vector<int>::iterator i = arr.begin(); i != arr.end(); i++) {
        cout << *i << "\n";
    }

    int sum = 0;

    // lambdas are useful when you're using a function for one time
    // and do not want to create an actual definition somewhere
    for_each(begin(arr), end(arr), [&](int x) { sum += x; });
   
    auto addOne = [&](int& a) {
        a++;
    };

    map(addOne, arr);

    cout << sum << "\n";

    for (auto i = arr.begin(); i != arr.end(); i++) {
        cout << *i << "\n";
    }
}
