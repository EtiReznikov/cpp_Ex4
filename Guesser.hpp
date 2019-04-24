#pragma once
#include <string>
using std::string;
class Guesser{
    void startNewGame(uint length);
    string guess();
    void learn(string reply);
};