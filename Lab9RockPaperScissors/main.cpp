//
//  main.cpp
//  Lab9RockPaperScissors
//
//  Created by William Myers on 3/26/13.
//  Copyright (c) 2013 William Myers. All rights reserved.
//
#include <iostream>
#include "Player.h"//contains all other necessary .h files
using namespace std;
//Gets user menu input, reprompts if user input is invalid
string showMenu () {
  string userInput;
  bool done = false; //checks for valid user input
  while (!done) {
      cout << "\tT H E   M E N U\n";
      
      cout << "\n [1] \tShow player list";
      cout << "\n [2] \tShow player line up";
      cout << "\n [3] \tAdd player to the player list";
      cout << "\n [4] \tAdd player to the line up";
      cout << "\n [5] \tFight";
      cout << "\n [q] \tQuit";
      cout << "\n\nInput: ";
      
      cin.clear(); cin >> userInput; cin.ignore();
      
      if (userInput == "1" || userInput == "2" || userInput == "3" || userInput == "4" || userInput == "5" || userInput == "q") {
        done = true;
      }
      else {
        cout << "\nInvalid input.\n\n";
      }
  }
  return userInput;
}
//Return iterator pointing to element that matches nameIN if it doesnt exist return NULL, also update iterator it
Player* searchList (vector <Player*>& playerList, string nameIn, int& it) {
  for (it = 0; it < playerList.size(); ++it) {
    if (playerList[it] -> getName() == nameIn) {
      return playerList[it];
    }
  }
  return NULL;
}
//displays the param listIn which represents either the playerList or the queue 
void showListIn (vector<Player*> listIn, string currentList) {
  if (listIn.size() == 0) {cout << "\nNo players in the " << currentList << ".";}
  else {cout << "\nCurrent  " << currentList << ":\n";}
  for (int i = 0; i < listIn.size(); i++) {
    cout << "\n" << listIn[i]->toString() << "\n";
  }
}
//Adds player to the param listIn which represents either the playerList or the queue
void addPlayer (vector <Player*>& listIn, string currentList) {
  int it = 0; string name;
  cout << "\nPlayer's name to add to the " << currentList << "? ";
  getline(cin, name);
  Player* newPlayer = new Player(name); //create an object pointer
  if (!searchList(listIn, name, it)) {//only add newPlayer if searchList returns NULL (playerList does not have Player already)
    listIn.push_back(newPlayer); //put object pointer into a vector of Player pointers
    cout << name << " added sucessfully to the " << currentList << ".";
  }
  else if (searchList(listIn, name, it)) {
    cout << "Player not added.\n" << name << " is already in the " << currentList << ".\n";
  }
}

int main(int argc, const char * argv[]) { 
  vector<Player*> playerList, queue;
  bool shouldQuit = false;
  while (!shouldQuit) {
    string menuChoice = showMenu();
    if (menuChoice == "1") {
      showListIn (playerList, "player list");
    }
    else if (menuChoice == "2") {
      showListIn (queue, "line up");
    }
    else if (menuChoice == "3") {
      addPlayer(playerList, "player list");
    }
    else if (menuChoice == "4") {
      addPlayer(queue, "line up");
    }
    else if (menuChoice == "5") {
      
    }
    else if (menuChoice == "q") {
      cout << "\nGoodbye.";
      shouldQuit = true;
    }
    cout << "\n\n"; //prints blank lines for aesthetics, if it is not the first time printing the menu
  }
  return 0;
}
