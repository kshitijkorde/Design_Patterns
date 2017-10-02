/* 
http://www.bogotobogo.com/DesignPatterns/observer.php
Intent:
- Observer Pattern's intent is to define a one-to-many dependency between subject and observers
  so that when one subject changes state, all its dependents(observers) are notified and updated automatically.
  Flow
  1) Observers registers themselves with the Subject.
  2) The Subject broadcasts events to all registered Observers
*/

#include<bits/stdc++.h>
#include<ctime>
using namespace std;

class Subject;

class Observer{
public:
	Observer(){}
	~Observer(){}
	virtual void Update(Subject *theChangedSubject) = 0;
};

class Subject{
public:
	Subject(){}
	~Subject(){}
	virtual void Attach(Observer *);
	virtual void Detach(Observer *);
	void Notify();
private:
	vector<Observer *> _observers;
};

void Subject :: Attach(Observer * ob){
	_observers.push_back(ob);
	cout << "Observer Attached..." << endl;
}

void Subject :: Detach(Observer * ob){
	vector<Observer *> :: const_iterator itr;
	for(itr = _observers.begin(); itr != _observers.end(); ++itr){
		if(*itr == ob){
			_observers.erase(itr);
			cout << "Observer Detached..." << endl;
			break;
		}
	}
}

void Subject :: Notify(){
	cout << "Will notify the observers..." << endl;
	vector<Observer *> :: iterator itr;
	for(itr = _observers.begin(); itr != _observers.end(); ++itr){
		(*itr)->Update(this);
	}
}

class NumberChanger: public Subject
{
public:
	NumberChanger(){}
	int getCurrent();
	void GenerateNew();
private:
	int current_num;
};

void NumberChanger :: GenerateNew(){
	cout << "Subject Changed...." << endl;
	srand(time(NULL));
	current_num = rand()%10 + 88;
	Notify();
}

int NumberChanger :: getCurrent(){
	return current_num;
}

class NumberTracker : public Observer{
public:
	// Register with the subject
	NumberTracker(NumberChanger * s){
		cout << "Will register with the subject ..." << endl;
		_subject = s;
		_subject->Attach(this);
	}
	// Get Un-Register from the subject
	~NumberTracker(){
		cout << "Will un-register from the subject ..." << endl;
		_subject->Detach(this);
	}
	void Update(Subject *);
	void printNumber();
private: 
	NumberChanger * _subject;
};

void NumberTracker :: Update(Subject * changedSubject){
	if(_subject == changedSubject){
		printNumber();
	}
}

void NumberTracker :: printNumber(){
	cout << _subject->getCurrent() << endl;
}

int main(){

	NumberChanger objNumChange;

	NumberTracker objNumTracker(&objNumChange);
	objNumChange.GenerateNew();
	return 0;
}
