class Solution
{
public:
    static bool cmp(string s1, string s2)
    {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string> &words)
    {
        unordered_map<string, int> dp;
        int ans = 1;
        sort(words.begin(), words.end(), cmp);
        for (auto word : words)
        {
            dp[word] = 1;
            for (int i = 0; i < word.size(); i++)
            {
                string s = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(s) != dp.end())
                {
                    dp[word] = 1 + dp[s];
                    ans = max(ans, dp[word]);
                }
            }
        }

        return ans;
    }
};

// solution worked about in reverse way
// rather than finding the successor we find the predecessor
// we find all the predecessors of the current word and find it in the dp map
// if found, we increment the length of the value in the dp map