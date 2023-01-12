class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        int count=0,sum=0;
        unordered_map<int,int> umap;
        umap[0]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int search = sum-target;
            if(umap.find(search)!=umap.end()){
                count += umap[search];
                umap[sum]++;
            }
            else{
                umap[sum]++;
            }
        }
        return count;
    }
};
