class Solution
{
public:
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        map<int, int> r;
        map<char, int> s;

        for (auto &x : ranks)
            r[x]++;

        for (auto &x : suits)
            s[x]++;

        for (auto &x : s)
        {
            if (x.second == 5)
                return "Flush";
        }

        for (auto &x : r)
        {
            if (x.second >= 3)
                return "Three of a Kind";
            else if (x.second == 2)
                return "Pair";
        }

        return "High Card";
    }
};