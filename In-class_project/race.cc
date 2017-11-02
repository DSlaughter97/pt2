#include <iostream>
#include <omp.h>
using namespace std;
int main() {
int a=0;
#pragma omp parallel for
for (int i=0;i<10000;i++) {
if (i%7 == 0) {
a++;
}
}
cout << a << endl;
}
