#include"champion.hpp"
#include <ctime>

static champion *ptr = NULL;

/******************************************************************************
* con'r
******************************************************************************/
champion::champion(int val) :
  initialHealth(val)
{
  currentHP = val;
}

/******************************************************************************
* calculateDamageTaken
******************************************************************************/
int champion::calculateDamageTaken(tm *date)
{
  int returnVal = 0;

  //if the day is holy or the champion is invincible
  if (holy_day(date->tm_wday) || isChampionInvincible())
  {
    //do nothing
  }
  else
  {
    if ((date->tm_hour == 6)
      && (date->tm_min >= 0)
      && (date->tm_min <= 29))
    {
      returnVal = 7;
    }
    /* "Tiamat" goddess of Oceans spawned */
    else if ((date->tm_hour == 6)
      && (date->tm_min >= 30)
      && (date->tm_min <= 59))
    {
      returnVal = 18;
    }
    /* "Mithra" goddess of sun spawned */
    else if ((date->tm_hour == 7)
      && (date->tm_min >= 0)
      && (date->tm_min <= 59))
    {
      returnVal = 25;
    }
    /* "Warwick" God of war spawned */
    else if ((date->tm_hour == 8)
      && (date->tm_min >= 0)
      && (date->tm_min <= 29))
    {
      returnVal = 18;
    }
    /* "Kalista" demon of agony spawned */
    else if ((date->tm_hour >= 8)
      && (date->tm_hour <= 14)
      && (date->tm_min >= 30)
      && (date->tm_min <= 59))
    {
      returnVal = 7;
    }
    /* "Ahri" goddess of wisdom spawned */
    else if ((date->tm_hour == 15)
      && (date->tm_min >= 0)
      && (date->tm_min <= 29))
    {
      returnVal = 13;
    }
    // "Brand" god of fire spawned
    else if ((date->tm_hour == 15 && date->tm_min >= 30)
      || (date->tm_hour == 16 && date->tm_min <= 59))
    {
      returnVal = 25;
    }

    /* "Rumble" god of lightning spawned */
    else if ((date->tm_hour == 17)
      && (date->tm_min >= 0)
      && (date->tm_min <= 59))
    {
      returnVal = 18;
    }

    /* "Skarner" the scorpion demon spawned */
    else if ((date->tm_hour >= 18)
      && (date->tm_hour <= 19)
      && (date->tm_min >= 0)
      && (date->tm_min <= 59))
    {
      returnVal = 7;
    }

    /* "Luna" The goddess of the moon spawned */
    else if ((date->tm_hour == 20) &&
      (date->tm_min <= 59))
    {
      returnVal = 13;
    }
    else
    {
      // do nothing
    }
  }
  return returnVal;
}

/******************************************************************************
* isChampionInvincible
******************************************************************************/
bool champion::isChampionInvincible() const
{
  return false;
}
/******************************************************************************
* holy_day
* Tuesday : 2
* Thursday: 4
******************************************************************************/
bool champion::holy_day(int wday) const
{
  return (wday == 2 || wday == 4);
}

/******************************************************************************
* convertStringToTimeFormat
******************************************************************************/
tm champion::convertStringToTimeFormat(const std::string str)
{
  tm tmp;
  const char *tempStr = str.c_str();
  int yy, month, dd, hh, mm;
  sscanf_s(tempStr, "%d-%d-%d %d:%d", &yy, &month, &dd, &hh, &mm);

  tmp.tm_year = yy - 1990;
  tmp.tm_mon = month - 1;
  tmp.tm_mday = dd;
  tmp.tm_hour = hh;
  tmp.tm_min = mm;
  tmp.tm_sec = 0;
  tmp.tm_isdst = -1;
  time_t  tStart = mktime(&tmp);

  return tmp;
}

/******************************************************************************
* calculateRemainingHealth
******************************************************************************/
int champion::calculateRemainingHealth(std::vector<std::string> *date_string)
{
  int remainingHealth = 0;
  tm tempTm, pre_tm = { 0,0,0,0,0,0,0,0,0 };
  int damage, total_damage = 0;

  for (int i = 0; i < static_cast<int>(date_string->size()); i++)
  {
    //calculate the damage taken
    tempTm = convertStringToTimeFormat(date_string->at(i));
    damage = calculateDamageTaken(&tempTm);

    if ((tempTm.tm_year == pre_tm.tm_year) && (tempTm.tm_mon == pre_tm.tm_mon) && (tempTm.tm_mday == pre_tm.tm_mday))
    {
      //Check if champion should only lose HP once every hour//
      if (tempTm.tm_hour > pre_tm.tm_hour)
      {
        total_damage = total_damage + damage;
      }
    }
    else
    {
      total_damage = total_damage + damage;
    }
    pre_tm = tempTm;
  }
  //*Check HP of Champion
  if (total_damage >= getInitialHealth())
  {
    currentHP = 0;
  }
  else
  {
    currentHP -= total_damage;
  }

  std::cout << "Amount of health remained for a champion:" << currentHP << std::endl;

  return total_damage;
}


/******************************************************************************
* getInitialHealth
******************************************************************************/
int champion::getInitialHealth() const
{
  return initialHealth;
}

