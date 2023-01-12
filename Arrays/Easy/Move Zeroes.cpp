class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1) return;
        if(nums.size()==2){
            if(nums[0]==0 && nums[1]==1) swap(nums[0],nums[1]);
            return;
        }
        int i=0,j=0;
        while(i<nums.size() && j<nums.size()){
            if(nums[j]==0){
                j++;
            } 
            else if(nums[j]!=0 && nums[i]==0){
                swap(nums[j],nums[i]);
                i++;
            } else{
                i++;
                j++;
            }
        }
    }
};
