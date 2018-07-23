#ifndef SPIRIT_CHAMPIONS_HPP
#define SPIRIT_CHAMPIONS_HPP

#include "champion.hpp"

class SpiritChampion : public champion
{
private:

  /**
  * Declare copy-constructor as private in order to prevent illegal use.
  */
  SpiritChampion(const SpiritChampion&);

  /**
  * Declare assignment-operator as private in order to prevent illegal use.
  */
  SpiritChampion& operator = (const SpiritChampion&);

public:

  /*constructor*/
  SpiritChampion();

protected:
  /*
  *  isChampionInvincible
  *   Wizards, Spirits are able to deceive the guards and pass through the gate without losing any HP.
  * @returns true if the champion is wizard or spirit
  */
  virtual  bool isChampionInvincible() const;
  
};
#endif