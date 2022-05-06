#include "Duke.hpp"
using namespace coup;

void Duke::block(Player &d)
{
    if (!d.fa)
    {
        throw std::invalid_argument("the last operation was not foreign_aid");
    }
    if (d.coins() == 1)
    {
        d.coin = 0;
    }
    else if (d.coins() >= 2)
    {
        d.coin -= 2;
    }
}
void Duke::tax()
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
    int const si=this->g->names.size();
    int index=-1;
    for(unsigned int i=0;i<si;i++)
    {
        if(this->g->turn()==this->g->names[i])
        {
            index=(int)i;
            break;
        }
    }
    if (this->g->next != index || index==-1)
    {
        throw std::invalid_argument("Not his turn");
    }
    if (index == this->g->names.size() - 1)
    {
        this->g->next = 0;
    }
    else
    {
         (*this->g).next=index+1;
    }
    this->coin += 3;
}
string Duke::role()
{
    return "Duke";
}
