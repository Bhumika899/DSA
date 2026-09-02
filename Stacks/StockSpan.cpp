class StockSpanner {
private:
    // Store pairs of {price, span}
    std::stack<std::pair<int, int>> st; 

public:
    StockSpanner() {
        // Constructor can be left empty
    }
    
    int next(int price) {
        int span = 1;
        
        // Pop elements while the current price is greater than or equal to the stack's top price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; 
            st.pop();
        }
        
        // Push the current price and its calculated span onto the stack
        st.push({price, span});
        
        return span;
    }
};
