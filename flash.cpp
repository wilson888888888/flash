#include <iostream>
#include <fstream>

struct card{
	std::string front;
	std::string back;
	bool correct;
};

int main(int argc, char *argv[]){
	bool good = true;
	if (argc != 2){
		std::cout << "Wrong number of arguments" << '\n';
		good = false;
	}
	if (good){
		std::ifstream in (argv[1]);
		int n;
		int points = 0;
		in >> n;
		card cards[n];	
		for (int i = 0; i < n; i++){
			in >> cards[i].front;
			in >> cards[i].back;
		}
		std::string input;
		for (int i = 0; i < n; i++){
			std::cout << cards[i].front << '\n';
			std::cin >> input;
			if (input == cards[i].back){
				std::cout << "Correct. +1 point" << '\n';
				points++;
				cards[i].correct = true;
			}	
			else{
				std::cout << "Incorrect. Answer was " << cards[i].back << '\n';
				cards[i].correct = false;
			}
		}
		std::cout << "Your total score was " << points << "/" << n << '\n';
		std::cout << "Missed cards were: " << '\n';
		for (int i = 0; i < n; i++){
			if (!cards[i].correct){
				std::cout << cards[i].front << '\n';
			}
		}
	}
}
