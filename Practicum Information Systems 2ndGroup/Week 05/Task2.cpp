#include<iostream>
#include<fstream>


#pragma warning(disable : 4996)
constexpr int HOLDER_NAME_SIZE = 49;
constexpr int IBAN_SIZE = 34;
constexpr int BANK_NAME_SIZE = 19;
constexpr int MAX_ACCOUNTS_SIZE = 1000;

struct BankAccount {


private:

	char holderName[HOLDER_NAME_SIZE + 1];
	char IBAN[IBAN_SIZE + 1];
	bool isLocked ;
	float balance ;
	float savingsBalance ;

public:

	const char* getIBAN() const {
		return this->IBAN;
	}

	const char* getHolderName() const {
		return this->holderName;
	}

	float getBalance() const {
		return this->balance;
	}

	float getSavingsBalance() const {
		return this->savingsBalance;
	}

	bool getIsLocked() const {
		return this->isLocked;
	}


	void setHolderName(const char* holderName) {
		if (strlen(holderName) <= HOLDER_NAME_SIZE)
			strcpy(this->holderName, holderName);
	}

	void setIBAN(const char* IBAN) {
		if (strlen(IBAN) <= IBAN_SIZE)
			strcpy(this->IBAN, IBAN);
	}

	void setBalance(const float balance) {
		if (balance >= 0)
			this->balance = balance;
	}

	void setSavingsBalance(const float savingsBalance) {
		if (savingsBalance >= 0)
			this->savingsBalance = savingsBalance;
	}

	void addMoney(const float money) {
		if (money >= 0)
			this->balance += money;
		else
			std::cout << "You can not add negative number." << std::endl;
	}

	void withdrawMoney(const float money) {
		if (this->balance - money < 0)
			std::cout << "There is not enough money in your bank account." << std::endl;
		else
			this->balance -= money;
	}

	void addMoneyToSavings(const float money) {
		if (this->balance - money < 0)
			std::cout << "You do not have enough money in ypur bank account" << std::endl;
		else {
			this->balance -= money;//take money from your balance
			this->savingsBalance += money;//and add them to your savings
		}
	}

	void withdraFromSavings(const float money) {

		if (this->savingsBalance - money < 0)
			std::cout << "You do not have enough money in your savings account. " << std::endl;
		else {
			this->savingsBalance -= money;
			this->balance += money;
		}
	}

	void unlockAccount() {
		this->isLocked = false;
	}

	void lockAccount() {
		this->isLocked = true;
	}

	void deleteAccount() {//destruct

		this->balance = 0;
		this->savingsBalance = 0;
		holderName[0] = '\0';
		for (size_t i = 0; i < 36; i++){
			IBAN[i] = 0;
		}

	}
};


class Bank {

	char bankName[BANK_NAME_SIZE];
	BankAccount bankAccounts[MAX_ACCOUNTS_SIZE];
	size_t numAccounts = 0;

public:


	Bank() {
		strcpy(this->bankName, "Undefined");
		this->numAccounts = 0;
	}

	Bank(const char* bankName) {
		strcpy(this->bankName, bankName);
		this->numAccounts = 0;
	}

	void addBankAccount(const BankAccount& bankAcc) {
		if (this->numAccounts + 1 > MAX_ACCOUNTS_SIZE)
			std::cout << "No space for adding bank account." << std::endl;
		else
			this->bankAccounts[this->numAccounts++] = bankAcc;
	}
	void removeBankAcc(const char* IBAN) {

		for (size_t i = 0; i < this->numAccounts; i++)
		{
			if (strcmp(this->bankAccounts[i].getIBAN(), IBAN) == 0)
			{
				for (size_t j = i; j < this->numAccounts - 1; j++)
				{
					this->bankAccounts[j] = this->bankAccounts[j + 1];
				}
				this->numAccounts--;
				break;
			}
		}
	}

	float sumAllBalances() const {

		float sum = 0;
		for (size_t i = 0; i < this->numAccounts; i++)
		{
			sum += this->bankAccounts[i].getBalance();
			sum += this->bankAccounts[i].getSavingsBalance();

		}
		return sum;
	}

	void sendMoney(const char* fromIBAN, const char* toIBAN,const float money) {

		for (size_t i = 0; i < this->numAccounts; i++)
		{
			if (strcmp(this->bankAccounts[i].getIBAN(), toIBAN) == 0){
	     	   this->bankAccounts[i].addMoney(money);
				break;
			}
			else if (strcmp(this->bankAccounts[i].getIBAN(), fromIBAN) == 0) {
				this->bankAccounts[i].withdrawMoney(money);
				break;
			}

		}
	}

	void unlockAccount(const char* IBAN) {
		for (size_t i = 0; i < this->numAccounts; i++)
		{
			if (strcmp(this->bankAccounts[i].getIBAN(), IBAN) == 0)	{
				this->bankAccounts[i].unlockAccount();
				break;
			}
		}
	}
	void lockAccount(const char* IBAN) {
		for (size_t i = 0; i < this->numAccounts; i++)
		{
			if (strcmp(this->bankAccounts[i].getIBAN(), IBAN) == 0) {
				this->bankAccounts[i].lockAccount();
				break;
			}
		}
	}
};


int main() {

	
		Bank bank("BestBank");

		BankAccount account1;
		account1.setHolderName("Yoana MAteva");
		account1.setIBAN("BG12345678901234567890");
		account1.setBalance(5000);
		account1.setSavingsBalance(3600);
		account1.unlockAccount();

		BankAccount account2;
		account2.setHolderName("Monika Angelova");
		account2.setIBAN("BG09876543210987654321");
		account2.setBalance(12700);
		account2.setSavingsBalance(400);
		account2.unlockAccount();

		bank.addBankAccount(account1);
		bank.addBankAccount(account2);

		std::cout << "Total balance in the bank: " << bank.sumAllBalances() << std::endl;

		bank.sendMoney("GB12345678901234567890", "GB09876543210987654321", 200.0);

		std::cout << "Total balance in the bank after transfer: " << bank.sumAllBalances() << std::endl;


	return 0;
}