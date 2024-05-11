/*
定义一个算法的操作骨架，而将具体实现的某些步骤放到子类中，
这样可以在不改变算法结构的基础上，重新定义算法的某些步骤。
稳定点：算法的骨架
变化点：算法的具体实现流程
*/

/*
1. 单一职责
2. 依赖倒置
3. 开闭原则
4. 最小知道
5. 接口隔离
*/


#include <iostream>
using namespace std;

class Structure {
public:
    void show() {
        show0();
        show1();
        show2();
    }


// 开放关闭原则：对子类开放，对其他类封闭
private:
    virtual void show0() {
        cout << "Structure show0()" << endl;
    }

    virtual void show1() {
        cout << "Structure show1()" << endl;
    }

    virtual void show2() {
        cout << "Structure show2()" << endl;
    }

};

class Implementation1: public Structure {

public:
    virtual void show0() override {
        cout << "Implementation1 show0()" << endl;
    }

    virtual void show1() override {
        cout << "Implementation1 show1()" << endl;
    }
};

class Implementation2: public Structure {

public:
    virtual void show0() override {
        cout << "Implementation2 show0()" << endl;
    }

    virtual void show2() override {
        cout << "Implementation2 show1()" << endl;
    }
};




int main() {
    Structure *p1 = new Implementation1();
    Structure *p2 = new Implementation2();
    p1->show();
    p2->show();
    return 0;
}
