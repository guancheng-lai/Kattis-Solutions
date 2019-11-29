//
//  main.cpp
//  Kattis Communications Satellite
//
//  Created by Guancheng Lai on 3/30/19.
//  Copyright © 2019 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <set>
#include "uf.h"
using namespace std;



struct Edges
{
    int length;
    Satellite a;
    Satellite b;
    
    
};

bool comparaByLengtt(const Edges &a, const Edges &b)
{
    return a.length > b.length;
}

int main(int argc, const char * argv[])
{
    set<Edges> setOfEdges;
    
    
    int numOfSatellite;
    cin >> numOfSatellite;
    
    double length(0.0);
    for (int i = 0; i < numOfSatellite; ++i)
    {
        int x, y, r;
        cin >> x >> y >> r;
        
        
    }
    
    return 0;
}
