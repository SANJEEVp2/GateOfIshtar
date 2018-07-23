#ifndef HUMANCHAMPION_HPP
#define HUMANCHAMPION_HPP

#include"champion.hpp"

class humanChampion : public champion
{
private:

  /**
  * Declare copy-constructor as private in order to prevent illegal use.
  */
  humanChampion(const humanChampion&);

  /**
  * Declare assignment-operator as private in order to prevent illegal use.
  */
  humanChampion& operator = (const humanChampion&);

public:

  /*constructor*/
  humanChampion();

};

#endif
