#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;

class queue{
	private:
		int front ,rear , count ;
		int arr[MAX];
		
	public:
		queue(){
			front = 0;
			rear = MAX -1;
			count = 0;
		}
		void enqueue(int x){
			if (count >= MAX ){
				cout<<"queue is full...."<<endl;
				return;
			}
			rear = (rear + 1) % MAX;
			arr[rear ] = x;
			count++;
		}
		int dequeue(){
			if (count <= 0 ){
				cout<<"queue is empty...."<<endl;
				return -1;
			}
			int x = arr[front];
			front = (front +1) % MAX;
			count--;
			return x;
		}
		int peek(){
			if (count <= 0 ){
				cout<<"queue is empty..."<<endl;
				return -1;
			}
			return arr[front];
		}
		int size (){
			return count;
			
		}
		bool isEmpty(){
			return count == 0;
		}
		bool isFull(){
			return count == MAX;
		}
};


int main(){
	queue q;
	q.enqueue(1);
	q.enqueue(4);
	q.enqueue(5);
	cout<<"queue size:\t"<<q.size()<<endl;
	cout<<"first element:\t"<<q.peek()<<endl;
	cout<<"second element:\t"<<q.peek()<<endl;
	cout<<"exit element:\t"<<q.dequeue()<<endl;
	cout<<"first element:\t"<<q.peek()<<endl;
	cout<<"queue size:\t"<<q.size()<<endl;
	return 0;
}



