#include <iostream>
using namespace std;
void swap(int arr[],int i , int j){
	int tmp = arr[i];
	arr[i]=arr[j];
	arr[j]=tmp;
}
void bubblesort(int arr[],int n  ){
	for(int i = 0; i < n ; i++){
		cout<<arr[i]<<" ";
		
	}
	cout<<" \n";
}
int main(){
	int i , arr[3] , j , temp;
	cout<<"x = ";
	for(i = 0 ; i < 4 ; i++){
		cin>>arr[i];
	}
	for(i=0 ; i< 4 ; i++){
		for(j = 0 ; j<4 -i - 1;j++){
			if(arr[j]>arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				}
		}
		cout<<"tahap: "<<i+1<<" : ";
		for(j = 0 ; j < 4; j++){
			cout<<arr[j]<<" ";
			
		}
		cout<<endl;
		
	}
	cout<<"\n hasil : ";
	for(j = 0 ; j <4 ; j++){
		cout<<arr[j]<<" ";
	}
	cout<<endl;
	return 0 ;

}

