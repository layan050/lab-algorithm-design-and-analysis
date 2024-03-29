#include <iostream>
#include <string>

using namespace std;

class info{
	private : 
	string a,b;
	int c;
	
	public :
		info (string nama, string alamat, int usia):a(nama),b(alamat),c(usia){
			cout<< "informasi biodata anda:\n ";
		}
		~info(){
			
		}
			  void data (){
			  	cout << "nama : " << a << endl << "umur : " << c << endl << "alamat : " << b <<endl; 
			  }
		 
		
};
int main (){
int z;
string y,x;
cout << "masukan nama anda: ";
getline(cin,y);
cout << "masukan usia anda: ";
cin >> z;
cout << "masukan alamat anda: ";
cin.ignore();
getline (cin,x);
{
	info obj(y,x,z);
	obj.data();
}
return 0;
}
