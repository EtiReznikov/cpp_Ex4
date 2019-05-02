#pragma once
#include "Guesser.hpp"
#include <string>
using std::string;
using namespace std;
#include <queue>  


namespace bullpgia{

 
  class SmartGuesser : public bullpgia::Guesser{

private:

int numofguess=0;


protected:
 uint  bull, pgia,lastbull, lastpgia;
  int change, previous, currentchar_firstcheck;
  int indforpgia;
 bool dig[10]={false};
 int k;

queue<int> pgiaqueue;
 bool firstcheck;
string lastanswer;


 int currentindex;

      public:
      
       void startNewGame(uint length) override;
       string guess() override;
        void learn(string reply) override;
};
}