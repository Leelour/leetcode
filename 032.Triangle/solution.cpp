class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        //dynamic programming
        if(triangle.size() == 0 || triangle[0].size() == 0)
            return 0;
        else
        {
            for(int i = triangle.size() - 2; i >= 0; -- i)
            {
                for(int j = 0; j < triangle[i].size(); ++ j)
                {
                    triangle[i][j] = triangle[i+1][j] > triangle[i+1][j+1] ? triangle[i][j] + triangle[i+1][j+1] : triangle[i][j] + triangle[i+1][j];
                }
            }
            return triangle[0][0];
        }
    }
};