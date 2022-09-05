#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const string SECRET_WORD = "BANANA";
map<char, bool> letter_already_guessed;
vector<char> wrong_guesses;


bool letter_exists(char guess)
{
    for (char letter : SECRET_WORD)
    {
        if (guess == letter)
        {
            return true;
        }
    }

    return false;
}



int main()
{
    cout << "+++++++++++++++++++++++++++++++++++" << endl;
    cout << "+          Hangman Game           +" << endl;
    cout << "+++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;

    cout << SECRET_WORD << endl;

    bool not_right_answer = true;
    bool not_hanged = true;

    while (not_right_answer && not_hanged)
    {
        cout << "Wrong guesses: ";
        for(char letter : wrong_guesses) {
            cout << letter << " ";
        }
        cout << endl;

        for (char letter : SECRET_WORD)
        {
            if (letter_already_guessed[letter])
            {
                cout << letter << " ";
            }
            else
            {
                cout << "_ ";
            }
        }
        cout << endl;

        cout << "Your guess: ";

        char guess;
        cin >> guess;
        if (letter_exists(guess))
        {
            cout << "Correct guess!" << endl;
            letter_already_guessed[guess] = true;
        }
        else
        {
            cout << "Wrong guess!" << endl;
            wrong_guesses.push_back(guess);
        }

        cout << endl;
    }
}