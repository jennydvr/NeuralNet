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
enum TypeIA {NEURAL,RANDOM,OFFENSIVE, TACKLE,CRUNCH,SUPERFANG,BLOOD,SUPERDOU,THREE};
class AiEngine {
protected:
    int helper;
    // Red neural del engine
    NeuralNet neuralNet;
    
    // Modo del engine
    TypeIA mode;
    
    int offensiveMove(Pet me, Pet foe);
    
    int tackleMove(Pet me);
    
    //Ratta IA
    int CrunchMove(Pet me);
    int SuperFangMove(Pet me,Pet foe);
    int BloodMove(Pet me,Pet foe);
    int SuperDouble(Pet me,Pet foe);
    int threeMove(Pet me);
    // Escoge un move al azar
    int randomMove(Pet me);
    
    // Escoge el move de acuerdo a la red
    int neuralNetMove(Pet me, Pet foe);
    
public:
    
    // Constructor
    AiEngine(TypeIA _mode);
    // Constructor
    AiEngine(TypeIA _mode, std::vector<float> encode);
    AiEngine(TypeIA _mode, const char * file);
    
    
    // Escoge un movimiento
    int chooseMove(Pet me, Pet foe);
    
    void setNeuralNet(std::vector<float> encode);
    
    float getFitness(){
        return neuralNet.getFitness();
    }
    
    void EncodgingToFile(const char * file);
};

#endif /* defined(__NeuralNet__AiEngine__) */
