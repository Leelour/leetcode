#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
int gcd(int a, int b)
{
    return b == 0? a : gcd(b, a % b);
}
//pair is unhashable, we need to define a hash function for it.
struct pairhash
{
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};
//type definition
typedef pair<int, int> DirVec;
typedef unordered_map<DirVec, int, pairhash> Hash;
class Solution
{
public:
    DirVec getDirVec(const Point& a, const Point& b)
    {
        int dx = a.x - b.x;
        int dy = a.y - b.y;
        int g = gcd(dx, dy);
        dx /= g;
        dy /= g;
        //when dx = 0, we use (0, INT_MAX) for all the dir vecs
        if(dx == 0)
            dy = INT_MAX;
        //when dy = 0, we use (0,0) for all the dir vecs
        if(dy == 0)
            dx = 0;
        return DirVec(dx, dy);
    }
    int maxPoints(vector<Point> &points)
    {
        if(points.size() <= 1)
            return (int)points.size();
        int max = 0, duplicate;
        Hash hash;
        for(int i = 0; i < (int)points.size(); ++ i)
        {
            //duplicates mean
            duplicate = 1;
            for(int j = i + 1; j < (int)points.size(); ++ j)
            {
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                {
                    ++duplicate;
                }
                else
                {
                    ++hash[getDirVec(points[i], points[j])];
                }
            }
            //fringe case [(0,0),(0,0),(0,0)]
            //in this case, the size of hash is 0
            max = max < duplicate ? duplicate : max;
            for(Hash::const_iterator c_iter = hash.begin(); c_iter != hash.end(); ++ c_iter)
            {
                if(c_iter->second + duplicate >= max)
                    max = c_iter->second + duplicate;
            }
            hash.clear();
        }
        return max;
    }
    
};
int main(int argc, const char * argv[])
{
    
    // insert code here...
    vector<Point> points;
    points.push_back(Point(0,0));
    points.push_back(Point(0,0));
    points.push_back(Point(0,0));
    points.push_back(Point(0,0));
    points.push_back(Point(1,1));
    points.push_back(Point(1,0));
    points.push_back(Point(2,0));
    points.push_back(Point(3,0));
    points.push_back(Point(0,1));
    points.push_back(Point(2,2));
    Solution sol;
    printf("%d\n", sol.maxPoints(points));
    return 0;
}