#pragma once
#ifndef GUARD_RandomNum_h
#define GUARD_RandomNum_h

#include <cstdio>
#include <stdexcept>
#include <ctime>

#include <stdlib.h> 
#include <time.h>
#include <random>
#include <functional>

using std::domain_error;


/********************************************************************************
*功能描述：	本函数用于实现"生成随机数"功能，目的是：生成[lr,rr]区间内的随机整数
*输入参数：	参数int lr, int rr，表示生成区间的左右边界
*返回值：	返回值为int型，表示返回生成的随机整数
*******************************************************************************/
inline int nrand( int lr, int rr )
{
    static std::default_random_engine generator( ( unsigned ) time( nullptr ) );
    static std::uniform_int_distribution<int> dis( lr, rr );
    static auto dice = std::bind( dis, generator );

    return dice();
}


int nrand( int n ){
    if ( n <= 0 || n > RAND_MAX )
        throw domain_error( "Argument to nrand is out of range" );

    static bool flag = false;
    if ( !flag ){
        srand( ( unsigned ) time( NULL ) );
        flag = true;
    }

    const int bucket_size = RAND_MAX / n;
    int r;
    do r = rand() / bucket_size;
    while ( r >= n );

    return r;
}

#endif