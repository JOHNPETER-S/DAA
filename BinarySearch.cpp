#include <iostream>
using namespace std;

int binarySort(int arr[], int target, int end) {
    int start = 0;
    while (start <= end) {
        int mid = start + (end - start) / 2; // Calculate mid at each iteration
        
        if (arr[mid] == target) {
            return mid; // Return the index where the target is found
        } else if (arr[mid] < target) {
            start = mid + 1; // Move to the right half
        } else {
            end = mid - 1; // Move to the left half
        }
    }
    return -1; // Target not found
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target;
    cin >> target;
    
    // Perform binary search
    int result = binarySort(arr, target, n - 1);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
    
    return 0;
}
