
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
    virtual void startNewGame(uint length){};
      virtual string guess()=0;
   virtual void learn(string reply){};
};
}