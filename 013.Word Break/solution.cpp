class Solution
{
public:
    bool wordBreak(string s, unordered_set<string> &dict)
    {
        bool *dp = new bool[s.size() + 1];
        memset(dp, 0, (s.size() + 1) * sizeof(bool));
        dp[0] = true;
        string ns = '#' + s;
        for(int i = 1; i < ns.size(); ++ i)
        {
            for(int j = 0; j < i; ++ j)
            {
                dp[i] = dp[j] && (dict.find(ns.substr(j+1, i-j)) != dict.end());
                if(dp[i])
                    break;
            }
        }
        return dp[s.size()];
    }
};