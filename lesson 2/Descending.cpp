#include <iostream>
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
        // If current element is greater than the pivot for descending order
        if (arr[j] > pivot) {
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

// Function to display the elements of an array
void show(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    cout << "\nArray before sorting: ";
    show(arr, size);
    quicksort(arr, 0, size - 1);
    cout << "\nArray after sorting in descending order: ";
    show(arr, size);
    return 0;
}

