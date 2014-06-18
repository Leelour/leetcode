class Solution {
    typedef int LEVEL;
    typedef pair<string, LEVEL> Node;
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<Node> q;
        q.push(Node(start, 1));
        unordered_set<string>:: const_iterator it;
        while(!q.empty())
        {
            Node cur = q.front();
            q.pop();
            if(cur.first == end)
            {
                return cur.second;
            }
            for(int i = 0; i < cur.first.length(); ++ i)
            {
                for(char j = 'a'; j <= 'z'; ++ j)
                {
                    if(j != cur.first[i])
                    {
                        char backup = cur.first[i];
                        cur.first[i] = j;
                        it = dict.find(cur.first);
                        if(it != dict.cend())
                        {
                            q.push(Node(cur.first, cur.second + 1));
                            dict.erase(it);
                        }
                        cur.first[i] = backup;
                    }
                }
            }
        }
        return 0;
    }
};