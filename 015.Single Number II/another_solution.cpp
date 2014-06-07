class Solution {
public:
    vector<unsigned> convertIntToTernary(unsigned v)
    {
        vector<unsigned> ret;
        while(v)
        {
            ret.push_back(v % 3);
            v /= 3;
        }
        return ret;
    }
    void update(vector<unsigned> &ans, const vector<unsigned> &tmp)
    {
        for(int i = 0; i < (unsigned) tmp.size() && i < (unsigned) ans.size(); ++ i)
        {
            ans[i] = (ans[i] + tmp[i]) % 3;
        }
    }
    
    void half(vector<unsigned> &ans)
    {
        for(int i = 0; i < ans.size(); ++ i)
        {
            if(ans[i] == 1)
            {
                ans[i] = 2;
            }
            else
            {
                ans[i] /= 2;
            }
        }
    }
    
    int convertTernaryToInt(vector<unsigned> &ans)
    {
        long long base = 1L;
        long long ret = 0;
        for(int i = 0; i < ans.size(); ++ i)
        {
            ret += ans[i] * base;
            base *= 3;
        }
        return (int) ret;
    }
    
    const int BIT = 21;
    int singleNumber(int A[], int n) {
        vector<unsigned> ans(BIT, 0);
        vector<unsigned> tmp;
        for(int i = 0; i < n; ++ i)
        {
            tmp = convertIntToTernary((unsigned)A[i]);
            update(ans, tmp);
        }
        if (n % 3 == 1)
        {
            return convertTernaryToInt(ans);
        }
        else if(n % 3 == 2)
        {
            half(ans);
            return convertTernaryToInt(ans);
        }
        else
        {
            return -1;
        }
    }
};