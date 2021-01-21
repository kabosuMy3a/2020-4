//forward_list와 같은 동작을 하면서 더 많은 기능을 제공하는 컨테이너 구현

#include <iostream>
#include <algorithm>

struct singly_11_node{
	int data;
	singly_11_node * next;
};


class singly_11{
	public :
		using node = singly_11_node ;
		using node_ptr = node * ;

		void push_front(int val){
			auto new_node = new node {val, NULL};
			if(head != NULL)
				new_node->next = head ;
			head = new_node ;
		}

		void pop_front(){
			auto first = head ;
			if(head != NULL){
				head = head->next ;
				delete first ;
			}
		}

		struct singly_11_iterator{
			private: 
				node_ptr ptr ;

			public:
				singly_11_iterator(node_ptr p) : ptr(p) {}
				int& operator*() { return ptr->data; }
				node_ptr get() { return ptr; }

				singly_11_iterator& operator++(){ //it++
					ptr = ptr->next ;
					return *this ;
				}

				singly_11_iterator operator++(int){ //++it
					singly_11_iterator result = *this;
					++(*this);
					return result;
				}

				friend bool operator==(const singly_11_iterator& left, const singly_11_iterator& right){
					return left.ptr == right.ptr ;
				}

				friend bool operator!=(const singly_11_iterator& left, const singly_11_iterator& right){
					return left.ptr != right.ptr ;
				}
		};

		singly_11_iterator begin() { return singly_11_iterator(head); }
		singly_11_iterator end() { return singly_11_iterator(NULL); }
		singly_11_iterator begin() const { return singly_11_iterator(head); } 
		singly_11_iterator end() const { return singly_11_iterator(NULL); }

		singly_11() = default ;
		singly_11(const singly_11& other) : head(NULL){
			if (other.head){
				head = new node{0, NULL};
				auto cur = head;
				auto it = other.begin();
				while(true){
					cur->data = *it;
					auto tmp = it;
					if(++tmp== other.end()) break;
					cur->next = new node{0, NULL};
					cur = cur->next ;
					it = tmp ;
				}
			}
		}

		singly_11(const std::initializer_list<int>& ilist) : head(NULL){
			for(auto it= std::rbegin(ilist); it != std::rend(ilist) ; it++){
				push_front(*it);
			}
		}

	private :
		node_ptr head ;

};


void s11_print(std::string msg, singly_11& s11){
	std::cout << msg ;
	for(auto i : s11){
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main(){

	singly_11 s11 = {1,2,3};
	s11.push_front(0);
	s11_print("첫 번째 리스트 ", s11);

	auto s112 = s11;
	s112.push_front(-1);
	s11_print("두 번째 리스트 ", s112);
	s11_print("깊은 복사 후 첫 번째 리스트 ", s11);
}