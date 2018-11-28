#include <map>
#include <iostream>
#
using namespace std;

int main()
{
    map<int,int> test;
    test.insert(pair<int,int>(3,2));
    cout << test[3] << endl;   
    test.insert(pair<int,int>(3,7));
    cout << test[3] << endl; 
    system("pause");
}