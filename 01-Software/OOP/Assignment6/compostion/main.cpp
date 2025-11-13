#include <iostream>
#include <graphics.h>

using namespace std;

class Point{
    int X;
    int Y;

public:
    Point(){
        X = Y = 0;
        cout << "\n Point Parametrless Ctor" ;
    }

    Point(int N){
        X = Y = N;
        cout << "\n Point One Parameter Ctor" ;
    }

    Point(int N1 , int N2){
        X = N1;
        Y = N2;
        cout << "\n Point Two Parameters Ctor" ;
    }

    ~Point(){
        cout << "\n Point Destructor";
    }

    void setX (int _x) {X = _x;}
    int getX (){return X;}

    void setY (int _y) {X = _y;}
    int getY (){return Y;}
};

class Line {
    Point Start;
    Point End;

public:
    Line() : Start() , End() ///Implicitly do that
    {
        cout << "Line Parameter less constructor";
    }

    Line(int N1, int N2, int N3, int N4) : Start(N1, N2), End(N3, N4){ ///constructor chaining
        cout << "Line Four Parameters Constructor";
//        Start.setX(N1);
//        Start.setY(N2);
//
//        End.setX(N3);
//        End.setY(N4);
    }

    Line (Point P1, Point P2){
        cout << "Line Tow Point Constructor";
        ///Start = P1;
        Start.setX (P1.getX());
        Start.setY (P1.getY());
        End.setX (P1.getX());
        End.setY (P1.getY());
    }

    void Draw(){
        ///setcolor(WHITE);
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }
};

class Rect {
    Point UL;
    Point LR;

public:
    Rect() : UL() , LR() ///Implicitly do that
    {
        cout << "Rect Parameter less constructor";
    }

    Rect(int N1, int N2, int N3, int N4) : UL(N1, N2), LR(N3, N4){ ///constructor chaining
        cout << "Rect Four Parameters Constructor";
//        UL.setX(N1);
//        UL.setY(N2);
//
//        LR.setX(N3);
//        LR.setY(N4);
    }

    Rect (Point P1, Point P2){
        cout << "Rect Tow Point Constructor";
        ///UL = P1;
        UL.setX (P1.getX());
        UL.setY (P1.getY());
        LR.setX (P1.getX());
        LR.setY (P1.getY());
    }

    void Draw(){
        ///setcolor(WHITE);
        Rect(UL.getX(), UL.getY(), LR.getX(), LR.getY());
    }
};

class Circle {
    Point Center;
    int Rad;

public:
    Circle() : Center() ///Implicitly do that
    {
        Rad = 10;
        cout << "Rect Parameter less constructor";
    }

    Circle(int N1, int N2, int N3) : Center(N1, N2){ ///constructor chaining
        cout << "Rect Four Parameters Constructor";
        Rad = N3;
//        Center.setX(N1);
//        Center.setY(N2);
//
//        LR.setX(N3);
//        LR.setY(N4);
    }

    Circle (Point P1, int R){
        cout << "Rect Tow Point Constructor";
        ///Center = P1;
        Center.setX (P1.getX());
        Center.setY (P1.getY());
        Rad = R;
    }

    void Draw(){
        ///setcolor(WHITE);
        circle(Center.getX(), Center.getY(), Rad);
    }
};


int main()
{
    ///cout << "Hello world!" << endl;
    int state = 0;
    initwindow(400, 500); ///Graphics window
    while (1){
        cleardevice();
        Circle C1(50*3,50*3,30*3);
        C1.Draw();
        if (state){
            // Set fill color and pattern
            setfillstyle(SOLID_FILL, YELLOW);
            // Fill the circle (same center as above)
            floodfill(50*3,50*3, WHITE);
            Line L5(50*3, 80*3, 130*3+20, 110*3+20);
            L5.Draw();
            Line L6(130*3+20, 110*3+20, 160*3, 80*3);
            L6.Draw();
        } else{
        Line L5(50*3, 80*3, 130*3, 110*3);
        L5.Draw();
        Line L6(130*3, 110*3, 160*3, 80*3);
        L6.Draw();
        }
        Line L1(50*3, 80*3, 50*3, 110*3);
        L1.Draw();
        Line L2(50*3, 110*3, 70*3, 125*3);
        L2.Draw();
        Line L3(30*3, 125*3, 70*3, 125*3);
        L3.Draw();
        Line L4(30*3, 125*3, 50*3, 110*3);
        L4.Draw();
        Line L7(160*3, 80*3, 190*3, 110*3);
        L7.Draw();
        Line L8(160*3, 80*3, 160*3, 120*3);
        L8.Draw();
        Line L9(190*3, 150*3, 160*3, 120*3);
        L9.Draw();
        Line L10(130*3, 150*3, 160*3, 120*3);
        L10.Draw();
        Line L11(160*3, 70*3, 160*3, 80*3);
        L11.Draw();
        Circle C2(160*3, 60*3, 10*3);
        C2.Draw();
        getch();
        state ^= 1;
    }
    closegraph();

    return 0;
}
