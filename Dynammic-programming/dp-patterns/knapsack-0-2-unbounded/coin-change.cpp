// #include<bits/stdc++.h>
// using namespace std;


// int minEdit(string a,string b){
//    vector<vector<int>> dp_matrix;

//    // fill the first row from 0 to n
//    // fill the first column from 0 to n

//    for(int i=0;i<rows;i++){
//        for(int j=1;j<cols;j++){
//            int diag = dp_matrix[i-1][j-1];
//            int left = dp_matrix[i][j-1];
//            int top_right = dp_matrix[i-1][j]; 
//            if(a[i] == b[i]) dp_matrix[i][j] = diag; // if they are the same , pull the last row and do none operation
//            else dp_matrix[i][j] = 1 + min(diag,min(left,right)) // add one and then select the minumum among the three'ss // on longest common subsequence we don't consider the diag element

//        }
//    }
// }



// int main(){


//     return 0;
// }