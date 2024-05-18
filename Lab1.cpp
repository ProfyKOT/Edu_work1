#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Deposit.cpp"
#include "Matrix.cpp"
#include "Password.cpp"
#include "Point.cpp"
#include "RGB.cpp"
#include "Time.cpp"
#include "Timer.cpp"

using namespace std;



int main()
{
    Deposit dep(6.10, 4, 450000);
    std::cout << dep;

    Timer tq;
    tq.start();
    system("pause");
    tq.stop();
    tq.save();
    cout << tq << endl;

    Time o{ 3,1,5 };
    Time t{ 3,2,12 };
    Time r = (o + t);
    //cin >> r;
    r.changeFormat();
    std::cout << r;

    Point op{ 3,9 };
    Point tp{ 3,2 };
    Equation e;

    std::cout << (op.compare(e));


    int** mat;

    mat = new int* [3];


    for (int i = 0; i < 3; i++) {
        mat[i] = new int[3];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = 2;
            cout << mat[i][j];
        }
        cout << endl;
    }
    Matrix om{ mat,3 };
    Matrix tm{ mat,3 };

    om += tm;
    Matrix s = om + tm;
    
    cout << "Enter the matrix:" << endl;

    cin >> s;

    std::cout << s;

    //std::cout << o.getMatrix()[0][0];
}