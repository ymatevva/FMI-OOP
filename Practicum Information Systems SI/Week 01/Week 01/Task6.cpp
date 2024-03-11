#include<iostream>

constexpr int QUESTIONS_SIZE = 10;
constexpr int TITLE_SIZE = 51;

struct Answer {
	char letter;
	char answerContent[TITLE_SIZE];
};

struct Question {

	char title[TITLE_SIZE];
	char correctAnswerLetter;
	Answer options[4];
	double points;
};

struct Test {
	Question questions[QUESTIONS_SIZE];
	size_t count = 0;
};

void printQuestion(const Question& question) {
	std::cout << question.title << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << question.options[i].letter << ": " << question.options[i].answerContent << std::endl;
	}
}

void playTest(const Test& test) {
	
	double points = 0;
	for (size_t i = 0; i < test.count ; i++){
		
		printQuestion(test.questions[i]);
		std::cout << std::endl;

		char userAnswer;
		std::cin >> userAnswer;

		if (userAnswer == test.questions[i].correctAnswerLetter) {
			std::cout << "correct" << std::endl;
			points += test.questions[i].points;
		}
		else
			std::cout << "wrong answer" << std::endl;
	}

	std::cout << "Points: " << points << std::endl;
}
int main() {



	return 0;
}