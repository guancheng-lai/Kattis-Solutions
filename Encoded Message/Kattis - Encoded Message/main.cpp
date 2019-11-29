//
//  main.cpp
//  Kattis - Encoded Message
//
//  Created by Guancheng Lai on 3/31/19.
//  Copyright © 2019 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void printMat(const vector< vector<char> > &mat)
{
    cout << endl;
    for (int i = 0; i < mat.size() - 1; ++i)
    {
        for (int j = 0; j < mat.size() - 1; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, const char * argv[])
{
    int numMsg;
    cin >> numMsg;
    cout << numMsg << endl;

    for (int i = 0; i < numMsg; ++i)
    {
        string input;

        getline(cin, input);
        cout << input << endl;

        int lengthOfMatrix = sqrt(input.size());
        vector< vector<char> > msgMatrix(lengthOfMatrix, vector<char>(lengthOfMatrix));

        cout << endl;
        for (int j = 0; j < lengthOfMatrix; ++j)
        {
            for (int k = 0; k < lengthOfMatrix; ++k)
            {
                msgMatrix[j][k] = input.at(j * lengthOfMatrix + k);
                cout << msgMatrix[j][k] << " ";
            }
            cout << endl;
        }

        //printMat(msgMatrix);


    }
}
