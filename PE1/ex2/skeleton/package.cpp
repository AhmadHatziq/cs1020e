// NAME: 
// NUSNET ID: 
// PLAB USERID: 

// FILE: package.cpp

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>    // for the ceil() function.
using namespace std;


// CuboidObject class
class CuboidObject
{
protected:
    double _length, _width, _height, _mass;
public:
    CuboidObject() {}
    CuboidObject( double length, double width, double height, double mass )
      : _length(length), _width(width), _height(height), _mass(mass) {}

    double getLength() { return _length; }
    double getWidth()  { return _width; }
    double getHeight() { return _height; }
    double getVolume() { return _length * _width * _height; }
    double getMass()   { return _mass; }
};


// Book class
class Book : public CuboidObject
{
private:
    string _title;
public:
    Book( string title, double length, double width, 
          double height, double mass )
      : CuboidObject( length, width, height, mass ), _title(title) {}

    string getTitle() { return _title; }
};


// Package class
class Package : public CuboidObject
{
private:
    vector<Book*> _books;

    // _improvedLength and _improvedWidth contain the length and 
    // width of the package when the improved packing method is used.
    double _improvedLength, _improvedWidth;

    // _length and _width from CuboidObject contain the length and
    // width of the package when the standard packing method is used.

    void _computeStandardLengthWidth();
    void _computeImprovedLengthWidth();

public:
    Package( vector<Book*> &books );
    vector<Book*>& getBooks() { return _books; }
    double getImprovedLength() { return _improvedLength; }
    double getImprovedWidth()  { return _improvedWidth; }
};


// Constructor of Package.

Package::Package( vector<Book*> &books ) : _books(books)
{
    // Write your code here.

}


// Sets _length and _width to the length and width of the package
// produced using the standard packing method.

void Package::_computeStandardLengthWidth()
{
    // Write your code here.

}


// Sets _improvedLength and _improvedWidth to the length and width 
// of the package produced using the improved packing method.

void Package::_computeImprovedLengthWidth()
{
    // Write your code here.

}


// Returns the billable mass of the input package.

double computeBillableMass( Package &package )
{
    const double volMassFactor = 500.0;

    // Write your code here.

}


// Returns the shipping charge given the billable mass.

double computeShippingCharge( double billableMass )
{
    // Write your code here.

}


int main()
{
    vector<Book*> books;

    // Write your code here to read the inputs.


    // Outputs
    Package package( books );
    double billableMass = computeBillableMass( package );
    double shippingCharge = computeShippingCharge( billableMass );

    cout << setprecision(2) << fixed;
    cout << "Package standard length (m): " << package.getLength() << endl;
    cout << "Package standard width (m): " << package.getWidth() << endl;
    cout << "Package height (m): " << package.getHeight() << endl;
    cout << "Package mass (kg): " << package.getMass() << endl;
    cout << "Billable mass (kg): " << billableMass << endl;
    cout << "Shipping charge ($): " << shippingCharge << endl;

    cout << "Package improved length (m): "
         << package.getImprovedLength() << endl;
    cout << "Package improved width (m): "
         << package.getImprovedWidth() << endl;

    // Not required to deallocate dynamically allocated memory.

    return 0;
}
