/* Stacks using Linked List (Name for class: StackLL) (push, pop, size, isEmpty, top)
Queues using Linked List (Name for class: QueueLL) (enqueue, dequeue, size, isEmpty, top)
*/

#include<iostream>
using namespace std;

//create a class named node
class node{
	public:
	//data
	int data;
	//pointer that points to next
	node * next;
	//construct
	node(){
		next=NULL;
	}
};

//create a class named LL
class LL{
	public:
	//declare head and tail
	node * head;
	node * tail;
	//constructor where head and tail both points to NULL
	LL(){
		head=NULL;
		tail=NULL;
	}

	//create a function called insertFirst
	void insertFirst(int value){
		node * temp=new node;
		temp->data=value;
		if(head==NULL){
			head=temp;
		}
		else{
			temp->next=head;
			head=temp;
		}
	}

	//create a function called deletFirst
	int deletFirst(){
		node * temp=head;
		head=temp->next;
		int x=temp->data;
		return x;
		delete temp;
	}

	//create a function called deletLast
	/*void deletLast(){
		if(head==NULL and tail==NULL){
			cout<<"queue is empty...";
		}
		else{
			node * temp=tail;
			node * current=head;
			while(current->next!=tail){
				current=current->next;
			}
			current->next=NULL;
			tail=current;
			delete temp;
		}
	} */

//delete the element at the end of the list
	void delet(){
		//store the tail in the temp
		node * temp=tail;
		node * curr=head;
		while(curr->next!=NULL){
			curr=curr->next;
		}
		tail=curr;
		//the box before tail has to point null
		node * current = head;
		while(current->next!=tail){
			current=current->next;
		}
		current->next=NULL;
		//update tail
		tail=current;
		//delete temp
		delete temp;
	}


	//create a funnction called topdisplay to display the top element
	void top_display(){
		cout<<"the top element is "<<head->data;
		cout<<","<<endl;
	}

	//create a function called countItems
	int countItems(){
		node * current=head;
		int l=0;
		while(current!=NULL){
			l++;
			current=current->next;
		}
		cout<<l;
	}

	//create a display function
	void display(){
		node * current=head;
		while(current!=NULL){
			cout<<current->data<<"->";
			current=current->next;
		}
		cout<<",";
	}
};

//create a class named StackLL
class StackLL{
	public:
	//declare top
	node * top;
	LL l1;
	//construct
	StackLL(){
		top=NULL;
	}
	//pushes on top
	void push(int x){
		l1.insertFirst(x);
		top=l1.head;
	}

	//pops on top
	int pop(){
		int popped=l1.deletFirst();
		top=l1.head;
		return popped;
	}

	//size function
	int size(){
		return l1.countItems();
	}

	//isEmpty function
	bool isEmpty(){
		if(top==NULL){
			return true;
		}
		else{
			return false;
		}
	}

	//top_show shows the top element
	int top_show(){
		l1.top_display();
	}

	//display
	void display(){
		l1.display();
	}
};

//create a class named QueueLL
class QueueLL{
	public:
	//declare front and end
	node * front;
	node * end;
	LL l2;
	//construct
	QueueLL(){
		front=NULL;
		end=NULL;
	}
	//enqueue function-enters on front
	void enqueue(int y){
		l2.insertFirst(y);
		front=l2.head;
		//front=l2.tail;
	}

	//dequeue function-deletes on end
	void dequeue(){
		l2.delet();
		
		end=l2.tail;
	}

	//size function
	int size(){
		return l2.countItems();
	}

	//isEmpty function
	bool isEmpty(){
		if(front==NULL and end==NULL){
			return true;
		}
		else{
			return false;
		}
	}

	//show_top finction-shows the top element
	int show_top(){
		l2.top_display();
	}

	//display	
	void display(){
		l2.display();
	}
};
/*
//drive the main
int main(){
	StackLL s1;
	
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.display();
	s1.pop();
	s1.display(); 

	QueueLL s2;

	s2.enqueue(1);
	s2.enqueue(2);
	s2.enqueue(3);
	s2.enqueue(4);
	s2.enqueue(5);
	s2.enqueue(6);
	s2.display();
	//s2.isEmpty();
	s2.dequeue();
	s2.display();
	s2.dequeue();
	s2.display();
	/*s2.size();
	s2.show_top();*/

