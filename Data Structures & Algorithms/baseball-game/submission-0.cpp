class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        int res = 0;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                score.push_back(score.back() + score[score.size() - 2]);
            }
            else if (operations[i] == "D") {
                score.push_back(score.back() * 2);
            }
            else if (operations[i] == "C") {
                score.pop_back();
            }
            else {
                score.push_back(stoi(operations[i]));
            }
        }

        for (int x : score) {
            res += x;
        }

        return res;
    }
};