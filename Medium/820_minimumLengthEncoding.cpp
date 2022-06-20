class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        set<string> s;
        for (auto x : words)
        {
            s.insert(x);
        }
        for (auto &x : words)
        {
            for (int i = 1; i < x.size(); i++)
            {
                auto it = s.find(x.substr(i));
                if (it != s.end())
                    s.erase(it);
            }
        }
        int ans = 0;
        for (auto x : s)
            ans += x.size() + 1;

        return ans;
    }
};

// store all the substrings in set
// for every string find it's substring in the set and remove it
// rest remaining is the answer