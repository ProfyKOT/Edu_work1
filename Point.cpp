#include <iostream>

using namespace std;

class Equation {
public:
    int getY(int x) {
        return x ^ 2;
    }
};


class Point {
public:
    Point(int x,int y) {
        this->x = x;
        this->y = y;
    }
    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }
    int setX(int x) {
        this->x = x;
        return this->x;
    }
    int setY(int x) {
        this->y = y;
        return this->y;
    }
    int compare(Equation Equation) {
        if (Equation.getY(this->x) > this->y) {
            return -1;
        }else if (Equation.getY(this->x) < this->y) {
            return 1;
        }
        else if (Equation.getY(this->x) == this->y) {
            return 0;
        }
    }
    int getQuarter() {
        if (this->y > 0) {
            if (this->x > 0) {
                return 1;
            }
            else if (this->x < 0) {
                return 2;
            }
            else {
                return -1;
            }
        }else if (this->y < 0) {
            if (this->x > 0) {
                return 3;
            }
            else if (this->x < 0) {
                return 4;
            }
            else {
                return -1;
            }
        }else {
            return -1;
        }
    }
    bool operator == (Point otherPoint)
    {
        if ((this->getX() == otherPoint.getX()) && (this->getY() == otherPoint.getY())) {
            return true;
        }
        return false;
    }
    bool operator != (Point otherPoint)
    {
        if ((this->getX() == otherPoint.getX()) && (this->getY() == otherPoint.getY())) {
            return false;
        }
        return true;
    }

private:
    int x, y;
};


istream& operator >> (istream& input, Point& otherPoint) //Ввод
{
    int x;
    int y;
    input >> x;
    input >> y;
    otherPoint.setX(x);
    otherPoint.setY(y);
    return input;
}
ostream& operator << (ostream& out, Point& otherPoint) //Вывод
{
    out << "Y: " << otherPoint.getY() << "\n";
    out << "X: " << otherPoint.getX() << endl;
    return out;
}
