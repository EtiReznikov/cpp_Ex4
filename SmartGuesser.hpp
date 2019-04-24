#pragma once
#include "Guesser.hpp"
#include <string>
using std::string;
using namespace std;

namespace bullpgia{

 
  class SmartGuesser : public bullpgia::Guesser{

      public:
       void startNewGame(uint length) override;
        string guess() override;
        void learn(string reply) override;
};
}