//
//  Pet.h
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#ifndef __Neuralmon__Pet__
#define __Neuralmon__Pet__
//#define Cocos2d

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
    int maxHP;
    int maxAttack;
    int maxDefense;
    
    // Stats actuales
    int hp;
    int attack;
    int defense;
    
    // Ultimo movimiento usdo
    int lastMove;
    
    // Agrega los movimientos
    virtual void addMoves() = 0;
    
public:
    
    void resetStats();
    // Pasa
    bool pass;
    
    // Lista de movimientos
    std::vector<Move *> moves;
    
    // Engine
    AiEngine engine;
    
    // Constructor
    Pet(float _maxHP, float _maxAttack, float _maxDefense, int _mode);
    Pet(float _maxHP, float _maxAttack, float _maxDefense, int _mode,std::vector<float> encode);
    Pet(float _maxHP, float _maxAttack, float _maxDefense, int _mode,const char * file);


    
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
    int getMaxHP();
    int getHP();
    int getAttack();
    int getDefense();
    int getNumMoves();
    int getLastMove();
    // "Setters" - dependen de los efectos activos
    void setHP(int _hp);
    void setDefense(int _defense);
    void setAttack(int _attack);
    void setLastMovePP(int _pp);
    
    // Retorna el pet en string
    std::string toString();
    
};

#endif /* defined(__Neuralmon__Pet__) */
