//내가 생각한 방법으로 풀기 어려웠고 실패했다.
//2시간 정도 고민했지만 구현이 완벽하지 않아 구글링 했다.
//가장 마음에 드는 방법은 큐를 이용해 다리를 만드는 것이었다.
//트럭의 위치를 큐 안에서 표현하는 것이다.
//0000070000 이면 무게 7의 트럭이 6번째 구간을 지나고 있는 것이다.

//아이디어는 좋았지만 구현이 깔끔한 편은 아니어서 내 방식으로 조금 다듬었다.
//내 코드는 queue의 사이즈를 다리의 길이로 항상 동일하게 유지한다.
//먼저 pop을 하고 시간을 증가시킨 다음 새 트럭을 넣는다.  

//내가 이 코드를 찾기 전까지 이 아이디어를 생각할 수 있을 것 같지 않아서 마음이 어려웠다 
//유사한 문제가 나왔을 때 자료구조를 이용해 내가 문제를 모델링 할 수 있을까?

//시간 복잡도는 음.. 모든 트럭이 겹치지 않을 때가 최악이므로
//O(bridge_length * truck_weights.size())이다.
//한 개의 트럭 당 다리의 길이만큼 루프를 돌기 때문이다 

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int now_time = 0 ;
    int now_weight = 0 ;
    queue<int> bridge ;
    
    for(int i = 0 ; i < bridge_length ; i++){
        bridge.push(0);
    }
  
    int idx = 0;
    while(1){
        int front = bridge.front() ;
        if(front != 0){
            now_weight -= front ;
        } 
        
        bridge.pop();
        now_time++;
        
        if(weight < now_weight + truck_weights[idx]){
            bridge.push(0);
            
        } else {
            bridge.push(truck_weights[idx]) ;
            now_weight += truck_weights[idx] ;
            idx++;
            
            if(idx == truck_weights.size()){
                now_time += bridge_length ;
                break;
            }
        }
    }
    
    return now_time ;
}
