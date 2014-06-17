class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> hash;
        bool * used = new bool[(int)num.size()];
        memset(used, 0, sizeof(bool) * (int) num.size());
        for(int i = 0; i < (int) num.size(); ++ i)
        {
            hash[num[i]] = i;
        }
        int max = 0, len = 0, v;
        for(int i = 0; i < (int) num.size(); ++ i)
        {
            if(!used[i])
            {
                len = 1;
                used[i] = true;
                for(v = num[i] - 1; hash.find(v) != hash.end(); ++len, -- v)
                {
                    used[hash[v]] = true;
                }
                for(v = num[i] + 1; hash.find(v) != hash.end(); ++len, --v)
                {
                    used[hash[v]] = true;
                }
                max = max > len ? max : len;
            }
        }
        delete used;
        return max;
    }
};