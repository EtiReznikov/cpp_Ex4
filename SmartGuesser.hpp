#pragma once
#include "Guesser.hpp"
#include <string>
using std::string;
using namespace std;
#include <queue>  


namespace bullpgia{

  class SmartGuesser : public bullpgia::Guesser{

protected:
  uint  bull, pgia; //nums of pgia and bull in this try
  uint lastbull, lastpgia; //nums of pgia and bull in last try
  int change; //the new digit
  int previous; //the digit we exchanged
  int num_of_check_digits; //num od digit we checked
  bool checked_digits[10] = {false}; //An array representing the digits that checked
  int digit; //digit we check

  queue<int> pgiaqueue; //A queue of possible digits
  bool first_queue_use; //boolean that represents the first use in the queue
  string lastanswer; //last answer that quess

  int currentindex; //current index in the string that checked

public:
  void startNewGame(uint length) override;
  string guess() override;
  void learn(string reply) override;
};
}