#include <iostream>
#include <string>
using namespace std;

bool isAlphaNumaric(char c) // AlphaNumaric Character
{
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

bool isPalindrome(string s) // Valid Palindrome
{
    int st = 0, end = s.length() - 1;
    while (st < end)
    {
        if (!isAlphaNumaric(s[st]))
        {
            st++;
            continue;
        }
        if (!isAlphaNumaric(s[end]))
        {
            end--;
            continue;
        }
        if (tolower(s[st]) != tolower(s[end]))
        {
            return false;
        }
        st++, end--;
    }
    return true;
}

string removeOccurrences(string s, string part) // Remove all Occurrences of a Substring in a String 
{
    while (s.length() > 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{

    return 0;
}