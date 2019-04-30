#include "calculate.hpp"
//using namespace bullpgia;

string calculateBullAndPgia(string choice, string guess)
{
    int bull=0, pgia=0;
    bool bullindex[choice.length()];
    bool pgiaindex[choice.length()];
    for (int k=0; k<choice.length(); k++)
    {
        bullindex[k]=false;
        pgiaindex[k]=false;
    }
        

   for (int k=0; k<choice.length(); k++)
   {
       if (choice[k]==guess[k])
       {
           bull++;
           bullindex[k]=true;
       }
   }
   int i=0, j=0;
   while (i<choice.length())
   {
       if (!bullindex[i] && !pgiaindex[i]){
       if (choice[i]==guess[j])
       {
           if (i!=j )
           {
            pgia++;
            pgiaindex[i]=false;
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
           i++;
           j=0;
       }
       
   }
    string strpgia=std::to_string(pgia);
    string strbull=std::to_string(bull);

    string ans=strbull+","+strpgia;

    return ans;
}