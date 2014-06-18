struct Node
{
    int level;
    vector<int> parents;
    string value;
    Node(){};
    Node(int l, vector<int> p, string v):level(l), parents(p), value(v){}
    Node(Node& node)
    {
        level = node.level;
        parents = node.parents;
        value = node.value;
    }
};
class Solution {
public:
    void buildResult(Node *q, int idx, vector<string> &path, vector<vector<string>> &ret)
    {
        if(idx == -1)
        {
            ret.push_back(path);
        }
        else
        {
            path.insert(path.begin(), q[idx].value);
            for(int i : q[idx].parents)
            {
                buildResult(q, i, path, ret);
            }
            path.erase(path.begin());
        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
    {
        vector<vector<string>> ret;
        Node *q = new Node[dict.size()];
        int head = 0, tail = 0;
        q[tail++] = Node(0, vector<int>(1, -1), start);
        unordered_set<string>::const_iterator cit;
        unordered_map<string, int> index;
        vector<string> erase_q;
        if(dict.find(start) != dict.cend())
        {
            dict.erase(start);
        }
        while(head < tail)
        {
            if(q[head].value == end)
            {
                vector<string> path;
                buildResult(q, head, path, ret);
                break;
            }
            for(int i = 0; i < (int)q[head].value.length(); ++ i)
            {
                for(char j = 'a'; j <= 'z'; ++ j)
                {
                    char backup = q[head].value[i];
                    q[head].value[i] = j;
                    //find value in the dict
                    if(dict.find(q[head].value) != dict.cend())
                    {
                        //if already in the index
                        if(index.find(q[head].value) != index.cend())
                        {
                            int idx = index[q[head].value];
                            q[idx].parents.push_back(head);
                        }
                        //not found in the index
                        else
                        {
                            //create a new node
                            q[tail] = Node(q[head].level + 1, vector<int>(1, head), q[head].value);
                            //update index
                            index[q[head].value] = tail ++;
                            //add current value to erase queue
                            erase_q.push_back(q[head].value);
                        }
                    }
                    q[head].value[i] = backup;
                }
            }
            //move to next level
            if(head + 1 < tail && q[head].level != q[head+1].level)
            {
                //clean the erase queue
                for(string key : erase_q)
                {
                    dict.erase(key);
                }
                erase_q.clear();
            }
            ++ head;
        }
        delete []q;
        return ret;
    }
};