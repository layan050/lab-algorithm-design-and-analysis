#include<iostream>
using namespace std;

// Function to swap two elements in an array
void swap(int arr[], int pos1, int pos2) {
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

// Function to partition the array and return the index of the pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of smaller element
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(arr, i, j); // Swap arr[i] and arr[j]
        }
    }
    swap(arr, i + 1, high); // Swap arr[i+1] and arr[high] (pivot)
    return i + 1; // Return the index of pivot
}

// Function to perform QuickSort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the index of pivot element
        int pi = partition(arr, low, high);
        // Recursively sort elements before and after the pivot
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: ";
    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Perform QuickSort
    quicksort(arr, 0, n - 1);
    // Output sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    return 0;
}

