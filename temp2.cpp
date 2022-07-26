#include <iostream>

class Base {
    virtual void method() {std::cout << "Base ";}
public:
    virtual ~Base() {method();}
    void baseMethod() {method();}
};

class A : public Base {
    void method() {std::cout << "A ";}
public:
    ~A() {method();}
};

int main(void) {
    Base* base = new A;
    base->baseMethod();
    delete base;
    return 0;
}