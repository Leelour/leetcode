class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = (int) prices.size();
        if(len <= 1)
            return 0;
        int total = 0;
        for(int i = 1; i < len; ++ i)
        {
            if(prices[i] > prices[i-1])
                total += (prices[i] - prices[i-1]);
        }
        return total;
    }
};