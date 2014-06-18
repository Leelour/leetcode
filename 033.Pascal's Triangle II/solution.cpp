class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r1, r2;
        vector<int>& pre= r1;
        vector<int>& cur = r2;
        vector<int>& tmp = pre;
        r1.push_back(1);
        if(rowIndex < 0)
        {
            return cur;
        }
        else
        {
            for(int i = 1; i <= rowIndex; ++ i)
            {
                for(int j = 0; j <= i; ++j)
                {
                    if(i == j || j == 0)
                    {
                        cur.push_back(1);
                    }
                    else
                    {
                        cur.push_back(pre[j] + pre[j-1]);
                    }
                }
                cur.swap(pre);
                cur.clear();
            }
            return pre;
        }
    }
};