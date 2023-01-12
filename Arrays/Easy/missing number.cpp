class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]==i){
                i++;
            }
            else{
                int count=0;
                while(nums[i]!=i && count<nums.size()-i){
                    if(nums[i] == nums.size())
                        swap(nums[i],nums[nums[i]-1]);
                    else
                        swap(nums[i],nums[nums[i]]);
                    count++;
                }
                i++;   
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] != i) return i;
        }
        return nums.size();
    }
};
