class Solution { 
public: 
    // Custom comparator to sort items by value-to-weight ratio in descending order
    static bool compare(pair<int, int>& a, pair<int, int>& b){ 
        double r1 = (double)a.first / a.second; 
        double r2 = (double)b.first / b.second; 
        return r1 > r2; 
    } 

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) { 
        int n = val.size();
        vector<pair<int, int>> items(n);

        // Combine values and weights into pairs: {value, weight}
        for(int i = 0; i < n; i++) {
            items[i] = {val[i], wt[i]};
        }

        // Sort items based on their value/weight ratio
        sort(items.begin(), items.end(), compare); 

        double maxVal = 0.0; // Must be double to store fractional values

        for(int i = 0; i < n; i++) {
            int currentVal = items[i].first;
            int currentWt = items[i].second;

            if(currentWt <= capacity) { 
                maxVal += currentVal; 
                capacity -= currentWt; 
            } else { 
                // Take the fractional part of the remaining capacity
                maxVal += ((double)currentVal / currentWt) * capacity; 
                break; 
            } 
        } 
        return maxVal; 
    } 
};
