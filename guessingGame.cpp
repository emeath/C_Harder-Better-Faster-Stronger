#include <iostream>
using namespace std;
int main()
{

    cout << "#################################" << endl;
    cout << "# Welcome to the guessing game! #" << endl;
    cout << "#################################" << endl;

    int secret_number = 42;
    
    int guess;
    cout << "Guess a number: ";
    cin >> guess;
    cout << "You guessed: " << guess << endl;

    if (guess == secret_number)
    {
        cout << "Congratulation! You guessed correctly the secret number!" << endl;
    }
    else if (guess > secret_number) {
        cout << "Your guess is biggger then the secret number!" << endl;
    }
    else {
        cout << "Your guess is smaller then the secret number!" << endl;
    }
}