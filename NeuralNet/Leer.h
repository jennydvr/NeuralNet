//
//  Leer.h
//  NeuralNet
//
//  Created by Luis Alejandro Vieira on 28/03/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#ifndef __NeuralNet__Leer__
#define __NeuralNet__Leer__


#include "Pet.h"

class Leer : public Move {
    
public:
    
    // Constructor
    Leer();
    
    // Efecto
    virtual void effect(Pet *me, Pet *foe);
    
};
#endif /* defined(__NeuralNet__Leer__) */
