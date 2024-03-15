#include <iostream>
using namespace std;
void bubblesort(int arr[] , int n){
	int i , j , tmp;
	for(i=0 ; i< n - 1 ; i++){
		for(j = 0 ; j < n - i - 1; j ++ ){
			if (arr[j] > arr[j + 1]){
				tmp = arr[j];
				arr[j]= arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main(){
	int array[10], n, i , j;
	cout<<"masuk banyak element: ";
	cin>>n;
	cout<<"masukkan nilai: \n";
	for(i = 0 ; i< n; i++){
		cin>>array[i];
	}
	bubblesort(array , n);
		cout<<"hasil algrima bubble: \n";
		for(i = 0 ; i< n ; i++){
			cout<<array [i];
		}
		cout<<" \n";
		return 0 ;
}
