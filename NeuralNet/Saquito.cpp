//
//  Saquito.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 21/03/13.
//
//

#include "Saquito.h"

Saquito::Saquito(TypeIA mode) : Pet(300, 72, 59, mode)
{
    name = "Saquito";
    addMoves();
}
Saquito::Saquito(TypeIA mode,std::vector<float> encode) : Pet(300, 72, 59, mode,encode)
{
    name = "Saquito";
    addMoves();
}

Saquito::Saquito(TypeIA mode,const char * file): Pet(300, 72, 59, mode,file){
    name = "Saquito";
    addMoves();
}


Saquito::Saquito(std::vector<FormulaValue> values,TypeIA mode) : Pet(values,mode){
    name = "Saquito";
    addMoves();
}

Saquito::Saquito(std::vector<FormulaValue> values,TypeIA mode,std::vector<float> encode) : Pet(values, mode,encode)
{
    name = "Saquito";
    addMoves();
}

Saquito::Saquito(std::vector<FormulaValue> values,TypeIA mode,const char * file): Pet(values, mode,file){
    name = "Saquito";
    addMoves();
}
void Saquito::addMoves()
{
    moves.push_back(new Tackle());
    moves.push_back(new Recover());
    moves.push_back(new Leer());
    moves.push_back(new Charm());
}
