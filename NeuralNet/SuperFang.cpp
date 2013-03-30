//
//  SuperFang.cpp
//  Neuralmon_Mac
//
//  Created by Jenny Valdez on 30/03/13.
//  Copyright (c) 2013 Universidad Simon Bolivar. All rights reserved.
//

#include "SuperFang.h"

SuperFang::SuperFang() : Move(10)
{
    name = "SuperFang";
}

void SuperFang::effect(Pet *me, Pet *foe)
{
    // Chequea cuantos pp quedan
    if (pp <= 0)
        return;
    
    // Disminuye los pp
    --pp;
    
    // 90% de chance de funcionar
    if (rand() % 100 >= 90)
        return;
    
    // Quita la mitad de la vida
    int damage = foe->getHP() / 2;
    if (damage == 0)
        damage = 1;
    
    foe->setHP(-damage);
}
