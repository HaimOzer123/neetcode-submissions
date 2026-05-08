class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numsMap;
        for(int i=0;i<nums.size();i++){
            int c = target - nums[i];
            if (numsMap.count(c)){
                return{numsMap[c],i};
            }
            numsMap.insert({nums[i],i});
        }
        return{};
    }
};
