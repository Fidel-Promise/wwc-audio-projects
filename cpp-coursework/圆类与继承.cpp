#include<iostream>
using namespace std;
class Shape{
	private:
		std::string color;
		
	public:
		Shape(const std::string&c = "red"){
			color=c;
		}
		void setColor(const std::string&c){
			color=c;
		}
		std::string getColor()const{
			return color;
		}
		void printInfo()const{
			cout<<"Color:"<<color;
		}
}; 

class Circle:public Shape{
	private:
		double radius;
		
	public:
		Circle(const std::string&c, double r){
			setColor(c);
			radius=r;
		}
		double getArea()const{
			return 3.14*radius*radius;
		}
		void printCircleInfo()const{
		Shape::printInfo();
		cout<<"Radius:"<<radius<<",Area:"<<getArea()<<endl;
		}
};

int main(){
	Circle c1("blue",5.0);
	c1.printCircleInfo();
	Shape*sp = &c1;
	(*sp).printInfo();
	//*sp.getArea();编译错误 
}
