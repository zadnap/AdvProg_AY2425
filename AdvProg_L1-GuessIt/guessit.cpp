#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;

/***
    Args:

    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber()
{
    int randomNumber = 1 + rand() % 100;
    return randomNumber;
}

/***
    Args:

    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess()
{
    int playerGuess;

    cout << "Enter your guess: ";
    cin >> playerGuess;

    return playerGuess;
}

/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber)
{
    /***
        TODO: check number with randomNumber and return the result.
              If number is higher than randomNumber, the answer is "Your number is higher."
              If number is lower than randomNumber, the answer is "Your number is lower."
              If number is equal randomNumber, the answer is "Congratulation! You win."
    ***/
    string answer;

    if (number > randomNumber)
    {
        answer = "Your number is higher.";
    }
    else if (number < randomNumber)
    {
        answer = "Your number is lower.";
    }
    else if (number == randomNumber)
    {
        answer = "Congratulation! You win.";
    }

    return answer;
}

/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(string answer)
{
    // TODO: return the result after checking that player guessed right or wrong
    return answer == "Congratulation! You win.";
}

/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued)
{
    // TODO: return result after checking player continue playing or not
    return isContinued == 'Y';
}

/***
    Args:

    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion()
{
    char isContinued;
    do
    {
        cout << "Do you want to continue playing? (Y/N): ";
        cin >> isContinued;
    } while (isContinued != 'N' && isContinued != 'Y');

    return isContinued;
}

void playGuessIt()
{
    int randomNumber = generateRandomNumber();
    int number;
    string answer;

    do
    {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run()
{
    srand(time(0));
    char isContinued;
    do
    {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
