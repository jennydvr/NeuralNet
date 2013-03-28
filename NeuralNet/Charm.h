//
//  Charm.h
//  Neuralmon
//
//  Created by Jenny Valdez on 24/03/13.
//
//

#ifndef __Neuralmon__Charm__
#define __Neuralmon__Charm__

#include "Pet.h"

class Charm : public Move {
    
public:
    
    // Constructor
    Charm();
    
    // Efecto
    virtual void effect(Pet *me, Pet *foe);
    
};


#endif /* defined(__Neuralmon__Charm__) */
