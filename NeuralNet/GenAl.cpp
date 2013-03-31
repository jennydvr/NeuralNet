//
//  GenAl.cpp
//  NeuralNet
//
//  Created by Jenny Valdez on 28/03/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#include "GenAl.h"

void GenAI::Initialize(){
    
    
    for (int i = 0; i != pSize; ++i)
        population.push_back(NeuralNet());
    
}

std::vector<NeuralNet> GenAI::tournamentSelection(std::vector<NeuralNet> &population, int size){
    std::vector<NeuralNet> newPopulation;
    
    std::vector<int> indexes;
    for (int i = 0; i != population.size(); ++i)
        indexes.push_back(i);
    
    while (newPopulation.size() != size)
    {
        // Selecciono dos individuos aleatorios
        int a = rand() % indexes.size();
        int b = rand() % (indexes.size() - 1);
        
        if (b == a)
            ++b;
        
        // Seleccionar al mejor entre a y b
        if (population[indexes[a]].getFitness() < population[indexes[b]].getFitness())
            a = b;
        
        newPopulation.push_back(population[indexes[a]]);
        
        // Elimino al individuo que acabo de utilizar
        std::swap(indexes[a], indexes.back());
        indexes.pop_back();
    }
    
    return newPopulation;
}

std::vector<NeuralNet> GenAI::rankingSelection(std::vector<NeuralNet> population, int size){
    std::vector<NeuralNet> newPopulation;
    
    // Calcular el fitness total
    int sum = 0;
    for (int i = 0; i != (int)population.size(); ++i)
        sum += population[i].getFitness();
    
    // Ordenar la poblacion por fitness relativo
    mergeSort(population, 0, (int)population.size() - 1,std::abs( sum));
    
    for (int i = (int)population.size() - 1; i != (int)population.size() - 1 - size; --i)
        newPopulation.push_back(population[i]);
    
    return newPopulation;
}

NeuralNet GenAI::getBest()
{
    int bestIndex = 0;
    float bestFit = std::numeric_limits<float>::min();
    
    for (int i = 0; i != population.size(); ++i){
        if (population[i].getFitness() >= bestFit) {
            bestIndex = i;
            bestFit = population[i].getFitness();
        }
    }
    
    return population[bestIndex];
}

void GenAI::Run(int epochs){
    
    Initialize();
    
    for (int e = 0; e != epochs; ++e)
    {
        // Seleccion de padres
        int np = crossoverRate * pSize;
        if (np % 2 != 0)
            np += 1;
        
        std::vector<NeuralNet> parents = GenAI::tournamentSelection(population, np);
        
        // Crossover
        std::vector<NeuralNet> offspring;
        for (int i = 0; i != parents.size(); i += 2)
        {
           // std::vector<NeuralNet> osp = NeuralNet::crossover(parents[i], parents[i+1]);
            //offspring.push_back(osp[0]);
            //offspring.push_back(osp[1]);
             NeuralNet osp = NeuralNet::crossover(parents[i], parents[i+1]);
            offspring.push_back(osp);
        }
        
        // Mutacion
        int maxMutation = mutationRate * offspring.size();
        for (int i = 0; i != maxMutation; ++i)
            offspring[i].mutate();
        
        // Seleccion de sobrevivientes
        for (int i = 0; i != offspring.size(); ++i)
            population.push_back(offspring[i]);
        
        population = GenAI::rankingSelection(population, pSize);
        
        allFitness.push_back(getBest().getFitness());
        std::cout <<"Epoch: "<<e <<" MejorFit: " << getBest().getFitness()<< std::endl;
 
    }
    
}
