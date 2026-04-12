#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct str
{
    int a;
    string s;
    bool operator<(const str &other) const
    {
        return a < other.a;
    }
};

int main()
{
    int n;
    cin >> n;
    
    vector<str> arr(n); 
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].a >> arr[i].s;
    }
    stable_sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].s << endl;
    }
    
    return 0;
}