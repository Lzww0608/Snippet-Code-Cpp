/*
定义一系列算法，并把它们封装起来，使得它们互相直接可替换。可以使得算法独立于客户程序而变化。
稳定点：算法与客户程序之间的关系
变化点：算法的变化
策略模式可以消除过多的条件判断if-else语句，也就是解耦合
*/

/*
1. 接口隔离
2. 依赖注入（通过一个接口解决两个类之间的依赖）
3. 面向接口编程
4. 开闭原则
*/

#include <iostream>
using namespace std;

class Context {

};

class ProStrategy {
public:
    virtual void calPro(const Context& ctx) = 0;
    virtual ~ProStrategy(){};
};

class VAC_Method1: public ProStrategy {
public:
    virtual void calPro(const Context& ctx) override {
        cout << "calPro: Method1" << endl;
    }
};

class VAC_Method2: public ProStrategy {
public:
    virtual void calPro(const Context& ctx) override {
        cout << "calPro: Method2" << endl;
    }
};

class Promotion {
public:
    void attach(ProStrategy* p) {
        s = p;
    }

    void calPro() {
        if (s != nullptr)
            s->calPro(ctx);
    }

private:
    Context ctx;
    ProStrategy *s;
};


int main() {
    ProStrategy *p1 = new VAC_Method1();
    ProStrategy *p2 = new VAC_Method2();

    Promotion *obj = new Promotion();
    obj->attach(p1);
    obj->calPro();

    obj->attach(p2);
    obj->calPro();

    return 0;
}