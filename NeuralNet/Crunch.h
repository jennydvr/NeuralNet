//
//  Crunch.h
//  Neuralmon_Mac
//
//  Created by Jenny Valdez on 30/03/13.
//  Copyright (c) 2013 Universidad Simon Bolivar. All rights reserved.
//

#ifndef __Neuralmon_Mac__Crunch__
#define __Neuralmon_Mac__Crunch__

#include "Pet.h"

class Crunch : public Move {
    
public:
    
    // Constructor
    Crunch();
    
    // Efecto
    virtual void effect(Pet *me, Pet *foe);
    
};

#endif /* defined(__Neuralmon_Mac__Crunch__) */
