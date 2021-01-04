#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    
    int answer = 0;
    for(auto skill_tree : skill_trees){
       vector<int> decision_list ;
       for(auto c : skill){
           decision_list.push_back(skill_tree.find(c));
       }
        
       int prev = -2 ;
       bool never_flag = false; 
       bool isCorrect = true;\
           
       for(auto eac : decision_list){
           //-1이 나오면 다음 부터는 절대 나오면 안됨
	   if(eac == -1) never_flag = true;
	   //현재 값이 -1 인 경우만 통과
	   if(never_flag && eac != -1) isCorrect = false; 
	   //오름차순 판별, 1,2,-1,-1 ;; 이런 상태 고려.
	   if(prev > eac && !never_flag) isCorrect = false; 

           prev = eac ;
       }
        
       if(isCorrect) answer += 2;
    }
    
    return answer; 
}

/* 시간 복잡도 
 * n -> the number of skill_trees
 * m -> length of skill
 * k -> length of each skill_tree
 * Since the time complexity of string.find() is O(size of needle * size of pattern),
 * O(nmk) 
 * 어떻게 줄일 수 있을까 ?
 * 각각의 문자 위치를 find 하는 부분을 줄여야 하는데 ... 
 */
/* 
 * ps) 미리 나올 수 있는 모든 경우 생각해보고 로직 짜는게
 */
