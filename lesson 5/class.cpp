#include <iostream>
using namespace std;

class karyawan {
	private:
		int gaji;
	public:
		void setgaji(int s){
			gaji = s;
		}
		int getgaji(){
			return gaji;
			
		}
};

int main (){
	karyawan myobj;
	myobj.setgaji(50000);
	cout<<myobj.getgaji();
}
