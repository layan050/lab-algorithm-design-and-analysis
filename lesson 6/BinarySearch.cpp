#include <iostream>
#include <algorithm>
using namespace std;
/*To apply Binary Search algorithm:
The data structure must be sorted.
Access to any element of the data structure takes constant time

mid = low + (high - low)/2  
*/
const int n = 100;
int nim[n];

int binarySearch(int x , int l , int r){
	if ( r >= l){
		int mid = l + (r - l )/ 2 ;
		if (nim[mid] == x ){
			return mid;
		}
		if (nim[mid] > x ){
			return binarySearch(x,l ,mid - 1);
		return binarySearch (x, mid +l , r);	
		}
		return -1;
	}
}
int main(){
	int n;
	cout<<"Masukan jumlah mahasiswa ";
	cin>>n;
	cout<<"Masukan NIM mahasisa : "<<endl;
	for(int i =0  ; i <n ;i++){
		cin>>nim[i];
	}
	sort (nim , nim + n);
	int x;
	cout<<"Masukan NIM yang dicari ";
	cin>>x;
	
	int hasil = binarySearch(x ,0, n-1 );
	if(hasil == -1){
		cout<<"NIM tidak ditemukan"<<endl;
	}
	else{
		cout<<"NIM ditemukan indeks "<<hasil<<endl;
	}
	return 0;
}






