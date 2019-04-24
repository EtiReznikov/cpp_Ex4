
#pragma once
#include <string>
#include <iostream>
using namespace std;
using std::string;
namespace bullpgia {
class Guesser
{
  private:
      
  public:
  uint length;
    virtual void startNewGame(uint length);
      string bullpgia::Guesser::guess()
    {
       int guess;
       string ans=NULL;
     cout << " Enter your guess ";
      cin >> guess;
   /* try
    {
      /*  int Guesslength = 1;
        while ( guess /= 10 )
           Guesslength++;
        if (Guesslength!=lentgh)
          throw "wrong input";
          */
       ans = to_string(guess);
       this->length= ans.length;
    //}
   /* catch (exception &e)
    {
      cout << " wrong input! ";
    }*/
    return ans;
    }
   virtual void learn(string reply);
};
};