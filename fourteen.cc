#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Base condition for product function
// (the product of no numbers?)
// Reminds me of functional programming
auto product() { return 1; }

// Generic function to add two or more variables 
// (not necessarily of the same type)
template<typename H, typename... T>
auto product(H h, T... t) {
    return h*product(t...);
}

// Generic function to add two variables
template<typename T, typename U>
auto add(T t, U u) {
    return t+u;
}

int main() {

    int x{4};
    string s{"food"};
    vector<int> values{1,2,3,4};

    for (auto i = values.begin(); i != values.end(); i++) {
        cout << *i << "\n";
    }

    cout << s << "\n";

    cout << add(1,2.3) << "\n";
    cout << add(1,2) << "\n";

    cout << add(string{"hello"}, "world") << "\n";

    cout << "using foreach loop thing\n";
    for (int& a : values) {
        a += 2;
    }
    
    int sum = 0;

    for_each(values.begin(), values.end(), [&](int i) {
            cout << i << "\n";
            sum += i;
    });

    cout << sum << "\n";

    cout << "product: " << product(1,2,3,4,5) << "\n";
}
