#include <iostream>
#include "trial.h"

using std::cout;    using std::cin;


int main() {
	int num{}, ch{};

	while (ch != 8) {
		std::cout << "\n\n\n\n\tPlease chose what you would like to do";
		std::cout << "\n\t1. Create a new account";//done
		std::cout << "\n\t2. Show all info regarding a cpecific account";//done
		std::cout << "\n\t3. Show all recorded accounts";//done
		std::cout << "\n\t4. Withdraw monay from an account";//done
		std::cout << "\n\t5. Deposit money into a specific account";//done
		std::cout << "\n\t6. Modify a recorded account ";//done
		std::cout << "\n\t7. Delete an account from the database";
		std::cout << "\n\t8. Close";
		std::cout << "\n\tPlease chose 1-8: ";
		std::cin >> ch;
		std::cout << "\n\n\n";
		switch (ch) {
		case 1:
			createLogOfAccount();
			std::cout << "Account was created..";
			break;
		case 2:
			displaySpecificFromLogs();
			std::cout << "Account was displayed";
			break;
		case 3:
			displayAllAccount();
			break;
		case 4:
			withdrawMon();
			std::cout << "Withdrawal complete..";
			break;
		case 5:
			depositMon();
			std::cout << "Deposit complete..";
			break;
		case 6:
			changeInfo();
			break;
		case 7:
			deleteAccountLog();
			std::cout << "Account was deleted..";
			break;
		case 8:
			std::cout << "Closing..";
			break;
		default:
			std::cout << "Incorrect input";
		}
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
