#include <iostream>
using namespace std;

class car{
	private:
		string brand;
		int year , door;
	public:
		void setInfo(string b, int y , int  d){
			brand = b ;
			year = y ;
			door = d;
		}
		 void getInfo(string& b, int& y, int& d){
		 	b = brand;
        	y = year;
        	d = door;
		}
};

int main(){
	car mycar;
	string brand;
	int year , door;
	cout<<"Enter Car's Brand : ";
	cin>>brand;
	cout<<"Enter Car's Production Year : ";
	cin>>year;
	cout<<"Enter Door Total : ";
	cin>>door;
	cout<<"\nCar Information\n"<<endl;
	mycar.setInfo(brand , year , door);
	mycar.getInfo(brand , year , door);
	cout<<"Brand : "<<brand<<endl;
	cout<<"Production Year : "<<year<<endl;
	cout<<"Total Doors : "<<door<<endl;
	
}

