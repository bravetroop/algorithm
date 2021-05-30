/*
 * Copyright: Co., Ltd. 2018-2020. All rights reserved.
 * Description: 
 * Author: 
 * Create: 2021-01-10
 * Notes: 
 * History: 
 */
#include <iostream>

using namespace std;

class B0 {
public:
    virtual void display() {
        cout << "B0::display" << endl;
    }
};

class B1 : public B0 {
public:
    void display() {
        cout << "B1::display" << endl;
    }
};

void func(B0 ptr) {
    ptr.display();
}

int main()
{
    B0 b0;
    B1 b1;

    func(b0);
    func(b1);
    return 0;
}