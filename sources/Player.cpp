
#include "Player.hpp"
using namespace coup;
using namespace std;

Player::~Player()
{
}
void Player::income()
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
    int index = -1;
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
    this->fa = false;
    this->st = false;
    this->zero = false;
    this->one = false;
    this->co = false;
    if (index == this->g->names.size() - 1)
    {
        this->g->next = 0;
    }
    else
    {
        (*this->g).next=index+1;
    }
    this->coin++;
}
void Player::foreign_aid()
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
    int index = -1;
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
    this->fa = false;
    this->st = false;
    this->zero = false;
    this->one = false;
    this->co = false;
    if (index == this->g->names.size() - 1)
    {
        this->g->next = 0;
    }
    else
    {
        this->g->next=index+1;
    }
    this->coin += 2;
    this->fa = true;
}
void Player::coup(Player &p)
{
    int const num1 = 6;
    int const num2 = 2;
    if(this->g->first)
    {
        if(this->g->names.size()>num1|| this->g->names.size()<num2)
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
    int const num = 7;
    int index = -1;
    int index2=0;
    for (unsigned int i = 0; i < this->g->names.size(); i++)
    {
        if (this->g->names[i] == p.name)
        {
            index = (int)i;
        }
    }
    if (index==-1) 
    {
        throw std::invalid_argument("Not his turn");
    }
    if (this->coins() < num &&this->role() == "Assassin")
    {
        if (this->coin < 3)
        {
            throw std::invalid_argument("Not enough money");
        }
        this->coin -= 3;
        this->co = true;
        this->victim_co = &p;
    }
    else
    {
        if (this->coin < num)
        {
            throw std::invalid_argument("Not enough money");
        }
        this->coin -= num;
    }
    this->victim_ind=index;
    this->g->names.erase(this->g->names.begin() + index);
    for (unsigned int i = 0; i < this->g->names.size(); i++)
    {
        if (this->g->names[i] == this->name)
        {
            index2= (int)i;
        }
    }
    if (index2 == this->g->names.size()-1)
    {
        this->g->next = 0;
    }
    else
    {
        (*this->g).next=index2+1;
    }
    // cout<<index2;
}
string Player::role()
{
    return this->r;
}
int Player::coins() const
{
    return this->coin;
}