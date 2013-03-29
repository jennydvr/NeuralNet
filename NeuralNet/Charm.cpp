//
//  Charm.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 24/03/13.
//
//

#include "Charm.h"

Charm::Charm() : Move(10)
{
    name = "Charm";
}

void Charm::effect(Pet *me, Pet *foe)
{
    // Chequea cuantos pp quedan
    if (pp <= 0)
        return;
    
    // Disminuye los pp
    --pp;
    
    // Quita PPs
    foe->setAttack(-2);
}
