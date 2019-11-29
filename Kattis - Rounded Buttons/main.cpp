//
//  main.cpp
//  Kattis - Rounded Buttons
//
//  Created by Guancheng Lai on 4/23/19.
//  Copyright © 2019 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

double distanceToCircleCenter(double testX, double testY, double circleX, double circleY)
{
    return pow(circleX - testX, 2) + pow(circleY - testY, 2);
}

bool isInside(double x, double y, double w, double h, double r, double testX, double testY)
{
    if (x + r <= testX && testX <= x + w - r)
    {
        // Middle
        if (y <= testY && testY <= y + h)
        {
            // Y range
            return true;
        }
        
        return false;
    }
    
    if (x <= testX && testX <= x + r)
    {
        // left
        if (y + r <= testY && testY <= y + h - r)
        {
            // y left middle
            return true;
        }
        
        if (y <= testY && testY <= y + r)
        {
            // y left top
            double circleX = x + r;
            double circleY = y + r;
            if (distanceToCircleCenter(testX, testY, circleX, circleY) <= pow(r, 2))
            {
                return true;
            }
        }
        
        if (y + h - r <= testY && testY <= y + h)
        {
            // y left bottom
            double circleX = x + r;
            double circleY = y + h - r;
            if (distanceToCircleCenter(testX, testY, circleX, circleY) <= pow(r, 2))
            {
                return true;
            }
        }
        
        return false;
    }
    
    
    if (x + w - r <= testX && testX <= x + w )
    {
        // x right
        if (y + r <= testY && testY <= y + h - r)
        {
            // y right middle
            return true;
        }
        
        if (y <= testY && testY <= y + r)
        {
            // y right top
            double circleX = x + w - r;
            double circleY = y + r;
            if (distanceToCircleCenter(testX, testY, circleX, circleY) <= pow(r, 2))
            {
                return true;
            }
        }
        
        if (y + h - r <= testY && testY <= y + h)
        {
            // y right bottom
            double circleX = x + w - r;
            double circleY = y + h - r;
            if (distanceToCircleCenter(testX, testY, circleX, circleY) <= pow(r, 2))
            {
                return true;
            }
        }
        
        return false;
    }
    
    return false;
}

int main(int argc, const char * argv[])
{
    int numOfCases;
    cin >> numOfCases;
    
    for (int i = 0; i < numOfCases; ++i)
    {
        double x, y, w, h, r;
        cin >> x >> y >> w >> h >> r;
        
        int numOfTests;
        cin >> numOfTests;

        for (int j = 0; j < numOfTests; ++j)
        {
            double testX, testY;
            cin >> testX >> testY;
            
            if (isInside(x, y, w, h, r, testX, testY))
            {
                cout << "inside" << endl;
            }
            else
            {
                cout << "outside" << endl;
            }
        }
        
        string junk;
        getline(cin, junk);

//        char junk;
//        cin >> junk;
        
        cout << endl;
    }
}
