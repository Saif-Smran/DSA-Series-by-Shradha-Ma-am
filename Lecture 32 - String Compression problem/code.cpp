#include <iostream>
#include <vector>
#include <string>
using namespace std;

// String Compression
int compress(vector<char> &chars) // Time: O(n), Space: O(1)
{
    int n = chars.size();
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = chars[i];
        int count = 0;
        while (i < n && chars[i] == ch)
        {
            count++;
            i++;
        }
        if (count == 1)
            chars[idx++] = ch;
        else
        {
            chars[idx++] = ch;
            string str = to_string(count);
            for (char dig : str)
            {
                chars[idx++] = dig;
            }
        }
        i--;
    }
    chars.resize(idx);
    return idx;
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout <<"Compressed size : "<< compress(chars) << endl;
    for (char ch : chars)
        cout << ch << " ";
    return 0;
}