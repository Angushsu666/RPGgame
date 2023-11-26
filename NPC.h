#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

//#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class NPC: public GameCharacter
{
private:
    string script;
    vector<Item*> commodity;
public:
    NPC();
    NPC(string name, string script, vector<Item*> commodity);
    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool triggerEvent(Object* obj);

    /* Set & Get function*/
    void setScript(string script);
    void setCommodity(vector<Item*> commodity);
    string getScript();
    vector<Item*> getCommodity();
};


#endif // NPC_H_INCLUDED
