#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find k closest integers to X
vector<int> findKClosest(vector<int>& arr, int X, int k) {
    // Step 1: Sort by absolute difference first, and by value if equal differences
    sort(arr.begin(), arr.end(), [X](int a, int b) {
        int diffA = abs(a - X);
        int diffB = abs(b - X);
        if (diffA == diffB)
            return a < b;  // Prefer smaller value if distances are the same
        return diffA < diffB;  // Otherwise, sort by distance
    });
    
    // Step 2: Get the first k elements
    vector<int> result(arr.begin(), arr.begin() + k);
    
    // Step 3: Sort the result in ascending order
    sort(result.begin(), result.end());
    
    return result;
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9};
    int X = 7;
    int k = 3;
    
    vector<int> result = findKClosest(arr, X, k);
    
    // Output the result
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
