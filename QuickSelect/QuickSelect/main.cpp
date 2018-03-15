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
Iterator quickSelectSort(Iterator begin, Iterator end, int k) {
    typedef typename iterator_traits<Iterator>::value_type T;
    while (true) {
        Iterator pivot = begin + rand() % distance(begin, end); //chooses random pivot value
        iter_swap(pivot, end-1);  // Move pivot to end
        pivot = partition(begin, end-1, bind2nd(less<T>(), *(end-1))); //uses the partition func from the STL
        iter_swap(end-1, pivot);  // Move pivot to its final place
        if (k == pivot - begin) {
            return pivot;
        } else if (k < pivot - begin) {
            end = pivot;
        } else {
            k -= pivot+1 - begin;
            begin = pivot+1;
        }
    }
}

int main() {
    vector<int> intVec;
    
    /* initialize random seed: */
    srand (time(NULL));
    
    //Insert elements into vector
    for(int k = 0; k < 10; k++){
        intVec.push_back(rand() % 100);
    }

    
    
    
    for (int i = 0; i < 10; i++) {
        
        quickSelectSort(intVec.begin(), intVec.end(), i);
        
    }
    
   
    //print vector
    for(auto x = intVec.begin(); x != intVec.end(); ++x){
        cout << *x << endl;
    }
    
    return 0;
}
