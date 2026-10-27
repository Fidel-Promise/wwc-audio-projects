#include<iostream>
using namespace std;

void swap(int &a,int &b){
	int t=a;a=b;b=t;
}
void reverse(int* arr,int n){
   
	for(int i=0;i<n-1;i++){
		int* head=arr+i;
	    int* tail=arr+n-1-i;
	    if(head<tail){
		swap(*(arr+i),*(arr+n-1-i));
		
		}
	}
}

int main(){
  int a[]={1,2,3,4,5};
  reverse(a,5);
  for(int f=0;f<5;f++){
  	cout<<*(a+f)<<" ";
  }
  return 0;
  
  
}
