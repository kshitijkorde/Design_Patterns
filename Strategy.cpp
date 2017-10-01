/* Ref: http://www.bogotobogo.com/DesignPatterns/strategy.php
Intent
- The strategy pattern (also known as the policy pattern) is a behavioural software design 
  pattern that enables selecting an algorithm at runtime.
- Defines a family of algorithms.
- Encapsulates each algorithm, and makes the algorithms interchangeable within that family.

For example, a class that performs validation on incoming data may use the Strategy pattern 
to select a validation algorithm depending on the type of data, the source of the data, user choice, 
or other discriminating factors. These factors are not known until run-time and may require 
radically different validation to be performed. The validation algorithms (strategies), encapsulated 
separately from the validating object, may be used by other validating objects in different areas of the 
system (or even different systems) without code duplication.
*/

#include<bits/stdc++.h>
using namespace std;

class SortPolicy{
public:
	virtual void sort() const = 0;
};

class MergeSort: public SortPolicy
{
public:
	virtual void sort() const {
		cout << "MergeSort" << endl;
	}
};

class QuickSort : public SortPolicy
{
public:
	virtual void sort() const {
		cout << "QuickSort" << endl;
	}
};

class HeapSort : public SortPolicy
{
public:
	virtual void sort() const {
		cout << "HeapSort" << endl;
	}
};

class SearchPolicy{
public:
	virtual void search() const = 0;
};

class BinarySearch : public SearchPolicy{
public:
	virtual void search() const{
		cout << "Binary Search" << endl;
	}
};

class SequentialSearch : public SearchPolicy{
public:
	virtual void search() const{
		cout << "Sequential Search" << endl;
	}
};

// Context
class Collection{
private:
	SearchPolicy * m_Search;
	SortPolicy * m_Sort;
public:	
	void setSortPolicy(SortPolicy * objsort){
		m_Sort = objsort;
	}
	void setSearchPolicy(SearchPolicy * objsearch){
		m_Search = objsearch;
	}
	void sort(){
		m_Sort->sort();
	}
	void search(){
		m_Search->search();
	}
};

int main(){

	MergeSort objMerge;
	QuickSort objQuick;
	HeapSort objHeap;

	BinarySearch objBinary;
	SequentialSearch objSearch;

	Collection sortCollection;
	sortCollection.setSortPolicy(&objQuick);
	sortCollection.sort();

	Collection searchCollection;
	searchCollection.setSearchPolicy(&objBinary);
	searchCollection.search();

	return 0;
}
