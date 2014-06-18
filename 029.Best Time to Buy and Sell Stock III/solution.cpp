class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max = 0;
        int cnt = (int) prices.size();
        if(cnt <= 1)
            return 0;
        int maxProfitEndWith[cnt];
        int premin = prices[0];
        int profit = 0, cur_profit;
        for(int  i = 0; i < cnt; ++ i)
        {
            cur_profit = prices[i] - premin;
            if(premin > prices[i])
            {
                premin = prices[i];
            }
            if(cur_profit > profit)
                profit = cur_profit;
            maxProfitEndWith[i] = profit;
        }
        int postMax = prices[cnt - 1];
        profit = 0;
        for(int i = cnt - 1; i >= 0; --i)
        {
            cur_profit = postMax - prices[i];
            if(postMax < prices[i])
            {
                postMax = prices[i];
            }
            if(cur_profit > profit)
                profit = cur_profit;
            max =  max > maxProfitEndWith[i] + profit ? max : maxProfitEndWith[i] + profit;
        }
        return max;
    }
};