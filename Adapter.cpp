/*
Ref: http://www.bogotobogo.com/DesignPatterns/adapter.php
Intent:
- Convert the interface of a class into another interface clients expect. 
- Adapter (or Wrapper) lets classes work together that couldn't otherwise because of incompatible interfaces. 
- Adapter pattern's motivation is that we can reuse existing software if we can modify the interface. */

#include<bits/stdc++.h>

using namespace std;

class LegacyRectangle{
public:
	LegacyRectangle(int x1, int y1, int x2, int y2):m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2){
		cout << "Constructor Legacy Rectangle" << endl;
	}
	// Legacy Interface
	void LegacyDraw(){
		cout << "x1: " << m_x1 << " y1:" << m_y1 << " x2:" << m_x2 << " y2:" << m_y2 << endl;
		cout << "Legacy Draw function" << endl;
	}
private:
	int m_x1, m_y1, m_x2, m_y2;
};

class LatestRectangle{
public:
	// Desired Interface
	LatestRectangle(){
		cout << "Constructor Latest Rectangle" << endl;
	}
	virtual void LatestDraw(){
	}
};

class AdapterRectangle : private LegacyRectangle, public LatestRectangle
{
public:
	AdapterRectangle(int x, int y, int width, int height): LegacyRectangle(x, y, x+width, y+height){
		cout << "Constructor Adapter Rectangle " << endl;
	}
	void LatestDraw(){
		 cout << "Inside LatestDraw function of AdapterRectangle calling LegacyDraw()" << endl;
		 LegacyDraw();
	}
private:
	int x, y, height, width;
};

int main(){
	int x=10, y=15, width=40, height=60;
	LatestRectangle *r = new AdapterRectangle(x, y, width, height);
	r->LatestDraw();
	return 0;
}
