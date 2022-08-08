class Solution
{
public:
    //     void count(vector<int>& t)
    //     {

    //     }

    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> countB(26);
        vector<string> ans;
        for (auto &word : words2)
        {
            vector<int> temp_count(26);
            for (int i = 0; i < word.size(); i++)
                temp_count[word[i] - 'a']++; // hash a string in second list

            for (int i = 0; i < 26; i++)
                countB[i] = max(countB[i], temp_count[i]);  // we need the max count of each letter
        }

        for (auto &word : words1)
        {
            vector<int> temp_count(26);
            for (int i = 0; i < word.size(); i++)
                temp_count[word[i] - 'a']++;

            bool f = 1;
            for (int i = 0; i < 26; i++)
                if (temp_count[i] < countB[i]) // compare the max count with each string's hash in first list
                {
                    f = 0;
                    break;
                }
            if (f)
                ans.push_back(word); // add only if hash is greater for all the letters
        }

        return ans;
    }
};