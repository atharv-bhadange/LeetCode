class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>> &courses)
    {
        int i = 0;
        int currentTotalTime = 0;
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> pq;
        for (i = 0; i < courses.size(); i++)
        {
            currentTotalTime += courses[i][0];
            pq.push(courses[i][0]);
            if (currentTotalTime > courses[i][1])
            {
                currentTotalTime -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};

// same principal as any other priority queue question
// subtract the max-till-current-index it current time exceeds the specified duration of the course