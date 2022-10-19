#pragma once
#include <string>
#include <iostream>

class Entity {
public:
  std::string character;
  int health;
  int attack;
  int magic;
  int defense;

public:

  // Entity constructor prototype
  Entity(std::string character_v, int health_v, int attack_v, int magic_v, int defense_v);
  ~Entity() {}

public:
  virtual void display_info()
  {
    std::cout << "These are the " << character << " stats:" << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "Magic: " << magic << std::endl;
    std::cout << "Defenese: " << defense << std::endl;
    std::cout << "*-------------------------------********----------------------------------*\n";
  }

};

class Player : public Entity {

public:
  //Player contruct prototype    
  Player(std::string character_v, int health_v, int attack_v, int magic_v, int defense_v);
  ~Player() {}

  int attack_Action_P(int& health, int attack, int magic, int& damage_m) {
    int attack_dice = (rand() % attack) + 1;
    std::cout << "You rolled a D" << attack << " dice and got: " << attack_dice << std::endl;
    if (attack_dice == attack) {
      damage_m = (attack / 4) + magic + attack;
      std::cout << "Nice! You deliverd a Critical Hit: " << damage_m << std::endl;
      return damage_m;
    }
    else if (attack_dice == 1) {
      damage_m = 0;
      std::cout << "Oh no!  You delivered a Critical Miss....: " << damage_m << std::endl;
      char extra_a{ };
      std::cout << " " << std::endl;
      std::cout << "------------------------Take your chance!-------------------------" << std::endl;
      std::cout << " " << std::endl;
      std::cout << "You can try to delivery an extra attack.  You have a 70% chance of hit but If you fail you will get some damage." << std::endl;
      std::cout << "Do you want to try the EXTRA ATTACK? Type Y or N: ";
      std::cin >> extra_a;
      if (extra_a == 'y' || extra_a == 'Y') {
        int extra_dice = (rand() % 9) + 1;
        std::cout << extra_dice << std::endl;
        int extra_attack = 24 % extra_dice;
        std::cout << extra_attack << std::endl;
        if (extra_attack == 0) {
          damage_m = extra_dice;
          std::cout << "You hit! " << damage_m << " " << extra_dice << std::endl;
          return damage_m;
        }
        else {
          std::cout << health << std::endl;
          std::cout << extra_attack << std::endl;
          health = health - extra_attack;
          std::cout << health << std::endl;
          std::cout << "You missed and received a " << extra_attack << " penalty!" << std::endl;
          return damage_m;
        }
      }
      else {
        std::cout << "You choose NOT to try an extra attack." << std::endl;
      }
      return damage_m;
    }
    else {
      damage_m = attack_dice + magic;
      std::cout << "You delivered a hit of: " << damage_m << std::endl;
      return damage_m;
    }
  }

  void defense_Action_P(int& health_x, int& damage_p) {
    std::cout << "Your health was " << health_x << ". Received " << damage_p << " damage. Remains with " << (health - damage_p) << " health." << std::endl;
    health = health - damage_p;
  }
};

class Monster : public Entity {
public:
  int fear;
public:
  Monster(std::string character_v, int health_v, int attack_v, int magic_v, int defense_v, int fear_v);
  ~Monster() {}

public:
  virtual void display_info()
  {
    std::cout << "These are the " << character << " stats:" << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "Magic: " << magic << std::endl;
    std::cout << "Defenese: " << defense << std::endl;
    std::cout << "Fear: " << fear << std::endl;
    std::cout << "*-------------------------------********----------------------------------*\n";
  }

  int attack_Action_M(int attack_y, int magic_y, int fear_y, int& damage_p) {
    int attack_dice = (rand() % attack) + 1;
    std::cout << "Monster rolled a D" << attack << " dice and got: " << attack_dice << std::endl;
    if (attack_dice == attack) {
      damage_p = (attack / 4) + magic + fear + attack;
      std::cout << "Oh No! Monster deliverd a Critical Hit: " << damage_p << std::endl;
      return damage_p;
    }
    else if (attack_dice == 1) {
      damage_p = 0;
      std::cout << "Yes!  Monster delivered a Critical Miss....: " << damage_p << std::endl;
      return damage_p;
    }
    else {
      damage_p = attack_dice + magic + fear;
      std::cout << "Monster delivered a hit of: " << damage_p << std::endl;
      return damage_p;
    }
  }


  void defense_Action_M(int& health_x, int& damage_m) {
    std::cout << "Monster health was: " << health_x << ". Received " << damage_m << " and remains with health " << (health - damage_m) << std::endl;
    health = health - damage_m;
  }
};
