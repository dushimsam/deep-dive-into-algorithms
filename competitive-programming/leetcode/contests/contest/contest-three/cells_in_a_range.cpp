#include<bits/stdc++.h>
using namespace std;


vector<string> extractCells(string input){
    vector<string> start_cells;
    string str1;
    string str2;
    bool foundDot = false;
    for(int i=0;i<input.length();i++){
        if(foundDot) str2.push_back(input[i]);
        else if(!foundDot) str1.push_back(input[i]);
        else if(input[i] == ':') start_cells.push_back(str1);
    }
    start_cells.push_back(str2);

    return start_cells;
}

int giveStartIndex(vector<char> possibles_rows,char target){
    for(int i=0;i<possibles_rows.size();i++){
        if(possibles_rows[i] == target) return i;
    }
    return 0;
}

int extractRowNumber(string input){
    int start_row = 1;
    string number;
    for(int i=0;i<input.length();i++){
        if(isdigit(input[i])) number.push_back(input[i]);
    }

    start_row = stoi(number);
    return start_row;
}

vector<string>  cellsInRange(string input){
    vector<char> possibles_cols={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    vector<string> range = extractCells(input);
    int maxRows = max(extractRowNumber(range[0]),extractRowNumber(range[1]));
    int startRow = extractRowNumber(range[0]);

    vector<string> cells_in_range;


    for(int i= giveStartIndex(possibles_cols,range[0][0]);i<possibles_cols.size();i++){
        
          for(int j=startRow;j<=maxRows;j++){
               string newCell;
               newCell.push_back(possibles_cols[i]);
               newCell.push_back(j);
               cells_in_range.push_back(newCell);
               
               if(newCell == range[1]) return cells_in_range;
               newCell.clear();
          }
          startRow =0;
    }

    return cells_in_range;
}
    
    int main(){

    
    return 0;
}