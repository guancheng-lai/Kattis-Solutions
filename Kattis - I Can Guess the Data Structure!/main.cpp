//
//  main.cpp
//  Kattis - I Can Guess the Data Structure!
//
//  Created by Guancheng Lai on 4/30/19.
//  Copyright © 2019 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(int argc, const char * argv[])
{
    int numTests;
    cin >> numTests;
    
    while (cin)
    {
        queue<int> q;
        priority_queue<int> pq;
        stack<int> s;
        
        bool isQueue(true), isPQ(true), isStack(true);
        
        for (int i = 0; i < numTests; ++i)
        {
            int operation, data;
            cin >> operation >> data;
            
            if (operation == 1)
            {
                q.push(data);
                pq.push(data);
                s.push(data);
            }
            else
            {
                if (isQueue)
                {
                    if (!q.empty() && data == q.front())
                    {
                        q.pop();
                    }
                    else
                    {
                        isQueue = false;
                    }
                }
                
                if (isPQ)
                {
                    if (!pq.empty() && data == pq.top())
                    {
                        pq.pop();
                    }
                    else
                    {
                        isPQ = false;
                    }
                }
                
                if (isStack)
                {
                    if (!s.empty() && data == s.top())
                    {
                        s.pop();
                    }
                    else
                    {
                        isStack = false;
                    }
                }
            }
        }
        
        if (!isQueue && !isPQ && !isStack)
        {
            cout << "impossible" << endl;
        }
        else if (isQueue && !isStack && !isPQ)
        {
            cout << "queue" << endl;
        }
        else if (!isQueue && isStack && !isPQ)
        {
            cout << "stack" << endl;
        }
        else if (!isQueue && !isStack && isPQ)
        {
            cout << "priority queue" << endl;
        }
        else
        {
            cout << "not sure" << endl;
        }
        
        cin >> numTests;
    }
    
    int i = 10;
}
