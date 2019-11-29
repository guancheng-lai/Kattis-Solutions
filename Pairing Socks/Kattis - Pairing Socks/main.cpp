//
//  main.cpp
//  Kattis - Pairing Socks
//
//  Created by Guancheng Lai on 4/2/19.
//  Copyright © 2019 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::stack;

int main(int argc, const char * argv[])
{
    int numPairs;
    cin >> numPairs;
    
    stack<int> ori;
    stack<int> aux;

    char socks[2 * numPairs + 1];
    for (int i = 0; i < 2 * numPairs; ++i)
    {
        cin >> socks[i];
    }
    
    for (int i = 2 * numPairs - 1; i >= 0; i--)
    {
        ori.push(socks[i] - 48);
    }

    int moves(0);
    while (!ori.empty())
    {
        moves++;
        if (aux.empty())
        {
            aux.push(ori.top());
            ori.pop();
            continue;
        }
        
        if (ori.top() == aux.top())
        {
            ori.pop();
            aux.pop();
            continue;
        }
        
        aux.push(ori.top());
        ori.pop();
        
    }

    if (aux.empty())
    {
        cout << moves << endl;
    }
    else
    {
        cout << "impossible" << endl;
    }
    
    return 0;
}
