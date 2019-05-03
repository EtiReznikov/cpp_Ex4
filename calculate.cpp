#include "calculate.hpp"
//using namespace bullpgia;

string calculateBullAndPgia(string choice, string guess)
{
    //saves the num of bull and pgia
    int bull = 0, pgia = 0;
    //Arrays that represent if the number in the string is checked
    bool guessindex[guess.length()], choiceindex[choice.length()];
    //Initializes the arrays, assuming that guess.length=choice.length
    for (int k = 0; k < choice.length(); k++)
    {
        guessindex[k] = false;
        choiceindex[k] = false;
    }

    //checks the bull's.

    for (int k = 0; k < choice.length(); k++)
    {
        if (choice[k] == guess[k])
        {
            bull++;
            guessindex[k] = true;
            choiceindex[k] = true;
        }
    }
    //i- the index in the guess string, j- the index in the choice string
    int i = 0, j = 0;
    while (i < choice.length())
    {
        // if the digit in the guess string in place i and the digit in the choice string in place j were not checked
        if (!guessindex[i] && !choiceindex[j])
        {
            //if the digits are equals- Update the arrays, increase pgia in one, update i and j
            if (choice[i] == guess[j])
            {
                pgia++;
                guessindex[i] = true;
                choiceindex[j] = true;
                i++;
                j = 0;
            }
            //update j
            else
            {
                j++;
            }
            //if j is bigger than choice length update i and j
            if (j == choice.length())
            {
                i++;
                j = 0;
            }
        }
        else
        {
            // if the digit in the guess string in place i checked, update i and j
            if (guessindex[i])
            {
                i++;
                j = 0;
            }
            // if the digit in the choice string in place j checked, update j
            else if (choiceindex[j])
                j++;
            //if j is bigger than choice length update i and j
            if (j == choice.length())
            {
                i++;
                j = 0;
            }
        }
    }
    //cast the ans to a string and return it
    string strpgia = std::to_string(pgia);
    string strbull = std::to_string(bull);

    string ans = strbull + "," + strpgia;

    return ans;
}
