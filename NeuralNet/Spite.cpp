//
//  Spite.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 22/03/13.
//
//

#include "Spite.h"

Spite::Spite() : Move(10)
{
    name = "Spite";
}

void Spite::effect(Pet *me, Pet *foe)
{
    // Chequea cuantos pp quedan
    if (pp <= 0)
        return;
    
    // Disminuye los pp
    --pp;
    
    // Quita PPs
    foe->setLastMovePP(-4);
}
