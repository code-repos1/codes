#include <iostream>
using namespace std;

class ATM {
private:
    double balance;

public:
    ATM() {
        balance = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. Current balance: $" << balance << endl;
        } else {
            cout << "Invalid amount. Please enter a positive value." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawal successful. Current balance: $" << balance << endl;
            } else {
                cout << "Insufficient funds." << endl;
            }
        } else {
            cout << "Invalid amount. Please enter a positive value." << endl;
        }
    }

    void displayBalance() {
        cout << "Current balance: $" << balance << endl;
    }
};

int main() {
    ATM atm;

    cout << "Welcome to the ATM!" << endl;

    while (true) {
        cout << "1. Deposit  2. Withdraw  3. Check Balance  4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the amount to deposit: ";
                double amount;
                cin >> amount;
                atm.deposit(amount);
                break;
            }
            case 2: {
                cout << "Enter the amount to withdraw: ";
                double amount;
                cin >> amount;
                atm.withdraw(amount);
                break;
            }
            case 3: {
                atm.displayBalance();
                break;
            }
            case 4: {
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}


/*
Certainly! Let's go through the code line by line to explain what each part does:

```cpp
#include <iostream>
using namespace std;
```

These are the necessary header files for input and output operations in C++. `iostream` provides functionality for reading input from the user and displaying output on the screen. `using namespace std;` allows us to use the standard library functions without explicitly specifying the `std` namespace.

```cpp
class ATM {
private:
    double balance;

public:
    ATM() {
        balance = 0.0;
    }
```

Here, we define a class named `ATM` to represent our ATM machine. It has a private member variable `balance` of type `double`, which represents the current balance in the account. The constructor `ATM()` initializes the `balance` to 0.0 when an `ATM` object is created.

```cpp
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. Current balance: $" << balance << endl;
        } else {
            cout << "Invalid amount. Please enter a positive value." << endl;
        }
    }
```

The `deposit` function allows the user to deposit money into their account. It takes a `double` parameter `amount` representing the amount to be deposited. If the `amount` is greater than 0, the `balance` is increased by the deposited `amount`, and a success message along with the updated balance is displayed. If the `amount` is not positive, an error message is displayed.

```cpp
    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawal successful. Current balance: $" << balance << endl;
            } else {
                cout << "Insufficient funds." << endl;
            }
        } else {
            cout << "Invalid amount. Please enter a positive value." << endl;
        }
    }
```

The `withdraw` function allows the user to withdraw money from their account. It takes a `double` parameter `amount` representing the amount to be withdrawn. If the `amount` is greater than 0, it checks if the `balance` is sufficient to cover the withdrawal. If so, it deducts the `amount` from the `balance` and displays a success message along with the updated balance. If the `balance` is insufficient, an error message is displayed. If the `amount` is not positive, an error message is shown.

```cpp
    void displayBalance() {
        cout << "Current balance: $" << balance << endl;
    }
```

The `displayBalance` function simply displays the current balance in the account.

```cpp
int main() {
    ATM atm;

    cout << "Welcome to the ATM!" << endl;

    while (true) {
        cout << "1. Deposit  2. Withdraw  3. Check Balance  4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the amount to deposit: ";
                double amount;
                cin >> amount;
                atm.deposit(amount);
                break;
            }
            case 2: {
                cout << "Enter the amount to withdraw: ";
                double amount;
                cin >> amount;
                atm.withdraw(amount);
                break;
            }
            case 3: {
                atm.displayBalance();
                break;
            }
            case 4: {
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
```

In the `main` function, we create an object `atm` of the `ATM` class. This object represents our ATM machine.

We display a welcome message to the user.

We then enter a while loop that runs indefinitely until the user chooses to exit.

Inside the loop, we display a menu of options to the user: deposit, withdraw, check balance, or exit.

We prompt the user to enter their choice.

Based on the user's choice, we use a switch statement to perform the corresponding operation.

- If the user chooses 1, we prompt for the amount to deposit, read it from the user, and call the `deposit` function of the `atm` object.
- If the user chooses 2, we prompt for the amount to withdraw, read it from the user, and call the `withdraw` function of the `atm` object.
- If the user chooses 3, we call the `displayBalance` function of the `atm` object to show the current balance.
- If the user chooses4, we display a goodbye message and exit the program.

If the user enters an invalid choice, we display an error message and continue the loop.

Finally, after the user chooses to exit, we return 0 to indicate successful program execution.
*/
