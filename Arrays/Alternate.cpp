class Solution {
  public:
    vector<int> getAlternates(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return arr;

        int index = 0;
        // Directly overwrite the array in-place to avoid extra allocations
        for (int i = 0; i < n; i += 2) {
            arr[index++] = arr[i];
        }

        // Shrink the vector to drop the remaining unused trailing elements
        arr.resize(index);
        return arr;
    }
};
