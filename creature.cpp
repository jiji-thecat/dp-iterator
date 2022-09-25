#include "creature.h"

void Creature::setName(string name){
    _name = name;
}

void Creature::setSound(string sound){
    _sound = sound;
}

void Creature::setFood(string food){
    _food = food;
}

string Creature::getName(){
    return _name;
}

string Creature::getSound(){
    return _sound;
}

string Creature::getFood(){
    return _food;
}
