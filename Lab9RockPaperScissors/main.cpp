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
void showMenu (string& userInput) {
  bool done = false; //checks for valid user input
  while (!done) {
    if (userInput != "") {cout << "\n\n";} //prints extra lines for aesthetics, if it is not the first time printing the menu
    
    cout << "\tT H E   M E N U\n";
    
    cout << "\n [1] \tShow Player List";
    cout << "\n [2] \tShow Player Line Up";
    cout << "\n [3] \tAdd Player to List";
    cout << "\n [4] \tAdd Player to Line Up";
    cout << "\n [5] \tFight";
    cout << "\n [q] \tQuit";
    cout << "\n\nInput: ";
    
    cin.clear(); cin >> userInput; cin.ignore();
    
    if (userInput == "1" || userInput == "2" || userInput == "3" || userInput == "4" || userInput == "5" || userInput == "q") {
      done = true;
    }
    else {
      cout << "\nInvalid input.";
    }
  }
}

void showPlayerList (vector<Player*> playerList) {
  if (playerList.size() == 0) {cout << "\nNo players in list.\n\n";}
  else {cout << "\nCurrent Player List:\n";}
  for (int i = 0; i < playerList.size(); i++) {
    cout << playerList[i]->toString() << endl;
  }
}

int main(int argc, const char * argv[]) { 
  vector<Player*> playerList, queue;
  string userInput = "";
  bool shouldQuit = false;
  while (!shouldQuit) {
    showMenu(userInput);
    if (userInput == "q") {
      cout << "\nGoodbye.";
      shouldQuit = true;
    }
    else if (userInput == "1") {
      
    }
    else if (userInput == "2") {
      
    }
    else if (userInput == "3") {
      
    }
    else if (userInput == "4") {
      
    }
    else if (userInput == "5") {
      
    }
  return 0;
  }
}
