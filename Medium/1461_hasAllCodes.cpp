class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        if (k > s.size())
            return false;

        unordered_set<string> st;

        for (int i = 0; i < s.size() - k + 1; i++)
            st.insert(s.substr(i, k));

        if (st.size() == pow(2, k))
            return true;
        return false;
    }
};

// obvious use of STL still couldn't get an intuition on my own