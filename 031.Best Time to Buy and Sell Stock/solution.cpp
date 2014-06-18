class Solution {
public:
    int maxProfit(vector<int> &prices){
        int len = (int) prices.size();
        if(len <= 0)
            return 0;
        int max = 0;
        int premin = prices[0];
        for(int i = 0; i < len; ++ i)
        {
            if(premin < prices[i])
            {
                max = max > (prices[i] - premin)? max : prices[i] - premin;
            }
            else if(premin > prices[i])
            {
                premin = prices[i];
            }
        }
        return max;
    }
};