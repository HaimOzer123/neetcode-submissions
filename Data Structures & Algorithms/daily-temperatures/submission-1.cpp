class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(),0);
        std::stack<int> stk;
        
        for(int i=0;i<temperatures.size();i++){
            while(!stk.empty() && temperatures[i]>temperatures[stk.top()]){
                int oldi=stk.top();
                stk.pop();

                res[oldi]=i-oldi;
            }
            stk.push(i);
        }
        return res;
    }
};
