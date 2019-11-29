//
//  main.cpp
//  Kattis - Primary Arithmetic
//
//  Created by Guancheng Lai on 4/6/19.
//  Copyright © 2019 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{
    int a, b;
    cin >> a >> b;
    while (cin)
    {
        if (a == 0 && b == 0) break;
        
        int carry(0);
        vector<int> va(11, 0);
        vector<int> vb(11, 0);
        int div(10);

        int pos(0);
        while (a / div != 0)
        {
            va[pos] = a % 10;
            a /= 10;
            ++pos;
        }
        va[pos] = a % 10;
        
        pos = 0;
        while (b / div != 0)
        {
            vb[pos] = b % 10;
            b /= 10;
            ++pos;
        }
        vb[pos] = b % 10;
        
        for (int i = 0; i < 11; ++i)
        {
            if (va[i] + vb[i] > 9)
            {
                ++carry;
                ++(va[i+1]);
            }
        }
        
        if (carry == 0)
        {
            cout << "No carry operation." << endl;
        }
        else if (carry == 1)
        {
            cout << carry << " carry operation." << endl;
        }
        else
        {
            cout << carry << " carry operations." << endl;
        }
        
        
        cin >> a >> b;
    }
}
