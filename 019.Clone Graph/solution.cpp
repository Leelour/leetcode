#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
    //use function pointer and bfs 3 times to achive this goal
    //we can also use unordered_map and copy the graph with one bfs
    void bfs(UndirectedGraphNode *node, void (*job)(UndirectedGraphNode *), int offset = 0)
    {
        //bfs the graph and do some job
        queue<UndirectedGraphNode *> q;
        q.push(node);
        unordered_set<UndirectedGraphNode *> visted;
        visted.insert(node);
        UndirectedGraphNode *cur;
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            job(cur);
            for(int i = 0; i < (int) cur->neighbors.size() + offset; ++i)
            {
                if(visted.find(cur->neighbors[i]) == visted.end())
                {
                    q.push(cur->neighbors[i]);
                    visted.insert(cur->neighbors[i]);
                }
            }
        }
    }
    static void createClone(UndirectedGraphNode *node)
    {
        UndirectedGraphNode *cloneNode = new UndirectedGraphNode(node->label);
        //create bidirectional link between node and clone
        node->neighbors.push_back(cloneNode);
        cloneNode->neighbors.push_back(node);
    }
    static void copyNeighbors(UndirectedGraphNode *node)
    {
        UndirectedGraphNode *cloneNode = node->neighbors.back();
        for(int i = 0; i < (int) node->neighbors.size() - 1; ++ i)
        {
            cloneNode->neighbors.push_back(node->neighbors[i]->neighbors.back());
        }
    }
    static void deliveryClone(UndirectedGraphNode *node)
    {
        UndirectedGraphNode *cloneNode = node->neighbors.back();
        //remove link from clone node to node
        cloneNode->neighbors.erase(cloneNode->neighbors.begin());
        //remove link from node to clone node
        node->neighbors.pop_back();
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        //in case of null pointer
        if(node == NULL)
            return NULL;
        bfs(node, createClone, -1);
        bfs(node, copyNeighbors, -1);
        UndirectedGraphNode *clone = node->neighbors.back();
        bfs(node, deliveryClone);
        return clone;
    }
};