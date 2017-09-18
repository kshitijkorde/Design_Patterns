/* Creational Design Pattern: Builder
Intent
- The construction process for the end product is made so generic, that multiple products can be produced using the same process.
- When the construction of the end product can be broken down into multiple steps.
- When the construction process of the product can be made independent of the parts to be used.
*/

#include<bits/stdc++.h>

using namespace std;

// End product
class Meal
{
public:
	Meal(){}
	~Meal(){}
	void addItem(string item){
		QMealItems.push(item);
	}
	void serveItems(){
		while(!QMealItems.empty()){
			cout << QMealItems.front() << " ";
			QMealItems.pop();
		}
		cout << endl;
	}
private:
	queue<string> QMealItems;
};

// Builder, abstract interface to build parts of the product
class MealBuilder
{
protected:
	Meal mMeal;
public:
	Meal getMeal(){
		return mMeal;
	}
	virtual void buildStarter() = 0;
	virtual void buildMainCourse() = 0;
	virtual void buildDesert() = 0;
};

// Concrete classes to build the parts of the product
class IndianMealBuilder : public MealBuilder
{
public:
	void buildStarter(){
		mMeal.addItem("Kachori");
	}
	void buildMainCourse(){
		mMeal.addItem("Sattu Paratha");
	}
	void buildDesert(){
		mMeal.addItem("Kheer");
	}
};

// Concrete classes to build the parts of the product
class ChineseMealBuilder : public MealBuilder
{
public:
	void buildStarter(){
		mMeal.addItem("Manchurian");
	}
	void buildMainCourse(){
		mMeal.addItem("Hakka Noodles");
	}
	void buildDesert(){
		mMeal.addItem("Hakka IceCream");
	}
};

// Director, constructs the product using the builder interface
class MultiCuisineCook
{
private:
	MealBuilder * ptrMealBuilder;
public:
	MultiCuisineCook():ptrMealBuilder(NULL){}

	void createMeal(){
		ptrMealBuilder->buildStarter();
		ptrMealBuilder->buildMainCourse();
		ptrMealBuilder->buildDesert();
	}

	void setMealBuilder(MealBuilder * builder){
		if(ptrMealBuilder){
			delete ptrMealBuilder;
		}
		ptrMealBuilder = builder;
	}

	void serveMeal(){
		(ptrMealBuilder->getMeal()).serveItems();
	}
};

int main(){
	MultiCuisineCook MCook;
	MCook.setMealBuilder(new ChineseMealBuilder);
	MCook.createMeal();
	MCook.serveMeal();
	MCook.setMealBuilder(new IndianMealBuilder);
	MCook.createMeal();
	MCook.serveMeal();
	return 0;
}
