/*  Facade Design Pattern (Structual Design Pattern)
	Intent
	- When we need to create a simplified interface that performs many other tasks
	- Provide a unified interface to a set of interfaces in a subsystem
	- Wrap a complicated subsystem with a simpler interface.
	  i.e encapsulating a complex subsystem within a single interface object.
*/

#include<bits/stdc++.h>
using namespace std;

class WelcomeToBank{
public:
	WelcomeToBank(){
		cout << "Welcome to bank" << endl;
		cout << "We strive to server..." << endl;
	}
};

class AccountNumberCheck{
private:
	int privateAccountNumber;
public:
	AccountNumberCheck(){
		privateAccountNumber = 1234;
	}
	int getAccountNumber(){
		return privateAccountNumber;
	}
	bool CheckAccountActive(int accnum){
		if(accnum == privateAccountNumber){
			return true;
		} else {
			return false;
		}
	}
};

class SecurityCodeCheck{
private:
	int SecurityCode;
public:
	SecurityCodeCheck(){
		SecurityCode = 9876;
	}
	bool CheckSecurityCode(int secCode){
		if(secCode == SecurityCode){
			return true;
		}
		return false;
	}
};

class FundsCheck{
private:
	int fundsinAccount;
public:
	FundsCheck(){
		fundsinAccount = 10000;
	}

	void depositCash(int cash){
		fundsinAccount += cash;
		cout << "Available Funds : " << fundsinAccount << endl;
	}

	void withdrawCash(int cash){
		if(haveEnoughCash(cash)){
			fundsinAccount -= cash;
			cout << "Available Funds : " << fundsinAccount << endl;
		} else {
			cout << "Not enough founds in the account" << endl;
		}
	}

	bool haveEnoughCash(int amounttoWithdraw){
		if(amounttoWithdraw > fundsinAccount){
			return false;
		}
		return true;
	}
};

class BankAccountFacade{
private:
	int accNum;
	int secCode;

	FundsCheck m_fundsCheck;
	SecurityCodeCheck m_secCodeCheck;
	AccountNumberCheck m_accnumCheck;
	WelcomeToBank m_welcomeBank;

public:
	BankAccountFacade(int _accNum, int _secCode):accNum(_accNum),secCode(_secCode){
	}
	int getAccountNumber(){
		return accNum;
	}
	int getSecurityCode(){
		return secCode;
	}	

	void withdrawCash(int cash){
		if(m_accnumCheck.CheckAccountActive(getAccountNumber()) and 
		   m_secCodeCheck.CheckSecurityCode(getSecurityCode())) {
		    m_fundsCheck.withdrawCash(cash);
			cout << "Withdrawal transaction complete.." << endl;
		} else {
			cout << "Withdrawal transaction failed.." << endl;
		}
	}
	void depositCash(int cash){
		if(m_accnumCheck.CheckAccountActive(getAccountNumber()) and 
		   m_secCodeCheck.CheckSecurityCode(getSecurityCode())){
			m_fundsCheck.depositCash(cash); 
			cout << "Deposit transaction complete.." << endl;
		} else {
			cout << "Deposit transaction failed.." << endl;
		}
	}
};

int main(){
	BankAccountFacade * ptrBankAccFac = new BankAccountFacade(1234, 9876); 
	ptrBankAccFac->depositCash(100);
	ptrBankAccFac->withdrawCash(500);
	return 0;
}
