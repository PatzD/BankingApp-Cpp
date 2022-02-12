#pragma once
#ifndef TRIAL_H
#define TRIAL_H

class Account {
private:
	//attributes
	int accountNo;
	double balance;
	char accHolderName[30];
public:
	//methods
	//getters 
	double getBalance();
	int getAccNo();
	//method to display all info for current account
	void displayAllAccInfo();
	//setters
	void setNewBalance();
	void setNewAccNo();
	void setNewAccHolderName();

	void deposit(double);
	void withdraw(double);

	void oneLineShowInfo();
};

//function declaration---------------
void changeInfo(); //modify chosen data for specific account and save it
void createLogOfAccount(); //creates new account and saves it to database
void displaySpecificFromLogs(); //displays all available info for chosen account
void depositMon(); //deposit money into chosen account
void withdrawMon(); //withdraw monay from chosen account if user has available balance
void displayAllAccount();//simply displays all saved accounts neatly
void deleteAccountLog();//deletes the cpecified accoutn from logs

#endif