#include<iostream>

constexpr int MAX_SIZE = 30;

enum class TypeBankAccount {

	Payment,
	Recruitment,
	Deposit,
	Undefined
};

enum class Currency {
	
	BGN,
	EUR,
	USD,
	CHF,
	GBP,
	Undefined
};

int myStrCmp(const char* str1, const char* str2) {

	if (!str1 || !str2)
		return -7;

	while (*str1 && (*str1 == *str2)) {
		str1++;
		str2++;
	}

	return *str1 - *str2;
}

TypeBankAccount typeAccount() {

	char str[MAX_SIZE];
	std::cin.getline(str, MAX_SIZE);

	if(myStrCmp(str,"payment") == 0)
		return TypeBankAccount :: Payment;

	else if (myStrCmp(str, "recruitment") == 0 )
		return TypeBankAccount::Recruitment;

	else if (myStrCmp(str, "deposit") == 0)
		return TypeBankAccount::Deposit;

	else
		return TypeBankAccount::Undefined;
}

Currency typeCurrency() {

	char str[MAX_SIZE];
	std::cin.getline(str, MAX_SIZE);

	if (myStrCmp(str, "USD") == 0)
		return Currency::USD;

	else if (myStrCmp(str, "BGN") == 0)
		return Currency::BGN;

	else if (myStrCmp(str, "EUR") == 0)
		return Currency::EUR;

	else if (myStrCmp(str, "CHF") == 0)
		return Currency::CHF;

	else if (myStrCmp(str, "GBP") == 0)
		return Currency::GBP;

	else
		return Currency::Undefined;
}


struct BankAccount {
	
	TypeBankAccount typeAcc;
	Currency currency;
	double balance;
	long number;
};


void depositMoney(BankAccount& account, double moneyAmmount) {
	account.balance += moneyAmmount;
}

void withdraw(BankAccount& account, double moneyAmmount) {

	if (account.balance >= moneyAmmount) {
		account.balance -= moneyAmmount;
	}

	else
		std::cout << "There is not enough amount.";
}

void changeCurrency(BankAccount& account, Currency newCurrency) {

	account.currency = newCurrency;
}

void createBankAccount(BankAccount& account) {


	account.typeAcc = typeAccount();
	account.currency = typeCurrency();

	std::cin >> account.balance;
	std::cin >> account.number;
}

void printTypeAccount(const BankAccount& account) {
	
	if (account.typeAcc == TypeBankAccount::Payment)
		std::cout << "Payment" << std::endl;

	else if (account.typeAcc == TypeBankAccount::Recruitment)
		std::cout << "Recruitment" << std::endl;

	else if (account.typeAcc == TypeBankAccount::Deposit)
		std::cout << "Deposit" << std::endl;

	else if (account.typeAcc == TypeBankAccount::Undefined)
		std::cout << "Undefined" << std::endl;

}

void printCurrency(const BankAccount& account) {

	if (account.currency == Currency::USD)
		std::cout << "USD" << std::endl;

	else if (account.currency == Currency::BGN)
		std::cout << "BGN" << std::endl;

	else if (account.currency == Currency::EUR)
		std::cout << "EUR" << std::endl;

	else if (account.currency == Currency::CHF)
		std::cout << "CHF" << std::endl;

	else if (account.currency == Currency::GBP)
		std::cout << "GBP" << std::endl;

	else
		std::cout << "Undefined" << std::endl;
	
}
void printBankAccount(const BankAccount& account) {

	printTypeAccount(account);
	printCurrency(account);
	std::cout << account.balance << std::endl;
	std::cout << account.number << std::endl;
}
int main() {

	BankAccount bankAccount;

	createBankAccount(bankAccount);
	printBankAccount(bankAccount);


	double moneyAmount = 0;
	std::cin >> moneyAmount;

	withdraw(bankAccount, moneyAmount);//test

	printBankAccount(bankAccount);



	return 0;
}
