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
    if ( id[0] == 'u' ) {
        id[0] = 'U';
        id.erase(3, 1);
        return id;
    } else {
        id[0] = 'A';
        return id;
    }
}


// Given an input matric number without check digit, computes and 
// returns the weighted sum of the numeric digits of the matric number.

int compute_weighted_sum( string partial_matric )
{
    const int U_digit_weights[6] = {0, 1, 3, 1, 2, 7};
    const int A_digit_weights[7] = {1, 1, 1, 1, 1, 1, 1};

    int sum = 0;

    if ( partial_matric[0] == 'U' ) {
        for ( int i = 0; i < 6; i++ ) {
            sum += digit_char_to_int( partial_matric[i + 1] ) * U_digit_weights[i];
        }
    } else {
        for ( int i = 0; i < 7; i++ ) {
            sum += digit_char_to_int( partial_matric[i + 1] ) * A_digit_weights[i];
        }
    }
    return sum;
}


// Given an input matric number without check digit, computes and 
// returns the check digit for the matric number.

char find_check_digit( string partial_matric )
{
    const char check_digits[13] = {'Y', 'X', 'W', 'U', 'R', 'N', 'M',
                                   'L', 'J', 'H', 'E', 'A', 'B'};

    int wt_sum = compute_weighted_sum( partial_matric );
    return check_digits[ wt_sum % 13 ];
}


// Given a valid Student NUSNET ID, computes and returns the 
// corresponding matric number.

string id_to_matric( string id )
{
    string partial_matric = id_to_partial_matric( id );
    string matric = partial_matric + find_check_digit( partial_matric );
    return matric;
}


int main()
{
    string nusnet_id;
    cin >> nusnet_id;
    cout << id_to_matric( nusnet_id ) << endl;
    return 0;
}
