#include "assessment.h"

using std::string;
using std::vector;

void updateMask(string &mask, const char ch, const string &word);
bool isCorrectChar(char ch, const string &mask);
bool isWholeWord(const string &mask);

void updateMask(string &mask, const char ch, const string &word)
{
    /***
     TODO Step 2: given a character ch, update the mask to show the character ch that is in the word
      eg . if ch = 'a' and word = "apple", then mask = "a____"

      Args:
          mask (string&): the string need to be updated
          ch (const char): the character that is tested to see if it is in the word or not
          word (const string&): the word that is needed to be tested
     */

    for (size_t i = 0; i < word.length(); i++)
    {
        if (ch == word[i])
        {
            mask[i] = ch;
        }
    }
}

int countMistakes(const string &word, HangmanGuesser &hmGuesser)
{
    /***
     TODO Step 3: Implement this function, which returns the number of mistakes
      tried to solve the word by the given HangmanGuesser.

     Args:
         word (const string&): the word that is needed to be tested
         hmGuesser (HangmanGuesser&): the guesser that is used to make the guess
     Returns:
         int: the number of mistakes made by the guesser
     */

    int count = 0;
    string mask(word.length(), MASK_CHAR);
    hmGuesser.newGame((int)word.length());

    while (mask.find(MASK_CHAR) != std::string::npos)
    {
        string prevMask = mask;
        char guessCh = hmGuesser.getChar(mask);
        updateMask(mask, guessCh, word);

        if (prevMask == mask)
            count++;
    }

    return count;
}

void getMistakeByWordList(vector<MistakeByWord> &mistakeList, vector<string> &unsolvableList, const vector<string> &testWords, HangmanGuesser &hmGuesser)
{
    /***
     TODO Step 4: given a list of words, return a list of mistakes by word,
        where each mistake is a struct containing the word and the number of mistakes that guesser has made on that word
        you can use the updateMask function to update the mask and isCorrectChar to check if a character is correct
        you can use countMistakes to count the number of mistakes
     Args:
         mistakeList (vector<MistakeByWord>&): the list of mistakes by word
         unsolvableList (vector<string>&): the list of words that cannot be solved by the guesser
         testWords (vector<string>&): the list of words that need to be tested
         hmGuesser (HangmanGuesser&): the guesser that is used to make the guess
     */

    for (const string &word : testWords)
    {
        int mistakes = countMistakes(word, hmGuesser);

        if (mistakes == word.length())
        {
            unsolvableList.push_back(word);
        }

        mistakeList.push_back(MistakeByWord{mistakes, word});
    }
}

bool isCorrectChar(char ch, const string &mask)
{
    return isCharInWord(ch, mask);
}

bool isWholeWord(const string &mask)
{
    return !isCharInWord(MASK_CHAR, mask);
}