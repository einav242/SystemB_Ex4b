#include "Contessa.hpp"
using namespace coup;

void Contessa::block(Player &d)
{
    if(!d.co ||d.role()!="Assassin")
    {
          throw std::invalid_argument("Invalid operation");
    }
    this->g->names.insert(this->g->names.begin()+d.victim_ind,d.victim_co->name);
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
    if(d.victim_ind<index)
    {
        if (index == this->g->names.size() - 1)
        {
            this->g->next = 0;
        }
        else
        {
            (*this->g).next=index+1;
        }
    }
    d.co=false;
}

string Contessa::role()
{
    return "Contessa";
}