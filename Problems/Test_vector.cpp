#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> first;
    vector<int> second (5,100);
    vector<int> third (second.begin(), second.end());
    vector<int> fouth (third);
    int i;

    second[0] = 100;
    second[1] = 200;
    second[2] = 300;
    second[3] = 400;
    second[4] = 500;
    second.erase(second.begin()+1, second.begin()+5);

    for (i = 0; i < second.size(); i++)
        cout << second[i] << ' ';
    cout << endl;

    system("pause");
}