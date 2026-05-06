class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        for(int i=0; i<nums.size();i++){
            int number = nums[i];
            if(hashmap.count(number)){
                return true;
            }
            hashmap[number] = 1;
        }
        return false;
    }
};