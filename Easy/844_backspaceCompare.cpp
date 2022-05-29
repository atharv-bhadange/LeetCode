class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st1, st2;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '#')
                st1.push(s[i]);
            else
            {
                if (!st1.empty())
                    st1.pop();
            }
        }

        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] != '#')
                st2.push(t[i]);
            else
            {
                if (!st2.empty())
                    st2.pop();
            }
        }

        while (!st1.empty() && !st2.empty())
        {
            int s1 = st1.top();
            st1.pop();
            int s2 = st2.top();
            st2.pop();

            if (s1 != s2)
                return false;
        }
        if (!st1.empty() || !st2.empty())
            return false;
        return true;
    }
};