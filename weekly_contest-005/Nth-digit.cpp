#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {
        int first = 1;
        int start = 9;
        while (n - first * (long)start > 0)
        {
            n -= first * start;
            start *= 10;
            first++;
        }
        int num = pow(10, first - 1) + (start - 1) / first;
        cout << num;
        return to_string(num)[first - 1] - '0';
    }
};