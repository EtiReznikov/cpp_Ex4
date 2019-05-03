
#include "SmartGuesser.hpp"
#include <random>
#include <iostream>
using namespace bullpgia;
//Initializes all the variables to a new game
void SmartGuesser::startNewGame(uint length)
{
    this->length = length;
    bull = 0, pgia = 0, lastbull = 0, lastpgia = 0;
    currentindex = 0, change = 0, previous = 0, digit=48;
    num_of_check_digits=0;
    lastanswer = "";
    
    for (int i = 0; i < length; i++)
        lastanswer += '0';
    pgiaqueue = queue<int>();
    for (int i=0; i<10; i++)
    checked_digits[i]=false;
    first_queue_use=true;
}
//Updating the variables-bull and pgia, according to the last guess
void SmartGuesser::learn(string reply)
{
    int separator = reply.find(",");
    this->bull = stoi(reply.substr(0, separator));
    this->pgia = stoi(reply.substr(separator + 1, reply.length() - 1));
}

string SmartGuesser::guess()
{
    //If not all digits have been tchecked
    if (num_of_check_digits<10){
        //if there was bull at last guees add this digit to queue as ASCII num
         if (bull > 0)
        {
            for (int i = 0; i < bull; i++)
                pgiaqueue.push(digit+48);
              
        }
        // If not all possible digits in the queue
         if (pgiaqueue.size() < this->length)
        {
            //rand a digit between 0 to 9
             digit=rand()%10;
             //while that digit has checked, rand new number
            while(checked_digits[digit])
            {
                 digit=rand()%10;
            }     
            //Mark the number as checked, and increased the number of digits that checked
            checked_digits[digit]=true;
            num_of_check_digits++;
            //If the last test is not the last digit, make the answer to "kk...k"
            if (num_of_check_digits <=10){
                for (int i = 0; i < length; i++)
                {
                    this->lastanswer.at(i) = (char)(digit+48);
                }

            }
        }
        //There is no need to check more digits
        else
            num_of_check_digits = 11;
    }


//last code
    /*
    if (currentchar_firstcheck < 58)
    {
        if (bull > 0)
        {
            for (int i = 0; i < bull; i++)
                pgiaqueue.push(currentchar_firstcheck);
        }
        if (pgiaqueue.size() < this->length)
        {
            currentchar_firstcheck++;
            if (currentchar_firstcheck < 58)
                for (int i = 0; i < length; i++)
                {
                    this->lastanswer.at(i) = currentchar_firstcheck;
                }
        }
        else
            currentchar_firstcheck = 59;
        
    }
    */

    else
    {
        //If this is not the first use in the queue

        if (!first_queue_use)
        
        {

            //If the num of bull is bigger than it was at last guess, move to next index
            if (bull > lastbull)
            {
                currentindex++;
            }

             //If the num of bull is smaller than it was at last guess,return the digit that was at the last guess,
             // move to next index and increase the num of bull by one
            else if (bull < lastbull)
            {
                this->lastanswer.at(this->currentindex) = previous;
                currentindex++;
                bull++;
            }
            //If at this try there is at least 1 pgia, return this digit to queue
             if (pgia>0)
             pgiaqueue.push(change);
        }

        //If current index is less than the length of the string
        if (currentindex < length)
        {
            first_queue_use = false;
            //Check to avoid exception - the queue is not empty
            if (!pgiaqueue.empty())
            {
                //save the first digit in queue at -change and pop it.
                change = pgiaqueue.front();
                pgiaqueue.pop();
                //If the change digit is equal to the digit in the index we are checking,
                // insert it back and take the next digit in the queue
                while (change == lastanswer.at(currentindex))
                {
                    pgiaqueue.push(change);
                    change = pgiaqueue.front();
                    pgiaqueue.pop();
                }
            }

            //save the last digit that replaced
            previous = this->lastanswer.at(this->currentindex);
            //change the answer
            this->lastanswer.at(this->currentindex) = (char)(change);
        }
    }

    //save this try num of bull and pgia
    this->lastbull = this->bull;
    this->lastpgia = this->pgia;
    //return the new guess
    return lastanswer;
}
