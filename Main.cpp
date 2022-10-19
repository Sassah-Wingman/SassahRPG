/* This program is intended to help the creator to practize the use of C++.
 * This is a RPG based game where a Player plays against the computer (performing a monster)
 * until one of them wins.
 * To reduce the odds and add some player influence to the outcome a choice will be presented to the player
 * during its turn.  Good look!  */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "SassahRPG.h"

 //--------------------------------------prototypes-------------------------------------//
void set_line();                                            // draw line function                                          
void set_space();                                           // include space      

 //--------------------------------test routines prototypes----------------------------//
//void test_random();


//--------------------------------------Main-------------------------------------//

int main() {

  // random seed implementation
  srand((unsigned int)time(NULL));

  // Introduction block
  std::string player_name{};
  std::cout << "Welcome to Sassah RPG" << std::endl;
  set_line();
  std::cout << "Please, say your name or type 'quit' to exit: ";
  std::cin >> player_name;
  set_line();
  if (player_name == "quit") {
    set_line();
    std::cout << "Bye!" << std::endl;
    set_line();
    exit(0);
    set_line();
  }

  // set player class block  
  std::cout << "OK " << player_name << ", first we need to pick the Hero Class.  You have 4 options as follows. Choose wisely:" << std::endl;
  set_space();
  std::cout << "1-Fighter gets an Attack Bonus." << std::endl;
  std::cout << "2-Wizard comes with more Magic." << std::endl;
  std::cout << "3-Rogue comes with a Defense Bonus." << std::endl;
  std::cout << "4-Cleric gets a Health Bonus." << std::endl;
  std::cout << "0-Exit!" << std::endl;
  set_space();

  int player_class{};
  std::cout << "Choose your Hero Class or type 0 to exit: ";
  std::cin >> player_class;
  set_space();

  Player* player_p = nullptr;
  Player* p = nullptr;

  switch (player_class) {
  case 1: {  std::cout << "Greate! You are a FIGHTER!" << std::endl;
    Player* player_p = new Player("Fighter", 100, 20, -1, 0);
    p = player_p;
    set_space();
    p->display_info();
    set_space();
    break;
  }
  case 2: {  std::cout << "Very Wise! Wizards are the best!" << std::endl;
    Player* player_p = new Player("Wizard", 80, 18, +1, 0);
    p = player_p;
    set_space();
    player_p->display_info();
    set_space();
    break;
  }
  case 3: {  std::cout << "Yeah! Rogue Rules!" << std::endl;
    Player* player_p = new Player("Rogue", 100, 16, 0, +1);
    p = player_p;
    set_space();
    player_p->display_info();
    set_space();
    break;
  }
  case 4: {  std::cout << "No Monster can deal with a Cleric!" << std::endl;
    Player* player_p = new Player("Cleric", 110, 18, 0, -1);
    p = player_p;
    set_space();
    player_p->display_info();
    set_space();
    break;
  }
  case 0: {  std::cout << "Very Well! See you next time!" << std::endl;
    break;
  }
  default:  std::cout << "This option is not available! Bye!" << std::endl;
  }
  set_line();

  //set Random Monster block
  int player_monster = (rand() % 4) + 1;
  std::cout << player_name << ", you are ready to enter the Dungeon.  Watch out!  There is somenthing moving towards you!" << std::endl;
  std::cout << "Hit any key and lets find out what it is...!" << std::endl;
  set_space();
  std::system("pause");
  set_space();

  Monster* monster_p = nullptr;
  Monster* m = nullptr;

  if (player_monster == 1) {
    std::cout << "An Undead! It has Life bonus!" << std::endl;
    Monster* monster_p = new Monster("Undead", 110, 8, 0, -1, 3);
    m = monster_p;
    set_space();
    monster_p->display_info();
    set_line();
  }
  else if (player_monster == 2) {
    std::cout << "An Ogre! Very good when Attacking!" << std::endl;
    Monster* monster_p = new Monster("Ogre", 100, 12, -1, +1, 2);
    m = monster_p;
    set_space();
    monster_p->display_info();
    set_line();
  }
  else if (player_monster == 3) {
    std::cout << "The Kobold! It got a Bonus for Defense!" << std::endl;
    Monster* monster_p = new Monster("Kobold", 90, 8, 0, +1, 1);
    m = monster_p;
    set_space();
    monster_p->display_info();
    set_line();
  }
  else if (player_monster == 4) {
    std::cout << "A Shadow! Its strength is Magic and Fear!" << std::endl;
    Monster* monster_p = new Monster("Shadow", 100, 10, +1, 0, 4);
    m = monster_p;
    set_space();
    monster_p->display_info();
    set_line();
  }

  set_space();
  std::cout << player_name << ", Lets attack it! Hit any key to throw the dice...! " << std::endl;
  set_space();
  std::system("pause");
  set_line();

  int damage{};

  do {
    p->attack_Action_P(p->health, p->attack, p->magic, damage);
    set_space();
    m->defense_Action_M(m->health, damage);
    if (m->health <= 0) {
      break;
    }
    set_line();
    m->attack_Action_M(m->attack, m->magic, m->fear, damage);
    set_space();
    p->defense_Action_P(p->health, damage);
    if (p->health <= 0) {
      break;
    }
    set_line();
  } while (p->health >= 0 && m->health >= 0);

  if (p->health <= 0) {
    std::cout << "You lost!" << std::endl;
  }
  else {
    std::cout << "You win!" << std::endl;
  }

  delete p;
  delete player_p;
  delete m;
  delete monster_p;
  return 0;
}





//---------------------------------Functions------------------------------------//


//draw line function
void set_line() {
  std::cout << " " << std::endl;
  std::cout << "*-------------------------------********----------------------------------*\n";
  std::cout << " " << std::endl;
}

// include space function  
void set_space() {
  std::cout << " " << std::endl;
}

//---------------------------------Test Routines------------------------------------//

//random number test routine
// void test_random ()  {
//for (int i =1; i <=100; i++)
//  std::cout << (rand()%20) + 1 << std::endl;
//}