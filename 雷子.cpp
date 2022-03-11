#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    float x, y;
    for (y = 1.5f; y >-1.5f; y -= 0.1f)
    {
        for (x = -1.5f; x <1.5f; x += 0.05f)
        {
            float a = x*x + y*y - 1;
            if ((a*a*a- x*x*y*y*y)<=0) cout<<"^";//心形方程
            else cout<<" ";
        }
        cout<<endl;
    }
    cout<<"                              乖乖\n";
    cout<<"                           我爱你呦--2021年11月9日10点48分";
    return 0;
}

