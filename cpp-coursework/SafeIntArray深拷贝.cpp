#include<iostream>
using namespace std;
class SafeIntArray{
private:
	int* data;
	int size;
	static int count;
	
public:
	SafeIntArray(int s){
		size=s;
		data=new int[size];
		for(int i=0;i<s;i++){
			data[i]=0;
		}
		count++;
	}
	SafeIntArray(const SafeIntArray&other){
		size=other.size;
		data=new int[size];
		for(int i=0;i<size;i++){
			data[i]=other.data[i];
	}
	count++;
	}
	~SafeIntArray(){
		delete[]data;
		count--;
	}
	SafeIntArray&operator=(const SafeIntArray&other){
		if (this==&other){
		return *this;}
		delete[]data;
		size=other.size;
		data=new int[size];
		for(int i=0;i<size;i++){
			data[i]=other.data[i];
	}
}
	int&operator[](int index){
		return data[index];
	}
	int getSize()const{
		return size;
	}
	static int getCount(){
		return SafeIntArray::count;
	}
};

int SafeIntArray::count=0;

int main(){
	SafeIntArray a(3);
	a[0]=1;
	a[1]=2;
	a[2]=3;
	SafeIntArray b = a;
	SafeIntArray c(3);
	c=a;
	b[0]=10;
	c[0]=20;
	cout<<a[0]<<endl;
	cout<<b[0]<<endl;
	cout<<c[0]<<endl;
	cout<<SafeIntArray::getCount();
	return 0;
}
