#include <bits/stdc++.h>
using namespace std;
void wrongPass()
{
    cout << "Password didn't match" << endl;
}
class BankAccount
{
protected:
    int balance;

private:
    string password;

public:
    string account_holder;
    string address;
    int age;
    int account_number;
    BankAccount(string account_holder, string address, int age, string password)
    {
        this->balance = 0;
        this->account_holder = account_holder;
        this->address = address;
        this->age = age;
        this->password = password;
        srand(time(0));
        this->account_number = rand() % 900000 + 100000;
        cout << "Your account no is " << this->account_number << endl;
    }
    int show_balance(string password)
    {
        if (this->password == password)
            return this->balance;
        else
            wrongPass();
    }
    void add_money(string password, int amount)
    {
        if (amount < 0)
        {
            cout << "Invalid amount" << endl;
            return;
        }
        // if (this->balance < amount)
        // {
        //     cout << "Insufficient Balance!" << endl;
        //     return;
        // }
        if (this->password == password)
        {
            this->balance += amount;
            cout << "Add money successful" << endl;
        }
        else
            wrongPass();
    }
    void withdraw_money(string password, int amount)
    {
        if (this->password == password)
        {
            if (this->balance >= amount)
            {
                this->balance -= amount;
                cout << "Withdraw money successful" << endl;
            }
            else
                cout << "Insufficient Fund!" << endl;
        }
        else
            wrongPass();
    }
    friend class MyCash;
};

class MyCash
{
protected:
    int balance;

public:
    MyCash()
    {
        this->balance = 0;
    }
    void add_money_from_bank(BankAccount *myAccount, string password, int amount)
    {
        if (amount < 0)
        {
            cout << "Invalid Amount!" << endl;
            return;
        }
        if (myAccount->balance < amount)
        {
            cout << "Insufficient Balance!" << endl;
            return;
        }
        if (myAccount->password == password)
        {
            this->balance += amount;
            myAccount->balance -= amount;
            cout << "Add money from bank is successful" << endl;
        }
        else
            wrongPass();
    }
    int show_balance()
    {

        return this->balance;
    }
};

BankAccount *create_account()
{
    string account_holder, password, address;
    int age;
    cout << "CREATE ACCOUNT" << endl;
    cin >> account_holder >> address >> age >> password;
    BankAccount *myAccount = new BankAccount(account_holder, address, age, password);
    return myAccount;
}

void add_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "ADD MONEY" << endl;
    cin >> password >> amount;
    myAccount->add_money(password, amount);
    cout << "Your bank balance is " << myAccount->show_balance("abc") << endl;
}

void withdraw_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "WITHDRAW MONEY" << endl;
    cin >> password >> amount;
    myAccount->withdraw_money(password, amount);
    cout << "Your bank balance is " << myAccount->show_balance("abc") << endl;
}

void add_money_from_bank(MyCash *myCash, BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "ADD MONEY FROM BANK" << endl;
    cin >> password >> amount;
    myCash->add_money_from_bank(myAccount, password, amount);
    cout << "Your bank balance is " << myAccount->show_balance("abc") << endl;
    cout << "Your MyCash balance is " << myCash->show_balance() << endl;
}

int main()
{

    BankAccount *myAccount = create_account();
    MyCash *myCash = new MyCash();

    while (1)
    {

        cout << "1. Add Money to Bank" << endl;
        cout << "2. Withdraw Money from Bank" << endl;
        cout << "3. Add Money to MyCash from Bank" << endl;
        cout << "Select option: " << endl;
        int option;
        cin >> option;
        if (option == 0)
            break;

        if (option == 1)
            add_money(myAccount);
        else if (option == 2)
            withdraw_money(myAccount);
        else
            add_money_from_bank(myCash, myAccount);
    }

    // add_money(myAccount);
    // withdraw_money(myAccount);
    // add_money_from_bank(myCash, myAccount);

    return 0;
}