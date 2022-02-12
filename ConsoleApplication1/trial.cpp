#include <string>
#include <iostream>
#include <fstream>
#include "trial.h"

//class definitions

//Methods
//getters
double Account::getBalance() {
	return balance;
}

int Account::getAccNo() {
	return accountNo;
}

void Account::displayAllAccInfo() {
	std::cout << "The account holder's name is: " << accHolderName << "\nThe account number is: " << accountNo << "\nThe current balance is: " << balance << "\n";
}

//setters
void Account::setNewBalance() {
	std::cout << "What should the balance be?: ";
	std::cin >> balance;
	std::cout << "The balance is " << balance << "\n";
}

void Account::setNewAccNo() {
	std::cout << "What should the account number be?: ";
	std::cin >> accountNo;
	std::cout << "The account number is " << accountNo << "\n";
}

void Account::setNewAccHolderName() {
	std::cout << "What should the account holder's name be?: ";
	std::cin >> accHolderName;
	std::cout << "The new account holder name is " << accHolderName << "\n";
}

void Account::deposit(double amount) {
	balance += amount;
}

void Account::withdraw(double amount) {
	balance -= amount;
}

void Account::oneLineShowInfo() {
	std::cout << accountNo << "\t\t\t" << accHolderName << "\t\t\t\t" << balance << "\n";
}

//function definitions-------------------

void createLogOfAccount() {
	Account ac1;
	std::ofstream toSave;
	toSave.open("Accounts.txt", std::ios::app);
	ac1.setNewAccNo();
	ac1.setNewAccHolderName();
	ac1.setNewBalance();
	toSave.write((char*)&ac1, sizeof(Account));
	toSave.close();
}


void displaySpecificFromLogs() {
	int tempAcc;
	std::cout << "Which account would you like to dislay";
	std::cin >> tempAcc;
	Account ac1;
	bool found = false;
	std::ifstream toRead;
	toRead.open("Accounts.txt", std::ios::binary);
	if (!toRead) {
		std::cout << "Couldn't open file";
		return;
	}
	while (toRead.read((char*)&ac1, sizeof(Account))) {	//(char*)&ac1 points to the start of the object
		if (ac1.getAccNo() == tempAcc) {				//where as sizeof(Account) calculates the number of bytes to read/write to/from file
			ac1.displayAllAccInfo();
			found = true;
		}
	}
	toRead.close();
	if (found == false)
		std::cout << "\nAccount was not found";
}

void depositMon() {
	double amount{}, tempAccNo{};
	bool found = false;
	Account ac1;
	std::cout << "What account would you like to deposit money for?: ";
	std::cin >> tempAccNo;
	std::cout << "And how much?: ";
	std::cin >> amount;
	std::fstream File;
	File.open("Accounts.txt", std::ios::binary | std::ios::in | std::ios::out);
	if (!File) {
		std::cout << "File couldn't open..";
		return;
	}
	while (!File.eof() && found == false) {
		File.read((char*)&ac1, sizeof(ac1));
		if (ac1.getAccNo() == tempAccNo) {
			ac1.deposit(amount);
			int pos = (-1) * static_cast<int>(sizeof(ac1));
			File.seekp(pos, std::ios::cur);
			File.write((char*)&ac1, sizeof(Account));
			found = true;
		}
	}
	File.close();
	if (found == false)
		std::cout << "File was not found...";

}

void withdrawMon() {
	double amount{}, tempAccNo{};
	bool found = false;
	Account ac1;
	std::cout << "What account would you like to withdraw money from?: ";
	std::cin >> tempAccNo;
	std::cout << "And how much?: ";
	std::cin >> amount;
	std::fstream File;
	File.open("Accounts.txt", std::ios::binary | std::ios::in | std::ios::out);
	if (!File) {
		std::cout << "File couldn't open..";
		return;
	}
	while (!File.eof() && found == false) {
		File.read((char*)&ac1, sizeof(Account));
		if (ac1.getAccNo() == tempAccNo) {
			if (amount > 0 && ac1.getBalance() > 0) {
				ac1.withdraw(amount);
				int pos = (-1) * static_cast<int>(sizeof(ac1));
				File.seekp(pos, std::ios::cur);
				File.write((char*)&ac1, sizeof(Account));
				found = true;
			}
		}
	}
	File.close();
	if (found == false)
		std::cout << "File was not found...";
}

void changeInfo() {
	int tempAcc{};
	bool found = false;
	Account ac1;
	std::fstream fileToMod;
	fileToMod.open("Accounts.txt", std::ios::binary | std::ios::out | std::ios::in);
	std::cout << "What account would you like to edit?: ";
	std::cin >> tempAcc;
	if (!fileToMod) {//checks if file can be opened
		std::cout << "Couldn't open file...";
		return;
	}
	while (!fileToMod.eof() && found == false) {
		fileToMod.read((char*)&ac1, sizeof(Account));
		if (ac1.getAccNo() == tempAcc) {//checks to see if current account number matches the one being looked for 
			ac1.displayAllAccInfo();
			int choice{};
			std::cout << "\n\nWhich piece of information would you like to edit?\n";
			std::cout << "1. Account number\n";
			std::cout << "2. Account holder's name\n";
			std::cout << "3. Account balance\n";
			std::cout << "4. Cancel\n";
			std::cout << "Choose 1-4: ";
			std::cin >> choice;
			switch (choice) {
			case 1:
				ac1.setNewAccNo();
				break;
			case 2:
				ac1.setNewAccHolderName();
				break;
			case 3:
				ac1.setNewBalance();
				break;
			case 4:
				std::cout << "Cancelling..";
				return;
			}
			int pos = (-1) * static_cast<int>(sizeof(Account));
			fileToMod.seekp(pos, std::ios::cur);
			fileToMod.write((char*)&ac1, sizeof(Account));
			found = true;
		}
	}
	fileToMod.close();//closes file
	if (found == false)
		std::cout << "Couldn't find account";
}

void displayAllAccount() {
	std::ifstream toRead;
	Account ac1;
	toRead.open("Accounts.txt", std::ios::in);
	if (!toRead) {
		std::cout << "Couldn't open file..";
		return;
	}
	std::cout << "List of accounts";
	std::cout << "-----------------------------------------\n";
	std::cout << "Account number\t\t" << "Account Holder's name\t\t" << "Account's balance\n";
	std::cout << "-----------------------------------------\n";
	while (toRead.read((char*)&ac1, sizeof(Account)))
		ac1.oneLineShowInfo();
	toRead.close();
}

void deleteAccountLog() {
	std::cout << "Which account would you like to delete? Type account number: ";
	int del;
	std::cin >> del;
	Account ac1;
	std::ifstream toRead;
	std::ofstream toWrite;
	toRead.open("Accounts.txt", std::ios::binary);
	if (!toRead) {
		std::cout << "Couldn't open file....";
		return;
	}
	toWrite.open("Temp.txt", std::ios::binary);
	toRead.seekg(0, std::ios::beg);
	while (toRead.read((char*)&ac1, sizeof(Account))) {
		if (ac1.getAccNo() != del) {
			toWrite.write((char*)&ac1, sizeof(Account));
		}
	}
	toRead.close();
	toWrite.close();
	remove("Accounts.txt");
	rename("Temp.txt", "Accounts.txt");
}