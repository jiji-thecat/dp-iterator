#include "creature-list.h"
#include "creature-list-iterator.h"

CreatureList::CreatureList(int maxsize){
    _creatures.resize(maxsize);
    _nCreatures = 0;
}

Creature CreatureList::getCreatureAt(int index){
    auto itr = _creatures.begin();

    for (int i=0; i<=index; i++) {
        itr++;
    }

    return *itr;
}

void CreatureList::add(Creature creature){
    auto itr = _creatures.begin();

    for (int i=0; i<=_nCreatures; i++) {
        itr++;
    }

    _creatures.insert(itr, creature);

    _nCreatures++;
}

int CreatureList::getCreatures(){
    return _nCreatures;
}

IteratorInterface* CreatureList::iterator(){
    return new CreatureListIterator(*this);
}
