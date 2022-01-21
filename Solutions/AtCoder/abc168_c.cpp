#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")

#include "bits/stdc++.h"
using namespace std;
#define PI 3.14159265358979323846264338327950L

long double findAngle(int h, int m)
{
    long double hourMove = (long double) (h+m/60.0)*5;
    long double minMove = (long double) m;
    long double diff = hourMove-minMove;
    //theta in radians. 360deg = 2*pi rad.
    long double theta = (long double)(2*PI)* (long double)(diff/60); // 360*(diff/60) in degrees
    return theta;
}

int main()
{
    int a,b,h,m;
    cin>>a>>b>>h>>m;
    long double theta = findAngle(h,m);
    // we've 2 sides and angle between them, hence cosine theorm.
    // a2 = b2 + c2 − 2bc cosA
    long double thirdSideSquared = (long double) (a*a+b*b) - (long double) (2*a*b*cos(theta));
    printf("%20.20Lf\n", sqrt(thirdSideSquared));
}
