
#include "Guesser.hpp"
using std::string;
using namespace bullpgia;

// Ask from the player to guess a number, checks that its a vaild input
string Guesser::guess()
{
   int guess;
   string ans = "";
   cout << " Enter your guess ";
   cin >> guess;
   try
   {
      ans = to_string(guess);
      this->length = ans.length();
   }
   catch (exception &e)
   {
      cout << " wrong input! ";
      return ans;
   }
}
//Informs the player that the game start
void Guesser::startNewGame(uint length)
{
   cout << " start new game \n Good luck! \n ";
}
//Informs the player about his bull and pgia
void Guesser::learn(string reply)
{
   int separator = reply.find(",");
   uint bull = stoi(reply.substr(0, separator));
   uint pgia = stoi(reply.substr(separator + 1, reply.length() - 1));

   cout << "bull: " << bull << " pgia: " << pgia;
}