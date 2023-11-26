#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Object
{
private:
    string name;
    string tag;
public:
    Object();
    Object(string name, string tag);

    /* pure virtual function */
    virtual bool triggerEvent(Object* obj) = 0;

    /* Set & Get function*/
    void setName(string name);
    void setTag(string tag);
    string getName();
    string getTag();
};

#endif // OBJECT_H_INCLUDED
