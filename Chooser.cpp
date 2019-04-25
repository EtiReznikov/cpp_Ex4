#include "Chooser.hpp"
using namespace bullpgia;
string Chooser::choose(uint lentgh)
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
 
    }
    catch (exception &e)
    {
      cout << " wrong input! ";
    }
    
    return ans;
}