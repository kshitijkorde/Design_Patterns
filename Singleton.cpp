#include<bits/stdc++.h>

using namespace std;

class Singleton{
private:
	Singleton(){

	}
	static Singleton * instance;
	static bool instance_flag;
public:
	static Singleton * getInstance();
	~Singleton(){
		instance_flag = false;
	}
};

Singleton * Singleton :: instance = NULL;
bool Singleton :: instance_flag = false;

Singleton * Singleton :: getInstance(){
	if(instance_flag == false){
		cout << "Creating new instance" << endl;
		instance = new Singleton;
		instance_flag = true;
	}
	return instance;
}

int main(){
	Singleton * single = Singleton :: getInstance();
	Singleton * second = Singleton :: getInstance();
	Singleton * x(single);
	Singleton * y;
	y = x;
	x->getInstance();
	y->getInstance();
	return 0;
}
