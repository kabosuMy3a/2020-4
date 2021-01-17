#include <iostream>
#include <string>

template <typename T>
struct cir_list_node
{
	T* data;
	cir_list_node * prev;
	cir_list_node * next;

	~cir_list_node(){
		delete data;
	}
};

template <typename T>
struct cir_list{

	public: 
		using node = cir_list_node<T>;
		using node_ptr = node * ;

		cir_list() : n(0){
			head = new node{NULL, NULL, NULL};
			head->next = head;
			head->prev = head;
		}

		size_t size() const{
			return n;
		}

		//Dummy] <-> head <->...[lists] <-> [Dummy] 
		//insert at head
		void insert(const T& value){
			node_ptr newNode = new node {new T(value), 0x0, 0x0};
			n++;
			auto dummy = head->prev;
			dummy->next = newNode;
			newNode->prev = dummy;
			if(head == dummy){//first insert
				dummy->prev = newNode ;
				newNode->next = dummy;
				head = newNode;
				return ;
			}
			newNode->next = head ;
			head->prev = newNode ;
			head = newNode ;
		}

		void erase(const T& value){
			auto cur = head, dummy = head->prev ;
			while(cur != dummy){
				if(*(cur->data) == value){
					cur->next->prev = cur->prev;
					cur->prev->next = cur->next;
					if(cur==head)
						head = head->next;
					delete cur;
					n--;
					return ;
				}
				cur = cur->next;
			}
		} 

		struct cir_list_it{
			private: 
				node_ptr ptr;
			
			public:
				cir_list_it(node_ptr p) : ptr(p) {}

				T& operator*(){
					return *(ptr->data);
				}

				node_ptr get(){ return ptr; }


				cir_list_it& operator++(){
					ptr = ptr->next;
					return *this;
				}

				cir_list_it& operator++(int){
					cir_list_it it = *this;
					++(*this);
					return it;
				}

				cir_list_it& operator--(){
					ptr = ptr->prev;
					return *this;
				}

				cir_list_it& operator--(int){
					cir_list_it it = *this;
					--(*this);
					return it;
				}

				friend bool operator==(const cir_list_it& it1, const cir_list_it& it2){
					return it1.ptr == it2.ptr;
				}

				friend bool operator!=(const cir_list_it& it1, const cir_list_it& it2){
					return it1.ptr != it2.ptr;
				}


		};

		cir_list_it begin(){
			return cir_list_it {head};
		}

		cir_list_it begin() const{
			return cir_list_it {head};
		}

		cir_list_it end(){
			return cir_list_it {head->prev};
		}

		cir_list_it end() const{
			return cir_list_it {head->prev};
		}

		cir_list(const cir_list<T>& other) : cir_list(){
			for(const auto& i : other){
				insert(i);
			}
		}

		cir_list(const std::initializer_list<T>& il): head(NULL), n(0){
			for(const auto& i : il)
				insert(i);
		}

		~cir_list(){
			while(size()){
				erase(*(head->data));
			}

			delete head;
		}


	private:
		node_ptr head;
		size_t n ;

};

struct playlist{
	cir_list<int> list;



	void insert(int song){
		list.insert(song);
	}

	void erase(int song){
		list.erase(song);
	}

	void loopOnce(){
		for(auto& song : list){
			std::cout << song << std::endl;
		}
	}

};

struct playlist2{
	cir_list<std::string> list;

	playlist2(const std::initializer_list<std::string>& il){
		for(auto& i : il){
			list.insert(i);
		}

	}

	void insert(std::string song){
		list.insert(song);
	}

	void erase(std::string song){
		list.erase(song);
	}

	void loopOnce(){
		for(auto& song : list){
			std::cout << song << std::endl;
		}
		std::cout << std::endl ;
	}

};

int main(){

	/*playlist pl; // = {"Basket case", "she\'s a rebel", "호랑이의 숲", "Give me a novacane", "Don\'t panic"};
	pl.insert(0);
	pl.insert(1);
	std::cout<< "0118-1" << std::endl; 
	pl.loopOnce();

	playlist pl2 = pl;
	pl2.erase(1);
	pl2.insert(2);
	std::cout<< "0118-2" << std::endl;
	pl2.loopOnce();
	std::cout<< "0118-1" << std::endl;
	pl.loopOnce();*/	

	playlist2 pl = {"Basket case", "she\'s a rebel", "호랑이의 숲", "Give me a novacane", "Don\'t panic"};
	pl.insert("whasername");
	pl.insert("바람들");
	std::cout<< "0118-1" << std::endl ; 
	pl.loopOnce();

	playlist2 pl2 = pl;
	pl2.erase("호랑이의 숲");
	pl2.insert("조금만 일찍 알았더라면");
	std::cout<< "0118-2" << std::endl;
	pl2.loopOnce();
	std::cout<< "0118-1" << std::endl;
	pl.loopOnce();	
	return 0;
}