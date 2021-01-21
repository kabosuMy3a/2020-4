//Written by kabosuMy3a 210119 ~ 210120
//가끔 무한 루프가 걸리는데 이유는 아마
//Erase 로직 아니면 랜덤 관련 이슈
//Solution from book is 1.7.5+1.solution.cpp
//Solution 코드도 같은 오류인 것 보니 게임 자체의 오류 

#include <iostream>
#include <random>
#include <list>
#include <algorithm>
#include <vector>
#include <array>
#include <cstdlib>
#include <chrono>

enum Shape{
	clover,
	heart,
	diamond,
	spade
};

std::string Shapes[]= {
	"\u2663", "\u2665", "\u2666", "\u2660"
};

struct Card {
	int num ;
	Shape shape;
};

std::ostream& operator<<(std::ostream& os, const Card& card){
	os << "[" << card.num << "/ " << Shapes[card.shape] << " ]" ;
	return os ; 
}


struct Player {
	std::vector<Card> hand ;
	std::string name; 

	void receive(Card card){
		hand.push_back(card);
	}

	Card submit(){
		/*
		std::random_device rd ;
		std::mt19937 g(rd());
		int hand_max = hand.size()-1 ;
		std::uniform_int_distribution<int> dis(0, hand_max);
		int num = dis(g);


		Card card = hand.at(num);
		hand.erase(hand.begin()+num);*/
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(hand.begin(),hand.end(),std::default_random_engine(seed));
		Card card = hand.at(hand.size()-1);
		hand.pop_back();

		return card ;

	}
};

struct Deck {
	std::vector<Card> cards ;
	size_t n ;

	Deck(){
		reset();
	}

	void reset(){
		cards.clear();
		for(int j = 1 ; j <= 13 ; j++){
			Card a = {j, clover};
			Card b = {j, heart};
			Card c = {j, diamond};
			Card d = {j, spade};

			cards.push_back(a);
			cards.push_back(b);
			cards.push_back(c);
			cards.push_back(d);

			n+= 4;
		}
		card_shuffle();
	}

	void card_shuffle(){
		std::random_device rd ;
		std::mt19937 g(rd());
		std::shuffle(cards.begin(), cards.end(), g);
	}

	Card give(){
		if(n==0){
			Card null_card = {0,spade};
			return null_card;
		}
		Card card = cards.at(n-1);
		cards.pop_back();
		n--;
		return card ;
	}

};

struct Card_and_Owner{
	Card card ;
	int owner ;
};


void give_cards_to_player(Deck * deck, std::array<Player,4> &players){
	for(int i = 0 ; i < 52 ; i++){
			int n = deck->n;
			Card card = deck->give();
			players[n%4].receive(card);
	}

}

void submit_and_erase_cards(std::array<Player,4> &players){
	Card_and_Owner c1 = {players[0].submit(), 0 };
	Card_and_Owner c2 = {players[1].submit(), 1 };
	Card_and_Owner c3 = {players[2].submit(), 2 };
	Card_and_Owner c4 = {players[3].submit(), 3 };

	std::vector<Card_and_Owner> cards = {c1, c2 ,c3, c4};
	std::random_device rd ;
	std::mt19937 g(rd());
	std::shuffle(cards.begin(), cards.end(), g);

	//Erase Logic//
	int loop = 0;
	int idx = 0 ;
	while(loop != 3){
		int same = idx ;
		for(int i = idx+1 ; i < cards.size() ; i++){
			if(cards[idx].card.num == cards[i].card.num) same = i;
		}
		if(same != idx){
			cards.erase(cards.begin()+same);
			cards.erase(cards.begin()+idx);
			idx = 0 ;
		} else {
			idx++ ;
		}
		loop++ ;
	}
	
	for(auto e : cards){
		std::cout << e.card ;
		players[e.owner].receive(e.card);
	}
	std::cout<<std::endl;
	
}

void start_round(int round){
	for(int i = 0 ; i < round ; i++){
		Deck * deck = new Deck();
		Player p1, p2, p3, p4;
		p1.name = "sungyu";
		p2.name = "gyu";
		p3.name = "kabosu";
		p4.name = "my3a";
		std::array<Player,4> players = {p1,p2,p3,p4} ;
		give_cards_to_player(deck,players);
		std::vector<Player> winners ;
		while(winners.size()==0){
			submit_and_erase_cards(players);
			std::cout <<"<" << players[0].name <<": "<< players[0].hand.size() << ">" ;
			std::cout <<"<" << players[1].name <<": "<< players[1].hand.size() << ">" ;
			std::cout <<"<" << players[2].name <<": "<< players[2].hand.size() << ">" ;
			std::cout <<"<" << players[3].name <<": "<< players[3].hand.size() << ">" ;
			std::cout << std::endl;

			if(players[0].hand.size() == 0){
				winners.push_back(players[0]);
			}
			if(players[1].hand.size() == 0){
				winners.push_back(players[1]);
			}
			if(players[2].hand.size() == 0){
				winners.push_back(players[2]);
			}
			if(players[3].hand.size() == 0){
				winners.push_back(players[3]);
			}
	
		}	

		for(auto winner : winners){
			std::cout << winner.name << std::endl;
		}
		std::cout << std::endl;

		delete(deck);
	}
}
void start_game(int round){
	start_round(round);
}

int main(int argc, char** argv){
	
	start_game(atoi(argv[1]));
	
	return 0; 
}
