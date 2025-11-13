#include <iostream>
#include <cmath>

using namespace std;

class GeoShape
{
    float Dim1;
    float Dim2;

public:
    GeoShape()
    {
        Dim1 = Dim2 = 0;
        cout << "\nGeoShape Parameter less constructor" << endl;
    }

    GeoShape(float d)
    {
        Dim1 = Dim2 = d;
        cout << "\nGeoShape One parameter constructor" << endl;
    }

    GeoShape(float d1, float d2)
    {
        Dim1 = d1;
        Dim2 = d2;
        cout << "\nGeoShape Two parameters constructor" << endl;
    }

    ~GeoShape()
    {
        cout << "\nGeoShape destructor is called." << endl;
    }

    void SetDim1(float d) { Dim1 = d; }
    void SetDim2(float d) { Dim2 = d; }

    float GetDim1() { return Dim1; }
    float GetDim2() { return Dim2; }

    virtual float CalcArea()
    {
        cout << "\nGeoShape CalcArea (Base) called" << endl;
        return 0;
    }
};

// =====================================================
// =============== Rectangle Class ======================
// =====================================================
class Rectangle : public GeoShape
{
public:
    Rectangle() : GeoShape()
    {
        cout << "\nRectangle Parameter less constructor" << endl;
    }

    Rectangle(float w, float h) : GeoShape(w, h)
    {
        cout << "\nRectangle Two parameters constructor" << endl;
    }

    ~Rectangle()
    {
        cout << "\nRectangle destructor is called." << endl;
    }

    float CalcArea()
    {
        cout << "\nRectangle CalcArea called" << endl;
        return GetDim1() * GetDim2();
    }
};

// =====================================================
// ================= Square Class =======================
// =====================================================
class Square : protected GeoShape
{
public:
    Square() : GeoShape()
    {
        cout << "\nSquare Parameter less constructor" << endl;
    }

    Square(float s) : GeoShape(s)
    {
        cout << "\nSquare One parameter constructor" << endl;
    }

    ~Square()
    {
        cout << "\nSquare destructor is called." << endl;
    }

    void set_Dim (float d){
        SetDim1 (d);
        SetDim2 (d);
    }

    float CalcArea()
    {
        cout << "\nSquare CalcArea called" << endl;
        return GetDim1() * GetDim2();
    }
};

// =====================================================
// ================= Circle Class =======================
// =====================================================
class Circle : protected GeoShape
{
public:
    Circle() : GeoShape()
    {
        cout << "\nCircle Parameter less constructor" << endl;
    }

    Circle(float r) : GeoShape(r)
    {
        cout << "\nCircle One parameter constructor" << endl;
    }

    ~Circle()
    {
        cout << "\nCircle destructor is called." << endl;
    }

    void set_Rad (float r){
        SetDim1 (r);
        SetDim2 (r);
    }

    float CalcArea()
    {
        cout << "\nCircle CalcArea called" << endl;
        ///float r = GetDim1();
        return 3.14159f * GetDim1() * GetDim1();
    }
};

// =====================================================
// ================= Triangle Class =====================
// =====================================================
class Triangle : public GeoShape
{
public:
    Triangle() : GeoShape()
    {
        cout << "\nTriangle Parameter less constructor" << endl;
    }

    Triangle(float b, float h) : GeoShape(b, h)
    {
        cout << "\nTriangle Two parameters constructor" << endl;
    }

    ~Triangle()
    {
        cout << "\nTriangle destructor is called." << endl;
    }

    float CalcArea()
    {
        cout << "\nTriangle CalcArea called" << endl;
        return 0.5f * GetDim1() * GetDim2();
    }
};

// =====================================================
// ================= Main Function ======================
// =====================================================
int main()
{
    cout << "\n--- Creating Shapes ---" << endl;

    Rectangle R1(5, 10);
    cout << "\nRectangle Area = " << R1.CalcArea() << endl;

    Square S1(7);
    ///S1.SetDim1(9); /// not accessable
    ///S1.set_Dim (9, 10);
    cout << "\nSquare Area = " << S1.CalcArea() << endl;

    Circle C1(4);
    cout << "\nCircle Area = " << C1.CalcArea() << endl;

    Triangle T1(6, 8);
    cout << "\nTriangle Area = " << T1.CalcArea() << endl;

    cout << "\n--- End of Program ---" << endl;

    return 0;
}
