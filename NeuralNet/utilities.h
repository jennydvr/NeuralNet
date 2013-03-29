//
//  utilities.h
//  NeuralNet
//
//  Created by Luis Alejandro Vieira on 29/03/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#ifndef __NeuralNet__utilities__
#define __NeuralNet__utilities__

#include "NeuralNet.h"

// Busqueda binaria de acuerdo al fitness <= key
int specialBinarySearch(std::vector<float> vec, float key);

// Mergesort de acuerdo al fitness
void mergeSort(std::vector<NeuralNet>& v, int start, int end);


// Mergesort de acuerdo al fitness relativo
void mergeSort(std::vector<NeuralNet>& v, int start, int end, float sum);

#endif /* defined(__NeuralNet__utilities__) */
