#include <iostream>
#include <stdexcept>
#include <string>
#include"Player.hpp"
using namespace std;
namespace coup
{
    class Captain:public Player
    {
    public:
        Captain(Game  &g,string const &s):Player(g,s)
        {
       
        }
        void steal(Player &p);
        static void block(Player &d);
        string role();
    };
} 
