#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;

    vec.push_back(25);
    vec.push_back(35);
    vec.push_back(45);

    cout << "After Push Back Size = " << vec.size() << endl;

    vec.pop_back(); // Deleting the last value

    // For-Each Loop
    for (int vel : vec)
    {
        cout << vel << endl;
    }
    return 0;
}