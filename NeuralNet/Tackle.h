//
//  Tackle.h
//  Neuralmon
//
//  Created by Jenny Valdez on 21/03/13.
//
//

#ifndef __Neuralmon__Tackle__
#define __Neuralmon__Tackle__

#include "Pet.h"

class Tackle : public Move {
    
public:
    
    // Constructor
    Tackle();
    
    // Efecto
    virtual void effect(Pet *me, Pet *foe);
    
};

#endif /* defined(__Neuralmon__Tackle__) */
