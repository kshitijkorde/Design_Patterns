/*  Chain of Responsibility (Behavioral Design Pattern)
	Intent
	- This pattern has a group of objects that are expected in between
	  them to solve the problem. If the first object can't solve the problem
	  it simply passes the data to the next object in the chain.
	Ref: http://www.newthinktank.com/2012/10/chain-of-responsibility-design-pattern-tutorial/
*/
#include<bits/stdc++.h>
using namespace std;

class Numbers{
private:
	int num1, num2;
	string operation;
public:
	Numbers(int n1, int n2, string op):num1(n1),num2(n2),operation(op){
		cout << "Operands [" << num1 << ", " << num2 << "] " << "Operation Requested: " << operation << endl; 
	}
	int getnum1(){
		return num1;
	}
	int getnum2(){
		return num2;
	}
	string getoperation(){
		return operation;
	}
};

class Chain{
public:
	virtual void setNextChain(Chain *) = 0;
	virtual void calculate(Numbers *) = 0;
};


class AddNumbers : public Chain{
private:
	Chain * nextInChain;
public:
	void calculate(Numbers * req){
		cout << "Inside Add..." << endl;
		if(req->getoperation() == "add"){
			cout << req->getnum1() << "+" << req->getnum2() << " = " << (req->getnum1() + req->getnum2()) << endl;
		} else {
			cout << "Forwarding ..." << endl;
			nextInChain->calculate(req);
		}
	}
	void setNextChain(Chain * next){
		nextInChain = next;
	}
};

class SubtractNumbers : public Chain{
private:
	Chain * nextInChain;
public:
	void calculate(Numbers * req){
		cout << "Inside Subtract..." << endl;
		if(req->getoperation() == "sub"){
			cout << req->getnum1() << "-" << req->getnum2() << " = " << (req->getnum1() - req->getnum2()) << endl;
		} else {
			cout << "Forwarding ..." << endl;
			nextInChain->calculate(req);
		}
	}
	void setNextChain(Chain * next){
		nextInChain = next;
	}
};

class MultiplyNumbers : public Chain{
private:
	Chain * nextInChain;
public:
	void calculate(Numbers * req){
		cout << "Inside Multiply..." << endl;
		if(req->getoperation() == "mul"){
			cout << req->getnum1() << "*" << req->getnum2() << " = " << (req->getnum1() * req->getnum2()) << endl;
		} else {
			cout << "Forwarding ..." << endl;
			nextInChain->calculate(req);
		}
	}
	void setNextChain(Chain * next){
		nextInChain = next;
	}
};

class DivideNumbers : public Chain{
private:
	Chain * nextInChain;
public:
	void calculate(Numbers * req){
		cout << "Inside Divide..." << endl;
		if(req->getoperation() == "div"){
			cout << req->getnum1() << "/" << req->getnum2() << " = " << (req->getnum1() / req->getnum2()) << endl;
		} else {
			cout << "Forwarding ..." << endl;
			nextInChain->calculate(req);
		}
	}
	void setNextChain(Chain * next){
		nextInChain = next;
	}
};

int main(){

	// Define all of the objects in the chain
	Chain *c1 = new AddNumbers;
	Chain *c2 = new SubtractNumbers;
	Chain *c3 = new MultiplyNumbers;
	Chain *c4 = new DivideNumbers;

	// Tell each object where to forward the data if it can't process the request
	c1->setNextChain(c2);
	c2->setNextChain(c3);
	c3->setNextChain(c4);
	c4->setNextChain(c1);

	Numbers *req = new Numbers(4,7,"add");
	c2->calculate(req);

	return 0;
}
