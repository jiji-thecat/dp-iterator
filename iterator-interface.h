#ifndef ITERATORINTERFACE_H
#define ITERATORINTERFACE_H

#include "creature.h"

/**
 *  @brief Iterator Interface
 */
class IteratorInterface{
  public:
    virtual bool isLast(void) = 0;
    virtual Creature next(void) = 0;
};

#endif // ITERATORINTERFACE_H
