#include <iostream>
using namespace std;
//insertion sort
int main(){
	int i , j , temp , num;
	int arr[30];
	cout<<"Enter the number of elements: ";
	cin>>num;
	
	for (i = 0 ; i < num ; i++){
		cout<<"Enter elements " <<i + 1<<" :";
		cin>>arr[i];
	}
	for(int i = 1; i<=num - 1;i++){
		temp=arr[i];
		j=i-1;
		
		while((temp<arr[j]) &&(j>=0) ){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j + 1] = temp;

	cout << "Processing element: ";
        for (j = 0; j < num; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;				

	}
	cout<<"\nsorted elemets: ";
	for(i = 0 ; i <num ; i++){
		cout<<arr[i]<<" ";
	}

}


