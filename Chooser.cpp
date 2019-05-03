#include "Chooser.hpp"
using namespace bullpgia;
// Ask from the player to choose a number, checks that its a vaild input
string Chooser::choose(uint lentgh)
{
int choice;
string ans=NULL;
  cout << " Enter your guess ";
  cin >> choice;
    try
    {
       ans = to_string(choice);
 
    }
    catch (exception &e)
    {
      cout << " wrong input! ";
    }
    
    return ans;
}