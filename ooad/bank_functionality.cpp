#include<iostream>
#include<string>
using namespace std;

class Account{
    protected:
    long int balance;
    string account_holder;

    public:
    Account(string _name, long int _balance):account_holder(_name), balance(_balance) {}

    void viewBalance(){
        cout<< "\nRemaining Balance: " << balance<<endl;
    }
};
class Bank: public Account{
    protected:
    long int accountId;
    public:
    Bank(string _name, long int _balance, long int id):Account(_name, _balance), accountId(id) {}
    void deposit(int amount){
        balance += amount;
        cout << "\nThe amount is deposited. \nPress 'y' to view balance. ";
    }
    void withdraw(int amount){
        if (balance<amount){
            cout << "Insufficient balance.\nPress 'y' to view balance.";
        }
        else{
            balance -= amount;
            cout << "Valid withdrawal.\nPress 'y' to view balance.";
        }
    }
};
int main(){
    Bank customer("Aayusha", 50000, 45645645);
    char prompt = 'y';
    char view, ch;
    int x, amt;
    while (prompt == 'y'){
        cout << "1. View Balance\n2. Deposit amount\n3. Withdraw amount\n4. Exit\n";
        cin>>x;
        switch(x){
            case 1:
                customer.viewBalance();
                std::cout<< "\nPRESS 'y' TO GET BACK TO MAIN MENU: ";
                std::cin >> ch;
                break;
            case 2:
                cout << "Enter the amount to be deposited: ";
                cin>>amt;
                customer.deposit(amt);
                cin >> view;
                if (view == 'y'){
                    customer.viewBalance();
                    cout<< "\nPRESS 'y' TO GET BACK TO MAIN MENU: ";
                    cin >> ch;
                }
                break;
            case 3:
                cout << "Enter the amount to withdraw: ";
                cin>>amt;
                customer.withdraw(amt);
                cin >> view;
                if (view == 'y'){
                    customer.viewBalance();
                    cout<< "\nPRESS 'y' TO GET BACK TO MAIN MENU: ";
                    cin >> ch;
                }
                break;
            case 4:
                cout << "Exiting....\n";
                prompt = 'n';
                break;
            default:
                cout << "Error!!\nexiting....\n";
                prompt = 'n';
                break;
        }
    }
}