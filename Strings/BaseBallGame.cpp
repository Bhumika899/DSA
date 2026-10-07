class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "C"){
                ans.pop_back();
            }
            else if(operations[i] == "D"){
                int a = 2 * ans[ans.size() - 1];
                ans.push_back(a);
            }
            else if(operations[i] == "+"){
                int a = ans[ans.size() - 1] + ans[ans.size() - 2];
                ans.push_back(a);
            }
            else {
                // This now safely only runs if the operation is a number string
                ans.push_back(stoi(operations[i]));
            }
        }
        
        int sum = 0;
        for(int i = 0; i < ans.size(); i++){
            sum += ans[i];
        }
        
        // Corrected from 'return ans;' to 'return sum;'
        return sum; 
    }
};
