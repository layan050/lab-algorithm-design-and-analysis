#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
	private :
		string nama;
		int usia;
		float ipk;
	
	public :
		void setNama (string a){
			nama = a;
		}
		string getNama (){
			return nama;
		}
		void setUsia (int b){
			usia = b;
		}
		int getUsia (){
			return usia;
		}
		void setIpk (float c){
			ipk = c;	
		}
		float getIpk (){
			return ipk;
		}
		
};

int main(){
	
	string nama;
	int usia, n;
	float ipk;
	 
	cout << "masukkan jumlah data : ";
	cin >> n;
	
	Mahasiswa *mhs = new Mahasiswa[n];
	
	for (int i = 0; i<n; i++){
		cout << " Masukkan Nama : " << endl;
		cin>>nama;
		cout << "Masukkan Usia : " << endl;
		cin>> usia;
	    cout<< "masukan Ipk : " << endl;
	    cin>> ipk;
		
	    mhs[i].setNama(nama);
	    mhs[i].setUsia(usia);
	    mhs[i].setIpk(ipk);
	   
	}
	for (int i = 0 ; i <n ; i++){
		cout<<"Nama :"<<mhs[i].getNama()<<endl;
	    cout<<"Usia :"<<mhs[i].getUsia()<<endl;
	    cout<<"IPK :"<<mhs[i].getIpk()<<endl;
	}
	    return 0;
}
