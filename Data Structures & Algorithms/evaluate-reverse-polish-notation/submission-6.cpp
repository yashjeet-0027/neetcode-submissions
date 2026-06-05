class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        float ans;
        if(tokens.size()==1) return stoi(tokens[0]);
        for(auto & el : tokens){
            if(el == "*"){
                ans = st.top();
                st.pop();
                ans *= st.top();
                st.pop();
                st.push(ans);
            }
            else if(el == "-"){
                ans = -1*st.top();
                st.pop();
                ans += st.top();
                st.pop();
                st.push(ans);
            }
            else if(el == "+"){
                ans = st.top();
                st.pop();
                ans += st.top();
                st.pop();
                st.push(ans);
            }
            else if(el == "/"){
                ans = (float)1/st.top();
                st.pop();
                ans *= st.top();
                st.pop();
                st.push(ans);
            }

            else{ // number hi hoga fir to
                int x = stoi(el);
                st.push(x);
            } 
        }
        return ans;
    }
};
