#include <iostream>
#include <array>

template <size_t N>
void print(const std::array<int, N> & arr){
	for (auto ele : arr){
		std::cout << ele << ", ";
	}
	//arr[2] = 1111 ; available without const
}
// &는 참조를 의미한다

int main(){

	std::array<int, 10> arr1 ;

	arr1[0] = 1;
	std::cout << "arr1 first ele" << arr1[0] << std::endl ;
	
	std::array<int, 4> arr2  = {1, 2, 3, 4};
	std::cout << "arr2 all ele" ;
	for (int i = 0 ; i < arr2.size() ; i++){
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl; 

	//////////////////////////////////////////////////////////
	// out of index //
	try{
		std::cout << arr2.at(3) << std::endl;
		std::cout << arr2.at(4) << std::endl;
	} catch(const std::out_of_range& ex) {
		std::cerr << ex.what() << std::endl;
	}

	////////////////////////////////////////////////////////
	//template 매개변수, 참조형, const //
	std::array<int, 5> arr = {1,2,3,4,5} ;
	print(arr);
	print(arr);

	////////////////////////////////////////////////////////
	// iterator // 
	for (auto it = arr.begin() ; it != arr.end() ; it++){
		auto ele1 = (*it) ; // iterator is pointer
		std::cout << ele1 << ' ';
	}
	std::cout << std::endl ;
	std::cout << *(arr.data() + 2) ;
	std::cout << arr.front() << std::endl;
	
}