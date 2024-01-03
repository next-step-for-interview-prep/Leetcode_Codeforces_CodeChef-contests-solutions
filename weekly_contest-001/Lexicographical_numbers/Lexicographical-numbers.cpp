// Question-1 Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order. You must write an algorithm that runs in O(n) time and uses O(1) extra space.

// Method-1 using recursion

/* #include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> arr;

    void next(int i, int n)
    {
        if (i > n)
        {
            return;
        }
        arr.push_back(i);
        next(i * 10, n);
        if ((i + 1) % 10 != 0 && (i + 1) <= n)
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

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> result = s.lexicographical_order(n);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
} */

// Method-2 using for loop and function for all values from 1 to n

/* #include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int next(int num, int n) {
        if (num * 10 <= n) {
            return num * 10;
        }

        if (num == n) {
            num /= 10;
        }

        while (num % 10 == 9 || num == n) {
            num /= 10;
        }

        return num + 1;
    }

    vector<int> lexicalOrder(int n) {
        if (n < 1) {
            return {};
        }
        vector<int> res(n);
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            res[i] = next(res[i - 1], n);
        }
        return res;
    }
};

int main() {
    Solution s;
    int n;
    cin>>n;
    vector<int> result = s.lexicalOrder(n);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
} */

// Method-3 using trie data structure

/* struct Node{
    Node* links[10];
    bool flag = false;
};

class Trie{
public:
    Node* head;
    Trie(){
        head = new Node();
    }

    void insert(string s){
        Node* node = head;
        for(auto ch : s){
            if(node->links[ch - '0'] == NULL){
                node->links[ch - '0'] = new Node();
            }
            node = node->links[ch - '0'];
        }
        node->flag = 1;
    }
    
};

class Solution {
public:
    vector<int>ans;
    void dfs(Node* node, string &curr){
        if(node->flag == 1){
            ans.push_back(stoi(curr));
        }
        for(int i=0; i<10; i++){
            if(node->links[i]){
                curr += (i + '0');
                dfs(node->links[i],curr);
                curr.pop_back();
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        Trie t;
        for(int i=1; i<=n; i++){
            t.insert(to_string(i));
        }
        string curr = "";
        dfs(t.head,curr);
        return ans;
    }
}; */

// Method-4 using only one while loop in the main function

/* class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> ans;
    int curr = 1;

    while (ans.size() < n) {
      ans.push_back(curr);
      if (curr * 10 <= n) {
        curr *= 10;
      } else {
        while (curr % 10 == 9 || curr == n)
          curr /= 10;
        ++curr;
      }
    }

    return ans;
  }
}; */

// Method-5 using set

/* class Solution {
public:
    vector<int> lexicalOrder(int n) {
        set<string> stt;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            stt.insert(to_string(i));
        }

        for(auto it=stt.begin();it!=stt.end();it++){
            ans.push_back(stoi(*it));
        }
        return ans;
    }
}; */

// Method-6 using bit manipulation

/* class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int curr=1;
        // int i=1;
        for(int i=0; i<n; i++){
            ans[i] = curr;
            if(((curr << 3) + (curr << 1))<=n){
                curr = (curr << 3) + (curr << 1);
            }
            else{
                if(curr>= n){
                    curr /=10;
                }
                curr +=1;
                while(curr%10 == 0){
                    curr/=10;
                }
            }
        }
        return ans;
    }
}; */

// Method-7 using sorting

/* class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> v;
        for(int i=1;i<=n;i++){
            string str = to_string(i);
            v.push_back(str);
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            ans.push_back(stoi(v[i]));
        }
        return ans;
    }
}; */