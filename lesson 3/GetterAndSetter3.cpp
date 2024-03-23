#include <iostream>
using namespace std;

class student{
	private:
		string studentname;
		int studentNPM;
	public:
		void setstudentname (string n ){
			studentname = n ;
		}
		void setstudentNPM(int p){
			studentNPM = p;
		}
		string getstudentname(){
			return studentname;
		}
		int getstudentNPM(){
			return studentNPM;
		}
};
int main(){
	student mystudent;
	string name;
	int number;
	cout<<"\nENTER STUDENT NAME: ";
	getline(cin , name);
	mystudent.setstudentname(name);
	
	cout<<"\nENTER STUDENT NPM: ";
	cin>>number;
	mystudent.setstudentNPM(number);
	
	cout<<"\nSTUDENT DATA: \n";
	cout<<"\nstudent name: "<<mystudent.getstudentname()<< endl;
	cout<<"student NPM:  "<<mystudent.getstudentNPM()<<endl;
	return 0;
}
