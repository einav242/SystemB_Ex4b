#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include"Player.hpp"
using namespace std;
namespace coup
{
class Ambassador:public Player
{
public:
Ambassador(Game &g,string const &s) : Player(g, s){}
void transfer(Player &p1, Player  &p2);
static void block(Player  &d);
string role();
};
} 