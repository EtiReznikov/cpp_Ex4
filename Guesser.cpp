
#include "Guesser.hpp"
using std::string;
using namespace bullpgia;

string Guesser::guess() {
       int guess;
       string ans="";
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
    void Guesser::startNewGame(uint length)
    {
       cout << " start new game \n Good luck! \n ";
    }
    void Guesser::learn(string reply)
    {
       int separator=reply.find(",");
           uint bull=stoi(reply.substr(0,separator));
            uint pgia=stoi(reply.substr(separator+1,reply.length()-1));

            cout<<"bull: "<<bull<<" pgia: "<<pgia;
    }