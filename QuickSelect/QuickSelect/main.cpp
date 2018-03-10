//
//  main.cpp
//  QuickSelect
//
//  Created by Andrew Hinson on 3/8/18.
//  Copyright © 2018 Andrew Hinson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <math.h>

using namespace std;



template <typename Iterator>
Iterator selectTest(Iterator begin, Iterator end, int n) {
    typedef typename iterator_traits<Iterator>::value_type T;
    while (true) {
        Iterator pivotIt = begin + rand() % distance(begin, end);
        iter_swap(pivotIt, end-1);  // Move pivot to end
        pivotIt = partition(begin, end-1, bind2nd(less<T>(), *(end-1)));
        iter_swap(end-1, pivotIt);  // Move pivot to its final place
        if (n == pivotIt - begin) {
            return pivotIt;
        } else if (n < pivotIt - begin) {
            end = pivotIt;
        } else {
            n -= pivotIt+1 - begin;
            begin = pivotIt+1;
        }
    }
}

int main() {
    vector<int> intVec;
    
    vector<int>::iterator vectorIterator;
    //Insert elements
    intVec.push_back(10);
    intVec.push_back(34);
    intVec.push_back(65);
    intVec.push_back(3);
    intVec.push_back(55);
    intVec.push_back(80);
    intVec.push_back(90);
    intVec.push_back(7);
    intVec.push_back(79);
    intVec.push_back(23);

    
    
    
    for (int i = 0; i < 10; i++) {
        
        selectTest(intVec.begin(), intVec.end(), i);
        
    }
    
   
    //print vector
    for(auto x = intVec.begin(); x != intVec.end(); ++x){
        cout << *x << endl;
    }
    
    return 0;
}
