#include<iostream>
using namespace std;
class IntArray {
    int* data;
    int size;
public:
    IntArray(int s, int v) {
        size = s;
        data = new int[size]; // 动态分配内存，重点观察拷贝行为
        for(int i=0; i<size; i++) data[i] = v;
    }
    ~IntArray() { delete[] data; }
    void set(int idx, int val) { if(idx>=0 && idx<size) data[idx] = val; }
    void print() {
        for(int i=0; i<size; i++) cout << data[i] << " ";
        cout << endl;
    }
};
int main() {
    IntArray a(3, 5);
    IntArray b = a;      // 调用默认拷贝构造函数（浅拷贝）
    a.set(0, 99);        // 修改对象a
    cout << "对象a: "; a.print();
    cout << "对象b: "; b.print(); // 观察b是否受影响
    return 0;
}
