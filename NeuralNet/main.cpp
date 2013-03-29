//
//  main.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 20/02/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#include "NeuralNet.h"

#include "Saquito.h"
#include "GenAl.h"
using namespace std;

int score1 = 0;
int score2 = 0;

void game()
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
        score1 += 1;
    } else if (player2.getHP() > player1.getHP()) {
        score2 += 1;
    } else {
        //cout << "Empate\n";
    }
}

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(0));
    
    /*
    for (int i = 0; i != 100; ++i) {
        game();
    }*/
   
    GenAI genetic = GenAI(100);
    
    genetic.Initialize();
    
    genetic.Run(1000);
    
    NeuralNet test = genetic.getBest();
    std::cout <<"Fitness: " << test.getFitness()<< endl;
    //std::cout <<"tostring: " << test.getEncoding()<< endl;

    return 0;
}
