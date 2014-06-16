class Solution {
public:
    int candy(vector<int> &ratings) {
        int len = (int) ratings.size();
        vector<int> candyNum(len, 1);
        for(int i = 1; i < len; ++ i)
        {
            if(ratings[i] > ratings[i - 1])
            {
                candyNum[i] = candyNum[i - 1] + 1;
            }
        }
        for(int i = len - 2; i >= 0; -- i)
        {
            if(ratings[i] > ratings[i + 1] && candyNum[i] <= candyNum[i + 1])
            {
                candyNum[i] = candyNum[i + 1] + 1;
            }
        }
        int sum = 0;
        for(auto i : candyNum)
        {
            sum += i;
        }
        return sum;
    }
};