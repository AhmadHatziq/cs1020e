#include <iostream>
using namespace std;

class BankAcct {

private:
    int _acctNum;
    double _balance;

public:
    BankAcct( int aNum )
    {
        _acctNum = aNum;
        _balance = 0;
    }

    BankAcct( int aNum, double amt )
        : _acctNum(aNum), _balance(amt)
    {
    }

    int withdraw( double amount )
    {
        if (_balance < amount) return 0;
        _balance -= amount;
        return 1;
    }

    void deposit( double amount )
    {
        _balance += amount;
    }

    void print()
    {
        cout << "Acct No: " << _acctNum << endl;
        cout << "Balance: $" << _balance << endl;
    }
};


int main()
{
    BankAcct ba1( 1234 );  // balance = 0.0
    BankAcct ba2( 1235, 500.00 );

    if ( ba1.withdraw( 500.00 ) == false )
        cout << "Insufficient fund. Cannot withdraw!\n";

    ba1.deposit( 750.00 );
    ba1.print();

    ba2.deposit( 1000.00 );
    ba2.print();

    return 0;
}
