//
//  Stronghold.hpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//
#pragma once
#include <string>
#include "Stocks/Warehouse.hpp"
#include "Stocks/Armory.hpp"
#include "Stocks/Granary.hpp"
#include <thread>
#include "Humans/Miner.h"
#define WORKERSCOUNT 20

using namespace std;
//class  Miner;
class Stronghold{
    
public:
    
    Stronghold();
    ~Stronghold();
    
    atomic_bool workingLumberjacks[WORKERSCOUNT];
    atomic_bool workingFarmers[WORKERSCOUNT];
    atomic_bool workingMiller[WORKERSCOUNT];
    atomic_bool workingBakers[WORKERSCOUNT];
    atomic_bool workingBlacksmiths[WORKERSCOUNT];
    atomic_bool workingBowMakers[WORKERSCOUNT];
    atomic_bool workingMiners[WORKERSCOUNT];
    
    thread lumberjacks[WORKERSCOUNT];
    thread farmers[WORKERSCOUNT];
    thread miller[WORKERSCOUNT];
    thread bakers[WORKERSCOUNT];
    thread blacksmiths[WORKERSCOUNT];
    thread bowMakers[WORKERSCOUNT];
    thread miners[WORKERSCOUNT];
    
    condition_variable armoryReady;
    
    Warehouse warehouse;
    Armory armory;
    Granary granary;
    
    void initWorld();
    void initGranary();
    void initWarehouse();
    void initArmory();
    void initPopulation();
//
//    void startLife();
//    void startMiner(int id);
};
