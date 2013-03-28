//
//  Saquito.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 21/03/13.
//
//

#include "Saquito.h"

Saquito::Saquito(int mode) : Pet(106, 90, 130, mode)
{
    name = "Saquito";
    addMoves();
}

void Saquito::addMoves()
{
    moves.push_back(new Tackle());
    moves.push_back(new Recover());
    moves.push_back(new Spite());
    moves.push_back(new Charm());
}
