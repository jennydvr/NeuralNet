//
//  Selem.h
//  Neuralmon
//
//  Created by Jenny Valdez on 25/03/13.
//
//

#ifndef __Neuralmon__Selem__
#define __Neuralmon__Selem__

#include "Tackle.h"
#include "Recover.h"
#include "Spite.h"
#include "Charm.h"
#include "Leer.h"
class Selem : public Pet {
protected:
    
    // Agrega los movimientos
    virtual void addMoves();
    
public:
    
    // Constructor
    Selem();

    Selem(int mode,std::vector<float> encode);
    Selem(int mode,const char * file);
    
    Selem(std::vector<FormulaValue> values,int mode,std::vector<float> encode);
    Selem(std::vector<FormulaValue> values,int mode,const char * file);
};

#endif /* defined(__Neuralmon__Selem__) */
