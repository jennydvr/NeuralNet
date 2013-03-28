//
//  Spite.h
//  Neuralmon
//
//  Created by Jenny Valdez on 22/03/13.
//
//

#ifndef __Neuralmon__Spite__
#define __Neuralmon__Spite__

#include "Pet.h"

class Spite : public Move {
    
public:
    
    // Constructor
    Spite();
    
    // Efecto
    virtual void effect(Pet *me, Pet *foe);
    
};

#endif /* defined(__Neuralmon__Spite__) */
