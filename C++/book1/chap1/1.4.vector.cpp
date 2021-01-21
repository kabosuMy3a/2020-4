#include <iostream>
#include <vector>
#include <algorithm>

//std::vector<int> vec;
//std::vector<int> vec = {1,2,3,4,5};
//std::vector<int> vec(10);
//std::vector<int> vec(10,5);

//push_back() 마지막 위치
//insert() 원하는 위치


void print(const std::vector<int> & vec){	
	for(auto ele : vec){
		std::cout << ele << " " ;
	}
	std::cout << std::endl ;
}

int main(){

	std::vector<int> vec = {1,2,3,4,5} ;
	vec.insert(vec.begin(), 0);
	vec.push_back(1);
	vec.push_back(2);
	vec.insert(std::find(vec.begin(), vec.end(), 3), 11);
	
	vec.emplace_back(12);
	vec.emplace(vec.begin()+2,111);

	vec.pop_back();
	vec.erase(vec.begin()+1);

	print(vec);

	/*
	vec.clear();
	vec.reserve(capacity); 
	*/
	vec.shrink_to_fit();
	
	return 0;
}
