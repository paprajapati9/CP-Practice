#include<iostream>
#include <vector>

using namespace std;


class Sudoku {
public:
    
    bool isValidColumn(vector<vector<char>> board, int column){
        int count[10] = {0};
        for(int i=0; i<board.size(); i++){
            int val = board[i][column] - '0';
            if(val < 0) continue;
            count[val]++;
            if(count[val] > 1) return false;
        }
        return true;
    }
    
    bool isValidRow(vector<char> boardArr){
        int count[10] = {0};
        for(int i=0; i<boardArr.size(); i++){
            int val = boardArr[i] - '0';
            if(val < 0) continue;
            count[val]++;
            if(count[val] > 1) return false;
        }
        return true;
    }
    
    bool isValidBox(vector<vector<char>> board, int startRow, int startCol){
        int count[10] = {0};
        for(int i=startRow; i<startRow+3; i++){
            for(int j=startCol; j<startCol+3; j++){
                int val = board[i][j] - '0';
                if(val < 0) continue;
                count[val]++;
                if(count[val] > 1) return false;
            }
        }
        
        return true;
    }
    
    int recursiveSudoku(vector<vector<char>>& board, int startRow, int startCol){
        if(startRow==8 && startCol==9) return 1;
        if (startCol == 9) {
            startRow++;
            startCol = 0;
        }
        int val = board[startRow][startCol] - '0';
        int k;
        if(val < 0){ //empty place
            for(k=1; k<=9; k++){
                // cout<<k<<" ";
                board[startRow][startCol] = k + '0';
                if(!isValidRow(board[startRow]) || !isValidColumn(board, startCol) && k) continue;
                if(!isValidBox(board, 3*(startRow/3), 3*(startCol/3))) continue;
                if(recursiveSudoku(board, startRow, startCol+1)) return 1;
               
            }
            if(k == 10) {
                board[startRow][startCol] = '.';
                return 0;
            }
        }else{
            return recursiveSudoku(board, startRow, startCol+1);
        }
        return 0;
    }

    bool hasValidBox(vector<vector<char>> board, int startRow, int startCol){
        int count[10] = {0};
        for(int i=startRow; i<startRow+3; i++){
            for(int j=startCol; j<startCol+3; j++){
                int val = board[i][j] - '0';
                if(val < 0) continue;
                count[val]++;
                if(count[val] > 1) return false;
            }
        }
        if(startCol < 6) return hasValidBox(board, startRow, startCol+3);
        else if(startRow < 6) return hasValidBox(board, startRow+3, 0);
        
        return true;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        recursiveSudoku(board, 0, 0);
        display(board);
    }

    void display(vector<vector<char>> board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    bool checkRowsAndColumns(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            if(!isValidRow(board[i]) || !isValidColumn(board, i)) return false;
        }
        
        if(!hasValidBox(board, 0, 0)) return false;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        if(checkRowsAndColumns(board)) return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{

    vector<vector<char>> board 
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','.','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','.','.','.','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','.','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},

        
    };

    Sudoku sudoku;
    sudoku.solveSudoku(board);
    if(sudoku.isValidSudoku(board)) cout<<"\nValid";
    else cout<<"\nNot valid";
    return 0;
}