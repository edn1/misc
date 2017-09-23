#include "matrix.h"
#include <iostream>



int main()
{
  try {
    Matrix m({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
    std::cout << m;
  } catch ( const char * err) {
    std::cout << "Error: " << err << '\n';
  }
}

