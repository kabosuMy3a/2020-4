#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

void print_list(vector<list<int>> lists, int n){
    
    for(int i = 1 ; i <= n ; i++){

        for(auto e : lists[i]){
            cout << e << ", " ;
        }
        cout << endl ;
    }
}

vector<int> solution(int n) {
    vector<list<int>> lists ;
    for(int i = 0 ; i <= n ; i++){
        list<int> l ;
        lists.push_back(l);
    }
    //no use 0 ;
    
 
 
    int start_idx = 1;
    int end_idx = n ;
    int nth_triangle = 1;
    int warm_size = n ; 
    int val = 1 ;
        
    while(warm_size != 0){
        //(1)insert warm_size elements from start_idx to end_idx
        for(int i = start_idx ; i <= end_idx ; i++){
             if(start_idx == 1) lists[i].push_front(val++);
             else {
                auto it = lists[i].begin();
                for(int n = 1 ; n < nth_triangle ; n++) it++;
                lists[i].insert(it,val++);
             }
        }
        warm_size -= 1;
        start_idx += 2;
        if(warm_size == 0) break; 
    
        //(2)insert warm_size elements to end_idx 
        auto it = lists[end_idx].begin();
        vector<int> v ;
        int a = val + warm_size ; 
        for(val ; val < a ; val++){
            v.push_back(val);
        }
        for(int n = 0 ; n < nth_triangle ; n++) it++;
        lists[end_idx].insert(it, v.begin(), v.end());

        warm_size -= 1;
        end_idx -= 1 ;
        if(warm_size == 0) break; 
        //(3)insert warm_size elements one by one from end_idx to (end_idx - warm_size)
        for(int i = end_idx ; i > end_idx - warm_size ; i--){
            it = lists[i].begin();
            for(int n = 0 ; n < nth_triangle ; n++) it++;
            lists[i].insert(it,val++);
        }
        warm_size -= 1;
        nth_triangle += 1;
        if(warm_size == 0) break; 

        
    }
    vector<int> answer;
    
    for(int i = 1 ; i <= n ; i++){
        for(auto e : lists[i]){
            answer.push_back(e);            
        }
    }
  

    return answer;

}
