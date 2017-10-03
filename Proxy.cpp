/*	Proxy Design Pattern
	Idea
	- Both the Proxy and the RealSubject implement the Subject interface. 
	  This allows any client to treat the Proxy just like the RealSubject.
	- The RealSubject is usually the object that does most of the real work; 
	  the Proxy controls access to it.
	- The Proxy often instantiates or handle the creation of the RealSubject.
	- Proxy is used if the Subject is expensive to create in some way or if 
	  access to the subject needs to be protected in some way.

	Use Cases
	- Implement lazy instantiation of the RealSubject object
	- Implement access control to the RealSubject object
	- Share resources, we could have multiple Proxy objects share the same underlying i
	  RealSubject class. This could be used to implement reference counting, for instance.

	Ref: http://www.bogotobogo.com/DesignPatterns/proxy.php
*/

#include<bits/stdc++.h>

using namespace std;

class Subject{
public:
	virtual void request() = 0;
	virtual ~Subject(){}
};

class RealSubject : public Subject{
public:
	void request(){
		cout << "Real Subject's request " << endl;
	}
};

class Proxy : public Subject{
private:
	Subject * realSub;
public:
	Proxy():realSub(new RealSubject){
	} 
	~Proxy(){
		delete realSub;
	}
	void request(){
		cout << "Proxy Request function" << endl;
		realSub->request();
	}
};	

int main(){
	Proxy P;
	P.request();
	return 0;
}
