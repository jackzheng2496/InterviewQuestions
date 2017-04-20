#include <iostream>
#include <vector>
#include <map>

/*
    Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
*/

using namespace std;

char tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (char)(c + 32);
    return c;
}

bool checkLetters(string& word, map<char,int>& rows)
{
    int strlen = word.length();
    int row = rows[tolower(word[0])];
    for (int i = 1; i < strlen; i++) {
        if (rows[tolower(word[i])] != row)
            return false;
    }
    return true;
}
vector<string> findWords(vector<string>& words)
{
    vector<string> valid_words;
    map<char,int> r;

    r['q']=r['w']=r['e']=r['r']=r['t']=r['y']=r['u']=r['i']=r['o']=r['p'] = 0;
    r['a']=r['s']=r['d']=r['f']=r['g']=r['h']=r['j']=r['k']=r['l'] = 1;
    r['z']=r['x']=r['c']=r['v']=r['b']=r['n']=r['m'] = 2;

    for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
        if (checkLetters(*iter, r))
            valid_words.push_back(*iter);
    }
    
    return valid_words;
}

int main()
{
    vector<string> v;

    v.push_back("Hello");
    v.push_back("Alaska");
    v.push_back("Dad");
    v.push_back("Peace");

    vector<string> result = findWords(v);

    cout << "Answer\n";
    for (vector<string>::iterator i = result.begin(); i != result.end(); i++) {
        cout << *i << "\n";
    }
}


