/* quick sort */
#include<iostream>
using namespace std;

//create a function called swap to swap the elements
void swap(int *a,int *b){
	int t= *a;
	*a= *b;
	*b= t;
}

//declare an array, start index as start, last index as last
//declare partition index as pIndex and initiate it from start
//create a function called partition-take the last element as pivot,use a for loop to compare arr[i] and pivot.
int partition(int arr[],int start,int end){
	int pivot=arr[end];
	int pIndex=start;
//if arr[i]>pivot-do nothing , else swap between them and  increment the pIndex by 1
	for(int i=start;i<end;i++){
		if(arr[i]<pivot){
			swap(&arr[i],&arr[pIndex]);
			pIndex++;
		}
	}
//return the pIndex of pivot after partition 
	swap(&arr[pIndex],&arr[end]);
	return pIndex;
}

//create a function called quicksort and call the partition function in it,USE RECURSION
void quicksort(int arr[],int start,int end){
	if(start<end){
		int pi=partition(arr,start,end);
		quicksort(arr,start,pi-1);
		quicksort(arr,pi+1,end);
	}
}

//display the array
void print(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<",";
	}
	cout<<endl;
}


//drive the main
int main(){
	int arr[]={9,5,10,3,6,7,14};
	int n=sizeof(arr)/sizeof(arr[0]);
	//int n=6;
	//partition(arr,0,n);
	quicksort(arr,0,n);
	cout<<"sorted array: "<<endl;
	print(arr,n);
}
