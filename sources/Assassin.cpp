#include "Assassin.hpp"

namespace coup
{
    Assassin:: Assassin(Game & g,string const &s):Player(g,s)
    {
    }
    string Assassin::role()
    {
        return "Assassin";
    }
}