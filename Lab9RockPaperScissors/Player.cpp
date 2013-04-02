//
//  Player.cpp
//  Lab9RockPaperScissors
//
//  Created by William Myers on 4/2/13.
//  Copyright (c) 2013 William Myers. All rights reserved.
//
#include "Player.h"
using namespace std;
//---------------------------------------------------------------------------------------
Player::Player(string nameIn, int winsIn, int lossesIn, int drawsIn) {
  name = nameIn;
  wins = winsIn;
  losses = lossesIn;
  draws = drawsIn;
}
Player::~Player(){}
//---------------------------------------------------------------------------------------
string Player::getName() {
  return name;
}
int Player::getWins() {
  return wins;
}
int Player::getLosses() {
  return losses;
}
int Player::getDraws() {
  return draws;
}
//---------------------------------------------------------------------------------------
double Player::getWinRecord() {
  winRecord = wins / matches;
  return winRecord;
}
string Player::getRPSThrow() {
  //randomize here
  return throwChoice;
}

//---------------------------------------------------------------------------------------
string Player::toString() {
  stringstream ss;
  ss << "Name: " << name << endl;
	ss << "Wins: " << wins; ss << "/Losses: " << losses; ss << "/Draws: " << draws << endl;
  ss << "Win Record: " << winRecord;
	return ss.str();
}