#include <iostream>
#include "NodeArray.h"
#include "array.h"
#include "stack.h"
using namespace std;
int main() {
    // стек
    int n, Build;
    cin >> n;
    array s;
    stack size(n);

    for (int i = 0; i < n; i++) {
        cin >> Build;
        size.push_back(Build);
    }
    cout << endl << size.can_we_see_the_buildings() << endl;

// не стек
//    array s;
//    int n, k;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> k;
//        s.push_back(k);
//    }
//    cout << s.can_we_see_the_buildings(s);
}
