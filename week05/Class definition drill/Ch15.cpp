#include "../../std_lib_facilities.h"

struct Person{
    Person(){};
    Person(string f_name, string l_name, int a) : first_name(f_name), last_name(l_name), age{a} {
        if (age < 0 || age > 150) error("Invalid age!");
        for (auto i : f_name){
            if (!isalpha(i))
                error("Not allowed character!");
        }
        for (auto i : l_name){
            if(!isalpha(i))
                error("Not allowed character!");
        }
    };
    string get_first_name() const {return first_name;}
    string get_last_name() const {return last_name;}
    int get_age() const {return age;}

private:
    string first_name, last_name;
    int age;
};
istream& operator>>(istream& is, Person& p){
    string f_name, l_name;
    int age;

    is >> f_name >> l_name >> age;
    p = Person(f_name, l_name, age);
    return is;
}

ostream& operator<<(ostream& os, Person& p){
    return os << p.get_first_name() << " " << p.get_last_name() << " " << p.get_age() << endl;
}
vector<Person> people;
string quit = "exit";

int main(){

    Person p {"Goofy","", 63};
    cout << p << endl;

    //Person test {"$inopharm", 30};
    //Person test2 {"Sinopharm", 600};
    //Person test3 {"Sinopharm", -890};

    cout << "Type some person details: first name, last name, age" << endl;
    cout << "To stop the input type: \"exit\" and a string and a number then hit ENTER" << endl;

    for (Person p; cin >> p;){
        if(p.get_first_name() == "exit")
            break;
        people.push_back(p);
    }
    cout << endl;
    cout << "Data input succesfully finished...\n" << endl;
    cout << "Stored data: " << endl;
    for(auto i : people){
        cout << i;
    }


    return 0;
}