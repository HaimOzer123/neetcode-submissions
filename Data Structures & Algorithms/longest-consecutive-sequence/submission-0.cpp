class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0; //check if empty
        sort(nums.begin(),nums.end());

        int res=0, current = nums[0],streak=0,i=0;
        while(i<nums.size()){
            if (current != nums[i]){
                current = nums[i];
                streak =0;
            }
            while(i<nums.size() && nums[i] == current){
                i++;
            }
            streak++;
            current++;
            res = max(res,streak);
        }
        return res;

    }
};
