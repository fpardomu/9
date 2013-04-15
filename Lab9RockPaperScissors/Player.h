//
//  Player.h
//  
//
//  Created by William Myers on 4/1/13.
//
//
#ifndef _Player_h
#define _Player_h

#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <ctime>//for srand()
//*****************************************************************************************
class Player {
private:
  std::string name; 
  int wins; 
  int losses; 
  int draws; 
  int matches; 
  double winRecord; 
  long throwNum; 
  std::array<std::string, 4> throwChoice = {"rock", "paper", "scissors"};
//=========================================================================================
public:
  //Constructor/Destructor
  Player(std::string nameIn);
  virtual ~Player();
//-----------------------------------------------------------------------------------------
  std::string getName();
  int getWins();
  int getLosses();
  int getDraws();
  double getWinRecord();
  long getRPSThrowNum();
  std::string getRPSThrow(); //returns the name of the throw ("rock", "paper", "scissors")
//-----------------------------------------------------------------------------------------
  double updateWinRecord();
  int updateWins();
  int updateLosses();
  int updateDraws();
  long throwRPS();//simulates a throw by randomly "choosing" a number 0,1,2
//-----------------------------------------------------------------------------------------
  std::string toString();
//*****************************************************************************************


};
#endif

