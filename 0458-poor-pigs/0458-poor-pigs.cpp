class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int n = minutesToTest/minutesToDie;
        n++;
        return ceil(log2(buckets)/log2(n));
    }
};