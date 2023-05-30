class Solution {
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0] and adjacentSearch(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
private:
    bool adjacentSearch(vector<vector<char>>&board, string word, int i, int j, int len){
        if(len == word.size())
            return true;
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size())
            return false;
        if(board[i][j] != word[len])
            return false;
        board[i][j] = '*';
        bool ans = 
        adjacentSearch(board, word, i-1, j, len+1) || //up
        adjacentSearch(board, word, i+1, j, len+1) || //down
        adjacentSearch(board, word, i, j-1, len+1) || //left
        adjacentSearch(board, word, i, j+1, len+1); // right
        board[i][j] = word[len];
        return ans;
    }
};
