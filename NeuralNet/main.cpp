//
//  main.cpp
//  NeuralNet
//
//  Created by Jenny Valdez on 20/02/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#include "neuralNet.h"

using namespace std;

int main(int argc, const char * argv[])
{
    NeuralNet mom;
    cout << mom.toString() << endl << endl;
    
    vector<float> in;
    for (int i = 0; i != 14; ++i)
        in.push_back(i);
    
    vector<float> ff = mom.feedForward(in);
    
    for (int i = 0; i != 4; ++i) {
        cout << ff[i] << endl;
    }
    
    return 0;
}

