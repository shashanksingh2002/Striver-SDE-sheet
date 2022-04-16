Question:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Constraints:
* m == matrix.length
* n == matrix[0].length
* 1 <= m, n <= 200
* -231 <= matrix[i][j] <= 231 - 1

Follow up:

* A straightforward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?

*********************************************************************************************************************************************************************
Approach-1: (BRUTE-FORCE)
1.] Make a copy of the matrix.
2.] Take 4 pointers named on the basis of direction.
3.] whenever encountered a zero run in all direction till you reach the end or until you encounter another zero.

Code:

class Solution {
public:
    vector<vector<int>> copyMatrix(vector<vector<int>>& matrix){
      vector<vector<int>> ans;
      for(int i=0;i<matrix.size();i++){
        vector<int> temp;
        for(int j=0;j<matrix[i].size();j++){
           temp.push_back(matrix[i][j]);
        }
        ans.push_back(temp);
      }
      return ans;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = copyMatrix(matrix);
        int up,down,left,right;
        for(int i=0;i<matrix.size();i++){
          for(int j=0;j<matrix[i].size();j++){
            if(temp[i][j]==0){
              up=i-1,down=i+1,right=j+1,left=j-1;
              while(up>=0&&temp[up][j]!=0){
                matrix[up--][j]=0;
              }
              while(down<matrix.size()&&temp[down][j]!=0){
                matrix[down++][j]=0;
              }
              while(left>=0&&temp[i][left]!=0){
                matrix[i][left--]=0;
              }
              while(right<matrix[i].size()&&temp[i][right]!=0){
                matrix[i][right++]=0;
              }
            }
          }
        }
      return;
    }
};
  
AUXILLIARY SPACE COMPLEXITY: THETHA(M*N)
TIME COMPLEXITY: O(ROWS*COLUMN*NUMBER OF ONES)
*******************************************************************************************************************************************************************
APPROACH-2 (IMPROVING SPACE)

1.] Store the j index of the place where zero is present.
2.] In the for loop while storing the index make the column zero.
3.] Run another for loop on the array where rows index is stored and make the rows zero.

CODE:

void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        for(int i=0;i<matrix.size();i++){
          for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==0){
              int left=j-1,right=j+1;
              rows.push_back(j);
              while(left>=0){
                matrix[i][left--]=0;
              }
              j++;
              while(j<matrix[i].size()){
                if(matrix[i][j]==0){
                   rows.push_back(j);
                }
                else{
                  matrix[i][j]=0;
                }
                j++;
              }
              break;
            }
          }
        }
      for(int i=0;i<rows.size();i++){
        int row=0,end = rows[i];
        while(row<matrix.size()){
          matrix[row++][end]=0;
        }
        
        
      }
   }
};

TIME COMPLEXITY:O(N*M)
AUXILIARY SPACE COMPLEXITY:O(M)

***********************************************************************************************************************************************************************

