class Node{
    private:
        bool flag;
        Node* links[26];
    public:
        Node(){
            flag = false;
            for(int i=0; i<26; i++)
                links[i] = nullptr;
        }    

    bool contains(char ch){
        return links[ch-'a'] != nullptr;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string s) {
        Node* node = root;
        for(int i=0; i<s.size(); i++)
        {
            if(!node->contains(s[i])){
                node->put(s[i],new Node());
            }
            node = node->get(s[i]);
        }

        node->setEnd();
    }
    
    bool search(string s) {
        Node* node = root;
        for(int i=0; i<s.size(); i++)
        {
            if(!node->contains(s[i])){
                return false;
            }
            node = node->get(s[i]);
        }

        return node->isEnd();
    }
    
    bool startsWith(string s) {
        Node* node = root;
        for(int i=0; i<s.size(); i++){
            if(!node->contains(s[i])){
                return false;
            }
            node = node->get(s[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */