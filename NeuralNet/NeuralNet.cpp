//
//  NeuralNet.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 20/02/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#include "neuralNet.h"
#include "Saquito.h"

const int NeuralNet::layerSize[4] = {14, NUMHIDDEN, 4};

NeuralNet::NeuralNet()
{
    for (int i = 0; i != 42; ++i)
        encoding.push_back(-1 + (float)rand()/((float)RAND_MAX/(2)));
}

NeuralNet::NeuralNet(std::vector<float> _encoding)
{
    encoding = _encoding;
}

std::vector<float> NeuralNet::feedForward(std::vector<float> input)
{
    std::vector<float> output, lastOutputs;
    float sum;
    int index;
    
    // Outputs de la capa 0 -> inputs recibidos
    output = input;
    
    // Se asigna output(activacion) a cada neurona
    for (int i = 1; i != 3; ++i) {
        lastOutputs = output;
        
        for (int j = 0; j != layerSize[i]; ++j) {
            index = (i - 1) * layerSize[i - 1] * (layerSize[i - 2] + 1) + j * (layerSize[i - 1] + 1);
            sum = 0;
            
            // Aplica el peso a cada input y agrega a la suma
            for (int k = 0; k != layerSize[i - 1]; ++k)
                sum += lastOutputs[k] * encoding[index + k];
            
            // Bias
            sum += encoding[index + layerSize[i - 1]];
            
            // Sigmoidal
            output[j] = 1.0 / (1.0 + exp(-sum));
        }
    }
    
    return output;
}

void NeuralNet::mutate()
{
    // Mutacion de nodos
    int r1 = rand() % (layerSize[1] + layerSize[2]);
    int r2 = rand() % (layerSize[1] + layerSize[2] - 1);
    
    if (r1 == r2)
        ++r2;
    
    mutateNode(r1);
    mutateNode(r2);
}

void NeuralNet::mutateNode(int node)
{
    // Encuentra la neurona y capa
    int i = node < layerSize[1] ? 1 : 2;
    int j = i == 1 ? node : node - layerSize[1];
    int index = (i - 1) * layerSize[i - 1] * (layerSize[i - 2] + 1) + j * (layerSize[i - 1] + 1);
    
    // Mutar el peso sumando un valor
    for (int k = 0; k != layerSize[i - 1] + 1; ++k)
        encoding[index + k] += -1 + (float)rand()/((float)RAND_MAX/(2));
}

NeuralNet NeuralNet::crossover(NeuralNet mom, NeuralNet dad)
{
    std::vector<float> kid;
    
    for (int i = 0; i != 42; ++i) {
        if (rand() % 100 < 50)
            kid.push_back(mom.encoding[i]);
        else
            kid.push_back(dad.encoding[i]);
    }
    
    return NeuralNet(kid);
}

int s1 = 0;
int s2 = 0;

void NeuralNet::game()
{
    Saquito player1(1), player2(5);
    bool currentPlayer = true;
    
    clock_t tstart = clock();
    
    while (true) {
        if (player1.pass && player2.pass)
            break;
        
        if (currentPlayer)
        {
            if (player1.getHP() <= 0)
                break;
            
            player1.useMove(&player2);
            
        }
        else
        {
            if (player2.getHP() <= 0)
                break;
            
            player2.useMove(&player1);
        }
        
        currentPlayer = !currentPlayer;
    }
    
    clock_t tend = clock();
    float elapsed_secs = float(tend - tstart) / CLOCKS_PER_SEC;
    
    if (player1.getHP() > player2.getHP()) {
        s1 += 1;
    } else if (player2.getHP() > player1.getHP()) {
        s2 += 1;
    } else {
        //cout << "Empate\n";
    }
}

