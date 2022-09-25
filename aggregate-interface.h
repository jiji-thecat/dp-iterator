#ifndef AGGREGATEINTERFACE_H
#define AGGREGATEINTERFACE_H

#include "iterator-interface.h"

/**
 *  @brief Aggregate Interface
 */
class AggregateInterface{
  public:
    virtual IteratorInterface* iterator(void) = 0;
};


#endif // AGGREGATEINTERFACE_H
