/*
class TrieNode{
    public:
        TrieNode* arr[26];
        bool isLeaf;

        TrieNode(){
            for(int i=0; i<26; i++)
                arr[i] = nullptr;
            isLeaf = false;
        }

        void insert(TrieNode* root, string s){
            TrieNode* crawl = root;
            for(int i=0; i<s.size(); i++)
            {
                TrieNode* t = new TrieNode;
                crawl->arr[s[i]-'a'] = t;
                crawl = t;
            }
            crawl->isLeaf = true;
        }

        bool search(TrieNode* root, string s){
            TrieNode* crawl = root;
            int i=0;
            for(i=0; s.size(); i++)
            {
                if(!crawl->arr[s[i]-'a'])
                {
                    for(int j=0; j<26; j++)
                    {
                        if(crawl->arr[j])
                        {
                            crawl = crawl->arr[j];
                            break;
                        }
                    }
                    i--;
                }
                else{
                    crawl = crawl->arr[s[i]-'a'];
                }
            }

            return i==s.size()-1;
        }
};
*/

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        // TrieNode* root = new TrieNode;
        // root->insert(root, s);
        // int ans = 0;
        // for(int i=0; i<words.size(); i++)
        // {
        //     ans+=root->search(root, words[i]);
        // }
        // return ans;

        vector<vector<int>> mp(26);
        for (int i = 0; i < s.size(); i++)
            mp[s[i] - 'a'].push_back(i);

        int ans = words.size();
        for (auto &w : words)
        {
            int lt = -1;
            for (auto c : w)
            {
                auto &cv = mp[c - 'a'];
                auto it = upper_bound(cv.begin(), cv.end(), lt);
                if (it == cv.end())
                {
                    ans--;
                    break;
                }
                else
                    lt = *it;
            }
        }

        return ans;
    }
};

// tried by trie tree but failed
// done by map