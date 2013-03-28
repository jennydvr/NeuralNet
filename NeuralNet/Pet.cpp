//
//  Pet.cpp
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#include "Pet.h"

Pet::Pet(float _maxHP, float _maxAttack, float _maxDefense, int _mode) :
maxHP(_maxHP), maxAttack(_maxAttack), maxDefense(_maxDefense),
hp(_maxHP), attack(_maxAttack), defense(_maxDefense), engine(_mode), lastMove(0) {}

#ifdef Cocos2d

void Pet::init(const char* name)
{
    sprite = cocos2d::CCSprite::create(name);
    sprite->setScale(0.5f);
}

cocos2d::CCSprite* Pet::getSprite()
{
    return sprite;
}
#endif

std::string Pet::useMove(int n, Pet *foe)
{
    // Chequea si se puede usar el movimiento
    if (moves[n]->getPP() <= 0)
        return "NO";
    
    // Usa el movimiento
    moves[n]->effect(this, foe);
    lastMove = n;
    
    std::stringstream ss;
    ss << name << " ha usado " << moves[n]->name << "!";
    return ss.str();
}

std::string Pet::useMove(Pet *foe)
{
    int n = engine.chooseMove(*this, *foe);
    
    // Si n == -1, no hay acciones disponibles (pasa)
    if (n == -1) {
        std::stringstream ss;
        ss << name << " ha pasado, no le quedan movimientos!";
        return ss.str();
    }
    
    // Usa el movimiento
    moves[n]->effect(this, foe);
    lastMove = n;
    
    std::cout << n << std::endl;
    
    std::stringstream ss;
    ss << name << " ha usado " << moves[n]->name << "!";
    return ss.str();
}



int Pet::getNumMoves()
{
    return (int)moves.size();
}

float Pet::getMaxHP()
{
    return maxHP;
}

float Pet::getHP()
{
    return hp;
}

float Pet::getAttack()
{
    return attack;
}

float Pet::getDefense()
{
    return defense;
}

int Pet::getLastMove(){
    
    return lastMove;
}
void Pet::setHP(float _hp)
{
    hp += _hp;
    
    // Reiniciar a los limites
    if (hp < 0)
        hp = 0;
    else if (hp > maxHP)
        hp = maxHP;
}

void Pet::setDefense(float _defense)
{
    defense += _defense;
    
    // Reiniciar a los limites
    if (defense < 0)
        defense = 0;
    else if (defense > maxDefense)
        defense = maxDefense;
}

void Pet::setAttack(float _attack)
{
    attack += _attack;
    
    // Reiniciar a los limites
    if (attack < 0)
        attack = 0;
    else if (attack > maxAttack)
        attack = maxAttack;
}

void Pet::setLastMovePP(float _pp)
{
    moves[lastMove]->setPP(_pp);
}

std::string Pet::toString()
{
    std::stringstream ss;
    ss << "HP = " << hp << "/" << maxHP << "\n";
    ss << "Atk = " << attack << "/" << maxAttack << "\n";
    ss << "Def = " << defense << "/" << maxDefense;
    return ss.str();
}
