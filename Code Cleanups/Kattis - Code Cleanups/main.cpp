//
//  main.cpp
//  Kattis - Code Cleanups
//
//  Created by Guancheng Lai on 4/7/19.
//  Copyright © 2019 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

int main(int argc, const char * argv[])
{
    int numOfDirty;
    cin >> numOfDirty;
    
    int numCleanUp(0);
    
    vector<int> dirtyDays(numOfDirty);
    for (int i = 0; i < numOfDirty; ++i)
    {
        cin >> dirtyDays[i];
    }
    
    vector<int> everyday(366, 0);
    for (auto &i : dirtyDays)
    {
        everyday[i] = 1;
    }
    
    vector<int> dirtyCode;
    for (int i = 1; i <= 365; ++i)
    {
        if (everyday[i] == 1)
        {
            dirtyCode.push_back(i);
        }
        
        int sum = (i + 1) * dirtyCode.size() - accumulate(dirtyCode.begin(), dirtyCode.end(), 0);
        if (sum > 19)
        {
            ++numCleanUp;
            dirtyCode.clear();
        }
    }
    
    if (!dirtyCode.empty())
    {
        ++numCleanUp;
    }
    
    cout << numCleanUp << endl;
}
