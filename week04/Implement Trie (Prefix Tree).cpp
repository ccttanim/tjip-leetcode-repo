
class Trie {
    Trie* children[26];
    bool isEndofWord;
public:
    Trie() {
        isEndofWord = false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }

    void insert(string word) {
        Trie* curr = this;
        for(char c : word)
        {
            if(!(curr->children[c - 'a']))
                curr->children[c - 'a'] = new Trie;
            curr = curr->children[c - 'a'];
        }
        curr->isEndofWord = true;
    }

    bool search(string word) {
          Trie* curr = this;
        for(char c : word)
        {
            curr = curr->children[c - 'a'];
            if(!curr)
                return false;
        }
        if (curr->isEndofWord)
            return true;
        return false;
    }

    bool startsWith(string prefix) {
           Trie* curr = this;
        for(char c : prefix)
        {
            curr = curr->children[c - 'a'];
            if(!curr)
                return false;
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
