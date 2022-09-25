#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
using namespace std;

/**
 * @brief Creature class
 */
class Creature{
  public:
    /**
     *　@brief set creature name
     */
    void setName(string name);

    /**
     *　@brief set creature sound
     */
    void setSound(string sound);

    /**
     *　@brief set creature food
     */
    void setFood(string food);

    /**
     * @brief return creature name
     */
    string getName(void);

    /**
     * @brief return creature sound
     */
    string getSound(void);

    /**
    * @brief return creature food
     */
    string getFood(void);

  private:
    string _name;
    string _sound;
    string _food;
};

#endif // CREATURE_H
