#include "calculate.hpp"
//using namespace bullpgia;

string calculateBullAndPgia(string choice, string guess)
{
    int bull=0, pgia=0;
    bool guessindex[choice.length()];
    bool choiceindex[choice.length()];
    for (int k=0; k<choice.length(); k++)
    {
guessindex[k]=false;
choiceindex[k]=false;
    }
        

   for (int k=0; k<choice.length(); k++)
   {
       if (choice[k]==guess[k])
       {
           bull++;
           guessindex[k]=true;
           choiceindex[k]=true;
       }
   }
   int i=0, j=0;
   while (i<choice.length())
   {
       if (!guessindex[i] && !choiceindex[j])
       {
        if (choice[i]==guess[j])
        {
           if (i!=j )
            {
                pgia++;
                guessindex[i]=true;
            choiceindex[i]=true;
                i++;
                j=0;
            }
        }
        else
        {
           j++;
        }
        if (j=choice.length())
        {
           i++;
           j=0;
        }
       }
       else
       {
           if (guessindex[i]) 
           {
               i++;
               j=0;
           }
           else if (choiceindex[j])j++;
           
           
       }
       
   }
    string strpgia=std::to_string(pgia);
    string strbull=std::to_string(bull);

    string ans=strbull+","+strpgia;

    return ans;
}