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
Player::Player(string nameIn) {
  name = nameIn;
  wins = 0;
  losses = 0;
  draws = 0;
  matches = 0;
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
double Player::getWinRecord() {
  return winRecord;
}
string Player::getRPSThrow() {
//randomize here
  return throwChoice;
}
//---------------------------------------------------------------------------------------
int Player::updateWins(int winsIn) {
  wins = winsIn;
  wins++; matches++;
  updateWinRecord(winRecord);
  return wins;
}
int Player::updateLosses(int lossesIn) {
  losses = lossesIn;
  losses++; matches++;
  updateWinRecord(winRecord);
  return losses;
}
int Player::updateDraws(int drawsIn) {
  draws = drawsIn;
  draws++; matches++;
  updateWinRecord(winRecord);
  return draws;
}
//---------------------------------------------------------------------------------------
double Player::updateWinRecord(double winRecordIn) {
  winRecordIn = winRecordIn / matches;
  winRecord = winRecordIn; //technically dont need this line... can return winRecordIn
  return winRecord;
}
//---------------------------------------------------------------------------------------
string Player::toString() {
  stringstream ss;
  ss << "Name: " << name << endl;
	ss << "Wins: " << wins; ss << "/Losses: " << losses; ss << "/Draws: " << draws << endl;
  ss << "Win Record: " << winRecord;
	return ss.str();
}