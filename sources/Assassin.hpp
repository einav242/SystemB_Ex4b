#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;
namespace coup
{
    class Assassin:public Player
    {
    public:
        Assassin(Game & g,string const &s);
        string role();
    };

}
