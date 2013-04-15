//
//  Player.cpp
//  Lab9RockPaperScissors
//
//  Created by William Myers on 4/2/13.
//  Copyright (c) 2013 William Myers. All rights reserved.
//
#include "Player.h"

//*****************************************************************************************
Player::Player(std::string nameIn) {
  name = nameIn;
  wins = 0;
  losses = 0;
  draws = 0;
  matches = 0;
  throwNum = Player::throwRPS(); //initialize throwNum with a simulated throw
}
Player::~Player(){}
//=========================================================================================
std::string Player::getName() {
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
long Player::getRPSThrowNum() {
  return throwNum;
}
std::string Player::getRPSThrow() {
  return throwChoice.at(throwNum);
}
//---------------------------------------------------------------------------------------
long Player::throwRPS() {
//  throwNum = rand() / (((RAND_MAX * 1.0)) * 3 + 1); //makes probability of each more even vs. rand()%4
  throwNum = rand()%3; //generate psuedorandom number between 0 & 2
//  should use std::mersenne_twister_engine, Defined in header <random> instead or boost::random_device or others
//  std::cerr << "_ThrowNum_" << throwNum << "\n";
  return throwNum;
}
//---------------------------------------------------------------------------------------
int Player::updateWins() {
  wins++; matches++;
  updateWinRecord();
  return wins;
}
int Player::updateLosses() {
  losses++; matches++;
  updateWinRecord();
  return losses;
}
int Player::updateDraws() {
  draws++; matches++;
  updateWinRecord();
  return draws;
}
double Player::updateWinRecord() {
  winRecord = wins / matches;
  return winRecord;
}

//---------------------------------------------------------------------------------------
std::string Player::toString() {
  std::stringstream ss;
  ss << "Name: " << name << "\n";
	ss << "Wins: " << wins; ss << " / Losses: " << losses; ss << " / Draws: " << draws << "\n";
  ss << "Win Record: " << winRecord;
	return ss.str();
}