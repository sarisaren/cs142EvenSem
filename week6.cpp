/* binary tree - insert,search and display */

#include<iostream>
using namespace std;

//create a node that has pointer that points to left and right
class node{
	public:
		int data;
		node * left;
		node * right;
	//construct
		node(int value){
			left=NULL;
			right=NULL;
			data=value;
		}
};

//create a class named BST which has functions insert,search and display
class BST{
	public:
//declare root and construct
		node * root;
		BST(){
			root=NULL;
		}

//function insert1 - uses insert2 function
		void insert1(int value){
			insert2(root,value);
		}

//function insert2
	//parameters are node * curr and int value
		void insert2(node * curr,int value){
	//if curr is NULL then create a new node and declare it as root
			if(curr==NULL){
				root=new node(value);
			}
	//else if value < curr->data then call insert2(curr->left,value)
			else if(value<curr->data){
				if(curr->left==NULL){
					curr->left=new node(value);
				}
				else{
					insert2(curr->left,value);
				}
			}
	//else call insert2(curr->right,value)
			else{
				if(curr->right==NULL){
					curr->right=new node(value);
				}
				else{
					insert2(curr->right,value);
				}
			}
		}

//function search1 - uses search2 function
		node * search1(int value){
			search2(root,value);
		}

//function search2
		node * search2(node * curr,int value){
	//if value found or reach NULL then return curr
			if(curr==NULL || curr->data==value){
				return curr;
			}
	//if value < curr->data then move left and call search2(curr->left,value)
			else if(value < curr->data){
				return search2(curr->left,value);
			}
	//else move right and call searcch2(curr->right,value)
			else{
				return search2(curr->right,value);
			}
		}

//function display1 -uses display2 function
		void display1(){
			display2(root);
		}
//function display2
		void display2(node * curr){
	//base condition
			if(curr==NULL)return;
	//display left
			display2(curr->left);
	//display curr
			cout<<curr->data<<",";
	//display right
			display2(curr->right);
		}
};

int main(){
	BST b1;
	b1.insert1(19);
	b1.insert1(12);
	b1.insert1(32);
	b1.insert1(14);
	b1.insert1(28);

	b1.display1();

	//b1.search1(78);

	if(b1.search1(78954)!=NULL){
		cout<<"FOUND!!!"<<endl;
	}
	else{
		cout<<"NOT FOUND, SORRY.."<<endl;
	}
}
