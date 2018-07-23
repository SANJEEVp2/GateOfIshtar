#include <algorithm>
#include "humanChampion.hpp"
#include "VampireChampion.hpp"
#include "GiantChampion.hpp"
#include "SpiritChampion.hpp"
#include "WizardChampion.hpp"
#include <assert.h>
#include <iostream>
#include <vector>
#define MAX_NO_TIME 4
using namespace std;



/****************************************************
* Handle Champion
*****************************************************/
champion* handleChampion(string str)
{
  champion *Chap = NULL;

  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  const char *tempStr = str.c_str();

  if (strcmp(tempStr, "human") == 0)
  {
    Chap = new humanChampion();
  }
  else if (strcmp(tempStr, "spirit") == 0)
  {
    Chap = new SpiritChampion();
  }
  else if (strcmp(tempStr, "wizard") == 0)
  {
    Chap = new WizardChampion();
  }
  else if (strcmp(tempStr, "giant") == 0)
  {
    Chap = new GiantChampion();
  }
  else if (strcmp(tempStr, "vampire") == 0)
  {
    Chap = new VampireChampion();
  }
  else
  {
    cout << "Invalid Champion" << endl;
  }
  return Chap;
}

int main()
{
#ifdef DEBUG



  vector<string> strVec = { "2018-07-22 07:45","2018-07-23 07:45","2018-07-24 12:00", "2018-07-24 00:15" };
  vector<string> strVec1 = { "2018-08-xx 0x:xx" };
  vector<string> strVec2 = { "2018-06-13 07:30", "2018-06-13 07:21", "2018-06-13 07:58", "2018-06-13 07:45" };

  cout << "==========Test1:Check normal flow============== \n";
  champion *myPtr = handleChampion("human");
  champion *myPtr2 = handleChampion("wizard");
  champion *myPtr3 = handleChampion("SPIRIT");
  champion *myPtr4 = handleChampion("GiaNt");

  if (static_cast<champion *>(NULL) != myPtr)
  {
    cout << "Total Damage of human is:" << myPtr->calculateRemainingHealth(&strVec) << endl;
  }

  if (static_cast<champion *>(NULL) != myPtr2)
  {
    cout << "Total Damage of wizard is:" << myPtr2->calculateRemainingHealth(&strVec) << endl;
  }

  if (static_cast<champion *>(NULL) != myPtr3)
  {
    cout << "Total Damage of spirit is:" << myPtr3->calculateRemainingHealth(&strVec) << endl;
  }

  if (static_cast<champion *>(NULL) != myPtr4)
  {
    cout << "Total Damage of giant is:" << myPtr4->calculateRemainingHealth(&strVec) << endl;
  }

  cout << "==========Test2:Check wrong input champion's name==============  \n";
  champion *myPtr5 = handleChampion("warrior");

  if (static_cast<champion *>(NULL) != myPtr5)
  {
    cout << "Total Damage is:" << myPtr5->calculateRemainingHealth(&strVec) << endl;
  }
  else
  {
    cout << "Invalid input" << endl;
  }

  cout << "==========Test3:Check wrong date_string_intervals==============  \n";
  cout << "Total Damage is:" << myPtr->calculateRemainingHealth(&strVec1) << endl;

#endif // DEBUG

  return 0;
}