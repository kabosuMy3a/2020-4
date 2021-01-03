#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string solution(int n) {
    
    int k = 0;
    int rst = 0;
    
    string answer = "";
    
    while(n != 0) {
        if(n%3 == 0){
           answer.insert(0, "4");
           //rst += pow(10,k) * 4;
           n = n/3 - 1;
        } else {
           answer.insert(0, to_string(n%3));
           //rst += pow(10,k) * (n%3) ;
           n = n/3 ;
        }
        
       // k++; 
    }
    
    //return to_string(rst);
    return answer ;
}