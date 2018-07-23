#ifndef GIANT_CHAMPIONS_HPP
#define GIANT_CHAMPIONS_HPP

#include "champion.hpp"

class GiantChampion : public champion
{
private:


  /**
  * Declare copy-constructor as private in order to prevent illegal use.
  */
  GiantChampion(const GiantChampion&);

  /**
  * Declare assignment-operator as private in order to prevent illegal use.
  */
  GiantChampion& operator = (const GiantChampion&);

public:
  /*Constructor*/
  GiantChampion();
};

#endif
