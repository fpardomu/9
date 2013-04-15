//
//  main.cpp
//  Lab9RockPaperScissors
//
//  Created by William Myers on 3/26/13.
//  Copyright (c) 2013 William Myers. All rights reserved.
//
#include "Player.h"
//*****************************************************************************************
//Gets user menu input, reprompts if user input is invalid
int showMenu () {
  int userInput;
  bool done = false; //checks for valid user input
  while (!done) {
      std::cout << "\tT H E   M E N U\n";
      
      std::cout << "\n [1] \tShow player list";
      std::cout << "\n [2] \tShow player line up";
      std::cout << "\n [3] \tAdd player to the player list";
      std::cout << "\n [4] \tAdd player to the line up";
      std::cout << "\n [5] \tFight";
      std::cout << "\n [0] \tQuit";
      std::cout << "\n\nInput: ";
      
      std::cin.clear(); std::cin >> userInput; std::cin.ignore();
      
      if (userInput == 1 || userInput == 2 || userInput == 3 || userInput == 4 || userInput == 5 || userInput == 0) {
        done = true;
      }
      else {
        std::cout << "\nInvalid input.\n\n";
      }
  }
  return userInput;
}
//-----------------------------------------------------------------------------------------
//displays the param listIn which represents either the playerList or the queue
void showListIn (std::vector<Player*> listIn, std::string currentList) {
  if (listIn.size() == 0) {std::cout << "\nNo players in the " << currentList << ".";}
  else {std::cout << "\nCurrent  " << currentList << ":\n";}
  for (int i = 0; i < listIn.size(); i++) {
    std::cout << "\n" << listIn[i]->toString() << "\n";
  }
}
//-----------------------------------------------------------------------------------------
//Return iterator pointing to element that matches nameIN if it doesnt exist return NULL, also update iterator it
Player* searchList (std::vector <Player*>& listIn, std::string nameIn, int& it) {
  for (it = 0; it < listIn.size(); ++it) {
    if (listIn[it] -> getName() == nameIn) {
      return listIn[it];
    }
  }
  return NULL;
}
//-----------------------------------------------------------------------------------------
//Adds Player to the param playerList or to the param queue based on the value of param currentList
void addPlayer (std::vector <Player*>& playerListIn, std::vector <Player*>& queueIn, std::string currentList) {
  int it = 0; std::string name;
  std::cout << "\nPlayer's name to add to the " << currentList << "? ";
  std::getline(std::cin, name);
  if (!searchList(playerListIn, name, it) && currentList == "player list") {//only add newPlayer if searchList returns NULL 
    Player* newPlayer = new Player(name); //create an object pointer (Player*)
    playerListIn.push_back(newPlayer); //add Player* to playerList
    std::cout << name << " added sucessfully to the " << currentList << ".";
  }
  else if (searchList(playerListIn, name, it) && currentList == "line up") {//only add Player* if searchList returns a Player*
    queueIn.push_back(searchList(playerListIn, name, it)); //add Player* to queue
    std::cout << name << " added sucessfully to the " << currentList << ".";
  }
  else if (!searchList(playerListIn, name, it) && currentList == "line up") {
    std::cout << "Player not added.\n" << name << " is not in the player list.\n";
  }
  else if (searchList(playerListIn, name, it) && currentList == "player list") {
    std:std::cout << "Player not added.\n" << name << " is already in the player list.\n";
  }
}
//-----------------------------------------------------------------------------------------
//start the rock paper scissors fight only if more than two people are in the queue
bool fight (std::vector<Player*>& queue) {
  if (queue.size() <= 1) {
    std::cout << "\nMust have at least two players to start the fight";
    return false;
  }
  else {
    std::cout << "\n" << queue[0] -> getName() << " threw " << queue[0] -> getRPSThrow() << "\n";
    std::cout << queue[1] -> getName() << " threw " << queue[1] -> getRPSThrow() << "\n\n";
    //calculate the winner and update stats
    switch (((3 + (queue[0] -> getRPSThrowNum()) - (queue[1] -> getRPSThrowNum())) % 3)) {
      case 0:
        std::cout << "Its a tie.\n";
        queue[0] -> updateDraws();
        queue[1] -> updateDraws();
        break;
      case 1:
        std::cout << queue[0] -> getName() << " wins!\n";
        queue[0] -> updateWins();
        queue[1] -> updateLosses();
        break;
      case 2:
        std::cout << queue[1] -> getName() << " wins!\n";
        queue[1] -> updateWins();
        queue[0] -> updateLosses();
        break;
    }
  }
  queue.erase(queue.begin(), queue.begin()+2); //removes the first two players from queue
  return true;
}
//=========================================================================================
int main(int argc, const char * argv[]) {
  std::srand(static_cast<unsigned int>(time(nullptr)));
  std::vector<Player*> playerList, queue;
  bool shouldQuit = false;  
  while (!shouldQuit) {
    int menuChoice = showMenu();
    switch (menuChoice) {
      case 0:
        std::cout << "\nGoodbye.";
        shouldQuit = true;
        break;
      case 1:
        showListIn (playerList, "player list");
        break;
      case 2:
        showListIn (queue, "line up");
        break;
      case 3:
        addPlayer(playerList, queue, "player list");
        break;
      case 4:
        addPlayer(playerList, queue, "line up");
        break;
      case 5:
        fight(queue);
        break;
    }
    std::cout << "\n\n"; //prints blank lines for aesthetics, if it is not the first time printing the menu
  }
  return 0;
}
