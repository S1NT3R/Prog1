#include "../std_lib_facilities.h"


template<typename Iter1, typename Iter2>
Iter2 mycopy(Iter1 f1, Iter1 e1, Iter2 f2){

    while (f1 != e1){
        *f2 = *f1;
        f2++;
        f1++;
    }
    return f2;
}



int main(){

    int arr[10] {0,1,2,3,4,5,6,7,8,9};
    vector<int> vec {0,1,2,3,4,5,6,7,8,9};
    list<int> lis {0,1,2,3,4,5,6,7,8,9};

    int* arr2 = arr;
    vector<int> vec2 = vec;
    list<int> lis2 = lis;

    cout << "Testing initialized values: " << endl;
    cout << "arr2: ";
    for (int i = 0; i < 10; i++)
        cout << arr2[i] << ' ';
    cout << endl;

    cout << "vec2: ";
    for (int i = 0; i < vec2.size(); i++)
        cout << vec2[i] << ' ';
    cout << endl;

    cout << "lis2: ";
    for (list<int>::iterator i = lis2.begin(); i !=lis2.end() ;i++)
        cout << *i << ' ';
    cout << endl;


    for(int i = 0; i < 10; ++i)
        arr2[i] += 2;
    
    for (int i = 0; i < vec2.size(); ++i)
        vec2[i] += 3;
    
    for(list<int>::iterator i = lis2.begin(); i != lis2.end(); ++i)
        *i += 5;

    
    cout << "Testing increased values: " << endl;
    cout << "arr2: ";
    for (int i = 0; i < 10; i++)
        cout << arr2[i] << ' ';
    cout << endl;

    cout << "vec2: ";
    for (int i = 0; i < vec2.size(); i++)
        cout << vec2[i] << ' ';
    cout << endl;

    cout << "lis2: ";
    for (list<int>::iterator i = lis2.begin(); i !=lis2.end() ;i++)
        cout << *i << ' ';
    cout << "\n" << endl;


    mycopy(begin(arr), end(arr), begin(vec2));
    cout << "vec2 copied: ";
    for (int i = 0 ; i < vec2.size(); ++i)
        cout <<  vec2[i] << ' ';
    cout << endl;

    mycopy(lis2.begin(), lis2.end(), arr2);
    
    cout << "arr2 copied: ";
    for(int i = 0; i < 10; i++)
        cout << arr2[i] << ' ';
    cout << "\n" << endl;
    
    vector<int>::iterator vres = find(vec2, 3);
    list<int>::iterator lres = find(lis2, 27);

    if(vres != vec2.end())
        cout << "In vec2, number 3 has been found at index: "<< vres-vec2.begin() << endl;
    else
        cout << "Number 3 has not been found in vec2" << endl;

    if(lres != lis2.end()){
        int index = 0;
        for(list<int>::iterator i = lis2.begin(); i != lis2.end(); ++i)
            index++;
        cout << "In lis2, number 27 has been found at index: " << index << endl;
    }
    else
        cout << "Number 27 has not been found in lis2." << endl;
    


    return 0;
}