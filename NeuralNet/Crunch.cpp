//
//  Crunch.cpp
//  Neuralmon_Mac
//
//  Created by Jenny Valdez on 30/03/13.
//  Copyright (c) 2013 Universidad Simon Bolivar. All rights reserved.
//

#include "Crunch.h"

Crunch::Crunch() : Move(15, 80)
{
    name = "Crunch";
}

void Crunch::effect(Pet *me, Pet *foe)
{
    // Chequea cuantos pp quedan
    if (pp <= 0)
        return;
    
    // Disminuye los pp
    --pp;
    
    // Inflinge dano
    foe->setHP(-power * me->getAttack() / foe->getDefense());
    
    // Con cierta probabilidad, quita defensa
    if (rand() % 100 < 20)
        foe->setDefense(-1);
}
