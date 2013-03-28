//
//  AiEngine.cpp
//  NeuralNet
//
//  Created by Jenny Valdez on 28/03/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#include "Pet.h"

AiEngine::AiEngine(int _mode)
{
    mode = _mode;
}

int AiEngine::chooseMove(Pet me, Pet foe)
{
    int move = -1;
    
    switch (mode) {
        case 0:
            move = neuralNetMove(me, foe);
            break;
        case 1:
            move = offensiveMove(me,foe);
            break;
        case 2:
            move = tackleMove(me);
            break;
        default:
            move = randomMove(me);
            break;
    }
    
    return move;
}

int AiEngine::neuralNetMove(Pet me, Pet foe)
{
    // Creo el vector input
    std::vector<float> input;
    
    // Mis stats
    input.push_back(me.getHP());
    input.push_back(me.getAttack());
    input.push_back(me.getDefense());
    
    for (int i = 0; i != 4; ++i)
        input.push_back(me.moves[i]->getPP());
    
    // Los stats del otro
    input.push_back(foe.getHP());
    input.push_back(foe.getAttack());
    input.push_back(foe.getDefense());
    
    for (int i = 0; i != 4; ++i)
        input.push_back(foe.moves[i]->getPP());
    
    // Feedforward
    std::vector<float> output = neuralNet.feedForward(input);
    
    // Escojo la mejor decision segun la red
    float prob = -1;
    int best = -1;
    
    for (int i = 0; i != 4; ++i)
        if (me.moves[i]->getPP() > 0 && output[i] > prob) {
            prob = output[i];
            best = i;
        }
    
    return best;
}

int AiEngine::randomMove(Pet me)
{
    // Revuelvo los movimientos
    std::vector<int> sm;
    for (int i = 0; i != (int)me.moves.size(); ++i)
        sm.push_back(i);
    
    std::random_shuffle(sm.begin(), sm.end());
    
    // Escojo el primero que tenga pps
    for (int i = 0; i != (int)sm.size(); ++i)
        if (me.moves[sm[i]]->getPP() > 0)
            return sm[i];
    
    // Si llegaste aqui, no tenias pp en ningun movimiento
    return -1;
}

int AiEngine::offensiveMove(Pet me, Pet foe){
    
    if( 0.6 * me.getMaxHP() <= me.getHP() && me.moves[3]->getPP() > 0 &&  me.getLastMove() != 3){
        return 3;
    }
    
    if(/*(rand() % 2) == 1 &&*/  0.4 * foe.getMaxHP() < foe.getHP() && me.getLastMove() != 1)
        if (0.35 * me.getMaxHP() >= me.getHP() && me.moves[1]->getPP() > 0 )
            return 1;
    
    if(me.moves[0]->getPP() > 0)
        return 0;
    
    if (me.moves[2]->getPP() > 0)
        return 2;
    
    if (me.moves[3]->getPP() > 0)
        return 3;
    
    if (me.moves[1]->getPP() > 0)
        return 1;
    
    return -1;
}

int AiEngine::tackleMove(Pet me){
    if(me.moves[0]->getPP() > 0)
        return 0;
    if(me.moves[1]->getPP() > 0)
        return 1;
    return -1;
}