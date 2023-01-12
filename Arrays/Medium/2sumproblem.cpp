class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        vector<int> ans(2);
        for(int i=0;i<nums.size();++i){
            int search = target - nums[i];
            if(umap.find(search) != umap.end()){
                ans[0] = umap[search];
                ans[1] = i;
                break;
            }
            else{
                umap[nums[i]] = i;
            }
        }
        return ans;
    }
};
