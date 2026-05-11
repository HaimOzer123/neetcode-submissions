class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string,vector<string>> hashMap;

        for(const auto& s:strs){
            string sorts = s;
            sort(sorts.begin(),sorts.end());    
            hashMap[sorts].push_back(s);
        }
        vector<vector<string>> res;
        for(auto& pair:hashMap){
            res.push_back(pair.second);
        }
        return res;
    }
};
