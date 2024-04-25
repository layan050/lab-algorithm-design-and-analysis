#include <iostream>
using namespace std;

int main(){
	int nilai [20];
	int posisi [20];
	int i , n , bil , jmlh= 0;
	bool ketemu;
	
	cout<<"Masukan jumlah deret bilangan : ";
	cin>>n;
	cout<<endl;
	
	for (i = 0 ; i< n ; i++){
		cout<<"Nilai Bilangan Ke-"<<i<<"= ";
		cin>>nilai [i];
		
	}
	cout<<"\n\Deret Bilangan : ";
	for (i = 0 ; i < n ; i++ ){
		cout<<nilai[i]<<" ";
	}
	cout<<"\n\nMasukan Bilangan yang akan Dicari : ";
	cin>>bil;
	
	for(int i = 0 ; i <n ;i++ ){
		if (nilai[i] == bil ){
			ketemu = true;// true and false must have only one =
			posisi[jmlh] = i ;
			jmlh++;
		}
	}
	if (ketemu){
		cout<<"Bilangan  "<<bil<<"  ditemukan sebanyak "<<jmlh;
		cout<<"\npada posisi ke = ";
		for (i = 0 ; i<jmlh ; i++){
			cout<<posisi[i]<<" ";
			
		}
		
	}
	else 
		cout<<"Maaf , bilangan "<<bil <<" tidak oditemuklan";
		getchar();
	
}
