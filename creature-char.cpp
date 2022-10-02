#include "creature-char.h"
#include "creature-char-iterator.h"

CreatureChar::CreatureChar(int maxsize){
    _creatures = new Creature *[maxsize];
    _nCreatures = 0;
}

Creature CreatureChar::getCreatureAt(int index){
    return *_creatures[index];
}

void CreatureChar::add(Creature creature){
    _creatures[_nCreatures] = &creature;
    _nCreatures++;
}

int CreatureChar::getCreatures(){
    return _nCreatures;
}

IteratorInterface* CreatureChar::iterator(){
    return new CreatureCharIterator(*this);
}
