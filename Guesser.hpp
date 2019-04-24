
#pragma once
#include <string>
#include <iostream>
using namespace std;
using std::string;
namespace bullpgia {
class Guesser
{
  private:
      uint length;
  public:
    void startNewGame(uint length);
    virtual string guess();
    void learn(string reply);
};
};