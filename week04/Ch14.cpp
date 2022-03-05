#include <iostream>

class M{
    public:
        virtual void pvf() = 0;
};

class B1 : public M{
    public:
        virtual void vf() {std::cout << "B1::vf()" << std::endl;}
        void pvf() override {std::cout << "B1::pvf()" << std::endl;}
        void f() {std::cout << "B1::f()" << std::endl;}
};

class D1 : public B1{
    public:
        void vf() override {std::cout << "D1::vf()" << std::endl;}
        void pvf() override {std::cout << "D1::pvf()" << std::endl;}
        void f() {std::cout << "D1::f()" << std::endl;}
};

class D2 : public D1{
    public:
        void pvf() override {std::cout << "D2::pvf()" << std::endl;}
};

class B2{
    public:
        virtual void pvf() = 0;
};

class D21 : public B2{
    public:
        std::string str = "string";
        void pvf() override {std::cout << str << std::endl;}
};

class D22 : public D21{
    public:
        int i = 123;
        void pvf() override {std::cout << i << std::endl;}
    };

void f(B2& b2){
    b2.pvf();
}

int main(){
    B1 b1;
    b1.vf();
    b1.f();
    b1.pvf();
    std::cout << std::endl;

    D1 d1;
    d1.vf();
    d1.pvf();
    d1.f();
    std::cout << std::endl;

    B1& b1r = d1;
    b1r.vf();
    b1r.f();
    b1r.pvf();
    std::cout << std::endl;

    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();
    std::cout << std::endl;
    
    D21 d21;
    D22 d22;
    f(d21);
    f(d22);
    
    return 0;
}