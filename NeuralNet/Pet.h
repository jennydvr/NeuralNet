//
//  Pet.h
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#ifndef __Neuralmon__Pet__
#define __Neuralmon__Pet__


#include <iostream>
#include <vector>
#include <sstream>
#ifdef Cocos2d
#include "cocos2d.h"
#endif
#include "Move.h"
#include "AiEngine.h"

class Pet {
protected:
    
    // Nombre del pet
    std::string name;
#ifdef Cocos2d
    // Imagen de la mascota
    cocos2d::CCSprite *sprite;
#endif
    // Maximos stats
    float maxHP;
    float maxAttack;
    float maxDefense;
    
    // Stats actuales
    float hp;
    float attack;
    float defense;
    
    // Ultimo movimiento usdo
    int lastMove;
    
    // Agrega los movimientos
    virtual void addMoves() = 0;
    
public:
    
    // Lista de movimientos
    std::vector<Move *> moves;
    
    // Engine
    AiEngine engine;
    
    // Constructor
    Pet(float _maxHP, float _maxAttack, float _maxDefense, int _mode);
    
    // Inicializa la mascota
    void init(const char* name);
    
    // Usa un movimiento
    std::string useMove(int num, Pet *foe);
    
    // Usa un movimiento escogido
    std::string useMove(Pet *foe);
    
    
    // Getters
#ifdef Cocos2d
    cocos2d::CCSprite* getSprite();
#endif
    float getMaxHP();
    float getHP();
    float getAttack();
    float getDefense();
    int getNumMoves();
    int getLastMove();
    // "Setters" - dependen de los efectos activos
    void setHP(float _hp);
    void setDefense(float _defense);
    void setAttack(float _attack);
    void setLastMovePP(float _pp);
    
    // Retorna el pet en string
    std::string toString();
    
};

#endif /* defined(__Neuralmon__Pet__) */
