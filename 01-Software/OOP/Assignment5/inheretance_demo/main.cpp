#include <iostream>
using namespace std;

class Base {
private:
    int x;
protected:
    int y;
public:
    Base() {
        x = y = 0;
        cout << "Base constructor parameterless" << endl;
    }
    Base(int n) {
        x = y = n;
        cout << "Base constructor one parameter" << endl;
    }
    Base(int n1, int n2) {
        x = n1; y = n2;
        cout << "Base constructor two parameters" << endl;
    }
    virtual ~Base() {
        cout << "Base destructor is called" << endl;
    }

    void stex(int _x) { x = _x; }
    int getx() { return x; }
    void stey(int _y) { y = _y; }
    int gety() { return y; }

    int SUM() { return x + y; }
};

class Derived : public Base {
private:
    int z;
public:
    Derived() : Base() {
        z = 0;
        cout << "Derived constructor parameterless" << endl;
    }
    Derived(int n1) : Base(n1) {
        z = 0;
        cout << "Derived constructor one parameter" << endl;
    }
    Derived(int n1, int n2) : Base(n1, n2) {
        z = 0;
        cout << "Derived constructor two parameters" << endl;
    }
    Derived(int n1, int n2, int n3) : Base(n1, n2) {
        z = n3;
        cout << "Derived constructor three parameters" << endl;
    }
    ~Derived() {
        cout << "Derived destructor is called" << endl;
    }

    void set_x(int n1) { stex(n1); }
    int get_x() { return getx(); }

    void set_y(int n2) { y = n2; }
    int get_y() { return y; }

    void set_z(int n3) { z = n3; }
    int get_z() { return z; }

    int SUM() { return getx() + y + z; }
};

class Derived_Junior : public Derived {
private:
    int m;
public:
    Derived_Junior() : Derived() {
        m = 0;
        cout << "Derived_Junior constructor parameterless" << endl;
    }
    Derived_Junior(int n1) : Derived(n1) {
        m = 0;
        cout << "Derived_Junior constructor one parameter" << endl;
    }
    Derived_Junior(int n1, int n2) : Derived(n1, n2) {
        m = 0;
        cout << "Derived_Junior constructor two parameters" << endl;
    }
    Derived_Junior(int n1, int n2, int n3) : Derived(n1, n2, n3) {
        m = 0;
        cout << "Derived_Junior constructor three parameters" << endl;
    }
    Derived_Junior(int n1, int n2, int n3, int n4) : Derived(n1, n2, n3) {
        m = n4;
        cout << "Derived_Junior constructor four parameters" << endl;
    }
    ~Derived_Junior() {
        cout << "Derived_Junior destructor is called" << endl;
    }

    void set_x(int n1) { stex(n1); }
    int get_x() { return getx(); }

    void set_y(int n2) { Derived::set_y(n2); }
    int get_y() { return Derived::get_y(); }

    void set_z(int n3) { Derived::set_z(n3); }
    int get_z() { return Derived::get_z(); }

    void set_m(int n4) { m = n4; }
    int get_m() { return m; }

    int SUM() { return getx() + get_y() + get_z() + m; }
};

int main() {
    Derived_Junior obj(1, 2, 3, 4);
    cout << "SUM = " << obj.SUM() << endl;
    return 0;
}
