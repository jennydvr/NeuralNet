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
    Saquito(TypeIA mode = RANDOM);
    

    Saquito(TypeIA mode,std::vector<float> encode);
    Saquito(TypeIA mode,const char * file);

    Saquito(std::vector<FormulaValue> values,TypeIA mode);
    Saquito(std::vector<FormulaValue> values,TypeIA mode,std::vector<float> encode);
    Saquito(std::vector<FormulaValue> values,TypeIA mode,const char * file);
    
};

#endif /* defined(__Neuralmon__Saquito__) */
