// Question-1 Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order. You must write an algorithm that runs in O(n) time and uses O(1) extra space.

// Method-1 using recursion

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> arr();

    void next(int i, int n)
    {
        if (i >= n)
        {
            return;
        }
        arr.push_back(i);
        next(i * 10, n);
        if ((i + 1) % 10 != 0)
        {
            next(i + 1, n);
        }
    }

    vector<int> lexicographical_order(int n)
    {
        next(1, n);
        return arr;
    }
};

int main(int argc, char const *argv[])
{
    Solution* s = new vector<int>();
    for (int i = 0; i < s->arr.size(); i++)
    {
        cout << s->arr[i] << " ";
    }
    return 0;
}
