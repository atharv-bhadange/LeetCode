class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int> pq;
        int i = 0;
        int diff = 0;
        for (i = 0; i < n - 1; i++)
        {
            diff = heights[i + 1] - heights[i];
            if (diff <= 0)
                continue;

            bricks -= diff;
            pq.push(diff);

            if (bricks < 0)
            {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }

            if (ladders < 0)
                break;
        }

        return i;
    }
};

// use of priority queue
// first we assume to put all the bricks and put the bricks in max Heap(default setting of priority queue)
// if bricks' count goes less than zero we add back the bricks where maximum were used and place a ladder there
// in this way we can find the farthest we can go 
// when ladders' count goes zero we have no way to go any further