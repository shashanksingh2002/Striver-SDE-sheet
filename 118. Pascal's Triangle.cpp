Question
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
  
Constraints:
1 <= numRows <= 30
  
**********************************************************************************************************************************************************************
Approach-1:
* if index 0 or n-1 push 0 in the list
*otherwise push arr[i-2][j]+arr[i-2][j-1]

Code: 

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        
       for(int i=1;i<=numRows;i++){
         vector<int>a;
         for(int j=0;j<i;j++){
           if(j==0||j==i-1){
             a.push_back(1);
           }
           else{
             a.push_back(ans[i-2][j]+ans[i-2][j-1]);
           }
         }
         ans.push_back(a);
       }
      return ans;
    }
};

Auxiliary Space complexity:O(1)
Time Complexity:O(N^2)
*****************************************************************************************************************************************************************
