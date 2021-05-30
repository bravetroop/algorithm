#include <iostream>

using namespace std;

class A {
public:
    A() : m_iVal(0) { test(); }
    void test() { func(); }
    virtual void func() { cout << "A::m_iVal=" << m_iVal << " "; }
//private:
protected:
    int m_iVal;
};

class B : public A {
public:
    B() { test(); }
    void func() {
        ++m_iVal;
        cout << "B::m_iVal=" << m_iVal << " ";
    }
};

int main()
{
    A* p = new B;
    p->func();
    return 0;
}