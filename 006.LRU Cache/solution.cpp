#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

//borrow the idea from 'http://www.cnblogs.com/TenosDoIt/p/3417157.html'
typedef int Key;
typedef int Value;
typedef pair<Key, Value> CacheEntry;
typedef list<CacheEntry> Cache;
class LRUCache{
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }
    
    int get(int key)
    {
        if(hash.find(key) == hash.end())
            return -1;
        else
        {
            history.splice(history.begin(), history, hash[key]);
            hash[key] = history.begin();
            return hash[key]->second;
        }
    }
    
    void set(int key, int value)
    {
        if(hash.find(key) == hash.end())
        {
            if(hash.size() == capacity)
            {
                hash.erase(history.back().first);
                history.pop_back();
            }
            history.push_front(CacheEntry(key, value));
            hash[key] = history.begin();
        }
        else
        {
            hash[key]->second = value;
            history.splice(history.begin(), history, hash[key]);
            hash[key] = history.begin();
        }
    }
private:
    int capacity;
    unordered_map<int, Cache::iterator > hash;
    Cache history;
};
