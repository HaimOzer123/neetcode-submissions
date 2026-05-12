class Solution {
public:
    int scoreOfString(string s) {
        if(s.empty())return 0;
        int res = 0;
        for(int i = 0; i < s.size() - 1; i++){
            res += abs(s[i] - s[i+1]);
        }
        return res;
    }
};