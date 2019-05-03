#pragma once
#include <string>
#include "calculate.hpp"
#include <iostream>
using namespace std;
using std::string;
namespace bullpgia
{
class Chooser
{
  public:
    virtual string choose(uint lentgh) = 0;
};
} // namespace bullpgia