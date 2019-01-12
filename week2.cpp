/* Implement Singly Linked List using C++. Make sure the following functions: 
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

class node{
	public:
	//data
	int data;
	//pointer that points to the next
	node * next;
	//constructer that points to null
	node(){
		next=NULL;
	}
};

class LinkedList{
	public:
	//declare head and tail
	node * head;
	node * tail;

	//construct
	LinkedList(){
		head=NULL;
		tail=NULL;
	}

	//insert
	void insert(int value){
		//if 1st node is added
		node * temp=new node;
		//insert the value to it
		temp->data=value;
		//for 1st node
		if(head==NULL)
		{
			head=temp;
		}
		//for any other nodes
		else
		{
			tail->next=temp;
		}
		tail=temp;
	}

	//insert at any position
	void insertAt(int pos,int value){
		//reach the place before pos
		node * current = head;
		int i=1;
		while(i<pos-1){
			current=current->next;
		}

		//create a node
		node * temp = new node;
		temp->data=value;

		//move the pointer
		temp->next=current->next;
		current->next=temp;
	}	

	//delete the element at the end of the list
	void delet(){
		//store the tail in the temp
		node * temp=tail;
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

	//delete the element or node at the position or pos
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

	//return the number of items in the linked list
	int countItems(){
		//store head in temp
		node * temp=head;	
		//initialize the length
		int l=0;
		//until temp is null increase length by 1
		while(temp!=NULL){
			l++;
			temp=temp->next;
		}
		cout<<l;
	}

	//display all the numbers in the linked list
	void display(){
		//store head in current
		node * current = head;
		//until current is NULL print current->data
		while(current!=NULL){
			cout<<current->data<<"->";
			current	= current->next;
		}
		cout<<",";
	}
};

int main()
{
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.display();
	l1.countItems();
	l1.deletAt(2);
	l1.display();
	l1.countItems();
	l1.delet();
	l1.display();
	return 0;
}
