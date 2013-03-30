//
//  Rattata.h
//  Neuralmon_Mac
//
//  Created by Jenny Valdez on 30/03/13.
//  Copyright (c) 2013 Universidad Simon Bolivar. All rights reserved.
//

#ifndef __Neuralmon_Mac__Rattata__
#define __Neuralmon_Mac__Rattata__

#include "SuperFang.h"
#include "Crunch.h"
#include "Endeavor.h"
#include "DoubleEdge.h"

class Rattata : public Pet {
protected:
    
    // Agrega los movimientos
    virtual void addMoves();
    
public:
    
    // Constructor
    Rattata(int mode = 10);
    

    Rattata(int mode,std::vector<float> encode);
    Rattata(int mode,const char * file);
    
    Rattata(std::vector<FormulaValue> values,int mode);
    Rattata(std::vector<FormulaValue> values,int mode,std::vector<float> encode);
    Rattata(std::vector<FormulaValue> values,int mode,const char * file);
};

#endif /* defined(__Neuralmon_Mac__Rattata__) */
