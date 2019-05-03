
#include "SmartGuesser.hpp"
#include <random>
#include <iostream>
using namespace bullpgia;
void SmartGuesser::startNewGame(uint length)
{
    this->length = length;
    this->bull = 0, this->pgia = 0, this->lastbull = length, this->lastpgia = 0;
    this->currentindex = 0, this->change = 0, this->previous = 0, this->currentchar_firstcheck = 47;
    this->indforpgia=0;
    this->lastanswer = "";
    this->k=48;
    for (int i = 0; i < length; i++)
        lastanswer += '0';
    pgiaqueue = queue<int>();
    for (int i=0; i<10; i++)
    dig[i]=false;
    this->firstcheck=true;
}

void SmartGuesser::learn(string reply)
{
    int separator = reply.find(",");
    this->bull = stoi(reply.substr(0, separator));
    this->pgia = stoi(reply.substr(separator + 1, reply.length() - 1));
}
string SmartGuesser::guess()
{
    
    if (indforpgia<10){
         if (bull > 0)
        {
            for (int i = 0; i < bull; i++)
                pgiaqueue.push(k);
              
        }
      //  cout<<"qeueu size"<<pgiaqueue.size()<<"\n";
         if (pgiaqueue.size() < this->length)
        {
             k=48+rand()%10;
            while(dig[k-48])
            {
                 k=48+rand()%10;
            }
        //    cout<<"k: "<<(char)k<<"\n";
               
            dig[k-48]=true;
            indforpgia++;
        //    cout<<"index: "<<indforpgia<<"\n";
            if (indforpgia <=10){
                for (int i = 0; i < length; i++)
                {
                    this->lastanswer.at(i) = k;
                }

            }
        }
        else
            indforpgia = 11;
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

        if (!firstcheck)
        //cout<<"test\n";
        {
            if (bull > lastbull)
            {
                currentindex++;
            }

            else if (bull < lastbull)
            {
                this->lastanswer.at(this->currentindex) = previous;
                currentindex++;
                bull++;
             //   pgiaqueue.push(change);

              
            }
           if (pgia>0)
             pgiaqueue.push(change);

        }

        if (currentindex < length)
        {
            firstcheck = false;
            if (!pgiaqueue.empty())
            {
                change = pgiaqueue.front();
                pgiaqueue.pop();
                while (change == lastanswer.at(currentindex))
                {
                    pgiaqueue.push(change);
                    change = pgiaqueue.front();
                    pgiaqueue.pop();
                }
            }
            previous = this->lastanswer.at(this->currentindex);
            this->lastanswer.at(this->currentindex) = (char)(change);
        }
    }

    this->lastbull = this->bull;
    this->lastpgia = this->pgia;
    return lastanswer;
}
