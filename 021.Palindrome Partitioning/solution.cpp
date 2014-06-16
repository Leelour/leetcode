//simple dfs, but use dynamic programming in creating isPalindrome rainbow table
class Solution {
    void dfs(const string& s, int start, vector<vector<bool> > &isPalindrome, vector<string> &path, vector<vector<string> > &ret)
    {
        if(start == s.length())
        {
            ret.push_back(path);
        }
        else
        {
            for(int i = start; i <= s.length(); ++ i)
            {
                if(isPalindrome[start][i])
                {
                    path.push_back(s.substr(start, i - start + 1));
                    dfs(s, i + 1, isPalindrome, path, ret);
                    path.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int len = (int) s.length();
        vector<vector<bool> > isPalindrome(len, vector<bool>(len, true));
        for(int j = 1; j < len; ++ j)
        {
            for(int i = 0; i < j; ++ i)
            {
                isPalindrome[i][j] = isPalindrome[i+1][j-1] && s[i] == s[j];
            }
        }
        vector<vector<string> > ret;
        vector<string> path;
        dfs(s, 0, isPalindrome, path, ret);
        return ret;
    }
};