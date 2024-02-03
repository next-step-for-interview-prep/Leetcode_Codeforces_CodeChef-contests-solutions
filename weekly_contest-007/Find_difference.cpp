// Q1 You are given two strings s and t. String t is generated by random shuffling string s and then add one more letter at a random position. Return the letter that was added to t.

/* class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>map;
        for(auto x:s)
        map[x]++;
        for(auto x:t){
            if(map.find(x)==map.end())
            return x;
            if(map[x]>1)
            map[x]--;
            else
            map.erase(x);
        }
        return '1';
    }
}; */