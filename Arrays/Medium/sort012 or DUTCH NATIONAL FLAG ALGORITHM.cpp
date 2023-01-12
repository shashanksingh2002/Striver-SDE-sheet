
/*
SIMPLE LOGIC EVERYTHING BEFORE I IS 0 AND EVERYTHING BEFORE K IS 2 SO WHENEVER J ENCOUNTERS 0  SWAP WITH I AND IF ENCOUNTERED WITH 2 SWAP WITH K
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1;
        while(j<=k){
            if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[j]==2){
                swap(nums[j],nums[k]);
                k--;
            }
            else j++;
        }
    }
};
