#include <iostream>

using namespace std;

struct A {
    A() { cout << "A's constructor" << endl; }
    void aMethod() { cout << "A's method" << endl; }
};


// -------------------------------------------------
// Without virtual inheritance
// -------------------------------------------------

// struct B : A {
//     B() { cout << "B's constructor" << endl; }
//     void bMethod() { cout << "B's method" << endl; }
// };

// struct C : A {
//     C() { cout << "C's constructor" << endl; }
//     void  cMethod() { cout << "C's method" << endl; }
// };

// struct D : B, C {
//     D() { cout << "D's constructor" << endl; }
//     void  dMethod() { cout << "D's method" << endl; }
// };

// -------------------------------------------------
// With virtual inheritance
// -------------------------------------------------

struct B : virtual A {
    B() { cout << "B's constructor" << endl; }
    void bMethod() { cout << "B's method" << endl; }
};

struct C : virtual A {
    C() { cout << "C's constructor" << endl; }
    void  cMethod() { cout << "C's method" << endl; }
};

struct D : B, C {
    D() { cout << "D's constructor" << endl; }
    void  dMethod() { cout << "D's method" << endl; }
};


int main()
{
    D d;
    // === Without virtual inheritance ===
    // A's constructor
    // B's constructor
    // A's constructor
    // C's constructor
    // D's constructor
    // 
    // === With virtual inheritance ===
    // A's constructor
    // B's constructor
    // C's constructor
    // D's constructor

    // === Without virtual inheritance ===
    // d.aMethod();
    // "D::aMethod" is ambigous -> use what inherited from B->A or C->A?
    d.B::aMethod(); // ok -> A's method
    d.C::aMethod(); // ok -> A's method
    // d.A::aMethod(); // error
    // base class "A" is ambigous -> class A from B->A or C->A?

    // === With virtual inheritance ===
    d.aMethod(); // ok -> A's method
    d.B::aMethod(); // ok -> A's method
    d.C::aMethod(); // ok -> A's method
    d.A::aMethod(); // ok -> A's method

}