

#ifndef VFNCS_H
#define VFNCS_H

#include <iostream>
#include <vector>
#include <cassert>
#include <pthread.h>
#ifdef _OPENMP
    #include <omp.h>
#endif
#include <semaphore.h>

namespace vf {
using namespace std;

template <typename T> void add( vector<T>& a, vector<T>& b, vector<T>& c );
template <typename T> T myFindMin( vector<T>& a );




}
#endif