class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<int> v(words.size(), 0);

        for (int i = 0; i < words.size(); i++)
        {
            int cur = 0;
            for (char c : words[i])
            {
                cur |= 1 << (c - 'a');
            }
            v[i] = cur;
        }
        int ans = 0;

        for (int i = 0; i < words.size() - 1; i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if ((v[i] & v[j]) == 0)
                {
                    int pro = words[i].size() * words[j].size();
                    ans = max(ans, pro);
                }
            }
        }

        return ans;
    }
};