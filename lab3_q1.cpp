/* Implement Doubly Linked List using C++. Make sure the following functions are implemented: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 

*/

#include<iostream>
using namespace std;

//create a class named node which contain prev,data and next
class node{
	public:
		//data
		int data;
		//pointer that points to previous and next
		node * prev;
		node * next;
		//constructer that points prev and next to null
		node(){
			prev=NULL;
			next=NULL;
		}
};

//create a class named DLL
class DLL{
	public:
		//declare head and tail
		node * head;
		node * tail;
	
		//construct
		DLL(){
			head=NULL;
			tail=NULL;
		}

		//give a function insert(int data) which adds a new element to the end of the linked list. 
		void insert(int value){
			//if 1st node is added
			node * temp = new node;
			//insert the value to it
			temp->data = value;
			//for 1st node
			if(head==NULL){
				head = temp;
			}
			//for the other nodes
			else{
				tail->next=temp;
				temp->prev=tail;
			}
			tail=temp;
		}

		//give a function insertAt(int pos, int data) which includes the position at which the insertion happens. Positioning starts with 1. 
		void insertAt(int pos , int value){
			//reach the place before pos
			node * current = head;
			int i=1;
			while(i<pos-1){
				current=current->next;
			}
			//create a node
			node * temp=new node;
			temp->data=value;
			//move the pointer
			temp->next=current->next;
			current->next->prev=temp;
			current->next=temp;
			temp->prev=current;
		}
			
			 
		//delete() - Deletes the element at the end of the list. 
		void delet(){
			//store the tail into temp
			node * temp = tail;
			//the box before tail has to point null
			node * current = head;
			while(current->next!=tail){
				current=current->next;
			}
			current->next=NULL;
			temp->prev=NULL;
			//update tail
			tail=current;
			//delete temp
			delete temp;
		}

		//deleteAt(int pos) - Deletes the element(or node) at the position pos)
		void deletAt(int pos){
			//store head into temp1
			node * temp1 = head;
			//if pos=1
			if(pos==1){
				head=temp1->next;
				temp1->next->prev=NULL;
				delete temp1;
				return;
			}
			//if pos not equal to 1 then go to pos-1
			int i;
			for(i=1;i<pos-1;i++){
				temp1=temp1->next;
			}	
			//store pos into temp2
			node * temp2 = temp1->next;
			//store pos+1 into temp1->next
			temp1->next=temp2->next;
			temp2->next->prev=temp1;
			//delete temp2
			delete temp2;
		}

		//countItems() - Returns the number of items in the linked list.
		int countItems(){
			//store head in temp
			node * temp = head;
			//initialize length
			int l=0;
			//until temp is NULL increase length by 1
			while(temp!=NULL){
				l++;
				temp=temp->next;
			}
			cout<<l;
		}

		//display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 
		void display(){
			//store head in current
			node * current = head;
			//until current is NULL print current->data
			while(current!=NULL){
				cout<<current->data<<"->";
				current=current->next;
			}
			cout<<",";
		}
};

//drive the program
int main(){
	DLL l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.display();
	l1.insertAt(2,5);
	l1.display();
	l1.delet();
	l1.display();
	l1.deletAt(2);
	l1.display();
	l1.countItems();
	return 0;
}
