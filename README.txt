PURPOSE
Object-oriented programming can be used to model many real-world environments. In this lab you will have the opportunity to model players from a battle between the Righteous Rock Rollers, the Savvy Scissor Slingers, and the Postulating Paper Pushers. The players that you create will compete against one another in games of Rock, Paper, Scissors.

KEY READING
 • 8.4, 9.2 - 9.5, 9.8 - 9.9

BACKGROUND
There is a war to wage. There can only be one winner. Who will it be?!?!? In this lab you will be creating a rock paper scissors tournament. You will design a main to prompt the user to enter one of several different options. You will create a Player class, including both a .h and a .cpp file. You will create new Player * (pointers) and add them to a vector containing all the players. Certain players will then be chosen to fight. More details below.

PART 1 – MAIN.CPP AND PLAYER “.H” AND “.CPP” FILES IN YOUR PROJECT (5 POINTS)
Create these files first and get everything to compile using stubs before you move on to the next step.
 • You should have a Main.cpp file that contains main and will contain code that creates new Player * objects.
 • You will need two vectors that store pointers to Player objects (Player*) . These vectors should be declared inside of your main(). One of the vectors will contain all Players added to the program, the other will contain the line-up of the next Players to fight.
 • You should have a “.h” file that is included by the main “.cpp” file that describes your Player. You could call this Player.h, or you could choose any other name. Your main “.cpp” file will include this file to gain access to the Player class that you will create. This Player.h file will allow you to create Player objects within your main.
 • You will also need a “.cpp” file that will contain the implementation of your Player class. It will include the Player.h file and will then provide the implementation of the functions you need for a Player.
 • You may need other include(.h) files and implementation(.cpp) files, but you should have at least these three in your project.

PART 2 - CREATE YOUR MAIN(6 POINTS)
 • You need to have a ".cpp" that contains your main() function, as well as any helper functions you may choose to create. This is NOT the same file as Player.cpp.
 • Your main should have two different vectors. The vectors will contain Player * (assuming your class was named Player). The vectors can be declared in this way: vector<Player*> vectorName; If your class is named something other than Player, that word will replace Player.
 	◦ One vector (ALL PLAYERS) will be used to store all players that are added to the game.
 	◦ One vector (LINE-UP) will be used to store players that are chosen by the user from the vector containing all players. This vector will be the used as a queue, and whenever the fight option (explained below) is chosen, the next two players in this vector are to play RPS against one another and then removed from this vector.
 • Your main menu should contain these options (I would highly recommend that you make a function for each of these options):
	◦ Show Players - This will show all of the players in the game (this is everyone from the ALL PLAYERS vector). This should show their name, their wins, losses, and draws, and their winning record as a percentage.
  	◦ Add Player - This will prompt the user for the name of a new player, then create a Player 		* for that player and add them to the ALL PLAYERS vector. Each name may only exist once. Names with multiple words (separated by spaces) must be allowed.
  	◦ Add To Line-UP - This will prompt the user for a name. You must verify that this Player exists in the ALL PLAYERS vector, if he does, you will add a * (pointer) to the same Player in the LINE-UP vector.
  	◦ Show Line-up - This will show all of the players in the LINE-UP.
  	◦ Fight - This will take the first two players out of the LINE-UP (the two that have been in the longest) and will "fight" them. Fighting instructions are found below in Part 4. (This section does not need to be implemented until part 4.)

PART 3 - CREATE YOUR PLAYER (11 POINTS)
 • You need to create a Player class, which has (as stated above) both a ".h" and a ".cpp" file to go with it. Your Player class is required to have certain functions to perform specific tasks. Your Player class should have the following:
	 ◦ A constructor that can accept a string (name).  Your constructor may accept more parameters if you desire.
	 ◦ Private member variables to store the fighters:
      • name
 	   	• number of wins
 	   	• number of losses
 	   	• number of draws
 ◦ Different member functions to perform these tasks:
 		• getRPSThrow() - Randomize the selection of choosing rock, paper or scissors, and return the chosen "throw".
		• getWinRecord() - Get the player's win record, which should be the number of wins / all matches that player has fought in (should return a double).
    • toString() - Will return a string that has all of the information about the player. This will be very helpful for debugging the program.

PART 4 - FIGHT (8 POINTS)
 • You will take the first two players out of the LINE-UP vector. You must verify that there are at least two players in the vector before you begin a fight.
 • You will then simulate a fight between these two players by having each of them simulate an RPS "throw" by using the getRPSThrow() member function. You will compare the results, and the winner will increase his number of wins statistic, and the loser will increase his number of losses statistic. In the event of a draw, each player will increase his number of draws statistic.
 • If the two players at the front of the LINE-UP are the same person, the result is an automatic draw.
 • You can design the specifics of how a fight should look, but the fight between two players might look something like this:

Fight initiated between Name1 and Name2!

Name1 throws rock!
Name2 throws paper!

Name2 is the winner!


REQUIREMENT NOTES

GENERAL
 • You must have a constructor and the three specified functions and the four specified variables for your object. You are also required to use only private member variables.
 • You must ensure that each Player has a unique name.
 • A Player can fight himself if that Player is found in the first two spots of the LINE-UP vector.
 • getRPSThrow() - This can be implemented however you wish as long as the result returned is random. One suggestion would be to randomly generate an integer between 1-3 and return that number. Have each number correspond to one of the three "throw" options, Rock, Paper, or Scissors. Use the returned ints to determine who won the battle and what was "thrown".
 • You must have at least 3 separate files for this lab (1 ".h" file, and 2 ".cpp" files)
 • You are required to use pointers in this lab to store your Players in the vectors.
 • Remember that all code included in your project must be written by you. You can work with other students on the ideas, but the code should all be your own.
 • In order to include your Player ".h" in your Main.cpp and your Player .cpp, do this: "#include "Player.h"