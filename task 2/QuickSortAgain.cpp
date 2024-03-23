#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
		
		cout << "[";
        for (int i = 0; i < 10; i++) {
        	cout << arr[i] << " ";
    	}
    	cout << "]";
    	cout << endl;

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[100];
	
	cout << "Input ten elements: ";
	for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
	
	system("cls"); // Assuming this was used to clear the screen

    cout << "Data to be sorted: ";
    for (int i = 0; i < 10; i++) {
       	cout << arr[i] << " ";
    }
    cout << endl << endl;

    cout << "Quick Sort: " << endl;
    quickSort(arr, 0, 10 - 1);

    return 0;
}




