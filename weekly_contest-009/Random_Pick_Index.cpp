#include <iostream>
#include <vector>
#include <random>
#include <hash_map>
#include <map>
using namespace std;

class Solution {
public:
    map<int, vector<int>> hashmap;
    Solution(vector<int>& nums) {
       for (int i=0; i<nums.size(); i++) 
            hashmap[nums[i]].emplace_back(i); 
    }
    
    int pick(int target) {
        int n = hashmap[target].size();
        int ind = rand();
        return hashmap[target][ind % n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */