#include <iostream>
#include <forward_list>

void print(std::forward_list<int> & fwd_list){
	for(auto ele : fwd_list){
		std::cout << ele << " " ;
	}
	std::cout << std::endl;

}

int main(){
	//forward_list는 첫 원소로 직접 접근 가능하고, Size 미지원, back 미지원

	std::forward_list<int> fwd_list = {1,2,3};
	fwd_list.push_front(0);
	
	auto it = fwd_list.begin();
	fwd_list.insert_after(it, 5);
	//how to insert_after certain index ?
	fwd_list.insert_after(it, 44);

	print(fwd_list);
	fwd_list.reverse();
	print(fwd_list);

	fwd_list.pop_front();
	print(fwd_list);
}
	