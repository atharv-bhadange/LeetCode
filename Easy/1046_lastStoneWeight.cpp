class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }

        while (pq.size() > 1)
        {
            // int s;
            int f = pq.top();
            pq.pop();
            if (pq.size() == 0)
                return f;

            int s = pq.top();
            pq.pop();

            if (f == s)
                continue;
            pq.push(abs(f - s));
        }

        if (pq.size() == 1)
        {
            return pq.top();
        }
        return pq.size();
    }
};

//standard pq question