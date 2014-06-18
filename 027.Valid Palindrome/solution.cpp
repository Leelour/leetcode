#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
        {
            return true;
        }
        else
        {
            int i = 0, j = s.length() - 1;
            while(i < j)
            {
                if(isalpha(s[i]) && isalpha(s[j]))
                {
                    if(toupper(s[i]) != toupper(s[j]))
                        return false;
                    else
                    {
                        ++i;
                        --j;
                    }
                }
                else if(isdigit(s[i]) && isdigit(s[j]))
                {
                    if(s[i] == s[j])
                    {
                        ++ i;
                        -- j;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(isalnum(s[i]) && isalnum(s[j]))
                {
                    return false;
                }
                else
                {
                    if(!isalnum(s[i])) ++ i;
                    if(!isalnum(s[j])) -- j;
                }
            }
            return true;
        }
    }
};