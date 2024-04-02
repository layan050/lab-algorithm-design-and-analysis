#include <iostream>
using namespace std;

void insertionSort(int arr[], int num) {
    int i, j, temp;
    for (i = 1; i < num; i++) {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int i, j, temp, num;
    int arr[] = {12, 11, 13, 5, 6};
    num = sizeof(arr) / sizeof(arr[0]);
    
    
 	cout<<"\nunsorted elements:";
 	for (i = 0 ; i <arr[i]; i++){
 		cout<<arr[i]<<" ";
	 }
	 
	 
    insertionSort(arr, num);
   

    cout << "\nSorted elements: ";
    for (i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

