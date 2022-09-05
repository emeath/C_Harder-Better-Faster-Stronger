#include <iostream>

using namespace std;

int main()
{

    cout << "#################################" << endl;
    cout << "# Welcome to the guessing game! #" << endl;
    cout << "#################################" << endl;

    cout << "Chose the difficulty level: " << endl;
    cout << "(E)asy (M)edium (H)ard" << endl;

    char difficulty;
    cin >> difficulty;
    int number_of_chances;

    if (difficulty == 'E')
    {
        number_of_chances = 15;
    }
    else if (difficulty == 'M')
    {
        number_of_chances = 10;
    }
    else
    {
        number_of_chances = 5;
    }

    const int SECRET_NUMBER = 42;
    bool did_not_got_it_right = true;
    int guess;
    int attempts = 0;

    double score = 1000.0;

    for(attempts = 1; attempts < number_of_chances; attempts++)
    {
        cout << "Attempt #" << attempts << endl;
        cout << "Guess a number: ";
        cin >> guess;

        double lost_points = abs(guess - SECRET_NUMBER) / 2.0;
        score -= lost_points;

        bool got_it_right = guess == SECRET_NUMBER;
        bool is_bigger = guess > SECRET_NUMBER;

        if (got_it_right)
        {
            cout << "Congratulation! You guessed correctly the secret number!" << endl;
            did_not_got_it_right = false;
            break;
        }
        else if (is_bigger)
        {
            cout << "Your guess is biggger then the secret number!" << endl;
        }
        else
        {
            cout << "Your guess is smaller then the secret number!" << endl;
        }
    }

    cout << "GAME OVER!" << endl;

    if (did_not_got_it_right)
    {
        cout << "You lose! Try again!" << endl;
    }
    else
    {
        cout << "You got it right in " << attempts << " attemps!" << endl;

        cout.precision(2);
        cout << fixed;

        cout << "You scored " << score << " points!" << endl;
    }
}