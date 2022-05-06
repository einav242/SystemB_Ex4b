#pragma once
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
namespace coup
{
    class Player
    {
    public:
        string name;
        string r;
        Game *g;
        bool fa;
        bool st;
        bool zero;
        bool one;
        bool co;
        int coin;
        Player* victim_co;
        Player* victim_st;
        int victim_ind;
        Player(Game & game,string const& s)
        {
            this->fa=false;
            this->st=false;
            this->zero=false;
            this->one=false;
            this->co=false;
            this->victim_co=NULL;
            this->victim_st=NULL;
            this->victim_ind=-1;
            this->name=s;
            this->g=&game;
            this->coin=0;
            if((*this->g).names.size()>=6 || !(*this->g).first)
            {
                 throw std::invalid_argument("Number of players: 2-6");
            }
            (*this->g).names.push_back(this->name);
        };
        ~Player();
        void income();
        void foreign_aid();
        void coup(Player &p);
        virtual string role();
        int coins() const;
    };

}
