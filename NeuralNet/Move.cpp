//
//  Move.cpp
//  NeuralNet
//
//  Created by Jenny Valdez on 28/03/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#include "Move.h"

Move::Move(float _maxPP, float _maxPower) : maxPP(_maxPP),  maxPower(_maxPower), pp(_maxPP), power(_maxPower) {}

std::string Move::toString()
{
    std::stringstream ss;
    ss << name << "\n";
    ss << "PP = " << pp << "/" << maxPP;
    return ss.str();
}

float Move::getPP()
{
    return pp;
}

void Move::setPP(int _pp)
{
    pp += _pp;
    
    // Reiniciar a los limites
    if (pp < 0)
        pp = 0;
    else if (pp > maxPP)
        pp = maxPP;
}

void Move::resetMove(){

     pp =maxPP;
     power =maxPower;
}
