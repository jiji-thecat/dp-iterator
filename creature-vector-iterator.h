#ifndef CREATUREVECTORITERATOR_H
#define CREATUREVECTORITERATOR_H

#include "iterator-interface.h"
#include "creature-vector.h"

/**
 * @brief Creature Vector Iterator
 */
class CreatureVectorIterator : public IteratorInterface{
  public:
    CreatureVectorIterator(CreatureVector creatureVector);

    /**
     * @brief If the iterator pointing is the last
     */
    bool isLast(void);

    /**
     * @brief returns the current pointing data and moves to the next
     */
    Creature next(void);

  private:
    CreatureVector _creatureVector;
    int _index;
};

#endif // CREATUREVECTORITERATOR_H
