#include <iostream>

using namespace std;

struct A {
    void foo() { cout << "A::foo "; }
    virtual void bar() { cout << "A::bar "; }
    A() { bar(); }
};

struct B : public A {
    void foo() { cout << "B::foo "; }
    void bar() { cout << "B::bar "; }
};

int main()
{
    A *p = new B;
    p->foo();
    p->bar();
    return 0;
}