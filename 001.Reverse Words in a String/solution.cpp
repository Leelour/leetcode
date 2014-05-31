#include <iostream>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        s += " ";
        string ret = "", pre = "";
        for(int i = 0; i < s.length(); ++ i)
        {
            if (s[i] == ' ')
            {
                if(pre.length() != 0)
                {
                    ret = pre + (ret == ""? "":" ") + ret;
                }
                pre = "";
            }
            else
            {
                pre += s[i];
            }
        }
        s = ret;
    }
};
int main()
{
    Solution sol;
    string s = " a   b  ";
    sol.reverseWords(s);
    cout << s << endl;
    return 0;
}
