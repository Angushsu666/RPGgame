#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include "Object.h"

using namespace std;

class Room
{
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    bool isLocked;
    int index;
    string name;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
public:
    Room();
    Room(string name, bool isExit, bool isLocked, int index, vector<Object*> objects);
    bool popObject(int index); /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void setIsLocked(bool isLocked);
    void setUpRoom(Room* upRoom);
    void setDownRoom(Room* downRoom);
    void setLeftRoom(Room* leftRoom);
    void setRightRoom(Room* rightRoom);
    void setIsExit(bool isExit);
    void setIndex(int index);
    void setObjects(vector<Object*> objects);
    void setName(string name);
    bool getIsExit();
    bool getIsLocked();
    int getIndex();
    string getName();
    vector<Object*> getObjects();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
};

#endif // ROOM_H_INCLUDED
