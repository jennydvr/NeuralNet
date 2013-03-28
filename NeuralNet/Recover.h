//
//  Recover.h
//  Neuralmon
//
//  Created by Jenny Valdez on 21/03/13.
//
//

#ifndef __Neuralmon__Recover__
#define __Neuralmon__Recover__

#include "Pet.h"

class Recover : public Move {
public:
    
    // Constructor
    Recover();
    
    // Efecto
    virtual void effect(Pet *me, Pet *foe);
};

#endif /* defined(__Neuralmon__Recover__) */
