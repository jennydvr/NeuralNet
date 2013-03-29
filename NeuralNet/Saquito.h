//
//  Saquito.h
//  Neuralmon
//
//  Created by Jenny Valdez on 21/03/13.
//
//

#ifndef __Neuralmon__Saquito__
#define __Neuralmon__Saquito__

#include "Tackle.h"
#include "Recover.h"
#include "Spite.h"
#include "Charm.h"
#include "Leer.h"
class Saquito : public Pet {
protected:
    
    // Agrega los movimientos
    virtual void addMoves();
    
public:
    
    // Constructor
    Saquito(int mode = 10);
    
    // Constructor
    Saquito(int mode,std::vector<float> encode);
    Saquito(int mode,const char * file);

    
};

#endif /* defined(__Neuralmon__Saquito__) */
