//
//  main.cpp
//  Kattis - Goat Rope
//
//  Created by Guancheng Lai on 5/1/19.
//  Copyright © 2019 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[])
{
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    
    if (x < x1 && y < y1)
    {
        cout << std::fixed << sqrt((x - x1)*(x - x1) + (y - y1) * (y - y1)) << endl;
    }
    else if (x < x1 && (y1 <= y && y <= y2))
    {
        cout << std::fixed << double (x1 - x) << endl;
    }
    else if (x < x1 && y2 < y)
    {
        cout << std::fixed << sqrt((x - x1) * (x - x1) + (y - y2) * (y - y2)) << endl;
    }
    else if ((x1 <= x && x <= x2) && y < y1)
    {
        cout << std::fixed << double (y1 - y) << endl;
    }
    else if ((x1 <= x && x <= x2) && y2 < y)
    {
        cout << std::fixed << double (y - y2) << endl;
    }
    else if (x2 < x && y < y1)
    {
        cout << std::fixed << sqrt((x - x2) * (x - x2) + (y - y1) * (y - y1)) << endl;
    }
    else if (x2 < x && (y1 <= y && y <= y2))
    {
        cout << std::fixed << double (x - x2) << endl;
    }
    else if (x2 < x && y2 < y)
    {
        cout << std::fixed << sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2)) << endl;
    }
}
