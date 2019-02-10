/* Stacks using Arrays (Name for class: StackArr)(push, pop, size, isEmpty, top)
Queues using Arrays (Name for class: QueueArr)(enqueue, dequeue, size, isEmpty, top)
*/

#include<iostream>
using namespace std;
#define MAX 5

//declare the class named StackArr
class StackArr{
	public:
	//declare the array and the top variable
	int arr[MAX];
	int top;

	//constructor
	StackArr(){
		top=-1;
	}

	//declare the isEmpty function
	bool isEmpty(){
		if(top==-1){
			
			return true;
		}
		else{
			
			return false;
		}
	}

	//declare the push function
	void push(int value){
		if(top>MAX){
			cout<<"stack is full!!"<<endl;
		}
		else{
			top++;
			arr[top]=value;
		}
	}

	//declare the pop function
	void pop(){
		if(top<0){
			cout<<"stack is empty!!!"<<endl;
			
		}
		else{
			int x=arr[top--];
			
		}
	}

	//declare the show-top function
	void show_top(){
		if(isEmpty()){
			cout<<"stack is empty.."<<endl;
		}
		else{
			cout<<"the top element is "<<arr[top]<<endl;
		}
	}

	//declare the display function
	void display(){
		if(isEmpty()){
			cout<<"stack is empty.."<<endl;
		}
		else{
			for(int i=0;i<=top;i++){
				cout<<arr[i]<<",";
			}
		}
		cout<<endl;
	}
};

//declare a class named QueueArr
class QueueArr{
	public:
	//declare the array,front and rear
	int arr[MAX];
	int front,rear;
	//constructor
	QueueArr(){
		front=-1;
		rear=-1;
	}

	//declare a function named isEmpty
	bool isEmpty(){
		if(front==-1 and rear==-1){
			return true;
		}
		else{
			return false;
		}
	}

	//declare a function named enqueue
	void enqueue(int value){
		if(rear==MAX-1){
			cout<<"queue is full..."<<endl;
		}
		else{
			if(front==-1){
				front=0;
			}
			rear++;
			arr[rear]=value;
		}
	}

	//declare a function named dequeue
	void dequeue(){
		if(front==-1 and rear==-1){
			cout<<"queue is empty..";
		}
		else{
			if(front==rear){
				front=rear=-1;
			}
			else{
				front++;
			}
		}
	}

	//declare a function named frontshow
	void frontshow(){
		if(isEmpty()){
			cout<<"queue is empty.."<<endl;
		}
		else{
			cout<<"the front element is: "<<arr[front]<<endl;
		}
	}

	//declare a display function
	void display(){
		if(isEmpty()){
			cout<<"queue is empty!!";
		}
		else{
			for(int i=front;i<=rear;i++){
				cout<<arr[i]<<",";
			}
		}
		cout<<endl;
	}
};

//drive the main 
int main(){
		StackArr l1;
		l1.push(1);
		l1.push(2);
		l1.push(3);
		l1.push(4);
		l1.push(5);
		l1.display();
		l1.show_top();

		l1.pop();
		l1.display();
		l1.show_top();

	/*	QueueArr l2;
		l2.enqueue(1);
		l2.enqueue(2);
		l2.enqueue(3);
		l2.enqueue(4);
		l2.enqueue(5);
		l2.display();
		l2.dequeue();
		l2.display();
		l2.frontshow(); */
		
	}		


