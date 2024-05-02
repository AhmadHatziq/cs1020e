#include <iostream>

using namespace std;

enum Color{
	Red, Yellow, Green
};
int main(){
	Color c1,c2,c3;
	
	c1 = Yellow;
	c2 = c1;
	c3 = c1;
	
	switch( c1 ){
		case Red :{
			cout << "Red" << endl;
			break;
		}
		case Yellow: {
			cout << "Yellow" << endl;
			break;
		}
		case Green:{
			cout << "Green" << endl;
			break;
		}

		
	}

	int a;		
	a = c1;
	cout << "a is " << c1;
	

	
	return 0;
}
