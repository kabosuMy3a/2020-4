#include <iostream>
#include <list>


void list_print(std::list<int> list1){
	for(auto i : list1)
		std::cout<< i << " ";
	std::cout<< std::endl;
}


int main(){

	std::list<int> list1 = {3,2,4,8,5};

	list1.push_back(6);
	list1.insert(next(list1.begin()), 0);
	list1.insert(prev(list1.end()),7);
	//prev와 next를 이용한 위치 찾기는 O(n)의 시간복잡도를 가진다 !

	list_print(list1);


	list1.pop_back();
	list1.sort();
	list_print(list1);

	//vector는 iterator를 저장한 후 vector를 변경하면 반복자가 무효화되지만
	//List는 list가 변경되어도 반복자가 무효화 되지 않는다.
	//다리를 건너는 트럭에서 queue를 사용했던 이유와 일맥상통하다.

}