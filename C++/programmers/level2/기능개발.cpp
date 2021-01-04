#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> due_dates;
    vector<int> answer;
    
    //두 배열을 합쳐서 남은 개발 기간에 대한 배열로
    for(auto i = 0 ; i < progresses.size() ; i++ ){
        int p = progresses.at(i) ;
        int s = speeds.at(i) ;
        
        int res = (100-p) % s ;
        int due_date = (100 - p)/s ;
        if(res != 0) due_date += 1;
        
        due_dates.push_back(due_date);
    }
    
    int clear_index = 0;
    const int job_size = due_dates.size();
    //모든 job을 해결하면 끝
    while(clear_index != job_size){
        int update_day = due_dates.at(clear_index);
        int clear_job_nums = 0;
        
        for(clear_index ; clear_index != job_size ; clear_index++){
            if(update_day >= due_dates.at(clear_index)){
                clear_job_nums++;
            } else {
                break; 
            }
        }
        
        if(clear_job_nums != 0) answer.push_back(clear_job_nums);
    }
    
    return answer;
}