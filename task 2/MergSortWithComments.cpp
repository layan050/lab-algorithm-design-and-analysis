#include <iostream>
using namespace std;

// Merge two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int x, y, z; // Variables for iteration
    int n1 = m - l + 1; // Size of left subarray
    int n2 = r - m; // Size of right subarray

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (x = 0; x < n1; x++) {
        L[x] = arr[l + x];
    }
    for (y = 0; y < n2; y++) {
        R[y] = arr[m + 1 + y];
    }

    // Merge the temporary arrays back into arr[l..r]
    x = 0; // Initial index of left subarray
    y = 0; // Initial index of right subarray
    z = l; // Initial index of merged subarray
    while (x < n1 && y < n2) {
        if (L[x] <= R[y]) {
            arr[z] = L[x];
            x++;
        } else {
            arr[z] = R[y];
            y++;
        }
        z++;
    }

    // Copy the remaining elements of L[], if any
    while (x < n1) {
        arr[z] = L[x];
        x++;
        z++;
    }

    // Copy the remaining elements of R[], if any
    while (y < n2) {
        arr[z] = R[y];
        y++;
        z++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Calculate mid point
        mergeSort(arr, l, m); // Sort first half
        mergeSort(arr, m + 1, r); // Sort second half
        merge(arr, l, m, r); // Merge the sorted halves
    }
}

// Function to print an array
void show(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
}

int main() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;
    int arr[size];
    // Input array elements
    for (int i = 0; i < size; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    mergeSort(arr, 0, size - 1); // Perform merge sort
    cout << "\nSorted array:\n";
    show(arr, size); // Print sorted array
    return 0;
}

