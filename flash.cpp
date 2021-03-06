#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

struct card{
	std::string front;
	std::string back;
	bool correct;
};

int find(char *arr[], char *search, int len){
	int index = -1;
	for (int i = 0; i < len; i++){
		if (arr[i] == search)
			index == i;
	}
	return index;
}

void swap(card arr[], int a, int b){
	card tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void shuf(card arr[], int len){
	srand(time(NULL));
	int j;
	for (int i = len - 1; i > 0; i--){
		j = rand() % (i + 1);
		swap(arr, j, i);
	}
}

int main(int argc, char *argv[]){
	std::vector<char*> files;
	bool rev = false;
	bool shf = false;
	for (int i = 1; i < argc; i++){
		if (argv[i][0] != '-')
			files.push_back(argv[i]);		
		else if (argv[i][1] == 'r')
			rev = true;
		else if (argv[i][1] == 's')
			shf = true;
	}
	for (int it = 0; it < files.size(); it++){
		char *filename = files.at(it);
		std::ifstream in (filename);
		int n;
		int points = 0;
		in >> n;
		card cards[n];
		if (rev)
			std::cout << "Cards are reversed" << '\n';
		for (int i = 0; i < n; i++){
			if (!rev){
				in >> cards[i].front;
				in >> cards[i].back;
			}
			else{
				in >> cards[i].back;
				in >> cards[i].front;
			}
		}
		if (shf){
			shuf(cards, n);
			std::cout << "Cards are shuffled" << '\n';
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
