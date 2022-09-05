#include <iostream>
#include <string>
using namespace std;

const string SECRET_WORD = "BANANA";

bool letter_exists(char guess)
{
    for (int i = 0; i < SECRET_WORD.size(); i++)
    {
        if (guess == SECRET_WORD[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << SECRET_WORD << endl;

    bool not_right_answer = true;
    bool not_hanged = true;

    while (not_right_answer && not_hanged)
    {
        char guess;
        cin >> guess;
        if (letter_exists(guess))
        {
            cout << "Correct guess!" << endl;
        } else {
            cout << "Wrong guess!" << endl;
        }
    }
}