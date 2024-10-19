#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void reverseString(vector<char> &s) // For char array
{
    int st = 0, end = s.size() - 1;
    while (st < end)
    {
        swap(s[st++], s[end--]);
    }
}

bool ispalindrome(string s) // True for racecar , madam
{
    string temp = s;
    reverse(temp.begin(), temp.end());
    return temp == s;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    // cout << str << endl;

    // reverse(str.begin(), str.end());
    // cout << str << endl;
    string p = (ispalindrome(str))? "Palindrom": "Not Palindrom";

    cout << "The string is " << p << endl;

    return 0;
}