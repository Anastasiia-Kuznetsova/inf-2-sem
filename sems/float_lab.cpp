#include <iostream>
#include <fstream>
#include<math.h>


using namespace std;

void binary(unsigned int n){
    int m[32];
    for(int i = 0;i < 32; i ++){
        m[i] = n&1;
        n >>= 1;
    }
    bool fl = false;
    for(int i = 0;i < 32; i ++){
        if (m[32 - i - 1] == 1) fl = true;
        if (fl) cout << m[32 - i -1];
    }
}

union fu {
 float f;
 unsigned int u;
};

int main(){
    /*// Перевод в двоичное представление
    fu a_lab_rat;
    cin >> a_lab_rat.f;
    binary(a_lab_rat.u);
    */

    /*//Переполнение мантиссы
    cout << fixed;
    cout.precision(2);
    float n = 1;
    for(int i = 1; i < 100; i ++){
        cout << n;
        n *= 10;
        cin.get();
    } */
    /* //дискретность float
    cout << fixed;
    cout.precision(2);
    float n = 1.67772e7;
    for(;n < 1e8;){
        cout << n;
        n += 1;
        cin.get();
    }
    */

    ofstream f("2.csv", ios::out);
    float n = 1;
    float k;
    for (float i = 1; i < 1000; i ++){
        n *= (2 * i) / (2* i - 1) * (2 * i) /(2 * i + 1);
        cout  << n << ' ';
        f << n * 2 << endl;

    }
}


