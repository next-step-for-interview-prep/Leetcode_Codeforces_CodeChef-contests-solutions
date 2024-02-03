#include <iostream>
#include <vector>
using namespace std;

class solution
{
    public:
    int maxrotatefunction(vector<int>& nums)
    {
        int n = nums.size();
        int sum = 0;
        int f = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            f += i * nums[i];
        }
        int max = f;
        for(int i = 1; i < n; i++)
        {
            f = f + sum - n * nums[n - i];
            if(f > max)
            {
                max = f;
            }
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    solution s;
    cout<<s.maxrotatefunction(nums)<<endl;
    return 0;
}