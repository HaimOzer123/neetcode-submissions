class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string dummy = strs[0];

        for(int i=0;i<strs.size();i++){
            while(strs[i].find(dummy) != 0){
                dummy.pop_back();
                if(dummy.empty()) return "";
            }
        }
        return dummy;
    }
};