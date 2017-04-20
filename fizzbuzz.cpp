#include <iostream>
#include <vector>

/*
    Write a program that outputs the string representation of numbers from 1 to n.

    But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
*/

using namespace std;

vector<string> fizzBuzz(int n)
{
    // If you know how large the vector will be, declare it with an initial size
    // This will help remove the overhead of the vector growing
    vector<string> result(n);

    for (int i = 1; i <= n; i++) {
        string str = "";

        if (i % 3 == 0) str += "Fizz";
        if (i % 5 == 0) str += "Buzz";
        if (str.compare("") == 0) str = to_string(i);

        result[i-1] = str;
    }
    return result;
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Answer for n = " << n << "\n";

    vector<string> res = fizzBuzz(n);

    for (vector<string>::iterator i = res.begin(); i != res.end(); i++) {
        cout << *i << "\n";
    }
}
