#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
namespace coup{
    class Game
    {
    public:
        vector<string>names;
        string t;
        int next;
        bool first;
        Game()
        {
            this->next=0;
            this->first=true;
        };
        ~Game();
        vector<string>players() const;
        string turn();
        string winner();
    };
    

    
}