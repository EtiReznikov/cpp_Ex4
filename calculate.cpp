#include "calculate.hpp"

auto calculate::calculateBullAndPgia(string choice, string guess)
{
    int bull, pgia;
    for (int i = 0; i < choice.length; i++)
    {
        for (int j = 0; j < guess.length; j++)
        {
            if (choice[i] == guess[j])
                pgia++;
        }
    }
    for (int i = 0; i < choice.length; i++)
    {
        if (choice[i] == guess[i])
        {
            pgia--;
            bull++;
        }
    }

    string strpgia=std::to_string(pgia);
    string strbull=std::to_string(bull);

    return strbull+","+strpgia;
}