class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        int n = target.size();
        // if(n==1 & )
        // return false;
        priority_queue<int> pq;
        sort(target.begin(), target.end());
        if (target[n - 1] < n)
            return false;

        long long int sum = 0; // overflow if not taken as ll
        for (int i = 0; i < n; i++)
        {
            pq.push(target[i]);
            sum += target[i];
        }

        while (pq.top() != 1)
        {
            int cur_top = pq.top();
            sum -= cur_top;
            if (sum == 0 || sum >= cur_top)
                return false;
            cur_top %= sum;
            //             cur_top -= sum 
            if (sum != 1 && cur_top == 0)
                return false;
            pq.pop();
            //             if(cur_top==1)
            //             {
            //                 sum++;
            //                 continue;
            //             }
            //             if(cur_top!=pq.top())
            //             {

            //             }
            //             else
            //                 return false;
            sum += cur_top;
            pq.push(cur_top);
        }

        return true;
    }
};

// had a good intution of the question after reading the first hint to reverse the process
// got a TLE after using cur_top -= sum 
// some mistakes in my original code are commented above
// the main logic of the code lie in the while loop