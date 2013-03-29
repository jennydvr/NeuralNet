//
//  Move.h
//  Neuralmon
//
//  Created by Jenny Valdez on 28/03/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#ifndef __Neuralmon__Move__
#define __Neuralmon__Move__

#include <iostream>
#include <sstream>

class Pet;

class Move {
protected:
    
    // Maximos stats
    float maxPP;
    float maxPower;
    
    // Stats
    float pp;
    float power;
    
public:
    
    // Nombre del movimiento
    std::string name;
    
    // Constructor
    Move(float _maxPP, float _maxPower = 0);
    
    // Efecto de la accion
    virtual void effect(Pet *me, Pet *foe) = 0;
    
    // Convierte a string
    std::string toString();
    
    // Setters
    void setPP(int _pp);
    
    // Getters
    float getPP();
    
    void resetMove();
};

#endif /* defined(__Neuralmon__Move__) */
