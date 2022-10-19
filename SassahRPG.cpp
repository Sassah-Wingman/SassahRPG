#include "SassahRPG.h"

// Base constructor and initialization list
Entity::Entity(std::string character_v, int health_v, int attack_v, int magic_v, int defense_v)
  : character{ character_v }, health{ health_v }, attack{ attack_v }, magic{ magic_v }, defense{ defense_v } {}

// Player constructor and initialization list       
Player::Player(std::string character_v, int health_v, int attack_v, int magic_v, int defense_v)
  : Entity{ character_v, health_v, attack_v, magic_v, defense_v } {}

// Monster constructor and initialization list      
Monster::Monster(std::string character_v, int health_v, int attack_v, int magic_v, int defense_v, int fear_v)
  : Entity{ character_v, health_v, attack_v, magic_v, defense_v }, fear{ fear_v } {}
