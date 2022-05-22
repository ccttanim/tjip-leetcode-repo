class TrieNode{
public:
    vector<TrieNode*> children;
    string word;
    
    TrieNode(){
        children = vector<TrieNode*>(26, nullptr);
    }
};

class Trie{
public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    
    void add(string word){
        TrieNode* cur = root;
        for(char c : word){
            if(cur->children[c-'a'] == nullptr){
                cur->children[c-'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        
        cur->word = word;
    }
    
    bool find(string word){
        TrieNode* cur = root;
        for(char c : word){
            cur = cur->children[c-'a'];
            if(cur == nullptr){
                return false;
            }
        }
        
        return true;
    }
};

class Solution {
public:
    Trie* trie;
    
    void dfs(vector<vector<char>>& board, int m, int n, int ci, int cj, TrieNode* node, vector<string>& ans){
        
        char c = board[ci][cj];
      
        if(c == '#') return;
       
        if(node->children[c-'a'] == nullptr) return;
        
        node = node->children[c-'a'];
        if(node->word != ""){
            ans.push_back(node->word);
           
            node->word = "";
        }
        
        
        board[ci][cj] = '#';
        
        if(ci > 0)   dfs(board, m, n, ci-1, cj,   node, ans);
        if(ci+1 < m) dfs(board, m, n, ci+1, cj,   node, ans);
        if(cj > 0)   dfs(board, m, n, ci,   cj-1, node, ans);
        if(cj+1 < n) dfs(board, m, n, ci,   cj+1, node, ans);
                
        board[ci][cj] = c;
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        if(m == 0) return vector<string>();
        int n = board[0].size();
        
        trie = new Trie();
        
        for(string& word : words){
            trie->add(word);
        }
        
        vector<string> ans;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dfs(board, m, n, i, j, trie->root, ans);
            }
        }
        
        return ans;
    }
};
