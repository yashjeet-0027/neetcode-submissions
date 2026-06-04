class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        // () -> 1
        // [] -> 2
        // {} -> 3
        for(auto &el : s){
            if(el=='(') st.push(1);
            if(el==')'){
                if(!st.empty() && st.top()==1) st.pop();
                else return false;
            }
            if(el=='[') st.push(2);
            if(el==']'){
                if(!st.empty() && st.top()==2) st.pop();
                else return false;
            }
            if(el=='{') st.push(3);
            if(el=='}'){
                if(!st.empty() && st.top()==3) st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
