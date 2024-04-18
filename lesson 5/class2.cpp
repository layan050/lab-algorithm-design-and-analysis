#include <iostream>
using namespace std;

class bangunDatar{
	protected:
		int lebar , tinggi;
	public:
		void setvalue(int a , int b){
			lebar = a ;
			tinggi = b ;
		}
};

class persegiPanjang : public bangunDatar{
	public:
		int getvalue(){
			return (lebar * tinggi);
		}
};

class segitiga : public bangunDatar{
	public:
		int getvalue(){
			return (tinggi * lebar)/2;
		}
};


int main (){
persegiPanjang persegi_panjang;
segitiga segi_tiga;
persegi_panjang.setvalue(4 , 5);
segi_tiga . setvalue(10 , 5);
cout<<persegi_panjang.getvalue()<<endl;
cout<<segi_tiga.getvalue()<<endl;
return 0 ;
	
}
