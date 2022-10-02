#include "creature-char-iterator.h"

CreatureCharIterator::CreatureCharIterator(CreatureChar creatureChar) :
    _creatureChar(creatureChar), _index(0) {
}

bool CreatureCharIterator::isLast(){
  if (_index < (_creatureChar.getCreatures())){
      return true;
  }
  else {
      return false;
  }
}

Creature CreatureCharIterator::next(){
  Creature creature = _creatureChar.getCreatureAt(_index);
  _index++;

  return creature;
}
