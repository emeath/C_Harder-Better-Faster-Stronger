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

bool not_guessed_all_letter_right()
{
    for (char letter : SECRET_WORD)
    {
        if (!letter_already_guessed[letter])
        {
            return true;
        }
    }
    return false;
}

bool not_hanged()
{
    return wrong_guesses.size() < 5;
}

void prints_header()
{

    cout << "+++++++++++++++++++++++++++++++++++" << endl;
    cout << "+          Hangman Game           +" << endl;
    cout << "+++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;
}

void prints_errors()
{
    cout << "Wrong guesses: ";
    for (char letter : wrong_guesses)
    {
        cout << letter << " ";
    }
    cout << endl;
}

void prints_word()
{
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
}

void player_guesses()
{
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

int main()
{
    prints_header();

    while (not_guessed_all_letter_right() && not_hanged())
    {
        prints_errors();
        prints_word();
        player_guesses();
    }

    cout << "GAME OVER!" << endl;
    cout << "The secret word is: " << SECRET_WORD << endl;

    if (not_guessed_all_letter_right())
    {
        cout << "You lose! Try again!" << endl;
    }
    else
    {
        cout << "Congratulation! You guessed the secret word!" << endl;
    }
}