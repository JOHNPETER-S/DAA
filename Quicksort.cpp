#include <iostream>
using namespace std;
int partition(int arr[], int start, int end) {
    int pivot = arr[end];  // Pivot element
    int i = start - 1;     // Index of smaller element
    
    // Loop from 'start' to 'end - 1'
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;  // Increment the index of smaller element
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Swap the pivot element to the correct position
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    
    return i;  // Return the pivot index
}


void Quicksort(int arr[], int start, int end) {
    if (end <= start) return;  // Base case: if the subarray has 1 or 0 elements, it's already sorted
    int pivot = partition(arr, start, end);  // Get the pivot index after partitioning
    Quicksort(arr, start, pivot - 1);  // Recursively sort the left subarray
    Quicksort(arr, pivot + 1, end);    // Recursively sort the right subarray
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    // Input the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Call QuickSort on the entire array
    Quicksort(arr, 0, n - 1);
    
    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
