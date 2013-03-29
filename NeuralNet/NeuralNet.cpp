//
//  NeuralNet.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 20/02/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#include "neuralNet.h"
#include "Saquito.h"
#include <numeric>
#include <math.h>
const int NeuralNet::layerSize[4] = {14, NUMHIDDEN, 4};

NeuralNet::NeuralNet()
{
    for (int i = 0; i != 42; ++i)
        encoding.push_back(-1 + (float)rand()/((float)RAND_MAX/(2)));
    
    fitness =std::numeric_limits<float>::min();
}

NeuralNet::NeuralNet(std::vector<float> _encoding)
{
    encoding = _encoding;
    fitness =std::numeric_limits<float>::min();

}
void NeuralNet::setEncoding(std::vector<float> _encoding){
    encoding = _encoding;
    fitness =std::numeric_limits<float>::min();
}

std::vector<float> NeuralNet::getEncoding(){
    return encoding;
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
    
    fitness =std::numeric_limits<float>::min();

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

float NeuralNet::executeTournamentGames(std::vector<float> _encoding){
    
   // Saquito player1(1);
    Saquito player2(0,_encoding);
    
    //Esto es ineficiente
    std::vector<Saquito> openentes;
    openentes.push_back(Saquito(1));
    openentes.push_back(Saquito(1));
    openentes.push_back(Saquito(1));
    openentes.push_back(Saquito(1));
    openentes.push_back(Saquito(2));
    openentes.push_back(Saquito(2));
    //Agrego varios random para que se enfrenten a varios
    openentes.push_back(Saquito(5));
    openentes.push_back(Saquito(5));
    openentes.push_back(Saquito(5));
    openentes.push_back(Saquito(5));
    openentes.push_back(Saquito(5));
    openentes.push_back(Saquito(5));
    openentes.push_back(Saquito(5));
    openentes.push_back(Saquito(5));
    openentes.push_back(Saquito(5));
    openentes.push_back(Saquito(5));


    int GAMESTOURNAMENT = (int)openentes.size();
    
    //int score1 = 0;
    //int score2 = 0;
    //int tie = 0;
    std::vector<int> timeEachGame(GAMESTOURNAMENT);
    std::vector<int> resultEachGame(GAMESTOURNAMENT);

    bool currentPlayer = true;
    int time = 0;
    for (int i=0; i < GAMESTOURNAMENT; i++) {
        //player1.resetStats();
        openentes[i].resetStats();
        player2.resetStats();
        time = 0;
        while (true) {
          
            if (/*player1*/openentes[i].pass && player2.pass)
                break;
            
            if (currentPlayer)
            {
                if (/*player1*/openentes[i].getHP() <= 0)
                    break;
                
                /*player1*/openentes[i].useMove(&player2);
                
            }
            else
            {
                if (player2.getHP() <= 0)
                    break;
                
                player2.useMove(&/*player1*/openentes[i]);
            }
            time++;
            currentPlayer = !currentPlayer;
        }
        timeEachGame[i] = time;
       // std::cout << "P1 HP: "<< player1.getHP()<<" P2 HP: "<< player2.getHP()<<std::endl;
        if (/*player1*/openentes[i].getHP() > player2.getHP()) {
            resultEachGame[i] = 0;
           // resultEachGame[i] = 300 + player1.getHP()/3;

        } else if (player2.getHP() > /*player1*/openentes[i].getHP()) {
            resultEachGame[i] = 2;
           // resultEachGame[i] = 300 + player2.getHP()/3;
        } else {
            resultEachGame[i] = 1;
        }
    }
    
    float sum = std::accumulate(resultEachGame.begin(),resultEachGame.end(),0);
    sum = pow(sum,2);
    
    //Luego sumar el promedio de las partidas aqui
    //sum += std::accumulate(timeEachGame.begin(),timeEachGame.end(),0)/GAMESTOURNAMENT;
    
    return sum;
}

float NeuralNet::getFitness(){
    
    if (fitness == std::numeric_limits<float>::min()) {
        fitness = NeuralNet::executeTournamentGames(encoding);
    }
    
    return fitness;
}




