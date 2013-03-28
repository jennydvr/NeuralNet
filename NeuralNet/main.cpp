//
//  main.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 20/02/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#include "NeuralNet.h"

#include "Saquito.h"

using namespace std;

int score1 = 0;
int score2 = 0;

void game()
{
    Saquito player1(1), player2(5);
    bool currentPlayer = true;
    
    while (true) {
        //cout << "NEXT : " << (currentPlayer ? "P1\n" : "P2\n");
        //cout << player1.toString() << endl << endl;
        //cout << player2.toString() << endl << endl;
        
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
    
    if (player1.getHP() > player2.getHP()) {
        //cout << "Gana PLAYER 1\n";
        score1 += 1;
    } else if (player2.getHP() > player1.getHP()) {
        //cout << "Gana PLAYER 2\n";
        score2 += 1;
    } else {
        //cout << "Empate\n";
    }
}

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i != 100; ++i) {
        game();
    }
    
    cout << score1 << " - " << score2 << endl;
    
    return 0;
}
