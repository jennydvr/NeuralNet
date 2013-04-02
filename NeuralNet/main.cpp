//
//  main.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 20/02/13.
//  Copyright (c) 2013 Jenny Valdez & Luis Vieira. All rights reserved.
//

#include "NeuralNet.h"
#include "draftsman.h"
#include "Saquito.h"
#include "GenAl.h"
#include "Rattata.h"
using namespace std;


#define NUMGAMES 100
#define NUMTEST 10
#define NUMPOBLACION 50
#define NUMITER 1000
struct DataGame{
  
    int whoWin;
    int numTurns;
    DataGame(){
        whoWin = 0;
        numTurns = 0;
    }
    DataGame(int win,int turn){
        whoWin = win;
        numTurns = turn;
    }
};

struct PercentGame{
    TypeIA name;
    float win;
    float lost;
    float tie;
    
    PercentGame(){
        win = 0;
        lost = 0;
        tie = 0;
        name = RANDOM;
        
    }
    PercentGame(float w, float l, float t,TypeIA tipe){
        win = w;
        lost = l;
        tie = t;
        name = tipe;
    }
    
};

DataGame game( Pet * player1, Pet * player2){
    player1->resetStats();
    player2->resetStats();
    bool currentPlayer = true;

    int turn = 0;
    while (true) {
        if (player1->pass && player2->pass)
            break;
        
        if (currentPlayer)
        {
            if (player1->getHP() <= 0)
                break;
            
            player1->useMove(player2);
            
        }
        else
        {
            if (player2->getHP() <= 0)
                break;
            
            player2->useMove(player1);
        }
        ++turn;
        currentPlayer = !currentPlayer;
    }
    
    DataGame data;
    
    if (player1->getHP() > player2->getHP()) {
        data = DataGame(2,turn);
    } else if (player2->getHP() > player1->getHP()) {
        data = DataGame(1,turn);
    } else {
        data = DataGame(0,turn);
    }
    
    return data;
}

std::vector< std::vector< DataGame > > tournament(std::vector<Pet *> player){
  
    std::vector< std::vector< DataGame > > datas;
    
    bool first;
    for (int i = 0;i<(int)player.size() ; i++) {
        std::vector< DataGame > newData;
        for (int j = 0;j<(int)player.size() ; j++) {
            first = true;
            for (int k=0; k<NUMGAMES; k++) {
                newData.push_back(game(player[j], player[i]));

            }
        }
        datas.push_back(newData);
    }
    
    return datas;
}

std::vector<PercentGame> dataPrueba1(){
    
    std::vector<FormulaValue>stats;

    stats.push_back(FormulaValue(HP, 170, 30, 31, LVLOPPONENT, 1,0));
    stats.push_back(FormulaValue(ATTACK, 170, 56, 31, LVLOPPONENT, 1,0));
    stats.push_back(FormulaValue(DEFENSE, 170, 35, 31, LVLOPPONENT, 1, 0));
    
    std::vector<Pet *> player;
    
    
    player.push_back(new Rattata(stats, CRUNCH));
    player.push_back(new Rattata(stats, BLOOD));
    player.push_back(new Rattata(stats, SUPERFANG));
    player.push_back(new Rattata(stats, SUPERDOU));
    player.push_back(new Rattata(stats, THREE));
    player.push_back(new Rattata(stats, RANDOM));
    
    std::vector< std::vector< DataGame > > datos = tournament(player);
    float totalGames = NUMGAMES * player.size();
    
    std::vector<PercentGame> perGames;
    
    std::cout << "___ Torneo Prueba: 1 ____ "<<std::endl;
    std::cout << "___ Games C/U: "<< totalGames<< " ____ "<<std::endl;
    std::cout << " "<<std::endl;

    for (int i = 0; i <(int)datos.size(); i++) {
        PercentGame percent;
        switch (i) {
            case 0:
                std::cout << "Crunch: ";
                percent.name = CRUNCH;
                break;
            case 1:
                std::cout << "Blood: ";
                percent.name = BLOOD;
                break;
            case 2:
                std::cout << "SUPERFANG: ";
                percent.name = SUPERFANG;
                break;
            case 3:
                std::cout << "SUPERDOU: ";
                percent.name = SUPERDOU;

                break;
            case 4:
                std::cout << "THREE: ";
                percent.name = THREE;
                break;
            case 5:
                std::cout << "RANDOM: ";
                percent.name = RANDOM;
                break;
        }
        float win = 0;
        float lose = 0;
        float tie = 0;
        for (int j = 0; j <(int)datos[i].size(); j++) {
            switch (datos[i][j].whoWin ) {
                case 1:
                    win++;
                    break;
                case 2:
                    lose++;
                    break;
                    
                default:
                    tie++;
                    break;
            }
            
        }
        float percWin = win * 100 / totalGames;
        float percLose = lose * 100 / totalGames;
        float percTie = tie * 100 / totalGames;
        percent.win = percWin;
        percent.lost = percLose;
        percent.tie  = percTie;
        perGames.push_back(percent);
        std::cout << " Wins: " << percWin << " Lost: " << percLose <<" Tie: " << percTie << std::endl;
        std::cout << " "<<std::endl;
    }
    
    return perGames;
    
}
std::vector<PercentGame> dataPrueba3(){
    
    std::vector<FormulaValue>stats1;
    stats1.push_back(FormulaValue(HP, 170, 30, 31, LVLPLAYER, 1,0));
    stats1.push_back(FormulaValue(ATTACK, 170, 56, 31, LVLPLAYER, 1,0));
    stats1.push_back(FormulaValue(DEFENSE, 170, 35, 31, LVLPLAYER, 1, 0));
    
    std::vector<FormulaValue>stats;
    stats.push_back(FormulaValue(HP, 170, 30, 31, LVLOPPONENT, 1,0));
    stats.push_back(FormulaValue(ATTACK, 170, 56, 31, LVLOPPONENT, 1,0));
    stats.push_back(FormulaValue(DEFENSE, 170, 35, 31, LVLOPPONENT, 1, 0));
    
    std::vector<Pet *> player;
    player.push_back(new Rattata(stats1,NEURAL,"BestNeuralPokemon.txt"));
    player.push_back(new Rattata(stats, CRUNCH));
    player.push_back(new Rattata(stats, BLOOD));
    player.push_back(new Rattata(stats, SUPERFANG));
    player.push_back(new Rattata(stats, SUPERDOU));
    player.push_back(new Rattata(stats, THREE));
    player.push_back(new Rattata(stats, RANDOM));
    
    std::vector< std::vector< DataGame > > datos = tournament(player);
    float totalGames = NUMGAMES * player.size();
    
    std::vector<PercentGame> perGames;
    
    std::cout << "___ Torneo Prueba: 2 ____ "<<std::endl;
    std::cout << "___ Games C/U: "<< totalGames<< " ____ "<<std::endl;
    std::cout << " "<<std::endl;
    
    for (int i = 0; i <(int)datos.size(); i++) {
        PercentGame percent;
        switch (i) {
            case 0:
                std::cout << "Neural: ";
                percent.name = NEURAL;
                break;
            case 1:
                std::cout << "Crunch: ";
                percent.name = CRUNCH;
                break;
            case 2:
                std::cout << "Blood: ";
                percent.name = BLOOD;
                break;
            case 3:
                std::cout << "SUPERFANG: ";
                percent.name = SUPERFANG;
                break;
            case 4:
                std::cout << "SUPERDOU: ";
                percent.name = SUPERDOU;
                
                break;
            case 5:
                std::cout << "THREE: ";
                percent.name = THREE;
                break;
            case 6:
                std::cout << "RANDOM: ";
                percent.name = RANDOM;
                break;
        }
        float win = 0;
        float lose = 0;
        float tie = 0;
        for (int j = 0; j <(int)datos[i].size(); j++) {
            switch (datos[i][j].whoWin ) {
                case 1:
                    win++;
                    break;
                case 2:
                    lose++;
                    break;
                    
                default:
                    tie++;
                    break;
            }
            
        }
        float percWin = win * 100 / totalGames;
        float percLose = lose * 100 / totalGames;
        float percTie = tie * 100 / totalGames;
        percent.win = percWin;
        percent.lost = percLose;
        percent.tie  = percTie;
        perGames.push_back(percent);
        std::cout << " Wins: " << percWin << " Lost: " << percLose <<" Tie: " << percTie << std::endl;
        std::cout << " "<<std::endl;
    }
    
    return perGames;
    
}
std::vector<PercentGame> dataPrueba2(){
    
    std::vector<FormulaValue>stats1;
    stats1.push_back(FormulaValue(HP, 170, 30, 31, LVLPLAYER, 1,0));
    stats1.push_back(FormulaValue(ATTACK, 170, 56, 31, LVLPLAYER, 1,0));
    stats1.push_back(FormulaValue(DEFENSE, 170, 35, 31, LVLPLAYER, 1, 0));
    
    std::vector<FormulaValue>stats;
    stats.push_back(FormulaValue(HP, 170, 30, 31, LVLOPPONENT, 1,0));
    stats.push_back(FormulaValue(ATTACK, 170, 56, 31, LVLOPPONENT, 1,0));
    stats.push_back(FormulaValue(DEFENSE, 170, 35, 31, LVLOPPONENT, 1, 0));
    
    std::vector<Pet *> player;
    player.push_back(new Rattata(stats1,NEURAL));
    player.push_back(new Rattata(stats, CRUNCH));
    player.push_back(new Rattata(stats, BLOOD));
    player.push_back(new Rattata(stats, SUPERFANG));
    player.push_back(new Rattata(stats, SUPERDOU));
    player.push_back(new Rattata(stats, THREE));
    player.push_back(new Rattata(stats, RANDOM));
    
    std::vector< std::vector< DataGame > > datos = tournament(player);
    float totalGames = NUMGAMES * player.size();
    
    std::vector<PercentGame> perGames;
    
    std::cout << "___ Torneo Prueba: 2 ____ "<<std::endl;
    std::cout << "___ Games C/U: "<< totalGames<< " ____ "<<std::endl;
    std::cout << " "<<std::endl;
    
    for (int i = 0; i <(int)datos.size(); i++) {
        PercentGame percent;
        switch (i) {
            case 0:
                std::cout << "Neural: ";
                percent.name = NEURAL;
                break;
            case 1:
                std::cout << "Crunch: ";
                percent.name = CRUNCH;
                break;
            case 2:
                std::cout << "Blood: ";
                percent.name = BLOOD;
                break;
            case 3:
                std::cout << "SUPERFANG: ";
                percent.name = SUPERFANG;
                break;
            case 4:
                std::cout << "SUPERDOU: ";
                percent.name = SUPERDOU;
                
                break;
            case 5:
                std::cout << "THREE: ";
                percent.name = THREE;
                break;
            case 6:
                std::cout << "RANDOM: ";
                percent.name = RANDOM;
                break;
        }
        float win = 0;
        float lose = 0;
        float tie = 0;
        for (int j = 0; j <(int)datos[i].size(); j++) {
            switch (datos[i][j].whoWin ) {
                case 1:
                    win++;
                    break;
                case 2:
                    lose++;
                    break;
                    
                default:
                    tie++;
                    break;
            }
            
        }
        float percWin = win * 100 / totalGames;
        float percLose = lose * 100 / totalGames;
        float percTie = tie * 100 / totalGames;
        percent.win = percWin;
        percent.lost = percLose;
        percent.tie  = percTie;
        perGames.push_back(percent);
        std::cout << " Wins: " << percWin << " Lost: " << percLose <<" Tie: " << percTie << std::endl;
        std::cout << " "<<std::endl;
    }
    
    return perGames;
    
}
std::vector<PercentGame> dataPrueba4(){
    
    std::vector<FormulaValue>stats1;
    stats1.push_back(FormulaValue(HP, 170, 30, 31, LVLPLAYER, 1,0));
    stats1.push_back(FormulaValue(ATTACK, 170, 56, 31, LVLPLAYER, 1,0));
    stats1.push_back(FormulaValue(DEFENSE, 170, 35, 31, LVLPLAYER, 1, 0));
    
    
    std::vector<Pet *> player;
    player.push_back(new Rattata(stats1,NEURAL,"TR1_BestNeuralPokemon.txt"));
    player.push_back(new Rattata(stats1,NEURAL,"TR3_BestNeuralPokemon.txt"));


    
    std::vector< std::vector< DataGame > > datos = tournament(player);
    float totalGames = NUMGAMES * player.size();
    
    std::vector<PercentGame> perGames;
    
    std::cout << "___ Torneo Prueba: 2 ____ "<<std::endl;
    std::cout << "___ Games C/U: "<< totalGames<< " ____ "<<std::endl;
    std::cout << " "<<std::endl;
    
    for (int i = 0; i <(int)datos.size(); i++) {
        PercentGame percent;
        switch (i) {
            case 0:
                std::cout << "Neural TR1: ";
                percent.name = NEURAL;
                break;
            case 1:
                std::cout << "Neural TR3: ";
                percent.name = NEURAL;
                break;
        }
        float win = 0;
        float lose = 0;
        float tie = 0;
        for (int j = 0; j <(int)datos[i].size(); j++) {
            switch (datos[i][j].whoWin ) {
                case 1:
                    win++;
                    break;
                case 2:
                    lose++;
                    break;
                    
                default:
                    tie++;
                    break;
            }
            
        }
        float percWin = win * 100 / totalGames;
        float percLose = lose * 100 / totalGames;
        float percTie = tie * 100 / totalGames;
        percent.win = percWin;
        percent.lost = percLose;
        percent.tie  = percTie;
        perGames.push_back(percent);
        std::cout << " Wins: " << percWin << " Lost: " << percLose <<" Tie: " << percTie << std::endl;
        std::cout << " "<<std::endl;
    }
    
    return perGames;
    
}

void promedioPrueba(int numPrueba){
    
    std::vector <std::vector<PercentGame>> totalGames;
    switch (numPrueba) {
        case 1:
            for (int i =0; i<NUMTEST; i++) {
                totalGames.push_back(dataPrueba1());
            }
            std::cout << "___ Torneo Total Prueba: 1 ____ "<<std::endl;
            std::cout << "___ Num Pruebas: "<< NUMTEST<< " ____ "<<std::endl;
            std::cout << "___ Num Juegos Contra cada enemigo: "<< NUMGAMES<< " ____ "<<std::endl;
            break;
        case 2:
            for (int i =0; i<NUMTEST; i++) {
                totalGames.push_back(dataPrueba2());
            }
            std::cout << "___ Torneo Total Prueba: 2 ____ "<<std::endl;
            std::cout << "___ Num Pruebas: "<< NUMTEST<< " ____ "<<std::endl;
            std::cout << "___ Num Juegos Contra cada enemigo: "<< NUMGAMES<< " ____ "<<std::endl;
            break;
        case 3:
            for (int i =0; i<NUMTEST; i++) {
                totalGames.push_back(dataPrueba3());
            }
            std::cout << "___ Torneo Total Prueba: 3 ____ "<<std::endl;
            std::cout << "___ Num Pruebas: "<< NUMTEST<< " ____ "<<std::endl;
            std::cout << "___ Num Juegos Contra cada enemigo: "<< NUMGAMES<< " ____ "<<std::endl;
            break;
        case 4:
            for (int i =0; i<NUMTEST; i++) {
                totalGames.push_back(dataPrueba4());
            }
            std::cout << "___ Torneo Total Prueba: 4 ____ "<<std::endl;
            std::cout << "___ Num Pruebas: "<< NUMTEST<< " ____ "<<std::endl;
            std::cout << "___ Num Juegos Contra cada enemigo: "<< NUMGAMES<< " ____ "<<std::endl;
            std::cout << "___ Primer Neural: TR1 \n    Segundo Neural: TR3 ____ "<<std::endl;

            break;
        default:
            break;
    }

    std::cout << " "<<std::endl;
    for (int j = 0; j < (int)totalGames[0].size(); j++) {
        float win = totalGames[0][j].win;
        float lost = totalGames[0][j].lost;
        float tie = totalGames[0][j].tie;
        switch (totalGames[0][j].name) {
            case NEURAL:
                std::cout << "Neural: ";
                break;
            case CRUNCH:
                std::cout << "Crunch: ";
                break;
            case SUPERFANG:
                std::cout << "SUPERFANG: ";
                break;
            case BLOOD:
                std::cout << "Blood: ";
                break;
            case SUPERDOU:
                std::cout << "SUPERDOU: ";
                break;
            case THREE:
                std::cout << "THREE: ";
                break;
            case RANDOM:
                std::cout << "RANDOM: ";
                break;
            default:
                break;
        }
        for (int i = 1; i < (int)totalGames.size(); i++) {
            win+=totalGames[i][j].win;
            lost+=totalGames[i][j].lost;
            tie+=totalGames[i][j].tie;
        }
        
        float promeWin = win/NUMTEST;
        float promelost = lost/NUMTEST;
        float prometie = tie/NUMTEST;
        std::cout << " Wins: " << promeWin << " Lost: " << promelost <<" Tie: " << prometie << std::endl;
        std::cout << " "<<std::endl;
    }
    
}
void fillPlotDataCircle(std::vector<float> genetic){
    for (int i = 0; i != (int)genetic.size(); ++i) {
        mp.x.push_back(i);
        mp.y.push_back(genetic[i]);
    }
}

NeuralNet promedioGenetic(){
    
    std::vector<std::vector<float>> fitness;
    NeuralNet best;
    float bestfit = std::numeric_limits<float>::min();
    for (int i = 0; i<NUMTEST; i++) {
        GenAI genetic = GenAI(NUMPOBLACION);
        genetic.Initialize();
        genetic.Run(NUMITER);
        NeuralNet aux = genetic.getBest();
        if( aux.getFitness() >bestfit )
            best = aux;
        
        fitness.push_back(genetic.allFitness);
        
    }
    
    std::vector<float> averageFitnes;
    
    for (int i =0; i<(int)fitness[0].size(); i++) {
        float sum = fitness[0][i];
        for (int j =1; j<(int)fitness.size(); j++) {
            sum+=fitness[j][0];
        }
        averageFitnes.push_back(sum/NUMTEST);
    }
    fillPlotDataCircle(averageFitnes);
    return best;
}

int main(int argc,  char * argv[])
{
    srand((unsigned int)time(0));
    promedioPrueba(3);
    
   /*
    NeuralNet bestAll = promedioGenetic();
    bestAll.toFile("BestNeuralPokemon.txt");
    Plotear(argc, argv);*/
     
    return 0;
}
