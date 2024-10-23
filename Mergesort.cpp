#include <iostream>
using namespace std;

void merge(int leftArr[], int leftSize, int rightArr[], int rightSize, int arr[]) {
    int i = 0, l = 0, r = 0;
    while (l < leftSize && r < rightSize) {
        if (leftArr[l] < rightArr[r]) {
            arr[i] = leftArr[l];
            l++;
        } else {
            arr[i] = rightArr[r];
            r++;
        }
        i++;
    }
    
    // Copy remaining elements of leftArr, if any
    while (l < leftSize) {
        arr[i] = leftArr[l];
        l++;
        i++;
    }
    
    // Copy remaining elements of rightArr, if any
    while (r < rightSize) {
        arr[i] = rightArr[r];
        r++;
        i++;
    }
}

void mergesort(int arr[], int n) {
    if (n < 2) return; // Base case: array is already sorted if it has 1 or 0 elements
    
    int middle = n / 2;
    
    // Create left and right subarrays
    int leftArr[middle];
    int rightArr[n - middle];
    
    // Fill the left and right subarrays
    for (int i = 0; i < middle; i++) {
        leftArr[i] = arr[i];
    }
    for (int i = middle; i < n; i++) {
        rightArr[i - middle] = arr[i];
    }
    
    // Recursively sort the left and right subarrays
    mergesort(leftArr, middle);
    mergesort(rightArr, n - middle);
    
    // Merge the two sorted halves
    merge(leftArr, middle, rightArr, n - middle, arr);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    // Input the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Call mergesort on the entire array
    mergesort(arr, n);
    
    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
