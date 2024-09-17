#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> vec;// size = 0
    // vector<int> vec = {1, 2, 3}; // size = 3
    // cout << vec[0] << endl;
    vector<int> vec(5, 0); // size = 5
    // For-Each Loop
    for (int i : vec)
    {
        cout << i << endl;
    }

    //For charecter
    vector<char> vec = {'a', 'b', 'c', 'd', 'e'};
    // For-Each Loop
    for (char vel : vec)
    {
        cout << vel << endl;
    }
    return 0;
}