#include <iostream>

using namespace std;

int main()
{

    cout << "#################################" << endl;
    cout << "# Welcome to the guessing game! #" << endl;
    cout << "#################################" << endl;

    const int SECRET_NUMBER = 42;
    bool did_not_got_it_right = true;
    int guess;
    int attempts = 0;

    while (did_not_got_it_right)
    {
        cout << "Guess a number: ";
        cin >> guess;
        cout << "You guessed: " << guess << endl;

        bool got_it_right = guess == SECRET_NUMBER;
        bool is_bigger = guess > SECRET_NUMBER;

        if (got_it_right)
        {
            cout << "Congratulation! You guessed correctly the secret number!" << endl;
            did_not_got_it_right = false;
        }
        else if (is_bigger)
        {
            cout << "Your guess is biggger then the secret number!" << endl;
        }
        else
        {
            cout << "Your guess is smaller then the secret number!" << endl;
        }

        attempts++;
    }

    cout << "GAME OVER!" << endl;
    cout << "You got it right in " << attempts << " attemps!" << endl;
}