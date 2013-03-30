//
//  DoubleEdge.cpp
//  Neuralmon_Mac
//
//  Created by Jenny Valdez on 30/03/13.
//  Copyright (c) 2013 Universidad Simon Bolivar. All rights reserved.
//

#include "DoubleEdge.h"

DoubleEdge::DoubleEdge() : Move(15, 120)
{
    name = "DoubleEdge";
}

void DoubleEdge::effect(Pet *me, Pet *foe)
{
    // Chequea cuantos pp quedan
    if (pp <= 0)
        return;
    
    // Disminuye los pp
    --pp;
    
    // Hace dano al oponente
    int damage = -power * me->getAttack() / foe->getDefense();
    foe->setHP(damage);
    
    // Me hace dano a mi
    me->setHP(damage * 0.3f);
}
