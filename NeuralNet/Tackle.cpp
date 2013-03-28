//
//  Tackle.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 21/03/13.
//
//

#include "Tackle.h"

Tackle::Tackle() : Move(35, 50)
{
    name = "Tackle";
}

void Tackle::effect(Pet *me, Pet *foe)
{
    // Chequea cuantos pp quedan
    if (pp <= 0)
        return;
    
    // Disminuye los pp
    --pp;
    
    // Inflinge dano
    foe->setHP(-power * me->getAttack() / foe->getDefense());
}
