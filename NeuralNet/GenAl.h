//
//  GenAl.h
//  NeuralNet
//
//  Created by Jenny Valdez on 28/03/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#ifndef __NeuralNet__GenAl__
#define __NeuralNet__GenAl__

#include <iostream>
#include "NeuralNet.h"
#include "utilities.h"
class GenAI {
    
protected:
    std::vector<NeuralNet> population;
    
    int pSize;
    float crossoverRate;
    float mutationRate;
    
public:
    GenAI(int size){
        pSize = size;
        crossoverRate = 0.75;
        mutationRate = 0.75;
    }
    
    GenAI(int size, float CrosR, float MutRa){
        pSize = size;
        crossoverRate = CrosR;
        mutationRate = MutRa;
    }
    std::vector<float> allFitness;

    void Initialize();
    
    void Run(int epochs);
    NeuralNet getBest();

    static std::vector<NeuralNet> tournamentSelection(std::vector<NeuralNet> &population, int size);
    static std::vector<NeuralNet> rankingSelection(std::vector<NeuralNet> population, int size);
    static std::vector<NeuralNet> rouletteSelection(std::vector<NeuralNet> population, int size);
    static std::vector<NeuralNet> elitismSelection(std::vector<NeuralNet> &population, int size);

};


#endif /* defined(__NeuralNet__GenAl__) */
