/*
http://www.bogotobogo.com/DesignPatterns/factorymethod.php
Intent:
- In Factory Method, client knows about abstract base class but not about the concrete subclass. 
- Client wants to create an object from abstract class. But the subclass decides which class to instantiate. 
  This allows us to defer the creation to the subclass. 
- Client doesn't know which subclass or concrete class is used to create the object. The creation is deferred to run-time.
Jist:
    Client knows about abstract base class but not concrete subclass.
    Run-time creation of objects.
    Subclasses create objects.
*/

#include<bits/stdc++.h>

using namespace std;

class Button{
public:
	virtual void label() = 0;
};

class WindowsButton : public Button
{
public:
	void label(){
		cout << "Labelled Windows" << endl;
	}
};

class CapsLockButton : public Button
{
public:
	void label(){
		cout << "Labelled CapsLock" << endl;
	}
};

class Factory {
public:
	virtual Button * createButton(string) = 0;
};

class ButtonFactory : public Factory
{
public:
	Button * createButton(string buttonType){
		if(buttonType == "Windows")
			return new WindowsButton;
		if(buttonType == "CapsLock")
			return new CapsLockButton;
	}
};

int main(){

	Factory * ptrFac;
	Button * btn;

	ptrFac = new ButtonFactory();

	btn = ptrFac->createButton("Windows");
	btn->label();

	btn = ptrFac->createButton("CapsLock");
	btn->label();	

	return 0;
}
