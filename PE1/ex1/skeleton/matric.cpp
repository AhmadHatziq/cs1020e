// NAME: 
// NUSNET ID: 
// PLAB USERID: 

// FILE: matric.cpp

#include <iostream>
#include <string>
using namespace std;


// Converts the input digit character to integer value.
// For example, digit_char_to_int('5') returns the integer value 5.

int digit_char_to_int( char digit )
{
    return digit - '0';
}


// Converts the input NUSNET ID to the matric number without 
// the check digit.
// For example, given the input "u0901234", it returns "U091234".

string id_to_partial_matric( string id )
{
    // Write your code here.

}


// Given an input matric number without check digit, computes and 
// returns the weighted sum of the numeric digits of the matric number.

int compute_weighted_sum( string partial_matric )
{
    const int U_digit_weights[6] = {0, 1, 3, 1, 2, 7};
    const int A_digit_weights[7] = {1, 1, 1, 1, 1, 1, 1};

    // Write your code here.

}


// Given an input matric number without check digit, computes and 
// returns the check digit for the matric number.

char find_check_digit( string partial_matric )
{
    const char check_digits[13] = {'Y', 'X', 'W', 'U', 'R', 'N', 'M',
                                   'L', 'J', 'H', 'E', 'A', 'B'};

    // Write your code here.

}


// Given a valid Student NUSNET ID, computes and returns the 
// corresponding matric number.

string id_to_matric( string id )
{
    // Write your code here.

}


int main()
{
    string nusnet_id;
    cin >> nusnet_id;
    cout << id_to_matric( nusnet_id ) << endl;
    return 0;
}
