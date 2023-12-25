#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
   void dfs(string node,string &dest, unordered_map<string,vector<pair<string,double>>> &mp,double &val,double &res,unordered_set<string> &vis)
   {
       if(vis.find(node)!=vis.end()) return ;
       vis.insert(node);
       if(node==dest) 
       {
           res=val;
           return ;
       }
       


        for(auto it : mp[node])
        {
            if(vis.find(it.first)==vis.end())
            {
                double val1=val;
                val=val*it.second;
                dfs(it.first,dest,mp,val,res,vis);
                val=val1;
            }
            
        }
   }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string,vector<pair<string,double>>> mp;
        for(int i=0;i<equations.size();i++)
        {
            string node=equations[i][0];
            string dest=equations[i][1];
            double val=values[i];
            mp[node].push_back({dest,val});
            mp[dest].push_back({node,(1.0/(1.0*val))});
        }
        for(int i=0;i<queries.size();i++)
        {
           
            string node=queries[i][0];
            string dest=queries[i][1];
            
            if(mp.find(node)==mp.end() or mp.find(dest)==mp.end())
            {
                ans.push_back(-1);
            }
            else
            {
                 unordered_set<string> vis;
                 double val=1.0,res=-1;
                 dfs(node,dest,mp,val,res,vis); 
                 ans.push_back(res);
            }
          
        }
        return ans;

    }
};