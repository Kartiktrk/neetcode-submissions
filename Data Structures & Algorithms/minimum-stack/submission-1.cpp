class MinStack {
private:
    stack<pair<int,int>> st;
public:
    MinStack() {}
    
    void push(int val) {
        int mini = INT_MAX;
        if( st.empty() ) mini = val;
        else mini = min( st.top().second, val );
        st.push(make_pair(val,mini));
    }
    
    void pop() {
        if(!st.empty()) st.pop(); 
    }
    
    int top() {
         if(!st.empty()) return st.top().first;
         return -1;
    }
    
    int getMin() {
         if(!st.empty()) return st.top().second;
         return -1;
    }
};
