#include <vector>
#include <iostream>

using namespace std;

int arr[] = {1, 2, 4, 1, 7, 8, 3};

vector<int> v({1, 2, 4, 1, 7, 8, 3});

int rec_opt(vector<int> ve, int i)
{
    if (i == 0)
    {
        return ve[0];
    }
    else if (i == 1)
    {
        return max(ve[0], ve[1]);
    }
    else
    {
        return max(rec_opt(ve, i - 2) + ve[i], rec_opt(ve, i - 1));
    }
}

int dp_opr(vector<int> v)
{
    int a, b = 0;
    int arr[v.size()];
    // for (int i = 0; i < v.size(); i++)
    // {
    //     arr[i] = 0;
    // }

    arr[0] = v[0];
    arr[1] = max(v[0], v[1]);
    for (int i = 2; i < v.size(); i++)
    {
        a = arr[i - 2] + v[i];
        b = arr[i - 1];
        arr[i] = max(a, b);
    }

    return arr[v.size() - 1];
}

int main(int argc, char const *argv[])
{
    cout << dp_opr(v);
    system("pause");
    return 0;
}
