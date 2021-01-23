//BST 트리를 구현해보고 균형트리, 시간복잡도 등을 생각해보자.

#include <iostream>
#include <queue>

struct node {
	int data ;
	node * left;
	node * right;
};

struct BST {
	node * root = nullptr; //nullptr != 0x0 

	node * find(int value){
		return find_impl(root, value);
	}

	void insert(int value){
		if(!root)
			root = new node{value, nullptr, nullptr};
		else 
			insert_impl(root, value);
	}

	void in_order(){
		in_order_impl(root);
	}

	void level_order(){
		level_order_impl(root);
	}

	node * successor(node * predecessor){
		auto current = predecessor->right ;
		while (current && current->left){
			current = current->left ;
		}
		return current ; 
	}

	void remove(int value){
		root = remove_impl(root, value);
	}



	void printBT()
	{
	    printBT("", root, false);    
	}

	private:
		node * find_impl(node * current, int value){
			if(!current) return 0x0 ;

			if(current->data == value) 
				return current ;

			if(value < current->data)	
				return find_impl(current->left, value) ;

			/* current->data < value */
			return find_impl(current->right, value);
		} 

		void insert_impl(node * current, int value){
			if (value < current->data){
				if(!current->left)
					current->left = new node{value, nullptr, nullptr};
				else 
					insert_impl(current->left, value);
			} else { //같으면 오른쪽 child에다 넣음 
				if(!current->right)
					current->right = new node{value, nullptr, nullptr};
				else
					insert_impl(current->right, value);		
			}
		}

		void in_order_impl(node * current){
			if(!current) return ;

			in_order_impl(current->left);
			std::cout << current->data << std::endl;
			in_order_impl(current->right);
		}

		void level_order_impl(node * start){
			if(!start)	return ;

			std::queue<node *> printer ;
			printer.push(start);
			while(not printer.empty()){
				int size = printer.size();
				for(int i = 0 ; i < size ; i++){
					node * now = printer.front();
					printer.pop();
					std::cout << now->data << " " ;

					if(now->left) printer.push(now->left);
					if(now->right) printer.push(now->right);
				}
				std::cout << std::endl ;	
			}
		}

		node * remove_impl(node * start, int value){
			if(!start) return 0x0;

			if(value < start->data){
				start->left = remove_impl(start->left, value);
			} else if(value > start->data){
				start->right = remove_impl(start->right, value);
			} else /* find target */ {
				if(!start->left){
					auto tmp = start->right ;
					delete start;
					return tmp ;
				}

				if(!start->right){
					auto tmp = start->left ;
					delete start ;
					return tmp ;
				}

				auto tmp = successor(start) ;
				start->data = tmp->data ;
				//delete tmp ; //안됨 왜? 트리에 연결돼 있는 걸 복사한 거니까
				remove_impl(start->right, start->data);

			}

			return start ;
		}

		void printBT(const std::string& prefix, const node * start, bool isLeft)
		{
		    if( start != nullptr )
		    {
		        std::cout << prefix;

		        std::cout << (isLeft ? "├──" : "└──" );

		        // print the value of the node
		        std::cout << start->data << std::endl;

		        // enter the next tree level - left and right branch
		        printBT( prefix + (isLeft ? "│   " : "    "), start->left, true);
		        printBT( prefix + (isLeft ? "│   " : "    "), start->right, false);
		    }
		}

};



int main(){

		BST bst ; 

		bst.insert(52);
		bst.insert(22);
		bst.insert(75);
		bst.insert(112);
		bst.insert(11);
		bst.insert(45);
		bst.insert(66);
		bst.insert(66);
		bst.insert(77);
		bst.insert(123);
		bst.insert(11);

		bst.printBT();
		//bst.remove(11);
		//bst.remove(77);
		bst.remove(52);
		bst.printBT();

		//implement remove_all, remove duplicate
		//easy 


}