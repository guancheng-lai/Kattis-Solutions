//
//  uf.h
//
//  Created by Guancheng Lai on 10/11/18.
//  Copyright © 2018 Guancheng Lai. All rights reserved.
//

#ifndef uf_h
#define uf_h

#include <vector>


//bool operator== (const Node &left, const Node &right)
//{
//    bool result;
//
//    if (left.color == right.color && left.row == right.row && left.col == right.col)
//    {
//        result = true;
//    }
//    else
//    {
//        result = false;
//    }
//
//    return result;
//}
//
//bool operator!= (const Node &left, const Node &right)
//{
//    return (left == right);
//}

struct Satellite
{
    int x;
    int y;
    int r;
    
    double getDistanceSquare(Satellite s1, Satellite s2)
    {
        return pow((s1.x - s2.x), 2) + pow((s1.y - s2.y), 2);
    }
    
    double getDistance(Satellite s1, Satellite s2)
    {
        return sqrt(getDistanceSquare(s1, s2));
    }
    
    double getGap(Satellite s1, Satellite s2)
    {
        return getDistance(s1, s2) - (s1.r + s2.r);
    }
};

class UnionFind
{
    std::vector <Satellite> setName;
    std::vector <int> setSize;
    
public:
    UnionFind(int n) {              // Constructor used to create initial n sets
        setSize.resize(n, 1);        // Initialize each set's size to
        setName.resize(n);          // Initialize the "name" of each singleton set
        
        for (int i=0; i<n; i++)
        {
            setName[i] = i;
        }
    }
    
    ~UnionFind() {                // Destructor should release the memory allocated
        setName.clear();
        setSize.clear();
    }
    
    int find (Satellite p) {        // Find the name of the set that contains element p
        while (p != setName[p]) {
            setName[p] = setName[setName[p]];    // Compression step
            p = setName[p];
        }
        return p;
    }
    
    void unite ( int x, int y) {    // Unite the sets that contain x & y
        // Note: The name 'unite' is used to avoid confusion with the union keyword
        int i = find(x);
        int j = find(y);
        if (i != j) {        // If x & y are in the same set, nothing to do
            
            // Smaller set is added to the larger of the 2 sets
            if (setSize[i] < setSize[j]) {
                setName[i] = j;
                setSize[j] += setSize[i];
            } else {
                setName[j] = i;
                setSize[i] += setSize[j];
            }
        }
    }
    
    int size( Satellite x ) {                // return size of set associated with x
        return setSize[find(x)];
    }
    
    void clear() {                    // Method used to explicitly release allocated memory
        setName.clear();
        setSize.clear();
    }
    
    
};


#endif /* uf_h */
