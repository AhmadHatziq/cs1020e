//=====================================================================       
// FILE: HelloByeBye.cpp
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
#include <string>

using namespace std;


int main() 
{
    string name; 

    cout << "What is your name? ";
    getline(cin, name);

    //=======================
    // WRITE YOUR CODE BELOW.
    //=======================
    int times = 0, i = 0;
	cout << "Hello how many times? " ;
	cin >> times ;
	
	for ( i = 1; i <= times; i ++){
		cout << i << ": Hello, " << name << "." << endl;
	}





    //=======================

    cout << "Bye-bye!" << endl;

    return 0;
}
