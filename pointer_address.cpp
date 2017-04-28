#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printString(string& str) {
    cout << str << "\n";

    string s1("new string");

    str = s1; // Changing the value of a reference changes the value of what it is referencing
}

void printPtr(string* str) {
    cout << *str << "\n";

    string s1("new string2");
    str = &s1;

}

int main() {
    string s1("jack zheng");
    string* ptr = &s1;
    string& rs = s1;

    printPtr(ptr);
    printPtr(ptr);

    //printString(rs);

    //printString(rs);

    //cout << s1 << "\n";
    //s1 = "zheng jack";

    //printString(rs);
}
