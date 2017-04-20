#include <iostream>

/*
    Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
*/
 
std::string reverseWords(std::string s)
{
    int i, j, strlen;

    strlen = s.length();
    i = 0;

    while (i < strlen) {
        // get to next space
        j = i;
        while (i < strlen && s[i] != ' ')
            i++;
        
        // reverse string up until i
        for (int t = i-1; j < t; j++, t--) {
            char c = s[t];
            s[t] = s[j];
            s[j] = c;
        }
        i++;
    }

    return s;
}

int main()
{
    std::string str;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, str);

    std::string t = reverseWords(str);

    std::cout << t << "\n";
}
