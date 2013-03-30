//
//  Pet.cpp
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#include "Pet.h"

Pet::Pet(float _maxHP, float _maxAttack, float _maxDefense, TypeIA _mode) :
maxHP(_maxHP), maxAttack(_maxAttack), maxDefense(_maxDefense),
hp(_maxHP), attack(_maxAttack), defense(_maxDefense), engine(_mode), lastMove(0), pass(false) {}

Pet::Pet(float _maxHP, float _maxAttack, float _maxDefense, TypeIA _mode,std::vector<float> encode) :
maxHP(_maxHP), maxAttack(_maxAttack), maxDefense(_maxDefense),
hp(_maxHP), attack(_maxAttack), defense(_maxDefense), engine(_mode,encode), lastMove(0), pass(false) {}

Pet::Pet(float _maxHP, float _maxAttack, float _maxDefense, TypeIA _mode,const char * file) :
maxHP(_maxHP), maxAttack(_maxAttack), maxDefense(_maxDefense),
hp(_maxHP), attack(_maxAttack), defense(_maxDefense), engine(_mode,file), lastMove(0), pass(false) {}


Pet::Pet(std::vector<FormulaValue>values,TypeIA _mode) :  engine(_mode), lastMove(0), pass(false) {
    
    for (int i = 0; i < (int) values.size(); i++) {
        setStatByFormula(values[i]);
    }
    
}
Pet::Pet(std::vector<FormulaValue>values, TypeIA _mode,std::vector<float> encode): engine(_mode,encode), lastMove(0), pass(false){
    for (int i = 0; i < (int) values.size(); i++) {
        setStatByFormula(values[i]);
    }
}
Pet::Pet(std::vector<FormulaValue>values, TypeIA _mode,const char * file) :engine(_mode,file), lastMove(0), pass(false){
    for (int i = 0; i < (int) values.size(); i++) {
        setStatByFormula(values[i]);
    }
}

void Pet::setStatByFormula(FormulaValue valuesFor){
    
    switch (valuesFor.stat) {
        case HP:
            maxHP = ((valuesFor.IV + (2*valuesFor.Base) + (valuesFor.EV /4) + 100)*valuesFor.Level/100 ) + 10 + valuesFor.Extra;
            hp = maxHP;
            break;
        case ATTACK:
            maxAttack = (((valuesFor.IV + (2*valuesFor.Base) + (valuesFor.EV /4))*valuesFor.Level/100 ) + 5)*valuesFor.Nature + valuesFor.Extra;
            attack = maxAttack;
            break;
        case DEFENSE:
            maxDefense = (((valuesFor.IV + (2*valuesFor.Base) + (valuesFor.EV /4))*valuesFor.Level/100 ) + 5)*valuesFor.Nature + valuesFor.Extra;
            defense = maxDefense;
            break;
        default:
            break;
    }

    
}

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

void Pet::resetStats(){

    hp = maxHP;
    attack = maxAttack;
    defense = maxDefense;
    lastMove = 0;
    
    for (int i = 0; i < (int)moves.size(); i++) {
        moves[i]->resetMove();
    }
    
}
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
        pass = true;
        return ss.str();
    }
    
    // Usa el movimiento
    moves[n]->effect(this, foe);
    lastMove = n;
    
    //std::cout << n << std::endl << std::endl;
    
    std::stringstream ss;
    ss << name << " ha usado " << moves[n]->name << "!";
    return ss.str();
}



int Pet::getNumMoves()
{
    return (int)moves.size();
}

int Pet::getMaxHP()
{
    return maxHP;
}

int Pet::getHP()
{
    return hp;
}

int Pet::getAttack()
{
    return attack;
}

int Pet::getDefense()
{
    return defense;
}

int Pet::getLastMove(){
    
    return lastMove;
}
void Pet::setHP(int _hp)
{
    hp += _hp;
    
    // Reiniciar a los limites
    if (hp < 0)
        hp = 0;
    else if (hp > maxHP)
        hp = maxHP;
}

void Pet::setDefense(int _defense)
{
    defense += _defense;
    
    // Reiniciar a los limites
    if (defense < 0)
        defense = 0;
    else if (defense > maxDefense)
        defense = maxDefense;
}

void Pet::setAttack(int _attack)
{
    attack += _attack;
    
    // Reiniciar a los limites
    if (attack < 0)
        attack = 0;
    else if (attack > maxAttack)
        attack = maxAttack;
}

void Pet::setLastMovePP(int _pp)
{
    moves[lastMove]->setPP(_pp);
}

std::string Pet::toString()
{
    std::stringstream ss;
    ss << "    HP = " << hp << "/" << maxHP << "\n";
    ss << "    Atk = " << attack << "/" << maxAttack << "\n";
    ss << "    Def = " << defense << "/" << maxDefense;
    return ss.str();
}
