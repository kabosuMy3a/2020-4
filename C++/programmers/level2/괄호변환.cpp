#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string start(string w){
    if(w.size()==0) return "";
    
    stack<string> st ; 
    int idx = 0;
    int det = 0 ;
    while(1){
        string paren = w.substr(idx,1);
        if(paren == "("){
            det++;
            st.push(paren);
        } else {
            det--;
            //error 처리 꼭 !!!!!!!!!!!!!!!!!!!!!!!!!
            if(!st.empty() && st.top()=="(") 
                st.pop();
            else
                st.push(paren);
        }
        idx++;
        if(det == 0) break; 
    }
    
    bool isU0 = st.empty();
    string u = w.substr(0, idx);    
    string v = w.substr(idx);
    
    if(isU0){
        return u + start(v);
    } else {
        
        string answer = "(";
        answer += start(v);
        answer += ")";
        string new_u = "";
        if(u.size() > 2) new_u = u.substr(1, u.size()-2);
        for(int i = 0 ; i < new_u.size() ; i++){
            string c = new_u.substr(i,1);
            if(c == "("){
                answer += ")";
            } else answer += "(";
        }
        
        return answer ;
    }
  
}

string solution(string p) {
    return start(p) ;
}