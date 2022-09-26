#ifndef CREATURELISTITERATOR_H
#define CREATURELISTITERATOR_H

#include "iterator-interface.h"
#include "creature-list.h"

/**
 * @brief Creature Vector Iterator
 */
class CreatureListIterator : public IteratorInterface{
  public:
    CreatureListIterator(CreatureList creatureList);

    /**
     * @brief If the iterator pointing is the last
     */
    bool isLast(void);

    /**
     * @brief returns the current pointing data and moves to the next
     */
    Creature next(void);

  private:
    CreatureList _creatureList;
    int _index;
};

#endif // CREATURELISTITERATOR_H
