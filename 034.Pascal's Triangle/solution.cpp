class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        if(numRows > 0)
        {
            for(int i = 0; i < numRows; ++ i)
            {
                vector<int> line;
                for(int j = 0; j <= i; ++ j)
                {
                    if(j == 0 || j == i)//side
                    {
                        line.push_back(1);
                    }
                    else
                    {
                        line.push_back(ret[i-1][j] + ret[i-1][j-1]);
                    }
                }
                ret.push_back(line);
            }
        }
        else//in case of fringe case
        {
            return ret;
        }
    }
};