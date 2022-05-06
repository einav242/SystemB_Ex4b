#include "Captain.hpp"
using namespace coup;

void Captain::block(Player &d)
{
    if(!d.st || d.role()!="Captain")
    {
          throw std::invalid_argument("Not stolen from this player");
    }
    d.st=false;
    if(d.one)
    {
        d.coin--;
        d.victim_st->coin++;
    }
    else if(!d.zero)
    {
        d.coin-=2;
        d.victim_st->coin+=2;
    }

}
void Captain::steal(Player &p)
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
    this->one=false;
    this->zero=false;
    this->fa=false;
    this->co=false;
    this->st=true;
    this->victim_st=&p;
    if(p.coins()==1)
    {
        p.coin=0;
        this->coin+=1;
        this->one=true;
    }
    else if(p.coins()>=2)
    {
        p.coin-=2;
        this->coin+=2;
    }
    else
    {
        this->zero=true;
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
    string Captain::role()
    {
        return "Captain";
    }