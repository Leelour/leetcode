class Solution {
public:
    //The prime here is that there is only one solution if the solution exsits.
    //So if we start at station i, sum(net[j] to net[i-1]) < 0 and sum(net[i] to net[n]) > 0
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int startNode = 0, sum = 0, presum = 0, net;
        for(int i = 0; i < (int) gas.size(); ++ i)
        {
            net = gas[i] - cost[i];
            sum += net;
            presum += net;
            if(presum < 0)
            {
                startNode = i + 1;
                presum = 0;
            }
        }
        return sum < 0 ? -1 : startNode;
    }
};