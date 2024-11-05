#include "matrix.h"

#include <iomanip>
#include <iostream>

int main()
{
    Matrix m(3, 5, 3);
    Matrix n(3, 5, 5);
    Matrix b = m.add(n);
    m = n;
    m.print();
    n.print();
    b.print();
    return 0;
}
