#include <iostream>

using namespace std;

class RGB {
public:
    bool checkCorrect() {
        if (((this->redData >= 0) && (this->redData <= 255)) &&
            ((this->greenData >= 0) && (this->greenData <= 255)) &&
            ((this->blueData >= 0) && (this->blueData <= 255))) {
            return true;
        }
        return false;
    }
    int getRed() {
        return this->redData;
    }
    int getGreen() {
        return this->greenData;
    }
    int getBlue() {
        return this->blueData;
    }
    bool setRed(int value) {
        this->redData = value;
        return true;
    }
    bool setGreen(int value) {
        this->greenData = value;
        return true;
    }
    bool setBlue(int value) {
        this->blueData = value;
        return true;
    }
    bool operator == (RGB otherRGB) {
        if ((this->redData == otherRGB.getRed()) &&
            (this->greenData == otherRGB.getGreen()) &&
            (this->blueData == otherRGB.getBlue())) {
            return true;
        }
        return false;
    }
    bool operator != (RGB otherRGB) {
        if ((this->redData == otherRGB.getRed()) &&
            (this->greenData == otherRGB.getGreen()) &&
            (this->blueData == otherRGB.getBlue())) {
            return false;
        }
        return true;
    }
private:
    int redData = 0;
    int greenData = 0;
    int blueData = 0;
};

istream& operator >> (istream& input, RGB& otherRGB) //Ввод
{
    int r;
    int g;
    int b;
    input >> r;
    input >> g;
    input >> b;
    otherRGB.setRed(r);
    otherRGB.setGreen(g);
    otherRGB.setBlue(b);
    return input;
}
ostream& operator << (ostream& out, RGB& otherRGB) //Вывод
{
    out << "Red: " << otherRGB.getRed() << "\n";
    out << "Green: " << otherRGB.getGreen() << "\n";
    out << "Blue: " << otherRGB.getBlue() << endl;
    return out;
}