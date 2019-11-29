//
//  main.cpp
//  Kattis - NPuzzle
//
//  Created by Guancheng Lai on 4/5/19.
//  Copyright © 2019 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

//void printMatrix(const vector< vector<int> > &m)
//{
//    cout << endl;
//    for (int i = 0; i < 4; ++i)
//    {
//        for (int j = 0; j < 4; ++j)
//        {
//            cout << m[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

int getDistance(int origin, int curI, int curJ)
{
    int originI = origin / 4;
    int originJ = origin % 4;
    
    return abs(originI - curI) + abs(originJ - curJ);
    
}

int main(int argc, const char * argv[])
{
    vector< vector<int> > matrix(4, vector<int>(4));
    char c;
    int distance(0);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> c;
            matrix[i][j] = int(c) - 65;
        }
    }

    //printMatrix(matrix);
    
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (matrix[i][j] != -19)
            {
                distance += getDistance(matrix[i][j], i, j);
            }
        }
    }
    
  
    cout << distance << endl;
}
