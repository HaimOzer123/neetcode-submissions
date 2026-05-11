class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        std::vector<int> newNums;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                newNums.push_back(nums[i]);
                k++;
            }
        }
        nums=newNums;
        return k;
    }
};