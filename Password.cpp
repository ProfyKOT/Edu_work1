#include <iostream>

using namespace std;

class Password {
public:
    string getPass() {
        return this->pass;
    }
    string setPass(string value) {
        this->pass = value;
        return this->pass;
    }
    int checkSecurity() {
        if (this->pass.length() < 6) {
            return -1;
        }else if (this->pass.length() < 10) {
            return 0;
        }
        else if (this->pass.length() < 20) {
            return 1;
        }
    }
    bool operator == (Password otherPassword) {
        if (this->pass == otherPassword.getPass()) {
            return true;
        }
        return false;
    }
    bool operator != (Password otherPassword) {
        if (this->pass != otherPassword.getPass()) {
            return true;
        }
        return false;
    }
private:
    string pass = "";
};
