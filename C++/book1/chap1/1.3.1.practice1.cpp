#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

template <typename T>
class dynamic_array{
	T * data ;
	size_t n ;

	public:

		//
		dynamic_array(int n){
			this->n = n;
			data = new T[n];
		}

		//deep copy : other array는 변하지 않음
		dynamic_array(const dynamic_array<T>& other){
			n = other.n ;
			data = new T[n];

			for(int i = 0 ; i < n ; i++){
				data[i] = other.data[i] ;
			}
		}

		//T&을 리턴하면 실제 객체를 리턴
		//T를 리턴하면 복사된 객체값을 리턴
		T& operator[] (int index){
			return data[index];
		}

		//const는 안전장치 () const {} 이건 method를 호출하는 객체를 제한
		//호출 객체의 변수를 건들지 않겠다는 선언
		const T& operator[] (int index) const{
			return data[index] ;
		}

		T& at(int index){
			if(index < n)
				return data[index];
			throw "Index out of range" ; 
		}

		size_t size() const{
			return n;
		}

		//destructor
		~dynamic_array(){
			delete[] data ;
		}

		T* begin(){
			return data ;
		}

		const T* begin() const {
			return data ;
		}

		T* end(){
			return data+n ; 
		}

		const T* end() const {
			return data+n ;
		}

		//friend method는 private 변수에 접근 가능
		//argument의 private 필드에 접근하기 위함 
		friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, 
												const dynamic_array<T>& arr2){
			dynamic_array<T> result(arr1.size()+arr2.size());
			std::copy(arr1.begin(), arr1.end(), result.begin());
			std::copy(arr2.begin(), arr2.end(), result.begin()+arr1.size());

			return result;
		} 

		//구분자를 인수를 받을 수 있고 기본 값은 ", "으로 할당 돼 있는 것
		std::string to_string(const std::string& sep = ", "){
			if(n==0)
				return "";

			std::ostringstream os ;
			os << data[0];

			for(int i = 1 ; i < n ; i++)
				os << sep << data[i] ;

			return os.str();
		}


};

struct student{
	std::string name; 
	int standard ;
};

std::ostream& operator<<(std::ostream& os, const student& s){
	return (os << "[" << s.name << ", " << s.standard << "]");
}

int main(){
	int nStudents ;
	std::cout << "학생수 입력 ㄱ" << std::endl;
	std::cin >> nStudents ;

	dynamic_array<student> class1(nStudents) ;

	for(int i = 0 ; i < nStudents ; i++){
		std::string name;
		int standard ;
		std::cout << i+1 << "번째 학생 이름과 나이를 입력하세요" ;
		std::cin >> name >> standard ;
		
		class1[i] = student{name, standard} ;
	}

	auto class2 = class1;
	std::cout << class2.to_string() << std::endl;
	auto class3 = class1 + class2 ;
	std::cout << class3.to_string() << std::endl ;

	std::cout << *(class3.begin()) << std::endl ; 

	return 0;

}