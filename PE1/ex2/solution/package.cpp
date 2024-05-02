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
    _height = 0.0;
    _mass = 0.0;
    for ( unsigned int i = 0; i < _books.size(); i++ ) {
        _height += _books[i]->getHeight();
        _mass += books[i]->getMass();
    }
    _computeStandardLengthWidth();
    _computeImprovedLengthWidth();
}


// Sets _length and _width to the length and width of the package
// produced using the standard packing method.

void Package::_computeStandardLengthWidth()
{
    // Write your code here.
    _length = 0.0;
    _width = 0.0;
    for ( unsigned int i = 0; i < _books.size(); i++ ) {
        if ( _books[i]->getLength() > _length )
            _length = _books[i]->getLength();
        if ( _books[i]->getWidth() > _width )
            _width = _books[i]->getWidth();
    }
}


// Sets _improvedLength and _improvedWidth to the length and width 
// of the package produced using the improved packing method.

void Package::_computeImprovedLengthWidth()
{
    // Write your code here.
    _improvedLength = 0.0;
    _improvedWidth = 0.0;
    for ( unsigned int i = 0; i < _books.size(); i++ ) {
        double longer, shorter;
        if ( _books[i]->getLength() > _books[i]->getWidth() ) {
            longer = _books[i]->getLength();
            shorter = _books[i]->getWidth();
        } else {
            longer = _books[i]->getWidth();
            shorter = _books[i]->getLength();
        }

        if ( longer > _improvedLength )
            _improvedLength = longer;
        if ( shorter > _improvedWidth )
            _improvedWidth = shorter;
    }
}


// Returns the billable mass of the input package.

double computeBillableMass( Package &package )
{
    const double volMassFactor = 500.0;

    // Write your code here.
    double volMass = package.getVolume() * volMassFactor;

    if ( package.getMass() > volMass )
        return package.getMass();
    else
        return volMass;
}


// Returns the shipping charge given the billable mass.

double computeShippingCharge( double billableMass )
{
    // Write your code here.
    billableMass = ceil(billableMass);
    double sum = 0.0;

    if (billableMass > 0.0) {
        sum = sum + 1.0 * 1.0;
        billableMass = billableMass - 1.0;
    }
    if (billableMass > 0.0) {
        sum = sum + 1.0 * 0.8;
        billableMass = billableMass - 1.0;
    }
    if (billableMass > 0.0) {
        sum = sum + 1.0 * 0.6;
        billableMass = billableMass - 1.0;
    }
    if (billableMass > 0.0) {
        sum = sum + billableMass * 0.4;
        billableMass = 0.0;
    }
    return sum;
}


int main()
{
    vector<Book*> books;

    // Write your code here to read the inputs.
    int numBooks;
    cin >> numBooks;

    for (int i = 0; i < numBooks; i++ ) {
        string title;
        double length, width, height, mass;
        cin >> title >> length >> width >> height >> mass;
        Book *newBook = new Book( title, length, width, height, mass );
        books.push_back( newBook );
    }

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
