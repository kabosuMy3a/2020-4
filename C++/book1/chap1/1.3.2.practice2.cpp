// 여러 type을 하나의 공통 타입으로 변환하는 템플릿

#include <array>
#include <iostream>
#include <type_traits>

//임의 개수의 매개변수
template<typename ... Args>
//std::array<?, ?> build_array(Args&&... args)
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, ?>{
	using commonType = typename std::common_type<Args...>::type;
	return {std::forward<commonType>((Args&&)args)}
}

int main(){

	auto data = build_array(1, 0u, 'a', 3.2f, false);
	for (auto i: data)
		std:: cout << i << " ";
	std::cout << std::endl;


}
