//
//  Recover.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 21/03/13.
//
//

#include "Recover.h"

Recover::Recover() : Move(10)
{
    name = "Recover";
}

void Recover::effect(Pet *me, Pet *foe)
{
    // Chequea cuantos pp quedan
    if (pp <= 0)
        return;
    
    // Disminuye los pp
    --pp;
    
    // Cura desde el 10% hasta el 50% de la vida
    //float low = me->getMaxHP() * 0.5;
    float high = me->getMaxHP() * 0.5;
    
    //me->setHP(low + (float)rand()/((float)RAND_MAX/(high - low)));
    me->setHP(high);
}
