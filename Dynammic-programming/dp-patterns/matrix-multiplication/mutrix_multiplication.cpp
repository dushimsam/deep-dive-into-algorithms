#include<bits/stdc++.h>
using namespace std;

/***
 * 
Given a set of matrices give the mininum number of operations to multiply them.
Input: p[] = {{40, 20}{20, 30},{30, 10,{10, 30}}
Output: 26000  

In order words , find the best way to arrange these matrices so as when we multiply them
it will yield the min number of operations.
 * 
 *            APPROACH
 * 1. matrix[][] , declare dp_matrix[matrix.size()][matrix.size()] , k = 1;
 * 2. Fill diagonal with zeros.
 * 3. for(let i = 1 to matrix.size())
 * 4.    for(let j = 0 to (m-k))
 * 5.        let result_1 = dp_matrix[j][(j+k)-1] + (matrix[j].rows * matrix[(j+k)-1].cols * matrix[(j+1).cols])
 * 6.        let result_2 = dpmatrix[j-1][(j+k)] + (matrix[j].rows * matrix[j+1].rows * matrix[j+k].cols)
 * 7.        dp_matrix[i][j] = max(result_1,result_2)
 * 
***/

int countMinOperations(vector<vector<int>> matrix){
    int m_size = matrix.size();
    int cols = m_size;
    int rows = m_size;
    vector<vector<int>> dp_matrix (rows,vector<int>(cols,0));

    // Calculate for one element
    int i=0;
    int j = 0;

    while(i < rows && j < cols){
        dp_matrix[i][j] =0;
        i++;
        j++;
    }


    int k = 1;

    for(int i = 1; i < m_size; i++){

        for(int j = 0; j < (m_size-k); j++){
            
            int col_index = j+k;
            vector<int> right_element = matrix[col_index];
            
            int result_1 = dp_matrix[j][col_index-1] + matrix[j][0] * matrix[col_index-1][1] * right_element[1];
            int result_2 = dp_matrix[j+1][col_index] + matrix[j][0] * matrix[j+1][0] * right_element[1];
            
            dp_matrix[j][col_index] = min(result_1, result_2);
        }
        k++;
    }

    return dp_matrix[0][cols-1];
}


int main(){

vector<vector<int>> matrix = {{10,20},{20,30}};
cout<<countMinOperations(matrix);

return 0;
}