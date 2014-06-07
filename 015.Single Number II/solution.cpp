class Solution {
public:
    // We use ternary to calculate the number
    int singleNumber(int A[], int n) {
        int t1 = 0, t2 = 0, t3 = 0;
        for(int i = 0; i < n; ++ i)
        {
            t3 = t1 & A[i];
            t1 ^= A[i];
            t2 |= t3;
            t3 = ~(t1 & t2);
            t1 &= t3;
            t2 &= t3;
        }
        //cout << t1 << " " << t2 << endl;
        return t1 | t2;
    }
};