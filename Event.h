#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include "Object.h"
#include "Player.h"

using namespace std;

class Event : public Object
{
private:
    string askScript;
    string rightChoice;
    string endScript;
    bool isKeyRequired;
    int addHealth;
    int addAttack;
    int addDefense;
public:
    Event();
    Event(string name, string askScript, string endScript, string rightChoice, bool isKeyRequired, int addHealth, int addAttack, int addDefense);
    void setAskScript(string askScript);
    void setRightChoice(string rightChoice);
    void setEndScript(string endScript);
    void setIsKeyRequired(bool isKeyRequired);
    void setAddHealth(int addHealth);
    void setAddAttack(int addAttack);
    void setAddDefense(int addDefense);
    string getAskScript();
    string getRightChoice();
    string getEndScripe();
    bool getIsKeyRequired();
    bool triggerEvent(Object* obj);
    int getAddHealth();
    int getAddAttack();
    int getAddDefense();
};
#endif