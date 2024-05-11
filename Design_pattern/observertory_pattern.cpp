/*
定义对象间一对多的依赖关系，当其中“一”即被依赖的对象变化时，
“多”个依赖它的对象随之自动被通知并更新。
稳定点： 一对多的依赖关系，自动变化
变化点： “多”个依赖对象的变化，比如增多或减少相应值
*/

/*
1. 面向接口
2. 接口隔离
*/


#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Display {
public:
    virtual void show() = 0;
    virtual ~Display(){}; // 继承存在，析构函数最好为虚函数
};

class Display1: public Display {
public:
    virtual void show() {
        cout << "Display1 show" << endl;
    }

private:
    void decr();
};

class Display2: public Display {
public:
    virtual void show() {
        cout << "Display2 show" << endl;
    }

private:
    void incr();

};

class DataCenter {
public:
    void Attach(Display* p) {
        q.push_back(p);
    }

    void Detach(Display *p) {
        q.remove(p);
    }

    void Notify() {
        for (auto &it : q) {
            it->show();
        }
    }    

private:
    list<Display*> q;
};


int main() {
    DataCenter* center = new DataCenter();

    Display* p1 = new Display1();
    Display* p2 = new Display2();

    center->Attach(p1);
    center->Notify();

    center->Attach(p2);
    center->Notify();

    center->Detach(p1);
    center->Notify();

    return 0;
}