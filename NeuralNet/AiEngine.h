//
//  AiEngine.h
//  NeuralNet
//
//  Created by Jenny Valdez on 28/03/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#ifndef __NeuralNet__AiEngine__
#define __NeuralNet__AiEngine__

#include <algorithm>

#include "NeuralNet.h"

class Pet;

class AiEngine {
protected:
    
    // Red neural del engine
    NeuralNet neuralNet;
    
    // Modo del engine
    int mode;
    
    int offensiveMove(Pet me, Pet foe);
    
    int tackleMove(Pet me);
    // Escoge un move al azar
    int randomMove(Pet me);
    
    // Escoge el move de acuerdo a la red
    int neuralNetMove(Pet me, Pet foe);
    
public:
    
    // Constructor
    AiEngine(int _mode);
    // Constructor
    AiEngine(int _mode, std::vector<float> encode);
    
    // Escoge un movimiento
    int chooseMove(Pet me, Pet foe);

    void setNeuralNet(std::vector<float> encode);

    float getFitness(){
        return neuralNet.getFitness();
    }
};

#endif /* defined(__NeuralNet__AiEngine__) */
