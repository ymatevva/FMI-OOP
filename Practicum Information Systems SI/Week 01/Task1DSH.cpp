#include<iostream>

namespace Constants {
	constexpr int TITLE_SIZE = 51;
	constexpr int AUTHOR_SIZE = 51;
	constexpr int LIBRARY_SIZE = 10;
	constexpr int GENRE_SIZE = 20;
} ;
enum class Genre {
	Novel,
	Historical,
	Poetry,
	Other
};

struct Book {
	char title[Constants :: TITLE_SIZE];
	char author[Constants :: AUTHOR_SIZE];
	Genre genre;
	int availability;
};


struct Library {
	size_t count = 0;
	Book books[Constants :: LIBRARY_SIZE];
};


int myStrCmp(const char* str1, const char* str2) {

	if (!str1 || !str2)
		return -9;

	while (*str1 && (*str1 == *str2)) {
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}
Genre readGenre() {

	char genre[Constants::GENRE_SIZE];
	std::cin.getline(genre, Constants::GENRE_SIZE);

	if (myStrCmp(genre, "Novel") == 0)
		return Genre::Novel;

	else if (myStrCmp(genre, "Historical") == 0)
		return Genre::Historical;

	else if (myStrCmp(genre, "Poetry") == 0)
		return Genre::Poetry;

	else
		return Genre::Other;
}

void readBook(Book& book) {

	std::cin.getline(book.title,Constants ::TITLE_SIZE);
	std::cin.getline(book.author,Constants ::  AUTHOR_SIZE);
	book.genre = readGenre();
	std::cin >> book.availability;
	std::cin.ignore();
}

void addNewBook(Book& book, Library& library) {
	
	if (library.count + 1 > Constants::LIBRARY_SIZE){
		std::cout << "There is not enough space." << std::endl;
		return;
	}

	library.books[library.count + 1] = book;
}


void getBook(Library& library, const char* str) {

	for (size_t i = 0; i < library.count; i++){
		if (myStrCmp(library.books[i].title, str) == 0)
			library.books[i].availability -= 1;
	}
}

void addBook(Library& library, const char* str) {

	for (size_t i = 0; i < library.count; i++) {
		if (myStrCmp(library.books[i].title, str) == 0)
			library.books[i].availability += 1;
	}
}




void printGenre(const Book& book) {

	if (book.genre == Genre::Novel)
		std::cout << "Novel" << std::endl;

	else if (book.genre == Genre::Historical)
		std::cout << "Historical" << std::endl;

	else if (book.genre == Genre::Poetry)
		std::cout << "Poetry" << std::endl;

	else
		std::cout << "Other" << std::endl;

}


void printBook(const Book& book) {

	std::cout << book.title << std::endl;
	std::cout << book.author << std::endl;
	printGenre(book);
	std::cout << book.availability << std::endl;
}

void printLibrary(const Library& library) {
	
	for (size_t i = 0; i < library.count; i++){
		printBook(library.books[i]);
	}
}

int main() {

	Library library{};
	for (size_t i = 0; i < 2; i++){
		readBook(library.books[i]);
		library.count++;
	}

	printLibrary(library);

	return 0;
}