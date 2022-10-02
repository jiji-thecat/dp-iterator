#include "creature-list-iterator.h"

CreatureListIterator::CreatureListIterator(CreatureList creatureList) :
    _creatureList(creatureList), _index(0) {
}

bool CreatureListIterator::isLast(){
  if (_index < (_creatureList.getCreatures())){
      return true;
  }
  else {
      return false;
  }
}

Creature CreatureListIterator::next(){
  Creature creature = _creatureList.getCreatureAt(_index);
  _index++;

  return creature;
}
