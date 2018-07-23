#ifndef CHAMPIONS_HPP
#define CHAMPIONS_HPP


#include <iostream>
#include <stdio.h>
#include <vector>

/*
Base class for champion
*/
class champion
{
public:

  /*
  * Calculate the remaining health of champion
  * @param[in]  date_string   pointer to vector
  * @returns int remaining life/health
  */
  int calculateRemainingHealth(std::vector<std::string> *date_string);

  /*
  *  calculateDamageTaken

  * @param[in] date   date and time
  * @returns val Total damage taken by respective champion
  */
  int calculateDamageTaken(tm * date);


protected:
  /*
  *  isChampionInvincible
  *   Wizards, Spirits are able to deceive the guards and pass through the gate without losing any HP.
  * @returns true if the champion is wizard or spirit
  */
  virtual  bool isChampionInvincible() const;

  /*constructor*/
  champion(int val = 100);

private:

  /*Get the intial health (Initial HP)*/
  int getInitialHealth() const;

  /*
  *  Initial health
  */
  const int initialHealth;

  /*
  *  holy days
  * @param[in]  wday weekday
  * @returns true if day is holy
  */
  bool holy_day(int wday) const;

  /*
  * Convert string to time format
  * @param[in]  str  string
  * @returns tm  time format
  */
  tm convertStringToTimeFormat(const std::string str);

  /*
  * Current HP of champion
  */
  int currentHP;

};
#endif