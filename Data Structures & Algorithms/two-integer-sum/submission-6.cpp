class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hashMap;
        for (int i=0;i< nums.size();i++){
            int wanted = target - nums[i];
            if(hashMap.count(wanted)){
                return{hashMap[wanted],i};
            }
            hashMap.insert({nums[i],i}); //val,key
        }
        return {};
    }
};
