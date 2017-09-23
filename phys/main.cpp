#include "matrix.h"
#include <iostream>



int main()
{
  try {
    //Matrix m({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
    //std::cout << m;
    auto v1=Vector({1,2,3});
    auto v2=Vector({2,3,4});
    auto v3=v1.dot(v2);
    auto v4=v1+v2;
    std::cout << "v1= " << v1;
    std::cout << "v2= " << v2;
    std::cout << "v1 dot v2 = " << v3;
    std::cout << "v1 + v2 = " << v4;
    return 0;
  } catch ( ... ) {
    return 1;
  }
}

