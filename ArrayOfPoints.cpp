//=====================================================================       
// FILE: ArrayOfPoints.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <Hat>
// MATRIC NO.  : <XXX>
// NUS EMAIL   : <XXX@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include <iostream>

using namespace std;


struct Point {
    int x;
    int y;
};


int main() 
{	
	
	int N = 0, i = 0, a, b;
	cin >> N;
	Point *p ;
	p = new Point[N+1];
	for (i = 0; i < N; i ++){
		
    	cin >> a ;
		cin >> b ;
		p[i].x = a;
		p[i].y = b;
	}
	for ( i = N-1 ; i >= 0; i -- ){		
		cout << "Point " << i <<": (" << p[i].x << ", " << p[i].y << ")" << endl ;		
	}
	
	delete p; p = NULL;


    return 0;
}
