//
//  main.cpp
//  Kattis - Daylight Saving Time
//
//  Created by Guancheng Lai on 4/7/19.
//  Copyright © 2019 Guancheng Lai. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int numTest;
    cin >> numTest;
    
    for (int i = 0; i < numTest; ++i)
    {
        char fb;
        int bias, curHour, curMin;
        
        cin >> fb >> bias >> curHour >> curMin;
        
        if (fb == 'F')
        {
            curMin += bias;
            while (curMin > 59)
            {
                curMin -= 60;
                ++curHour;
                
                if (curHour > 23)
                {
                    curHour = 0;
                }
            }
        }
        else
        {
            curMin -= bias;
            while (curMin < 0)
            {
                curMin += 60;
                curHour--;
                
                if (curHour < 0)
                {
                    curHour = 23;
                }
            }
        }
        
        cout << curHour << " " << curMin << endl;
    }
}
