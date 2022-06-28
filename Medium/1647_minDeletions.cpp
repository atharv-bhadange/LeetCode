class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> freq(26, 0);

        for (int i = 0; i < s.size(); i++)
            freq[s[i] - 'a']++;

        unordered_set<int> st;
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            while (freq[i] && st.find(freq[i]) != st.end())
            {
                freq[i]--;
                ans++;
            }
            st.insert(freq[i]);
        }

        return ans;
    }
};

// store the frequencies in a set a if its not found store it in the set
// if it is found the keep reducing it by one until its not found in the set
// dk why i fucked up the implementation 