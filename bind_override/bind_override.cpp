#include <iostream>
#include <functional>

class Base
{
    public:
        virtual ~Base() {}
        virtual void f1() const {std::cout<<"Base::f1() called"<<std::endl;}
        virtual void f1(int) const {std::cout<<"Base::f1(int) called"<<std::endl;}
        virtual void f2() const {std::cout<<"Base::f2() called"<<std::endl;}
};

class Derived : public Base
{
    public:
        virtual ~Derived() {}
        using  Base::f1; // this is a must
        void f1() const {std::cout<<"Derived::f1() called"<<std::endl;}
};

int main()
{
    Base base;
    Derived derived;
    auto func1 = std::bind(static_cast<void(Base::*)()const>(&Base::f1), std::cref(base));
    func1();
    auto func2 = std::bind(static_cast<void(Derived::*)()const>(&Derived::f1), std::cref(derived));
    func2();
    auto func3 = std::bind(&Base::f2, std::cref(base));
    func3();
    auto func4 = std::bind(&Derived::f2, std::cref(derived));
    func4();
    auto func5 = std::bind(static_cast<void(Base::*)(int)const>(&Base::f1), std::cref(base), std::placeholders::_1);
    func5(1);
    auto func6 = std::bind(static_cast<void(Derived::*)(int)const>(&Derived::f1), std::cref(derived), std::placeholders::_1);
    func6(2);
    return 0;
}

