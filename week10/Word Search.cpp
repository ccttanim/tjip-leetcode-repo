  bool isValid(int i, int j, int n, int m) {
        if(i >= 0 && j >= 0 && i < n && j < m) 
            return true;
        else 
            return false;
    }
    bool solve(int i, int j, int n, int m, int k, vector<vector<char>>& board, string word) {
        if(k == word.size()) 
            return true;
        if(isValid(i, j, n, m))
            if(board[i][j] == word[k]) {
                board[i][j] = '.';
                    if(solve(i + 1, j, n, m, k + 1, board, word)) return true;
                    if(solve(i - 1, j, n, m, k + 1, board, word)) return true;
                    if(solve(i, j - 1, n, m, k + 1, board, word)) return true;
                    if(solve(i, j + 1, n, m, k + 1, board, word)) return true;
                board[i][j] = word[k];
            }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        if(n == 1 && m == 1 && word.size() == 1 && board[0][0] == word[0]) 
            return true;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == word[0])
                    if(solve(i, j, n, m, 0, board, word)) return true;
        return false;
    }
