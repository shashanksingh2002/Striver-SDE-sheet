class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]==nums[j]) j++;
            else{
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};
