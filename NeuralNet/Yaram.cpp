//
//  Yaram.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 25/03/13.
//
//

#include "Yaram.h"

Yaram::Yaram() : Pet(300, 72, 59,RANDOM)
{
    name = "Yaram";

    addMoves();
}

Yaram::Yaram(std::vector<FormulaValue> values) : Pet(values,RANDOM)
{
    name = "Yaram";
    
    addMoves();
}

void Yaram::addMoves()
{
    moves.push_back(new Tackle());
    moves.push_back(new Recover());
    moves.push_back(new Leer());
    moves.push_back(new Charm());
}
