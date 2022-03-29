#include "../std_lib_facilities.h"

template <typename T>
struct S
{
    S(T t) : val(t){};

    T& get();
    const T& get() const;

    void set(const T& t) {val = t;}
    T& operator=(const T& t){
        val = t;
        return val;
    };

private:
    T val;
};

template <typename T> T& S<T>::get()
{
    return val;
}

template<typename T> const T& S<T>::get() const{
    return val;
}

template<typename T> istream& operator>>(istream& is, S<T>& s) {
    T v;
    is >> v;
    if (!is) return is;
    s = v;
    return is;
}

template <typename T> ostream& operator<<(ostream& os, vector<T>& s){
    cout << "{ ";
    for (int i = 0; i < s.size(); ++i){
        cout << s[i] << " ";
    }
    cout <<"}"<< endl;
}

template <typename T> istream& operator>>(istream& is, vector<T>& s){
    char ch1;
    char ch2;
    T temp;
    vector<T> vtemp;
    is >> ch1;
    if (!is) return is;
    if (ch1 != '{') {
        is.clear(ios_base::failbit);
        return is;
    }
    while (cin >> temp >> ch2 && ch2 == ',') {
        vtemp.push_back(temp);
    }
    if (ch2 != '}') {
        is.clear(ios_base::failbit);
        return is;
    }
    vtemp.push_back(temp);
    s = vtemp;
}
template<typename T> T& read_val(T& v){
    cin >> v;
}

int main()
{

    S<int> sint(23);
    S<char> schar('c');
    S<double> sdouble(3.1415);
    S<string> sstr("string");
    vector<int> vi {1,2,3,4};
    S<vector<int>> svi(vi);

    cout << "Output data with initialized values: " << endl;
    cout << sint.get() << ", " << schar.get() << ", " << sdouble.get() << ", " << sstr.get() << ", " << svi.get() << endl;
    /*for(int i = 0; i < svi.get().size(); ++i){
        cout << svi.get()[i] << " ";
    }
    cout << endl;*/

    sint.set(12345);
    schar.set('k');
    sdouble.set(2.7182818);
    sstr.set("felirat");

    cout << "Output data with set() function used: " << endl;
    cout << sint.get() << ", " << schar.get() << ", " << sdouble.get() << ", " << sstr.get() << ", " << svi.get() << endl;

    cout << "Input data " << endl;
    cout << "Enter an int: ";
    read_val(sint);
    cout << "Enter a char: ";
    read_val(schar);
    cout << "Enter a double: ";
    read_val(sdouble);
    cout << "Enter a string: ";
    read_val(sstr);
    cout << "Enter elements of an int vector, format:{val,val,val}: ";
    read_val(svi);
    cout << endl;
    cout << "Output data with read_val() function used: " << endl;
    cout << sint.get() << ", " << schar.get() << ", " << sdouble.get() << ", " << sstr.get() << ", "<< svi.get() << endl;

    return 0;
}