/*  Decorator Design Pattern
	Intent
	- Attach additional responsibilities to an object dynamically.
	- Decorator pattern is used when you want the capabilites of inheritance with subclasses,
	  but you need to add functionality at runtime.
	Ref: https://sourcemaking.com/design_patterns/decorator/cpp/2
*/
#include<bits/stdc++.h>
using namespace std;

// Create an interface/pure abstract class
class Widget{
public:
	virtual void draw() = 0;
};

// Create a second level base class for optional functionality
class TextBox : public Widget{
private:
	int height, width;
public:
	TextBox(int w, int h){
		height = h;
		width = w;
	}
	void draw(){
		cout << "Created Textbox [Height:" << height << " Width:" << width << "]" << endl;
	}
};

/* "Core" class and "Decorator" class declare an "isa" relationship
	Decorator class also "has a" instance of the "core class"
*/
class Decorator : public Widget{  // "is a" relationship
private:
	Widget * wid; 				  // "has a" relationship
public:
	Decorator(Widget * w): wid(w){}
	void draw(){
		wid->draw();
	}
};

// Create a Decorator derived class for each optional embellishment
class BorderDecorator : public Decorator{
public:
	BorderDecorator(Widget * w) : Decorator(w){
	}
	void draw(){
		Decorator :: draw();
		cout << "Adding Border" << endl;
	}
};

// Create a Decorator derived class for each optional embellishment
class ScrollbarDecorator : public Decorator{
public:
	ScrollbarDecorator(Widget * w) : Decorator(w){
	}
	void draw(){
		Decorator :: draw();
		cout << "Adding Scrollbar" << endl;
	}
};

// Create a Decorator derived class for each optional embellishment
class ButtonDecorator : public Decorator{
public:
	ButtonDecorator(Widget * w) : Decorator(w){
	}
	void draw(){
		Decorator :: draw();
		cout << "Adding Buttons" << endl;
	}
};

int main(){
	// Client has the responsibility to compose desired configurations
	Widget * widobj = new ButtonDecorator(new BorderDecorator(new ScrollbarDecorator(new TextBox(40, 50))));
	widobj->draw();
	return 0;
}
