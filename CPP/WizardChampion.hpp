#ifndef WIZARDS_CHAMPIONS_HPP
#define WIZARDS_CHAMPIONS_HPP
#include "champion.hpp"

class WizardChampion : public champion
{
private:


  /**
  * Declare copy-constructor as private in order to prevent illegal use.
  */
  WizardChampion(const WizardChampion&);

  /**
  * Declare assignment-operator as private in order to prevent illegal use.
  */
  WizardChampion& operator = (const WizardChampion&);

public:

  /*constructor*/
  WizardChampion();
protected:
  /*
  *  isChampionInvincible
  *   Wizards, Spirits are able to deceive the guards and pass through the gate without losing any HP.
  * @returns true if the champion is wizard or spirit
  */
  virtual  bool isChampionInvincible() const;
};

#endif
