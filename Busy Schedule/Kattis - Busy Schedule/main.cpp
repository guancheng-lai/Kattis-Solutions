//
//  main.cpp
//  Kattis - Busy Schedule
//
//  Created by Guancheng Lai on 4/11/19.
//  Copyright © 2019 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef bool (*comp)(string, string);
bool cmp(string left, string right)
{
    std::string::iterator leftColonPosition = find(left.begin(), left.end(), ':');
    long leftDividePostion = distance(left.begin(), leftColonPosition);
    int leftHour = stoi(left.substr(0, leftDividePostion)); if (leftHour == 12) { leftHour = 0; }
    int leftMinute = stoi(left.substr(leftDividePostion + 1));
    
    std::string::iterator rightColonPosition = find(right.begin(), right.end(), ':');
    long rightDividePostion = distance(right.begin(), rightColonPosition);
    int rightHour = stoi(right.substr(0, rightDividePostion)); if (rightHour == 12) { rightHour = 0; }
    int rightMinute = stoi(right.substr(rightDividePostion + 1));
    
    int leftTime = leftHour * 60 + leftMinute;
    int rightTime = rightHour * 60 + rightMinute;
    
    return leftTime > rightTime;
}

int main(int argc, const char * argv[])
{
    int numOfSchedule;
    cin >> numOfSchedule;
    
    while (cin && numOfSchedule != 0)
    {
        priority_queue<string, vector<string>, comp> amTime(cmp);
        priority_queue<string, vector<string>, comp> pmTime(cmp);
        
        for (int i = 0; i < numOfSchedule; ++i)
        {
            string time;
            string ampm;
            
            cin >> time >> ampm;
            if (ampm == "a.m.")
            {
                amTime.push(time);
            }
            else
            {
                pmTime.push(time);
            }
        }
        
        while (!amTime.empty())
        {
            cout << amTime.top() + " a.m."<< endl;
            amTime.pop();
        }
        
        while (!pmTime.empty())
        {
            cout << pmTime.top() + " p.m."<< endl;
            pmTime.pop();
        }
        
        cout << endl;
        cin >> numOfSchedule;
    }
}
