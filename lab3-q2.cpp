/* Implement Circular Linked List using C++. Make sure the following functions are implemented: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 ” for a linked list holding integers in the order 1,2,3,4. 
*/

#include<iostream>
using namespace std;

//creat a class namesd node which contains data and next
class node{
	public:
		//data
		int data;
		//pointer that points to next
		node * next;
		//constructor that points next to null
		node(){
			next=NULL;
		}
};

//create a class named CSLL
class CSLL{
	public:
		//declare head and tail
		node * head;
		node * tail;
		//construct
		CSLL(){
			head=NULL;
		}	
		//give a function named insert-adds a new element to the end of the linked list
		void insert(int value){
			//if 1st node is added
			node * temp=new node;
			//insert the value to it
			temp->data=value;
			//for 1st node
			if (head==NULL){
				head=temp;
			}
			//for the other nodes
			else{
				tail->next=temp;
			}
			tail=temp;
			tail->next=head;
		}
	
		//give a function named insertAt(int pos, int data) - It includes the position at which the insertion happens
		void insertAt(int pos,int value){
		//reach the place before pos
			node * current = head;
			int i=1;
			while(i<pos-1){
			i++;
			current=current->next;
			}

		//create a node
			node * temp = new node;
			temp->data=value;

		//move the pointer
			temp->next=current->next;
			current->next=temp;
		}	

		//give a function named delete() - Deletes the element at the end of the list. 
		void delet(){
		//store the tail in the temp
			node * temp=tail;
		//the box before tail has to point null
			node * current = head;
			while(current->next!=tail){
				current=current->next;
			}
			current->next->next=NULL;
			current->next=head;
		//update tail
			tail=current;
		//delete temp
			delete temp;
		}

		//give a function named deleteAt(int pos) - Deletes the element(or node) at the position pos)
		void deletAt(int pos){
		//store head in the temp1
			node * temp1 = head;
		//if pos=1
			if(pos==1){
				head=temp1->next;
				delete temp1;
				return;
			}
		//if pos is not equal to 1 then go to pos-1
			int i;
			for(i=1;i<pos-1;i++){
				temp1=temp1->next;
			}
		//store pos node into temp2
			node * temp2 = temp1->next;
		//store pos+1 in temp->next
			temp1->next=temp2->next;
		//delete temp2
			delete temp2;
		}

		//give a function named countItems() - Returns the number of items in the linked list. 
		int countItems(){
		//store head in temp
			node * temp=head;	
		//initialize the length
			int l=1;
		//until temp is null increase length by 1
			while(temp->next!=head){
				l++;
				temp=temp->next;
			}
			cout<<l;
		}
		//give a function named display() - Displays all the elements in the linked list.
		void display(){
			//store the head into current
			node * current = head;
			//print current->data if head is not null
			if(head != NULL){
				while(current->next!=head){
					cout<<current->data<<"->";
					current=current->next;
				}
				cout<<current->data;
				cout<<",";
			}
		}
};

int main(){
	CSLL cll;
	cll.insert(1);
	cll.insert(2);
	cll.insert(3);
	cll.insert(4);
	cll.insert(5);
	cll.display();
	cll.delet();
	cll.display();
	cll.insertAt(3,6);
	cll.display();
	cll.deletAt(3);
	cll.display();
	cll.countItems();
	
}
