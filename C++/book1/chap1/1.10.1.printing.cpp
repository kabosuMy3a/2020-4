#include <iostream>
#include <queue>
#include <string>

class Job{

	int id ;
	std::string user ;
	int pages ;

	static int count ;

	public: 
		Job(const std::string& u, int p) : user(u), pages(p), id(++count){}
		friend std::ostream& operator<<(std::ostream& os, const Job& j){
			os << "id: " << j.id << ", user: " << j.user << ", pages: " << j.pages ;
			return os ;
		}	
};

int Job::count = 0 ;


template <size_t MAX>
class Printer{
	 
	std::queue<Job> buffer ; 
	
	public:
		bool request(const Job& job){
			if(buffer.size()== MAX){
				return false ;
			}
			std::cout << "Plus job: " << job << std::endl ;
			buffer.push(job);
			return true ;
		}

		void print(){
			while(not buffer.empty()){
				std::cout << "Printing now: " << buffer.front() << std::endl;
				buffer.pop();
			}
		}
};




int main(){

	Printer<3> printer ;
	Job j1("sun", 11);
	Job j2("gyu", 132);
	Job j3("kasu", 123);
	Job j4("sdf", 11);

	printer.request(j1);
	printer.request(j2);
	printer.request(j3);
	printer.request(j4);
	printer.print();
	printer.request(j4);
	printer.print();
	return 0 ;
}