//
//  Leer.cpp
//  NeuralNet
//
//  Created by Luis Alejandro Vieira on 28/03/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#include "Leer.h"

Leer::Leer() : Move(3)
{
    name = "Leer";
}

void Leer::effect(Pet *me, Pet *foe)
{
    // Chequea cuantos pp quedan
    if (pp <= 0)
        return;
    
    // Disminuye los pp
    --pp;
    
    // Quita PPs
    foe->setDefense(-12);
}
