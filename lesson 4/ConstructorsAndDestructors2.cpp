#include<iostream>
using namespace std;

class Laptop{
	private:
		string owner;
		string brand;
	public:
		Laptop (string var1 , string var2){
			owner = var1;
			brand = var2;
			cout<<"package Laptop "<<brand<<" Owner "<<owner<<"\nit has been send."<<endl;
			
		}
};

int main(){
	Laptop laptopSomeone("Someone","Asus");
	Laptop laptopRIMA("Rima","Aceer");
	Laptop laptopLayan("Layan","Lenovo");
	
	return 0;
	
}
