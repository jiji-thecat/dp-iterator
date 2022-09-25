#include "creature-vector.h"
#include "creature-vector-iterator.h"

CreatureVector::CreatureVector(int maxsize){
    _creatures.resize(maxsize);
    _nCreatures = 0;
}

Creature CreatureVector::getCreatureAt(int index){
    return _creatures[index];
}

void CreatureVector::add(Creature creature){
    _creatures[_nCreatures] = creature;
    _nCreatures++;
}

int CreatureVector::getCreatures(){
    return _nCreatures;
}

IteratorInterface* CreatureVector::iterator(){
  return new CreatureVectorIterator(*this);
}
