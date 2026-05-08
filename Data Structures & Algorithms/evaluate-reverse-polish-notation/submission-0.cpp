class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;
        for(int i=0; i<tokens.size(); i++){
            const string& c = tokens[i];
            if(c=="+"){
                int a=stk.top(); stk.pop();
                int b=stk.top(); stk.pop();
                stk.push(b+a);
            } else if(c=="-"){ //abc...
                int a=stk.top(); stk.pop();
                int b=stk.top(); stk.pop();
                stk.push(b-a);
            }else if(c=="*"){
                int a=stk.top(); stk.pop();
                int b=stk.top(); stk.pop();
                stk.push(b*a);
            }else if(c=="/"){//abc...
                int a=stk.top(); stk.pop();
                int b=stk.top(); stk.pop();
                stk.push(b/a);
            } else {
                stk.push(stoi(c));
            }
        }
        return stk.top();
        //time: O(n) one run | space ???? 
    }
};
