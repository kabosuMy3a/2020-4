//사각형의 대각선을 일차함수로 표현해서 풀 수 있었다.

#include <iostream>

using namespace std ;

long long solution(int w,int h) {
    long long answer = 0 ;
    
    double slope = (double)w / h ;
    
    for(long long y = 1 ; y < w ; y++){
       double x = y/slope ;
       double n = h - x ;
       answer += (long long) n ;        
    }
    
    return answer * 2;
    
}