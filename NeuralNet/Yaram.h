//
//  Yaram.h
//  Neuralmon
//
//  Created by Jenny Valdez on 25/03/13.
//
//

#ifndef __Neuralmon__Yaram__
#define __Neuralmon__Yaram__

#include "Tackle.h"
#include "Recover.h"
#include "Spite.h"
#include "Charm.h"
#include "Leer.h"
class Yaram : public Pet {
protected:
    
    // Agrega los movimientos
    virtual void addMoves();
    
public:
    
    // Constructor
    Yaram();
    Yaram(std::vector<FormulaValue> values);
    
};

#endif /* defined(__Neuralmon__Yaram__) */
