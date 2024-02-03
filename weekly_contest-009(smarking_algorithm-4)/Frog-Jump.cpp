#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canCross(std::vector<int>& stones) {
        int n = stones.size();

        std::unordered_map<int, std::unordered_set<int>> dp;
        for (int stone : stones) {
            dp[stone] = std::unordered_set<int>();
        }
        dp[0].insert(0);

        for (int i = 0; i < n; i++) {
            for (int k : dp[stones[i]]) {
                for (int step = k - 1; step <= k + 1; step++) {
                    if (step != 0 && dp.count(stones[i] + step)) {
                        dp[stones[i] + step].insert(step);
                    }
                }
            }
        }
        
        return !dp[stones.back()].empty();
    }
};