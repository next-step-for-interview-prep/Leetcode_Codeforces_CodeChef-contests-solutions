// Q3 Suppose we have a file system that stores both files and directories. An example of one system is represented in the following picture. Here, we have dir as the only directory in the root. dir contains two subdirectories, subdir1 and subdir2. subdir1 contains a file file1.ext and subdirectory subsubdir1. subdir2 contains a subdirectory subsubdir2, which contains a file file2.ext. In text form, it looks like this (with ⟶ representing the tab character):

/* dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext */

// If we were to write this representation in code, it will look like this: "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext". Note that the '\n' and '\t' are the new-line and tab characters.

// Every file and directory has a unique absolute path in the file system, which is the order of directories that must be opened to reach the file/directory itself, all concatenated by '/'s. Using the above example, the absolute path to file2.ext is "dir/subdir2/subsubdir2/file2.ext". Each directory name consists of letters, digits, and/or spaces. Each file name is of the form name.extension, where name and extension consist of letters, digits, and/or spaces. Given a string input representing the file system in the explained format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0. Note that the testcases are generated such that the file system is valid and no file or directory name has length 0.

// Method-1 using stack

/* class Solution {
public:
    int lengthLongestPath(string str) {

        int maxi = 0;
        stack<pair<int,int>> st;
        int ind = 0;
        int n = str.size();
        stringstream data(str);
        string temp;
        while(getline(data,temp,'\n')){
            int i = 0;
            while(temp[i]=='\t'){
                i++;
            }
            int num = i;
            while(!st.empty() and st.top().first>=num){
                st.pop();
            }
            int prev = 0;
            if(!st.empty()) prev = st.top().second+1;
            int curr = temp.size()-num;
            auto found = temp.find('.');
            if (found!=std::string::npos){
                maxi = max(maxi,prev+curr);
            }
            st.push({num,prev+curr});
        }
        return maxi;
    }
}; */

// Method-2 using deque (most optimised solution)

/* class Solution {
public:
    int lengthLongestPath(string input) {
        deque<int> dq;
        int len = 0, res = 0, level = 0;
        bool file = false;
        for(char c: input){
            if(c == '\n'){
                dq.push_back(len);
                level = len = file = 0;
            }
            else if(c == '\t') ++level;
            else if(c == '.') ++len, file = true;
            else{
                len++;
                if(file) res = max(res, len + accumulate(dq.begin(), dq.end(), 0) + level);
                while(level < dq.size()){
                    dq.pop_back();
                }
            }
        }
        return res;
    }
}; */

// Method-3 using unordered map

/* class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        string currRow;
        unordered_map<int,int>len;
        int ans=0;
        while(getline(ss,currRow,'\n')){
            int level=0;
            while(currRow[level]=='\t')level++; //jump to current level,root is 0th level
            if(level==0){
                // we are at root;
                len[level]=currRow.size();
            } else{
                len[level]=len[level-1]+1+currRow.size()-level;// length upto last level + '\' + length of string on current level after subtracting all the '\t' of current row .
            }
            //check if you are at a file
            if(currRow.find('.')!= string::npos){
                ans=max(ans, len[level]);
            }
        }
        return ans;
    }
}; */

// Method-4 using vector

/* class Solution {
public:
    int lengthLongestPath(string input) {
        int i = 0; int n = input.size();
        vector<int> ts = {0}; int ans = 0;
        while(i<n) {
            int t = 0;
            while(input[i]=='\t' && i<n) {i++; t++;}
            int l = 0; bool dot = false;
            while(input[i]!='\n' && i<n) {if(input[i]=='.') dot = true; i++; l++;}
            if(i<n && input[i]=='\n') i++;
            if(dot) {
                ans = max(ans,l+(int)accumulate(ts.begin(),ts.begin()+t,0));
            }
            else {
                if(t==0) ts = {l+1};
                else {
                    while(t<ts.size()) {ts.pop_back();}
                    assert(t==ts.size());
                    ts.push_back(l+1);
                }
            }
        }
        return ans;
    }
}; */