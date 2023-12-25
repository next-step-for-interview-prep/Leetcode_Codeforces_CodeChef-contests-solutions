#include <iostream>
using namespace std;

class Solution {
public:
    long long solve(long long n)
    {  
        if(n==1)return 0;
        if(n%2==1)
        {
            return 1+min(solve(n-1),solve(n+1));
        }
        else
        return 1+solve(n/2);
    }
    int integerReplacement(int n) {
       return solve(n);
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.integerReplacement(n)<<endl;
    return 0;
}
