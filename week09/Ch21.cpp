#include "../std_lib_facilities.h"

struct Item{
    string name;
    int iid;
    double value;
    Item(){};
    Item(string n, int i, double v): name(n), iid(i), value(v){} 
};

struct Cmp_by_name{
    bool operator()(const Item& a, const Item& b) const {
        return a.name < b.name;
    }
};
struct Cmp_by_iid{
    bool operator()(const Item& a, const Item& b) const {
        return a.iid < b.iid;
    }
};

struct Cmp_by_val{
    bool operator()(const Item& a, const Item& b) const {
        return a.value < b.value;
    }
};

class Find_by_iid {
    int iid;
public:
    Find_by_iid(int i) :iid(i) { }
    bool operator()(const Item& it) const
    {
        return it.iid == iid;
    }
};

class Find_by_name {
    string name;
public:
    Find_by_name(const string& s) :name(s) { }
    bool operator()(const Item& it) const
    {
        return it.name == name;
    }
};
template<typename T, typename V>
void printMap(map<T,V>& m, string out = ""){
    if(out != "")
        cout << out << endl;
    else
        cout << "Map contents:" << endl;
    if(m.size() == 0)
        cout << "\tEmpty map" << endl;

    for (auto pair : m)
        cout << "\t" <<pair.first << " : " << pair.second << endl;
}

template<typename iter>
void print(iter first, iter last, string out = "")
{
    if (out != "")
        cout << out << endl;
    while (first!=last) {
        cout << "\t" <<*first << endl;
        ++first;
    }
}
template<typename T> 
void meret(vector<T>& v){
    cout << "Size of vector: "<<v.size() << endl;
}
template<typename T> 
void meret(list<T>& l){
    cout << "Size of list: "<<l.size() << endl;
}

istream& operator>>(istream& is, Item& it)
{
    string name;
    int iid;
    double value;
    is >> name >> iid >> value;
    if (!is) return is;
    it = Item(name,iid,value);
    return is;
}

ostream& operator<<(ostream& os, const Item& it)
{
    return os << it.name << '\t' << it.iid << '\t' << it.value;
}

template<typename T, typename V>
void read_val(map<T,V>& m){
    string key;
    int value;
    cin >> key >> value;
    m[key] = value;
}

template<class T>
class Less_than{
    T v;
public:
    Less_than(T val) :v(val) { }
    bool operator()(T x) const { return x < v; }
};

void elso(){
    cout << "Vector part of the drill: " << endl;
    vector<Item> vi;
    ifstream ifs;
    const string infile = "in.txt";
    ifs.open(infile);
    if(!ifs) error("Cannot open file: ", infile);
    Item i;
    while(ifs >> i) vi.insert(vi.end(), i);

    print(vi.begin(), vi.end());
    meret(vi);

    cout << "\nSort by name: " << endl;
    sort(vi.begin(), vi.end(), Cmp_by_name());
    print(vi.begin(), vi.end());

    sort(vi.begin(), vi.end(), Cmp_by_iid());
    print(vi.begin(), vi.end(), "\nSort by iid: ");
    
    sort(vi.begin(), vi.end(), Cmp_by_val());
    reverse(vi.begin(), vi.end());
    print(vi.begin(), vi.end(), "\nSort by value: ");

    vi.push_back(Item("horse shoe",99,12.34));
    vi.push_back(Item("Canon S400", 9988,499.95));

    print(vi.begin(), vi.end(), "\nItems added to vector: ");
    meret(vi);

    vector<Item>::iterator vi_it = find_if(vi.begin(), vi.end(), Find_by_name("sargabarack"));
    vi.erase(vi_it);
    vi_it = find_if(vi.begin(), vi.end(), Find_by_name("kaposzta"));
    vi.erase(vi_it);

    print(vi.begin(), vi.end(), "\nItems removed from vector by name:");
    meret(vi);

    vi_it = find_if(vi.begin(), vi.end(), Find_by_iid(3));
    vi.erase(vi_it);
    vi_it = find_if(vi.begin(), vi.end(), Find_by_iid(99));
    vi.erase(vi_it);

    print(vi.begin(), vi.end(), "\nItems removed from vector by iid:");
    meret(vi);
    cout << "-------------------------------------------------------------------" << endl;
}

void masodik(){
    cout << "List part of the drill:" << endl;
    list<Item> li;

    ifstream ifs;
    const string infile = "in.txt";
    ifs.open(infile);
    if(!ifs) error("Cannot open file: ", infile);
    Item i;
    while(ifs >> i) li.insert(li.end(), i);

    print(li.begin(), li.end());
    meret(li);

    cout << "\nSort by name: " << endl;
    li.sort(Cmp_by_name());
    print(li.begin(), li.end());

    li.sort(Cmp_by_iid());
    print(li.begin(), li.end(), "\nSort by iid: ");
    
    li.sort(Cmp_by_val());
    reverse(li.begin(), li.end());
    print(li.begin(), li.end(), "\nSort by value: ");

    li.push_back(Item("horse shoe",99,12.34));
    li.push_back(Item("Canon S400", 9988,499.95));

    print(li.begin(), li.end(), "\nItems added to list: ");
    meret(li);

    list<Item>::iterator li_it = find_if(li.begin(), li.end(), Find_by_name("sargabarack"));
    li.erase(li_it);
    li_it = find_if(li.begin(), li.end(), Find_by_name("kaposzta"));
    li.erase(li_it);

    print(li.begin(), li.end(), "\nItems removed from list by name:");
    meret(li);

    li_it = find_if(li.begin(), li.end(), Find_by_iid(3));
    li.erase(li_it);
    li_it = find_if(li.begin(), li.end(), Find_by_iid(99));
    li.erase(li_it);

    print(li.begin(), li.end(), "\nItems removed from list by iid:");
    meret(li);
    cout << "-------------------------------------------------------------------" << endl;
}

void harmadik(){
    cout << "Map part of the drill: "  << endl;

    map<string, int> msi;
    msi["alaplap"] = 100;
    msi["videokartya"] = 99999;
    msi["ssd"] = 30;
    msi["laptop"] = 50;
    msi["cpu"] = 4354;
    msi["tapegyseg"] = 23;
    msi["huto"] = 754;
    msi["haz"] = 34;
    msi["pc"] = 6542;
    msi["monitor"] =3423;

    printMap(msi, "Filling up msi with values: ");

    msi.clear();
    printMap(msi, "Cleared map: ");

    cout << "Enter 10 key-pair values: " << endl;
    for(int i = 0; i < 10; ++i)
        read_val(msi);

    printMap(msi, "Filled map: ");
    int sumval = 0;
    for(auto pair : msi)
        sumval += pair.second;
    cout << "Map msi summed values: " << sumval << endl;

    map<int, string> mis;
    for(auto pair : msi)
        mis[pair.second] = pair.first;
    printMap(mis, "Map mis key-pair values: ");

    cout << "-------------------------------------------------------------------" << endl;
}

void negyedik(){
    cout << "More vector part of the drill: " << endl;
    vector<double> vd;
    ifstream ifs;
    const string infile = "in2.txt";
    double input;
    ifs.open(infile);
    if (!ifs) error("Cannot open file ", infile);
    while(ifs >> input) vd.push_back(input);
    print(vd.begin(), vd.end(), "Filled vd vector: ");

    vector<int> vi(vd.size());
    copy(vd.begin(), vd.end(), vi.begin());

    cout << "\n(vd,vi) pairs:" << endl;
    for (int i = 0; i < vd.size(); ++i) 
        cout << '(' << vd[i] << ',' << vi[i] << ')' << endl;
    
    double sum_vd = 0;
    sum_vd = accumulate(vd.begin(),vd.end(),sum_vd);
    cout << "\nSum of the elements of vd: " << sum_vd << endl;
    
    int sum_vi = 0;
    sum_vi = accumulate(vd.begin(),vd.end(),sum_vi);
    cout << "The difference between vd and vi: " << sum_vd - sum_vi << endl;

    reverse(vd.begin(), vd.end());
    print(vd.begin(), vd.end(), "Revesed vd vector: ");

    double mean_vd = sum_vd/vd.size();
    cout << "Mean value in vd: " << mean_vd << endl;

    vector<double> vd2(count_if(vd.begin(),vd.end(),Less_than<double>(mean_vd)));
    copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than<double>(mean_vd));
    print(vd2.begin(), vd2.end(), "Vector vd2 elements: ");

    sort(vd);
    print(vd.begin(), vd.end(), "Sorted vd vector: ");

    cout << "-------------------------------------------------------------------" << endl;
}

void menu(){
    string vezerles = "";
    string help = "1 - First vector task\n2 - List part\n3 - Map part\n4 - Second vector part\n";
    cout << "---------Ch21 drill---------" << endl;
    cout << help;
    while(true){
    cout << "To exit type \"q\"\nFor help type \"h\"" << endl;
    cout << "Enter the number of task(1,2,3,4): ";
    cin >> vezerles;
    if(vezerles == "1")
        elso();
    else if(vezerles == "2")
        masodik();
    else if(vezerles == "3")
        harmadik();
    else if(vezerles == "4")
        negyedik();
    else if(vezerles == "q")
        break;
    else if(vezerles == "h")
        cout << help;
    else
        cout << "Unknown command \"" << vezerles << "\" Try again..." << endl;
    }
}

int main(){
    menu();
    return 0;
}