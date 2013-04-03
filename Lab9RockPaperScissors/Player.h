//
//  Player.h
//  
//
//  Created by William Myers on 4/1/13.
//
//
#ifndef _Player_h
#define _Player_h

#include <string>
#include <sstream>
#include <vector>
//#include <fstream>
#include <algorithm> //for myVector.erase() & myVector.find()
using namespace std;

class Player {
private:
  string name;
  int wins;     
  int losses;   
  int draws;
  int matches;
  double winRecord;

  string throwChoice;
//-----------------------------------------------------------------------------------------
  double updateWinRecord(double winRecordIn);

//-----------------------------------------------------------------------------------------
public:
//Constructor/Destructor
//param name player's name
//param wins player's win count
//param losses player's loss count
//param draws player's draw count
  Player(string nameIn);
  virtual ~Player();
//-----------------------------------------------------------------------------------------
//each gets the respective variable and returns it
  string getName();
  int getWins();
  int getLosses();
  int getDraws();
  double getWinRecord();
  string getRPSThrow();
//---------------------------------------------------------------------------------------
  int updateWins(int winsIn);
  int updateLosses(int lossesIn);
  int updateDraws(int drawsIn);
//---------------------------------------------------------------------------------------
  string toString();
//  idk if its smart to use these bc they need object pointers from the same class to function  
//  vector<Player*> addToList(vector<Player*> playerList, string name);
//  vector<Player*> addToQueue(vector<Player*> queue);

};
#endif

