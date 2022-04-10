#include "../std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>

using namespace Numeric_lib;

void elso(){
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of short: " << sizeof(short) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of int*: " << sizeof(int*) << endl;
    cout << "Size of double*: " << sizeof(double*) << endl;
    cout << "\n-------------------------------------------------------------\n" << endl;
}

void masodik_harmadik(){
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int, 2> d(10, 10);
    Matrix<int, 3> e(10, 10, 10);

    cout << "Size of Matrix<int> a(10): " << sizeof(a) << endl;
    cout << "Size of Matrix<int> b(100): " << sizeof(b) << endl;
    cout << "Size of Matrix<double> c(10): " << sizeof(c) << endl;
    cout << "Size of Matrix<int, 2> d(10, 10): " << sizeof(d) << endl;
    cout << "Size of Matrix<int, 3> e(10, 10, 10): " << sizeof(e) << endl;
    cout << "\n-------------------------------------------------------------\n" << endl; 

    cout << "Number of elements a: " << a.size() << endl;
    cout << "Number of elements b: " << b.size() << endl;
    cout << "Number of elements c: " << c.size() << endl;
    cout << "Number of elements d: " << d.size() << endl;
    cout << "Number of elements e: " << e.size() << endl;
    cout << "\n-------------------------------------------------------------\n" << endl;
}

void negyedik(){
    int num;
    cout << "Enter ints (exit with char): ";
    while(cin >> num){
        if(num < 0)
            cout << "This number "<< num <<" has no square root!" << endl;
        else
            cout << "This number "<< num <<" has a square root " << sqrt(num) << endl;
        cout << "Enter ints (exit with char): ";
    }
    cout << "\n-------------------------------------------------------------\n" << endl;
}

void otodik(){
    cin.clear();
    cin.ignore();
    cout << "Enter 10 floating point values: ";
    Matrix<double> m(10);
    double val;
    for (int i = 0; i<m.size(); ++i) {
        cin >> val;
        m[i] = val;
    }
    cout << "Matrix:\n" << m << endl;
    cout << "\n-------------------------------------------------------------\n" << endl;
}

void hatodik(){
    cout << "\nMultiplication table\nEnter n: ";
    int n;
    cin >> n;
    cout << "Enter m: ";
    int m;
    cin >> m;
    Matrix<int,2> mtable(n,m);
    for (Index i = 0; i<mtable.dim1(); ++i) {
        for (Index j = 0; j<mtable.dim2(); ++j) {
            mtable(i,j) = (i+1)*(j+1);
            cout << setw(5) << mtable(i,j);
        }
        cout << endl;
    }
    cout << "\n-------------------------------------------------------------\n" << endl;
}

void hetedik(){
    Matrix<complex<double>> m(10);
    cout << "Enter 10 complex numbers(Re, Img): ";
    complex<double> c;
    for (int i = 0; i<10; ++i) {
        cin >> c;;
        m[i] = c;
    }
    complex<double> sum;
    for (Index i = 0; i<m.size(); ++i)
        sum += m[i];
    cout << "Sum: " << sum << endl;
    cout << "\n-------------------------------------------------------------\n" << endl;
}

void nyolcadik(){
    Matrix<int,2> m(2,3);
    cout << "\nEnter six ints: ";
    int n;
    for (int i = 0; i<m.dim1(); ++i)
        for (int j = 0; j<m.dim2(); ++j) {
            cin >> n;
            m(i,j) = n;
        }
    cout << "Matrix:\n" << m << endl;
    cout << "\n-------------------------------------------------------------\n" << endl;
}

int main(){
    elso();
    masodik_harmadik();
    negyedik();
    otodik();
    hatodik();
    hetedik();
    nyolcadik();

    
    return 0;
}