//
//  NeuralNet.h
//  Neuralmon
//
//  Created by Jenny Valdez on 20/02/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#ifndef __Neuralmon__NeuralNet__
#define __Neuralmon__NeuralNet__

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <math.h>

#define NUMHIDDEN 2

class NeuralNet {
protected:
    
    // Muta un nodo completo
    void mutateNode(int node);
    
    // Tamaño de cada capa
    const static int layerSize[4];
    
    // Torneo para calcular el fitness
    void game();
    
public:
    
    // Encoding de esta red
    std::vector<float> encoding;
    
    // Constructor aleatorio
    NeuralNet();
    
    // Constructor a partir de encoding
    NeuralNet(std::vector<float> _encoding);
    
    // Feed Forward
    std::vector<float> feedForward(std::vector<float> input);
    
    // Mutacion
    void mutate();
    
    // Crossover
    static NeuralNet crossover(NeuralNet mom, NeuralNet dad);
    
    // Fitness
    float getFitness();
    
};

#endif /* defined(__Neuralmon__NeuralNet__) */
