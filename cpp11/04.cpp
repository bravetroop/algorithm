#include <iostream>

using namespace std;

class A {
public:
    virtual void func(int val = 1) {
        cout << "A->" << val << endl;
    }
    virtual void test() { func(); }
};

class B : public A {
public:
    void func(int val = 0) {
        cout << "B->" << val << endl;
    }
};

int main()
{
    B* pb= new B;
    pb->test();

    A* pa = pb;
    pa->test();
    return 0;
}