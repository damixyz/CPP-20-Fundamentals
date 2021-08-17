#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void guessGame();
bool isCorrect(int, int);

int main(int argc, char const *argv[])
{
    srand(time(0)); // seed random number generator
    guessGame();
    return 0; // indicate successful termination
} // end main

// guessGame generates numbers between 1 and 1000
// and checks user's guess

void guessGame()
{
    char response; // determines whether to contine playing

    do
    {
        // generate random number between 1 and 1000
        // 1 is shift, 1000 is scaling factor
        int answer = 1 + rand() % 1000;

        // prompt for guess
        cout << "I have a number between 1 and 1000. \n"
             << "Can you guess my number?\n"
             << "Please type your first guess."
             << endl
             << "? ";
        int guess;
        cin >> guess;

        // loop until correct number
        while (!isCorrect(guess, answer))
        {
            cin >> guess;
        }

        // prompt for another game
        cout << "\nExcellent! You guessed the number!\n"
             << "Would you like to play again (y or n)?";
        cin >> response;
        cout << endl;

    } while (response == 'y');
} // end function guessGame

// isCorrect return true if g equals a
// if g does not equal a, display hint
bool isCorrect(int g, int a)
{
    // guess is correct
    if (g == a)
    {
        return true;
    }

    // guess is incorrect; display hint
    if (g < a)
    {
        cout << "Too low . Try again. \n?";
    }
    else
    {
        cout << "Too high. Try again. \n?";
    }
    return false;

} // end function isCorrect