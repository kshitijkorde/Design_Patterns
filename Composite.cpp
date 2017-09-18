/*
http://www.bogotobogo.com/DesignPatterns/composite.php
Intent:
- Composite lets clients treat individual objects and compositions of objects uniformly.
- Using a composite structure, we can apply the same operations over both composites and individual object. 
  In other words, in most cases we can ignore the differences between composition of objects and individual objects. 
*/
#include<bits/stdc++.h>
using namespace std;

class Graphic{
public:
	virtual void draw(){}
	virtual void add(Graphic *){}
	virtual void remove(Graphic *){}
};

class Line : public Graphic
{
public:
	void draw(){
		cout << "Draw Line" << endl;
	}

};

class Rectangle : public Graphic{
public:
	void draw(){
		cout << "Draw Rectangle " << endl;
	}
};

class Circle : public Graphic {
public:
	void draw(){
		cout << "Draw Circle " << endl;
	}
};

class Picture : public Graphic{
public:
	void draw(){
		cout << "------- Draw Picture -------" << endl;
		for(auto G: vecG){
			G->draw();
		}
	}
	void add(Graphic * obj){
		vecG.push_back(obj);
	}
private:
	vector<Graphic *> vecG;
};

int main(){

	Line L;
	L.draw();

	Circle C;
	C.draw();

	Rectangle R;
	R.draw();
	
	Picture P;
	P.add(&L);
	P.add(&C);
	P.add(&R);
	P.draw();
	return 0;
}
