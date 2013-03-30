//
//  Rattata.cpp
//  Neuralmon_Mac
//
//  Created by Jenny Valdez on 30/03/13.
//  Copyright (c) 2013 Universidad Simon Bolivar. All rights reserved.
//

#include "Rattata.h"

Rattata::Rattata(TypeIA mode) : Pet(61, 43, 29, mode)
{
    name = "Rattata";
    
    addMoves();
}

Rattata::Rattata(TypeIA mode,std::vector<float> encode) : Pet(61, 43, 29, mode,encode)
{
    name = "Rattata";
    addMoves();
}

Rattata::Rattata(TypeIA mode,const char * file): Pet(61, 43, 29, mode,file){
    name = "Rattata";
    addMoves();
}

Rattata::Rattata(std::vector<FormulaValue> values,TypeIA mode) : Pet(values,mode){
    name = "Rattata";
    addMoves();
}

Rattata::Rattata(std::vector<FormulaValue> values,TypeIA mode,std::vector<float> encode) : Pet(values, mode,encode)
{
    name = "Rattata";
    addMoves();
}

Rattata::Rattata(std::vector<FormulaValue> values,TypeIA mode,const char * file): Pet(values, mode,file){
    name = "Rattata";
    addMoves();
}
void Rattata::addMoves()
{
    moves.push_back(new Crunch());
    moves.push_back(new SuperFang());
    moves.push_back(new DoubleEdge());
    moves.push_back(new Endeavor());
}
