class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<int>> line_map, col_map;
        
        for(int i=0; i<board.size(); i+=3){
            for(int j=0; j<board[i].size(); j+=3){
                set<int> box_set;
                for(int k = i; k<i+3; k++){
                    for(int l = j; l<j+3;l++){
                        if (board[k][l] == '.') continue;
                        int elem = board[k][l];
                        if(line_map[k].find(elem) != line_map[k].end()){
                            return false;
                        }
                        else{
                            line_map[k].insert(elem);
                        }

                        if(col_map[l].find(elem) != col_map[l].end()){
                            return false;
                        }
                        else{
                            col_map[l].insert(elem);
                        }
                        if(box_set.find(board[k][l]) == box_set.end()){
                            box_set.insert(board[k][l]);
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};