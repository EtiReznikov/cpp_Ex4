#include "Chooser.hpp"

string bullpgia::Chooser::choose(uint lentgh)
{
int choice;
string ans=NULL;
  cout << " Enter your guess ";
  cin >> choice;
    try
    {
      /*  int Guesslength = 1;
        while ( guess /= 10 )
           Guesslength++;
        if (Guesslength!=lentgh)
          throw "wrong input";
          */
       ans = to_string(choice);
    //   this->length= ans.length;
    }
    catch (exception &e)
    {
      cout << " wrong input! ";
    }
    return ans;
}