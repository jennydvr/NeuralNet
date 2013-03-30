//
//  Endeavor.cpp
//  Neuralmon_Mac
//
//  Created by Jenny Valdez on 30/03/13.
//  Copyright (c) 2013 Universidad Simon Bolivar. All rights reserved.
//

#include "Endeavor.h"

Endeavor::Endeavor() : Move(5)
{
    name = "Endeavor";
}

void Endeavor::effect(Pet *me, Pet *foe)
{
    // Chequea cuantos pp quedan
    if (pp <= 0)
        return;
    
    // Disminuye los pp
    --pp;
    
    // Iguala la vida
    int difference = foe->getHP() - me->getHP();
    
    if (difference > 0)
        foe->setHP(-difference);
}
