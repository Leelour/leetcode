//space O(N*N) but more clear for understanding
class Solution {
public:
    int minCut(string s)
    {
        int len = (int)s.length();
        vector<vector<bool> > isPalindrome(len + 1, vector<bool>(len + 1, true));
        for(int j = 1; j < len; ++ j)
        {
            for(int i = 0; i < j; ++ i)
            {
                isPalindrome[i][j] = isPalindrome[i+1][j-1]  && s[i] == s[j];
            }
        }
        
        vector<int> cut(len, 0);
        for(int i = 0; i < len ; ++ i)
        {
            cut[i] = i;
        }
        
        for(int i = 0; i < len; ++ i)
        {
            if(isPalindrome[0][i])
                cut[i] = 0;
            for(int j = 1; j <= i; ++ j)
            {
                if(isPalindrome[j][i])
                {
                    cut[i] = cut[i] < cut[j-1] + 1? cut[i] : cut[j-1] + 1;
                }
            }
        }
        return cut[len-1];
    }
};