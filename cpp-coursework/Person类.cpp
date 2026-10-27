#include<iostream>
#include<cstring>
using namespace std;

class Person{
private:
	char* name;
	int age;
public:
	Person(char* str,int a){
		age=a;
		name=new char[strlen(str)+1];
		strcpy(name,str);
	}
	Person(const Person&p){
		age=p.age;
		name=new char[strlen(p.name)+1];
		strcpy(name,p.name);
	}
	~Person(){
		delete[]name;
	}
	void print(){
		cout<<name<<","<<age<<endl;
	}
	void Setname(char* t){
		name=new char[strlen(t)+1];
		strcpy(name,t);
	}}; 

int main(){
	Person p1("Alice",20);
	Person p2=p1;
	p1.Setname("Bob");
	p1.print();
	p2.print();
	
	return 0;
}
