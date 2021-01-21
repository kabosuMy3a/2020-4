//회사 조직도

#include <iostream>
#include <queue>

//일단은 최대 두 명의 부하 직원이 있는 이진 트리 

struct node{

	std::string position;
	node * first ;
	node * second ;
};

struct org_tree{

	node * root;

	static org_tree create_org_structure(const std::string& pos){
		org_tree tree ;
		tree.root = new node {pos, NULL, NULL};
		return tree ;
	}

	static node * find(node * root, const std::string& value){
		if(root == NULL){
			return NULL ;
		}

		if(root->position == value)
			return root;

		auto firstFound = org_tree::find(root->first, value);
		if(firstFound != NULL ) 
			return firstFound ;

		return org_tree::find(root->second, value);
	}

	bool addSubordinate(const std::string& manager, const std::string& subordinate){
		auto managerNode = org_tree::find(root, manager);

		if(!managerNode){
			//찾을 수 없음
			return false ;
		}

		if(managerNode->first && managerNode->second){
			//꽉참 
			return false;
		}

		if(!managerNode->first){
			managerNode->first = new node {subordinate, NULL, NULL};
			std::cout<< manager << " 왼쪽에 " << subordinate << " 추가했습니다." <<std::endl;  

		} else {
			managerNode->second = new node {subordinate, NULL, NULL} ;	
			std::cout<< manager << " 오른쪽에 " << subordinate << " 추가했습니다." <<std::endl;  
		}

		return true ;
	}
};

static void pre_order_traverse(node * start){
	if(!start) return ;

	std::cout<< start->position << std::endl;
	pre_order_traverse(start->first);
	pre_order_traverse(start->second);
}

static void in_order_traverse(node * start){
	if(!start) return ;

	in_order_traverse(start->first);
	std::cout<< start->position << std::endl;
	in_order_traverse(start->second);
}

static void post_order_traverse(node * start){
	if(!start) return ;

	post_order_traverse(start->first);
	post_order_traverse(start->second);
	std::cout<< start->position << std::endl;
}

static void level_order_traverse(node * start){
	if(!start)	return ;

	std::queue<node *> printer ;
	printer.push(start);
	while(not printer.empty()){
		int size = printer.size();
		for(int i = 0 ; i < size ; i++){
			node * now = printer.front();
			printer.pop();
			std::cout << now->position << " " ;

			if(now->first) printer.push(now->first);
			if(now->second) printer.push(now->second);
		}
		std::cout << std::endl ;
		
	}

}

int main(){
	auto tree = org_tree::create_org_structure("CEO");
	tree.addSubordinate("CEO", "부사장");
	tree.addSubordinate("부사장", "IT 부장");
	tree.addSubordinate("부사장", "마케팅부장");
	tree.addSubordinate("부사장", "구루루");
	tree.addSubordinate("마케팅부장", "물류팀장");
	tree.addSubordinate("마케팅부장", "홍보팀장");
	tree.addSubordinate("IT 부장", "보안팀장");
	tree.addSubordinate("IT 부장", "앱개발팀장");

	pre_order_traverse(tree.root);
	std::cout << std::endl;
	in_order_traverse(tree.root);
	std::cout << std::endl;
	post_order_traverse(tree.root);
	std::cout << std::endl;
	level_order_traverse(tree.root);
	std::cout << std::endl;

}