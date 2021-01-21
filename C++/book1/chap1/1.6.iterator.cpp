#include <iostream>
#include <forward_list>
#include <vector>

int main(){
	std::vector<std::string> lol_world_championship = {
		"DWG", "FPX", "IG", "Samsung", "SKT", "SKT", "Samsung", "SKT", "TPA", "Fnatic"
	};

	auto it = lol_world_championship.begin();
	std::cout<< "가장 최근 우승팀: " << *it << std::endl;

	it += 6 ;
	std::cout << "6년 전 우승팀: " << *it << std::endl ;

	advance(it, -2);

	std::cout << "그로부터 2년 뒤 우승팀: " << *it << std::endl ;

	std::forward_list<std::string> fw(lol_world_championship.begin(), lol_world_championship.end());

	auto it2 = fw.begin();
	advance(it2, 1);

	std::cout << "1년 전 우승팀: " << *it2 << std::endl;
}