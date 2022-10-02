#ifndef CREATURECHARITERATOR_H
#define CREATURECHARITERATOR_H

#include "iterator-interface.h"
#include "creature-char.h"

/**
 * @brief Creature Char Iterator
 */
class CreatureCharIterator : public IteratorInterface{
  public:
    CreatureCharIterator(CreatureChar creatureChar);

    /**
     * @brief If the iterator pointing is the last
     */
    bool isLast(void);

    /**
     * @brief returns the current pointing data and moves to the next
     */
    Creature next(void);

  private:
    CreatureChar _creatureChar;
    int _index;
};

#endif // CREATURECHARITERATOR_H
