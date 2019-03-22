/* binary search tree - II */
#include<iostream>
using namespace std;

//create a node
class node{
	public:
		int data;
		node * left;
		node * right;
		node * parent;
		node(int value){
			left=NULL;
			right=NULL;
			parent=NULL;
			data=value;
		}
};

//create a class named bst
class bst{
	public:
		node * root;
		bst(){
			root=NULL;	
		}

//function insert1
		void insert1(node * curr,int value){
	//if curr==null then curr = new node and root=curr
			if(curr==NULL){
				curr=new node(value);
				if(root==NULL){
					root=curr;
				}
			}
	//if value<curr->data then if curr->left==null - new node else go to curr->left
			else if(value < curr->data){
				if(curr->left==NULL){
					curr->left=new node(value);
					curr->left->parent=curr;
				}
				else{
					insert1(curr->left,value);
				}
			}
	//if value>curr->data then if curr->right==null - new node else go to curr->right
			else{
				if(curr->right==NULL){
					curr->right=new node(value);
					curr->right->parent=curr;
				}
				else{
					insert1(curr->right,value);
				}
			}
		}

//wrapper function insert2
		void insert2(int value){
			insert1(root,value);
		}

//function search1
		node * search1(node * curr,int value){
	//if curr==null or curr->data==value then return curr
			if(curr==NULL || curr->data==value){
				return curr;
			}
	//else if value<curr->data then go to curr->left
			else if(value < curr->data){
				return search1(curr->left,value);
			}
	//else go to curr->right
			else{
				return search1(curr->right,value);
			}
		}

//wrapper search2
		node * search2(int value){
			search1(root,value);
		}

//function display2d
		void print2d(node * curr,int space){
	//base case
			if(curr==NULL){
				return;
			}
	//increase the space
			space=space+5;
	//go to right child
			print2d(curr->right,space);
	//print curr->data after space
			cout<<endl;
			for(int i=5;i<space;i++){
				cout<<" ";
			}
			cout<<curr->data<<endl;
	//go to left child
			print2d(curr->left,space);
		}

//wrapper function display2d(2)
		void display2d(){
			print2d(root,0);
		}
		
//function getMin
		node * getMin(node * curr){
		//	node * curr=root;
	//if curr==null then return
			if(curr==NULL){
				return NULL;
			}
	//else if curr->left==null then return curr->left
			else if(curr->left==NULL){
				return curr;	
			}
	//else go to curr->left
			else{
				 getMin(curr->left);
			}
		}

//function delet
		void delet1(int value){
	//search the value and keep its address in a pointer curr
			node * curr=search2(value);
	//for leaf node
		//if it is a left child then its parent should point towards null and delete the curr
			if(curr->left==NULL and curr->right==NULL){
				curr->parent->left=NULL;
				delete curr;
			}
		//if it is a right child then its parent should point towards null and delete the curr
			else if(curr->left==NULL and curr->right==NULL){
				curr->parent->right=NULL;
				delete curr;
			}

	//for one child
	//if it has right child
			else if(curr->left==NULL){
		//then its parent's right should point to its children
				curr->parent->left=curr->right;
				//curr->right=NULL;
				delete curr;
			}
	//if it has left child
			else if(curr->right==NULL){ 
		//then its parent's left should point to its left
				curr->parent->right=curr->left;
				//curr->left=NULL;
				delete curr;
			}

	//for deleting root
			else if(curr==root){
		//point curr->right with curr1
				node * curr1=curr->right;
		//get the minimum of curr1
		//set the minimum as the root
				node * temp=getMin(curr->right);
				curr->data=temp->data;
		//delete curr1->left
				delete curr1->left;
			}
	//for two child
		//replace right subtree minimum with the curr
			else if(curr->data > curr->parent->data){
				node * temp=getMin(curr->right);
				curr->data=temp->data;
				temp->parent->left=temp->left;
				delete temp;
			}
				
			else if(curr->data < curr->parent->data){
				node * temp=getMin(curr->right);
				curr->data=temp->data;
				temp->parent->left=temp->left;
				delete temp;
			}	
		} 
};

//drive the program
int main(){
	bst b1;
	//node * root=NULL;
	b1.insert2(5);
	b1.insert2(3);
	b1.insert2(7);
	b1.insert2(4);
	b1.insert2(6);
	b1.insert2(9);
	b1.insert2(8);
	b1.insert2(1);
	b1.insert2(2);
	b1.insert2(10);
	b1.insert2(14);
	b1.display2d();

	b1.delet1(7);
	b1.display2d();
//	cout<<b1.root->data<<endl;
//	b1.getMin(b1.search2(b1.root->data));
	return 0;
}
