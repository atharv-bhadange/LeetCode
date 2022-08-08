class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int n = minutesToTest / minutesToDie;
        n++; // if a pig doesn't die in n buckets then surely last one will be poisoned one 
        return ceil(log(buckets) / log(n));
    }
};

// extremely unsolvable question according to me
// visualize in mutiple dimension
