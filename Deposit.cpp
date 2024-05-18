#include <iostream>

using namespace std;

class Deposit {
public:
    Deposit(int bet,int term,int currentVal) {
        this->bet = bet;
        this->term = term;
        this->currentVal = currentVal;
    }
    int getVal() {
        return this->currentVal;
    }
    int getBet() {
        return this->bet;
    }
    int getTerm() {
        return this->term;
    }
    int calculateSalary() {
        return (this->currentVal + (this->currentVal * this->bet / 100) * this->term);
    }
    int operator + (int value) {
        this->currentVal += value;
        return this->currentVal;
    }
    int operator - (int value) {
        this->currentVal - value;
        return this->currentVal;
    }


private:
    int bet = 0;
    int term = 0;
    int currentVal = 0;
};

ostream& operator << (ostream& out, Deposit& otherDeposit) //Вывод
{
    out << "Current amount: " << otherDeposit.getVal() << "\n";
    out << "Bet: " << otherDeposit.getBet() << "\n";
    out << "Term: " << otherDeposit.getTerm() << "\n";
    out << "Total amount: " << otherDeposit.calculateSalary() << endl;
    return out;
}