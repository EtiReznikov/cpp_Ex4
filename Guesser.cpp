
#include "Guesser.hpp"
using std::string;
using namespace bullpgia;

string Guesser::guess() {
       int guess;
       string ans=NULL;
     cout << " Enter your guess ";
      cin >> guess;
    try
    {
       ans = to_string(guess);
       this->length= ans.length();
    }
    catch (exception &e)
    {
      cout << " wrong input! ";
    return ans;
    }
}
  //  void Guesser::startNewGame(uint length){}
  //  void Guesser::learn(string reply){}