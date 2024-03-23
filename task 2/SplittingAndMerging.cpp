#include <iostream>
using namespace std;

void merge(int arr[], int left, int middle, int right) {
    int left_size = middle - left + 1;
    int right_size = right - middle;

    int left_arr[left_size];
    int right_arr[right_size];

    for (int i = 0; i < left_size; i++) {
        left_arr[i] = arr[left + i];
    }

    for (int j = 0; j < right_size; j++) {
        right_arr[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    cout << "Splitting list: ";
    for (int l = left; l <= right; l++) {
        cout << arr[l] << " ";
    }
    cout << endl;

    while (i < left_size && j < right_size) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

    cout << "Merging list: ";
    for (int l = left; l <= right; l++) {
        cout << arr[l] << " ";
    }
    cout << endl;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    int arr[] = {2, 5, 60, 43, 27, 10, 89, 17};
	cout<<"The list: ";
    for (int i = 0 ; i < 8 ; i++){
    	cout<<arr[i]<<" ";
	}
	
	cout<<endl;
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted list: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

