#include "calculate.hpp"
//using namespace bullpgia;

string calculateBullAndPgia(string choice, string guess)
{
    int bull=0, pgia=0;
    for (int i = 0; i < choice.length(); i++)
    {
        for (int j = 0; j < guess.length(); j++)
        {
            if (choice[i] == guess[j])
                pgia++;
        }
    }
    for (int k = 0; k < choice.length(); k++)
    {
        if (choice[k] == guess[k])
        {
            pgia--;
            bull++;
        }
    }

    string strpgia=std::to_string(pgia);
    string strbull=std::to_string(bull);

    return strbull+","+strpgia;
}