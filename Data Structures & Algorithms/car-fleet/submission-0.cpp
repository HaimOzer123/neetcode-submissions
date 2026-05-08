class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<pair<int,int>> pairOfCars;
        for(int i=0;i<position.size();i++){
            pairOfCars.push_back({position[i],speed[i]});
        }
        sort(pairOfCars.rbegin(),pairOfCars.rend());
        std::vector<double> stack;
        for(const auto& p: pairOfCars){
            stack.push_back((double)(target-p.first)/p.second);
            if(stack.size() >=2 && stack.back() <=stack[stack.size()-2]){
                stack.pop_back();
            }
        }
        return stack.size();

    }
};
