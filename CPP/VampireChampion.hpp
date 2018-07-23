#ifndef VAMPIRES_CHAMPIONS_HPP
#define VAMPIRES_CHAMPIONS_HPP

#include "champion.hpp"

class VampireChampion : public champion
{
private:

  /**
  * Declare copy-constructor as private in order to prevent illegal use.
  */
  VampireChampion(const VampireChampion&);

  /**
  * Declare assignment-operator as private in order to prevent illegal use.
  */
  VampireChampion& operator = (const VampireChampion&);

public:
  /*Constructor*/
  VampireChampion();

};

#endif
