#include <iostream>
using namespace std;
class Solution {
public:
    int minCut(string s)
    {
        int len = (int)s.length();
        if(len == 0)
        {
            return 0;
        }
        bool isPalindrome[len];
        memset(isPalindrome, 0, sizeof(bool) * len);
        int cut[len];
        for(int i = 0; i < len; ++ i)
        {
            cut[i] = i;
        }
        isPalindrome[0] = true;
        for(int i = 1; i < len; ++ i)
        {
            isPalindrome[i] = true;
            for(int j = 0; j <= i; ++ j)
            {
                isPalindrome[j] = (s[i] == s[j] && (i == j ? true :isPalindrome[j+1]));
                if(isPalindrome[j])
                {
                    cut[i] = j == 0 ? 0 : (cut[i] < cut[j-1] + 1? cut[i] : cut[j-1] + 1);
                }
            }
        }
        return cut[len - 1];
    }
};