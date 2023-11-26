#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>

#include "Object.h"

using namespace std;

class GameCharacter: public Object
{
    public:
    GameCharacter();
    GameCharacter(string name, string tag);
};
#endif // GAMECHARACTER_H_INCLUDED
