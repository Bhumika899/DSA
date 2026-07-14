#include <iostream>
#include <vector>
#include <utility>

// Function returns a pair where:
// first element = Floor value (-1 if not found)
// second element = Ceil value (-1 if not found)
std::pair<int, int> findFloorAndCeil(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int floor = -1;
    int ceil = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return {arr[mid], arr[mid]}; // Target found, floor and ceil are the same
        }
        else if (arr[mid] < target) {
            floor = arr[mid];  // Potential floor candidate
            low = mid + 1;     // Look for a larger valid floor on the right
        }
        else {
            ceil = arr[mid];   // Potential ceil candidate
            high = mid - 1;    // Look for a smaller valid ceil on the left
        }
    }

    return {floor, ceil};
}

int main() {
    std::vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int target = 5;

    std::pair<int, int> result = findFloorAndCeil(arr, target);

    std::cout << "Floor: " << result.first << "\n";
    std::cout << "Ceil: " << result.second << "\n";

    return 0;
}
