#include <iostream>
#include <stdexcept>
#include <string>
#include"Player.hpp"
using namespace std;
using namespace coup;
    class Duke :public Player
    {
    public:
        Duke(Game & g,string const& s):Player(g,s){}
        static void block(Player &d);
        void tax();
        string role();
    };

