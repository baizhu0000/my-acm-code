#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Tv
{
private:
    int voice, num;
    string mode;
    static int tvcnt;
    static int dvdcnt;

public:
    Tv(int i = 0)
    {
        num = i;
        voice = 50;
        mode = "TV";
        if (i != 0)
            tvcnt++;
    }

    void change(int m, int x, int v)
    {
        string temp = mode;

        if (m == 1)
        {
            mode = "TV";
            num = x;
        }
        else if (m == 2)
        {
            mode = "DVD";
            num = 99;
        }

        if (mode != temp)
        {
            if (temp == "TV")
            {
                tvcnt--;
                dvdcnt++;
            }
            else if (temp == "DVD")
            {
                dvdcnt--;
                tvcnt++;
            }
        }

        voice += v;
        if (voice < 0)
            voice = 0;
        if (voice > 100)
            voice = 100;

        if (mode == "TV")
            cout << "TV模式";
        else
            cout << "DVD模式";
        cout << "--频道" << num << "--音量" << voice << endl;
    }

    static int gettv() { return tvcnt; }
    static int getdvd() { return dvdcnt; }
};

int Tv::tvcnt = 0;
int Tv::dvdcnt = 0;

int main()
{
    int n;
    cin >> n;

    vector<Tv> a;
    a.push_back(Tv(0));
    for (int i = 1; i <= n; i++)
    {
        a.push_back(Tv(i));
    }

    int t;
    cin >> t;

    while (t--)
    {
        int i, k, x, v;
        cin >> i >> k >> x >> v;
        cout << "第" << i << "号电视机--";
        a[i].change(k, x, v);
        }

    cout << "播放电视的电视机数量为" << Tv::gettv() << endl;
    cout << "播放DVD的电视机数量为" << Tv::getdvd() << endl;

    return 0;
}