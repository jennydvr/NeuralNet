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
#include <numeric>
#include <fstream>
#define NUMHIDDEN 2

class NeuralNet {
protected:
    
    // Muta un nodo completo
    void mutateNode(int node);
    
    // Tamaño de cada capa
    const static int layerSize[4];
    
    // Numero de pesos en total en la red
    const static int numWeights;
    
    float fitness;
    // Encoding de esta red
    std::vector<float> encoding;
    
public:
    
    void setEncoding(std::vector<float> _encoding);
    std::vector<float> getEncoding();

    // Constructor aleatorio
    NeuralNet();
    
    // Constructor a partir de encoding
    NeuralNet(std::vector<float> _encoding);
    
    NeuralNet(const char * name);

    
    // Feed Forward
    std::vector<float> feedForward(std::vector<float> input);
    
    // Mutacion
    void mutate();
    
    // Ejecuta un torneo con una red dada
    static float executeTournamentGames(std::vector<float> _encoding);
    
    // Crossover
    static NeuralNet crossover(NeuralNet mom, NeuralNet dad);
    
    // Fitness
    float getFitness();
    
    void toFile(const char * name);
};

#endif /* defined(__Neuralmon__NeuralNet__) */
