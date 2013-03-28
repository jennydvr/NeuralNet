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

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
    
    Saquito player1(0), player2(0);
    bool currentPlayer = true;
    
    while (true) {
        cout << player1.toString() << endl;
        cout << player2.toString() << endl << endl;
        
        if (currentPlayer)
        {
            if (player1.getHP() <= 0) {
                cout << "Gana PLAYER 2\n";
                break;
            }
            
            player1.useMove(&player2);
            
        }
        else
        {
            if (player2.getHP() <= 0) {
                cout << "Gana PLAYER 1\n";
                break;
            }
            
            player2.useMove(&player1);
        }
        
        currentPlayer = !currentPlayer;
    }
    
    return 0;
}
