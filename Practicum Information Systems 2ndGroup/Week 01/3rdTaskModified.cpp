#include<iostream>
#include<fstream>
#pragma warning (disable:4996)


constexpr int CURRENCY_LENGHT = 3;
enum class  TypeBankAccount {

	Undefined,
	Deposit,
	Collection,
	Checking
};

enum class Currency {

	Undefined,
	BGN,
	EUR,
	GDR,
	TRL
};

struct BankAccount {

	char* accountNumber = nullptr;//let's say that the number contains not only digits//8 bytes
	double balance = 0;
	Currency currency = Currency::Undefined;
	TypeBankAccount typeBankAcc = TypeBankAccount::Undefined;

};


BankAccount init(const char* accNum, double balance, Currency currency, TypeBankAccount typeBankAcc) {

	BankAccount bankAccount{};

	size_t accNumLen = strlen(accNum);
	bankAccount.accountNumber = new char[accNumLen + 1];
	strcpy(bankAccount.accountNumber, accNum);

	bankAccount.balance = balance;
	bankAccount.currency = currency;
	bankAccount.typeBankAcc = typeBankAcc;

	return bankAccount;
}


void readBankAccFromFile(std::ifstream& ifs, BankAccount& bankAcc) {

	size_t accNameLen = 0;
	ifs.read((char*)&accNameLen, sizeof(accNameLen));
	bankAcc.accountNumber = new char[accNameLen + 1];
	ifs.read(bankAcc.accountNumber, accNameLen + 1);

	ifs.read((char*)&bankAcc.balance, sizeof(bankAcc.balance));
	ifs.read((char*)&bankAcc.currency, sizeof(bankAcc.currency));
	ifs.read((char*)&bankAcc.typeBankAcc, sizeof(bankAcc.typeBankAcc));
}
void readBankAccArrFromFile(std::ifstream& ifs, BankAccount*& bankAccArr, size_t& sizeArr) {

	ifs.read((char*)&sizeArr, sizeof(sizeArr));
	bankAccArr = new BankAccount[sizeArr];

	for (size_t i = 0; i < sizeArr; i++) {
		readBankAccFromFile(ifs, bankAccArr[i]);
	}
}
void readFromFile(const char* fromFile, BankAccount*& bankAccArr, size_t& sizeArr) {

	if (!fromFile)
		return;

	std::ifstream ifs(fromFile, std::ios::binary);
	if (!ifs.is_open())
		return;

	readBankAccArrFromFile(ifs, bankAccArr, sizeArr);
}

void writeBankAccToFile(std::ofstream& ofs, const BankAccount& bankAccount) {

	size_t accNameLen = strlen(bankAccount.accountNumber);
	ofs.write((const char*)&accNameLen, sizeof(accNameLen));
	ofs.write(bankAccount.accountNumber, accNameLen + 1);

	ofs.write((const char*)&bankAccount.balance, sizeof(bankAccount.balance));
	ofs.write((const char*)&bankAccount.currency, sizeof(bankAccount.currency));
	ofs.write((const char*)&bankAccount.typeBankAcc, sizeof(bankAccount.typeBankAcc));
}
void writeArrToFile(std::ofstream& ofs, const BankAccount* bankAccArr, size_t arrSize) {


	if (!bankAccArr)
		return;

	ofs.write((const char*)&arrSize, sizeof(arrSize));
	for (size_t i = 0; i < arrSize; i++) {
		writeBankAccToFile(ofs, bankAccArr[i]);
	}
}
void writeToFile(const char* toFile, const BankAccount* bankAccArr, size_t arrSize) {


	if (!toFile || !bankAccArr)
		return;

	std::ofstream ofs(toFile, std::ios::binary);
	if (!ofs.is_open())
		return;


	writeArrToFile(ofs, bankAccArr, arrSize);
}


void printCurrency(const Currency& currency) {

	switch (currency) {

	case Currency::BGN:
		std::cout << "BGN" << " "; break;

	case Currency::EUR:
		std::cout << "EUR" << " "; break;

	case Currency::GDR:
		std::cout << "GDR" << " "; break;

	case Currency::Undefined:
		std::cout << "Undefined" << " "; break;
	}
}
void printTypeAccount(const TypeBankAccount& typeAccount) {

	switch (typeAccount) {

	case(TypeBankAccount::Undefined):
		std::cout << "Undefined" << " "; break;

	case(TypeBankAccount::Checking):
		std::cout << "Checking" << " "; break;

	case(TypeBankAccount::Collection):
		std::cout << "Collection" << " "; break;

	case(TypeBankAccount::Deposit):
		std::cout << "Deposit" << " "; break;

	}
}
void printBankAccount(const BankAccount& bankAcc) {

	std::cout << bankAcc.accountNumber << " " << bankAcc.balance << " ";
	printCurrency(bankAcc.currency);
	printTypeAccount(bankAcc.typeBankAcc);
}
void printArr(const BankAccount* bankAccArr, size_t arrSize) {
	if (!bankAccArr)
		return;

	for (size_t i = 0; i < arrSize; i++) {
		printBankAccount(bankAccArr[i]);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void withdrawMoney(BankAccount& bankAcc, double moneyToWithdraw) {

	if (bankAcc.balance - moneyToWithdraw >= 0) {
		bankAcc.balance -= moneyToWithdraw;
		std::cout << "The withdraw was successful. " << std::endl;
		std::cout << "The current balance is: " << bankAcc.balance << std::endl;
	}
	else
		std::cout << "The withdraw was not successful. " << std::endl;

	std::cout << std::endl;
}

void depositMoney(BankAccount& bankAcc, double moneyToDeposit) {

	bankAcc.balance += moneyToDeposit;
	std::cout << "The deposit was successful. " << std::endl;
	std::cout << "The current balance is: " << bankAcc.balance << std::endl;

	std::cout << std::endl;
}

void changeCurrency(BankAccount& bankAcc, const char* currency) {

	if (!currency || !(*currency) || strlen(currency) != CURRENCY_LENGHT) {
		std::cout << "Invalid currency" << std::endl;
		return;
	}

	if (strcmp(currency, "BGN") == 0) {
		bankAcc.currency = Currency::BGN;
	}

	else if (strcmp(currency, "EUR") == 0) {
		bankAcc.currency = Currency::EUR;
	}

	else if (strcmp(currency, "GDR") == 0) {
		bankAcc.currency = Currency::GDR;
	}

	else {
		bankAcc.currency = Currency::Undefined;
	}
}

int main() {

	BankAccount bankAccounts [3];
	bankAccounts[0] = init("3MI0700295", 20.5, Currency::BGN, TypeBankAccount::Deposit);
	bankAccounts[1] = init("3MI0600266", 29.2, Currency::GDR, TypeBankAccount::Checking);
	bankAccounts[2] = init("1MI0700241", 14.9, Currency::EUR, TypeBankAccount::Collection);

	writeToFile("BankAccounts.dat", bankAccounts, 3);

	size_t sizeArr = 0;
	BankAccount* bankAccArr;

	readFromFile("BankAccounts.dat", bankAccArr, sizeArr);
	printArr(bankAccArr, sizeArr);

	double moneyToWithdraw = 0;
	std::cin >> moneyToWithdraw;

	withdrawMoney(bankAccArr[2], moneyToWithdraw);
	printArr(bankAccArr, sizeArr);

	double moneyToDeposit = 0;
	std::cin >> moneyToDeposit;

	depositMoney(bankAccArr[1], moneyToDeposit);
	printArr(bankAccArr, sizeArr);

	changeCurrency(bankAccArr[0], "EUR");
	printArr(bankAccArr, sizeArr);

	for (size_t i = 0; i < sizeArr; ++i) {
		delete[] bankAccArr[i].accountNumber;
	}
	delete[] bankAccArr;

	return 0;
}
