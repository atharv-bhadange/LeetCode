class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;
        for (auto &word : words)
        {
            char a[26], b[26];
            if (word.size() != pattern.size())
                continue;
            for (int i = 0; i < 26; i++)
            {
                b[i] = '.';
                a[i] = '.';
            }
            bool f = 1;
            for (int i = 0; i < pattern.size(); i++)
            {
                if (a[pattern[i] - 'a'] == '.' && b[word[i] - 'a'] == '.')
                {
                    a[pattern[i] - 'a'] = word[i];
                    b[word[i] - 'a'] = pattern[i];
                }
                else
                {
                    if (a[pattern[i] - 'a'] != word[i] || b[word[i] - 'a'] != pattern[i])
                    {
                        f = 0;
                    }
                }
            }

            if (f)
                ans.push_back(word);
        }

        return ans;
    }
};