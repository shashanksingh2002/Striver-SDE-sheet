Question:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
  
Approach:
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
  
AUXILLIARY SPACE COMPLEXITY: THETHA(N^2)
TIME COMPLEXITY: O(ROWS*COLUMN*NUMBER OF ONES)
