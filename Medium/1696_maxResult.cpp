#define pii pair<int, int>
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        int score[n];
        priority_queue<pii> pq;

        for (int i = n - 1; i >= 0; i--)
        {
            while (pq.size() && pq.top().second > i + k)
                pq.pop();

            score[i] = nums[i];
            score[i] += (pq.size() ? pq.top().first : 0);
            pq.push({score[i], i});
        }

        return score[0];
    }
};

// score[i] will store the score if I start jumping from index i and priority queue will store all the scores of the window [i+1, min(n-1, i+k)].
// To get the maximum score from index i, I should jump to next index with the maximum value in the window.