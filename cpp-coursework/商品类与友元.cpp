#include <iostream>
#include <string>
using namespace std;

class Product{
	string name;
	double price;
public:
	static int count;
	Product(string n="",double p=0.0):name(n),price(p){
		count++;
	}
	~Product(){
		count--;
	}
	void show()const{
		cout<<"Name:"<<name<<" "<<"Price:"<<price<<endl;
	}
	static int getCount(){
		return count;
	}
	friend bool expensive(Product&p1,Product&p2){
		return p1.price>p2.price;
	}
};
    int Product::count=0;

int main(){
	Product a("声卡",4000); 
	Product b("麦克风",1000);
	Product c("耳机",800);
	Product abc[3]={a,b,c};
	for(int i=0;i<3;i++){
		abc[i].show();}
	Product::getCount() ;
	expensive(a,b);
	cout<<"Product a is more expensive."<<endl;
	return 0;
	
	
}
