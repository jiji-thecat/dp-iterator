#ifndef CREATURECHAR_H
#define CREATURECHAR_H

#include "aggregate-interface.h"
#include "iterator-interface.h"
#include "creature.h"

/**
 *  @brief Creature list with vector
 **/
class CreatureChar : public AggregateInterface{
  public:
    /**
     *  @brief constructor
     *  @param maxsize max size of vector
     **/
    CreatureChar(int maxsize);

    /**
     * @brief Get the creature at index
     * @param index creature index
     */
    Creature getCreatureAt(int index);

    /**
     * @brief Add creature on vector
     * @param creature data of the creasture
     */
    void add(Creature creature);

    /**
     * @brief vector length
     */
    int getCreatures(void);

    /**
     * @brief Iterator of CreatureVector
     */
    IteratorInterface* iterator(void);

  private:
    Creature **_creatures;
    int _nCreatures;
};

#endif // CREATURECHAR_H
