#include "Room.h"

Room::Room(){

}

Room::Room(string name, bool isExit, bool isLocked, int index, vector<Object*> objects){
    this->name = name;
    this->isExit = isExit;
    this->index = index;
    this->objects = objects;
    this->upRoom = nullptr;
    this->downRoom = nullptr;
    this->leftRoom = nullptr;
    this->rightRoom = nullptr;
    this->isLocked = isLocked;
}
bool Room::popObject(int index){
    objects.erase(objects.begin()+index);
    return true;
}
void Room::setUpRoom(Room* upRoom){
    this->upRoom = upRoom;
}
void Room::setDownRoom(Room* downRoom){
    this->downRoom = downRoom;
}
void Room::setLeftRoom(Room* leftRoom){
    this->leftRoom = leftRoom;
}
void Room::setRightRoom(Room* rightRoom){
    this->rightRoom = rightRoom;
}
void Room::setIsExit(bool isExit){
    this->isExit = isExit;
}
void Room::setIndex(int index){
    this->index = index;
}
void Room::setObjects(vector<Object*> objects){
    this->objects = objects;
}
void Room::setName(string name){
    this->name = name;
}
bool Room::getIsExit(){
    return this->isExit;
}
int Room::getIndex(){
    return this->index;
}
vector<Object*> Room::getObjects(){
    return this->objects;
}
Room* Room::getUpRoom(){
    return this->upRoom;
}
Room* Room::getDownRoom(){
    return this->downRoom;
}
Room* Room::getLeftRoom(){
    return this->leftRoom;
}
Room* Room::getRightRoom(){
    return this->rightRoom;
}
string Room::getName(){
    return this->name;
}
void Room::setIsLocked(bool isLocked){
    this->isLocked = isLocked;
}
bool Room::getIsLocked(){
    return this->isLocked;
}