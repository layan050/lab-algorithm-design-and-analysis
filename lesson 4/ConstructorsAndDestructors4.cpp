#include <iostream>
using namespace std;

class example{
	private:
		int score;
	public:
		example(int n){
			score = n;
		}
		int getNum(){
			return score;
		}
};

int main(){
	example obj(10);
	cout<<"Input Score: "<<obj.getNum()<<endl;
	return 0 ;
}
