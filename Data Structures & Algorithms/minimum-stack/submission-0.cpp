class MinStack {
public:
    vector<int> st;
    vector<int> min_el;
    MinStack() {}
    
    void push(int val) {
        st.push_back(val);
        if(min_el.empty()) min_el.push_back(val);
        else if(min_el.back() > val) min_el.push_back(val);
        else if(min_el.back() <= val) min_el.push_back(min_el.back());
    }
    
    void pop() {
        st.pop_back();
        min_el.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return min_el.back();
    }
};
