#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int digit = -1;
        int visited[s.size()];
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j < s.size(); j++)
            {
                if(s[i]==s[j] && i!=j)
                {
                    visited[i]++;
                }
            }
        }
        for(int i = 0; i<s.size()-1; i++)
        {
            if(visited[i]==1)
            {
                digit = i;
            }
        }
        return digit;
    }
};