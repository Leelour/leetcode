#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
        string ns = "#" + s;
        int i,j;
        vector<vector<int> > idx = vector<vector<int> >((int)ns.length(), vector<int>());
        idx[0].push_back(0);
        for(i = 1; i < (int) ns.length(); ++ i)
        {
            for(j = 0; j < i; ++ j)
            {
                if(!idx[j].empty() && dict.find(ns.substr(j+1, i-j)) != dict.end())
                {
                    idx[i].push_back(j);
                }
            }
        }
        sol.clear();
        gen_sol(idx, ns,  (int)s.length(), "");
        return sol;
    }
private:
    vector<string> sol;
    void gen_sol(vector<vector<int> > idx, string s, int i, string path)
    {
        if(i == 0)
        {
            sol.push_back(path);
        }
        else
        {
            for(int j = (int)idx[i].size() - 1; j >= 0; -- j)
            {
                gen_sol(idx, s, idx[i][j], s.substr(idx[i][j] + 1, i - idx[i][j]) + (path == ""? path : " " + path));
            }
        }
    }
};