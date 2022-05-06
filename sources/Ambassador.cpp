#include "Ambassador.hpp"
namespace coup
{
    void Ambassador::transfer(Player &p1, Player &p2)
    {    
        int const num1 = 10;
        int const num2 = 2;
        int const num3 = 6;
        if(this->coin>=num1)
        {
            throw std::invalid_argument("more then 10 coin");
        }
        if(this->g->first)
        {
            if(this->g->names.size()>num3|| this->g->names.size()<num2)
            {
                throw std::invalid_argument("Number of players: 2-6");
            }
            this->g->first=false;
        }
        this->fa = false;
        this->st = false;
        this->zero = false;
        this->one = false;
        this->co = false;
        if(p1.coin==0)
        {
            throw std::invalid_argument("Not ");
        }
        if (p1.coin > 0)
        {
            p1.coin--;
            p2.coin++;
        }
        int index=-1;
        for (unsigned int i = 0; i < this->g->names.size(); i++)
        {
        if (this->g->names[i] == this->name)
        {
            index = (int)i;
            break;
        }
    }
    if (this->g->next != index || index==-1)
    {
        throw std::invalid_argument("Not his turn");
    }
        if (this->g->next == this->g->names.size() - 1)
        {
            this->g->next = 0;
        }
        else
        {
            (*this->g).next=index+1;
        }
    }
    void Ambassador::block(Player &d)
    {
        if (!d.st || d.role() != "Captain")
        {
            throw std::invalid_argument("Not enough money");
        }
        if (d.one)
        {
            d.coin--;
            d.victim_st->coin++;
        }
        else if (!d.zero)
        {
            d.coin-=2;
            d.victim_st->coin+=2;
        }
    }
    string Ambassador::role()
    {
        return "Ambassador";
    }
}