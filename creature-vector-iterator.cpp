#include "creature-vector-iterator.h"

CreatureVectorIterator::CreatureVectorIterator(CreatureVector creatureVector) :
    _index(0), _creatureVector(creatureVector) {
}

bool CreatureVectorIterator::isLast(){
  if (_index < (_creatureVector.getCreatures())){
      return true;
  }
  else {
      return false;
  }
}

Creature CreatureVectorIterator::next(){
  Creature creature = _creatureVector.getCreatureAt(_index);
  _index++;

  return creature;
}
