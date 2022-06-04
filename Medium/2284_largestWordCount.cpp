class Solution
{
public:
    static bool cmp(pair<string, int> &a, pair<string, int> &b)
    {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first > b.first;
    }
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        map<string, int> m;

        for (int i = 0; i < messages.size(); i++)
        {
            // int c
            for (auto x : messages[i])
                if (x == ' ')
                    m[senders[i]]++;
            m[senders[i]]++;
        }

        vector<pair<string, int>> v;

        for (auto &i : m)
            v.push_back(i);

        sort(v.begin(), v.end(), cmp);

        for (auto x : v)
            cout << x.first << " " << x.second << endl;

        auto it = v.begin();

        return it->first;
    }
};