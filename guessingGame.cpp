#include <iostream>
using namespace std;
int main()
{

    cout << "#################################" << endl;
    cout << "# Welcome to the guessing game! #" << endl;
    cout << "#################################" << endl;

    const int SECRET_NUMBER = 42;

    int guess;
    cout << "Guess a number: ";
    cin >> guess;
    cout << "You guessed: " << guess << endl;

    bool gotItRight = guess == SECRET_NUMBER;
    bool isBigger = guess > SECRET_NUMBER;

    if (gotItRight)
    {
        cout << "Congratulation! You guessed correctly the secret number!" << endl;
    }
    else if (isBigger)
    {
        cout << "Your guess is biggger then the secret number!" << endl;
    }
    else
    {
        cout << "Your guess is smaller then the secret number!" << endl;
    }
}