#include <iostream>
#include "Player.hpp"
using namespace std;
namespace coup
{
    class Contessa:public Player
    {
    public:
        Contessa(Game  &g,string const &s):Player(g,s){}
        void block(Player  &d);
        string role();
    };
}
