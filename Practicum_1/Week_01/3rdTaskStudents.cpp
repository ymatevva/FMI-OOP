#include<iostream>
constexpr int NAME_SIZE = 20;

struct Student {
	
	char name[NAME_SIZE];
	unsigned facultyNumber;
	int group;
	double grade;
};

void readStudent(Student& student) {

	std::cin >> student.name;
	std::cin >> student.facultyNumber;
	std::cin >> student.group;
	std::cin >> student.grade;
}

void printStudent(const Student& student) {

	std::cout << student.name << " ";
	std::cout << student.facultyNumber << " ";
	std::cout << student.group << " ";
	std::cout << student.grade << std::endl;
}

unsigned scholarship(const Student* arrStudents, size_t N, double minGrade) {

	unsigned int count = 0;

	for (size_t i = 0; i < N; i++){
		if (arrStudents[i].grade >= minGrade)
			count++;
	}

	return count;
}

Student* arrScholarships(const Student* arrStudents, size_t N, double minGrade){
	
	Student* newArr = new Student[scholarship(arrStudents, N, minGrade)];
	unsigned newInd = 0;

	for (size_t i = 0; i < N; i++)
	{
		if (arrStudents[i].grade >= minGrade)
			newArr[newInd++] = arrStudents[i];
	}
	return newArr;
}

void printStudents(const Student* arrSt, size_t N) {

	for (size_t i = 0; i < N; i++){
		printStudent(arrSt[i]);
	}
}

void sortBYGroupAndFN(Student* arrAllStudents, size_t N, double minGrade)
{
	Student* arrStudents = arrScholarships(arrAllStudents, N, minGrade);
	size_t eligibleCount = scholarship(arrAllStudents, N, minGrade);

	for (size_t i = 0; i < N  - 1; i++)
	{
		int minElIndGroup = i;
		int minElIndFN = i;

		for (size_t j = i + 1; j < N; j++){
			
			if (arrStudents[j].group < arrStudents[minElIndGroup].group) {
				minElIndGroup = j;
			}

			else if (arrStudents[j].group == arrStudents[minElIndGroup].group && arrStudents[j].facultyNumber < arrStudents[minElIndFN].facultyNumber) {
				minElIndFN = j;
			}
		}
		
		if (minElIndGroup != i){
			std::swap(arrStudents[i], arrStudents[minElIndGroup]);
		}


		if (minElIndGroup != i) {
			std::swap(arrStudents[i], arrStudents[minElIndFN]);
		}
	}

	printStudents(arrStudents, eligibleCount);

	delete[] arrStudents;
}
int main() {

	unsigned N;
	std::cin >> N;

	Student* arrStudents = new Student[N];
	double avgScore = 0;

	for (size_t i = 0; i < N; i++){
		readStudent(arrStudents[i]);
		avgScore += arrStudents[i].grade;
	}

	avgScore /= N;

	double minGrade  = 0;
	std::cin >> minGrade;

	sortBYGroupAndFN(arrStudents, N, minGrade);

	delete[] arrStudents;
	return 0;
}