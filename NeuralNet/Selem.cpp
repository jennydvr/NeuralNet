//
//  Selem.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 25/03/13.
//
//

#include "Selem.h"

Selem::Selem() : Pet(300, 72, 59,RANDOM)
{
    name = "Selem";
    addMoves();
}

Selem::Selem(TypeIA mode,std::vector<float> encode) : Pet(300, 72, 59, mode,encode)
{
    name = "Selem";
    addMoves();
}

Selem::Selem(TypeIA mode,const char * file): Pet(300, 72, 59, mode,file){
    name = "Selem";
    addMoves();
}

Selem::Selem(std::vector<FormulaValue> values,TypeIA mode,std::vector<float> encode) : Pet(values, mode,encode)
{
    name = "Selem";
    addMoves();
}

Selem::Selem(std::vector<FormulaValue> values,TypeIA mode,const char * file): Pet(values, mode,file){
    name = "Selem";
    addMoves();
}

void Selem::addMoves()
{
    moves.push_back(new Tackle());
    moves.push_back(new Recover());
    moves.push_back(new Leer());
    moves.push_back(new Charm());
}
