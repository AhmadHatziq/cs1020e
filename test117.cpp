#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main (){
	
	vector<int> myVector;
	myVector.push_back(27);	
	myVector.push_back(35);	
	myVector.push_back(2);	
	myVector.push_back(99);	
	myVector.push_back(101);
	myVector.push_back(35);
	
	vector<int>::iterator iter = myVector.begin();
	
	while (iter != myVector.end()){
		cout << *iter << " " ; iter++;
	}
	cout << endl;
	
	sort (myVector.begin(), myVector.end(), less_equal<int>());
	
	iter = myVector.begin();
	
	while (iter != myVector.end()){
		cout << *iter << " " ; iter++;
	}
	cout << endl;	
	
	return 0;
}
