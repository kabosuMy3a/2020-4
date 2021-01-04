//내 풀이보다 구글링 코드가 훨씬 나았음
//진법 관련 문제는 어렵게 생각하지 말고 나눗셈으로

//해당 코드는 0으로 나눠떨어질 때 몫을 -1 해주는 것과 종료조건 설정이 깔끔함

//테스트 케이스 11~14 까지 내 풀이와 pow를 사용한 코드가 통과를 못함
//내 풀이도 로직은 맞았지만, 아마 answer 작성 부분에서 오류였을 것으로 생각된다.


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
