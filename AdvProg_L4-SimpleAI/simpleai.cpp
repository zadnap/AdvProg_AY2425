#include "simpleai.h"

int readMaxGuess()
{
    int maxGuess;
    cout << endl
         << "Enter the number of incorrect guesses: ";
    cin >> maxGuess;
    return maxGuess;
}

int readWordLen()
{
    int wordLen;
    cout << endl
         << "Enter the number characters of your secret word: ";
    cin >> wordLen;
    return wordLen;
}

/***
    Args:
        wordLen (int): The desired length of input word
        vocabulary (vector<string>): The vocabulary
    Returns:
        answer (vector<string>) : A set or word from the vocabulary where the number of character is equal to wordLen
***/
vector<string> filterWordsByLen(int wordLen, const vector<string> &vocabulary)
{
    vector<string> answer;

    for (string word : vocabulary)
    {
        if ((int)word.size() == wordLen)
        {
            answer.push_back(word);
        }
    }

    return answer;
}

/***
    Args:
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The next character given the provided word is not in the vocabulary
***/

char nextCharWhenWordIsNotInDictionary(const set<char> &selectedChars)
{
    char answer = 0;

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (selectedChars.find(ch) == selectedChars.end())
        {
            answer = ch;
            break;
        }
    }

    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string
    Returns:
        answer (map) : The map which count the occurences of character in the set of candidate words
***/

map<char, int> countOccurrences(const vector<string> &candidateWords)
{
    map<char, int> answer;

    for (const string &word : candidateWords)
    {
        for (char ch : word)
        {
            answer[ch]++;
        }
    }

    return answer;
}

/***
    Args:
        occurrences (map<char, int>): The map which count the occurences of character in the set of candidate words
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most frequent character
***/

char findMostFrequentChar(const map<char, int> &occurrences, const set<char> &selectedChars)
{
    char answer = 0;
    int highestFrequency = -1;

    for (const auto &entry : occurrences)
    {
        if (entry.second > highestFrequency && selectedChars.find(entry.first) == selectedChars.end())
        {
            highestFrequency = entry.second;
            answer = entry.first;
        }
    }

    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most suitable character for prediction
***/

char findBestChar(const vector<string> &candidateWords, const set<char> &selectedChars)
{
    map<char, int> occurences = countOccurrences(candidateWords);
    char answer = findMostFrequentChar(occurences, selectedChars);

    return answer;
}

string getWordMask(char nextChar)
{
    string mask;
    cout << "The next char is: " << nextChar << endl;
    cout << "Please give me your answer: ";
    cin >> mask;
    return mask;
}

/***
    Args:
        ch (char): The predicted character by the AI
        mask (string): The response mask by the player
    Returns:
        answer (bool) : return False if the predicted character is the wrong one, True otherwise
***/

bool isCorrectChar(char ch, const string &mask)
{
    bool answer = mask.find(ch) != string::npos;

    return answer;
}

/***
    Args:
        mask (string): The response mask by the player
    Returns:
        answer (bool) : return False if the provided mask is not a whole word, True otherwise
        (Example: -False: g__d
                  -True:  good)
***/
bool isWholeWord(const string &mask)
{
    bool answer = true;

    for (char c : mask)
    {
        if (c == '-')
        {
            answer = false;
            break;
        }
    }

    return answer;
}

/***
    This function should be used to support the filterWordsByMask function below
    Args:
        mask (string): The response mask by the player
        word (string): input word
        ch (char): The predicted character by the AI
    Returns:
        answer (bool) : return False if the provided mask and the given word is not in the same form.
        Example: - False: mask(-ood), char 'd' vs word(boot)
                 - True: mask(-ood), char 'd'  vs word(good)

***/
bool wordConformToMask(const string &word, const string &mask, char ch)
{
    bool answer = true;

    for (size_t i = 0; i < mask.length(); i++)
    {
        if (mask[i] != '-' && mask[i] != word[i])
        {
            answer = false;
            break;
        }
    }

    return answer;
}

/***
    Args:
        mask (string): The response mask by the player
        words (vector<string>): The candidate words
        ch (char): The predicted character by the AI
    Returns:
        answer (bool) : a list of word which satisfiy the mask and the predicted character
        Examples: input words: (good,boot,hood,...)
                  input mask: -ood
                  predicted char: d
                  Return: good,hood
***/
vector<string> filterWordsByMask(const vector<string> &words, const string &mask, char ch)
{
    vector<string> answer;

    for (string word : words)
    {
        if (wordConformToMask(word, mask, ch))
            answer.push_back(word);
    }

    return answer;
}