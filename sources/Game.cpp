#include"Game.hpp"
using namespace std;
namespace coup{
    Game::~Game()
    {
    }
    vector<string> Game::players() const
    {
        return this->names;
    }
    string Game::turn()
    {
        return this->names[(unsigned int)this->next];
    }
    string Game::winner()
    {
        if(this->names.size()!=1)
        {
             throw std::invalid_argument("There is still no winner");
        }
        int const num1 = 6;
        int const num2 = 2;
        if(this->first)
        {
            if(this->names.size()>num1|| this->names.size()<num2)
            {
                throw std::invalid_argument("Number of players: 2-6");
            }
        }
        return this->names[0];
    }
}