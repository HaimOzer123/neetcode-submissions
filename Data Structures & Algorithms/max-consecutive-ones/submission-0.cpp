class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                j++;
                res = max(res,j);
            }else{
                j=0;
            }
        }
        return res;
    }
};