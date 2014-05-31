#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        int a, b;
        for(int i = 0; i < tokens.size(); ++i)
        {
            //asssume all expressions are valid, otherwise, we need to check when using s.top() / s.pop()
            if(tokens[i] == "+")
            {
                a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(b + a);
            }
            else if(tokens[i] == "-")
            {
                a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(b - a);
            }
            else if(tokens[i] == "*")
            {
                a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(b * a);
            }
            else if(tokens[i] == "/")
            {
                a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(b / a);
            }
            else
            {
                s.push(atoi(tokens[i].c_str()));
            }
        }
        return s.top();
    }
};
int main(int argc, const char * argv[])
{   
    // insert code here...
    vector<string> tockens;
    tockens.push_back("1");
    tockens.push_back("2");
    tockens.push_back("3");
    tockens.push_back("-");
    tockens.push_back("*");
    Solution sol;
    cout << sol.evalRPN(tockens) << endl;
    return 0;
}
